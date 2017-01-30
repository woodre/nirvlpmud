/*
 * A configurable rope, written by Cariade and Coogan, Tubmud, May 1998
 *
 */

// This file is still under construction, don't use it in your code, yet!

#pragma strong_types

#include <event.h>
#include <message.h>
#include <grammar.h>
#include <describe.h>
#include <persistence.h>
#include <prop/item.h>

#define FAIL(who,mess) with_player(who,#'notify_fail,({mess,1}))

inherit "complex/item";

private mapping tied_to = ([ ]);
private int length;
private int strength;   // measured in cm
private object partner;

object
query_partner() {
  return partner;
}

int
query_strength() {
  return strength;
}

mapping
query_tied_to() {
  return tied_to || ([ ]);
}

int
query_length() {
  return length;
}

void
set_partner(object p) {
  partner = p;
}

void
set_strength(int blah) {
  if (blah > 0)
    strength = blah;
}

void
set_tied_to(mapping t) {
  if (sizeof(t) < 3)
    tied_to = t;
}

void
set_length(int l) {
  if (l > 0)
    length = l;
}

void
clean_tied_to() {
  if (!sizeof(query_tied_to()))
    return;
  if (member(query_tied_to(), 0) == 1) {
    if (!query_tied_to()[0])
      set_tied_to(query_tied_to() - ([ 0 ]));
  }
  if (member(query_tied_to(), 1) == 1) {
    if (!query_tied_to()[1])
      set_tied_to(query_tied_to() - ([ 1 ]));
  }
  if (sizeof(query_tied_to()) == 1 && query_tied_to()[1,0])
    set_tied_to(([ 0 : query_tied_to()[1,0] ; query_tied_to()[1,1] ]));
  return;
}

string
query_tied_stage_description(status in_output) {
  clean_tied_to();
  if (!sizeof(query_tied_to()))
    if (in_output)
      return 0;
    else
      return "not tied";
  return
    "tied to "+ describe(query_tied_to()[0], ARTICLE_A, DESCRIBE_SHORT) +
    ((sizeof(query_tied_to()) == 2)
     ?  " and "+describe(query_tied_to()[1], ARTICLE_A, DESCRIBE_SHORT)
     : (query_partner() ? ", held by " + 
                          environment(query_partner())->query_name()
                        : ""));
}

status
get() {
  int s;
  object p;
  if (!s = sizeof(query_tied_to()))
    return 1;
  if (!query_partner()) {  // much easier
    if (s == 1)
      return 1;
    // no partner, tied to two items, can only be in the environment
    send_message(({ M_WRITE, "You first should untie ", M_ME_THE, "." }));
    return 0;
  }
  // now we know, it is tied somewhere, and has a partner rope.
  // (the partner rope can be hold by someone)
  if (query_tied_to()[0] == environment()) {  // we are tied to a fakeitem
    send_message(({ M_WRITE, "You first should untie ", M_ME_THE, "." }));
    return 0;
  }
  // we are tied to a real item.
  if (present(this_object(), environment(this_player()))) {
    if (find_living_environment(query_partner()) && p == this_player()) {
      message("You first should untie the rope.\n");
      return 0;
    }
  }
}

string
short() {
  if (!query_property(P_STATE_DESCRIPTION) && !random(10))
    log_file("state_description", load_name(this_object())+"\n");
  return query_short();
}

void
handle_tie_event(mapping e, string type, int prio) {
  object o, p;
  mapping u;
  if (type != "tie" || e[E_TARGET] != this_object())
    return;
  if (e[E_HANDLED] || e[E_CANCELLED])
    return;
  e[E_HANDLED] = 1;
  if (sizeof(query_tied_to()) +
      (query_partner() && sizeof(query_partner()->query_tied_to())) == 2) {
    FAIL(e[E_AGENT],
         ({({ "You can't tie ", M_THE, this_object(), " to ", M_THE, M_OBJECT,
              e[E_OBJECT], ", because both sides of ", M_PRONOUN,
              this_object(), " are already tied." })}));
    e[E_SUCCESS] = 0;
    return;
  }
  if ((o = find_living_environment(e[E_OBJECT])) && o != e[E_AGENT] &&
      o != e[E_OBJECT]) {
    FAIL(e[E_AGENT], ({({ "You can't tie ", M_THE, this_object(), " to ",
                          M_THE, M_OBJECT, e[E_OBJECT], "." })}));
    e[E_SUCCESS] = 0;
    return;
  }
  if (e[E_OBJECT]->query_fakeitem_id(e[E_OBJECT,1])) {
    if (!e[E_OBJECT]->query_tieable(e[E_OBJECT,1]))
      FAIL(e[E_AGENT], ({({ "You can't tie ", M_THE, this_object(), " to ",
                            M_THE, e[E_OBJECT,1], "." })}));
    else
      FAIL(e[E_AGENT], ({({ "You can't tie ", M_THE, this_object(), " to ",
                            M_THE, e[E_OBJECT], "." })}));
    e[E_SUCCESS] = 0;
    return;
  }
  send_message(({ M_THE, e[E_AGENT], M_VERB, "tie", e[E_AGENT], M_ME_THE,
                  " to ", M_THE, M_OBJECT, e[E_OBJECT], "." }));
  if (!present(e[E_OBJECT], environment())) {
    p = clone_object(load_name(this_object()));
    p->set_name(query_real_name());
    p->set_short(query_real_short());
    p->set_long(query_real_long());
    p->set_id(query_real_id());
    p->set_length(query_length());
    p->set_strength(query_strength());
    p->set_partner(this_object());
    u = ([ 0 : e[E_OBJECT] ; e[E_OBJECT,1] ]);
    if (sizeof(query_tied_to()))
      u += ([ 1 : query_tied_to()[0,0]; query_tied_to()[0,1] ]);
    p->set_tied_to(u);
    move_object(p, environment(e[E_AGENT]));
    set_partner(p);
  } else {
    u = ([ 0 : e[E_OBJECT] ; e[E_OBJECT,1] ]);
    if (sizeof(query_tied_to()))
      u += ([ 1 : query_tied_to()[0,0]; query_tied_to()[0,1] ]);
    set_tied_to(u);
  }
  return;
}

