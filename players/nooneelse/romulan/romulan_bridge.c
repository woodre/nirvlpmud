/*
 romulan_bridge.c
*/

#include "/players/nooneelse/romulan/romulan_warbird.h"

inherit "room/room";

string str;
object view_obj, warbird_obj;
int calc_xp;

init() {
  ::init();

  add_action("view_screen",   "view");
  add_action("fly",           "fly");
  add_action("screen",        "screen");
  add_action("speak",         "speak");
  add_action("self_destruct", "self");
}

view_screen(str) {
  object stuff_obj;
  string who, what;

  if (!str) {
    tell_room(this_object(), "The computer beeps and says:\n"+
              "   View what captain?\n");
    return 1;
  }
  str = lower_case(str);
  sscanf(str, "%s %s", who, what);
  if (!who || !what) {
    tell_room(this_object(), "The computer beeps and says:\n"+
              "   View what captain?  Incorrect syntax!\n");
    return 1;
  }
  /* this was showing illegal stuff - N 8/16/97 */
  if (what=="readings" || what=="rea") {
    write("The computer beeps and says:\n"+
          "   That function is not available at this time.\n");
    return 1;
  }
  if (who) view_obj = find_living(who);
/* this dumb thing didnt check for invis, fixed by mizan */
if(view_obj->query_invis() > 38 || view_obj->query_level() > 20) {
    view_obj = 0;
 }
  if (!view_obj) view_obj = present(who, this_player());
  if (!view_obj) view_obj = present(who, this_object());
  if (!view_obj) {
    tell_room(this_object(), "The computer beeps and says:\n"+
              "   The sensors cannot locate "+capitalize(str)+" captain.\n");
    view_obj=0;
    return 1;
  }
  if (!what) {
    tell_room(this_object(), "The computer beeps and says:\n"+
              "   The sensors cannot read '"+what+"' captain.\n");
    view_obj=0;
    return 1;
  }
  if (what=="rea") what="readings";
  if (what=="see") what="sees";
  if (what=="pos") what="possessions";
  if (what != "readings" &&
      what != "sees" &&
      what!= "possessions") {
    tell_room(this_object(), "The computer beeps and says:\n"+
              "   I don't know how to scan "+what+" on "+capitalize(who)+":\n");
    view_obj=0;
    return 1;
  }
  if (living(view_obj) || environment(view_obj)->id("dreadnought")) {
    tell_room(ROMULAN_PHASER, "\nAs you enter, you hear the computer say:\n"+
              "    Sensors are now locked onto:\n"+
              "       "+view_obj->short()+
              ".  You may now aim and fire phasers.\n\n");
    tell_room(ROMULAN_TORPEDO, "\nAs you enter, you hear the computer say:\n"+
              "    Sensors are now locked onto:\n"+
              "       "+view_obj->short()+
              ".  You may now aim and fire torpedos.\n\n");
  }
  tell_room(this_object(), "The computer beeps and says:\n"+
            "   "+capitalize(who)+" "+what+":\n");
  if (what=="readings" || what=="rea") {
    write(view_obj->short()+"\n");
    if (present("vampire fangs", view_obj))
      write("guild:        vampire\n");
    if (present("seal", view_obj))
      write("guild:        mason\n");
    if (present("license", view_obj))
      write("guild:        assassin\n");
    if (present("robes", view_obj))
      write("guild:        cleric\n");
    if (present("books", view_obj))
      write("guild:        necromancer\n");
    if (view_obj->query_value())
      write("value:        "+view_obj->query_value()+"\n");
    if (view_obj->query_weight())
      write("weight:       "+view_obj->query_weight()+"\n");
    if (view_obj->query_info())
      write("info:         "+view_obj->query_info()+"\n");
    if (view_obj->weapon_class())
      write("wc:           "+view_obj->weapon_class()+"\n");
    if (view_obj->armor_class())
      write("ac:           "+view_obj->armor_class()+"\n");
    if (view_obj->query_type())
      write("armor type:  "+view_obj->query_type()+"\n");
    if (view_obj->query_money())
      write("money:        "+view_obj->query_money()+"\n");
    if (view_obj->query_level())
      write("level:        "+view_obj->query_level()+"\n");
    if (view_obj->query_hp())
      write("hp:           "+view_obj->query_hp()+"\n");
    if (view_obj->query_sp())
      write("sp:           "+view_obj->query_sp()+"\n");
    if (view_obj->query_wc())
      write("weapon class: "+view_obj->query_wc()+"\n");
    if (view_obj->query_ac())
      write("armor class: "+view_obj->query_ac()+"\n");
    if (view_obj->query_alignment())
      write("alignmnet:    "+view_obj->query_alignment()+"\n");
    if (view_obj->query_exp()) {
      calc_xp=view_obj->query_exp() / 35;
      write("experience:   "+view_obj->query_exp()+" -> "+calc_xp+"\n");
    }
  }
  if (what=="possessions") {
    stuff_obj = first_inventory(view_obj);
    while(stuff_obj) {
      if (stuff_obj->short() && stuff_obj != this_object())
        write(capitalize(stuff_obj->short())+"\n");
      stuff_obj = next_inventory(stuff_obj);
    }
  }
  if (what=="sees") {
    write(environment(view_obj)->long()+"\n");
    stuff_obj = first_inventory(environment(view_obj));
    while(stuff_obj) {
      if (stuff_obj->short() && stuff_obj != view_obj)
        write(capitalize(stuff_obj->short())+"\n");
      stuff_obj = next_inventory(stuff_obj);
    }
  }
  return 1;
}

