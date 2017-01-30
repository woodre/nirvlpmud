#include <event.h>
#include <action.h>
#include <grammar.h>
#include <combat.h>
#include <message.h>
#include <describe.h>

inherit "basic/container";
inherit "complex/shooting_weapon";

void init() {
  shooting_weapon::init();
  add_action_rule("load "G_OBJECT" with "G_INDIRECT, "load");
  add_action_rule("load with "G_INDIRECT, "load");
  add_action_rule("load "G_OBJECT, "load");
  add_action_rule("load","load");
  add_action_error_message("load", "Load with which arrow?\n");
  add_action_rule("reload "G_OBJECT" from "G_INDIRECT, "reload");
  add_action_rule("reload from "G_INDIRECT, "reload");
  add_action_error_message("reload", "Reload from which quiver?\n");
  add_action_rule("bend "G_OBJECT" with "G_INDIRECT, "bend");
  add_action_rule("bend with "G_INDIRECT, "bend");
  add_action_rule("bend", "bend");
  add_action_error_message("bend", "Bend with which bow string?\n");
  add_action_rule("unbend "G_OBJECT, "unbend");
  add_action_rule("unbend","unbend");
  add_action_error_message("unbend", "Unbend what?\n");
  add_action_rule("remove "G_INDIRECT" from "G_OBJECT, "unbend");
  add_action_rule("remove "G_INDIRECT, "unbend");
  add_action_error_message("remove", "Remove what from what?\n");
}

private static object bow_string;

object
query_bow_string()
{
  return bow_string && present(bow_string,this_object());
}

status
accepts_bow_string(object str)
{
  return str->id("bow string");
}

status
accepts_ammunition(object ammo)
{
  if (ammo->id("arrow"))
    return 1;
}

