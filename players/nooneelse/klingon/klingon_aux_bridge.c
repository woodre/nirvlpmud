/*
 klingon_aux_bridge.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

object scout_ship_obj;

inherit "room/room";

init() {
  ::init();

  add_action("fly",           "fly");
  add_action("screen",        "screen");
  add_action("speak",         "speak");
  add_action("self_destruct", "self");
}

fly(str) {
  if (present("first officer")) {
    tell_room(this_object(),
        "The Klingon covers the computer voice lead, preventing\n"+
        this_player()->query_name()+" from flying the ship.\n");
    return 1;
  }
  if (!str) {
    if (present("klingon pilot key", this_player()))
      tell_room(this_object(), "The computer beeps and says:\n"+
                "   Fly in which direction First Officer?\n");
    else
      tell_room(this_object(), "The computer beeps and blares:\n"+
                "   Alert!  Alert!  Unauthorized attempt to pilot the ship!"+
                "  Alert!\n");
    return 1;
  }
  if (!scout_ship_obj) {
    scout_ship_obj=
      clone_object("/players/nooneelse/klingon/klingon_scout_ship");
    call_other("/room/mine/tunnel_room", "???", 0);
    move_object(scout_ship_obj, "/room/mine/tunnel_room");
  }
  if (str=="n") str="north";
  if (str=="ne") str="northeast";
  if (str=="e") str="east";
  if (str=="se") str="southeast";
  if (str=="s") str="south";
  if (str=="sw") str="southwest";
  if (str=="w") str="west";
  if (str=="nw") str="northwest";
  if (str=="u") str="up";
  if (str=="d") str="down";
  scout_ship_obj->move_ship(str);
  return 1;
}

screen() {
  object aux_bridge, stuff_obj;
  if (!scout_ship_obj) {
    scout_ship_obj=
      clone_object("/players/nooneelse/klingon/klingon_scout_ship");
    call_other("/room/mine/tunnel_room", "???", 0);
    move_object(scout_ship_obj, "/room/mine/tunnel_room");
  }
  aux_bridge=find_object(KLINGON_AUX_BRIDGE);
  write("\nThe screen flickers and snaps, but displays:\n\n");
  tell_room(aux_bridge, environment(scout_ship_obj)->long()+"\n");
  stuff_obj = first_inventory(environment(scout_ship_obj));
  while(stuff_obj) {
    if (stuff_obj && stuff_obj->short() &&
        !stuff_obj->id("klingon scout ship")) {
      tell_room(aux_bridge, capitalize(stuff_obj->short())+"\n");
    }
    stuff_obj = next_inventory(stuff_obj);
  }
  return 1;
}

speak(str) {
  if (!str) return;
  if (!scout_ship_obj) {
    scout_ship_obj=
      clone_object("/players/nooneelse/klingon/klingon_scout_ship");
    call_other("/room/mine/tunnel_room", "???", 0);
    move_object(scout_ship_obj, "/room/mine/tunnel_room");
  }
  tell_room(environment(scout_ship_obj), "A voice from the scout ship goes: " + str + "\n");
  write("       blares through the external speakers.\n");
  return 1;
}

self_destruct(str) {
  if (!str || str != "destruct") return;
  if (!scout_ship_obj) {
    write("The moving ship has already been destroyed.\n");
    return 1;
  }
  scout_ship_obj->self_destruct();
  write("\nDestructing the moving ship!\n");
  destruct(scout_ship_obj);
  return 1;
}

reset(arg) {
  object obj;
  if (arg) return;

  set_light(1);
  short_desc=("Auxilliary Control");
  long_desc=
    "This is the auxilliary bridge of this Klingon scout ship.  The deck,\n"+
    "ceiling and walls are constructed of riveted gray steel.  It looks\n"+
    "like there has been some kind of fight here that wrecked view screen,\n"+
    "but you can still use the helm controls.  There is one doorway leading\n"+
    "out into the corridor.\n"+
    "\n"+
    "Some of the controls seem to be functioning still.  You can:\n"+
    "  fly <direction>   - fly the ship in a direction\n"+
    "  screen            - use the view screen to see outside the ship\n"+
    "  speak <message>   - use the external speakers on the ship\n"+
    "  self destruct     - destroy the scout ship that moves around the mud\n";
  no_castle_flag=1;
  items=
    ({
      "rivet", "A dull gray steel rivet",
      "rivets", "Dull gray steel rivets",
      "doorway", "An opening in the steel plates of the wall",
      "screen", "A broken & buckled, screen similar to the one in the "+
                "main bridge",
    });
  dest_dir=
    ({
      "players/nooneelse/klingon/klingon_corridor6", "aft",
    });
  obj = clone_object ("obj/monster");
  obj->set_name("Klingon First Officer");
  obj->set_alias("first officer");
  obj->set_alt_name("klingon");
  obj->set_level(16);
/*
  obj->set_ep(800000);
*/
  obj->set_hp(750);
  obj->set_al(-500);
  obj->set_race("klingon");
  obj->set_short("Klingon First Officer");
  obj->set_long("Klingon First Officer.\n");
  obj->set_ac(16);
  obj->set_wc(20);
  obj->set_aggressive(1);
  move_object(clone_object("/players/nooneelse/klingon/klingon_blaster"), obj);
  move_object(clone_object("/players/nooneelse/klingon/klingon_pilot_key"),
              obj);
  move_object(obj, this_object());
  return;
}

realm() { return "NT"; }
