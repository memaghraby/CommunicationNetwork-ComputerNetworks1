//
// Generated file, do not edit! Created by nedtool 5.6 from MyMessage.msg.
//

#ifndef __MYMESSAGE_M_H
#define __MYMESSAGE_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
//    #define MAX_PACKET_SIZE_BYTES 1024
    typedef unsigned int sequence_number;
//    typedef struct {unsigned char data[MAX_PACKET_SIZE_BYTES];} packet_inside_frame;
//	typedef struct {unsigned char* data;} packet_inside_frame;
    typedef enum {data, ack, nack, timeout, ack_timeout, frame_from_network, network_enable, handshake} frame_type;
// }}

/**
 * Class generated from <tt>MyMessage.msg:30</tt> by nedtool.
 * <pre>
 * packet MyMessage
 * {
 *     \@customize(true);  // see the generated C++ header for more info
 *     frame_type type;
 *     unsigned int destination_node;
 *     unsigned int source_node;
 *     sequence_number sequence;
 *     sequence_number ack;
 *     string M_Payload;
 * }
 * </pre>
 *
 * MyMessage_Base is only useful if it gets subclassed, and MyMessage is derived from it.
 * The minimum code to be written for MyMessage is the following:
 *
 * <pre>
 * class MyMessage : public MyMessage_Base
 * {
 *   private:
 *     void copy(const MyMessage& other) { ... }

 *   public:
 *     MyMessage(const char *name=nullptr, short kind=0) : MyMessage_Base(name,kind) {}
 *     MyMessage(const MyMessage& other) : MyMessage_Base(other) {copy(other);}
 *     MyMessage& operator=(const MyMessage& other) {if (this==&other) return *this; MyMessage_Base::operator=(other); copy(other); return *this;}
 *     virtual MyMessage *dup() const override {return new MyMessage(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from MyMessage_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(MyMessage)
 * </pre>
 */
class MyMessage_Base : public ::omnetpp::cPacket
{
  protected:
    frame_type type;
    unsigned int destination_node;
    unsigned int source_node;
    sequence_number sequence;
    sequence_number ack;
    ::omnetpp::opp_string M_Payload;

  private:
    void copy(const MyMessage_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MyMessage_Base&);
    // make constructors protected to avoid instantiation
    // make assignment operator protected to force the user override it
    MyMessage_Base& operator=(const MyMessage_Base& other);

  public:
    MyMessage_Base(const char *name=nullptr, short kind=0);
    MyMessage_Base(const MyMessage_Base& other);
    virtual ~MyMessage_Base();
    virtual MyMessage_Base *dup() const override {return new MyMessage_Base(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual frame_type& getType();
    virtual const frame_type& getType() const {return const_cast<MyMessage_Base*>(this)->getType();}
    virtual void setType(const frame_type& type);
    virtual unsigned int getDestination_node() const;
    virtual void setDestination_node(unsigned int destination_node);
    virtual unsigned int getSource_node() const;
    virtual void setSource_node(unsigned int source_node);
    virtual sequence_number& getSequence();
    virtual const sequence_number& getSequence() const {return const_cast<MyMessage_Base*>(this)->getSequence();}
    virtual void setSequence(const sequence_number& sequence);
    virtual sequence_number& getAck();
    virtual const sequence_number& getAck() const {return const_cast<MyMessage_Base*>(this)->getAck();}
    virtual void setAck(const sequence_number& ack);
    virtual const char * getM_Payload() const;
    virtual void setM_Payload(const char * M_Payload);
};


#endif // ifndef __MYMESSAGE_M_H

