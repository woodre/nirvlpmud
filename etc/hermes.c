/***************************************************************************
  etc/hermes.c, Copyright by Amylaar 

  This is a daemon that helps players that are stuck in a defective room.
  Don't clone this object.

  I modernized Hermes and put it into /etc. Carador, Feb-1996.
  Made it independent from the glandon npc class, Coogan, 06-Jan-1999
**************************************************************************/

#pragma strong_types

#include <prop/living.h>
#include <prop/room.h>
#include <message.h>
#include <wizlevels.h>
#include <grammar.h>

#ifdef TUBMUD
#define HERMES_HOME "domains/glandon/room/town/church_entrance"
#else
#define HERMES_HOME "room/church"
#endif

inherit "basic/living/attack";
inherit "basic/living/chat";
inherit "obj/monster";

object disabler;

string *exits = ({ "north", "northeast", "east", "southeast", "south",
  "southwest", "west", "northwest", "up", "down", "enter", "out",
  "leave", "climb", "crawl" });


status among_target(mixed *target) {
  return (!sizeof(target) || sizeof(target & ({ this_object() })));
}

string my_long() {
  if (disabler)
    return "Hermes, the messenger of the gods, who usually helps players out "
           "of rooms where they are stuck, has been disabled by " +
           disabler->query_vis_name()+". " +
           (this_player()->query_level() >= WL_WIZARD ?
           "Your wizardhood gives you the power to enable him again.\n" : "\n");

  return "Hermes, the messenger of the gods is able to help players which "
         "are stuck in a defective room. Just tell Hermes to get you out "
         "and he will try to help you. " +
         (this_player()->query_level() >= WL_WIZARD ?
         "Your wizardhood gives you the power to disable him.\n" : "\n");
}

void refresh() {
  monster::refresh();

  if (!environment() ||
      load_name(environment()) != HERMES_HOME) {
    move_living("X", HERMES_HOME);
  }
}

mixed help_chat(string text, string type, object pl, mixed target) {
  int i;
  mixed header;
  string *check_ex;
  mixed ex;
  object ob, room_obj;

  if (!among_target(target))
    return;

  if (!environment() || load_name(environment()) != HERMES_HOME)
    move_object(this_object(), HERMES_HOME);

  if (type == "tell")
    header = ({ M_WRITE, M_ME, " tells you: " });
  else
    header = ({ M_SAYS });

  room_obj = environment(pl);
  if (!room_obj)
    return;

  if (disabler) {
    log_file("HERMES", break_string(ctime(time()) + ": Hermes did not help " +
      pl->query_vis_name() + " in " + load_name(room_obj) + 
      " because " + disabler->query_vis_name() + " disabled him.\n", 78,2,1));
    return ({ header + ({ disabler->query_vis_name() +
      " told me not to help you, sorry." }) });
  }

  if (room_obj == environment())
    return ({ header + ({ "Yes, if you once are stuck, just tell me that " +
      "you want me to help you, and I will try to do so." }) });

  catch(move_living("X", room_obj));

  if (environment() != room_obj)
    return ({ header + ({ "Sorry, can't help you." }) });

  send_message(({ M_SAYS, "Let's see..." }));

  if (!room_obj->query_property(P_HERMES) &&  // Coogan, 16-Apr-2002
      (room_obj->query_property(P_NO_HERMES) ||
       room_obj->query_property(P_NO_TELEPORT) ||
       room_obj->query_property(P_NO_TELEPORT_FROM) ||
       room_obj->query_no_teleport())) {
    move_living("X", HERMES_HOME);
    log_file("HERMES", break_string(ctime(time()) + ": Hermes did not help " +
      pl->query_vis_name() + " in " + load_name(room_obj) + 
      " because the room doesn't allow it.\n", 78,2,1));
    return ({
       header + ({ "Sorry, I don't like that room." })
    });
  }

  ex = room_obj->query_dest_dir();
  check_ex = exits;

  if (ex && sizeof(ex) > 1) {
    for (i=1; i<sizeof(ex); i++)
      if (stringp(ex[i]) && member(check_ex, ex[i]) < 0)
        check_ex += ({ ex[i] });
  }

  if (!room_obj->query_property(P_HERMES)) {  // Coogan, 16-Apr-2002
    for (i=sizeof(check_ex); i--;) {
      catch(command(check_ex[i]));
      if (environment() != room_obj ) {
        log_file("HERMES", break_string(ctime(time()) + 
           ": Hermes did not help " + pl->query_vis_name() + " in " + 
           load_name(room_obj) + " because he found a working exit " +
           check_ex[i] + " leading to " + load_name(environment()) + 
           ".\n", 78, 2, 1));
         move_living("X", HERMES_HOME);
         return ({
           2,
           header + ({ "Hey, what do you want? That room seems pretty "
                       "okay." })
           });
      }
    }
  }

  log_file("HERMES", break_string(ctime(time()) + 
      ": Hermes gives " + pl->query_vis_name() + " in " + 
           load_name(room_obj) + " a lift to " + HERMES_HOME +
           ".\n", 78, 2, 1));

  send_message(({ M_SAYS, "That looks really bad. I'll help you." }));

  move_living("X", HERMES_HOME);
  write("You are magically transferred.\n");
  pl->move_living("X", HERMES_HOME);
  if (environment(pl) != environment())
    move_object(pl, environment());

  return ({
    2,
    header + ({ "Always at your service in rooms like this." })
  });
}

