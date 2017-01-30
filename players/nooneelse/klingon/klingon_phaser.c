/*
 klingon_phaser.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "room/room";

string str, target_description;
object view_obj;
int phasers_aimed, dreadnought_counter;

init() {
  object tmp_obj;
  ::init();

  add_action("aim_target",   "aim");
  add_action("shoot_target", "fire");
  add_action("shoot_target", "firea");
  tmp_obj=call_other("/players/nooneelse/klingon/klingon_bridge",
                     "query_view_obj", 0);
  if (tmp_obj && present("klingon phaser key", this_player()))
    write("\nAs you enter, you hear the computer say:\n"+
          "    Sensors are currently locked onto:\n"+
          "       "+tmp_obj->short()+"\n\n");
}

aim_target(str) {
  if (!str || str != "phasers") return;
  if (!present("klingon phaser key", this_player())) {
    tell_room(this_object(), "The computer beeps and blares:\n"+
        "   Alert!  Alert!  Attempted unauthorized use of phaser weapons! "+
        "Alert!\n");
    return 1;
  }
  phasers_aimed=0;
  if (view_obj != call_other("players/nooneelse/klingon/klingon_bridge",
                             "query_view_obj", 0)) dreadnought_counter=0;
  view_obj=0;
  view_obj=call_other("players/nooneelse/klingon/klingon_bridge",
                      "query_view_obj", 0);
  if (!view_obj) {
    tell_room(this_object(), "The computer beeps and says:\n"+
        "   Aim at what gunnery officer?  "+
        "The bridge has not scanned a target.\n");
    return 1;
  }
  if (view_obj->query_level() > 19) {
    write("Sorry, you cannot aim at a wizard!\n");
    return 1;
  }
  if (view_obj->query_name())
    target_description = capitalize(view_obj->query_name());
  else
    target_description = capitalize(view_obj->short());
  tell_room(this_object(), "The computer beeps and says:\n"+
      "   Yes gunnery officer!  "+
      "Phasers locked onto "+target_description+".\n");
  phasers_aimed=1;
  return 1;
}

shoot_target(str) {
  int at_enterprise, at_romulan;
  string enterprise_str;
  if (!str) return;
  sscanf(str, "phasers at %s", enterprise_str);
  if (enterprise_str=="enterprise") {
    str="phasers";
    phasers_aimed=1;
    at_enterprise=1;
  }
  if (enterprise_str=="romulan") {
    str="phasers";
    phasers_aimed=1;
    at_romulan=1;
  }
  if (str != "phasers") return;
  if (!present("klingon phaser key", this_player())) {
    tell_room(this_object(), "The computer beeps and blares:\n"+
        "   Alert!  Alert!  Attempted unauthorized use of phaser weapons! "+
        "Alert!\n");
    return 1;
  }
  if (!phasers_aimed) {
    tell_room(this_object(), "The computer beeps and says:\n"+
        "   Impossible gunnery officer!  "+
        "Phasers have not been aimed at a target.\n");
    return 1;
  }
  phasers_aimed=0;
  if (at_enterprise) {
    TELL_SHIP("You hear a high pitched squeal and feel the deck buck as the\n"+
              "phasers are fired.\n");
    shoot_enterprise();
    at_enterprise=0;
    return 1;
  }
  if (at_romulan) {
    TELL_SHIP("You hear a high pitched squeal and feel the deck buck as the\n"+
              "phasers are fired.\n");
    shoot_romulan();
    at_romulan=0;
    return 1;
  }
  dreadnought_counter++;
  tell_room(this_object(), "The computer beeps and says:\n"+
      "   Yes gunnery officer!  "+
      "Firing phasers at "+target_description+".\n");
  tell_room(environment(view_obj),
              "You hear a high-pitched electrical hum and feel the ground\n"+
              "shake as a bright red energy beam lances down to strike "+
              target_description+"!\n");
  if (query_verb()=="firea") tell_mud();
  TELL_SHIP("You hear a high-pitched electrical shriek and feel the deck\n"+
            "jerk as the phasers are fired.\n");
  if (!living(view_obj)) {
    if (environment(view_obj)->id("dreadnought"))
      kill_dreadnought();
    else {
      tell_object(environment(view_obj), target_description+
                  " shimmers in the energy beam and disappears!\n");
      tell_room(this_object(), "The computer beeps and says:\n"+
          "   "+target_description+" destroyed gunnery officer!\n");
/*
      destruct(view_obj);
*/
    }
    return 1;
  }
  tell_object(environment(view_obj), target_description+
              " shimmers in the energy beam and looks heavily damaged!\n");
