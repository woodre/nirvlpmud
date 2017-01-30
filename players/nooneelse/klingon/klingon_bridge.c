/*
 klingon_bridge.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "room/room";

string str;
object view_obj;
int calc_xp;

init() {
  ::init();

  add_action("view_screen",   "view");
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
  if (who) view_obj = find_living(who);
if(view_obj->query_invis() > 38) {
  view_obj = 0;
  } else
  if (view_obj->query_level() > 20) {
    tell_room(this_object(), "A shield is blocking our readings captain!\n");
    return 1;
  }
  if (!view_obj) view_obj = present(who, this_player());
  if (!view_obj) view_obj = present(who, this_object());
  if (!view_obj) {
    tell_room(this_object(), "The computer beeps and says:\n"+
              "   The sensors cannot locate "+capitalize(str)+" captain.\n");
    return 1;
  }
  if (!what) {
    tell_room(this_object(), "The computer beeps and says:\n"+
              "   The sensors cannot read '"+what+"' captain.\n");
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
    return 1;
  }
  tell_room(KLINGON_PHASER, "\nAs you enter, you hear the computer say:\n"+
            "    Sensors are now locked onto:\n"+
            "       "+view_obj->short()+
            ".  You may now aim and fire phasers.\n\n");
  tell_room(KLINGON_TORPEDO, "\nAs you enter, you hear the computer say:\n"+
            "    Sensors are now locked onto:\n"+
            "       "+view_obj->short()+
            ".  You may now aim and fire torpedos.\n\n");
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
/*
    if (view_obj->weapon_class())
      write("wc:           "+view_obj->weapon_class()+"\n");
    if (view_obj->armor_class())
      write("ac:           "+view_obj->armor_class()+"\n");
  took this out - mythos <5-2-96>  */
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
/*
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
took this out too - mythos <5-2-96> */
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

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("the Main Bridge");
  long_desc=
    "This is the main bridge of this Klingon scout ship.  The deck,\n"+
    "ceiling and walls are constructed of riveted gray steel.  There\n"+
    "is one doorway leading aft into a corridor.  The helm controls\n"+
    "seem to have been damaged, but you can still use the ship's\n"+
    "sensors to lock on to monsters/players/objects and see certain\n"+
    "things about them on the screen, with:\n"+
    "   view <who> readings     - to get a description of <who>\n"+
    "   view <who> sees         - to get a description of what <who> sees\n"+
    "   view <who> possessions  - to get a description of what <who> has\n";
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
      "players/nooneelse/klingon/klingon_corridor1", "aft",
    });
  return;
}

query_view_obj() { return view_obj; }

realm() { return "NT"; }
