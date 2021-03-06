/****************************************************************************
**
** qutIM - instant messenger
**
** Copyright © 2011 Ruslan Nigmatullin <euroelessar@yandex.ru>
** Copyright © 2011 Aleksey Sidorov <gorthauer87@yandex.ru>
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
#include <cstdlib>
#include <ctime>
#include <random>

#include <QApplication>
#include <QTextCodec>
#include <QWidget>
#include <QTime>
#include <QOpenGLContext>

#include "src/widgets/modulemanagerimpl.h"

#if defined(STATIC_IMAGE_PLUGINS)
Q_IMPORT_PLUGIN(qjpeg)
Q_IMPORT_PLUGIN(qgif)
#endif

Q_GUI_EXPORT void qt_gl_set_global_share_context(QOpenGLContext *context);

int main(int argc, char *argv[])
{
    {
        std::random_device rd;
        srand(rd());
        qsrand(rd());
    }
	QApplication app(argc, argv);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QOpenGLContext context;
    context.create();

    qt_gl_set_global_share_context(&context);

	Core::ModuleManagerImpl core;
	Q_UNUSED(core);

	return app.exec();
}

