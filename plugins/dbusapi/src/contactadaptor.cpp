/****************************************************************************
 *
 *  This file is part of qutIM
 *
 *  Copyright (c) 2010 by Nigmatullin Ruslan <euroelessar@gmail.com>
 *
 ***************************************************************************
 *                                                                         *
 *   This file is part of free software; you can redistribute it and/or    *
 *   modify it under the terms of the GNU General Public License as        *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 ***************************************************************************
 ****************************************************************************/

#include "contactadaptor.h"

ContactAdaptor::ContactAdaptor(Contact *contact) :
		QDBusAbstractAdaptor(contact)
{
	connect(contact, SIGNAL(tagsChanged(QStringList,QStringList)),
			this, SIGNAL(tagsChanged(QStringList,QStringList)));
	connect(contact, SIGNAL(inListChanged(bool)),
			this, SIGNAL(inListChanged(bool)));
}