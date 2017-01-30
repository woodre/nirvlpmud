/*
 * /basic/view.c by Alfe for Tubmud 2002-Jan-17
 *
 * provides an interface for rooms stating that people in this room
 * can see all that is happening in another room.
 */

#include <server.h>
#include <libs.h>

#if 0
#define DEBUG_ROOM_RESET
#endif

private nosave mapping view, viewers;
/* view: ([ <direction>: <room_file_name>, ... ])
 *       describes which rooms are viewable in which direction from
 *       this_object()
 * viewers: ([ <viewer>, ... ])
 *          describes which objects are viewing this_object()
 */

void create() {
#ifdef DEBUG_ROOM_RESET
  log_file("DEBUG-room-reset",sprintf("%s: %O: %s\n",ctime(),this_object(),"basic/view::create() ..."),1);
#endif
  view    = m_allocate(0, 1);  // ([ ]);
  viewers = m_allocate(0, 0);  // ([ ]);
#ifdef DEBUG_ROOM_RESET
  log_file("DEBUG-room-reset",sprintf("%s: %O: %s\n%O %O\n",ctime(),this_object(),"... basic/view::create()",view,viewers),1);
#endif
}

private nosave mapping reverse_view;  // this is just to cheapen up things.

varargs mixed query_view(string room) {
  if (room) {
    if (!reverse_view)
      reverse_view = factorize(m_indices(view), (: view[$1] :));
    return reverse_view[room];
  }
  else
    return view;
}

mapping query_viewers() {
#if 1  // strange bug workaround  Alfe 2006-Jun-30
  mixed h;
  if (!viewers) {
    h = sprintf("reset-not-called bug for %O in room %O;"
                " calling reset(0) now",
                this_player() || this_interactive(), this_object());
    log_file("DEBUG-room-reset", ctime() + ": " + h);
    LIB_CHANNELS->channel_shout("wrongness", h);
    this_object()->reset(0);
  }
#endif
  //  return viewers - ([ 0 ]);
  return filter(viewers, (: objectp($1) :));
}

void add_viewer(object room) {
  m_add(viewers, room);
}

void remove_viewer(object room) {  // Coogan, 03-May-2002
  m_delete(viewers, room);
}

varargs void set_view(mixed view_or_room, string direction) {
  if (stringp(view_or_room) && view_or_room[0..0] == "/")
    raise_error("Bad object name to set_view() (leading slash found in " +
                view_or_room + ")");
  reverse_view = 0;  // clear cache
  if (direction) {
    view[direction] = view_or_room;
    SE_NOTIFIER->add_notify(view_or_room,"notify_viewed");
  }
  else {
    view = copy(view_or_room);
    map(m_values(view), (: SE_NOTIFIER->add_notify($1, "notify_viewed") :));
  }
}

// next function by Coogan, 03-May-2002
varargs void remove_view(mixed view_or_room, string direction) {
  mixed h;
  string err_msg;
  reverse_view = 0;  // clear cache
  if (direction) {  // view_or_room is a room
    m_delete(view, direction);
    if (member(m_values(view), view_or_room) < 0) {  // not viewed anymore?
      err_msg = SE_NOTIFIER->remove_notify(view_or_room, this_object());
      if (h=find_object(view_or_room))
        h->remove_viewer(this_object());
    }
  }
  else  // view_or_room is like ([ "in the sky above": "air/village" ])
    foreach (direction, string room : view)
      remove_view(room, direction);
}

void notify_viewed(string viewed_room, status refresh) {
  viewed_room->add_viewer(this_object());
}

object *query_receivers() {
  object *receivers;
  receivers = m_indices(this_object()->query_viewers() ||
                        ([]));  // the viewing rooms
  receivers += ({ this_object() });
  receivers = map(receivers,(: all_inventory($1) :));  // their inventories
  receivers = flatten_array(receivers);  // all in one
  receivers = filter(receivers,#'living);  // just the living ones
  return receivers;
}
