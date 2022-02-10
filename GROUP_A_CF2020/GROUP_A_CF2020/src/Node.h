//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef __MESH_NODE_H_
#define __MESH_NODE_H_

#include <omnetpp.h>
#include "MyMessage_m.h"
#include <vector>


using namespace omnetpp;
#define MAX_SEQUENCE 7
#define NUMBER_OF_FILES 6
#define WINDOW_WIDTH ((MAX_SEQUENCE+1)/2)
#define circular_increment(s_no) if(s_no < MAX_SEQUENCE) s_no = s_no + 1; else s_no = 0

class Node : public cSimpleModule
{
  private:
    int node_number;
    int NUMBER_OF_NODES;
    double ACK_TIMEOUT_DURATION;
    double TIMEOUT_DURATION;
    std::vector<cQueue> buffered_from_network;
    std::vector<bool> no_nack_sent;
    std::vector<bool> network_layer_enabled;
    std::vector<bool> ack_sent_or_not;
    std::vector<sequence_number> ack_expected;
    std::vector<sequence_number> sequence_to_send_next;
    std::vector<sequence_number> seq_where_inbound_window_begins;
    std::vector<sequence_number> seq_after_inbound_window_boundary;
    std::vector<sequence_number> number_of_sent_but_not_acked;
    MyMessage_Base *signal_to_enable_network = new MyMessage_Base("");
    MyMessage_Base *frame_to_send = new MyMessage_Base("");
    MyMessage_Base *frame_received = new MyMessage_Base("");
    std::vector<std::vector<MyMessage_Base*>> outbound_window;
    std::vector<std::vector<MyMessage_Base*>> inbound_window;
    std::vector<MyMessage_Base*> time_outs;
    std::vector<MyMessage_Base*> ack_timers;
    std::vector<std::vector<bool>> is_timer_set;
    std::vector<std::vector<bool>> inbound_receieved_or_not;
    std::vector<std::vector<bool>> ack_received_or_not;

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void statistics(int choice);
    void start_timer(sequence_number s_no, unsigned int destination);
    void stop_timer(sequence_number s_no, unsigned int destination);
    void start_ack_timer(unsigned int destination);
    void stop_ack_timer(unsigned int destination);
    void enable_network_layer(int destination_index);
    void disable_network_layer(int destination_index);
    bool is_sequence_between (sequence_number s_no_to_check, sequence_number window_boundary_1, sequence_number window_boundary_2);
    void send_frame(frame_type type, sequence_number frame_no, sequence_number ack, unsigned int destination);
    char calculateParityAtPosition(int position, int newSize, std::string newCode);
    std::string Hamming(int m, int r, std::string code);
    std::string convertToCode(std::string message);
    std::string convertToChar(std::string message);
    std::string characterCount(std::string message, int size);
    int checkHamming(int m, int r, std::string newCode);
};

#endif
