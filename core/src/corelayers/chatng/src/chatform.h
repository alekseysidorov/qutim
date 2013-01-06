/****************************************************************************
**
** qutIM - instant messenger
**
** Copyright © 2013 Aleksey Sidorov <gorthauer87@yandex.ru>
**
*****************************************************************************
**
** $QUTIM_BEGIN_LICENSE$
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see http://www.gnu.org/licenses/.
** $QUTIM_END_LICENSE$
**
****************************************************************************/
#ifndef CHATFORM_H
#define CHATFORM_H
#include <qutim/menucontroller.h>
#include <QPointer>

class QDeclarativeComponent;
class QGraphicsObject;
class QDeclarativeContext;

class ChatForm : public qutim_sdk_0_3::MenuController
{
    Q_OBJECT
	Q_CLASSINFO("Uses", "ChatLayer")
	Q_CLASSINFO("Service", "ChatForm")
public:
    explicit ChatForm(QObject *parent = 0);
public slots:
	void load(const QString &theme);
protected slots:
	void continueExecute();
private:
	QPointer<QDeclarativeComponent> m_rootComponent;
	QPointer<QGraphicsObject> m_rootObject;
	QDeclarativeContext *m_context;
};

#endif // CHATFORM_H
