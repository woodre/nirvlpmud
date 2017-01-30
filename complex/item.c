/*
    complex/item.c - generic item, provides logic for physical items
    Feb 1992 by marion@cs.tu-berlin.de
*/

#pragma strong_types            // Coogan, 24-Aug-2001

#include <prop/item.h>
#include <describe.h>
#include <message.h>
#include <persistence.h>
#include <regexps.h>
#include <global_commands.h>    // added global_, Coogan, 02-May-2001
#include <grammar.h>
#include <event.h>

#if 1  // Alfe 1997-Nov-26
inherit "complex/create";       // added by Alfe 1997-Nov-26
#endif
inherit "basic/description";    /* provide short and long description */
inherit "basic/id";             /* provide for several ids */
inherit "basic/fakeitem";       /* provide for parts of the item */
inherit "basic/property";       /* provide properties */
#if 0  // Coogan, 06-Jan-1999
inherit "basic/move";           /* provide move and encumbrance */
#else
inherit "basic/encumbrance";
#endif
inherit "basic/value";          /* provide value */
inherit "basic/info";           /* provide extra information */
inherit "basic/persistence";    // added by Carador, Oct-1996 
inherit "basic/plural";         // added by Alfe 1996-Jun-18
inherit "basic/holdable";       // added by Ugh Jul-13-1997
inherit "basic/inventory";      // added by Ugh Feb-17-1998
inherit "basic/event_listener"; // added by Ugh Apr-2-1998
#if 1  // 0 ==> 1  Alfe 1998-Apr-28
inherit "basic/breakable";      // added by Coogan, 09-Apr-1998
#endif
inherit "basic/cloned";         // added by Alfe 1998-Apr-23
inherit "basic/vroom_object";   // added by Ugh Mar-11-2002
inherit "basic/material";       // added by Coogan, 11-Oct-2002

// made it varargs, Coogan, 31-May-1999
varargs mixed make_pieces(object source, mapping damage) {
  mixed s,n;
  object result;
  if (!source)  // Coogan, 31-May-1999
    source = this_object();
  result = clone_object("complex/item");
  result->set_id(({ "pieces","remains" }));
  if (s=source->short())
    result->add_id(({ "pieces of " + s }));
  if (n=source->query_name())
    result->add_id(({ "pieces of " + n }));
  result->set_name("pieces");
  result->set_short(s && ("some pieces of " + s));  // keep pieces invis...
  result->set_plural();
  result->set_long(s ?  // fixed typo, Coogan, 31-May-1999
                   "These are the broken remains of " + s + ". You cannot"
                   " make out any specific features anymore, though.\n" :
                   "These are some broken remains of something.\n");
  result->set_encumbrance(source->query_encumbrance());
  result->set_info("Before it was broken, it looked like this:\n" +
                   source->long());
  result->set_break_rules(0);
  return result;
}

void create() {  // Alfe 1998-May-03
  // do our own initialization first
  "basic/cloned"::cloned();
  /* then call the superclass's methods which then also will start the
   * configuring (which shall not be done when we are not yet fully
   * initialized)
   */
  "complex/create"::create();
  "basic/vroom_object"::create();
}

