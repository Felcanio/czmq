/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#ifndef QML_ZLISTX_H
#define QML_ZLISTX_H

#include <QtQml>

#include <czmq.h>
#include "qml_czmq_plugin.h"


class QmlZlistx : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isNULL READ isNULL)
    
public:
    zlistx_t *self;
    
    QmlZlistx() { self = NULL; }
    bool isNULL() { return self == NULL; }
    
    static QObject* qmlAttachedProperties(QObject* object); // defined in QmlZlistx.cpp
    
public slots:
    //  Add an item to the head of the list. Calls the item duplicator, if any,
    //  on the item. Resets cursor to list head. Returns an item handle on     
    //  success, NULL if memory was exhausted.                                 
    void *addStart (void *item);

    //  Add an item to the tail of the list. Calls the item duplicator, if any,
    //  on the item. Resets cursor to list head. Returns an item handle on     
    //  success, NULL if memory was exhausted.                                 
    void *addEnd (void *item);

    //  Return the number of items in the list
    size_t size ();

    //  Return first item in the list, or null, leaves the cursor
    void *head ();

    //  Return last item in the list, or null, leaves the cursor
    void *tail ();

    //  Return the item at the head of list. If the list is empty, returns NULL.
    //  Leaves cursor pointing at the head item, or NULL if the list is empty.  
    void *first ();

    //  Return the next item. At the end of the list (or in an empty list),     
    //  returns NULL. Use repeated zlistx_next () calls to work through the list
    //  from zlistx_first (). First time, acts as zlistx_first().               
    void *next ();

    //  Return the previous item. At the start of the list (or in an empty list),
    //  returns NULL. Use repeated zlistx_prev () calls to work through the list 
    //  backwards from zlistx_last (). First time, acts as zlistx_last().        
    void *prev ();

    //  Return the item at the tail of list. If the list is empty, returns NULL.
    //  Leaves cursor pointing at the tail item, or NULL if the list is empty.  
    void *last ();

    //  Returns the value of the item at the cursor, or NULL if the cursor is
    //  not pointing to an item.                                             
    void *item ();

    //  Returns the handle of the item at the cursor, or NULL if the cursor is
    //  not pointing to an item.                                              
    void *cursor ();

    //  Find an item in the list, searching from the start. Uses the item     
    //  comparator, if any, else compares item values directly. Returns the   
    //  item handle found, or NULL. Sets the cursor to the found item, if any.
    void *find (void *item);

    //  Detach an item from the list, using its handle. The item is not modified, 
    //  and the caller is responsible for destroying it if necessary. If handle is
    //  null, detaches the first item on the list. Returns item that was detached,
    //  or null if none was. If cursor was at item, moves cursor to previous item,
    //  so you can detach items while iterating forwards through a list.          
    void *detach (void *handle);

    //  Detach item at the cursor, if any, from the list. The item is not modified,
    //  and the caller is responsible for destroying it as necessary. Returns item 
    //  that was detached, or null if none was. Moves cursor to previous item, so  
    //  you can detach items while iterating forwards through a list.              
    void *detachCur ();

    //  Delete an item, using its handle. Calls the item destructor is any is 
    //  set. If handle is null, deletes the first item on the list. Returns 0 
    //  if an item was deleted, -1 if not. If cursor was at item, moves cursor
    //  to previous item, so you can delete items while iterating forwards    
    //  through a list.                                                       
    int delete (void *handle);

    //  Move an item to the start of the list, via its handle.
    void moveStart (void *handle);

    //  Move an item to the end of the list, via its handle.
    void moveEnd (void *handle);

    //  Remove all items from the list, and destroy them if the item destructor
    //  is set.                                                                
    void purge ();

    //  Sort the list. If an item comparator was set, calls that to compare    
    //  items, otherwise compares on item value. The sort is not stable, so may
    //  reorder equal items.                                                   
    void sort ();

    //  Create a new node and insert it into a sorted list. Calls the item        
    //  duplicator, if any, on the item. If low_value is true, starts searching   
    //  from the start of the list, otherwise searches from the end. Use the item 
    //  comparator, if any, to find where to place the new node. Returns a handle 
    //  to the new node, or NULL if memory was exhausted. Resets the cursor to the
    //  list head.                                                                
    void *insert (void *item, bool lowValue);

    //  Move an item, specified by handle, into position in a sorted list. Uses 
    //  the item comparator, if any, to determine the new location. If low_value
    //  is true, starts searching from the start of the list, otherwise searches
    //  from the end.                                                           
    void reorder (void *handle, bool lowValue);

    //  Make a copy of the list; items are duplicated if you set a duplicator
    //  for the list, otherwise not. Copying a null reference returns a null 
    //  reference.                                                           
    QmlZlistx *dup ();

    //  Set a user-defined deallocator for list items; by default items are not
    //  freed when the list is destroyed.                                      
    void setDestructor (czmq_destructor destructor);

    //  Set a user-defined duplicator for list items; by default items are not
    //  copied when the list is duplicated.                                   
    void setDuplicator (czmq_duplicator duplicator);

    //  Set a user-defined comparator for zlistx_find and zlistx_sort; the method 
    //  must return -1, 0, or 1 depending on whether item1 is less than, equal to,
    //  or greater than, item2.                                                   
    void setComparator (czmq_comparator comparator);
};

class QmlZlistxAttached : public QObject
{
    Q_OBJECT
    QObject* m_attached;
    
public:
    QmlZlistxAttached (QObject* attached) {
        Q_UNUSED (attached);
    };
    
public slots:
    //  Returns the item associated with the given list handle, or NULL if passed     
    //  in handle is NULL. Asserts that the passed in handle points to a list element.
    void *handleItem (void *handle);

    //  Self test of this class.
    void test (bool verbose);

    //  Create a new, empty list.
    QmlZlistx *construct ();

    //  Destroy a list. If an item destructor was specified, all items in the
    //  list are automatically destroyed as well.                            
    void destruct (QmlZlistx *qmlSelf);
};


QML_DECLARE_TYPEINFO(QmlZlistx, QML_HAS_ATTACHED_PROPERTIES)

#endif
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/