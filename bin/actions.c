/*
    basic/living/brain.c - general brain logic
    Oct 1991 by marion@cs.tu-berlin.de
*/

/* 
    The initial brain was written by marion@cs.tu-berlin
    This is a re-write (using mappings instead of alists) 
    which could serve as a daemon instead as an object in
    the inventory of the player.
    In all other aspects, this is fully compatible with the old system.

    Ugh@Tubmud 1995
*/

#include <global_actions.h>

/*
 * basic_action and new_action have the following structure:
 * ([ verb : 
 *    ([ specific : ({ ({ function, handler }), ... }),
 *       ...
 *    ]),
 *    ...
 * ])
 *
 * The specific can either be a word or zero (0).
 */

inherit "basic/daemon";
inherit "basic/create";

string player;          /* The owner set by set_player() */
mapping basic_action;   /* the basic actions for this player and the
                           associated specifics and methods */
mapping new_action;     /* the new actions for this player and the
                           associated specifics and methods */
string *tempactions;    /* the temporary actions for this player */

/*
 * This function inserts a new action into the new_action structure.
 */
public int filter_new(mixed new, string what) {
  if (stringp(new))
    new = ({new,0,what->query_actions()[2]});
  if (!pointerp(new) || sizeof(new) < 3) {
    // added ctime()   Alfe 1996-Nov-19
    log_file("ACTION",ctime() + ": BAD init_living in "+what+"\n");
    return 0;
  }
  if (!member(new_action,new[0])) {
    new_action += 
      ([ new[0] : ([ new[1] : ({ ({ new[2], what }) }) ]) ]);
    add_command("perform_command", new[0]);
  }
  else if (!member(new_action[new[0]],new[1]))
    new_action[new[0]] += ([ new[1] : ({ ({ new[2], what }) }) ]);
  else
    new_action[new[0]][new[1]] += ({ ({ new[2], what }) });

  return 0;
}

/*
 * This function is called when the object is created and initializes
 * the basic_action and new_action data-structures and fills them
 * with the global actions and methods which are returned by ACTIONS.
 */
