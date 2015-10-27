#include <fstream>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include "header.h"
#include <SerialStream.h>
	
using namespace std;
using namespace LibSerial ;

void main ()
{
		//For USB comms use this website http://libserial.sourceforge.net/tutorial.html#opening-a-serial-port-i-o-stream
	//First task, read from serial port, package, and save to file
	
	//
	// Create and open the serial port for communication.
	//
	SerialStream my_serial_stream( "/dev/ttyS0" ) ;
	//
	// The various available baud rates are defined in SerialStreamBuf class.
	// This is to be changed soon. All serial port settings will be placed in
	// in the SerialPort class.
	//
	my_serial_stream.SetBaudRate( SerialStreamBuf::BAUD_115200 ) ;
	//
	// Use 8 bit wide characters.
	// ensures we're only getting ASCII
	my_serial_port.SetCharSize( SerialStreamBuf::CHAR_SIZE_8 ) ;
	//
	// Use one stop bit.
	//
	my_serial_port.SetNumOfStopBits(1) ; //Even I don't know what this does or if it's necessary
	//
	// Use odd parity during serial communication.
	//
	my_serial_port.SetParity( SerialStreamBuf::PARITY_ODD ) ;
	//
	// Use hardware flow-control.
	//
	my_serial_port.SetFlowControl( SerialStreamBuf::FLOW_CONTROL_HARD ) ; //I guess this is necessary
	
	//create MessageQueue
	QueueID = msgQCreate( MAX_MSG, MSGLEN, MSG_Q_PRIORITY);
	if( QueueID == NULL)
		return(ERROR);
      
	  //enableTimeStamp
	  sysTimestampEnable();
    //now we can go into sending and receiving
	
	const int BUFFER_SIZE = 256 ;
	char input_buffer[BUFFER_SIZE], quit ;
	short counter;
	string strWords[20];
	string serial_line, yaw, pitch, roll, timestamp;
	string messageID;
	int num_messages_of_this_type=0;
	ofstream myfile;
	bool continue_code = true;
	//
	while(continue_code==true) //maybe there might be some reason to stop the code, for now it just loops forever
	{
		cin >> quit; //way to quit from loop
		if(quit='q')
		{
			continue_code=false;
		}
		my_serial_stream.read( input_buffer, BUFFER_SIZE ) ;
		serial_line = string(input_buffer); //convert the serial line to string for easier handling. May not be necessary if we can do this directly
		counter = 1;
		
		strWords[0]=timestamp();/*************replace timestap() with the proper thing that makes a timestap****************/
		for(short i=1;i<line.length();i++)
		{
			strWords[counter] += line[i]; // Append fixed
			if(line[i] == ','|| line[i]=='=')
			{
				counter++;
			}
		}
		//now our serial data is packaged into [timestamp] [msgID] [first value] [second value] ...
		
		//now we can do a switch or if else statement 
		cout << "timestamp is " << strWords[0] << " The message ID is " << strWords[1] << " value1 = " << strWords[2] << " value2 = " << strWords[3] << " value3 = " << strWords[4] << " value4 = " << strWords[5] << endl;
	}
}