status
accepts_magazine(object magazine)
{
  mixed h;
  return (h = magazine->query_arrows()) && 
	 sizeof(filter(h,#'accepts_ammunition)) > 0;
}

void
set_bow_string(object str)
{
  mixed h;
  if (!str)
  {
    if (h = query_bow_string()) {
      bow_string = 0;
      move_object(h, environment());
    }
  }
  else if (!query_bow_string() && accepts_bow_string(str))
    bow_string = str;
}

status
can_load(object what)
{
  return
    query_wielded() && query_bow_string() &&
    accepts_ammunition(what) &&
    ammunition_space(what);
}

status
can_put_and_get(string id, object what)
{
  if (what && can_load(what))
    return 1;
  return !what;
}

mixed query_action_impossible(mapping action)
{
  mixed h;
  switch (action[E_ACTION])
  {
  case "bend":
    if (query_bow_string())
      return "There is already a bow string.\n";
    if (!accepts_bow_string(action[E_TARGET]))
      return "You can't use this as bow string.\n";
    if (query_wielded())
      return 
        message2string(({"You should unwield ",M_ME_THE," first.\n"}));
    break;

  case "unbend":
    if (!query_bow_string())
      return "But there is no bow string on it!\n";
    if (action[E_TARGET] && action[E_TARGET] != query_bow_string())
      return "You can't remove that.\n";
    if (sizeof(query_ready_ammunition()))
      return message2string(({"Not while ",M_ME_THE," is loaded.\n"}));
    if (query_wielded())
      return 
        message2string(({"You should unwield ",M_ME_THE," first.\n"}));
    break;

  case "aim":
    if (!query_wielded())
      return message2string(({"You should wield ",M_ME_THE," first.\n"}));
    if (!query_bow_string())
      return "You can't do that without a bow string.\n";
    if (!sizeof(query_ready_ammunition()))
      return 
        message2string(({"You should load ",M_ME_THE," first.\n"}));
    if (action[E_OBJECT] && 
        !action[E_OBJECT]->query_held_by(action[E_AGENT]))
      return
        message2string(({"You should grab ",
                         M_THE,action[E_OBJECT]," first.\n"}));
    break;

  case "fire":
    if (!query_wielded())
      return message2string(({"You should wield ",M_ME_THE," first.\n"}));
    if (!query_bow_string())
      return "You can't do that without a bow string.\n";
    if (!sizeof(query_ready_ammunition()))
      return 
        message2string(({"You should load ",M_ME_THE," first.\n"}));
    if (!query_aim())
      return 
        message2string(({"You should aim ",M_ME_THE," first.\n"}));
    if (action[E_OBJECT] &&
        action[E_OBJECT]->query_held_by(action[E_AGENT]))
      return
        message2string(({"You should let go of ",
                         M_THE,action[E_OBJECT]," first.\n"}));
    break;

  case "load":
    if (!query_wielded())
      return message2string(({"You should wield ",M_ME_THE," first.\n"}));
    if (!query_bow_string())
      return message2string(({"There is no bow string on ",M_ME_THE,".\n"}));
    if (action[E_TARGET])
    {
      if (!accepts_ammunition(action[E_TARGET]))
	return message2string(({"You can't load ",M_ME_THE," with that.\n"}));
      if (!ammunition_space(action[E_TARGET]))
	return "There isn't enough room.\n";
    }
    else
    {
      if (!(sizeof(h = query_magazines()) &&
	    sizeof(filter_objects(h,"get_ammunition"))))
	return message2string(({"Load ",M_ME_THE," with what?\n"}));
    }
    break;
  }
  return shooting_weapon::query_action_impossible(action);
}

mapping
build_complete_action(mapping action, mapping args)
{
  mixed h;
  switch (action[E_ACTION])
  {
  case "bend":
  case "unbend":
  case "load":
    h = map_objects(get_holding_parts(this_player()), "query_name");
    h = map_indices(mkmapping(h), (: return 1; :));
    action +=
      ([ E_WEAPON: this_object(); args[G_OBJECT,1],
         E_TARGET: args[G_INDIRECT]; args[G_INDIRECT,1],
         A_NEEDED_SHARED: ([ "leg" : 2 ]); 0,
         A_NEEDED_USED: h; 0 ]);
    break;
  default:
    return shooting_weapon::build_complete_action(action,args);
  }
  return action;
}

mapping
build_action_event(mapping action)
{
  mixed h;
  switch (action[E_ACTION])
  {
  case "bend":
  case "unbend":
  case "reload":
    break;
  case "load":
    if (!action[E_TARGET])
    {
      if (sizeof(h = filter(all_inventory(action[E_AGENT]),
                            "accepts_ammunition")))
        action[E_TARGET] = h[0];
      else if (sizeof(h = query_magazines())) {
	if (sizeof(h = map_objects(h,"get_ammunition") - ({0})))
          action[E_TARGET] = h[0];
      }
    }
    break;
  case "shoot":
  case "aim":
    if (!action[E_OBJECT] && sizeof(h = query_ready_ammunition())) {
      action[E_OBJECT] = h[0];
      action[E_OBJECT,1] = h[0]->query_name();
    }
  }
  return shooting_weapon::build_action_event(action);
}

status handle_action_shoot(mapping action) {
  object body;

  body = action[E_AGENT]->query_body();
  if (action[E_OBJECT]->query_held_by(action[E_AGENT])) 
    return
      body->schedule_action(body->build_action("let_go",
                                               ([A_G_TARGET:
                                                   action[E_OBJECT];
                                                   action[E_OBJECT,1]])));
  else
    return 0; // shooting_weapon::handle_action_shoot(action);
}

status handle_action_bend(mapping action)
{
  send_message(({M_CLASS, action,
                 M_ARG,E_AGENT,M_VERB,"stretch",M_ARG,E_AGENT,
		 M_THE,M_OBJECT,M_ARG,E_TARGET," over ",
		 M_POSSESSIVE,M_ARG,E_AGENT,
		 M_OBJECT,M_NONE,M_ARG, E_WEAPON,"."}), action);
  move_object(action[E_TARGET],action[E_WEAPON]);
  action[E_SUCCESS] = 1;
  return 1;
}

status handle_action_unbend(mapping action)
{
  send_message(({M_CLASS, action,
                 M_ARG, E_AGENT, M_VERB,"remove",M_ARG, E_AGENT,
		 M_SIMPLE_DESCRIBE,M_OBJECT,M_THE,query_bow_string(),
                 " from ",M_ME_THE,"."}), action);
  set_bow_string(0);
  action[E_SUCCESS] = 1;
  return 1;
}

status should_stop_aiming(mapping action) {
  status let_go;

  let_go =
    query_aim() &&
    action[E_ACTION] == "let_go" && 
    (action[E_TARGET] ?
     sizeof(query_ready_ammunition() & action[E_TARGET]) :
     sizeof(query_ready_ammunition()));
  return shooting_weapon::should_stop_aiming(action) && !let_go;
}

status should_shoot(mapping action) {
  mixed h;
  return
    action[E_ACTION] == "let_go" &&
    action[E_TARGET] && 
    action[E_TOOL] != action[E_AGENT]->query_body();
}

status prevent_prepare_action_event(mapping action, string t, int p) {
  object body;
  object *hands;
  int i;

  if (action[E_TOOL] == this_object()) 
    switch (action[E_ACTION]) {
    case "load":
      if (action[E_TARGET] && !ammunition_space(action[E_TARGET]))
        break;
      body = action[E_AGENT]->query_body();
      if (action[E_TARGET] &&
          !present(action[E_TARGET], action[E_AGENT]))
        return
          body->precede_action(body->build_action("take",
                                                  ([A_G_TARGET:
                                                      action[E_TARGET]; 
                                                      action[E_TARGET,1]])),
                               action);
      if (action[E_TARGET] &&
          !action[E_TARGET]->query_held_by(action[E_AGENT])) {
        hands = body->get_hands();
        for (i = sizeof(hands); i-->0; )
          if (hands[i]->can_take(action[E_TARGET])) 
            return 
              hands[i]->
              precede_action(hands[i]->
                             build_action("grab",
                                          ([A_G_TARGET:
                                              action[E_TARGET];
                                              action[E_TARGET,1]])), action);
      }
      break;
    case "shoot":
      body = action[E_AGENT]->query_body();  
      if (!query_aim())
        return
          precede_action(build_action("aim",
                                      ([A_G_TARGET:
                                          action[E_TARGET];
                                          action[E_TARGET,1]])));
      break;
    case "aim":
      body = action[E_AGENT]->query_body();
      if (!sizeof(query_ready_ammunition()))
        return precede_action(build_action("load"));
      if (action[E_OBJECT] && 
          !action[E_OBJECT]->query_held_by(action[E_AGENT])) {
        hands = body->get_hands();
        for (i = sizeof(hands); i-->0; )
          if (hands[i]->can_take(action[E_OBJECT])) {
            return 
              hands[i]->
              precede_action(hands[i]->
                             build_action("grab",
                                          ([A_G_TARGET:
                                              action[E_OBJECT];
                                              action[E_OBJECT,1]])), action);
          }
      }
    }                                   
  return shooting_weapon::prevent_prepare_action_event(action, t, p);
}

status handle_action_load(mapping action)
{
  send_message(({M_CLASS, action, 
                 M_ARG, E_AGENT,M_VERB,"load",M_ARG,E_AGENT,
		 M_POSSESSIVE,M_ARG,E_AGENT,
		 M_OBJECT,M_NONE,M_ARG,E_WEAPON," with ",
		 M_OBJECT,M_ARG,E_TARGET,"."}), action);
  move_object(action[E_TARGET],action[E_WEAPON]);
  action[E_SUCCESS] = 1;
  return 1;
}

mixed
do_action(string action, mapping args)
{
  mixed h, msg;
  switch (action)
  {
  case "reload":
    if (args[G_OBJECT] && args[G_OBJECT] != this_object())
      return 0;
    if (!present(args[G_INDIRECT],this_player()))
      return notify_fail("Why don't you take it first.\n"), 0;
    remove_magazine(h = query_magazines());
    if (!add_magazine(args[G_INDIRECT]))
    {
      map(h,#'add_magazine);
      return notify_fail("You can't reload from that.\n"), 0;
    }
    write("Ok. You'll now reload from "+
	  describe(args[G_INDIRECT],ARTICLE_THE)+".\n");
    return 1;
  default:
    return shooting_weapon::do_action(action, args);  
  }
}

status
hide_inventory(string id)
{
  return 1;
}

string bow_long;

string
query_bow_long()
{
  return funcall(bow_long);
}

void
set_bow_long(mixed l)
{
  bow_long = l;
}

private string
bow_long_desc()
{
  mixed h;
  return
    (query_bow_long() ||
     capitalize(describe(this_object(),ARTICLE_A,DESCRIBE_FULL))+".\n")+
    (query_bow_string()? "It has a bow string.\n" : "It has no bow string.\n") +
    (sizeof(h = flatten_array(map(get_wielders(), #'get_holding_parts))) ? 
    message2string(({"It is wielded in ",M_THE,h,".\n"})) : "")+
    (sizeof(h = query_ready_ammunition()) ? 
    message2string(({"It is loaded with ",h,".\n"})) : "") + 
    ((query_wielded() && (h = query_aim()) && h[E_TARGET]) ? 
      message2string(({M_ME_PRONOUN,M_ME_VERB,"be"," aimed at ",
		       M_OBJECT,h[E_TARGET],"."})) : "");
}

void
configure()
{
  shooting_weapon::configure();
  set_persistence(__FILE__);
  remove_persistent_variable("weapon_long");
  set_name("bow");
  add_id("bow");
  set_type("bow");
  set_weapon_long(#'bow_long_desc);
  set_weapon_short("a bow");
  move_object(clone_object("/complex/weapon/bow_string"),this_object());
  add_planned_action_rule("load "G_OBJECT" with "G_INDIRECT, "load");
  add_planned_action_rule("load with "G_INDIRECT, "load");
  add_planned_action_rule("load "G_OBJECT, "load");
  add_planned_action_rule("load","load");
  add_planned_action_rule("reload "G_OBJECT" from "G_INDIRECT, "reload");
  add_planned_action_rule("reload from "G_INDIRECT, "reload");
  add_planned_action_rule("bend "G_OBJECT" with "G_INDIRECT, "bend");
  add_planned_action_rule("bend with "G_INDIRECT, "bend");
  add_planned_action_rule("unbend "G_OBJECT, "unbend");
  add_planned_action_rule("unbend","unbend");
}

status
prevent_enter(object ob, object from)
{
  if (accepts_bow_string(ob))
    return !!query_bow_string();
  if (accepts_ammunition(ob))
    return !can_load(ob);
}

status prevent_leave(object ob) {
  if (ob == query_bow_string())
    return 1;
}

void
notify_enter(object ob, object from)
{
  if (accepts_ammunition(ob))
    make_ready_ammunition(ob);
  if (accepts_bow_string(ob))
    set_bow_string(ob);
}

void notify_leave(object ob, object to) {
  remove_ready_ammunition(ob);
}

void notify_unwield(object wielder) {
  mixed h;

  shooting_weapon::notify_unwield(wielder);
  if (wielder && sizeof(h = query_ready_ammunition()))
  {
    send_message(({M_WRITE,h,M_VERB,"fall",h," out of ",M_ME_THE,"."}));
    map(h,#'move_object,wielder);
  }
}

void
notify_destruct()
{
  object s;
  if (s = query_bow_string())
    destruct(s);
}
