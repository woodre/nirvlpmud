/*
 *  marion@cs.tu-berlin.de
 *
 *  This module requires you to inherit /basic/namespace in your code.
 *  This module requires you to inherit /basic/timedep in your code.
 *
 *  Time dependant faked item descriptions (e.g. for rooms).
 *
 *  See also /basic/timedepitem.h
 */

#pragma strong_types

#include <grammar.h>
#include "/basic/timedep.h"

                 inherit "basic/alias";
virtual          inherit "basic/synonym"; // added virtual, Coogan, 24-Jan-2001
nosave variables inherit "basic/parser"; /* Ugh Feb-16-1995 */
                                        // nosave variables, Coogan, 06-Jun-2001

#define TIMEDEPITEM_SPACE ({ "/basic/timedepitem" })

private string *timedepitem_space;

varargs void set_item_descriptions(mixed *names, mixed *descriptions,
                                 string when, string *depspace, string *space) {
  if (!space)
    space = timedepitem_space ? timedepitem_space : TIMEDEPITEM_SPACE;
  if (!depspace)
    depspace = ({ "void" });

  if (!get_namespace(({ space[0] })))
    add_namespace(space[0]);

  timedepitem_space = space;

  // filter() -> map(), Coogan, 24-Mar-2011
  map(names, "set_item_descriptionsF",
                      this_object(), ({ depspace, space + ({ "depspace" })}));
  alias::set_aliases(names, descriptions, space + ({ "keys", when }));
}

// changed function type int to void, Coogan, 24-Mar-2011
void set_item_descriptionsF(mixed name, mixed *x) {
  // foslay Feb-07-1993
  int t;

  if (pointerp(name))
    for (t=0; t<sizeof(name); t++)
      set_namespace(x[1] + ({ lower_case(name[t]) }), x[0]);
  else
    set_namespace(x[1] + ({ lower_case(name) }), x[0]);
}

varargs void set_one_item_description(mixed name, mixed description,
                                      string when, string *depspace,
                                      string *space) {
  int t;

  if (!space)
    space = timedepitem_space ? timedepitem_space : TIMEDEPITEM_SPACE;
  if (!depspace)
    depspace = ({ "void" });

  if (!get_namespace(({ space[0] })))
    add_namespace(space[0]);

  timedepitem_space = space;

  if (pointerp(name))
    for (t=0; t<sizeof(name); t++)
      set_namespace(space + ({ "depspace", lower_case(name[t]) }), depspace);
  else {
    name = lower_case(name);
    set_namespace(space + ({ "depspace", name }), depspace);
  }
  alias::set_alias(name, description, space + ({ "keys", when }));
}

varargs void set_one_item_descriptions(mixed name, mixed *descriptions,
                                       string *depspace, string *space) {
  string *whens;
  int i;

  whens = query_timedep_table (depspace)[1];
  for (i = 0; i < sizeof (descriptions); i++) {
    set_one_item_description(name, descriptions[i], whens[i], depspace, space);
  }
}

// introduced by Ugh Jul-08-1997
status query_timedepitem_id(string subject) {
  string *depspace;

  subject = get_synonym(subject ? lower_case(subject) : subject);
  if (timedepitem_space &&
      (depspace = get_namespace(timedepitem_space + ({ "depspace", subject }))))
    return
      alias::id_alias(subject,
                      timedepitem_space + ({ "keys",
                                             query_timedep(depspace) }));
  return 0;  // Coogan, 27-Mar-2011
}

// introduced by Ugh Jul-08-1997
status query_fakeitem_id(string subject) {
  return query_timedepitem_id(subject);
}

// former code of id() now resides in query_timedepitem_id() -- Ugh Jul-08-1997
int id(string subject) {
  return query_timedepitem_id(subject);
}

string query_timedepitem_long(string subject) {
  subject = get_synonym(subject ? lower_case(subject) : 0);
  return
    funcall(timedepitem_space &&
            alias::query_alias(subject,
                               timedepitem_space+
                               ({ "keys",
                                  query_timedep(
                                    get_namespace(timedepitem_space +
                                                  ({ "depspace", subject })))
                               })));
}

string query_long(string str) {
  return query_timedepitem_long(str);
}

/* marion
 * Sorry, but this depends on the alias and namespace organization
 */
