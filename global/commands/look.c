#pragma strong_types

#include <describe.h>
#include <grammar.h>
#include <prop/room.h>
#include <prop/item.h>
#include <prop/player.h>
#include <event.h>
#include <message.h>
#include <closures.h>
#include <is_wizard.h>
#include <light.h>      // Coogan, 14-Apr-99
#include <money.h>      // Coogan, 28-Apr-99
#include <alignment.h>  // Alfe 2001-Oct-5
#include <skilltree.h>  // Alfe 2001-Oct-17
#include <assert.h>     // Coogan, 20-May-2004

#define MAX_ITEMS 40

// Coogan, 14-Apr-99, added cases
// INVENTORY_COMPLETELY_FACTORIZED and INVENTORY_ONLY_IN_CONTAINER_FACTORIZED

#define INVENTORY_COMPLETELY_FACTORIZED
// #define INVENTORY_ONLY_IN_CONTAINER_FACTORIZED
// #define INVENTORY_TRADITIONAL

inherit "basic/time";
inherit "basic/create";
inherit "basic/math";
inherit "basic/coloured_string";  // Coogan, 16-Oct-01


void create() {
  listen_event("look");
  set_global_listening_event("look", 1);
}

// Coogan, 14-Apr-99
string test_can_see(object who, object room) {
  if (who? who->test_darkness(room, 1) :
      query_light(room) < LIGHT_DARKNESS_THRESHOLD)
    return room->query_darkness() || "It is too dark to see.\n";
  if (who? who->test_brightness(room, 1) :
      query_light(room) > LIGHT_BRIGHTNESS_THRESHOLD)
    return room->query_brightness() || "It is too bright to see.\n";
  return 0;  // Coogan, 27-Mar-2011
}