// int to void, Coogan, 26-Mar-2011
static void introduce(object ob) {  /* introduce player 'ob' */
  string        *new, specific;
  mixed         *node;
  string        *global_action;
  mixed         *global_method;
  int i, j;

  global_action = (string *)ACTION->query_action();
  global_method = (mixed *)ACTION->query_method();
  
  basic_action = ([]);
  new_action = ([]);

  for (i = sizeof(global_action); i--; ) {
    node = global_method[i];
    for (j = sizeof(node[1]); j--; ) {
      specific = node[0] ? node[0][j] : 0;

// Following check added by Carador, Mar-1996
      if (stringp(node[1][j][1]) &&
          catch(load_object(node[1][j][1]))) {
        // added ctime() to log  Alfe 1996-Nov-19
        log_file("ACTION", ctime()+": failed to load " + node[1][j][1] + "\n");
        continue;
      }
      if (new = (string *)node[1][j][1]->init_living(ob))
        map(new,#'filter_new,node[1][j][1]);
      else
        continue;
      if (!member(basic_action,global_action[i])) {
        basic_action += 
          ([ global_action[i] : 
              ([ specific : node[1][j..j] ])
          ]);
        add_command("perform_command",global_action[i]);
      }
      else if (!member(basic_action[global_action[i]],specific))
        basic_action[global_action[i]] += 
          ([ specific : node[1][j..j] ]);
      else
        basic_action[global_action[i]][specific] += node[1][j..j];
    }
  }
}

// This surely is the work of a genius! *praise Myxectbo*
static int filter_perform(string *what,mixed *extra) {
  if (!extra[0])
    return extra[0] = (int)call_other(what[1],what[0],extra[1]);
}

// This function is called as daemon-handling
static int perform_command(string str,string what) {
  string sub, more;
  mapping node;

  if (str && sscanf(str,"%s %s",sub,more) != 2) {
    sub = str;
    more = 0;
  }
  if (member(basic_action,what)) {
    node = basic_action[what];
    // verb+specific
    if (sub && member(node,sub))
      if (sizeof(filter(node[sub],#'filter_perform,({0,more}))))
        return 1;
    // verb
    if (member(node,0))
      if (sizeof(filter(node[0],#'filter_perform,({0,str}))))
        return 1;
  }
  if (member(new_action,what)) {
    node = new_action[what];
    // verb+specific
    if (sub && member(node,sub))
      if (sizeof(filter(node[sub],#'filter_perform,({0,more}))))
        return 1;
    // verb
    if (member(node,0))
      if (sizeof(filter(node[0],#'filter_perform,({0,str}))))
        return 1;
  }
  if (what[0] == '\n')
    notify_fail("?\b");
  return 0;
}

private void add_handlers_of_specific(string specific,mixed *actions,
                                      mapping handlers) {
  handlers += mkmapping(transpose_array(actions)[1]);
}

private void add_handlers_of_action(string action,mapping node,
                                    mapping handlers) {
  walk_mapping(node,#'add_handlers_of_specific,handlers);
}

string * query_action_handlers(string action) {
  mapping handlers;
  walk_mapping(basic_action,#'add_handlers_of_action,handlers = ([]));
  walk_mapping(new_action,#'add_handlers_of_action,handlers);
  return m_indices(handlers);
}

void create() {
  // let every player have his own daemon
  set_auto_clone();
}

// This is called by the blueprint whenever a new clone is made
void set_player(string who) {
  player = who;
  // find_living() added by Ugh for livings with query_real_name()
  // Aug-6-1997
  introduce(find_object(who) || find_player(who) || find_living(who));
}

static void do_reconfigure() {
  string *temptemp;

  if (player) {
    set_player(player);
    if (tempactions) {
      temptemp = tempactions;
      tempactions = 0;
      filter(temptemp,#'new_action);
    }
  }
}

// this function is called by /obj/actions.c if a new action was added
// or one was removed, or if a temporary action is removed (see below)
public void reconfigure() {
  if (!clonep())
    map_objects(get_instances(),"reconfigure");
  else if (find_call_out("do_reconfigure") < 0)
    call_out("do_reconfigure",0);
}

// This is called to add temporary actions for testing purposes
// by (for instance) /domains/skills/logic/add_action (action ?add)
string new_action(string what) {
  string *new;
  mixed *newnew;
  object ob;

  if (pointerp (tempactions) &&
      member(tempactions, what) >= 0)
    return "already added";
  if (!(ob = load_object (what)))
    return "load failed";
  if (clonep (ob))
    return "cloned illegal";
  /* get definition and double check what we can check */
  new = (string *)ob->query_actions();
  if (!pointerp (new) || sizeof (new) != 3)
    return "invalid";
  if (!stringp (new[0]) || !stringp (new[2]))
    return "invalid";
  if (!function_exists (new[2], ob))
    return new[2]+" undefined";
  ob = find_object(player) || find_player(player);
  if (newnew = (mixed *)call_other (what, "init_living", ob)) 
    filter (({new})+newnew, #'filter_new, what);
  if (!tempactions)
    tempactions = ({what});
  else
    tempactions += ({what});
  return "ok";
}

// This is called to remove temporary actions again 
string remove_action(string what) {
  int i;

  if (!pointerp (tempactions) ||
      (i = member(tempactions, what)) < 0)
    return what+" not found";
  tempactions = exclude_element (tempactions, i);
  reconfigure();
  return "ok";
}

// Next two functions introduced by Ugh May-12-1996
// for global action 'show verbs' (the availability of which had been
// lost due to the conversion)

private string * what_verbs(mapping action) {
  return
    m_indices(filter_indices(action,
			     lambda(({'s}),
				    ({#'&&,
				      's,
				      ({#'!=, ({#'[,'s,0}), '\n'})}))));
}

string query_verbs() {
  string verbs;
  string *can;

  verbs = "";
  if (sizeof(can = what_verbs(basic_action+new_action))) 
    verbs = implode (can, " ");
  return verbs != "" ? verbs : 0;
}

void refresh() {  // Coogan, 29-Dec-2001
  "*"::refresh();
  if (clonep() && !query_owner())
    destruct(this_object());
}

void notify_destruct() {  // Coogan, 29-Aug-2003
  if (!clonep())
    return daemon::notify_destruct();
}

