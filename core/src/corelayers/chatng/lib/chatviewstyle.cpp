#include "chatviewstyle.h"

ChatViewStyle::ChatViewStyle(WebKitMessageViewStyle *style, QObject *parent)
    : QObject(parent), m_style(style)
{
}

ChatViewStyle::~ChatViewStyle()
{
}

QString ChatViewStyle::scriptForChangingVariant()
{
    return m_style->scriptForChangingVariant();
}

QString ChatViewStyle::scriptForSettingCustomStyle()
{
    return m_style->scriptForSettingCustomStyle();
}

