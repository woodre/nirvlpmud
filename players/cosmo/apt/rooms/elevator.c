/* Elevator room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#define mp2 plyr->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

object plyr;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=RED+"Death Trap"+NORM;
  no_castle_flag = 0;
  long_desc="\n"+
"You step into a very plain, ordinary looking elevator.  Nothing\n"+
"special about it at all.  There is the typical handrail going\n"+
"around three walls, the flourescent lights in the ceiling, the\n"+
"checkered tile floor, the panel of buttons indicating the floor\n"+
"to which you wish to be transported, and a red emergency phone.\n",

  items=
  ({
    "floor","One of the tiles appears to be loose. You may be able to slide it",
    "lights","Don't stare into them, you may hurt your eyes",
    "handrail","It is firmly attached to the walls",
    "panel","There are five buttons on the panel marked\n"+
            "1, 2, 3, 4, 5, 6, and L",
    "phone","It is clearly marked:\n"+
         "USE ONLY IN CASE OF EMERGENCY",
  });

}

init() {
  ::init() ;
  add_action("a_push","push");
  add_action("a_push","press");
  add_action("a_use","use");
  add_action("a_slide","slide");
}

a_push(string floor) {
  if(!floor) { write("Push what?\n"); return 1; }
  if(floor=="1"||floor=="2"||floor=="3"||floor=="4"||floor=="5"||floor=="6") {
    write("You push the button marked "+floor+".\n");
    say(capitalize(tp)+" pushes one of the buttons....\n");
    plyr = this_player();
    call_out("s1",2,floor);
  return 1;
  }
  else if(floor == "L" || floor == "l") {
    write("You hear a buzz as you press the button, but nothing happens.\n"+
      "It appears that the lobby button has been short-circuited.\n");
    say(capitalize(tp)+" pushes the lobby button, but nothing happens.\n");
  }
  else { write("Pushing the "+floor+" has no apparent effect.\n"); return 1; }
}

s1(floor) {
  tell_object(plyr,
    "\nYour knees buckle as the elevator begins\n"+
    "to move very rapidly...\n");
  call_out("s2",2,floor);
return 1; }

s2(floor) {
  tell_object(plyr,
    "\nThe elevator climbs higher and higher, faster and faster...\n");
  call_out("s3",2,floor);
return 1; }

s3(floor) {
  tell_object(plyr,
    "\nThe elevator finally comes to a stop.  The doors slide open\n"+
    "and you step out.\n");
  call_out("s4",2,floor);
return 1; }

s4(floor) {
  switch(floor) {
    case "1":
      tell_object(plyr,"\nYou find yourself in strange room.\n");
      mp2("out#/players/cosmo/apt/rooms/rnewman");
      command("glance", plyr);
    break;
    case "2":
      tell_object(plyr,"\nYou find yourself in a strange room.\n");
      mp2("out#/players/cosmo/apt/rooms/relaine");
      command("glance", plyr);
    break;
    case "3":
      tell_object(plyr,"\nYou find yourself in a strange room.\n");
      mp2("out#/players/cosmo/apt/rooms/rstein");
      command("glance", plyr);
    break;
    case "4":
      tell_object(plyr,"\nYou find yourself in a strange room.\n");
      mp2("out#/players/cosmo/apt/rooms/rbubble");
      command("glance", plyr);
    break;
    case "5":
      tell_object(plyr,"\nYou find yourself in a hallway.\n");
      mp2("out#/players/cosmo/apt/rooms/hallway");
      command("glance", plyr);
    break;
    case "6":
      tell_object(plyr,"\nYou find yourself in a strange room.\n");
      mp2("out#/players/cosmo/apt/rooms/rgeorge");
      command("glance", plyr);
    break;
  }
  return 1;
}

a_use(arg) {
  if(!arg) { write("Use what?\n"); return 1; }
  if(arg !="phone") { write("You can't use that.\n"); return 1; }
  say(capitalize(tp)+" picks up the phone and screams,\n"+
    BLU+"  G E T   M E   O U T   O F   H E R E  !!!"+NORM+"\n");
  write("You pick up the phone and scream,\n"+
    BLU+"  G E T  M E  O U T  O F  H E R E  !!!"+NORM+"\n\n");
  mp("back to the lobby#/players/cosmo/apt/rooms/lobby");
  return 1;
}

a_slide(arg) {
  if(!arg) { write("Slide what?\n"); return 1; }
  if(arg !="tile") { write("You can't slide that.\n"); return 1; }
  say(capitalize(tp)+" pushes one of the floor tiles off to the side.\n");
  write("You slide the loose tile aside to reveal a secret shaft.\n"+
        "Maybe you can crawl down the shaft.\n");
  add_action("a_crawl","crawl");
  return 1;
}

a_crawl(arg) {
   if(!arg) {
      write("Where would you like to crawl?\n"); return 1; }
   if(arg != "down") {
      write("You cannot crawl in that direction.\n"); return 1; }
   if (this_player()->query_level() > 10) 
      write("The shaft is too small for you to go down.\n");
   else {
     plyr = this_player();
     call_out("t1",2);
     return 1;
   }
   return 1;
}

t1() {
  tell_object(plyr,
    "\n\n\tYou start to crawl down the shaft but lose your grip and slip.\n"+
    "\tYou quickly fall down through the hole...\n");
  call_out("t2",2);
return 1; }

t2() {
  tell_object(plyr,
    "\n\n\n\tAhh...\n"+
    "\n\n\n\t\tahh...\n"+
    "\n\n\n\t\t\tahh...\n"+
    "\n\n\n\t\t\t\tahh...\n"+
    "\n\n\n\t<T H U D>\n");
  mp2("down the shaft#/players/cosmo/apt/rooms/NEWBIE/h30.c");
  write_file("/players/cosmo/apt/rooms/NEWBIE/RAT.LOG", plyr->query_name()+
    " entered ELEVATOR at "+ctime(time())+"\n");
  command("glance", plyr);
return 1; }