void configure() {  // Alfe 1996-Jun-05
  "complex/create"::configure();  // Alfe 1997-Nov-26
  set_persistence("complex/item", ({   // Carador, Oct-1996
    "encumbrance", "extra_long", "extra_look", "gender",
    PER_PERM_VAR + "persistent_content",  // Coogan, 16-Feb-1997
      // we pile up on ids if we call query_id() which also yields
      // ids of fake items; we call query_real_id() instead,
      // Chameloid, 27-Dec-1997
    ({ "id", "set_id", "query_real_id" }),
    "info",
      // set_items() in /basic/fakeitem wants an array with name and desc
      // alternating; however, query_items() returns an array with first
      // entry the array of names and second entry the array of descs,
      // which where added as single items upon restoring,
      // Chameloid, 27-Dec-1997
    ({ "items", "set_item_descriptions", "query_items" }),
    "long",  "name",  "property", "short", "value",
#if 0  // added the next 2 lines, Coogan, 21-Apr-2002
    "smell", "smell_desc", "touch", "touch_desc",
    "taste", "taste_desc", "sound", "sound_desc",
#endif
    // next one added by Coogan, 09-Nov-2006, as it is currently (Nov-2006)
    // too much overhead to use material::query_persistent_variables()
    "material",
    }));
  set_short("a non-descript item");
  set_long(lambda(0,({ #'capitalize,
                       ({ #'+, ({ #'short }), ".\n" }) })));
  set_break_message(({ ({ M_ME_THE,M_ME_VERB,"break","." }) }));
  set_break_rules(#'make_pieces);
  set_id(({ "item", query_short() }));
}

private string get_state_description(mixed fun) {
  if (pointerp(fun) && !fun[0])
    return call_other(this_object(), fun[1], 0);
#if 1  // Coogan, 06-Jun-1999, changed according to kernel/simul/string
  else if (stringp(fun))
    return fun;
#endif
  else
    return apply_function(fun,0);
}

string strip_state_descriptions(string str) {
  mixed h;
  if (!str || !pointerp(h=query_property(P_STATE_DESCRIPTION)))
      // 'str' might be a null pointer, Chameloid, 12-Oct-1997
    return 0;
  h = map(h,#'get_state_description) - ({ 0 });
  if (!sizeof(h))
    return 0;
  h = "(\\<" + implode(h,"\\>|\\<") + "\\>|[, \t])";
#if 0  // Alfe 2002-Oct-15
  h = h + h + "*";
#else
  h += "+";
#endif
  h = regexplode(str,h);
  if (sizeof(h) > 2 && h[0] == "")
    return implode(h[2..],"");
  return 0;  // Coogan, 17-Mar-2011
}

public int id(string str) {
  mixed h;
  if (id::id(str) || fakeitem::id(str))
    return 1;
  if (!(h=strip_state_descriptions(str)))
    return 0;
  return id::id(h) || fakeitem::id(h);
}

public string *query_id() {
  return (fakeitem::query_id() || ({})) + (id::query_id() || ({}));
}

#if 0
public string short() {
  return
    funcall(description::short());
}
#endif

// varargs added by Coogan, 26-Sep-2010
public varargs string query_long(string str) {
  if (str && query_fakeitem_id(str))
    return funcall(fakeitem::query_long(str));
  return funcall(description::query_long(str));
}

// varargs added by Coogan, 18-May-1998
varargs status get(string str) {  // Alfe 15-Mar-1995
  return !query_property(P_NOT_PORTABLE);
}

varargs status drop(int silently) { // Ugh Jun-13-1995
                   // drop changed by Carador, Feb-1996, added DESTRUCT-
                   // feature and feature of putting messages into the
                   // properties.
  mixed dr, des;

  if ((des = query_property(P_DESTRUCT_ON_DROP)) ||
      (dr = query_property(P_NOT_DROPPABLE))) {
#if 0 // otherwise P_DESTRUCT_ON_DROP wouldn't make any sense anymore with
      // persistence which checks this function silently whenever an autosave
      // is issued causing the destruction of the object although the player
      // didn't really drop it, Chameloid, 25-Sep-1997
    if (des)
      call_out(#'destruct, 0, this_object());
#endif
    if (!silently &&
        query_verb() != "quit" &&
        environment() &&
        query_once_interactive(environment())) {
      if (des) {
        if (intp(des))
          des = 0;
        with_player(environment(), #'message,
                    ({ des || ({ ({ M_WRITE, "As you drop ", M_ME_THE,
                                    " ", M_ME_PRONOUN, M_ME_VERB, "crumble",
                                    " to dust." }) }) }));
        destruct(this_object());
        return 1;
      }
      if (intp(dr)) dr = 0;
      with_player(environment(), #'message,
                  ({ dr || ("You can't drop "+
                            describe(this_object(),ARTICLE_THE)+".\n") }));
    }
    return 1;
  }
  // Ugh Mar-31-1998
#if 1 // Ugh Apr-06-1998 -- non-droppable items can also be persistent
  // wielded weapons will otherwise not be saved, Chameloid, 5-Apr-1998
  return holdable::drop(silently);
#else
  return 0;
#endif
}

// moved from complex/container to here, Coogan, 16-Feb-1998
mixed query_persistent_content() {
  object *inv;
  int i;
  mixed res;

  res = ({ });
  inv = all_inventory()[0..200];     // sorry, no more of me.
  for (i=sizeof(inv); i-->0;) {
    if (get_eval_cost() < 300000) {  // der wert muss so hoch sein, da bei
                                     // vollen bags, d.h. bei grossen daten-
                                     // strukturen das kopieren selbiger
                                     // irrelang dauert (ca. 200.000).
      res += ({ ({ object_name(inv[i]), 0 }) });
    }
    else
      res += ({ ({ object_name(inv[i]), inv[i]->get_state() }) });

    if (environment() &&  // check of command 'persistence', Coogan, 22-Mar-1998
        (environment()->query_quitting() || query_verb() == "persistence") &&
        res[<1][1] &&
        res[<1][1] != -1) // Chameloid, 25-Sep-1997
      destruct(inv[i]);
  }
  return ({ res, time() });
}

void set_persistent_content(mixed arg) {
  object o;
  while (o=first_inventory())  // clean up the inventory; it is re-set due
    destruct(o);               // persistence. Coogan, 22-Mar-1998
  LIB_PERSISTENCE->do_restore_equipment(arg[0], arg[1], this_object());
}

int apply_action(string action,int level,mapping args) {
#if 1  // Alfe 2002-Sep-18
  return 0;
#else
  mixed m;
  switch (action) {
  default:
    return 0;
  case "throw":
    if (args[E_AGENT] != environment())
      return notify_fail("Take " + query_objective() + " first.\n"), 0;
    if (args[E_TARGET]->drop())
      return notify_fail("You can't throw that.\n"), 0;
    if (args[E_OBJECT]) {  // target to throw at/to given
      if (environment(args[E_OBJECT]) != environment(args[E_AGENT]) &&
          args[E_OBJECT] != environment(args[E_AGENT]))
        return notify_fail("You could throw something at a living but not at"
                           " specific items carried by a living.\n"), 0;
      m = ({ M_THE,M_ARG,E_AGENT,M_VERB,"throw",M_ARG,E_AGENT,
             M_OBJECT,M_THE,M_ARG,E_TARGET," ",M_ARG,E_PREPOSITION,
             " ",M_OBJECT,M_THE,M_ARG,E_OBJECT,"." });
      switch (args[E_PREPOSITION]) {
      default:
        return 0;  // don't know what to do then, so don't do anything.
      case "at":
        send_message(m,args);
        if (random(2))
          send_message(({ M_THE,M_ARG,E_TARGET,M_VERB,"miss",M_ARG,E_TARGET,
                          M_OBJECTIVE,M_ARG,E_OBJECT,"." }),args);
        else
          send_message(({ M_THE,M_ARG,E_TARGET,M_VERB,"hit",M_ARG,E_TARGET,
                          M_OBJECTIVE,M_ARG,E_OBJECT,"." }),args);
        move_object(args[E_TARGET], // can be fakeitem, Chameloid, 9-Dec-1998
                    environment(args[E_OBJECT]) || args[E_OBJECT]);
        break;
      case "to":
        send_message(m,args);
        if (random(4))
          send_message(({ M_THE,M_ARG,E_TARGET,M_VERB,"land",M_ARG,E_TARGET,
                          " in front of ",M_OBJECTIVE,M_ARG,E_OBJECT,"." }),
                       args);
        else
          send_message(({ M_THE,M_ARG,E_TARGET,M_VERB,"hit",M_ARG,E_TARGET,
                          M_OBJECTIVE,M_ARG,E_OBJECT,"." }),args);
        move_object(args[E_TARGET], // can be fakeitem, Chameloid, 9-Dec-1998
                    environment(args[E_OBJECT]) || args[E_OBJECT]);
        break;
      }
    }
    else {  // no target to throw at given
      send_message(({ M_THE,M_ARG,E_AGENT,M_VERB,"throw",M_ARG,E_AGENT,
                      M_OBJECT,M_THE,M_ARG,E_TARGET," upwards and ",
                      M_PRONOUN,M_ARG,E_TARGET,M_VERB,"fall",M_ARG,E_TARGET,
                      " down again." }),args);
      move_object(args[E_TARGET],environment(args[E_AGENT]));
    }
    return 1;
  }
#endif
}