varargs string look_at_room(mixed room, int brief, status combined,
                            object who, int turn, status as_view) {
  mixed *inv, h, hh;
  int w, i;
  int shift, shift2;
  string result;
  mixed tmp;
  status swapper, from_long; // 'from_long' flag to not add exits twice,
  from_long = 0;             // Chameloid, 1-Nov-97
  string past_long;
  int li, ri, j;
  string *wrapped_result, verbatim_result;

  // checks by Alfe 2001-Oct-26
  if (!objectp(room))
    if (!stringp(room))
      raise_error("Bad argument 1 to look_at_room()\n");
    else
      room = load_object(room);
  if (who && !objectp(who))
    raise_error("Bad argument 4 to look_at_room()\n");

  if (result = test_can_see(who, room))
    return result;

  if (as_view)
    brief = 1;

  if (brief == 2) {  // extra brief, Coogan, 06-Nov-2002
    tmp = room->query_property(P_LOCAL_PREPOSITION);
    result = (describe(room, 0, DESCRIBE_FULL+DESCRIBE_WITH_STATE) ||
              "somewhere");
    result = tmp ? tmp + " " + result : result;
    tmp = room->query_exit_long(1);
    result = (capitalize(result) +
              (tmp == "" ? "" : ". " + (tmp || "No obvious exits")) + ".\n");
    inv = filter(all_inventory(room), #'living) - ({ who });
                                  // do not look at oneself, if given
    inv = filter(inv, (: !$1->query_property(P_OMIT_FROM_ROOMINV) :));
    				  // ^^^ Alfe 2006-Sep-29
    inv = describe_list(inv, ARTICLE_A, DESCRIBE_FULL+DESCRIBE_WITH_STATE);
    if (sizeof(inv)) {
      result += implode(map(inv[0..MAX_ITEMS], #'capitalize_coloured),
                        ".\n") + ".\n";
      if (sizeof(inv) > MAX_ITEMS)
        result += "*** TRUNCATED ***\n";
    }
    return result;
  }
  if (this_player()->query_show_long_delayed())  // Coogan, 06-Nov-2002
    this_player()->stop_show_long_delayed();

  // some clean up and modifies in the following, Carador, 24-Jul-97
  if (!brief) {  // verbose mode
    // 'who' is the person to exclude from the showed inventory of the room,
    // so better use this_player() if it exists.  Coogan, 30-Nov-97
    w = this_player() && this_player()->query_property(P_DISPLAY_WIDTH) || 79;
    result = room->query_room_long(as_view);  // long+extralong without exits
                                              // we add exits later
    if (!stringp(result)) {
      from_long = 1; // Chameloid, 1-Nov-97
      result = room->long();  /* this room must be very old
                               * do nothing, rooms with
                               * write in long have written
                               * there desc now and here
                               */
    }
    else {   // a rather modern room with query_room_long()
      // for rooms whose room-long is the empty string
      // Ugh Aug-11-97
      if (!strlen(result)) {
        if (room->long())
          from_long = 1; // Chameloid, 1-Nov-97
        result = room->long() || result;
      }
      if (stringp(result) && 
          // Coogan, 30-Nov-97, see above
          this_player() && this_player()->query_property(P_LITTLEMAP) &&
          !room->query_property(P_NO_MAP)) {
        // create a little-map besides the long
        result = LIB_NEARBY->unbreak_long_string(result);
        past_long = "";
        if (!as_view && (tmp=room->query_view()) && sizeof(tmp))
          past_long += ("You have this view: "+ make_list(m_indices(tmp)) +
                        ".\n");
        if (!from_long) // Chameloid, 1-Nov-97
          past_long += room->query_exit_long();  // add the exits here
#define USE_COMBINE_COLUMNS
#ifdef USE_COMBINE_COLUMNS  // Coogan, 09-Sep-2002
        hh = LIB_NEARBY->get_map(room, who, turn);
        while(hh[0] ==  "         ")
          hh = hh[1..];
        while(hh[<1] == "         ")
          hh = hh[0..<2];
        hh = map(hh, (: $1 + " " :));  // Coogan, 10-Sep-2002
        result = LIB_STRINGS->combine_columns(hh, result + past_long, w, 0);
#else
#  if 1  // Coogan, 10-May-2002
        if (strlen_visible(result) != strlen(result)) {
          // ^^^ colour tokens in long?
          h = wrap_coloured_line(result, w-1, 10);
        }
        else {
          h = explode(break_string(result, w-1, 10), "\n") - ({ "" });
        }
#  else
        h = explode(break_string(result, w-1, 10), "\n") - ({ "" });
#  endif
#  if 1  // Coogan, 16-May-2002
        if (strlen_visible(past_long) != strlen(past_long)) { // colour tokens
          h += wrap_coloured_line(past_long, w-1, 10);
        }
        else {
          h += explode(break_string(past_long, w-1, 10), "\n") - ({ "" });
        }
#  else
        h += explode(break_string(past_long, w-1, 10), "\n") - ({ "" });
#  endif
        hh = LIB_NEARBY->get_map(room, who, turn);
                                        /* who added, Carador, 5-Aug-97
                                         * turn added, Alfe 01-Jul-10 */

        while (hh[0] ==  "         ")
          hh = hh[1..];
        while (hh[<1] == "         ")
          hh = hh[0..<2];
        if (sizeof(hh) < sizeof(h))
          shift2 = (sizeof(h)-sizeof(hh)) / 2;
        else
          shift = (sizeof(hh)-sizeof(h)) / 2;
        for (i=sizeof(h); i<sizeof(hh); i++) {
          swapper ^= 1;
          if (swapper)
            h += ({ "           " });
          else
            h  = ({ "           " }) + h;
        }
        for (i=0; i<sizeof(hh); i++)
          h[i+shift2][0..8] = hh[i];
        result = implode(h, "\n") + "\n";
#endif  // COMBINE_COLUMNS
      }
      else if (!from_long) // Chameloid, 1-Nov-97
        result += room->query_exit_long();  // no map, add exits here
    }
  }
  else {  // if (brief)
    tmp = room->query_property(P_LOCAL_PREPOSITION);
    result = (describe(room, 0, DESCRIBE_FULL+DESCRIBE_WITH_STATE) ||
              "somewhere");  // Alfe 96-Mar-18
    result = tmp? tmp + " " + result : result;
  }

  if (!(result && stringp(result)))
    result = "";
  else if (brief && result != "")  // result check added by Coogan, 31-Aug-97
    result = capitalize_coloured(result + ".\n");
  if (brief && !as_view && !room->query_property(P_NO_EXITS_IN_BRIEF) &&
      stringp(tmp=room->query_exit_long(1)) && strlen(tmp))
    result += tmp + ".\n";

  inv = (room->get_inventory() || all_inventory(room)) - ({ who }); 
                                 // do not look at oneself, if given
  inv = filter(inv, (: !$1->query_property(P_OMIT_FROM_ROOMINV) :));
  // ^^^ Alfe 2006-Sep-29
  if (combined)
    inv = describe_list(inv, ARTICLE_A, DESCRIBE_FULL+DESCRIBE_WITH_STATE);
  else
    inv = map(inv, #'describe, ARTICLE_A,
              DESCRIBE_FULL+DESCRIBE_WITH_STATE) - ({ 0 });
  if (sizeof(inv)) {
    result += implode(map(inv[0..MAX_ITEMS], #'capitalize_coloured),
                      ".\n") + ".\n";
    if (sizeof(inv) > MAX_ITEMS)
      result += "*** TRUNCATED ***\n";
  }
  return result;
}

varargs string look_at_environment(object whose, status brief) {
  return look_at_room(environment(whose), brief,
                      whose->query_property(P_COMBINED), whose);
}

varargs string look_at_thing(object who, object ob, string id, int without_inv){
  // fourth arg and varargs added, Coogan, 20-May-2004
  string result;
  mixed *inv;

  assert(who);  // Coogan, 20-May-2004
  assert(ob );  // Coogan, 20-May-2004

  if (result = test_can_see(who, environment(who)))
    return result;

  //  bin/standard wants to know which was the last item the player looked
  //  at to handle the look-failure properly. Carador, Jul-96
  if (ob == environment(who))
    who->set_last_referenced("item", id);
  result = ob->long(id);
  if (!result || !stringp(result))
    result = "";
  inv = ob->get_inventory(id) || all_inventory (ob);

  // changed by Carador, Dec-95 to allow objects to return messages
  // as extra_looks.
  result += implode(map(inv,
                        lambda(({ 'x, 'el }),
                               ({ (#'?),
                                  ({ (#'pointerp),
                                     ({ (#'=), 
                                        'el, 
                                        ({ (#'call_other),
                                           'x,
                                           "extra_look" }) }) }),
                // added #'capitalize and CL_L_RANGE-part below  Alfe 96-Feb-21
                                  ({ (#'capitalize_coloured),
                                     ({ (#'message2string),
                                        ({ CL_L_RANGE, 'el, 0 }),
                                        who }) }),
                                  'el }))) +
                    ({ "" }), ".\n");
  
  if (ob == environment(who)    ||
      !sizeof(inv)              ||
      ob->hide_inventory(id)    ||
      ob->query_fakeitem_id(id) ||
      without_inv)
    return result;
  if (who->query_property(P_COMBINED))
    inv = describe_list(inv, ARTICLE_A, DESCRIBE_FULL+DESCRIBE_WITH_STATE);
  else
    inv = (map(inv, #'describe, ARTICLE_A, DESCRIBE_FULL+DESCRIBE_WITH_STATE) -
           ({ 0 }));
  if (!sizeof(inv))
    return result;
  if (living(ob))
    result += ("  " +
               capitalize_coloured(message2string(({ M_PRONOUN, ob, 
                                                     M_VERB, "are", ob }),
                                                  who)) +
               " carrying");
  else if (ob->query_property(P_SURFACE, id))
    result += ("  " +
               "On " + (ob->query_objective() || "it") +   // Carador, May-96
               " you can see");
  else
    result += ("  " +
               capitalize_coloured(message2string(({ M_PRONOUN, ob, 
                                                     M_VERB, "contain", ob }),
                                                  who)));
  if (who->query_property(P_ADD_INVENTORY)) {
    result += ":\n  ";
    result += implode(map(inv[0..MAX_ITEMS], #'capitalize_coloured),
                      ".\n  ") + ".\n";
    if (sizeof(inv) > MAX_ITEMS)
      result += "*** TRUNCATED ***\n";
  }
  else
    result += " something.\n";
  return result;
}

int do_action(string action, mapping args) {
  mixed *inv, h;
  int i, size;
  object ob;
  switch (action) {
  case "examine_all":
    args[G_INDIRECT, 1] = args[G_ALL, 1][0];
    size = args[G_ALL, 1][1] || sizeof(args[G_ALL]);
    for (i=0; i<size; i++) {
      args[G_INDIRECT] = args[G_ALL][i];
      do_action("examine", args);
    }
    return 1;
  case "look":
  case "see":
  case "glimpse":  // Coogan, 07-Nov-2002
    send_event("look", ([ E_AGENT: this_player(),
                          E_TARGET: environment(this_player()),
                          E_TYPE: action ]), environment(this_player()));
    return 1;
  case "look_view":
    send_event("look", ([ E_AGENT: this_player(); 0,
                          E_TARGET: load_object(args[G_VIEW, 1]); args[G_VIEW],
                          E_TYPE: "look_view"; 0 ]),
               ({ environment(this_player()), load_object(args[G_VIEW, 1]) }));
    return 1;
  case "show_all":
    send_event("look", ([ E_AGENT: this_player(),
                          E_TARGET: args[G_LIVING],
                          E_OBJECT: args[G_ALL_IN_INVENTORY],
                          E_ID: args[G_ALL_IN_INVENTORY, 1],
                          E_TYPE: action,
                          E_MESSAGES:
                          ([ 0: ({ M_THE, M_ARG, E_AGENT, M_ADVERBS,
                                   M_VERB, "show", M_ARG, E_AGENT,
                                   M_POSSESSIVE, M_ARG, E_AGENT,
                                   M_OBJECT, M_NONE, M_ARG, E_OBJECT, " to ",
                                   M_THE, M_OBJECT, M_ARG, E_TARGET, "." })
                          ]) ]),
               environment(this_player()));
    return 1;
  case "show":
    send_event("look", ([ E_AGENT: this_player(),
                          E_TARGET: args[G_LIVING],
                          E_OBJECT: args[G_IN_INVENTORY],
                          E_ID: args[G_IN_INVENTORY, 1],
                          E_TYPE: action,
                          E_MESSAGES:  // Alfe 98-Apr-24
                          // M_THE after " to " added, Coogan, 05-Jul-98
                          ([ 0: ((args[G_IN_INVENTORY]->
                                  query_fakeitem_id(args[G_IN_INVENTORY, 1]))?
                                 ({ M_THE, M_ARG, E_AGENT, M_ADVERBS,
                                    M_VERB, "show", M_ARG, E_AGENT,
                                    M_POSSESSIVE, M_ARG, E_AGENT, " ",
                                    M_ARG, E_ID, " to ", M_THE,
                                    M_OBJECT, M_ARG, E_TARGET, "." }) :
                                 ({ M_THE, M_ARG, E_AGENT, M_ADVERBS,
                                    M_VERB, "show", M_ARG, E_AGENT,
                                    M_POSSESSIVE, M_ARG, E_AGENT,
                                    M_OBJECT, M_NONE, M_ARG, E_OBJECT, " to ",
                                    M_THE, M_OBJECT, M_ARG, E_TARGET, "." }))
                          ]) ]),
               environment(this_player()));
    return 1;
  case "examine_place":
    args = ([ G_INDIRECT: environment(this_player()); 0 ]);
    return do_action("examine", args);
  case "examine":
    send_event("look", ([ E_AGENT: this_player(),
                          E_TARGET: args[G_INDIRECT],
                          E_ID: args[G_INDIRECT, 1],
                          E_TYPE: action ]), environment(this_player()));
    return 1;
    // these two macros must be the same as in bin/standard!
#define OBJECT2 "<object2>"
#define LIVING2 "<living2>"
  case "est_weight":
  case "est_light":
  case "est_value":
  case "est_quality":
  case "est_strength":
  case "est_condition":
  case "est_alignment":
  case "est_age":
  case "est_load":
  case "est_weapon":
  case "est_armour":
  case "est_health":
    if (action == "est_weight") {
      // next check added by Coogan, 09-Oct-01
      if (!member(args, G_OBJECT))  // we're coming from command 'weigh item'
        args[G_OBJECT] = args[G_ONLY_IN_INVENTORY];
      if (environment(args[G_OBJECT]) != this_player())
        return notify_fail(({ ({ M_WRITE,
                                 M_PL_THE, M_PL_VERB, "don't", " have ",
                                 M_OBJECT, M_THE, args[G_OBJECT],
                                 " in ", M_PL_POSSESSIVE, " hands." }) })), 0;
    }
    if (!args[G_OBJECT] && !args[G_LIVING] &&
        !this_player()->query_attack())
      return notify_fail(({ ({ M_WRITE,
                               "As you are not in a fight, please name a"
                               " target of your estimation." }) })), 0;
    send_event("look", ([ E_AGENT: this_player(),
                          E_TARGET: (args[G_OBJECT] || args[G_LIVING] ||
                                     this_player()->query_attack()),
                          E_ID: args[G_OBJECT, 1] || args[G_LIVING, 1],
                          E_TYPE: action,
                          E_MESSAGES:  // Alfe 98-Apr-24
                          ([ 0: ({ M_THE, M_ARG, E_AGENT,
                                   M_VERB, "estimate", M_ARG, E_AGENT,
                                   M_OBJECT, M_THE, M_ARG, E_TARGET,
                                   M_ADVERBS, "." }) ]) ]),
               environment(this_player()));
    return 1;
  case "cmp_weight":
  case "cmp_light":
  case "cmp_value":
  case "cmp_quality":
  case "cmp_strength":
  case "cmp_condition":
  case "cmp_alignment":
  case "cmp_age":
  case "cmp_load":
  case "cmp_weapon":
  case "cmp_armour":
  case "cmp_health":
    if (action == "cmp_weight") {
      if (environment(args[G_OBJECT]) != this_player())
        return notify_fail(({ ({ M_WRITE,
                                 M_PL_THE, M_PL_VERB, "don't", " have ",
                                 M_OBJECT, M_THE, args[G_OBJECT],
                                 " in ", M_PL_POSSESSIVE, " hands." }) })), 0;
      if (environment(args[OBJECT2]) != this_player())
        return notify_fail(({ ({ M_WRITE,
                                 M_PL_THE, M_PL_VERB, "don't", " have ",
                                 M_OBJECT, M_THE, args[OBJECT2],
                                 " in ", M_PL_POSSESSIVE, " hands." }) })), 0;
    }
    if (!args[G_OBJECT] && !args[G_LIVING] &&
        !this_player()->query_attack())
      return notify_fail(({ ({ M_WRITE,
                               "Please name two targets of your"
                               " estimation." }) })), 0;
    {
      object *targets;
      targets = ({ (args[G_OBJECT] || args[G_LIVING] ||
                    this_player()->query_attack()),
                   (args[OBJECT2] || args[LIVING2] ||
                    this_player()) });
      if (targets[0] == targets[1])
        return notify_fail("You cannot compare something with itself.\n"), 0;
      send_event("look", ([ E_AGENT: this_player(),
                            E_TARGET: targets,
                            E_ID: args[G_OBJECT, 1] || args[G_LIVING, 1],
                            E_TYPE: action,
                            E_MESSAGES:  // Alfe 98-Apr-24
                            ([ 0: ({ M_THE, M_ARG, E_AGENT,
                                     M_VERB, "compare", M_ARG, E_AGENT,
                                     M_OBJECT, M_THE, M_ARG, E_TARGET,
                                     M_ADVERBS, "." }) ]) ]),
                 environment(this_player()));
    }
    return 1;
  case "look_into":  // Coogan, 15-Apr-2003
    if (!args[G_OBJECT])
      return 0;
    // a cheap test if it's a container
    if (!args[G_OBJECT]->query_container_max_encumbrance())
      return notify_fail("You can't look into " +
                         describe(args[G_OBJECT], ARTICLE_THE) + ".\n");
    if (!args[G_OBJECT]->query_open())
      return notify_fail(({ ({ M_WRITE, "But ", M_THE, args[G_OBJECT], M_VERB,
                               "be", args[G_OBJECT], " not open!" }) }));
    send_event("look", ([ E_AGENT : this_player(),
                          E_TARGET: args[G_OBJECT],
                          E_ID    : args[G_OBJECT, 1],
                          E_TYPE  : action ]), environment(this_player()));
    return 1;
  case "inventory":
  case "equipment":
    if (args[G_ALL])
      h = args[G_ALL][0..args[G_ALL, 1][1]-1];
    else
      h = ({ this_player() });
    send_event("look", ([ E_AGENT: this_player(),
                          E_TARGET: h,
                          E_ID : (args[G_ALL] ? args[G_ALL, 1][0] : 0),
                          E_TYPE: action ]), environment(this_player()));
    return 1;
  case "toggle_map":
    if (this_player()->query_property(P_LITTLEMAP)) {
      this_player()->remove_property(P_LITTLEMAP);
      write("Map next to room descriptions turned off.\n");
    }
    else {
      this_player()->set_property(P_LITTLEMAP);
      write("Map next to room descriptions turned on.\n");
    }
    break;
  case "toggle_combined":
    if (this_player()->query_property(P_COMBINED)) {
      this_player()->remove_property(P_COMBINED);
      write("Combined short descriptions turned off.\n");
    }
    else {
      this_player()->set_property(P_COMBINED);
      write("Combined short descriptions turned on.\n");
    }
    break;
  case "toggle_inventory":
    if (this_player()->query_property(P_ADD_INVENTORY)) {
      this_player()->remove_property(P_ADD_INVENTORY);
      write("Adding of inventory turned off.\n");
    }
    else {
      this_player()->set_property(P_ADD_INVENTORY);
      write("Adding of inventory turned on.\n");
    }
    break;
  case "toggle_hide_autoloads":  // Coogan, 28-Apr-99
    if (this_player()->query_property(P_HIDE_AUTOLOADS)) {
      this_player()->remove_property(P_HIDE_AUTOLOADS);
      message("Hiding of autoloads in look at inventory turned off.\n");
    }
    else {
      this_player()->set_property(P_HIDE_AUTOLOADS);
      message("Hiding of autoloads in look at inventory turned on.\n");
    }
    break;
  default:
    return 0;
  }
  return 1;
}

// the next two functions are needed for INVENTORY_COMPLETELY_FACTORIZED
// Coogan, 14-Apr-99
private string factorize_object(object o, string id) {
  string d;
  if (!o->short())
    return 0;
  d = describe(o, ARTICLE_A, DESCRIBE_FULL + DESCRIBE_WITH_STATE);
  if (o->can_put_and_get() && !o->hide_inventory(id) &&
      sizeof(all_inventory(o)))
    d += LIB_ID->string_id();
  return d;
}

// this functions tries to preserve the shown order of items in the inventory
// after factorizing (the sum of all values of m should be o without invisible
// items).
private mixed* preserve_order(mapping m, object *o) {
  mixed * result;
  object ob;
  int i;
  string *mi;

  result = ({});
  while (sizeof(o)) {
    if (!o[0]->short()) {
      o -= ({ o[0] });
      continue;
    }
    mi = m_indices(m);
    for (i = 0; i < sizeof(mi); i++) {
      if (member(m[mi[i]], o[0]) > -1) {
        result += ({ m[mi[i]][0..] });
        o -= m[mi[i]];
        m -= ([ mi[i] ]);
        continue;
      }
    }
  }
  return result;
}

private varargs string make_inventory_output(string desc, int halfwidth) {
  string *lines, *split_lines, verbatim_line, verbatim_line_start;
  string *wrapped_lines;
  string result;
  int i, j, li, ri; 
  int single_column;

  result = "";
  lines = explode(desc, "\n") - ({ "" });
  i = 0;

  if (!halfwidth)
    halfwidth = this_player()->query_property(P_DISPLAY_WIDTH) / 2 - 1;

  // for short inventories, use a single column output with full width.
  // Coogan, 25-Sep-2006
  if (sizeof(lines) < 4) {
    single_column = 1;
    halfwidth *= 2;
  }

  // rewrote this function; it now breaks too long lines. Coogan, 14-Jan-01
  while (i < sizeof(lines)) {
    if (strlen((verbatim_line = to_verbatim(lines[i]))) > halfwidth) {
                                   // we have to wrap this line
                                   // verbatim() usage by Coogan, 16-Oct-01
      // rewritten by Coogan, 16-Oct-01
      // improvements and fixes by Alfe, 17-Oct-01, Coogan, 18-Oct-01
      li = 0; ri = 0;
#if 1  // Coogan, 18-Oct-01
      if (verbatim_line[0..4] == "  -> ") {
        verbatim_line_start = verbatim_line[0..4];
        wrapped_lines = explode(break_string(verbatim_line[5..], halfwidth-5),
                                "\n");
      } else {
        verbatim_line_start = verbatim_line[0..1];
        wrapped_lines = explode(break_string(verbatim_line[2..], halfwidth-2),
                                "\n");
      }
      wrapped_lines[0] = verbatim_line_start + wrapped_lines[0];
#else
      wrapped_lines = explode(break_string(verbatim_line, halfwidth), "\n");
#endif
      split_lines = ({});
      for (j = 0; j < sizeof(wrapped_lines); j++) {
        li = strstr(verbatim_line, wrapped_lines[j], li);
        ri = li + strlen(wrapped_lines[j]);
        if (li > 0) {
          if (verbatim_line_start == "  -> ")
            split_lines += ({ "     " + subcoloured_string(lines[i], li, ri) });
          else
            split_lines += ({ "  " + subcoloured_string(lines[i], li, ri) });
        }
        else 
          split_lines += ({ subcoloured_string(lines[i], li, ri) });
      }
      lines[i..i] = split_lines;
      i += sizeof(split_lines) - 1;  // skip the inserted lines
    }
    i++;
  }
  if (sizeof(lines) % 2)
    lines += ({ "" });
  j = sizeof(lines) / 2;
  if (single_column) {
    for (i = 0; i < sizeof(lines); i++) {
      result += sprintf("%-" +
                        (halfwidth + strlen(lines[i]) -
                         strlen_visible(lines[i]) + 1) + "s\n",
                        lines[i]);
    }
  }
  else {
    for (i = 0; i < j; i++) {
      // take care of different strlen() vs. strlen_visible(), Coogan, 16-Oct-01
      result += sprintf("%-" +
                        (halfwidth + strlen(lines[i]) -
                         strlen_visible(lines[i]) + 1) + "s%-" +
                        (halfwidth + strlen(lines[i+j]) -
                         strlen_visible(lines[i+j])) + "s\n",
                        lines[i], lines[i+j]);
    }
  }
  return result;
}

string look_at_equipment(mixed ob, string id) {
  if (pointerp(ob))
    return implode(map(ob, #'look_at_equipment, id), "\n");
  if (ob->hide_inventory(id))
    return "The equipment is completely hidden.\n";
  return LIB_EQUIPMENT->describe_equipment(ob);
}

varargs string look_at_inventory(mixed ob, string id, int depth) {
               // depth argument added for INVENTORY_COMPLETELY_FACTORIZED
               // due to recursive behaviour, Coogan, 14-Apr-99
               // added varargs modifier  Alfe 2001-Oct-16
  int i, j;
  string description, s, desc;
  mixed h;
  object *inv, *n0, *n1, *n2, en;
  mapping m0, m1, m2;
  string *si, *t, *s2;
  int k, width;
  closure cl;

  if (description = test_can_see(this_player(), environment(this_player())))
    return description;
  description = "";
  if (objectp(ob))
    ob = ({ ob });
  width = this_player()->query_property(P_DISPLAY_WIDTH) / 2 - 1;

#ifdef INVENTORY_TRADITIONAL

  for (j=sizeof(ob); j; j--) {
    h = 0;
    // P_HIDE_AUTOLOADS checks by Coogan, 28-Apr-99
    if (ob[<j]->query_auto_load() &&
        !ob[<j]->query_property(P_COINS) &&
        this_player()->query_property(P_HIDE_AUTOLOADS))
      continue;
    if (ob[<j] != this_player() && ob[<j]->hide_inventory(id))
      continue;
    h = ob[<j]->get_inventory(id) || all_inventory(ob[<j]);
    h = filter_objects(h, "short");  // Coogan, 03-Jul-99
    if (this_player()->query_property(P_HIDE_AUTOLOADS)) {  // Coogan
      en = present_property(P_COINS, ob[<j]);
      h -= filter_objects(h, "query_auto_load");
      if (en)
        h += ({ en });
    }
    if (this_player()->query_property(P_COMBINED))
      h = describe_list(h, ARTICLE_A, 
                        DESCRIBE_FULL+DESCRIBE_WITH_STATE+
                        DESCRIBE_WITH_INVENTORY);
                                    // Ugh Jul-17-1996
    else
      h = map(h, #'describe, ARTICLE_A,
              DESCRIBE_FULL+DESCRIBE_WITH_STATE) - ({ 0 });
    for (i=sizeof(h); i-->0; )
      h[i] = capitalize_coloured(h[i] + ".\n");
    h = sizeof(h) && sprintf("%-78#s\n", implode(h, ""));
    if (h && sizeof(ob) > 1) {
      description += "\n";
      s = describe(ob[<j], ARTICLE_THE, DESCRIBE_SHORT, -1);
      if (s)
        description += capitalize_coloured(s) + ":\n";
      description += h;
    }
    else if (h)
      description += h;
    else if (sizeof(ob) < 2)
      description += "Nothing.\n";
  }
  return description;
#endif

#ifdef INVENTORY_COMPLETELY_FACTORIZED
  switch (depth) {
    case 2:
      desc = "";
      ob = filter_objects(ob, "short");  // Coogan, 03-Jul-99
      if (this_player()->query_property(P_COMBINED)) {
        m2 = factorize(ob, #'describe,
                       ({ ARTICLE_A, DESCRIBE_FULL+DESCRIBE_WITH_STATE }));
        s2 = m_indices(m2);
        for (k = 0; k < sizeof(s2); k++) {
          desc += "  -> " + describe(m2[s2[k]][0], ARTICLE_A,
                                     DESCRIBE_FULL + DESCRIBE_WITH_STATE,
                                     sizeof(m2[s2[k]])) + "\n";
        }
      }
      else {
        for (k = 0; k < sizeof(ob); k++) {
          desc += "  -> " + describe(ob[k], ARTICLE_A,
                                     DESCRIBE_FULL+DESCRIBE_WITH_STATE) + "\n";
        }
      }
      return desc;

    case 1:
      desc = "";
      // added check for sizeof(ob), Coogan, 19-Jun-01
      if (!sizeof(ob) || !ob[0]->short())  // Coogan, 03-Jul-99
        return desc;
      if (this_player()->query_property(P_COMBINED)) {
        desc += "- " + describe(ob[0], ARTICLE_A,
                                DESCRIBE_FULL + DESCRIBE_WITH_STATE,
                                sizeof(ob)) + "\n";
        // open containers with contents are given separately, if P_COMBINED
        if (ob[0]->can_put_and_get()   &&
            !ob[0]->hide_inventory(id) &&
            first_inventory(ob[0])     &&
            find_living_environment(ob[0]) == this_player())
          desc += look_at_inventory(all_inventory(ob[j]), id, 2);
      }
      else {
        for (j = 0; j < sizeof(ob); j++) {
          desc += "- " + describe(ob[j], ARTICLE_A,
                                  DESCRIBE_FULL+DESCRIBE_WITH_STATE) + "\n";
          if (ob[j]->can_put_and_get()   &&
              !ob[j]->hide_inventory(id) &&
              first_inventory(ob[j])     &&
              find_living_environment(ob[j]) == this_player())
            desc += look_at_inventory(all_inventory(ob[j]), id, 2);
        }
      }
      return desc;

    case 0:
      ob -= filter_objects(ob, "hide_inventory", id);
      if (!sizeof(ob))
        return "The complete inventory is hidden.\n";
      if (this_player()->query_property(P_COMBINED)) {
        inv = all_inventory(ob[0]);
        inv = filter_objects(inv, "short");  // Coogan, 03-Jul-99
        // P_HIDE_AUTOLOADS checks by Coogan, 28-Apr-99
        if (this_player()->query_property(P_HIDE_AUTOLOADS)) {
          en = present_property(P_COINS, ob[0]);
          inv -= filter_objects(inv, "query_auto_load");
          if (en)
            inv += ({ en });
        }
        m0 = factorize(inv, #'factorize_object, ({ id }));
        m0 -= ([ 0 ]);
        n0 = preserve_order(m0, inv);
        for (i = 0; i < sizeof(n0); i++) {
          description += look_at_inventory(n0[i], id, 1);
        }
      }
      else {
        for (i = 0; i < sizeof(ob); i++) {
          inv = all_inventory(ob[i]);
          inv = filter_objects(inv, "short");  // Coogan, 03-Jul-99
          // next if() by Coogan, 28-Apr-99
          if (this_player()->query_property(P_HIDE_AUTOLOADS)) {
            en = present_property(P_COINS, ob[i]);
            inv -= filter_objects(inv, "query_auto_load");
            if (en)
              inv += ({ en });
          }
          description += look_at_inventory(inv, id, 1);
        }
      }
      if (description == "")
        description = "Nothing.\n";
      break;

    default:
      return "";
  }
  return make_inventory_output(description, width);
#endif

#ifdef INVENTORY_ONLY_IN_CONTAINER_FACTORIZED
  desc = "";
  cl = lambda(({ 'x }), ({ #'call_other, 'x, "short" }));

  ob -= filter_objects(ob, "hide_inventory", id);
  ob = filter_objects(ob, "short");  // Coogan, 03-Jul-99

  if (!sizeof(ob))
    return "The complete inventory is hidden.\n";
  for (k = 0; k < sizeof(ob); k++) {
    if (this_player()->query_property(P_HIDE_AUTOLOADS) && // Coogan, 28-Apr-99
        ob[k]->query_auto_load() &&
        !ob[k]->query_property(P_COINS))
      continue;
    inv = all_inventory(ob[k]);
    for (i = 0; i < sizeof(inv); i++) {
      if (!inv[i]->short())
        continue;
      if (this_player()->query_property(P_HIDE_AUTOLOADS) &&
          // ^^^ Coogan, 28-Apr-99
          inv[i]->query_auto_load() &&
          !inv[i]->query_property(P_COINS))
        continue;
      desc += ("- " + describe(inv[i], ARTICLE_A,
                               DESCRIBE_FULL + DESCRIBE_WITH_STATE) + "\n");
      if (living(ob[k]) && this_player() != ob[k] ||
          inv[i]->hide_inventory(id)              ||
          !sizeof(filter_objects(all_inventory(inv[i]), "short") - ({ 0 }))) {
        continue;
      }
      else {
        h = filter(all_inventory(inv[i]), cl) - ({ 0 });
        if (this_player()->query_property(P_COMBINED)) {
          h = factorize(h, #'describe,
                        ({ ARTICLE_A, DESCRIBE_FULL+DESCRIBE_WITH_STATE }));

          si = m_indices(h);
          for (j = 0; j < sizeof(h); j++) {
            desc += ("  -> " + describe(h[si[j]][0], ARTICLE_A,
                                        DESCRIBE_FULL+DESCRIBE_WITH_STATE,
                                        sizeof(h[si[j]])) + "\n");
          }
        } else {
          for (j = 0; j < sizeof(h); j++) {
            desc += ("  -> " + describe(h[j], ARTICLE_A,
                                        DESCRIBE_FULL+DESCRIBE_WITH_STATE) +
                     "\n");
          }
        }
      }
    }
    if (desc == "")
      desc = "Nothing.\n";
    description += desc;
  }
  return make_inventory_output(description);
#endif
}

private string describe_weight(int weight) {
  switch (weight) {
  case            0: return "nothing";
  case     1..  100: return "less than an apple";
  case   101..  300: return "about as much as an apple";
  case   301.. 1500: return "less than a melon";
  case  1501.. 3000: return "about as much as a melon";
  case  3001.. 5000: return "more than a melon";
  case  5001.. 8000: return "about as much as a small bucket full of water";
  case  8001..12000: return "about as much as a large bucket full of water";
  case 12001..20000: return "more than a large bucket full of water";
  default:
    if (weight < 0)
      return "less than nothing";
    else
      return "much more than a large bucket full of water";
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

private string describe_light(int light) {
  switch (light) {
  case 0..LIGHT_DARKNESS_THRESHOLD/5-1:
    return "no light";
  case LIGHT_DARKNESS_THRESHOLD/5..LIGHT_CANDLE*3/2-1:
    return "about as much light as a candle";
  case LIGHT_CANDLE*3/2..LIGHT_TORCH*2/3-1:
    return "less light than a normal torch";
  case LIGHT_TORCH*2/3..LIGHT_TORCH*2-1:
    return "about as much light as a normal torch";
  case LIGHT_TORCH*2..LIGHT_LAMP*3-1:
    return "about as much light as a normal lamp";
  default:
    if (light < 0)
      return "an evil kind of darkness";
    else
      return "an awful lot of light";
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

private string describe_value(int value) {
  return LIB_MONEY->describe_money(value);
}

private string describe_armour_quality(int class) {
  switch (class) {
  case 0   : return "useless";
  case 1   : return "a useful armourpart";
  case 2   : return "a good armour";
  case 3..4: return "a very good armour";
  default  : return "a fantastic armour";
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

private string describe_weapon_quality(int class) {
  switch (class) {
  case  0    : return "useless";
  case  1.. 4: return "a rather primitive weapon";
  case  5..10: return "a normal weapon";
  case 11..15: return "a good weapon";
  case 16..19: return "a very good weapon, but hard to handle";
  default    : return "a fantastic weapon, but very hard to handle";
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

private string describe_strength(int strength) {
  return "like someone with strength " + strength;
}

private string describe_condition(int condition) {
  switch (condition) {
  case   0..  50: return "like an easy target";
  case  51.. 150: return "like a medium target";
  case 151.. 300: return "like a tough target";
  case 301..1000: return "very powerful";
  default       : return "extremely powerful";
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

private string describe_alignment(int alignment) {
  switch (alignment) {
  case AL_DEMONIC  ..AL_EVIL   : return "demonic";
  case AL_EVIL   +1..AL_NASTY  : return "evil";
  case AL_NASTY  +1..AL_NEUTRAL: return "nasty";
  case AL_NEUTRAL+1..AL_NICE   : return "neutral";
  case AL_NICE   +1..AL_GOOD   : return "nice";
  case AL_GOOD   +1..AL_SAINTLY: return "good";
  default                      : return "saintly";
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

private string describe_age(int age) {
  return "about " + implode(explode(heart_long(age), " ")[0..1], " ") + " old";
}

private string describe_load(int load) {
  switch (load) {
  case         0: return "carry nothing";
  case   1.. 100: return "carry nearly nothing";
  case 101.. 300: return "carry just a few things";
  case 301.. 600: return "be about half-loaded";
  case 601.. 800: return "be heavily loaded";
  case 801..1000: return "be fully loaded";
  default       : return "be overloaded";
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

private string describe_weapon(int weapon) {
  return "to have " + describe_weapon_quality(weapon);
}

private string describe_armour(int armour) {
  switch (armour) {
  case    0: return "unarmed";
  case 1..2: return "lightly armed";
  case 3..4: return "armed";
  default  : return "heavily armed";
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

private string describe_health(int health) {
  switch (health) {
    // values and descriptions taken from ereborn's monster spectacles.
    // and changed a little bit -- Alfe 2004-Apr-22
  case      0: return "dead";
  case  1..11: return "nearly dead";
  case 12..23: return "in a bad condition";
  case 24..35: return "not in a good condition";
  case 36..49: return "almost in normal condition";
  case 50..61: return "in normal condition";
  case 62..73: return "in good condition";
  case 74..84: return "in very good condition";
  case 85..92: return "in superb condition";
  case 93..97: return "in almost excellent condition";
  default    : return "in excellent condition";
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

int light_of(object o) {
#if 1
  if (environment(o))
    return query_inner_light_sources(environment(o))[o];
  else  // a room?
    return query_own_light(o);
#else
  return (o->query_arm_light() ||
          o->query_light() ||
          fold_left((#'+),
                    m_values(filter(query_light_sources(o),
                                    (: member($3, $1) :),
                                    mkmapping(deep_inventory(o))))));
#endif
}

void receive_event(mapping e, string type, int prio) {
  int i, j;
  mixed h;
  mixed agent;
  string description;
  object fading_blindness;
  if (e[E_HANDLED])
    return;
  e[E_HANDLED] = 1;  // we will handle it now
  agent = e[E_AGENT];
  switch (type) {
  default:
    raise_error("Internal error '" + type + "'\n");
  case "look":
    switch (e[E_TYPE]) {
    default:
      raise_error("Internal error '" + e[E_TYPE] + "'\n");
    case "look_into":
      if (!e[E_ID])     // this is a look_into event to neighbour rooms,
        break;          // skip it.
      // next part by Coogan, 15-Apr-2003
      send_message(({ M_PL_THE, M_PL_VERB, "look", " into ", M_THE, M_ARG,
                      E_TARGET, "." }), e);
      if ((i=sizeof((h=all_inventory(e[E_TARGET])))))
        send_message(({ M_WRITE, "This ", M_NONE, M_ARG, E_TARGET, M_VERB,
                        "seem", M_ARG, E_TARGET, " to contain ",
                        M_SIMPLE_DESCRIBE, h, "." }), e);
      else
        send_message(({ M_WRITE, "This ", M_NONE, M_ARG, E_TARGET, M_VERB,
                        "seem", M_ARG, E_TARGET, " to contain nothing." }), e);
      break;
    case "look":
    case "see":
    case "glimpse":  // Coogan, 07-Nov-2002
    case "look_view":
      h = agent->query_property(P_DISPLAY_WIDTH) || 79;
      tell_object(agent,
                  break_string(look_at_room(e[E_TARGET],
                                            (e[E_TYPE]=="see"? 1 :
                                             (e[E_TYPE]=="glimpse"? 2 : 0)),
                                            agent->query_property(P_COMBINED),
                                            agent, 0, e[E_TYPE]=="look_view"),
                               h));
      if (!agent->test_sight(0, 1) &&            // cannot see
          e[E_TARGET] == environment(agent)) {  // looked at his own room?
        if (fading_blindness=present_clone("obj/fading_blindness", agent))
          destruct(fading_blindness);
        move_object(fading_blindness=clone_object("obj/fading_blindness"),
                    agent);
        fading_blindness->set_command(e[E_TYPE]);
      }
      break;
    case "inventory":
    case "equipment":
      // added the next complete if (), Coogan, 03-Jul-99
      if (e[E_ID] && e[E_TARGET][0]->query_fakeitem_id(e[E_ID])) {
        description = look_at_thing(agent, e[E_TARGET][0], e[E_ID]);
        h = agent->query_property(P_DISPLAY_WIDTH) || 79;
#if 0  // Coogan, 10-Feb-02, tell_more() and tell_object() break, too
        description = break_string(description, h);
#endif
        if (!call_resolved(&h, agent, "tell_more", description))
          tell_object(agent, description);
        break;
      }
      description = with_player(agent, (e[E_TYPE] == "equipment"?
                                        (#'look_at_equipment) :
                                        (#'look_at_inventory)),
                                ({ e[E_TARGET], e[E_ID] }));
      tell_object(agent, description);
      break;
    case "show":
      map_messages(e[E_MESSAGES], e);
      h = e[E_TARGET]->query_property(P_DISPLAY_WIDTH) || 79;
#if 0  // Coogan, 10-Feb-02: use the target's t_c_closure()!
      tell_object(e[E_TARGET],
                  break_string(with_player(e[E_TARGET], #'look_at_thing,
                                           ({ e[E_TARGET], e[E_OBJECT],
                                              e[E_ID] })) || "", h));
#else
      tell_object(e[E_TARGET],
                  terminal_colour(with_player(e[E_TARGET], #'look_at_thing,
                                              ({ e[E_TARGET], e[E_OBJECT],
                                                 e[E_ID] })) || "",
                                  e[E_TARGET]->get_terminal_colour_closure(),
                                  h));
#endif
      break;
    case "show_all":
      map_messages(e[E_MESSAGES], e);
      i = e[E_TARGET]->query_property(P_DISPLAY_WIDTH) || 79;
      h = map(e[E_OBJECT], (: look_at_thing($2, $1, 0, 1) :), e[E_AGENT]);
      tell_object(e[E_TARGET],
                  terminal_colour(implode(h,""),
                                  e[E_TARGET]->get_terminal_colour_closure(),
                                  e[E_TARGET]->query_property(P_DISPLAY_WIDTH)
                                    || 79));
      break;
    case "examine":
      if (description=look_at_thing(agent, e[E_TARGET], e[E_ID])) {
        h = agent->query_property(P_DISPLAY_WIDTH) || 79;
#if 0  // Coogan, 10-Feb-02: keep the %^stuff%^ as long as possible.
       // and tell_object() replaces that stuff, too. 
        description = break_string(description, h);
#endif
        if (!call_resolved(&h, agent, "tell_more", description))
          tell_object(agent, description);
      }
      break;
    case "est_weight":
    case "est_light":
    case "est_value":
    case "est_quality":
    case "est_strength":
    case "est_condition":
    case "est_alignment":
    case "est_age":
    case "est_load":
    case "est_weapon":
    case "est_armour":
    case "est_health":
      map_messages(e[E_MESSAGES], e);
      {
        int val, estimated_val, skill_base;
        // skill_base shall be in the range of one stat value (about 0..40)
        // but also lesser and greater values are possible.
        string skill;
        mixed computer;
        mixed *msg;
        string desc;
        closure describer;
        switch (e[E_TYPE]) {
        default:
          raise_error("Internal error: " + e[E_TYPE] + "\n");
        case "est_weight":
          describer = (#'describe_weight);
          msg = ({ M_WRITE,
                   M_THE, e[E_TARGET], M_VERB, "weigh", e[E_TARGET], M_ARG, 0,
                   "." });
          skill_base = e[E_AGENT]->query_dex();
          skill = S_ESTIMATE_ITEM;
          val = get_encumbrance(e[E_TARGET]);
          break;
        case "est_light":
          describer = (#'describe_light);
          msg = ({ M_WRITE,
                   M_THE, e[E_TARGET], M_VERB, "emit", e[E_TARGET], M_ARG, 0,
                   "." });
          skill_base = (e[E_AGENT]->query_int() +
                        10);  // estimating light is easy.
          skill = S_ESTIMATE_ITEM;
          val = light_of(e[E_TARGET]);
          break;
        case "est_value":
          describer = (#'describe_value);
          msg = ({ M_WRITE,
                   M_THE, e[E_TARGET], M_VERB, "could", e[E_TARGET],
                   " be worth about ", M_ARG, 0, "." });
          skill_base = e[E_AGENT]->query_int();
          skill = S_ESTIMATE_VALUE;  // --> VALUE, Coogan, 05-Feb-02
          val = e[E_TARGET]->query_value();
          break;
        case "est_quality":
          if      (e[E_TARGET]->id("armour")) {
            describer = (#'describe_armour_quality);
            skill = S_ESTIMATE_ARMOUR;
          }
          else if (e[E_TARGET]->id("weapon")) {
            describer = (#'describe_weapon_quality);
            skill = S_ESTIMATE_WEAPON;
          }
          else {
            message("This is neither armour nor weapon.\n");
            return;
          }
          msg = ({ M_WRITE,
                   M_THE, e[E_TARGET], M_VERB, "seem", e[E_TARGET],
                    " to be", M_ARG, 0, "." });
          skill_base = e[E_AGENT]->query_int();
          val = e[E_TARGET]->query_class();
          break;
        case "est_strength":
          describer = (#'describe_strength);
          msg = ({ M_WRITE,
                   M_THE, e[E_TARGET], M_VERB, "look", e[E_TARGET], M_ARG, 0,
                   "." });
          skill_base = (e[E_AGENT]->query_int() +
                        e[E_AGENT]->query_str()) / 2;  /* strong people are
                                                        * better in estimating
                                                        * other people's
                                                        * strength
                                                        */
          skill = S_ESTIMATE_STATS;
          val = e[E_TARGET]->query_str();
          break;
        case "est_condition":
          describer = (#'describe_condition);
          msg = ({ M_WRITE,
                   M_THE, e[E_TARGET], M_VERB, "look", e[E_TARGET], M_ARG, 0,
                   "." });
          skill_base = (e[E_AGENT]->query_int() +
                        e[E_AGENT]->query_con()) / 2;
          skill = S_ESTIMATE_STATS;
          val = e[E_TARGET]->query_max_hp();
          break;
        case "est_alignment":
          describer = (#'describe_alignment);
          msg = ({ M_WRITE,
                   M_THE, e[E_TARGET], M_VERB, "seem", e[E_TARGET], M_ARG, 0,
                   "." });
          skill_base = e[E_AGENT]->query_int();
          // people tend to see another person as what they are themselves,
          // but a more intelligent person is less influenced by this.
          skill = S_ESTIMATE_LIVING;
          val = to_int(e[E_TARGET]->query_alignment() +
                       e[E_AGENT]->query_alignment() *
                       pow(2.0, (200-e[E_AGENT]->query_alignment())/20000.0));
          break;
        case "est_age":
          describer = (#'describe_age);
          msg = ({ M_WRITE,
                   M_THE, e[E_TARGET], M_VERB, "look", e[E_TARGET], M_ARG, 0,
                   "." });
          skill_base = e[E_AGENT]->query_int();
          skill = S_ESTIMATE_LIVING;
          val = e[E_TARGET]->query_age();
          break;
        case "est_load":
          describer = (#'describe_load);
          msg = ({ M_WRITE,
                   M_THE, e[E_TARGET], M_VERB, "seem", e[E_TARGET], " to",
                   M_ARG, 0, "." });
          skill_base = (e[E_AGENT]->query_int() +
                        e[E_AGENT]->query_str()) / 2;  /* strong people
                                                        * estimate better
                                                        */
          skill = S_ESTIMATE_EQUIPMENT;
          val = (e[E_TARGET]->query_carry() * 1000 /
                 e[E_TARGET]->query_max_carry());
          break;
        case "est_weapon":
          describer = (#'describe_weapon);
          msg = ({ M_WRITE,
                   M_THE, e[E_TARGET], M_VERB, "seem", e[E_TARGET], M_ARG, 0,
                   "." });
          skill_base = (e[E_AGENT]->query_int() +
                        e[E_AGENT]->query_dex()) / 2;  /* base weapon skill
                                                        * is dex
                                                        */
          skill = S_ESTIMATE_WEAPON;
          val = e[E_TARGET]->query_wc();
          break;
        case "est_armour":
          describer = (#'describe_armour);
          msg = ({ M_WRITE,
                   M_THE, e[E_TARGET], M_VERB, "seem", e[E_TARGET], M_ARG, 0,
                   "." });
          skill_base = e[E_AGENT]->query_int();
          skill = S_ESTIMATE_ARMOUR;
          val = e[E_TARGET]->query_ac();
          break;
        case "est_health":
          describer = (#'describe_health);
          msg = ({ M_WRITE, M_THE, e[E_TARGET], M_VERB, "seem", e[E_TARGET],
                   " to be", M_ARG, 0, "." });
          skill_base = e[E_AGENT]->query_int();
          skill = S_ESTIMATE_HEALTH;
          val = (e[E_TARGET]->query_hp() * 100 /
                 e[E_TARGET]->query_max_hp());
          break;
        }
        // use_skill() returns values between -300 and +200.
        // Values above 0 are meant the be a success.
        // Values between -200 and 0 are meant to be a failure.
        // Values below -200 are meant to be a botch or fumble.
        // We do not honor these semantics but use the value directly
        // in the formula:
        // gnuplot: plot [-300:200] 100 * 1.015**(1.018**-x) - 99
        // This formula gives the factor by which the real value is either
        // multiplied or divided (which depends on a simple random(2)).
        // The skill base (derived from the stats) is multiplied by 5 and
        // added to the result of use_skill() before the formula is applied.
        computer = (: float v;
                    v = 100 * pow(1.015,
                                  pow(1.018,
                                      -($4->use_skill($3) + 5*$2))) - 99;
                    return to_int(random(2)? $1 * v : $1 / v);
                    :);
        computer = lambda(0,
                          ({ (#'funcall), computer,
                             val, skill_base, skill, e[E_AGENT] }));
        estimated_val = e[E_AGENT]->get_cache(sprintf("%s:%O:%d",
                                                      e[E_TYPE],
                                                      e[E_TARGET],
                                                      e[E_TYPE] != "est_age" &&
                                                      // ignore val for 
                                                      // cache-key if an age
                                                      // is estimated.
                                                      val),
                                              computer);
        desc = funcall(describer, estimated_val);
        if (is_wizard(e[E_AGENT], IW_TOOLUSER))
          desc += sprintf(" [%d%+d]", val, estimated_val-val);
        send_message(msg, ([ 0: " " + desc ]));
      }
      break;
    case "cmp_weight":
    case "cmp_light":
    case "cmp_value":
    case "cmp_quality":
    case "cmp_strength":
    case "cmp_condition":
    case "cmp_alignment":
    case "cmp_age":
    case "cmp_load":
    case "cmp_weapon":
    case "cmp_armour":
    case "cmp_health":
      map_messages(e[E_MESSAGES], e);
      {
        string *descs;
        int diff;  // shall be in range -1000..1000, but may exceed
        int skill_base;
        switch (e[E_TYPE]) {
        default:
          raise_error("Internal error\n");
        case "cmp_weight":
          descs = ({ "lighter than", "as heavy as", "heavier than" });
          skill_base = e[E_AGENT]->query_dex();
          diff = to_int((log(get_encumbrance(e[E_TARGET][0])+1) -
                         log(get_encumbrance(e[E_TARGET][1])+1)) * 85);
          // log(100000 (~=max_weight_item)) * 85  ~=  1000
          break;
        case "cmp_light":
          descs = ({ "darker than", "as bright as", "brighter than" });
          skill_base = (e[E_AGENT]->query_int() +
                        10);  // estimating light is easy.
          // added the "|| 1" for log(), Coogan, 13-Nov-01
          diff = to_int((log(light_of(e[E_TARGET][0]) || 1) -
                         log(light_of(e[E_TARGET][1]) || 1)) * 7);
          // log(1000000 (~=max_light_value)) * 7  ~=  1000
          break;
        case "cmp_value":
          descs = ({ "not as expensive as",
                     "as valuable as",
                     "more expensive than" });
          skill_base = e[E_AGENT]->query_int();
          diff = (e[E_TARGET][0]->query_value() -
                  e[E_TARGET][1]->query_value());
          break;
        case "cmp_quality":
          descs = ({ "to be of a lesser quality than",
                     "as good as",
                     "to be of a higher quality than" });
          skill_base = e[E_AGENT]->query_int();
          diff = (e[E_TARGET][0]->query_class() -
                  e[E_TARGET][1]->query_class()) * 40;
          break;
        case "cmp_strength":
          descs = ({ "to be weaker than",
                     "to be as strong as",
                     "to be stronger than" });
          skill_base = (e[E_AGENT]->query_int() +
                        e[E_AGENT]->query_str()) / 2;  /* strong people are
                                                        * better in estimating
                                                        * other people's
                                                        * strength
                                                        */
          diff = (e[E_TARGET][0]->query_str() -
                  e[E_TARGET][1]->query_str()) * 25;
          break;
        case "cmp_condition":
          descs = ({ "less fit than",
                     "as fit as",
                     "fitter than" });
          skill_base = (e[E_AGENT]->query_int() +
                        e[E_AGENT]->query_con()) / 2;
          diff = (e[E_TARGET][0]->query_max_hp() -
                  e[E_TARGET][1]->query_max_hp()) * 3;
          break;
        case "cmp_alignment":
          descs = ({ "to be more evil than",
                     "to be as good to others as",
                     "to be better than" });
          skill_base = e[E_AGENT]->query_int();
          diff = (e[E_TARGET][0]->query_alignment() -
                  e[E_TARGET][1]->query_alignment());
          break;
        case "cmp_age":
          descs = ({ "younger than",
                     "of the same age as",
                     "older than" });
          skill_base = e[E_AGENT]->query_int();
          diff = to_int((log(e[E_TARGET][0]->query_age()) -
                         log(e[E_TARGET][1]->query_age())) * 50);
          // log(alfe's_age) * 50  ~=  1000
          break;
        case "cmp_load":
          descs = ({ "to carry less than",
                     "to carry as much as",
                     "to carry more than" });
          skill_base = (e[E_AGENT]->query_int() +
                        e[E_AGENT]->query_str()) / 2;  /* strong people
                                                        * estimate better
                                                        */
          diff = (e[E_TARGET][0]->query_carry() * 1000 /
                  e[E_TARGET][0]->query_max_carry() -
                  e[E_TARGET][1]->query_carry() * 1000 /
                  e[E_TARGET][1]->query_max_carry());
          break;
        case "cmp_weapon":
          descs = ({ "to be worse equipped than",
                     "to be as good equipped as",
                     "to be better equipped than" });
          skill_base = (e[E_AGENT]->query_int() +
                        e[E_AGENT]->query_dex()) / 2;  /* base weapon skill
                                                        * is dex
                                                        */
          diff = (e[E_TARGET][0]->query_wc() -
                  e[E_TARGET][1]->query_wc()) * 50;
          break;
        case "cmp_armour":
          descs = ({ "to be worse armoured than",
                     "to be as good armoured as",
                     "to be better armoured than" });
          skill_base = e[E_AGENT]->query_int();
          diff = (e[E_TARGET][0]->query_ac() -
                  e[E_TARGET][1]->query_ac()) * 100;
          break;
        case "cmp_health":
          descs = ({ "to be more hurt than",
                     "to be as healthy as",
                     "to be healthier than" });
          skill_base = e[E_AGENT]->query_int();
          diff = (e[E_TARGET][0]->query_hp() * 1000 /
                  e[E_TARGET][0]->query_max_hp() -
                  e[E_TARGET][1]->query_hp() * 1000 /
                  e[E_TARGET][1]->query_max_hp());
          break;
        }
        diff = e[E_AGENT]->get_cache(sprintf("%s:%O:%d",
                                             e[E_TYPE],
                                             e[E_TARGET] & e[E_TARGET],
                                             /*
                                              * that x & x on arrays produces
                                              * an array with fixed ordering
                                              * of the elements; this is
                                              * necessary in order to produce
                                              * equal results on comparing two
                                              * things in various order; same
                                              * is valid for the abs()-value
                                              * used in the line below.
                                              */
                                             diff<0? -diff : diff),
                                     to_int(diff + (1000 * gauss_random() /
                                                    skill_base)) / 50);
        send_message(({ M_WRITE,
                        M_THE, e[E_TARGET][0], M_VERB, "seem", e[E_TARGET][0],
                        " " + descs[(diff>=0) + (diff>0)] + " ",
                        M_THE, e[E_TARGET][1], "." }));
      }
      break;
    }
  }
}
