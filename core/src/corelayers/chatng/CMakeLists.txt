add_subdirectory(lib)

qutim_add_plugin(chatng
    SUBPLUGIN
    SOURCE_DIR src
    DISPLAY_NAME "Adium-like chat"
    DESCRIPTION "New qutIM chat implementation, based on Adium chat styles and power of Qt Quick"
    DEPENDS ureenQuick qutim-adiumwebview
    LINK_LIBRARIES ureenQuick qutim-adiumwebview
    QT_LIBRARIES webkit declarative
    CXX11
)

qutim_add_artwork(qml/quickChatForm)
