#include <combat.h>
#include <event.h>
#include <message.h>

inherit "basic/create";

mapping combat_coordinator = ([ ]);

// This function gets an object and returns the combat-coordinator-object
// for the outermost environment of that object
object get_combat_coordinator(object where) {
//  raise_error("JUST A TEST TO RECEIVE A PROPER TRACE (Alfe)\n");
  if (environment(where))
    where = all_environment(where)[<1];
  if (!(combat_coordinator[where] &&
        present(combat_coordinator[where],where)) &&
      !(combat_coordinator[where] = present_clone(COMBAT_COORDINATOR,where)))
  {
    combat_coordinator[where] = COMBAT_COORDINATOR->get_free_coordinator();
    move_object(combat_coordinator[where],where);
  }
  return combat_coordinator[where];
}

object query_combat_coordinator(object where) {
  if (environment(where))
    where = all_environment(where)[<1];
  return combat_coordinator[where] && present(combat_coordinator[where],where);
}

void create() {
  "basic/create"::create();
  listen_event("start_fight",EPRIO_MODIFY);
  listen_event("start_fight",EPRIO_HANDLE);
  listen_event("stop_fight",EPRIO_HANDLE);
  listen_event("prepare_action",EPRIO_MODIFY);
  listen_event("prepare_action",EPRIO_CANCEL);
  listen_event("prepare_action",EPRIO_HANDLE);
  listen_event("prepare_action",EPRIO_NOTICE);
  listen_event("begin_action",EPRIO_MODIFY);
  listen_event("begin_action",EPRIO_CANCEL);
  listen_event("begin_action",EPRIO_HANDLE);
  listen_event("begin_action",EPRIO_NOTICE);
  listen_event("action",EPRIO_MODIFY);
  listen_event("action",EPRIO_CANCEL);
  listen_event("action",EPRIO_HANDLE);
  listen_event("action",EPRIO_NOTICE);
  listen_event("finish_action",EPRIO_MODIFY);
  listen_event("finish_action",EPRIO_CANCEL);
  listen_event("finish_action",EPRIO_HANDLE);
  listen_event("finish_action",EPRIO_NOTICE);
  listen_event("damage",EPRIO_MODIFY);
  listen_event("damage",EPRIO_CANCEL);
  listen_event("damage",EPRIO_HANDLE);
  listen_event("damage",EPRIO_NOTICE);
  listen_event("wound",EPRIO_HANDLE);
  listen_event("move",EPRIO_MODIFY);
  listen_event("move",EPRIO_NOTICE2);
  listen_event("missile",EPRIO_HANDLE);

  // listen to all the events globally
  set_global_listening_event("start_fight",1);
  set_global_listening_event("stop_fight",1);
  set_global_listening_event("prepare_action",1);
  set_global_listening_event("begin_action",1);
  set_global_listening_event("action",1);
  set_global_listening_event("finish_action",1);
  set_global_listening_event("damage",1);
  set_global_listening_event("wound",1);
  set_global_listening_event("move",1);
  set_global_listening_event("missile",1);
}

