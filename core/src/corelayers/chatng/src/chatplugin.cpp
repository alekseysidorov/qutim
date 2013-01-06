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
#include <qutim/quickchat/chat.h>
#include <qutim/icon.h>
#include <qutim/servicemanager.h>
#include "chatplugin.h"
#include "chatform.h"

using namespace qutim_sdk_0_3;

template<typename T>
T findParent(QObject *w)
{
    while(w) {
        if (T parent = qobject_cast<T>(w))
            return parent;
        w = w->parent();
    }
    return 0;
}

//class EmoActionGenerator : public ActionGenerator
//{
//public:
//	EmoActionGenerator(QObject *obj) :
//		ActionGenerator(Icon("face-smile"),QT_TRANSLATE_NOOP("ChatLayer", "Insert Emoticon"),obj,SLOT(onInsertEmoticon(QAction*,QObject*)))
//	{
//		setType(ActionTypeChatButton);
//	}

//	void showImpl(QAction *action, QObject *)
//	{
//		debug() << Q_FUNC_INFO;
//		action->setVisible(!Emoticons::theme().isNull());
//	}

//protected:
//	virtual QObject *generateHelper() const
//	{
//		EmoAction *emo = new EmoAction();
//		prepareAction(emo);
//		return emo;
//	}
//};

void ChatPlugin::init()
{
	LocalizedString name = QT_TRANSLATE_NOOP("Plugin", "Adium chat layer");
	LocalizedString description = QT_TRANSLATE_NOOP("Plugin", "Modern qutIM chat implementation, based on Adium chat styles and power of Qt Quick");
    setInfo(name, description, QUTIM_VERSION);
    setCapabilities(Loadable);
    addExtension<Chat>(name, description);
	addExtension<ChatForm>(QT_TRANSLATE_NOOP("Plugin", "Quick chat"),
						   QT_TRANSLATE_NOOP("Plugin", "Chat window with Qt quick interface"));
}

bool ChatPlugin::load()
{
	ChatForm *form = ServiceManager::getByName<ChatForm*>("ChatForm");
	if (!form) {
		return true;
	}

	//Shortcut::registerSequence("showEmoticons",
	//						   QT_TRANSLATE_NOOP("ChatLayer", "Show Emoticons"),
	//						   "ChatWidget",
	//						   QKeySequence("alt+e")
	//						   );
	//Shortcut::registerSequence("quote",
	//						   QT_TRANSLATE_NOOP("ChatLayer", "Quote"),
	//						   "ChatWidget",
	//						   QKeySequence("alt+q")
	//						   );
	//Shortcut::registerSequence("clearChat",
	//						   QT_TRANSLATE_NOOP("ChatLayer", "Clear Chat"),
	//						   "ChatWidget",
	//						   QKeySequence("alt+c")
	//						   );

	//ActionGenerator *gen = new EmoActionGenerator(this);
	//gen->setShortcut(QLatin1String("showEmoticons"));
	//form->addAction(gen);

	//gen = new ActionGenerator(Icon("insert-text-quote"),
	//						  QT_TRANSLATE_NOOP("ChatLayer","Quote"),
	//						  this,
	//						  SLOT(onQuote(QObject*)));
	//gen->setShortcut(QLatin1String("quote"));
	//form->addAction(gen);

	//gen = new ActionGenerator(Icon("edit-clear-list"),
	//						  QT_TRANSLATE_NOOP("ChatLayer","Clear chat"),
	//						  this,
	//						  SLOT(onClearChat(QObject*)));
	//gen->setToolTip(QT_TRANSLATE_NOOP("ChatLayer","Clear chat field"));
	//gen->setShortcut(QLatin1String("clearChat"));
	//form->addAction(gen);

    return true;
}

bool ChatPlugin::unload()
{
    return true;
}

void ChatPlugin::onClearChat(QObject *controller)
{
    //if (AbstractChatWidget *chat = findParent<AbstractChatWidget*>(controller))
    //    chat->currentSession()->clearChat();
}

void ChatPlugin::onInsertEmoticon(QAction *, QObject *)
{
}

void ChatPlugin::onQuote(QObject *controller)
{
}

void ChatPlugin::onQuote(const QString &quote, QObject *controller)
{
}

QUTIM_EXPORT_PLUGIN(ChatPlugin)
