/*
 * WinDom: a high level GEM library
 * Copyright (c) 1997-2005 Dominique Bereziat & Arnaud Bercegeay
 *                    2004 STanda Opichal
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 * $Source: /cygdrive/c/Users/johan/Sources/public/fvdi/modules/ft2/list.h,v $
 *
 * CVS info:
 *   $Author: johan $
 *   $Date: 2005-05-09 20:56:16 $
 *   $Revision: 1.1 $
 */

#ifndef __WINDOM_LIST__
#define __WINDOM_LIST__


typedef struct Linkable {
	struct Linkable *next;
	struct Linkable *prev;
} LINKABLE;


typedef struct {
	LINKABLE head;
	LINKABLE tail;
} LIST;


#define listEmptyListInitializer() {{NULL,NULL},{NULL,NULL}}

static inline void listInit( LIST *list ) {
	list->head.next = &list->tail;
	list->head.prev = (LINKABLE*)0L;
	list->tail.next = (LINKABLE*)0L;
	list->tail.prev = &list->head;
}

static inline void listInsert( LINKABLE *iter, LINKABLE *entry ) {
	entry->next = iter;
	entry->prev = iter->prev;
	iter->prev->next = entry;
	iter->prev = entry;
}

static inline void listAppend( LINKABLE *iter, LINKABLE *entry ) {
	entry->next = iter->next;
	entry->prev = iter;
	iter->next->prev = entry;
	iter->next = entry;
}

static inline LINKABLE *listRemove( LINKABLE *iter ) {
	iter->prev->next = iter->next;
	iter->next->prev = iter->prev;
	return iter;
}

LIST *createList( void );
LIST *listSplice( LIST *list, LINKABLE *first, LINKABLE *pastLast );

#define listForEach( type, i, list )	\
	if ( list ) for( i=(type)(list)->head.next; \
		((LINKABLE*)i) != &(list)->tail; \
		i=(type)((LINKABLE*)i)->next )

#define listRewind( list )	&((list)->head)
#define listEnd( list )		&((list)->tail)
#define listNext( iter )	((!((LINKABLE*)iter)->next->next) ? NULL : (((LINKABLE*)iter)->next))
#define listPrev( iter )	((!((LINKABLE*)iter)->prev->prev) ? NULL : (((LINKABLE*)iter)->prev))

#define listIsEmpty(list)	( ((list)->head.next) == (&(list)->tail))
#define listFirst(list)		( ((list)->head.next) == (&(list)->tail) ? NULL : ((list)->head.next))
#define listLast(list)		( ((list)->tail.prev) == (&(list)->head) ? NULL : ((list)->tail.prev))

typedef struct VoidP_Linkable {
	struct Linkable *next;
	struct Linkable *prev;
	void		*value;
} VOIDP_LINKABLE;


#endif /* __WINDOM_LIST__ */
