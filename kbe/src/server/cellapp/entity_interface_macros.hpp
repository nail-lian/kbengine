/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/


#if defined(DEFINE_IN_INTERFACE)
	#undef __ENTITY_INTERFACE_MACRO_H__
#endif


#ifndef __ENTITY_INTERFACE_MACRO_H__
#define __ENTITY_INTERFACE_MACRO_H__

// common include	
#include "network/interface_defs.hpp"
// windows include	
#if KBE_PLATFORM == PLATFORM_WIN32
#else
// linux include
#endif
	
namespace KBEngine{

/**
	Entity消息宏，  参数为流， 需要自己解开
*/
#if defined(NETWORK_INTERFACE_DECLARE_BEGIN)
	#undef ENTITY_MESSAGE_HANDLER_STREAM
#endif

#if defined(DEFINE_IN_INTERFACE)
#if defined(CELLAPP)
#define ENTITY_MESSAGE_HANDLER_STREAM(NAME)										\
	void NAME##EntityMessagehandler_stream::handle(Mercury::Channel* pChannel,	\
													KBEngine::MemoryStream& s)	\
	{																			\
			ENTITY_ID eid;														\
			s >> eid;															\
			KBEngine::Entity* e =												\
					KBEngine::Cellapp::getSingleton().findEntity(eid);			\
			if(e)																\
			{																	\
				e->NAME(pChannel, s);											\
			}																	\
			else																\
			{																	\
				ERROR_MSG(boost::format(										\
					"Messagehandler::handle: can't found entityID:%1%.\n") %	\
					eid);														\
			}																	\
	}																			\
	Mercury::MERCURY_MESSAGE_TYPE NAME##EntityMessagehandler_stream::type()const\
	{																			\
		return Mercury::MERCURY_MESSAGE_TYPE_ENTITY;							\
	}																			\

#else
#define ENTITY_MESSAGE_HANDLER_STREAM(NAME)										\
	void NAME##EntityMessagehandler_stream::handle(Mercury::Channel* pChannel,	\
													KBEngine::MemoryStream& s)	\
	{																			\
	}																			\
	Mercury::MERCURY_MESSAGE_TYPE NAME##EntityMessagehandler_stream::type()const\
	{																			\
		return Mercury::MERCURY_MESSAGE_TYPE_ENTITY;							\
	}																			\

#endif
#else
#define ENTITY_MESSAGE_HANDLER_STREAM(NAME)										\
	class NAME##EntityMessagehandler_stream : public Mercury::MessageHandler	\
	{																			\
	public:																		\
		virtual void handle(Mercury::Channel* pChannel,							\
							KBEngine::MemoryStream& s);							\
		virtual Mercury::MERCURY_MESSAGE_TYPE type()const;						\
	};																			\

#endif

#define ENTITY_MESSAGE_DECLARE_STREAM(NAME, MSG_LENGTH)							\
	ENTITY_MESSAGE_HANDLER_STREAM(NAME)											\
	NETWORK_MESSAGE_DECLARE_STREAM(Entity, NAME,								\
				NAME##EntityMessagehandler_stream, MSG_LENGTH)					\
																				\

/**
	Entity消息宏，  只有一个参数的消息
*/
#if defined(NETWORK_INTERFACE_DECLARE_BEGIN)
	#undef ENTITY_MESSAGE_HANDLER_ARGS1
#endif

#if defined(DEFINE_IN_INTERFACE)
#if defined(CELLAPP)
#define ENTITY_MESSAGE_HANDLER_ARGS1(NAME, ARG_TYPE1, ARG_NAME1)				\
	void NAME##EntityMessagehandler1::handle(Mercury::Channel* pChannel,		\
											KBEngine::MemoryStream& s)			\
	{																			\
			ENTITY_ID eid;														\
			s >> eid;															\
			KBEngine::Entity* e =												\
					KBEngine::Cellapp::getSingleton().findEntity(eid);			\
			ARG_TYPE1 ARG_NAME1;												\
			s >> ARG_NAME1;														\
			if(e)																\
			{																	\
				e->NAME(pChannel, ARG_NAME1);									\
			}																	\
			else																\
			{																	\
				ERROR_MSG(boost::format(										\
					"Messagehandler::handle: can't found entityID:%1%.\n") %	\
					eid);														\
			}																	\
	}																			\
	Mercury::MERCURY_MESSAGE_TYPE NAME##EntityMessagehandler1::type()const		\
	{																			\
		return Mercury::MERCURY_MESSAGE_TYPE_ENTITY;							\
	}																			\

