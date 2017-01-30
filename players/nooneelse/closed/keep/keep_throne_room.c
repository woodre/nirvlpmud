/*
  keep_throne_room.c - players private keep (castle)
*/

inherit "room/room";
inherit "/players/nooneelse/closed/keep/keep_common";

string *protected_players;

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc="Throne Room";
  items =
    ({
      "spy glass", "It's a small telescope, with magical properties",
      "herald", "He's a slim, young man wearing a herald's tabard",
    });
  dest_dir =
    ({
      PARAPIT, "up",
      REPAIR_ROOM, "east",
      query_keep_room(), "out",
    });
}

long() {
  write(
    "This is the throne room of this keep.  The walls and floors are made of\n"+
    "gray granite.  The ceiling is made of thick, rough cut, oak planks.\n"+
    "You can perform many functions from here.  (The throne has a magic\n"+
    "spy glass with wich to view various things and a herald that can be\n"+
    "sent to make announcements within & without the keep.\n"+
    "An important looking sign is on the wall.\n"+
    describe_damage()+".\n\n"+
    "There are three obvious exits, up, east and out.\n");
}

init() {
  ::init();

  add_action("dump_keep",        "dump");
  add_action("out",              "out");
  add_action("up",               "up", 1);
  add_action("east",             "east", 1);
  add_action("read_sign",        "read");
  add_action("read_sign",        "examine");
  add_action("read_sign",        "look");
  add_action("view",             "view");
  add_action("announce",         "announce");
  add_action("speak",            "speak");
  add_action("open_gates",       "open");
  add_action("close_gates",      "close");
  add_action("command_soldiers", "soldiers");
}

out() {
  if (living(query_keep_room())) {
    write("\nSomething's wrong!  You're not supposed to be in here unless\n"+
          "the keep has been placed!  I'm dumping you in the church.\n\n");
    tell_room("/room/church",
              this_player()->query_name()+" appears as if by magic.\n");
    move_object(this_player(), "/room/church");
    command("look", this_player());
    return 1;
  }
  if (!query_gates()) {
    write("Thud!!  You walk right into the closed gates.\n");
    return 1;
  }
  write("You stroll through the gates out of the keep.\n");
  tell_room(query_keep_room(),
            this_player()->query_name()+
            " strolls through the gates out of the keep.\n");
  move_object(this_player(), query_keep_room());
  tell_room(THRONE_ROOM,
            this_player()->query_name()+
            " strolls through the gates out of the keep.\n");
  command("look", this_player());
  return 1;
}

up() {
  if (living(query_keep_room())) {
    write("\nSomething's wrong!  You're not supposed to be in here unless\n"+
          "the keep has been placed!  I'm dumping you in the church.\n\n");
    tell_room("/room/church",
              this_player()->query_name()+" appears as if by magic.\n");
    move_object(this_player(), "/room/church");
    command("look", this_player());
    return 1;
  }
  write("You climb the granite stairs to the parapits.\n");
  tell_room(PARAPIT,
            this_player()->query_name()+
            " climbs the granite stairs to the parapits.\n");
  move_object(this_player(), PARAPIT);
  tell_room(THRONE_ROOM,
            this_player()->query_name()+
            " climbs the granite stairs to the parapits.\n");
  command("look", this_player());
  return 1;
}

east() {
  if (living(query_keep_room())) {
    write("\nSomething's wrong!  You're not supposed to be in here unless\n"+
          "the keep has been placed!  I'm dumping you in the church.\n\n");
    tell_room("/room/church",
              this_player()->query_name()+" appears as if by magic.\n");
    move_object(this_player(), "/room/church");
    command("look", this_player());
    return 1;
  }
  write("You walk through the archway into the masonry guild's workroom.\n");
  tell_room(REPAIR_ROOM,
            this_player()->query_name()+
            " walks through the archway into the masonry guild's workroom.\n");
  move_object(this_player(), REPAIR_ROOM);
  tell_room(THRONE_ROOM,
            this_player()->query_name()+
            " walks through the archway into the masonry guild's workroom.\n");
  command("look", this_player());
  return 1;
}

read_sign(str) {
  string str2;
  if (!str) return 0;
  str2=0;
  if (query_verb()=="read" && str=="sign") str2="sign";
  if (query_verb()=="examine" && str=="sign") str2="sign";
  if (query_verb()=="look" && str=="at sign") str2="sign";
  if (str2!="sign") return 0;
  write(
"view [<who>/<dir>]                - look outside the keep, or\n"+
"                                    look at <who>, or\n"+
"                                    look <direction>\n"+
"announce <msg>                    - send the herald throughout the keep\n"+
"speak <msg>                       - send the herald outside the keep\n"+
"open/close gates                  - open or close the gates\n"+
"soldiers [defend keep/stand down] - command your soldiers to actively\n"+
"                                    defend the keep or stop actively\n"+
"                                    defending (attack anything in here\n"+
"                                    but you or not)\n"+
"soldiers [no] protect <who>       - tell your soldiers not to attack <who>\n"+
"                                  - tell your soldiers to stop "+
"ignoring <who>\n"+
"                                    & attack them on sight\n"+
"soldiers list                     - list who's under the soldiers's\n"+
"                                    protection\n");
  return 1;
}

