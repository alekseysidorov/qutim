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
#include "chatform.h"

#include <qutim/declarativeview.h>
#include <qutim/thememanager.h>
#include <qutim/config.h>
#include <qutim/servicemanager.h>
#include <QGraphicsObject>
#include <QDeclarativeContext>
#include <QDeclarativeComponent>

using namespace qutim_sdk_0_3;

ChatForm::ChatForm(QObject *parent) :
	qutim_sdk_0_3::MenuController(parent),
	m_context(new QDeclarativeContext(DeclarativeView::engine(), this))
{
	m_context->setContextProperty("chatForm", this);
	m_context->setContextProperty("chat", ServiceManager::getByName("ChatLayer"));

	QString theme = Config(QLatin1String("appearance/quickChat")).value("chatForm", "default");
	load(ThemeManager::path("quickChatForm",
							theme) + "/main.qml");
}

void ChatForm::load(const QString &path)
{
	if (m_rootComponent)
		m_rootComponent->deleteLater();

	m_rootComponent = new QDeclarativeComponent(DeclarativeView::engine() , path, this);
	if (!m_rootComponent->isLoading()) {
		continueExecute();
	} else {
		connect(m_rootComponent.data(), SIGNAL(statusChanged(QDeclarativeComponent::Status)), this, SLOT(continueExecute()));
	}
}

void ChatForm::continueExecute()
{
	disconnect(m_rootComponent.data(), SIGNAL(statusChanged(QDeclarativeComponent::Status)), this, SLOT(continueExecute()));

	if (m_rootComponent->isError()) {
		auto errorList = m_rootComponent->errors();
		foreach (auto error, errorList) {
			warning() << error;
		}
		return;
	}

	QObject *obj = m_rootComponent->create(m_context);
	obj->setParent(this);

	if (m_rootComponent->isError()) {
		auto errorList = m_rootComponent->errors();
		foreach (auto error, errorList) {
			warning() << error;
		}
		return;
	}

	m_rootObject = qobject_cast<QGraphicsObject*>(obj);
	Q_ASSERT(m_rootObject);

	//QGraphicsScene *scene = m_rootObject->scene();
	//foreach (auto view, scene->views())
	//	view->setViewport(new QGLWidget(QGLFormat::defaultFormat()));
}

