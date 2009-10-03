/****************************************************************************
 *  icon.h
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

#ifndef ICON_H
#define ICON_H

#include <QIcon>

class Icon : public QIcon
{
public:
	// Qt 4.6 has ability for getting icons from system themes
	// but has no one for getting client-specific icons like
	// status icons and client icons (except installed clients)
	// so we create our own imlp of icon engine, which has wrapper
	// around QIcon::fromTheme
	enum Type { System, Status };

	// There is also another way: i.e. give names for icons
	// like "user-online-jabber", "user-online-icq" and so on
	// names for clients should be like "miranda" or "qutim"
	Icon(const QString &name);

	Icon(const QIcon &icon);
};

#endif // ICON_H