/*
  view_obj->hit_player(100);
*/
  if (living(view_obj))
    tell_room(this_object(), "The computer beeps and says:\n"+
        "   "+target_description+
        " has been heavily damaged gunnery officer!\n");
  else
    tell_room(this_object(), "The computer beeps and says:\n"+
        "   "+target_description+" has been destroyed gunnery officer!\n");
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("phaser control");
  long_desc=
    "This is the phaser control room of this Klingon scout ship.  The\n"+
    "deck, ceiling and walls are constructed of riveted gray steel.\n"+
    "There is a steel ladder leading down to engineering.  You can\n"+
    "use the ship's phasers to fire upon monsters/players/objects with:\n"+
    "   aim phasers\n"+
    "   fire phasers\n"+
    "   fire phasers at enterprise  (without even aiming :)\n"+
    "   fire phasers at romulan     (without even aiming :)\n";
  no_castle_flag=1;
  items=
    ({
      "rivet", "A dull gray steel rivet",
      "rivets", "Dull gray steel rivets",
      "ladder", "A steel runged ladder leading through the plates "+
                "of the floor",
      "phaser", "The phasers are out of reach beyond a wall of\n"+
                "transparent aluminium.  You can command them\n"+
                "via the two commands that the computer understands\n",
      "phasers", "The phasers are out of reach beyond a wall of\n"+
                 "transparent aluminium.  You can command them\n"+
                 "via the two commands that the computer understands\n",
    });
  dest_dir=
    ({
      "players/nooneelse/klingon/klingon_engineering", "down",
    });
  return;
}

tell_mud() {
  string users_list;
  int i;
  users_list=users();
  for (i=0; i < sizeof(users_list); i++) {
    if (environment(users_list[i]) != environment(view_obj) &&
        lower_case(users_list[i]->query_name()) != "someone" &&
        users_list[i]->in_editor() != 1 &&
        (environment(users_list[i]) &&
         sscanf(file_name(environment(users_list[i])), "klingon%s", str) != 1))
      tell_object(users_list[i],
             "You hear a high-pitched electrical hum and feel the ground\n"+
             "shake as a bright red energy beam lances down from above\n"+
             "to strike in the distance.\n");
  }
}

kill_dreadnought() {
  object tank_obj;
  string msg;
  if (dreadnought_counter < 3) return;
  tell_room(environment(view_obj),
            "The last phaser strike seems to have been too much for the\n"+
            "armor of even this powerful dreadnought to take!  It starts\n"+
            "to glow cherry red, then almost a blue-white.\n");
  tank_obj=first_inventory(view_obj);
  while (tank_obj) {
    if (living(tank_obj)) {
      str=tank_obj->query_name();
      msg=capitalize(str)+" scrambles out an escape hatch to safety!\n";
    }
    else {
      str=tank_obj->short();
      msg=capitalize(str)+" is blown clear of the dreadnought.\n";
    }
    tell_room(environment(view_obj), msg);
    move_object(tank_obj, environment(view_obj));
    tank_obj=next_inventory(tank_obj);
  }
  move_object(clone_object("/players/nooneelse/klingon/dreadnought_wreckage"),
              environment(view_obj));
  destruct(view_obj);
}

shoot_enterprise() {
  object players_list;
  string msg, msg2, str;
  int i;
  i=random(5);
  msg2="auxillary bridge";
  if (i=4) msg2="port Nacelle";
  if (i=3) msg2="starboard Nacelle";
  if (i=2) msg2="engineering deck";
  if (i=1) msg2="port hull";
  if (i=0) msg2="starboard hull";
  msg="\n\nYou hear a high-pitched shriek and feel the deck buck\n"+
      "as a phaser bolt slams into the Enterprise on the\n"+
      msg2+"!\n\n\n";
  tell_room(this_object(), "The computer beeps and says:\n"+
            "   Good shot gunnery officer!  "+
            "You got them in the "+msg2+"!\n");
  players_list=users();
  for (i = 0; i < sizeof(players_list); i++) {
    if (environment(players_list[i])) {
      str=0;
      sscanf(file_name(environment(players_list[i])), "players/rich%s", str);
      if (str) tell_room(environment(players_list[i]), msg);
    }
  }
}

shoot_romulan() {
  object players_list;
  string msg, msg2, str;
  int i;
  i=random(5);
  msg2="auxillary bridge";
  if (i=4) msg2="port Nacelle";
  if (i=3) msg2="starboard Nacelle";
  if (i=2) msg2="engineering deck";
  if (i=1) msg2="port hull";
  if (i=0) msg2="starboard hull";
  msg="\n\nYou hear a high-pitched shriek and feel the deck buck\n"+
      "as a phaser bolt slams into the Romulan Warbird on the\n"+
      msg2+"!\n\n\n";
  tell_room(this_object(), "The computer beeps and says:\n"+
            "   Good shot gunnery officer!  "+
            "You got them in the "+msg2+"!\n");
  players_list=users();
  for (i = 0; i < sizeof(players_list); i++) {
    if (environment(players_list[i])) {
      str=0;
      sscanf(file_name(environment(players_list[i])), "players/rich%s", str);
      if (str) tell_room(environment(players_list[i]), msg);
    }
  }
}

realm() { return "NT"; }
