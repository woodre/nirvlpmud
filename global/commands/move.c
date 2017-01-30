/****************************************************************************
    move.c -- moving of objects (living or not) by sending events
                    written by Ugh for Tubmud
****************************************************************************/
#include <closures.h>
#include <event.h>
#include <grammar.h>
#include <describe.h>
#include <prop/item.h>
#include <prop/player.h>
#include <prop/room.h>
#include <prop/living.h>
#include <wizlevels.h>
#include <message.h>
#include <libs.h>
#include <is_wizard.h>
#include <server.h>
#include <termcol.h>  // Coogan, 27-Aug-2003, 25-Nov-2003

inherit "basic/name";  // Coogan, 27-Aug-2003
inherit "basic/create";

#define HANDLE_PRIO      0
#define REACTION_PRIO -100

private void receive_move_event(mapping e,string t,int p);

void create() {
  set_global_listening_event("take",1);
  set_global_listening_event("drop",1);
  set_global_listening_event("put",1);
  set_global_listening_event("give",1);
  set_global_listening_event("offer",1);
  set_global_listening_event("move",1);
  listen_event("take");
  listen_event("drop");
  listen_event("put");
  listen_event("give");
  listen_event("offer");
  listen_event("move",HANDLE_PRIO,#'receive_move_event);
  listen_event("move",REACTION_PRIO,#'receive_move_event);
  create::create();
}

#if 0  // Coogan, 18-May-98, also replaced all occurences of get_enc() with
       // get_encumbrance()
private int get_enc(object ob) { // check if ob exists, Coogan, 01-Jan-97
  return ob && (ob->query_encumbrance() || 2500*ob->query_weight());
}
#endif

status query_gettable(object ob, string name) {
  object from;
  name = name || ob->query_name();

  if (!ob->get(name))
    return 0;
  if ((from = environment(ob)) && from != this_player()) {
    if (living(from)) {
      if (with_player(from,#'call_other,({ob,"drop",1})))
        return 0;
      if (!from->is_offered(ob,this_player()))
        return 0;
    }
    if (from != environment(this_player()) &&
        !from->can_put_and_get())
      return 0;
  }
  return 1;
}

status query_giveable(object ob, string name, object to) {
  if (!with_player(to,#'query_gettable,({ob,name})))
    return 0;
  if (to->refuse_object(ob))
    return 0;
  return 1;
}

private void get_objects(mapping e) {
  mixed h;
  object *temp, *too_light, *not_offered, *cant_be_dropped, env,tmp;
  closure test, enc;
  int i, en;
  e[E_TARGET]=filter_objects(e[E_TARGET],"short");  // Alfe 96-Mar-6
  env = environment(this_player());
  if (!sizeof(e[E_TARGET])) {
    write("Nothing taken.\n");
    return;
  }
  temp = filter(e[E_TARGET],#'present,this_player());
  e[E_TARGET] -= temp;
  if (!sizeof(e[E_TARGET])) {
    write("You already have all this.\n");
    return;
  }
  if (e[E_ID] && sizeof(temp) && e[E_NUMBER] &&
      sizeof(e[E_TARGET])-sizeof(temp)<e[E_NUMBER])
    send_message(({M_WRITE, "You already have ",M_THE,temp,"."}));
  // Fangorn 96-April-9, Fix for living rooms
  if (sizeof(e[E_TARGET]) && e[E_TARGET][0] != environment(this_player()) &&
      living(environment(e[E_TARGET][0])) &&
#if 1
// temporarily added by Carador, 10-Feb-97, this will be replaced by 
// something better soon.  // not so soon i think ;-)  Alfe 97-Jul-26
      !environment(e[E_TARGET][0])->is_living_container() &&
#endif
      environment(e[E_TARGET][0])!= environment(this_player())) {
    h = symbol_function("is_offered",environment(e[E_TARGET][0]));
    if (!h) {  // should not occur, but anyway ...
      write("That would be stealing.\n");
      return;
    }
    not_offered = e[E_TARGET];
    e[E_TARGET] = filter(e[E_TARGET],h,e[E_AGENT]);
    not_offered -= e[E_TARGET];
    // let the offerer drop the things to be taken.
    if (sizeof(e[E_TARGET]))
      cant_be_dropped = with_player(environment(e[E_TARGET][0]),
                                    (#'filter_objects),
                                    ({ e[E_TARGET],"drop" }));
    else
      cant_be_dropped = ({});
    e[E_TARGET] -= cant_be_dropped;
    if (sizeof(not_offered)) {
      // The player tries to take them, so obviously he accepts them.
      // Ugh Mar-31-98
      filter(not_offered,"set_accepted",e[E_AGENT]);
      send_message(({ M_THE,M_ARG,E_AGENT,M_VERB,"try",M_ARG,E_AGENT,
                      " to take ",M_OBJECT,M_THE,not_offered," but ",
                      M_VERB,"fail",M_ARG,E_AGENT," because ",
                      M_THE,environment(not_offered[0]),
                      M_VERB,"are",environment(not_offered[0]),
                      " not offering ",M_OBJECTIVE,not_offered," to ",
                      M_OBJECTIVE,M_ARG,E_AGENT,"." }),e);
    }
    if (sizeof(cant_be_dropped))
      send_message(({ M_THE,cant_be_dropped,M_VERB,"cannot",cant_be_dropped,
                      " be dropped by ",M_OBJECTIVE,
                      environment(cant_be_dropped[0]),"." }),e);
    if (sizeof(e[E_TARGET]))
      map_indices(environment(e[E_TARGET][0])->query_offered(),
                  lambda(({ 'x }),
                         ({ (#'call_other),
                            environment(e[E_TARGET][0]),
                            "query_offered_id",
                            'x })));
  }
#if 1  // Coogan, 30-Jun-2004
  if (member(e[E_TARGET], env) > -1) {
    e[E_TARGET] -= ({ env });
    if (!sizeof(e[E_TARGET])) {
      if (!env->do_take_action(e[E_ID]))
        write("You can't take that.\n");
      return;
    }
  }
#else  
  if (sizeof(e[E_TARGET]) == 1 && e[E_TARGET][0] == env) {
    e[E_TARGET] = ({});
    if (!env->do_take_action(e[E_ID]))
      write("You can't take that.\n");
    return;
  }
#endif
  // calling of do_take_action() in fakeitems of items as well as rooms
  // introduced by Ugh Oct-1-1997
  e[E_TARGET] -=
    (temp = filter_objects(e[E_TARGET],"query_fakeitem_id",e[E_ID]));
  e[E_TARGET] += (temp = filter_objects(temp,"do_take_action",e[E_ID]));
  if (!sizeof(e[E_TARGET])) {  // Alfe 98-Jun-19
    message("You can't take that.\n");
    return;
  }
  temp = e[E_TARGET] - temp;
  temp = temp - filter_objects(temp,"get",e[E_ID]);
  e[E_TARGET] -= temp;
  if (sizeof(temp) && (!e[E_NUMBER] || e[E_NUMBER] > sizeof(e[E_TARGET]))) {
    h = filter(temp,lambda(({ 'x }),
                                 ({ (#'pointerp),
                                    ({ (#'call_other),'x,"query_property",
                                       P_NOT_PORTABLE }) })));
    // h is an array of the not portable things which have an own fail-
    // message set in the property P_NOT_PORTABLE
    if (sizeof(temp) > sizeof(h))
      send_message(({M_WRITE,"You can't take ",M_THE,temp-h,"."}));
    map(map_objects(h,"query_property",P_NOT_PORTABLE),
              lambda(({ 'x }),
                     ({ (#'send_message),
                        ({ CL_L_RANGE,'x,0 }),  // copy the messages to keep
                                                // things like M_WRITE!
                        e })));
  }
  if (!sizeof(e[E_TARGET]))
    return;
  if (e[E_NUMBER])
    e[E_TARGET] = e[E_TARGET][0..e[E_NUMBER]-1];
  if (sizeof(e[E_TARGET])) 
    map_messages(e[E_MESSAGES],e);
  else {
    write("Nothing taken.\n");
    return;
  }
  temp = ({});
  too_light = ({});
  tmp = environment(e[E_TARGET][0]);
  if (tmp == environment(this_player()))
    tmp = 0;
  else
    enc = symbol_function("add_encumbrance",tmp);
  test = symbol_function("test_encumbrance",this_player());
  for (i=0;i<sizeof(e[E_TARGET]);i++) {
    en = get_encumbrance(e[E_TARGET][i]);  
    if (enc && !funcall(enc,-en,e[E_ID]))
      too_light += e[E_TARGET][i..i];
#if 1
// re-enabled these lines that have been disabled by somebody unknown.
// Carador, 13-Oct-97,
// these are the lines that check if a player can pick up a certain object
// without these lines players can carry things without a limit.
// Don't know who disabled this and why.
    else if (test && !funcall(test,en))
      temp += e[E_TARGET][i..i];
#endif
    else {
      move_object(e[E_TARGET][i],this_player());
      this_player()->add_encumbrance(en);
    }
  }
  if (tmp && sizeof(too_light))
    send_message(({ "As ",M_PL,M_PL_VERB,"take"," out ",M_OBJECT,M_THE,
                    too_light,", ",M_THE,tmp,M_VERB,"seem",tmp,
                    " to get too heavy, so ",M_PL,M_PL_VERB,"put",
                    M_PRONOUN,M_OBJECT,too_light," back." }));
  e[E_TARGET] -= (temp + too_light);
  if (sizeof(temp))
    send_message(({ temp,M_VERB,"are",temp," too heavy, so ",M_PL,
                    M_PL_VERB,"drop",M_OBJECT,M_PRONOUN,temp," again." }));
  map(temp,#'move_object,environment(this_player()));

// following message added by Carador, 13-Dec-97
  if (sizeof(e[E_TARGET]))
    if (this_player()->query_carry() > this_player()->query_max_carry())
      message("You have great difficulties in holding all your "
              "equipment.\n");
}

// changed to 'status' (success) by Ugh Apr-9-98
// also changed some write()s to notify_fail()s
private status drop_objects(mapping e) {
  object *temp,env,tmp;
  string list;
  mixed below,current;
  closure enc;
  int i, en;
  env = e[E_TO];  // env = object into which the things are dropped
  temp = e[E_TARGET] - (e[E_TARGET] & deep_inventory(this_player()));
                   // temp = objects to be dropped which are not in this_player
  e[E_TARGET] -= temp;  // remove them from the objects to be dropped
  if (!sizeof(e[E_TARGET])) {
    write("You have none of these things.\n");
    return 1; // the result is that of a successful drop
  }
  e[E_TARGET] -= filter_objects(e[E_TARGET],"query_fakeitem_id",e[E_ID]);
  // remove all fakeitems (don't drop an item if one of its fakeitems is given)
  temp = ({});
  if (sizeof(e[E_TARGET]) == 1) {  // one single item to be dropped?
    if (e[E_TARGET][0]->drop())  // not silently
      temp = e[E_TARGET];
  }
  else
    temp = filter_objects(e[E_TARGET],"drop",1);  // silently
      // temp = all objects which cannot be dropped (which return 1 in drop(1))
  e[E_TARGET] -= temp + ({ 0 });  // remove them and all destructed objects
  if (e[E_NUMBER])
    e[E_TARGET] = e[E_TARGET][0..e[E_NUMBER]-1];
               // choose the first N possible items if the player gave a number
  // if not exactly one item wasn't droppable but nothing is to be dropped
  // anymore, state that. we assume that a single item has given out a proper
  // message in its drop(0).
  // changed sizeof(temp) != 1 to sizeof(temp), because dropping exactly
  // one not droppable item causes a 'What?'. Coogan, 01-May-98
  if (sizeof(temp)  && !sizeof(e[E_TARGET])) {
    e[E_TARGET] = ({});
    if (!sizeof(temp)) {
      write("Nothing dropped.\n");
      return 1;
    } else {
      return
        notify_fail("Nothing dropped.\n"), 0;
    }
  }
  if (!sizeof(e[E_TARGET]))  // nothing to be done anymore?
    return 0;

#if 1  // Coogan, 09-Jul-2003, added message for empty
  if (e[E_CONTAINER] &&
      e[E_TYPE] == "empty" &&
      !sizeof((e[E_TARGET] & all_inventory(e[E_CONTAINER])) - e[E_TARGET]))
    e[E_MESSAGES][0] = ({ M_THE,M_ARG,E_AGENT,M_VERB,"empty",M_ARG,E_AGENT,
                          M_THE,M_OBJECT,M_ARG,E_CONTAINER,", dropping ",
                          M_DESCRIBE_UNOWNED,M_OBJECT,
                          M_ARG,E_TARGET,M_ADVERBS,"." });
#endif

  map_messages(e[E_MESSAGES],e);
  tmp = environment(e[E_TARGET][0]);  // tmp = env of item to be dropped
  if (tmp == this_player())
    tmp = 0;
  else
    enc = symbol_function("add_encumbrance",tmp);
  temp = ({});
  for (i = sizeof(e[E_TARGET]); i--; ) {
#if 0
    en = get_encumbrance(e[E_TARGET][i]);
    if (enc && !funcall(enc,-en))
      temp += e[E_TARGET][i..i];
    else
#endif
    {
#if 0  // Coogan, 09-Jul-2003, not needed anymore
      if (environment(e[E_TARGET][i]) != this_player())  // drop from a sack?
        environment(e[E_TARGET][i])->                    // Alfe 97-Aug-13
          add_encumbrance(-get_encumbrance(e[E_TARGET][i]));
#endif
      move_object(e[E_TARGET][i],env);
    }
  }
  e[E_TARGET] -= temp;
  if (tmp && sizeof(temp))
    send_message(({ "As ",M_PL_THE,M_PL_VERB,"take"," out ",M_OBJECT,M_THE,temp,
                    ", ",M_THE,tmp,M_VERB,"seem",tmp," to get too heavy, so ",
                    M_PL_PRONOUN,M_PL_VERB,"put",M_PRONOUN,M_OBJECT,temp,
                    " back." }));
  if (sizeof(e[E_TARGET])) {
    // following message added by Carador, 13-Dec-97
    if (this_player()->query_carry() > this_player()->query_max_carry())
      message("You still have great difficulties in holding all your"
              " equipment.\n");
    for (current = env;
         (below=current->query_property(P_NO_GROUND));
         current = below)
      if (stringp(below) || objectp(below)) {
        send_message(({ M_ROOM,current,
                        M_THE,e[E_TARGET]," instantly ",
                        M_VERB,"fall",e[E_TARGET]," down out of reach." }));
        map(e[E_TARGET],(: move_object($1,$2) :),below);
        send_message(({ M_ROOM,below,
                        e[E_TARGET],M_VERB,"come",e[E_TARGET],
                        " falling down from above." }));
      }
      else {  // no string?  nowhere to fall to...
        send_message(({ "Though there is no ground, ",M_THE,e[E_TARGET],
                        M_VERB,"hover",e[E_TARGET]," in mid-air." }));
        break;
      }
    }
  return 1;
}

private void put_objects(mapping e) {
  object *temp,env;
  mixed tmp;
  string list;
  closure enc;
  int i, en;
  env = environment(this_player());
  temp = e[E_TARGET] - filter(e[E_TARGET],lambda(({'x}),
                                                       ({ (#'call_other), 
                                                          e[E_RECIPIENT], 
                                                          "can_put_and_get",
                                                          e[E_ID],
                                                          'x })));
  if (sizeof(temp))
    message(({({M_WRITE,"You can't put ",
                M_OBJECT,M_THE,temp," ",e[E_PREPOSITION],"to ",
                M_OBJECT,M_THE,e[E_RECIPIENT],"."})}));
  e[E_TARGET] -= temp + ({ e[E_RECIPIENT] });
  e[E_TARGET] = filter(e[E_TARGET],#'present,this_player());
  e[E_TARGET] -= filter_objects(e[E_TARGET],"query_fakeitem_id",e[E_ID]);
  temp = ({});
  if (sizeof(e[E_TARGET]) == 1) {
    if (e[E_TARGET][0]->drop())
      temp = e[E_TARGET];
  }
  else
    temp = filter_objects(e[E_TARGET],"drop",1);
  e[E_TARGET] -= temp + ({ 0 });
  temp = filter_objects(e[E_TARGET],"prevent_insert",e[E_ID]);
  e[E_TARGET] -= temp;
  if (sizeof(temp) && (!e[E_NUMBER] || e[E_NUMBER] < sizeof(e[E_TARGET])))
    send_message(({ M_WRITE,"You can't put ",
                    M_OBJECT,M_THE,temp," ",e[E_PREPOSITION],"to ",
                    M_OBJECT,M_THE,e[E_RECIPIENT],"." }));
  if (e[E_NUMBER])
    e[E_TARGET] = e[E_TARGET][0..e[E_NUMBER]-1];
  if (!sizeof(e[E_TARGET])) {
    write("Nothing put.\n");
    return;
  }
  map_messages(e[E_MESSAGES],e);
  enc = symbol_function("add_encumbrance",e[E_RECIPIENT]);
  temp = ({});
  for (i=0;
       i<(e[E_NUMBER]?e[E_NUMBER]:sizeof(e[E_TARGET])) &&
       i<sizeof(e[E_TARGET]);
       i++) {
    en=get_encumbrance(e[E_TARGET][i]);
    if (enc && !funcall(enc,en,e[E_ID]))
      temp += e[E_TARGET][i..i]; 
    else {
      if (!e[E_RECIPIENT]->add_inventory(e[E_TARGET][i],
                                         e[E_ID],e[E_PREPOSITION]))
        move_object(e[E_TARGET][i],e[E_RECIPIENT]);
      this_player()->add_encumbrance(-en);
    }
  }
  if (sizeof(temp))
    send_message(({ M_THE,temp,M_VERB,"do",temp,"n't seem to fit ",
                    e[E_PREPOSITION],"to ",M_OBJECT,M_THE,
                    e[E_RECIPIENT],", though." }));
  e[E_TARGET] -= temp;

// following message added by Carador, 13-Dec-97
  if (sizeof(e[E_TARGET]) &&
      this_player()->query_carry() > this_player()->query_max_carry())
    message("You still have great difficulties in holding all your"
            " equipment.\n");
}

private void give_objects(mapping e) {
  object *temp,*refused,*too_light,env,tmp;
  string list;
  closure enc, ref, test;
  int i, en;
  object container;

  env = environment(this_player());
  e[E_TARGET] -= ({ env });
  for (i = sizeof(e[E_TARGET]); i--; )
    if (env != environment(e[E_TARGET][i]) && 
        living (environment(e[E_TARGET][i])) &&
        environment(e[E_TARGET][i]) != this_player()) {
      e[E_TARGET] = ({ });
      write("That would be stealing.\n");
      return;
    }
  if (e[E_ID]) // if() added because E_ID can be 0, Coogan, 07-Nov-2006
    e[E_TARGET] -= filter_objects(e[E_TARGET],"query_fakeitem_id",e[E_ID]);
#if 0  // Coogan, 07-Nov-2006
  temp = e[E_TARGET] - all_inventory(this_player());
#else
  if (e[E_FROM])
    container = e[E_FROM];
  else
    container = this_player();  // let us assume this
  temp = e[E_TARGET] - all_inventory(container);
#endif
  e[E_TARGET] -= temp;
  if (e[E_NUMBER]) {
#if 1  // Coogan, 07-Nov-2006
    if (e[E_ID])
#endif
    temp =
      filter_objects(temp[0..e[E_NUMBER]-sizeof(e[E_TARGET])-1],"get",e[E_ID]);
  }
  else {
#if 1  // Coogan, 07-Nov-2006
    if (e[E_ID])
#endif
    temp = filter_objects(temp,"get",e[E_ID]);
  }
  // added '=' in the next line !!!, Coogan, 07-Nov-2006
  if (!e[E_NUMBER] || e[E_NUMBER] >= sizeof(e[E_TARGET]))
    e[E_TARGET] += temp;
  if (e[E_NUMBER] && e[E_NUMBER] < sizeof(e[E_TARGET]))
    e[E_TARGET] = e[E_TARGET][0..e[E_NUMBER]-1];
  // added the next line, Coogan, 22-Aug-2002
#if 0  // Coogan, 07-Nov-2006
  e[E_TARGET] = filter(e[E_TARGET], #'present, this_player());
  e[E_TARGET] -= filter_objects(e[E_TARGET] & all_inventory(this_player()),
                                "drop");
#else
  e[E_TARGET] = filter(e[E_TARGET], #'present, container);
  e[E_TARGET] -= filter_objects(e[E_TARGET] & all_inventory(container),
                                "drop");
#endif
  e[E_TARGET] = with_player(e[E_RECIPIENT],#'filter_objects,
                            ({ e[E_TARGET],"get",e[E_ID] }));
  if (!sizeof(e[E_TARGET])) {
    write("Nothing given.\n");
    return;
  }
#if 0
  // giving from one player to another is disabled to allow refusings.
  //                           Alfe 97-Jul-26
  // removed tests for interactives
  if (query_once_interactive(e[E_AGENT]) &&
      query_once_interactive(e[E_RECIPIENT]) &&
      e[E_RECIPIENT]->query_property(P_AUTO_REFUSE)) {
    message(({ ({ M_THE,e[E_AGENT],M_VERB,"try",e[E_AGENT]," to give ",
                  M_THE,e[E_TARGET]," to ",M_OBJECT,M_THE,e[E_RECIPIENT],
                  " but ",M_VERB,"fail",e[E_AGENT]," because ",
                  M_THE,e[E_RECIPIENT]," automatically ",
                  M_VERB,"refuse",e[E_RECIPIENT],M_OBJECTIVE,e[E_TARGET],
                  "." }),
               ({ M_WRITE,"You may offer your things to ",M_SUBJECT,e[E_AGENT],
                  M_OBJECTIVE,e[E_RECIPIENT],", though." }) }));
    return;
  }
#endif
  map_messages(e[E_MESSAGES],e);
  tmp = environment(e[E_TARGET][0]);
  if (tmp == environment(this_player()) || tmp == this_player())
    tmp = 0;
  else
    enc = symbol_function("add_encumbrance",tmp);
  test = symbol_function("test_encumbrance",e[E_RECIPIENT]);
  ref = symbol_function("refuse_object",e[E_RECIPIENT]);
  temp = ({});
  refused = ({});
  too_light = ({});
  for (i=0;i<sizeof(e[E_TARGET]);i++) {
    en=get_encumbrance(e[E_TARGET][i]);
    if (enc && !funcall(enc,-en))
      too_light += e[E_TARGET][i..i];
    else if (
#if 1 // comment that out somewhen -- Ugh Mar-31-98
      (!ref && e[E_RECIPIENT]->query_property(P_AUTO_REFUSE)) ||
#endif
             (ref && e[E_TARGET][i] && funcall(ref,e[E_TARGET][i])))
             
      refused += e[E_TARGET][i..i];
    else if (test && e[E_TARGET][i] &&
             environment(e[E_TARGET][i]) != e[E_RECIPIENT] && 
             !funcall(test,en))
      temp += e[E_TARGET][i..i];
    else if (e[E_TARGET][i]) {
      move_object(e[E_TARGET][i],e[E_RECIPIENT]);
      e[E_RECIPIENT]->add_encumbrance(en);
    }
  }
  if (tmp && sizeof(too_light))
    send_message(({ "As ",M_PL_THE,M_PL_VERB,"take"," out ",M_OBJECT,M_THE,
                    too_light,", ",M_THE,tmp,M_VERB,"seem",tmp,
                    " to get too heavy, so ",M_PL_THE,M_PL_VERB,"put",
                    M_OBJECTIVE,too_light," back." }));
  if (sizeof(refused)) {
    filter(refused,"offer_item",e[E_AGENT],e[E_RECIPIENT]);
    message(({ e,  // these are the args for the following messages
               ({ M_THE,M_ARG,E_RECIPIENT,M_VERB,"refuse",M_ARG,E_RECIPIENT,
                  " to take ",M_DESCRIBE_UNOWNED,M_OBJECT,refused,
                  " from ",M_THE,M_ARG,E_AGENT, "." }),
                  // added ',' before the ".", Coogan, 11-Jan-99
               ({ "Instead, ",M_PRONOUN,M_ARG,E_AGENT,
                  M_VERB,"offer",M_ARG,E_AGENT,M_OBJECTIVE,refused," to ",
                  M_OBJECTIVE,M_ARG,E_RECIPIENT,"." }) }));
  }
  if (sizeof(temp)) {
    send_message(({ M_THE,temp,M_VERB,"are",temp," too heavy for ",
                    M_OBJECT,M_THE,M_ARG,E_RECIPIENT,", so ",
                    M_PRONOUN,M_ARG,E_RECIPIENT,
                    M_VERB,"drop",M_ARG,E_RECIPIENT,
                    M_OBJECT,M_PRONOUN,temp,"." }),e);
    map(temp,#'move_object,environment(this_player()));
  }
  e[E_TARGET] -= (temp + refused + too_light);
  enc = symbol_function("receive_object",e[E_RECIPIENT]);
  if (enc)
    map (e[E_TARGET], enc, this_player());
  e[E_TARGET] -= ({ 0 });  // Coogan, 01-Jan-98

// following messages added by Carador, 13-Dec-97
  if (sizeof(e[E_TARGET])) {
    // changed this_player() to e[E_AGENT], Coogan, 01-Jan-98
    if (e[E_AGENT]->query_carry() > e[E_AGENT]->query_max_carry())
      message("You still have great difficulties in holding all your "
              "equipment.\n", e[E_AGENT]);
    if (e[E_RECIPIENT]->query_carry() > e[E_RECIPIENT]->query_max_carry())
      message("You have great difficulties in holding all your "
              "equipment.\n", e[E_RECIPIENT]);
  }
}

private void offer_objects(mapping e) {
  object env, *not_in_hand, *fakeitems;
  env = environment(e[E_AGENT]);
  e[E_TARGET] -= ({ env });
  not_in_hand = ({});
  // anything to offer which we cannot offer at all?
  not_in_hand = filter(e[E_TARGET],
                             lambda(({ 'x }),({ (#'!=),e[E_AGENT],
                                                ({ (#'environment),'x }) })));
  e[E_TARGET] -= not_in_hand;
  // remove all fakeitems
  fakeitems = filter_objects(e[E_TARGET],"query_fakeitem_id",e[E_ID]);
  e[E_TARGET] -= fakeitems;
  // if a number was given, choose only the first N targets
  if (e[E_NUMBER])
    e[E_TARGET] = e[E_TARGET][0..e[E_NUMBER]-1];
  if (sizeof(not_in_hand))
    send_message(({ M_WRITE,M_PL_THE,M_PL_VERB,"cannot"," offer ",M_OBJECT,
                    not_in_hand," because ",M_PL_PRONOUN,M_PL_VERB,"do",
                    " not have ",M_OBJECTIVE,not_in_hand," in ",
                    M_PL_POSSESSIVE," hand." }));
  if (sizeof(fakeitems))
    send_message(({ M_WRITE,M_THE,M_DESCRIBE_GROUP,e[E_ID],fakeitems,
                    " of ",M_THE,fakeitems," cannot be offered." }));
  if (!sizeof(e[E_TARGET])) {
    write("Nothing offered.\n");
    return;
  }
  // tell what happens
  map_messages(e[E_MESSAGES],e);
  // now mark them as offered
  filter(e[E_TARGET],symbol_function("offer_item",e[E_AGENT]),
               e[E_RECIPIENT],e[E_ID]);
}

private void receive_move_event(mapping e,string t,int p) {
  mixed h;
  mixed dir, in, out, liv;
  object agent, dest, from, *excl_from, *excl_to, *could_see_before;
  mapping args;
  if (t != "move")
    return;
  if (!(agent = e[E_AGENT]))
    return;
  switch (p) {
  case HANDLE_PRIO:
    if (e[E_HANDLED])
      return;
    e[E_HANDLED] = 1;
    dest = e[E_TO];
    from = e[E_FROM];
    dir = e[E_DIR];
// Ugh Aug-5-1996
    if (from && dir != "X") {
      if (stringp(dir) && from->prevent_use_exit(dir)) {
        cancel_event();
        return;
      }
#define LINKED_MOVE
#ifdef LINKED_MOVE
      if (!e[E_CO_AGENTS])
        e[E_CO_AGENTS] = ({});
      if (!e[E_LINKED])
        e[E_LINKED] = ({});
      h = e[E_CO_AGENTS]+e[E_LINKED]+({agent});
      h = filter_objects(all_inventory(from)-h,"query_linked_to",agent);
      e[E_LINKED] += h;
      if (sizeof(e[E_LINKED])) {
        h = copy(e);
        h[E_CO_AGENTS] += ({agent});
        h[E_AGENT] = e[E_LINKED][0];
        h[E_LINKED] = e[E_LINKED][1..];
        send_event("move",h,e[E_RECEIVERS]);
        if (h[E_CANCELLED] || 
            h[E_TO] != e[E_TO]) {
          cancel_event();
          return;
        }
        e[E_CO_AGENTS] = h[E_CO_AGENTS];
      } else {
        e[E_CO_AGENTS] += ({agent});
      }
      // if we are not initiator of this move
      if (sizeof(e[E_CO_AGENTS]) && e[E_CO_AGENTS][0] != agent)
        return; // the moving will be done by the initiator
#endif
    }
    if (sizeof(e[E_CO_AGENTS]) > 1) { // we are the initiator of a move of many
      filter_objects(e[E_CO_AGENTS], "leave_combat");
      filter_objects(e[E_CO_AGENTS], "start_show_long_delayed");
                                                      // Coogan, 06-Nov-2002
      h = filter_objects(e[E_CO_AGENTS],"short");
      if (stringp(dir) && sizeof(h))
        send_message(({ M_ROOM,from,
                        M_CNTL_SEQ, TERMCOL_PLAYER,
                        "together, ",M_THE,h,M_VERB,"leave",h," "+dir+".",
                        M_CNTL_SEQ, TERMCOL_NORMAL }));
      filter(e[E_CO_AGENTS],#'move_object,dest);
      map_objects(e[E_CO_AGENTS], "decrease_saturation"); // Coogan, 01-Apr-2003
      send_message(({M_TARGETS,
                     filter(e[E_CO_AGENTS],#'is_wizard,IW_APPRENTICE),
                     "/"+object_name(dest)}));
      if (stringp(dir) && sizeof(h))
        send_message(({ M_ROOM,dest,M_EXCLUDE,e[E_CO_AGENTS],
                        M_CNTL_SEQ, TERMCOL_PLAYER,
                        "together, ",M_THE,h,M_VERB,"arrive",h,".",
                        M_CNTL_SEQ, TERMCOL_NORMAL }));
      return;
    }
    // get the message before the living is moved
    out = (e[E_OUT] ||
           (intp(dir)? 0 : // silent?
            // else not silent:
            (dir == "X" ?  // teleport?
             (agent->query_mmsgout() ||
              ({ M_THE, M_ARG, E_AGENT,
                 M_VERB, "disappear", M_ARG, E_AGENT,
                 " in a puff of smoke." })) :
             (agent->query_msgout() ||
              ({ M_THE, M_ARG, E_AGENT,
                 M_VERB, "leave", M_ARG, E_AGENT,
                 " ", M_ARG, E_OUT, "." })))));
    agent->leave_combat();
    agent->start_show_long_delayed();  // Coogan, 06-Nov-2002
#if 1  // Alfe
    // we need to compute who could see _before_ the move has taken place
    // to give proper messages to them in case that they cannot see anymore
    // _after_ the move has taken place.
    could_see_before = (filter_objects(filter(all_inventory(from ||
                                                            this_object()),
                                              (#'living)),
                                       "test_sight", from, 1) +
                        filter_objects(filter(all_inventory(dest ||
                                                            this_object()),
                                              (#'living)),
                                       "test_sight", dest, 1));
#endif
    move_object(agent, dest);
    agent->decrease_saturation(); // Coogan, 01-Apr-2003
    if (dest == from || environment(agent) != from)
      e[E_SUCCESS] = 1;  // Alfe 2002-Sep-4
    if (agent->query_level() >= WL_APPRENTICE) 
      tell_object(agent, "/"+object_name(environment(agent))+"\n");
    if (e[E_SUCCESS] && agent->short()) {
      // give messages only if the moved one is visible
      // and the move is really done as wished
      h = m_indices(e[E_MESSAGES])+({ agent });  // the ones with special-msgs
      args = ([ E_AGENT: agent,
                E_FROM: from,
                E_TO: dest,
                E_DIR: dir ]);
#if 0
      map_messages(e[E_MESSAGES],e||args);
#else
      map_indices(e[E_MESSAGES],
                  lambda(({ 'receiver }),
                         ({ #'send_message,
                            ({ #'+,
                               ({ CL_ARRAY, M_TARGETS, 'receiver }),
                               ({ CL_INDEX, e[E_MESSAGES], 'receiver }) }),
                            e||args })));
#endif
      in = (e[E_IN] ||
            (intp(dir)? 0 :  // silent?
             // else not silent:
             (dir == "X"?  // teleport?
              (agent->query_mmsgin() || "appears in a puff of smoke") :
              (agent->query_msgin()  || "arrives"))));
      if (stringp(in))  // no complex message yet?
        in = ({ agent, " "+in+"." });
      if (stringp(out))  // no complex message yet?
        out = (dir == "X"?
               ({ M_THE, agent, " "+out+"." }) :
               ({ M_THE, agent, " "+out+" ", M_ARG, E_DIR, "." }));
      if (in && pointerp(in)) {  // Coogan, 27-Aug-2003
        in = ({ M_CNTL_SEQ, TERMCOL_LIVING }) + in +
             ({ TERMCOL_DESC_NORMAL });
      }
      if (out && pointerp(out)) {  // Coogan, 27-Aug-2003
        out = ({ M_CNTL_SEQ, TERMCOL_LIVING }) + out +
              ({ TERMCOL_DESC_NORMAL });
      }

#if 1  // those, who can't see, don't get the name of the leaving/arriving
       // person. Coogan, 15-Apr-99
      if (from) {
        excl_from = filter(all_inventory(from), #'living);
        excl_from -= filter_objects(excl_from, "test_sight", from, 1); // added
        excl_from -= h;     //  silently arg to test_sight(), Coogan, 18-Dec-00
#if 1  // Alfe 2006-Aug-23
        excl_from -= could_see_before;
        // ^^^ who could see before should notice the leaving
#endif
      }

      excl_to = filter(all_inventory(dest), #'living);
      excl_to -= filter_objects(excl_to, "test_sight", dest, 1);
      excl_to -= h;

      if (from && sizeof(excl_from))
        send_message(({ M_TARGETS, excl_from, "Someone leaves." }));

      if (sizeof(excl_to))
        send_message(({ M_TARGETS, excl_to, "Someone arrives." }));
#endif
      if (liv=e[E_MSG]) {  // Alfe 2002-Sep-4
        // if given, this is a message for the moved living itself.
        if (stringp(liv))
          liv = ({ liv });
        send_message(({ M_TARGETS, agent, M_INDENT, 0 }) + liv, e||args);
      }
      if (from && out)
        send_message(({ M_ROOM,from,M_EXCLUDE, h+excl_from }) + out, e||args);
      if (in)
        send_message(({ M_ROOM,dest,M_EXCLUDE, h+excl_to   }) + in,  e||args);
    }
    agent->enter_combat();
    // added [agent &&] check, as agent can be killed, Coogan, 11-Dec-2003
    agent && agent->remove_absent_references();  // Alfe 2002-May-2
    break;
  case REACTION_PRIO:
#if 1  // Alfe 2002-Mar-14
    e[E_FROM] && e[E_FROM]->catch_event(e, t, p);
#endif
    agent->adjust_to_environment();
    if (e[E_CMD] || (e[E_DIR] != 1 && interactive(agent))) {
      if (e[E_SUCCESS]) {
        if (e[E_CMD])
          command(e[E_CMD], agent);
        else
          agent->look_at_environment();
      }
    }
#if 1  // Alfe 2002-Mar-14
    e[E_TO] && e[E_TO]->catch_event(e, t, p);
#endif
    break;
  }
}

// Alfe 2002-May-2
private void check_for_references(object room) {
  object obj;
  for (obj = first_inventory(room); obj; obj = next_inventory(obj))
    if (living(obj))
      obj->remove_absent_references();
}

void receive_event(mapping e, string type, int prio) {
  if (e[E_HANDLED] || e[E_CANCELLED])  // Alfe 95-Jun-20
    return;
  e[E_HANDLED] = 1;  // Alfe 95-Jun-20
  if (e[E_AGENT]->query_ghost() && type != "drop") {
    message("You try to but fail.  It seems to be impossible in your"
            " immaterial state.\n");
    e[E_SUCCESS] = 1;  // states that the trial has been executed
    return;
  }
  if (e[E_HANDLER]) return;
  switch (type) {
  case "take":
    with_player(e[E_AGENT],#'get_objects,e);
    check_for_references(environment(e[E_AGENT]));  // Alfe 2002-May-2
    break;
  case "drop":
    // Ugh Apr-9-98 filling of field E_SUCCESS
    e[E_SUCCESS] = with_player(e[E_AGENT],#'drop_objects,e);
    // we omit the check for references here  Alfe 2002-May-2
    break;
  case "put":
    with_player(e[E_AGENT],#'put_objects,e);
    // we omit the check for references here  Alfe 2002-May-2
    break;
  case "give":
    with_player(e[E_AGENT],#'give_objects,e);
    check_for_references(environment(e[E_AGENT]));  // Alfe 2002-May-2
    break;
  case "offer":
    with_player(e[E_AGENT],#'offer_objects,e);
    break;
  }
}

private status order_objects(mixed *objects,int i) {
  mixed h,res,aux;
  if (!this_player())
    return 0;
  while (get_eval_cost() > 50000 && i--) {
    h = regexplode(objects[i],
                   "[a-zA-Z0-9][-a-zA-Z0-9'_]*[a-zA-Z0-9]|[^ \t\n]");
    if (!call_other_2ref(LIB_GRAMMAR,"parse_object",
                         &res,&aux,0,(sizeof(h)>>1)-1,
                         split_array(h,2)[0],h))
      return write("You have no \""+objects[i]+"\""+".\n"), 0;
    objects[i] = res;
  }
  if (i<=0) {
    h = map(objects,#'environment)-({ this_player() });
    if (sizeof(h))  // something moved, so stop.
      return send_message(({ M_WRITE,"cannot order, ",h," moved."})), 0;
#if 1  // this saves a LOT of eval cost, Coogan, 18-Nov-2006
    with_delayed_light(#'move_object_group, objects, this_player());
#else
    for (i=sizeof(objects); i--; ) {
      move_object(objects[i],this_player());
    }
#endif
    return write("Things ordered as wished.\n"), 1;
  }
  else {
    call_out(#'order_objects,2,objects,i);
    return write("Please wait, not finished.\n"), 2;
  }
}

private object get_container(object *objects) {
  mixed h;
#if 0  // Alfe 98-Jan-20 (why should the container have to be present?)
  return (sizeof(objects) && 
          (h = environment(objects[0])) &&
          (present(h,this_player()) ||
           (h != this_player() &&
            present(h,environment(this_player())))));
#else
  return (sizeof(objects) &&
          (h=environment(objects[0])) &&
          h != this_player() && environment(h) && h);
#endif
}

private mapping msg_prefix() {
  return (!this_player()->query_property(P_ECHO) ?
          ([ this_player() : ({ "Ok." }) ]) :
          ([ ]));
}

public varargs status send_drop_event(mixed objects,
                                      mixed ids,
                                      int number,
                                      object where,
                                      string type) {
  // added fifth arg 'type', Coogan, 09-Jul-2003
  object container;
  mapping e;
  if (!pointerp(objects))
    objects = ({ objects });
  if (!number)
    number = sizeof(objects);
  if (!type)
    type = "drop";
  container = get_container(objects);
  e = ([ E_AGENT    : this_player(); 0,
         E_TO       : where || environment(this_player()); 0,
         E_TARGET   : objects; ids,
         E_ID       : (pointerp(ids) ? ids[0] : ids); 0,
         E_NUMBER   : number; 0,
         E_CONTAINER: container; 0,
         E_TYPE     : type; 0,
         E_MESSAGES : msg_prefix() +
                      ([ 0:
#if 1  // Coogan, 22-Apr-98 // 0 => 1 again  Alfe 98-Apr-24
                            ({ M_THE,M_ARG,E_AGENT,
                               M_VERB,"drop",M_ARG,E_AGENT,
                               M_THE,M_OBJECT,M_ARG,E_TARGET,M_ADVERBS,"." })
#else  // this version gives simpler output and is still using PL in an event.
                            ({ M_PL_THE, M_PL_VERB, "drop", M_POSSESSIVE,
                               M_PL, M_NONE, M_SIMPLE_DESCRIBE, M_OBJECT,
                               M_ARG, E_TARGET, "." })
#endif
                      ]); 0,
      ]);
  send_event("drop", e, ({ environment(this_player()) }));
  return e[E_SUCCESS];
}

status can_fly(object living) {
  return (is_wizard(living,IW_WIZARD) ||  // not TOOLUSER, but real wizard!
          living->can_fly() ||
          living->query_property(P_CAN_FLY));
}

int do_action(string action, mapping args) {
  mixed h;
  object ob,ob2,env,container;
  status on;
  mapping msg;

  if ((action == "give" || action == "give_all") &&
      !this_player()->test_sight())
    return 0;  // test_sight() was not called silently, a message was given
  msg = msg_prefix();
  if (args[G_ALL_ONLY_IN_ENVIRONMENT]) {
    args[G_ALL]   = args[G_ALL_ONLY_IN_ENVIRONMENT];
    args[G_ALL,1] = args[G_ALL_ONLY_IN_ENVIRONMENT,1];
  } else if (args[G_ALL_ONLY_IN_INVENTORY]) {
    args[G_ALL]   = args[G_ALL_ONLY_IN_INVENTORY];
    args[G_ALL,1] = args[G_ALL_ONLY_IN_INVENTORY,1];
  } else if (args[G_ALL_OBJECT]) {
    args[G_ALL]   = args[G_ALL_OBJECT];
    args[G_ALL,1] = args[G_ALL_OBJECT,1];
  } else if (args[G_ALL_INDIRECT]) {
    args[G_ALL]   = args[G_ALL_INDIRECT];
    args[G_ALL,1] = args[G_ALL_INDIRECT,1];
  } else if (args[G_ALL_IN_ENVIRONMENT]) {
    args[G_ALL]   = args[G_ALL_IN_ENVIRONMENT];
    args[G_ALL,1] = args[G_ALL_IN_ENVIRONMENT,1];
  } else if (args[G_ALL_IN_INVENTORY]) {
    args[G_ALL]   = args[G_ALL_IN_INVENTORY];
    args[G_ALL,1] = args[G_ALL_IN_INVENTORY,1];
  } else if (args[G_CONTAINER]) {  // this { }, Coogan, 09-Jul-2003
    args[G_ALL]   = all_inventory(args[G_CONTAINER]);
    args[G_ALL,1] = map(args[G_ALL], #'describe, ARTICLE_NONE);
  }
  container = get_container(args[G_ALL]);
  switch (action) {
#if 1  // this is a test, Coogan, 13-Aug-01
  case "pick_up_all_test":
    send_event("take",
               ([ E_TYPE    : "take"          ; 0, // Coogan, 02-May-2007
                  E_AGENT   : this_player()   ; 0,
                  E_FROM    : container       ; 0,
                  E_TARGET  : args[G_ALL]     ; args[G_ALL,1][0],
                  E_ID      : args[G_ALL,1][0]; 0,
                  E_NUMBER  : args[G_ALL,1][1]; 0,
                  E_MESSAGES: msg +
                   ([ 0 : (container
                          ? ({ M_THE, M_ARG, E_AGENT,
                               M_VERB, "take", M_ARG, E_AGENT,
                               M_OBJECT, M_DESCRIBE_UNOWNED, M_ARG, E_TARGET,
                               M_ADVERBS, " from " }) +
                               (present(container,this_player())
                               ? ({ M_POSSESSIVE, M_ARG, E_AGENT,
                                    M_NONE, container, "." })
                               : ({ M_THE, container, "." }))
                          : ({ M_THE, M_ARG, E_AGENT,
                               M_VERB, "take", M_ARG, E_AGENT,
                               M_OBJECT, M_THE, M_ARG, E_TARGET,
                               M_ADVERBS, "." })) ]); 0
                   ]),
               ({ environment(this_player()) }));
    return 1;
#endif
  case "pick_up_all":
#define MAX_NUMBER_OF_OBJECTS 20
    if (sizeof(args[G_ALL]) > MAX_NUMBER_OF_OBJECTS &&
        args[G_ALL,1][1] > MAX_NUMBER_OF_OBJECTS) {
      // crude, i know ...  Alfe 96-Dec-2
      write("Only "+MAX_NUMBER_OF_OBJECTS+
            " objects selected to avoid bugs!\n");
      args[G_ALL,1][1] = MAX_NUMBER_OF_OBJECTS;
    }
    send_event("take",([ E_TYPE: "take"; 0,     // Coogan, 02-May-2007
                         E_AGENT:this_player(); 0,
                         E_FROM:environment(this_player()); 0,// Alfe 98-Jan-20
                         E_TARGET:
                           filter(args[G_ALL],
                                        (#'present),
                                        environment(this_player()));
                           args[G_ALL,1][0],
                         E_ID:args[G_ALL,1][0]; 0,
                         E_NUMBER:args[G_ALL,1][1]; 0,
                         E_MESSAGES:
                           msg + ([ 0 : ({ M_THE,M_ARG,E_AGENT,
                                           M_VERB,"take",M_ARG,E_AGENT,
                                           M_OBJECT,M_THE,M_ARG,E_TARGET,
                                           M_ADVERBS,"." }) ]); 0 ]),
               ({ environment(this_player()) }));
    return 1;
  case "take_all":
    if (sizeof(args[G_ALL]) > MAX_NUMBER_OF_OBJECTS &&
        args[G_ALL,1][1] > MAX_NUMBER_OF_OBJECTS) {
      // crude, i know ...  Alfe 96-Dec-2
      write("Only "+MAX_NUMBER_OF_OBJECTS+
            " objects selected to avoid bugs!\n");
      args[G_ALL,1][1] = MAX_NUMBER_OF_OBJECTS;
    }
    send_event("take",([
               E_TYPE: "take"; 0,     // Coogan, 02-May-2007
               E_AGENT:this_player(); 0,
               E_FROM:container; 0,        // Carador May-96
               E_TARGET:args[G_ALL]; args[G_ALL,1][0], 
               E_ID:args[G_ALL,1][0]; 0,
               E_NUMBER:args[G_ALL,1][1]; 0,
               E_MESSAGES: msg +
                 ([ 0 :
#if 1
                        /* the following results in "Alfe takes a torch from
                         * his second bag."
                         */
                        (container?
                         ({ M_THE,M_ARG,E_AGENT,
                            M_VERB,"take",M_ARG,E_AGENT,
                            M_OBJECT,M_DESCRIBE_UNOWNED,M_ARG,E_TARGET,
                            M_ADVERBS," from " }) +
                         (present(container,this_player()) ? 
                          ({ M_POSSESSIVE,M_ARG,E_AGENT,
                             M_NONE,container,"." }) :
                          ({ M_THE,container,"." })) :
                         ({ M_THE,M_ARG,E_AGENT,
                            M_VERB,"take",M_ARG,E_AGENT,
                            M_OBJECT,M_THE,M_ARG,E_TARGET,M_ADVERBS,"." }))
#else
                        /* the following results in "Alfe takes his second
                         * bag's torch." (and still uses PL which is not
                         * supposed to be used in messages given to events.)
                         */
                        ({ M_THE,M_PL_THE,M_PL_VERB,"take",M_OBJECT,
                           M_THE,M_ARG,E_TARGET,"." })
#endif
                       ]); 0 ]),
               ({ environment(this_player()) }));
    return 1;
  case "empty":  // Coogan, 09-Jul-2003
    if (sizeof(args[G_ALL]) > MAX_NUMBER_OF_OBJECTS)
      write("Only "+MAX_NUMBER_OF_OBJECTS+" objects selected to avoid bugs!\n");
    return
      send_drop_event(args[G_ALL], args[G_CONTAINER,1], sizeof(args[G_ALL]),
                      0, "empty");
  case "drop_all":
    if (sizeof(args[G_ALL]) > MAX_NUMBER_OF_OBJECTS &&
        args[G_ALL,1][1] > MAX_NUMBER_OF_OBJECTS) {
      // crude, i know ...  Alfe 96-Dec-2
      write("Only "+MAX_NUMBER_OF_OBJECTS+
            " objects selected to avoid bugs!\n");
      args[G_ALL,1][1] = MAX_NUMBER_OF_OBJECTS;
    }
    // Ugh Apr-9-98
    return
      send_drop_event(args[G_ALL],args[G_ALL,1][0],args[G_ALL,1][1],0,"drop");
  case "put_all_on":
    if (sizeof(args[G_ALL]) > MAX_NUMBER_OF_OBJECTS &&
        args[G_ALL,1][1] > MAX_NUMBER_OF_OBJECTS) {
      // crude, i know ...  Alfe 96-Dec-2
      write("Only "+MAX_NUMBER_OF_OBJECTS+
            " objects selected to avoid bugs!\n");
      args[G_ALL,1][1] = MAX_NUMBER_OF_OBJECTS;
    }
    if (!args[G_CONTAINER]->query_property(P_SURFACE,args[G_CONTAINER,1])) {
      write("This isn't a good surface to put anything on.\n");
      return 1;
    }
    on = 1;
    // fall through
  case "put_all_into":
    if (sizeof(args[G_ALL]) > MAX_NUMBER_OF_OBJECTS &&
        args[G_ALL,1][1] > MAX_NUMBER_OF_OBJECTS) {
      // crude, i know ...  Alfe 96-Dec-2
      write("Only "+MAX_NUMBER_OF_OBJECTS+
            " objects selected to avoid bugs!\n");
      args[G_ALL,1][1] = MAX_NUMBER_OF_OBJECTS;
    }
    send_event("put",([ E_TYPE: "put"; 0,     // Coogan, 02-May-2007
                        E_RECIPIENT:args[G_CONTAINER]; args[G_CONTAINER,1],
                        E_AGENT:this_player(); 0,
                        E_TARGET:args[G_ALL]; args[G_ALL,1][0],
                        E_ID:args[G_CONTAINER,1]; 0,
                        E_NUMBER:args[G_ALL,1][1]; 0,
                        E_PREPOSITION: (on ? "on" : "in"); 0,
                        E_MESSAGES:
                          msg + ([ 0 : ({ M_THE,M_ARG,E_AGENT,
                                          M_VERB,"put",M_ARG,E_AGENT,
                                          M_THE,M_OBJECT,M_ARG,E_TARGET,
                                          M_ADVERBS,
                                          " ",M_ARG,E_PREPOSITION,"to ",
                                          M_THE,M_ARG,E_RECIPIENT,
                                          "." }) ]); 0 ]),
               ({ environment(this_player()) }));
    return 1;
  case "give_all":
    if (sizeof(args[G_ALL]) > MAX_NUMBER_OF_OBJECTS &&
        args[G_ALL,1][1] > MAX_NUMBER_OF_OBJECTS) {
      // crude, i know ...  Alfe 96-Dec-2
      write("Only "+MAX_NUMBER_OF_OBJECTS+
            " objects selected to avoid bugs!\n");
      args[G_ALL,1][1] = MAX_NUMBER_OF_OBJECTS;
    }
    send_event("give",([ E_TYPE: "give"; 0,     // Coogan, 02-May-2007
                         E_AGENT    : this_player()   ; 0,
                         E_TARGET   : args[G_ALL]     ; args[G_ALL,1][0],
                         E_ID       : args[G_ALL,1][0]; 0,
                         E_NUMBER   : args[G_ALL,1][1]; 0,
                         E_RECIPIENT: args[G_LIVING]  ; args[G_LIVING,1],
                         E_FROM     : container       ; 0,
                         E_MESSAGES :
                           msg + ([ 0 : (({ M_THE,M_ARG,E_AGENT,
                                            M_VERB,"give",M_ARG,E_AGENT,
                                            M_OBJECT,M_THE,M_ARG,E_TARGET,
                                            M_ADVERBS," to ",
                                            M_OBJECT,M_THE,M_ARG,E_RECIPIENT,
                                            "." })) ]); 0 ]),
               ({ environment(this_player()) }));
    return 1;
  case "offer_all":
    if (sizeof(args[G_ALL]) > MAX_NUMBER_OF_OBJECTS &&
        args[G_ALL,1][1] > MAX_NUMBER_OF_OBJECTS) {
      // crude, i know ...  Alfe 96-Dec-2
      write("Only "+MAX_NUMBER_OF_OBJECTS+
            " objects selected to avoid bugs!\n");
      args[G_ALL,1][1] = MAX_NUMBER_OF_OBJECTS;
    }
    send_event("offer",([ E_TYPE: "offer"; 0,     // Coogan, 02-May-2007
                          E_AGENT:this_player(); 0,
                          E_TARGET:args[G_ALL]; args[G_ALL,1][0],
                          E_ID:args[G_ALL,1][0]; 0,
                          E_NUMBER:args[G_ALL,1][1]; 0,
                          E_RECIPIENT:args[G_LIVING]; 0,
                          E_MESSAGES:
                            msg + ([ 0 : (({ M_THE,M_ARG,E_AGENT,
                                             M_VERB,"offer",M_ARG,E_AGENT,
                                             M_OBJECT,M_THE,M_ARG,E_TARGET,
                                             M_ADVERBS }) +
                                          (args[G_LIVING]?
                                           ({ " to ",
                                              M_OBJECT,M_THE,M_ARG,E_RECIPIENT,
                                              "." }) :
                                           ({ "." }))) ]); 0 ]),
               ({ environment(this_player()) }));
    return 1;
  case "stop_offering":
    h = m_indices(this_player()->query_offered());
    if (!sizeof(h))
      return notify_fail("But you aren't offering anything.\n"), 0;
    send_message(({ M_PL_THE,M_PL_VERB,"stop"," offering ",M_OBJECT,M_THE,h,
                    "." }));
    this_player()->stop_offering();
    return 1;
  case "stop_accepting": // case added by Ugh Mar-31-98
    h = this_player()->query_accepted();
    if (!sizeof(h))
      return notify_fail("But you aren't accepting anything.\n"), 0;
    send_message(({ M_PL_THE,M_PL_VERB,"stop"," accepting ",M_OBJECT,M_THE,h,
                    "." }));
    this_player()->stop_accepting();
    return 1;
  case "toggle_refuse":
    h = this_player()->query_property(P_AUTO_REFUSE);
    if (h) {
      message("Other players may give items to you with 'give' now.\n");
      this_player()->remove_property(P_AUTO_REFUSE);
    }
    else {
      // message changed by Ugh Mar-31-98 in accord with other changes today
      message("Items that other players try to 'give' to you are instead only"
              " offered.\n"
              "You have to 'take' the offered items then.\n");
      this_player()->set_property(P_AUTO_REFUSE);
    }
    return 1;
  case "order_inventory":
    h = explode(args[G_TEXT],",");
    order_objects(h,sizeof(h));
    return 1;
  case "fly":
    if (can_fly(this_player()))
      if ((h=environment(this_player()))->query_property(P_OUTSIDE))
        if (h=SE_AIR->get_air_room(environment(this_player())))
          this_player()->move_living("fly",h,
                                     ({ M_THE,M_ARG,E_AGENT,
                                        M_VERB,"fly",M_ARG,E_AGENT,
                                        " up into the sky." }));
        else  // no air room given
          return notify_fail("Though you normally can fly and this is also"
                             " not inside a house, you somehow don't know"
                             " where to fly to.\n"), 0;
      else  // not outside
        return notify_fail("You know how to fly, but you cannot fly inside"
                           " closed areas.  Go outside to fly.\n"), 0;
    else  // can't fly
      return notify_fail("You cannot fly.\n"), 0;
    return 1;
  default:
    return 0;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}
