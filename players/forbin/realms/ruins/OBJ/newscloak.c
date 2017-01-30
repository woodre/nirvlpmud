/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Ruins area (/players/forbin/realms/ruins)
//  Function:     Unique armor
//  Create Date:  2002.07.05
//  Last Edit:    2004.07.05 -Forbin
//  Notes:        Can surround the player with darkness
//                See /players/forbin/realms/ruins/OBJ/dark_shroud.c
//                  for more information
//  Approval:     Fred 2004.07.24
//  Notable Changes:
*/

#include "/players/forbin/realms/ruins/ruinsdefine.h"
#include "/players/forbin/logging.h"
inherit "obj/armor" ;

int Cost;

reset(status arg) {
  if(arg) return;
  ::reset();
  set_name("overcloak of shadow");
  set_alias("cloak");
  set_short((!random(2) ? HIW+"An overcloak of ShADoWs"+NORM : HIW+"An overcloak of SHaDoWS"+NORM));
  set_long(
    "  Looking closely you see this cloak is slightly worn, but otherwise\n"+
    "is made of the finest fabric you have ever seen.  An extremely soft\n"+
    "material, it is dark blue - in fact, almost black, and shimmers\n"+
    "iridescently as you look at it.  Woven into it are many symbols of\n"+
    "magic, just slightly visible in the weave.  If worn, it may offer\n"+
    "some protection from the elements.  You could also 'shroud' yourself\n"+
    "in it, cloaking your body in the darkness of shadows.\n");
  set_type("cloak");
  set_weight(1);
  set_ac(1); /* 1 for special ability */
  Cost = 0;
}

init() {
  ::init();
  add_action("cmd_shroud", "shroud");
}

cmd_shroud() {
  object darkness;
  if(!Cost) Cost = 150 + random(51);
  if(!worn) {
    write("You must be wearing the overcloak.\n");
    return 1;
  }
  if(this_player()->query_sp() < Cost) {
    write("Your body does not have enough energy to shroud yourself in shadows.\n");
      return 1;
  }
  if(present("shroud_of_darkness", this_player())) {
    write("You are already shrouded in shadows.\n");
    return 1;   /* 11-24-07 -Rumplemintz changed from 0 to 1 */
  }
  this_player()->add_spell_point(-Cost);
  write("You pull your "+HIW+"overcloak of shadow"+NORM+" close to your body.\n\n"+
        HIW+"        ^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^\n\n"+
        "                A thick, dark mist slinks into the\n"+ 
        "               room and surrounds you with shadows.\n\n"+
        "        ^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^\n\n"+NORM);
  say(this_player()->query_name()+" pulls "+this_player()->query_possessive()+" "+HIW+"overcloak of shadow"+NORM+" close to "+this_player()->query_possessive()+" body.\n"+
      "A thick, dark mist slinks into the room and surrounds "+this_player()->query_name()+" in shadows.\n");
  darkness = clone_object(OBJ+"dark_shroud");
  move_object(darkness, this_player());
  darkness->darken(this_player());
  Cost = 0;
  return 1;
}

remove(string arg) {
  object ob;
  status x;
  ob = present("shroud_of_darkness", environment(this_object()));
  x = (int)::remove(arg);
  if(ob) ob->lighten();
  return x;
}

drop(int arg){
  this_object()->remove("overcloak");
  ::drop(arg);
}

give(){
  this_object()->remove("overcloak");
  return 1;
}

do_special(object owner) {
  string omsg, rmsg;
  object attack;
  attack = owner->query_attack();
if(!attack) return 0;
 if(!random(7)) {
    if(!random(4)) {
      switch(random(3)) {
        case 0: omsg = "\n\tThe area darkens as "+HIW+"SHaDowS"+NORM+" swell around you.\n\n";
                rmsg = "The area darkens as "+HIW+"SHaDowS"+NORM+" swell around "+owner->query_name()+".\n";
                break;  
        case 1: omsg = "\n\tA dark blotch of "+HIW+"sHAdOWs"+NORM+" attack "+attack->query_name()+".\n\n";
                rmsg = "A dark blotch of "+HIW+"sHAdOWs"+NORM+" attack "+attack->query_name()+".\n";
                break;
        case 2: omsg = HIW+"\n\tShADoWS"+NORM+" expand outward in your defense.\n\n";
                rmsg = HIW+"ShADoWS"+NORM+" expand outward from "+owner->query_name()+" in "+owner->query_possessive()+" defense.\n";
                break;
      }
      tell_object(owner, omsg);
      tell_room(environment(owner), rmsg, ({ owner }));
    }
  return 1;
  }
}