void
handle_untie_event(string type, mapping e, int prio) {
  if (type != "untie" || e[E_TARGET] != this_object())
    return;
  if (e[E_HANDLED] || e[E_CANCELLED])
    return;
  e[E_HANDLED] = 1;
}

void configure() {
  item::configure();
  set_persistence(__FILE__, PER_KEEP_VARS, ({
    "strength", "length",
    }));
  set_name("rope");
  set_short("a rope");
  set_long("This is a rope which can be tied to things.\n");
  set_id(({ "rope" }));
  set_encumbrance(1000);
  set_strength(10000);
  set_length(400);
  set_value(10);
  add_to_property(P_STATE_DESCRIPTION, ({ 0,"query_tied_stage_description" }));
  listen_event("tie",   EPRIO_HANDLE, #'handle_tie_event);
  listen_event("untie", EPRIO_HANDLE, #'handle_untie_event);
//  listen_event("take",  EPRIO_NOTIFY, #'notify_take_event);
//  listen_event("drop",  EPRIO_NOTIFY, #'notify_drop_event);
}

void init() {
  add_action_rule("tie "G_OBJECT" to "G_INDIRECT,     "tie");
  add_action_rule("tie "G_OBJECT" to "G_LIVING,       "tie");
  add_action_rule("untie "G_OBJECT,                   "untie");
  add_action_rule("untie "G_OBJECT" from "G_INDIRECT, "untie");
  add_action_rule("untie "G_OBJECT" from "G_LIVING,   "untie");
}

mixed do_action(string verb,mapping args) {
  mapping e;
  object *where, h;
  int i;
  
  if (args[G_OBJECT] != this_object())
    return 0;
  e = ([
         E_AGENT  : this_player(); this_player()->query_name(),
         E_TARGET : this_object(); describe(this_object(), ARTICLE_NONE),
         E_OBJECT : args[G_INDIRECT] || args[G_LIVING];
                    args[G_INDIRECT,1] || args[G_LIVING]->query_name(),
         E_SUCCESS: 1; 0,
      ]);
  if (!e[E_OBJECT]->short())
    return 0;
  where = ({ environment(this_player()) });
  for (i = 0; i < sizeof(query_tied_to()); i++) {
    h = query_tied_to()[i];
    while (environment(h))
      h = environment(h);
    where += ({ h });
  }

  switch (verb) {
    case "tie":
      send_event("tie", e, where);
      return e[E_SUCCESS];
    case "untie":
      send_event("untie", e, where);
      return e[E_SUCCESS];
    default:
      return 0;
  }
}

#if 0
    case "untie":
	if(args[G_INDIRECT] && args[G_INDIRECT]==query_tied_to()) {
	    send_message(({M_PL_THE,M_PL_VERB,"untie",M_ME_THE," from ",M_THE,args[G_INDIRECT],"."}));
	    set_tied_to(0);
	    return 1;
	}
	if(args[G_LIVING] && args[G_LIVING]==query_tied_to()) {
	    send_message(({M_PL_THE,M_PL_VERB,"untie",M_ME_THE," from ",M_THE,args[G_LIVING],"."}));
	    set_tied_to(0);
	    return 1;
	}
	if(query_tied_to()) {
	    send_message(({M_PL_THE,M_PL_VERB,"untie",M_ME_THE," from ",M_THE,m_indices(query_tied_to())(),"."}));
	    set_tied_to( ([]) );
	    return 1;
	}
	break;
    }
}
#endif