void configure() {
  monster::configure();
  set_name("Hermes");
  add_id(({ "messenger", "help" }));
  set_level(19);
  set_wc(35);
  set_ac(70);
  set_short("Hermes the messenger of the gods");
  set_long(#'my_long);
  set_male();
  set_race("human");  // Coogan, 07-Jun-2001
  move_living(0, HERMES_HOME);
  send_message(({
     M_ME_THE, M_ME_VERB, "reappear", " in solid form." 
  }));

  set_attack_prevention(
    ({ ({ M_ME_THE, " laughs at ", M_PL_THE, " in a very hollow voice." }),
       2,
       ({ "HOHO HOHO HOHO..." }),
       2,
       ({ "Nothing further happens." })
    })
  );

  set_property(P_MMSGIN, "arrives in a puff of pink smoke");
  set_property(P_MMSGOUT, "disappears in a pink cloud");

  set_chat_reactions(({
     ({ ({ "help", "get me out" }),
        #'help_chat,
        ({ "say", "tell" })
     })
  }));
}

varargs int hit_player(int dam, object from) {
  if (query_is_hittable(dam, from))
    return monster::hit_player(dam, from);
  else
    return 0;
}

void heart_beat() {
  attack::heart_beat();
  monster::heart_beat();
}

void init() {
  monster::init();

  if (this_player()->query_level() < WL_WIZARD) {
     message(({
        M_PRESENT, 2,
        ({ M_WRITE, "You feel full of awe as you meet Hermes." })
     }));
     return;
  }
  add_action_rule("enable <living>","enable");
  add_action_rule("disable <living>","disable");
  add_action_error_message("disable", "Perhaps 'disable hermes'?\n");
  add_action_error_message("enable", "Perhaps 'enable hermes'?\n");
}

status do_action(string verb, mapping args) {
  if (args[G_LIVING] != this_object() ||
      this_player()->query_level() < WL_APPRENTICE)
    return 0;

  switch(verb) {
  case "disable" :
    if (disabler) {
      write("But Hermes has already been disabled by " + 
            disabler->query_real_name() + ".\n");
      return 1;
    }
    message(({({ M_PL_THE, M_PL_VERB, "disable", " ", M_ME_THE, "." }),
           2, ({ M_WRITE, "Hermes will be enabled again when you log off." })
           }));

    disabler = this_player();
    log_file("HERMES", ctime(time()) +  ": " +
             this_player()->query_vis_name() + " disabled Hermes.\n");
    return 1;
    break;

  case "enable" :
    if (!disabler) {
      write("But Hermes isn't disabled.\n");
      return 1;
    }
    disabler=0;
    log_file("HERMES", ctime(time()) +  ": " +
             this_player()->query_vis_name() + " enabled Hermes.\n");
    send_message(({ M_PL_THE, M_PL_VERB, "enable", " ", M_ME_THE, "." }));
    return 1;
    break;
  }
  return 0;  // Coogan, 26-Mar-2011
}

