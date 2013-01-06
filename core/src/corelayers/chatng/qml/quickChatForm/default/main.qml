import QtQuick 1.1
import QtDesktop 0.1
import org.qutim 0.3
import "."

ApplicationWindow {
    id: root

    property variant currentSessionPage

    width: 600
    height: 600
    visible: true

    Connections {
        target: chat
        onActiveSessionChanged: {
            root.currentSessionPage = session.page;
        }
        onSessionCreated: {
            if (!session.page) {
                var tab = tabFrame.addTab(dummy, session.unit.title);
                var page = webViewComponent.createObject(tab, { "session": session });
                session.page = page;
            }
            root.currentSessionPage = session.page;
        }
        onSessionDestroyed: {
            if (session.page) {
                var page = session.page;
                session.page = null;
                page.destroy();
            }
        }
    }

    TabFrame {
        id: tabFrame
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            bottom: textField.top
            margins: 6
        }
    }

    Component {
        id: webViewComponent
        ChatView {
            id: chatView

            anchors.fill: parent
            //visible: chatView.session.active
            visible: chatView === root.currentSessionPage
        }
    }

    Component {
        id: dummy
        Item {}
    }

    TextField {
        id: textField
        anchors { left: parent.left; bottom: parent.bottom }
        placeholderText: qsTr("Write anything")
        height: Math.min(200, implicitHeight)
        width: parent.width - sendButton.width
    }

    Button {
        id: sendButton
        anchors { top: textField.top; right: parent.right; bottom: textField.bottom }
        text: qsTr("Send")
        onClicked: {
            if (textField.text!=="")
            {
                var result = chat.activeSession.send(textField.text);
                if (result !== -2)
                    textField.text = "";
            }
        }
    }
}
