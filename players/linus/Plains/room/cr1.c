#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
int is_it_open;
reset(arg) {
 if(!arg);
 set_light(1);
 set_short("Cemetary of "+HIY+"Celestia"+NORM);
 set_long("\
  The roadway stops here at a hill standing to the north.  A crypt\n\
has been carved into the hill, where a black door permits entry.  A\n\
skull is mounted to the door, its mouth forming a twisted smile.  To\n\
the east and west, grave markers lay in states of ruin.  The roadway\n\
travels deeper into the cemetary to the south.\n");
 add_item("grave markers","Stones used to identify the location of graves in the cemetary");
 add_item("markers","Stones used to identify the location of graves in the cemetary");
 add_item("marker","A stone used to identify the location of a grave in the cemetary");
 add_item("stones","Stones used to identify the location of graves in the cemetary");
 add_item("stone","A stone used to identify the location of a grave in the cemetary");
 add_item("grass","Tall green and brown grass");
 add_item("weeds","All sorts of green and brown weeds");
 add_item("roadway","\A path used to get around the cemetary.\n\
It is heavily overgrown with grass and weeds");
 add_item("road","\A path used to get around the cemetary.\n\
It is heavily overgrown with grass and weeds");
 add_item("door","A black door that could be 'open'ed to 'enter' the 'crypt'");
 add_item("skull","A bleached white skull, its mouth forms a twisted smile");
 add_item("mouth","The mouth of the skull forms a twisted smile");
 add_exit(PLAIN+"c2","south");
 add_object("/players/linus/Plains/NPC/hound.c");
}
init() {
 ::init();
 add_action("Open","open");
 add_action("Enter","enter");
 add_action("Close","close");
 is_it_open = 0;
}
Open(str) {
 if(!str || str !="door") { FAIL("Open what?\n"); return 0; }
 if(str =="door") {
 if(is_it_open == 0) {
write("\You carefully open the door.\n\
A cold gust of wind blows from within the crypt.\n");
say(TPN+" carefully opens the door.\n"+
"A cold gust of wind blows from within the crypt.\n");
 is_it_open = 1;
 return 1;
   }
  else { write("The door is already open.\n"); return 1;}
 }
}
Close(str) {
 if(!str || str != "door") { FAIL("Close what?\n"); return 0; }
 if(is_it_open == 1) {
 write("You close the door.\n");
 say(TPN+" closes the crypt door.\n");
 is_it_open = 0;
 return 1;
 }
 else {
 write("The door is already closed!\n");
  return 1;
 }
}
Enter(str) {
if(!str || str!="crypt") { FAIL("What are you trying to enter?\n"); return 0; }
if(str == "crypt" && is_it_open == 0 ){
 write("The door is not open!\n");
 return 1;
} 
if(str == "crypt" && is_it_open == 1){ 
 write("You cautiously enter the crypt.\n");
 TP->move_player("into the crypt#"+PLAIN+"cr2.c");
  return 1;
 }
}