#else
#define ENTITY_MESSAGE_HANDLER_ARGS1(NAME, ARG_TYPE1, ARG_NAME1)				\
	void NAME##EntityMessagehandler1::handle(Mercury::Channel* pChannel,		\
											KBEngine::MemoryStream& s)			\
	{																			\
	}																			\
	Mercury::MERCURY_MESSAGE_TYPE NAME##EntityMessagehandler1::type()const		\
	{																			\
		return Mercury::MERCURY_MESSAGE_TYPE_ENTITY;							\
	}																			\
		
#endif
#else
#define ENTITY_MESSAGE_HANDLER_ARGS1(NAME, ARG_TYPE1, ARG_NAME1)				\
	class NAME##EntityMessagehandler1 : public Mercury::MessageHandler			\
	{																			\
	public:																		\
		virtual void handle(Mercury::Channel* pChannel,							\
							KBEngine::MemoryStream& s);							\
		virtual Mercury::MERCURY_MESSAGE_TYPE type()const;						\
	};																			\

#endif

#define ENTITY_MESSAGE_DECLARE_ARGS1(NAME, MSG_LENGTH, ARG_TYPE1, ARG_NAME1)	\
	ENTITY_MESSAGE_HANDLER_ARGS1(NAME, ARG_TYPE1, ARG_NAME1)					\
	NETWORK_MESSAGE_DECLARE_ARGS1(Entity, NAME,									\
				NAME##EntityMessagehandler1, MSG_LENGTH, ARG_TYPE1, ARG_NAME1)	\
																				\

/**
	Entity消息宏，  只有二个参数的消息
*/
#if defined(NETWORK_INTERFACE_DECLARE_BEGIN)
	#undef ENTITY_MESSAGE_HANDLER_ARGS2
#endif

#if defined(DEFINE_IN_INTERFACE)
#if defined(CELLAPP)
#define ENTITY_MESSAGE_HANDLER_ARGS2(NAME, ARG_TYPE1, ARG_NAME1,				\
											ARG_TYPE2, ARG_NAME2)				\
	void NAME##EntityMessagehandler2::handle(Mercury::Channel* pChannel,		\
											KBEngine::MemoryStream& s)			\
	{																			\
			ENTITY_ID eid;														\
			s >> eid;															\
			KBEngine::Entity* e =												\
					KBEngine::Cellapp::getSingleton().findEntity(eid);			\
			ARG_TYPE1 ARG_NAME1;												\
			ARG_TYPE2 ARG_NAME2;												\
			s >> ARG_NAME1;														\
			s >> ARG_NAME2;														\
			if(e)																\
			{																	\
				e->NAME(pChannel, ARG_NAME1, ARG_NAME2);						\
			}																	\
			else																\
			{																	\
				ERROR_MSG(boost::format(										\
					"Messagehandler::handle: can't found entityID:%1%.\n") %	\
					eid);														\
			}																	\
	}																			\
	Mercury::MERCURY_MESSAGE_TYPE NAME##EntityMessagehandler2::type()const\
	{																			\
		return Mercury::MERCURY_MESSAGE_TYPE_ENTITY;							\
	}																			\

#else
#define ENTITY_MESSAGE_HANDLER_ARGS2(NAME, ARG_TYPE1, ARG_NAME1,				\
											ARG_TYPE2, ARG_NAME2)				\
	void NAME##EntityMessagehandler2::handle(Mercury::Channel* pChannel,		\
											KBEngine::MemoryStream& s)			\
	{																			\
	}																			\
	Mercury::MERCURY_MESSAGE_TYPE NAME##EntityMessagehandler2::type()const		\
	{																			\
		return Mercury::MERCURY_MESSAGE_TYPE_ENTITY;							\
	}																			\
		