varargs mixed * query_items(string *space, string when) {
  mixed temp;
  if (!space)
    if (!(space = timedepitem_space))
      return 0;
  temp = get_namespace(space + ({ "keys", when }));
  return mappingp(temp) && 
         ({ (temp = m_indices(temp)), 
            map(temp, #'query_timedepitem_long) });
  /* changed by Ugh 06-Jul-1994 after the change of namespace.c */
  /* changed to return the actual query_timedepitem_long of each item */
}

// Ugh Jun-07-1995 tests for 'when' and consequences
varargs void remove_item(mixed subject, mixed when, string *space) {
  mixed h;
  if (!space)
    // added || TIMEDEPITEM_SPACE -- Ugh Jan-20-1998
    space = timedepitem_space || TIMEDEPITEM_SPACE;
  if (pointerp(subject)) {
    map(subject, #'remove_item, when, space);
    return;
  }
  subject = get_synonym(subject ? lower_case(subject) : 0);
  if (!when) {
    h = get_namespace(space + ({ "depspace", subject })) || 
        ({ "void" }); // this is for the case that someone tries to remove
                      // a non-existing item
    when = get_namespace(h + ({ "what" }));
    // Ugh Jun-08-1995
    if (!when)
      when = ({ 0 });
  }
  else if (stringp(when))
    when = ({ when });
  if (pointerp(when)) {
    for(h=sizeof(when); h--; )
      alias::remove_single_alias(subject, space + ({ "keys", when[h] }));
  }
}

void set_timedepitem_space(string *space) {
  timedepitem_space = space;
}

/*  add_item () and set_items () automatically create the required
 *  default depspaces, Mar-26-1993 foslay
 */

varargs void add_item(mixed name, mixed description, string *depspace,
                      string when) {
  if (pointerp (description) && sizeof(description) > 1) {
    // check for sizeof added by Ugh 07-Dec-1994
    if (!depspace)
      depspace = DEFAULT_DEPSPACE[sizeof(description)];
    if (depspace && !get_namespace(depspace))
      set_default_depspace(depspace);
    set_one_item_descriptions(name, description, depspace);
  } else {
    if (depspace && !get_namespace(depspace))
      set_default_depspace(depspace);
    set_one_item_description(name, description, when, depspace);
  }
}

private mapping action_counter;

// Ugh Jul-24-1997 -- removed 6th argument 'depspace'
varargs void add_item_action(mixed name, string rule, string action,
                             mixed func, mixed time) {
  int i, j;
  string *keys, *actions;

#if 1 // Coogan, 18-May-1998
  string *space;
  if (!space)
    space = timedepitem_space ? timedepitem_space : TIMEDEPITEM_SPACE;
  if (!get_namespace(({ space[0] })))
    add_namespace(space[0]);
  timedepitem_space = space;
#endif

  if (rule) {
    if (pointerp(rule))
      map(rule, #'add_rule, action, 0, ITEM_ACTION_FAMILY);
    else 
      add_rule(rule, action, 0, ITEM_ACTION_FAMILY);
  }
  if (stringp(name))
    name = ({ lower_case(name) });
  else
    name = map(name, #'lower_case);
  // loop for different given times -- Ugh Jul-24-1997
  // some bugfixes (use of timedepitem_space instead of depspace)
  if (!pointerp(time))
    time = ({ time });
  for (j = sizeof(time); j--; ) {
    keys    = timedepitem_space + ({ "keys", time[j] });
    actions = timedepitem_space + ({ "actions", action, time[j] });
    if (!action_counter)
      action_counter = ([ ]);
    for (i = sizeof(name); i--; ) {
#if 0 // Ugh Dec-01-????
      if (!alias::id_alias(name[i], keys))
        continue;
#endif
      if (func) {
        if (!alias::id_alias(name[i], actions))
          action_counter[action]++;
        if (func == 1)
          continue;
        else
          alias::set_single_alias(name[i], ({ func }), actions);
      } else {
        if (alias::id_alias(name[i], actions))
          action_counter[action]--;
        alias::remove_single_alias(name[i], actions);
      }
    }
  }
  update_actions();
}

void add_item_actions(mixed actions) {
  map(actions, lambda(({'r}), ({#'apply, #'add_item_action, 'r})));
}

// Ugh Jul-24-1997 -- removed 3rd argument 'depspace' from signature
varargs void remove_item_action(mixed name, string action, string time) {
  add_item_action(name, 0, action, 0, time);
  if (action_counter[action] < 1)
    remove_rule(0, action, ITEM_ACTION_FAMILY);
}

status parse_item_action(string str) {
  return parse_sentence((str ? query_verb()+" "+str : query_verb()), 
                        ITEM_ACTION_FAMILY);
}

mixed do_action(string verb, mapping args) {
  string now, name;
  mixed func, depspace;

  name = (args[G_ME] && get_synonym(args[G_ME,1])) ||
         (args[G_FAKEITEM] == this_object() && get_synonym(args[G_FAKEITEM,1]));
  if (!name)
    return 0;
  depspace = get_namespace(timedepitem_space + ({ "depspace", name }));
  now = query_timedep(depspace);
  if (alias::id_alias (name, timedepitem_space+({"keys", now})) && 
      (func = 
       alias::query_alias (name, timedepitem_space+({"actions", verb, now})))) {
    func = func[0];
    if (closurep(func)) {
      if (!(func = funcall(func, args)))
        return 0;
      if (intp(func))
        return func;
    }
    if (func) {
      // to break strings properly, Carador, 14-Mar-1996
      // and put them through tell_more, 03-May-1996
      if (stringp(func)) 
        this_player()->tell_more(break_string(func));
      else message(func[0..]);
    }
    return 1;
  }
  return 0;  // Coogan, 28-Mar-2011
}

void init() {
  add_actions("parse_item_action", ITEM_ACTION_FAMILY);
}

void add_item_action_error_message(string verb,mixed mess) {
  add_error_message(verb, mess, ITEM_ACTION_FAMILY);
}

// added following function to be able to remove error messages again,
// Chameloid, 26-Feb-1999
void remove_item_action_error_message(string verb) {
  remove_error_message(verb, ITEM_ACTION_FAMILY);
}

varargs void set_items(mixed items, string *depspace, string when) {
  int t;
  string *space;

  if (depspace && !get_namespace(depspace))
    set_default_depspace(depspace);

  for (t=0; t < sizeof (items); t+=2) {
    if (pointerp(items[t+1]) /* ??? && !closurep(items[t+1]) ??? */)
      set_one_item_descriptions(items[t], items[t+1], depspace);
    else
      set_one_item_description(items[t], items[t+1], when, depspace);
  }
}

mixed query_timedepitem_space() {
  return timedepitem_space;
}

