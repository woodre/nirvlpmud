/*************************************************************************
      /basic/link.c -- an interface for linking objects together
		      written by Ugh Oct-1996
*************************************************************************/
#include <event.h>

private static mapping linked_to;

static void move_linked(mapping e, string t, int p);

private void start_link_behaviour() {
  if (!linked_to) {                             // first link
    linked_to = ([]);
    listen_event("move",-100,#'move_linked);
  }
}

private void stop_link_behaviour() {
  if (!sizeof(linked_to)) {
    unlisten_event("move",-100,#'move_linked);
    linked_to = 0;
  }
}

public varargs mixed
query_linked_to(object ob) {
  if (!(linked_to && sizeof(m_delete(linked_to,0))))
    return 0;
  if (ob)
    return member(linked_to,ob);
  else if (extern_call())
    return copy(linked_to);
  else
    return linked_to;
}

public varargs int
add_link_to(object ob) {
  if (!ob || 
      ob==this_object() || 			// can't be linked to self
      environment(ob) !=			// can only link to objects
      environment(this_object()))		// in same environment
    return 0;
  start_link_behaviour();
  linked_to[ob]++;
  return linked_to[ob];
}

public int
remove_link_to(object ob) {
  if (!(ob && query_linked_to(ob)))
    return 0;
  linked_to[ob]--;
  if (!linked_to[ob])
    m_delete(linked_to,ob);
  stop_link_behaviour();
  return linked_to && linked_to[ob];
}

private void
clear_up_links() {
  if (linked_to)
    linked_to = filter_indices(linked_to,#'present,environment());
}

// overload this function, if you want a different reaction-behaviour
void
react_move_linked(mapping e) {
  mixed h;

  h = copy(e);
  h[E_AGENT] = this_object();
  h[E_HANDLED] = 0;
  send_event("move",h,h[E_RECEIVERS]);
}

static void
move_linked(mapping e, string t, int p) {
  mixed h, l;
  if (t != "move")
    return;
  switch (p) {
  case -100:
    clear_up_links();
  }
}