#endif
#else
#define ENTITY_MESSAGE_HANDLER_ARGS2(NAME, ARG_TYPE1, ARG_NAME1,				\
											ARG_TYPE2, ARG_NAME2)				\
	class NAME##EntityMessagehandler2 : public Mercury::MessageHandler			\
	{																			\
	public:																		\
		virtual void handle(Mercury::Channel* pChannel,							\
							KBEngine::MemoryStream& s);							\
		virtual Mercury::MERCURY_MESSAGE_TYPE type()const;						\
	};																			\

#endif

#define ENTITY_MESSAGE_DECLARE_ARGS2(NAME, MSG_LENGTH, ARG_TYPE1, ARG_NAME1,	\
														ARG_TYPE2, ARG_NAME2)	\
	ENTITY_MESSAGE_HANDLER_ARGS2(NAME, ARG_TYPE1, ARG_NAME1,					\
										ARG_TYPE2, ARG_NAME2)					\
	NETWORK_MESSAGE_DECLARE_ARGS2(Entity, NAME,									\
				NAME##EntityMessagehandler2, MSG_LENGTH, ARG_TYPE1, ARG_NAME1,	\
														ARG_TYPE2, ARG_NAME2)	\
																				\


/**
	Entity消息宏，  只有零个参数的消息
*/
#if defined(NETWORK_INTERFACE_DECLARE_BEGIN)
	#undef ENTITY_MESSAGE_HANDLER_ARGS0
#endif

#if defined(DEFINE_IN_INTERFACE)
#if defined(CELLAPP)
#define ENTITY_MESSAGE_HANDLER_ARGS0(NAME)										\
	void NAME##EntityMessagehandler0::handle(Mercury::Channel* pChannel,		\
											KBEngine::MemoryStream& s)			\
	{																			\
			ENTITY_ID eid;														\
			s >> eid;															\
			KBEngine::Entity* e =												\
					KBEngine::Cellapp::getSingleton().findEntity(eid);			\
			if(e)																\
			{																	\
				e->NAME(pChannel);												\
			}																	\
			else																\
			{																	\
				ERROR_MSG(boost::format(										\
					"Messagehandler::handle: can't found entityID:%1%.\n") %	\
					eid);														\
			}																	\
	}																			\
	Mercury::MERCURY_MESSAGE_TYPE NAME##EntityMessagehandler0::type()const		\
	{																			\
		return Mercury::MERCURY_MESSAGE_TYPE_ENTITY;							\
	}																			\

#else
#define ENTITY_MESSAGE_HANDLER_ARGS0(NAME)										\
	void NAME##EntityMessagehandler0::handle(Mercury::Channel* pChannel,		\
											KBEngine::MemoryStream& s)			\
	{																			\
	}																			\
	Mercury::MERCURY_MESSAGE_TYPE NAME##EntityMessagehandler0::type()const		\
	{																			\
		return Mercury::MERCURY_MESSAGE_TYPE_ENTITY;							\
	}																			\
		
#endif
#else
#define ENTITY_MESSAGE_HANDLER_ARGS0(NAME)										\
	class NAME##EntityMessagehandler0 : public Mercury::MessageHandler			\
	{																			\
	public:																		\
		virtual void handle(Mercury::Channel* pChannel,							\
							KBEngine::MemoryStream& s);							\
		virtual Mercury::MERCURY_MESSAGE_TYPE type()const;						\
	};																			\

#endif

