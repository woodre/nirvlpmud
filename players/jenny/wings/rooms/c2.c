inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int inuse, door;
realm() { return "NT"; }
reset(arg) {
if(!present("fan"))  {
if(!random(8)) {
MOCO("/players/jenny/wings/mobs/other/mfan.c"),TO); 
MOCO("/players/jenny/wings/mobs/other/ffan.c"),TO);}}
   if(arg) return;
   set_light(1);
   set_listen(BOLD+"You can hear some activity down on the ice surface."+NORM);
   set_smell(BOLD+"You can smell food in the distance."+NORM);
   set_search(BOLD+"You notice a button next to the elevator."+NORM);
   long_desc=
   "You are standing in a concourse which wraps around the Joe\n"+      
   "Louis Arena ice surface.  Before games, and between periods\n"+
   "it is absolutely packed with fans, but it is relatively empty\n"+
   "now.  Looking around the concourse, you notice an almost\n"+
   "endless amount of concession stands.  There is an elevator\n"+
   "along the wall, and a button next to it.\n";
   
   items = ({
         "concourse","This is a walkway which winds around Joe Louis Arena.  It exits\n"+
         "into the stands.  Many concession stands, as well as souvenir shops\n"+
         "are located within the concourse",
         "ice surface","You can get a more clear view of this from the stands",
         "concession stands","You see many concession stands, which sell pizza, beer, coke, etc.\n"+
         "They do not appear to be open yet",
         "stands","You see many concession stands, which sell pizza, beer, coke, etc\n"+
         "They do not appear to be open yet",
         "button","A plastic red button.  You can push it to get the elevator",
         "elevator","This is an elevator which can take you up to the media area\n"+
         "and suits, or down to the ice surface and locker rooms.  You\n"+
         "can enter the elevator",
         });
   
   dest_dir = ({
         "/players/jenny/wings/rooms/c3","south",
         "/players/jenny/wings/rooms/c1","west",
});
}
short() {
   return BOLD+RED+"Joe Louis Arena concourse"+NORM; }
init() { 
   ::init(); 
   this_player()->set_fight_area();
   add_action("button","push");
   add_action("button","press");
   add_action("elevator","enter");
}
button(arg) {
   if(!arg) { notify_fail("What do you want to push?\n"); }
   if(arg == "button") {
      if(inuse > 1) { write("The elevator is currently in use.  Try again in a few seconds.\n"); return 1;}
      write("You push the button.\n");
      call_out("button2",4);
      inuse = 5;
      call_other("/players/jenny/wings/rooms/i2.c","inuse");
      call_other("/players/jenny/wings/rooms/2h8.c","inuse");
      call_other("/players/jenny/wings/rooms/s1.c","inuse");
      call_other("/players/jenny/wings/rooms/elevator.c","setbusy");
      tell_room("/players/jenny/wings/rooms/elevator.c","The elevator doors close and it starts to move.\n");
      return 1; }}
button2() {
   tell_room("/players/jenny/wings/rooms/elevator.c","The elevator doors open.\n");
   tell_room("/players/jenny/wings/rooms/c2.c","The elevator doors open.\n");
   call_other("/players/jenny/wings/rooms/elevator.c","setfloor2");
call_other("/players/jenny/wings/rooms/i2.c","inuse2");
call_other("/players/jenny/wings/rooms/c2.c","inuse2");
call_other("/players/jenny/wings/rooms/s1.c","inuse2");
call_other("/players/jenny/wings/rooms/2h8.c","inuse2");
   door = 3;
   return 1; }
elevator() {
   if(door < 1) {
      write("The elevator doors are closed.\n");
      return 1;}
   TP->move_player("into the elevator#players/jenny/wings/rooms/elevator.c");
   return 1; }
inuse() {
   inuse = 5;
   return 1; }
door() {
   door = 0;
   return 1;}
inuse2() {
   inuse = 0;
   return 1;}
