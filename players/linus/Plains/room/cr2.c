#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
int is_it_open;
reset(arg) {
 if(!arg);
 set_light(0);
 set_short("In the "+HIK+"Crypt"+NORM); 
 set_long("\
  The stench of death and decay permeates the narrow confines of the\n\
crypt.  The crypt was constructed by digging tunnels and chambers in\n\
the hill,  and standing logs along the earthen walls as pillars.  Some\n\
bones and articles of clothing lay strewn about the floor.  The tunnel\n\
continues to the northeast, and a black door stands in the wall to the\n\
south.\n");
 add_item("crypt","Tunnels and chambers dug into a hill");
 add_item("tunnel","\Tunnels carved into the hill.  Log pillars stand along the\n\
earthen walls for support");
 add_item("walls","Packed dirt with logs standing as pillars for support");
 add_item("earthen walls","Packed dirt with logs standing as pillars for support");
 add_item("wall","Packed dirt with logs standing as pillars for support");
 add_item("earthen wall","Packed dirt with logs standing as pillars for support");
 add_item("logs","Wooden logs that stand along earthen walls for support");
 add_item("log","A wooden log that stands along earthen walls for support");
 add_item("pillars","Wooden logs that stand along earthen walls for support");
 add_item("pillar","A wooden log that stands along earthen walls for support");
 add_item("bones","The bones are old and covered in dirt");
 add_item("dirt","The dirt is brown in color, and moist from condensation");
 add_item("clothing","Tattered remains of clothing from corpses buried in the crypt");
 add_item("door","A black door that could be 'open'ed to 'leave' the 'crypt'");
 add_item("articles","Tattered remains of clothing from corpses buried in the crypt");
 add_item("floor","Hard packed dirt with a few bones and articles of clothing scattered about");
 add_exit(PLAIN+"cr3.c","northeast");
 }
init() {
 ::init();
 add_action("Open","open");
 add_action("Leave","leave");
 add_action("Close","close");
 is_it_open = 1;
}
Open(str) {
 if(!str || str !="door") { FAIL("Open what?\n"); return 0; }
 if(is_it_open == 0) {
 write("You open the door.\n");
 say(TPN+" opens the door.\n");
 is_it_open = 1;
 return 1;
   }
  else { write("The door is already open.\n"); return 1;}
}
Leave(str) {
if(!str || str!="crypt") { FAIL("What are you trying to leave?\n"); return 0; }
if(is_it_open == 0) {
 write("The door is not open!\n");
 return 1;
} 
if(is_it_open == 1) {
 write("You step out of the crypt.\n");
 TP->move_player("out of the crypt#"+PLAIN+"cr1.c");
  return 1;
 }
}
Close(str) {
 if(!str || str != "door") { FAIL("Close what?\n"); return 0; }
 if(is_it_open == 0) {
  write("The door is already closed!\n");
 return 1;
}
 else {
 write("You close the door.\n");
 say(TPN+" closes the door.\n");
 is_it_open = 0;
 return 1;
 }
}
string query_smell(string arg) {
   if (!arg || arg == "main" || arg == "crypt") {
   return "The stench of the crypt makes you sick to your stomach.\n";
  }
  else {
   return "The stench of the crypt overpowers the smell of "+arg+" and makes you sick to your stomach.\n";
  }
}

