/****************************************************************************
 *  objectgenerator.h
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

#ifndef OBJECTGENERATOR_H
#define OBJECTGENERATOR_H

#include "libqutim_global.h"
#include <QPointer>

namespace qutim_sdk_0_3
{
	class LIBQUTIM_EXPORT ObjectGenerator
	{
		Q_DISABLE_COPY(ObjectGenerator)
	public:
		inline QObject *generate() const
		{ return generateHelper(); }
		template<typename T>
		inline T *generate() const
		{ return extends<T>() ? qobject_cast<T *>(generateHelper()) : 0; }
		inline QObject *generate(const QMetaObject *super) const
		{ return extends(super) ? generateHelper() : 0; }
		inline QObject *generate(const char *id) const
		{ return extends(id) ? generateHelper() : 0; }
		virtual const QMetaObject *metaObject() const = 0;
		virtual const char *iid() const = 0;
		inline bool extends(const QMetaObject *super) const
		{
			const QMetaObject *meta = metaObject();
			while(meta && ((meta = meta->superClass()) != super));
			return super && meta == super;
		}
		inline bool extends(const char *id) const
		{ return id && !qstrcmp(id, iid()); }
		template<typename T>
		inline bool extends() const
		{ return extends_helper<T>(reinterpret_cast<T *>(0)); }
	protected:
		template<typename T>
		inline bool extends_helper(const QObject *) const
		{ return extends(&T::staticMetaObject); }
		template<typename T>
		inline bool extends_helper(const void *) const
		{ return extends(qobject_interface_iid<T *>()); }
		virtual QObject *generateHelper() const = 0;
		inline ObjectGenerator() {}
		mutable QPointer<QObject> m_object;
	};

	template<typename T>
	class LIBQUTIM_EXPORT GeneralGenerator : public ObjectGenerator
	{
		Q_DISABLE_COPY(GeneralGenerator)
	public:
		inline GeneralGenerator() {}
	protected:
		virtual QObject *generateHelper() const
		{
			if(m_object.isNull())
				m_object = new T();
			return m_object.data();
		}
		virtual const QMetaObject *metaObject() const
		{
			return &T::staticMetaObject;
		}
		virtual const char *iid() const
		{
			return 0;
		}
	};

	template<typename T, typename Interface>
	class LIBQUTIM_EXPORT InterfaceGenerator : public ObjectGenerator
	{
		Q_DISABLE_COPY(InterfaceGenerator)
	public:
		inline InterfaceGenerator() {}
	protected:
		virtual QObject *generateHelper() const
		{
			if(m_object.isNull())
				m_object = new T();
			return m_object.data();
		}
		virtual const QMetaObject *metaObject() const
		{
			return 0;
		}
		virtual const char *iid() const
		{
			return qobject_interface_iid<Interface *>();
		}
	};
}

#endif // OBJECTGENERATOR_H
