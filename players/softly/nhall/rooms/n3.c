#include "/players/softly/closed/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {

  set_light(1);

  short_desc = "Hall of Apprentices [Armory]";
  long_desc =
    "  This is the Armory of the Hall.  A large forge stands in the\n"+
    "center of the room, with a black pipe leading up and out of the\n"+
    "ceiling overhead. Several racks of weapons and armor stand along\n"+
    "the walls. A huge banner of a dragon hangs from the ceiling behind\n"+
    "the forge.  For information on acquiring equipment, simply "+BOLD+"browse"+NORM+"\n"+
    "the armory.\n";
  items = ({
    "walls",
    "Polished white rock which is carefully laid in a silver mortar",
    "stone",
    "A heavy strong stone that is nearly unbreakable",
    "mortar",
    "An enchanted mortar that holds the hall together",
    "floor",
    "A polished marble floor that you can even see your reflection in",
    "weapons",
    "A vast selection of weapons",
    "armor",
    "Several suits of chainmail. Each of differing colors",
    "pipe",
    "A large iron pipe that allows the smoke from the forge to flow out of\n"+
    "the room",
    "ceiling",
    "A high ceiling with a black pipe running through its center",
    "banner",
    "A large banner with a dragon imprinted on it",
    "forge",
    "A large stone forge. It appears to have seen alot of use",
    "racks",
    "Large wooden racks covered in armor and weapons"
  });

  dest_dir = ({

    "/players/softly/nhall/rooms/n1.c","west",
  });
}


init(){
  ::init();
  if(this_player()) /* added by Vertebraker [5.30.01] */
  if(this_player()->query_level() > 7 && this_player()->query_level() < 20){
    write("You don't belong here!\n");
    move_object(this_player(), "/room/vill_green.c");
    tell_room(environment(tp), tpn+" arrives suddenly.\n", ({tp}));
    command("look", this_player());
    return;
  }
  add_action("browse_it","browse");
  add_action("equip_me","grab");
}


browse_it(){
        write(
                "You browse the selection of equipment...\n\n"+
                "____________________"+HIR+"Armor"+NORM+"___________________________\n"+
                " Chainmail                                       \n"+
                " Surcoat                                         \n\n"+
                "___________________"+HIR+"Weapons"+NORM+"__________________________\n"+
                " Sword\n"+
                " Axe\n"+
                " Pike\n"+
                " Mace\n"+
                " Hammer\n\n"+
                "____________________"+HIR+"Misc"+NORM+"____________________________\n"+
                " Farseer Bot\n"+
                " Map\n"+
                " Bag\n\n\n");
write(
          "To obtain any of these items simply: "+BOLD+"grab <item>"+NORM+" or "+BOLD+"grab all"+NORM+" for one\n"+
          "of each armor, a bag, a Farseer Bot, and a sword.\n");
return 1;
}