view(str) {
  object view_obj, stuff_obj;

  /* describe keep's room */
  if (!str) {
    write("\nIn the spy glass, you see:\n\n"+
          query_keep_room()->long()+"\n");
    stuff_obj = first_inventory(query_keep_room());
    while(stuff_obj) {
      if ((function_exists("short", stuff_obj) && stuff_obj->short()) &&
          !stuff_obj->id("keep")) {
        tell_room(this_object(), capitalize(stuff_obj->short())+"\n");
      }
      stuff_obj = next_inventory(stuff_obj);
    }
    return 1;
  }

  /* see if it's a scan of a direction */
  if (str=="n") str="north";
  if (str=="s") str="south";
  if (str=="e") str="east";
  if (str=="w") str="west";
  if (str=="ne") str="northeast";
  if (str=="se") str="southeast";
  if (str=="sw") str="southwest";
  if (str=="nw") str="northwest";
  if (str=="u") str="up";
  if (str=="d") str="down";
  view_obj=environment(query_keep_obj())->query_destination_object(str);
  if (view_obj) {
    write("\nIn the spy glass, you see:\n\n"+
          view_obj->long()+"\n");
    stuff_obj = first_inventory(environment(view_obj));
    while(stuff_obj) {
      if (function_exists("short", stuff_obj) && stuff_obj->short())
        write(capitalize(stuff_obj->short())+"\n");
      stuff_obj = next_inventory(stuff_obj);
    }
    return 1;
  }

  /* describe target of scan, it's location & it's contents */
  str = lower_case(str);
  view_obj=0;
  view_obj = find_player(str);
  if (view_obj) {
    /* describe the target's room */
    write("\nIn the spy glass, you see that "+capitalize(str)+
          " is located:\n\n"+
          environment(view_obj)->long()+"\n");
    stuff_obj = first_inventory(environment(view_obj));
    while(stuff_obj) {
      if (function_exists("short", stuff_obj) && stuff_obj->short())
        write(capitalize(stuff_obj->short())+"\n");
      stuff_obj = next_inventory(stuff_obj);
    }
    /* describe what the target has */
    write("is carrying:\n");
    stuff_obj = first_inventory(view_obj);
    while(stuff_obj) {
      if (function_exists("short", stuff_obj) && stuff_obj->short())
        write(capitalize(stuff_obj->short())+"\n");
      stuff_obj = next_inventory(stuff_obj);
    }
    return 1;
  }
  write("For some reason, you can't view "+str+".\n");
  return 1;
}

announce(str) {
  if (!str) return 0;
  TELL_KEEP(str);
  return 1;
}

speak(str) {
  if (!str) return 0;
  tell_room(query_keep_room(), str+"\n");
  write("The herald repeats your message\n"+
        str+
        ",\n then departs to deliver it outside the keep.\n");
  return 1;
}

open_gates(str) {
  if (!str || (str!="gate" && str!="gates")) return 0;
  if (query_gates()) {
    write("But, the gates are already open.\n");
    return 1;
  }
  set_gates(1);
  tell_room(query_keep_obj(),
            "The guards remove the bar and open the gates.\n");
  tell_room(this_object(), "The guards remove the bar and open the gates.\n");
  return 1;
}

close_gates(str) {
  if (!str || (str!="gate" && str!="gates")) return 0;
  if (!query_gates()) {
    write("But, the gates are already closed.\n");
    return 1;
  }
  set_gates(0);
  tell_room(query_keep_obj(), "The guards close and bar the gates.\n");
  tell_room(this_object(), "The guards close and bar the gates.\n");
  return 1;
}

command_soldiers(str) {
  int i, found_one;
  string player_name;

  if (!str) return 0;

  if (str=="defend keep") {
    if (query_soldiers_defending()) {
      write("But, they already are.\n");
      return 1;
    }
    else {
      write("Your soldiers are now actively defending the keep.\n");
      set_soldiers_defending(1);
      return 1;
    }
  }

  if (str=="stand down") {
    if (query_soldiers_defending()) {
      write("Your soldiers are no longer actively defending the keep.\n");
      set_soldiers_defending(0);
      return 1;
    }
    else {
      write("But, they are already in stand down mode.\n");
      return 1;
    }
  }

  if (sscanf(str, "protect %s", player_name)==1) {
    found_one=0;
    for (i=0; i<10; i++) { if (protected_players[i]==player_name) found_one=1; }
    if (found_one)
      write(capitalize(str)+
            " is already under the protection of the soldiers.\n");
    else {
      write(capitalize(str)+" is now under the protection of the soldiers.\n");
      protected_players[i]=player_name;
    }
    return 1;
  }

  if (sscanf(str, "no protect %s", player_name)==1) {
    found_one=0;
    for (i=0; i<10; i++) { if (protected_players[i]==player_name) found_one=1; }
    if (found_one) {
      write(capitalize(str)+
            " is no longer under the protection of the soldiers.\n");
      protected_players[i]=" ";
    }
    else
      write(capitalize(str)+" is not under the protection of the soldiers.\n");
    return 1;
  }

  if (str=="list") {
    found_one=0;
    for (i=0; i<10; i++) {
      if (!found_one && protected_players[i]!=" ")
        write("The players under the protection of the soldiers are:\n");
      if (protected_players[i]!=" ") {
        found_one=1;
        write(capitalize(protected_players[i])+"\n");
      }
    }
    if (!found_one) write("There are no players protected by the soldiers.\n");
    return 1;
  }
}

query_protected(player_name) {
  int found_one, i;
  player_name=lower_case(player_name);
  found_one=0;
  for (i=0; i<10; i++) { if (protected_players[i]==player_name) found_one=1; }
  if (found_one) return 1;
  return 0;
}
