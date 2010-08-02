/*
 * $Id$
 */

/*
 * Harbour Project source code:
 * QT wrapper main header
 *
 * Copyright 2009 Pritpal Bedi <pritpal@vouchcac.com>
 *
 * Copyright 2009 Marcos Antonio Gambeta <marcosgambeta at gmail dot com>
 * www - http://harbour-project.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307 USA (or visit the web site http://www.gnu.org/).
 *
 * As a special exception, the Harbour Project gives permission for
 * additional uses of the text contained in its release of Harbour.
 *
 * The exception is that, if you link the Harbour libraries with other
 * files to produce an executable, this does not by itself cause the
 * resulting executable to be covered by the GNU General Public License.
 * Your use of that executable is in no way restricted on account of
 * linking the Harbour library code into it.
 *
 * This exception does not however invalidate any other reasons why
 * the executable file might be covered by the GNU General Public License.
 *
 * This exception applies only to the code released by the Harbour
 * Project under the name Harbour.  If you copy code from other
 * Harbour Project or Free Software Foundation releases into a copy of
 * Harbour, as the General Public License permits, the exception does
 * not apply to the code that you add in this way.  To avoid misleading
 * anyone as to the status of such modified files, you must delete
 * this exception notice from them.
 *
 * If you write modifications of your own for Harbour, it is your choice
 * whether to permit this exception to apply to your modifications.
 * If you do not wish that, delete this exception notice.
 *
 */

#ifndef __HBQT_H
#define __HBQT_H

#include "hbapi.h"

#if defined( HB_OS_OS2 )
#  define OS2EMX_PLAIN_CHAR
#  define INCL_BASE
#  define INCL_PM
#  include <os2.h>
#endif

#include <QtCore/qglobal.h>

#if !( QT_VERSION >= 0x040500 )
#  error QT library version 4.5.0 or upper is required for hbqt.
#endif

#define QT_G_FUNC( hbfunc )   void hbfunc( void * Cargo ) /* callback function for cleaning garbage memory pointer */
typedef QT_G_FUNC( QT_G_FUNC_ );
typedef QT_G_FUNC_ * QT_G_FUNC_PTR;

typedef struct
{
   void * ph;
   bool bNew;
   QT_G_FUNC_PTR func;
   int type;
} QGC_POINTER;

HB_GARBAGE_FUNC( Q_release );

extern HB_EXPORT void * hbqt_gcpointer( int iParam );
extern HB_EXPORT const HB_GC_FUNCS * hbqt_gcFuncs( void );
extern HB_EXPORT void * hbqt_pPtrFromObj( int iParam );
extern HB_EXPORT void * hbqt_pPtrFromItem( PHB_ITEM pObj );

#define hbqt_par_QString( n )                       ( ( QString ) hb_parcx( n ) )
#define hbqt_par_uchar( n )                         ( ( uchar * ) hb_parcx( n ) )
#define hbqt_par_QRgb( n )                          ( hb_parnint( n ) )
#define hbqt_par_Bool( n )                          ( hb_parl( n ) )
#define hbqt_par_char( n )                          ( hb_parcx( n ) )

#endif /* __HBQT_H */