equip_me(str){
  object chain;
  object surcoat;
  object weapon;
  object bag;
  object tmap;
  object farseerBot;


  /* Added weight checks - Feldegast 5/2/00 */

  if(!str){
    write("Grab what?\n");
    return 1;
  }

  if(str == "all"){
    if(!present("newbie_chain", this_player()) ) {
      if(this_player()->add_weight(2)) {
        chain = clone_object("players/softly/nhall/obj/chain.c");
        move_object(chain, this_player());
        write("You pick up chainmail armor.\n");
      } else write("You are carrying too much already.\n");
    }
    if(!present("farseer", this_player()) ) {
      if(this_player()->add_weight(2)) {
        farseerBot = clone_object("players/mokri/obj/farseerBot.c");
        farseerBot->setIsNewbie(1);
        move_object(farseerBot, this_player());
        write("You pick up a Farseer Bot.\n");
      } else write("You are carrying too much already.\n");
    }
    if(!present("bag", this_player())) {
      if(this_player()->add_weight(1)) {
                                /* Insert by Snow 3/00 */
        bag = clone_object("players/sandman/NEWBIE/newbie_bag.c");
        move_object(bag, this_player());
        write("You pick up a bag.\n");
      } else write("You are carrying too much already.\n");
    }
    if(!present("surcoat", this_player())){
      if(this_player()->add_weight(1)) {
        surcoat = clone_object("players/softly/nhall/obj/scoat.c");
        move_object(surcoat, this_player());
        write("You pick up a surcoat.\n");
      } else write("You are carrying too much already.\n");
    }
    if(!present("newbie_wep", this_player())){
      if(this_player()->add_weight(1)) {
        weapon = clone_object("players/softly/nhall/obj/sword.c");
        move_object(weapon, this_player());
        write("You pick up a sword.\n");
      } else write("You are carrying too much already.\n");
    }
    if(!present("newbie_wep", this_player())){
      if(this_player()->add_weight(1)) {
        weapon = clone_object("players/softly/nhall/obj/sword.c");
        move_object(weapon, this_player());
        write("You pick up a sword.\n");
      } else write("You are carrying too much already.\n");
    }
    if(str == "map" || str == "town map") {
      if(!present("tmap", this_player())) {
        tmap = clone_object("players/softly/newbie/obj/tmap.c");
        move_object(tmap, this_player());
        write("You pick up a map.\n");
      }else write("You already have one!\n");
      return 1;
    }
return 1;
  }

if(str == "chainmail") {
  if(!present("newbie_chain", this_player())){
    if(!this_player()->add_weight(1)) {
      write("That is too heavy for you to carry.\n");
      return 1;
    }
    chain = clone_object("players/softly/nhall/obj/chain.c");
    move_object(chain, this_player());
    write("You pick up a chainmail armor.\n");
    return 1;
  }
  write("You already have one!\n");
  return 1;
}

if(str == "farseer" || str == "bot" || str == "farseer bot") {
  if(!present("farseer", this_player())){
    if(!this_player()->add_weight(2)) {
      write("That is too heavy for you to carry.\n");
      return 1;
    }
    farseerBot = clone_object("players/mokri/obj/farseerBot.c");
    farseerBot->setIsNewbie(1);
    move_object(farseerBot, this_player());
    write("You pick up a Farseer Bot.\n");
    return 1;
  }
  write("You already have one!\n");
  return 1;
}

if(str == "surcoat") {
  if(!present("surcoat", this_player())){
    if(!this_player()->add_weight(1)) {
      write("That is too heavy for you to carry.\n");
      return 1;
    }
    surcoat = clone_object("players/softly/nhall/obj/scoat.c");
    move_object(surcoat, this_player());
    write("You pick up a surcoat.\n");
    return 1;
  }
  write("You already have one!\n");
  return 1;
}

if(str == "bag") {
  if(!present("bag", this_player())){
    if(!this_player()->add_weight(1)) {
      write("That is too heavy for you to carry.\n");
      return 1;
    }
    bag = clone_object("players/sandman/NEWBIE/newbie_bag.c");
    move_object(bag, this_player());
    write("You pick up a bag.\n");
    return 1;
  }
  write("You already have one!\n");
  return 1;
}

if(str == "sword"){
  if(!present("newbie_wep", this_player())){
    if(!this_player()->add_weight(1)) {
      write("That is too heavy for you to carry.\n");
      return 1;
    }
    weapon = clone_object("players/softly/nhall/obj/sword.c");
    move_object(weapon, this_player());
    write("You pick up a sword.\n");
    return 1;
  }
  write("You already have a weapon!\n");
  return 1;
}

if(str == "axe"){
  if(!present("newbie_wep", this_player())){
    if(!this_player()->add_weight(1)) {
      write("That is too heavy for you to carry.\n");
      return 1;
    }
    weapon = clone_object("players/softly/nhall/obj/axe.c");
    move_object(weapon, this_player());
    write("You pick up an axe.\n");
    return 1;
  }
  write("You already have a weapon!\n");
  return 1;
}

if(str == "pike"){
  if(!present("newbie_wep", this_player())){
    if(!this_player()->add_weight(1)) {
      write("That is too heavy for you to carry.\n");
      return 1;
    }
    weapon = clone_object("players/softly/nhall/obj/pike.c");
    move_object(weapon, this_player());
    write("You pick up a pike.\n");
    return 1;
  }
  write("You already have a weapon!\n");
  return 1;
}

if(str == "mace"){
  if(!present("newbie_wep", this_player())){
    if(!this_player()->add_weight(1)) {
      write("That is too heavy for you to carry.\n");
      return 1;
    }
    weapon = clone_object("players/softly/nhall/obj/mace.c");
    move_object(weapon, this_player());
    write("You pick up a mace.\n");
    return 1;
  }
  write("You already have a weapon!\n");
  return 1;
}

if(str == "hammer"){
  if(!present("newbie_wep", this_player())){
    if(!this_player()->add_weight(1)) {
      write("That is too heavy for you to carry.\n");
      return 1;
    }
    weapon = clone_object("players/softly/nhall/obj/hammer.c");
    move_object(weapon, this_player());
    write("You pick up a hammer.\n");
    return 1;
  }
  write("You already have a weapon!\n");
  return 1;
}

 if(str == "map" || str == "town map") {
   if(!present("town map", this_player())) {
     tmap = clone_object("players/softly/newbie/obj/tmap.c");
     move_object(tmap, this_player());
     write("You pick up a map.\n");
     return 1;
   }
   write("You already have one!\n");
   return 1;
 }


write("You don't see that here.\n");
return 1;
}
