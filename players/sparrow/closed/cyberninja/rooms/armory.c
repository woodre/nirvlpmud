#include "../DEFS.h"
inherit "/players/dune/closed/guild/rooms/room";


init() {
    add_action("order", "buy");
    add_action("register","register");
    ::init();
}

reset(arg) {
  if (!present(ARMOR_NPC)) {
    move_object(clone_object(ROOMDIR+"/ArmoreR.c"),
      this_object()); 
  }
  if (!arg) {
  set_light(1);
  short_desc=FUNKYNAME+" Armory";
  long_desc=
"     The "+FUNKYNAME+" armory sells very special armor to "+FUNKYNAME+"s.\n"+
"The armor here is not like normal armor.  It is designed especially\n"+
"with the ninja in mind.  Type 'register' to see what you can do here\n";

  items=({
         });

  dest_dir=({
    ROOMDIR + "/shop.c", "east",
      });
  }
}

status findCost() {
  int cost;
  cost = ((int)IPTP->query_art_level());
  if(cost >= 8) cost = 8;
  cost = cost * 1000;
  if(cost <= 4000) cost = 4000;
  return cost;
}

status register() {
  tell_object(TP,
"Services available:\n\n"+
"buy <design>......buy some ninja armor with the color/design\n"+
"                  you specified.  The armor comes in a folded\n"+
"                  package.\n"+
"                  For you, armor would cost "+findCost()+" @'s.\n");
  tell_room(TP, TPN+" registers "+TP->POS+" name.\n");
  return 1;
}

status order(string str) {
  object pack;
  int cost;
  cost = findCost();
  if(IPTP->balance() < cost) {
    write("You do not have enough credits.\n");
    write(FUNKYNAME+" armor for you would cost "+cost+" @'s.\n");
    return 1; 
  }
  pack = clone_object(ARMORDIR+"/fold.c");
  pack->set_color(str);
  if(!str) {
    write("You buy a brand new set of "+FUNKYNAME+" armor.\n");
    say(TPN+" buys a set of brand new "+FUNKYNAME+" armor.\n"); 
  }
  else {
    write("You buy a set of "+str+" "+FUNKYNAME+" armor.\n");
    say(TPN+" buys a set of "+str+" "+FUNKYNAME+" armor.\n"); 
  }
  IPTP->addToBalance(-cost);
  IPTP->set_garbcolor(str);
  IPTP->save_me();
  move_object(pack, TP);
  return 1;
}
