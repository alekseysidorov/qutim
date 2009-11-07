/****************************************************************************
 *  icqprotocol.h
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

#ifndef ICQPROTOCOL_H
#define ICQPROTOCOL_H

#include <qutim/protocol.h>

using namespace qutim_sdk_0_3;

struct IcqProtocolPrivate;

class IcqProtocol : public Protocol
{
	Q_OBJECT
	Q_CLASSINFO("Protocol", "icq")
public:
    IcqProtocol();
	virtual ~IcqProtocol();
	static inline IcqProtocol *instance() { if(!self) qWarning("IcqProtocol isn't created"); return self; }
	virtual AccountCreationWizard *accountCreationWizard();
protected:
	void loadAccounts();
private:
	QScopedPointer<IcqProtocolPrivate> p;
	static IcqProtocol *self;
};

#endif // ICQPROTOCOL_H