#define ENTITY_MESSAGE_DECLARE_ARGS0(NAME, MSG_LENGTH)							\
	ENTITY_MESSAGE_HANDLER_ARGS0(NAME)											\
	NETWORK_MESSAGE_DECLARE_ARGS0(Entity, NAME,									\
				NAME##EntityMessagehandler0, MSG_LENGTH)						\
																				\


/**
	Entity消息宏，  只有三个参数的消息
*/
#if defined(NETWORK_INTERFACE_DECLARE_BEGIN)
	#undef ENTITY_MESSAGE_HANDLER_ARGS3
#endif

#if defined(DEFINE_IN_INTERFACE)
#if defined(CELLAPP)
#define ENTITY_MESSAGE_HANDLER_ARGS3(NAME, ARG_TYPE1, ARG_NAME1,				\
											ARG_TYPE2, ARG_NAME2,				\
											ARG_TYPE3, ARG_NAME3)				\
	void NAME##EntityMessagehandler3::handle(Mercury::Channel* pChannel,		\
											KBEngine::MemoryStream& s)			\
	{																			\
			ENTITY_ID eid;														\
			s >> eid;															\
			KBEngine::Entity* e =												\
					KBEngine::Cellapp::getSingleton().findEntity(eid);			\
			ARG_TYPE1 ARG_NAME1;												\
			ARG_TYPE2 ARG_NAME2;												\
			ARG_TYPE3 ARG_NAME3;												\
			s >> ARG_NAME1;														\
			s >> ARG_NAME2;														\
			s >> ARG_NAME3;														\
			if(e)																\
			{																	\
				e->NAME(pChannel, ARG_NAME1, ARG_NAME2, ARG_NAME3);				\
			}																	\
			else																\
			{																	\
				ERROR_MSG(boost::format(										\
					"Messagehandler::handle: can't found entityID:%1%.\n") %	\
					eid);														\
			}																	\
	}																			\
	Mercury::MERCURY_MESSAGE_TYPE NAME##EntityMessagehandler3::type()const		\
	{																			\
		return Mercury::MERCURY_MESSAGE_TYPE_ENTITY;							\
	}																			\

#else
#define ENTITY_MESSAGE_HANDLER_ARGS3(NAME, ARG_TYPE1, ARG_NAME1,				\
											ARG_TYPE2, ARG_NAME2,				\
											ARG_TYPE3, ARG_NAME3)				\
	void NAME##EntityMessagehandler3::handle(Mercury::Channel* pChannel,		\
											KBEngine::MemoryStream& s)			\
	{																			\
	}																			\
	Mercury::MERCURY_MESSAGE_TYPE NAME##EntityMessagehandler3::type()const		\
	{																			\
		return Mercury::MERCURY_MESSAGE_TYPE_ENTITY;							\
	}																			\
		
#endif
#else
#define ENTITY_MESSAGE_HANDLER_ARGS3(NAME, ARG_TYPE1, ARG_NAME1,				\
											ARG_TYPE2, ARG_NAME2,				\
											ARG_TYPE3, ARG_NAME3)				\
	class NAME##EntityMessagehandler3 : public Mercury::MessageHandler			\
	{																			\
	public:																		\
		virtual void handle(Mercury::Channel* pChannel,							\
							KBEngine::MemoryStream& s);							\
		virtual Mercury::MERCURY_MESSAGE_TYPE type()const;						\
	};																			\

#endif

#define ENTITY_MESSAGE_DECLARE_ARGS3(NAME, MSG_LENGTH, ARG_TYPE1, ARG_NAME1,	\
											ARG_TYPE2, ARG_NAME2,				\
											ARG_TYPE3, ARG_NAME3)				\
	ENTITY_MESSAGE_HANDLER_ARGS3(NAME, ARG_TYPE1, ARG_NAME1,					\
											ARG_TYPE2, ARG_NAME2,				\
											ARG_TYPE3, ARG_NAME3)				\
	NETWORK_MESSAGE_DECLARE_ARGS3(Entity, NAME,									\
				NAME##EntityMessagehandler3, MSG_LENGTH, ARG_TYPE1, ARG_NAME1,	\
											ARG_TYPE2, ARG_NAME2,				\
											ARG_TYPE3, ARG_NAME3)				\
																				\


}
#endif
