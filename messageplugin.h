/****************************************************************************
 *  messageplugin.h
 *
 *  Copyright (c) 2009 by Nigmatullin Ruslan <euroelessar@gmail.com>
 *
 ***************************************************************************
 *                                                                         *
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************
*****************************************************************************/

#ifndef MESSAGEPLUGIN_H
#define MESSAGEPLUGIN_H

#include <qutim/account.h>

class IcqAccount;

namespace qutim_sdk_0_3
{
	class MessagePlugin
	{
	public:
		virtual ~MessagePlugin() {}
		virtual QList<QByteArray> capabilities() = 0;
		virtual void processMessage(const QString &uin, const QByteArray &guid, const QByteArray &data, quint64 id) = 0;
		virtual void virtual_hook(int type, void *data) = 0;
		inline void setAccount(Account *account) { m_account = account; }
	protected:
		union {
			IcqAccount *m_icq_account;
			Account *m_account;
		};
	};
}

Q_DECLARE_INTERFACE(qutim_sdk_0_3::MessagePlugin, "org.qutim.MessagePlugin")

#endif // MESSAGEPLUGIN_H
