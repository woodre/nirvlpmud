inherit "/players/dune/closed/guild/rooms/room";
#include "../DEFS.h"
 


init() {
 add_action("buy","order");
  add_action("buy","o1");
 add_action("list","mechlist");
 add_action("mechsign","mechsign");
 ::init();
}
 
reset(arg){
 
  if(!present(MECH_NPC)) {
    move_object(clone_object(ROOMDIR + "/MechsmitH.c"),
    this_object());
  }
 
  if(!arg){
  set_light(1);
  short_desc="The MechShop";
  long_desc=
"   Bright flourescent lights and stark white walls make this\n"+
"room seem more like an operating room than a machine shop.\n"+
"This is where the dreaded attack robots of the "+FUNKYNAME+"s\n"+
"are made.   You can 'order <mech>', 'mechlist', or 'mechsign'.\n";
 
  items=({
"lights","The smooth flourescent floods the room with unnatural light",
"walls","Blank walls... nothing on them",
  });
 
  dest_dir=({
    ROOMDIR + "/shop.c", "up",
  });
  }
}
 
buy(string str) {
  int cost, name;
  if(!IPTP) return 0;
  if(!present(MECH_NPC, environment(TP))) {
    write("The mechsmith is not present.\n");
    return 1; }
  if(!str) {
    write("Mechsmith says: What kind of mech would you like to order?\n");
    return 1;
  }
  if(find_living("mech"+TP->query_real_name())) {
    write("You already have a mech.\n"); return 1; }
  if(str != "laser" && str != "shuriken" && str != "rolling" &&
     str != "whirli" && str != "flake") {
  write("That type of mech does not exist\n");
  return 1; }
  if(call_other(MECHD, "buy", TP, str)) {
    write("The mechsmith takes your order and turns to the back wall...\n"+
          "You see him pushing buttons and muttering...\n"+
          "An opening appears in the floor and your mech rises out.\n\n"+
          "Mechsmith says: Ok uh, thanks for your service.\n");
  }
  return 1;
} 
 
status list() {
  if(!IPTP) return 0;
  call_other(MECHD, "list", TP);
  return 1;
}
 
status mechsign() {
  if(!IPTP) return 0;
  write(
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"+
"After you order your mech. Type 'mech help'.\n"+
"If you ever see a mech without a master, you\n"+
"may type 'mechtake' to claim it for your own.\n"+
"Mechtake only works if you do not own a mech.\n"+
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
  return 1;
}