fly(str) {
  if (present("first officer")) {
    tell_room(this_object(),
        "The Romulan covers the computer voice lead, preventing\n"+
        this_player()->query_name()+" from flying the Warbird.\n");
    return 1;
  }
  if (!str) {
    if (present("romulan captain key", this_player()))
      tell_room(this_object(), "The computer beeps and says:\n"+
                "   Fly in which direction First Officer?\n");
    else
      tell_room(this_object(), "The computer beeps and blares:\n"+
                "   Alert!  Alert!  Unauthorized attempt to pilot the ship!"+
                "  Alert!\n");
    return 1;
  }
  if (!warbird_obj) {
    warbird_obj=
      clone_object("/players/nooneelse/romulan/romulan_warbird");
    call_other("/room/mine/tunnel_room", "???", 0);
    move_object(warbird_obj, "/room/mine/tunnel_room");
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
  warbird_obj->move_ship(str);
  return 1;
}

screen() {
  object bridge, stuff_obj;
  if (!warbird_obj) {
    warbird_obj=
      clone_object("/players/nooneelse/romulan/romulan_warbird");
    call_other("/room/mine/tunnel_room", "???", 0);
    move_object(warbird_obj, "/room/mine/tunnel_room");
  }
  bridge=find_object(ROMULAN_BRIDGE);
  write("\nOn the screen you see:\n\n");
  tell_room(bridge, environment(warbird_obj)->long()+"\n");
  stuff_obj = first_inventory(environment(warbird_obj));
  while(stuff_obj) {
    if (stuff_obj && stuff_obj->short() &&
        !stuff_obj->id("romulan warbird")) {
      tell_room(bridge, capitalize(stuff_obj->short())+"\n");
    }
    stuff_obj = next_inventory(stuff_obj);
  }
  return 1;
}

speak(str) {
  if (!str) return;
  if (!warbird_obj) {
    warbird_obj=
      clone_object("/players/nooneelse/romulan/romulan_warbird");
    call_other("/room/mine/tunnel_room", "???", 0);
    move_object(warbird_obj, "/room/mine/tunnel_room");
  }
  tell_room(environment(warbird_obj), "A voice from the romulan warbird goes: " + str + "\n");
  write("       blares through the external speakers.\n");
  return 1;
}

self_destruct(str) {
  if (!str || str != "destruct") return;
  if (!warbird_obj) {
    write("The moving Warbird has already been destroyed.\n");
    return 1;
  }
  warbird_obj->self_destruct();
  write("\nDestructing the moving Warbird!\n");
  destruct(warbird_obj);
  return 1;
}

reset(arg) {
  object obj;
  if (arg) return;

  set_light(1);
  short_desc=("the Main Bridge");
  long_desc=
    "This is the main bridge of this Romulan Warbird.  The deck,\n"+
    "ceiling and walls are constructed of riveted gray steel.  There\n"+
    "is one doorway leading aft into a corridor.  The helm controls\n"+
    "seem to have been damaged, but you can still use the Warbird's\n"+
    "sensors to lock on to monsters/players/objects and see certain\n"+
    "things about them on the screen, with:\n"+
    "   view <who> readings     - to get a description of <who>\n"+
    "   view <who> sees         - to get a description of what <who> sees\n"+
    "   view <who> possessions  - to get a description of what <who> has\n"+
    "\n"+
    "You can also:\n"+
    "  fly <direction>   - fly the Warbird in a direction\n"+
    "  screen            - use the view screen to see outside the Warbird\n"+
    "  speak <message>   - use the external speakers on the Warbird\n"+
    "  self destruct     - destroy the Warbird that moves around the mud\n";
  no_castle_flag=1;
  items=
    ({
      "rivet", "A dull gray steel rivet",
      "rivets", "Dull gray steel rivets",
      "screen", "A white synthi-glass sheet that the computer projects"+
                " information on",
      "doorway", "An opening in the steel plates of the wall",
    });
  dest_dir=
    ({
      "players/nooneelse/romulan/romulan_corridor1", "aft",
      "players/nooneelse/romulan/romulan_phaser", "up",
      "players/nooneelse/romulan/romulan_torpedo", "down",
    });
  obj = clone_object ("obj/monster");
  obj->set_name("Romulan First Officer");
  obj->set_alias("first officer");
  obj->set_alt_name("romulan");
  obj->set_level(16);
/*
  obj->set_ep(800000);
      level 16 wc 20 ac 16 for 800k xp?
    I DONT THINK SO.  - mythos <8-14-97>
*/
  obj->set_hp(750);
  obj->set_al(-500);
  obj->set_race("romulan");
  obj->set_short("Romulan First Officer");
  obj->set_long("Romulan First Officer.\n");
  obj->set_ac(16);
  obj->set_wc(20);
  obj->set_aggressive(1);
  move_object(clone_object("/players/nooneelse/romulan/romulan_blaster"), obj);
  move_object(clone_object("/players/nooneelse/romulan/romulan_torpedo_key"),
              obj);
  move_object(clone_object("/players/nooneelse/romulan/romulan_security_key"),
              obj);
  move_object(obj, this_object());
}

query_view_obj() { return view_obj; }

realm() { return "NT"; }