mixed get_fighter(mixed attacked) {
  object env;
  if (pointerp(attacked))
    return map(attacked,#'get_fighter);
  if (!attacked->can_fight() && 
      (env=environment(attacked)) && 
#if 0
      env->query_carrying(attacked) &&
#endif
      env->can_fight())
    return env;
  return attacked;
}

varargs object * start_fight(object ob, mixed against, mixed range,
                             mapping attack) {
  int i;

  if (!pointerp(against))
    against = ({ against });
  else
    against = against[0..];
  for (i = sizeof(against); i-->0; )
    against[i] = (against[i] && against[i]->get_user()) || against[i];
  send_event("start_fight",
             ([E_AGENT: ob,
               E_TARGET: against,
               E_RANGE: range,
               E_ATTACK: attack]),
             environment(ob));
  return
    filter_objects(against,"query_fighting",ob,range);
}

status stop_fight(object ob, mixed against) {
  if (!pointerp(against))
    against = ({ against });
  send_event("stop_fight",
             ([E_AGENT: ob,
               E_TARGET: against]),
             environment(ob));
  return 
    !(sizeof(filter_objects(against,"query_fighting",ob)) || 
      sizeof(filter_objects(against,"query_fighting",ob,1)));
}

void inflict_damage(object ob, int damage, string id, mapping damage_event) {
  ob->inflict_damage(damage, id, damage_event);
}

void modify_damage(object ob, int damage, string id, mapping damage_event) {
  ob->modify_damage(damage, id, damage_event);
}

void receive_event(mapping e, string t, int p) {
  object c;
  mixed h, d;
  if(t!="move")DEBUG_POINT("alfe", ({ t,p }));
  if (p == EPRIO_HANDLE && e[E_HANDLED])
    // already handled by somebody with higher priority
    return;
  switch (t) {
    case "start_fight":
      switch (p) {
        case EPRIO_MODIFY:
#if 0
          e[E_TARGET] = map_objects(e[E_TARGET],"get_protection",e[E_AGENT]);
          if (!sizeof(e[E_TARGET]))
            cancel_event();
#endif
          break;
        case EPRIO_HANDLE:
          if (e[E_MESSAGES])
            map_messages(e[E_MESSAGES],e);
          c = get_combat_coordinator(e[E_AGENT]);
          c->start_coordinating(e[E_AGENT]);
          if (pointerp(e[E_TARGET])) 
            map(e[E_TARGET],"start_coordinating",c);
          else 
            c->start_coordinating(e[E_TARGET]);
          e[E_AGENT]->start_fighting(e[E_TARGET], e[E_RANGE]);
          break;
      }
      break;
    case "stop_fight":
      if (e[E_MESSAGES])
        map_messages(e[E_MESSAGES], e);
      e[E_AGENT]->stop_fighting(e[E_TARGET]);
      break;
    case "prepare_action":
    case "begin_action":
    case "action":
    case "finish_action":
      if (p == EPRIO_MODIFY && e[E_AGENT]) {
        e[E_TIME] = e[E_AGENT]->get_current_time();
        c = query_combat_coordinator(e[E_AGENT]);
        if (!c && (e[E_TYPE,1] == "attack" || e[E_TYPE,1] == "defense"))
          c = get_combat_coordinator(e[E_AGENT]);
        if (c) 
          c->start_coordinating(e[E_AGENT]);
      }
      if (e[E_TARGET])
        if (pointerp(e[E_TARGET]))
          map_objects(e[E_TARGET],"catch_event",e,t,p);
        else
          call_other(e[E_TARGET],"catch_event",e,t,p);
      if (e[E_WEAPON])
        call_other(e[E_WEAPON],"catch_event",e,t,p);
      if (e[E_TOOL] && e[E_TOOL] != e[E_WEAPON])
        call_other(e[E_TOOL],"catch_event",e,t,p);
      break;
    case "damage":
      filter_indices(e[E_DAMAGE],#'call_other,"catch_event",e,t,p);
      break;
    case "move":
      if (!e[E_AGENT] || !e[E_FROM])  // Alfe 96-Sep-3
        return;  // not nice but functional.
      switch (p) {
#if 1
        case EPRIO_NOTICE2:
          if (c = query_combat_coordinator(e[E_FROM]))
            c->stop_coordinating(e[E_AGENT]);
          break;
#else
        case EPRIO_MODIFY:
          if (h = e[E_AGENT]->query_fighting(1)) {
            stop_fight(e[E_AGENT],m_indices(h));
            if (e[E_AGENT]->query_fighting(1)) {
              cancel_event();
              return;
            }
            e[E_AGENT]->abort_actions();
          }
          break;
        case EPRIO_NOTICE2:
          if (e[E_FROM]) {
            h = all_inventory(e[E_FROM]);
            h = filter_objects(h,"query_fighting",e[E_AGENT]) +
                filter_objects(h,"query_fighting",e[E_AGENT],1);
            if (sizeof(h))
              map(h,#'stop_fight,({e[E_AGENT]}));
          }
          if ((h = e[E_AGENT]->query_enemies()) && mappingp(h)) {
            h = filter_indices(h,(#'present),e[E_TO]);
            if (sizeof(h))
              start_fight(e[E_AGENT],m_indices(h));
          }
          break;
#endif
      }
      break;
    case "wound":
      e[E_TARGET]->add_wound(e[E_OBJECT]);
      break;
    case "missile":
      send_message(({M_THE,M_SIMPLE_DESCRIBE,
                     M_ARG, E_OBJECT," ",M_VERB,"hit",M_ARG, E_OBJECT, " ",
                     M_THE, M_ARG, E_TARGET,"."}),e);  
      // send damage event here
      move_object(e[E_OBJECT], e[E_WOUND] || e[E_TARGET]);
    default:
      return;
  }
}

