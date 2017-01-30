#pragma strong_types
#pragma no_shadow  // Coogan, 03-Nov-2009

#include <event.h>

inherit "basic/create";

#define SHARED_VARIABLE "userserver_callbacks"

static object *call_back;

void create () { // Alfe 95/3/10
  if (!(call_back="/etc/shared"->query_global(SHARED_VARIABLE)))
    "/etc/shared"->set_global(SHARED_VARIABLE,call_back=({}));
}

static void notify(string fun, object ob) {
  int i;

  call_back -= ({0});
  if (!(ob && query_once_interactive(ob)))
    return;
  for (i=0 ; i<sizeof(call_back) ; i++)
    efun::call_out("exec_notify",0,({call_back[i],fun,ob->query_vis_name()}));
}

static void exec_notify (mixed *arr) {
  if (objectp(arr[0]))
    call_other(arr[0],arr[1],arr[2]);
}


/*
 * called by /obj/login every time player ob enters the game
 * No, from now on it is called by obj/player.  Alfe 97-Feb-8
 */
void enter (object ob) {
  if (ob && environment(ob))
    send_event("login",([ E_AGENT: ob ]),environment(ob));
  notify("notify_login",ob);
}

void leave (object ob) {
  if (ob && environment(ob))
    send_event("logout",([ E_AGENT: ob ]),environment(ob));
  notify("notify_logout",ob);
}

void petrify (object ob) {
  if (ob && environment(ob))
    send_event("petrify",([ E_AGENT: ob ]),environment(ob));
  notify("notify_petrify",ob);
}

void depetrify (object ob) {
  if (ob && environment(ob))
    send_event("depetrify",([ E_AGENT: ob ]),environment(ob));
  notify("notify_depetrify",ob);
}

/* visible and invisible added by Carador, 24/jun/93, to be called
   by obj/player.c when a player turns visible or invisible */

void visible (object ob) {
  notify("notify_visible", ob);
}

void invisible (object ob) {
  notify("notify_invisible", ob);
}


/*
 * call this function if you want to be notified
 * by the server.
 */
varargs void add_notify(object o) { // Alfe 95/3/10
  if (member(call_back, o || previous_object()) >= 0)
    return;
  call_back += ({ o || previous_object() });
  "/etc/shared"->set_global(SHARED_VARIABLE,call_back);
}

/*
 * call this function if you are nolonger interested
 * in notification messages.
 */
void remove_notify() {
  call_back -= ({ previous_object () });
  "/etc/shared"->set_global(SHARED_VARIABLE,call_back);
}

object *query_call_back () { return call_back && call_back[0..]; }
