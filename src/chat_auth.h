/*
 *  Off-the-Record Messaging library
 *  Copyright (C) 2015-2016  Dimitrios Kolotouros <dim.kolotouros@gmail.com>,
 *							 Konstantinos Andrikopoulos <el11151@mail.ntua.gr>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of version 2.1 of the GNU Lesser General
 *  Public License as published by the Free Software Foundation.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef CHAT_AUTH_H_
#define CHAT_AUTH_H_

//#include "chat_enc.h"
//#include "chat_context.h"
//#include "chat_message.h"
#include "chat_types.h"
#include "message.h"
struct OtrlListOpsStruct interKeyOps;

//typedef enum {
//	OTRL_CHAT_AUTHSTATE_NONE,
//	OTRL_CHAT_AUTHSTATE_AWAITING_RES
//} OtrlAuthGKAState;
//
//typedef struct {
//	OtrlAuthGKAState state;  /* the gka state */
//
//	unsigned char key[32];
//
//	OtrlChatMessage *auth_msg; /* the next message to be send for GKA */
//} OtrlAuthGKAInfo;

/**
  Destroyes an OtrlAuthGKAInfo struct. It does not free the struct itself.

  @param gka_info the struct to be destroyed.
 */
void chat_auth_gka_info_destroy(OtrlAuthGKAInfo *gka_info);

/**
 Initialize the query exchange

 This function will intialize the query exchange proccess. Call this when you want to send a query
 message.

 @param ops Client callbacks, used to get the participants of the chat
 @param ctx The context for which the qery will be created
 @param msgToSend The query message will be stored here
 */
gcry_error_t chat_auth_init(OtrlChatContext *ctx, ChatMessage **msgToSend);

/**
  Check if the msg belongs to the authentication protocol

  This function accepts a message and determines if it should be handled by the
  authentication protocol.

  @param msg The message to check
  @returns 1 if the message belongs to the authentication protocol. 0 otherwise
 */
int chat_auth_is_my_message(const ChatMessage *msg);

/**
  Handle a message that belongs to the authentication protocol

  This function accepts a message tha belongs to the the authentication protocol and
  performs the required actions mandated by it.

  @param ops A pointer to the operations struct in order to get the participants list
  @param ctx The context in which any action is performed
  @param msg The message to handle
  @param msgToSend a pointer to a pointer to a message. The apropriate response
   to the handled message will be stored here
  @returns 1 if the message belongs to the authentication protocol. 0 otherwise
 */
int chat_auth_handle_message(OtrlChatContext *ctx, ChatMessage *msg,
		ChatMessage **msgToSend);
#endif /* CHAT_AUTH_H_ */
