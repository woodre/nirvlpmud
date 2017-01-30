#include <ansi.h>
#define NAME "Lew"
int started;
#define DEST "room/station"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return str == "train" || str == "silver train"; }

short() {

return "A small two car, silver colored train";
}

long() {
  write("This silver colored train car has many hard fiberglass seats\n"+
        "that are not at all comfortable. The train car has many posters\n"+
        "on the inside as well as system maps. It appears to belong to\n"+
        "something called the CTA. And the system maps don't match \n"+
        "anything you know.");
write("\n");
     write(HIR+"Careful in this area, it is a very old one and entering can have variable results.\n");
     write(NORM);
     write(" Type 'enter train' and 'leave train to\n"+
           "enter and leave the train.\n");
}

init() {
    object ob1,test,quarter,processor;
    test=find_object("room/quest_room");
/*
     quarter=clone_object("/players/lew/closed/quarter");
*/
      if(!present("keivjam", test)) {
       ob1=clone_object("obj/quest_obj");
       call_other(ob1,"set_name","keivjam");
	call_other(ob1,"set_hint",
  "To end Keivjam's lag, start your search by taking the\n"+
  "train to 35th street.\n");
       move_object(ob1,test);
     }
    add_action("enter", "enter");
     add_action("leave","leave");

/*
     move_object(quarter,"/players/lew/closed/autold");
*/
}

enter(str) {
    if (!id(str))
	return 0;
   write("You step into the el train.\n");
this_player()->move_player("Boards the el#players/lew/castle.c");
    if (!started) 
    call_out("move_el", 16);
    started =1;
    return 1;
}

reset(arg) {
object test,ob1;
    object quarter,processor;
    if (arg)
	return;
    test=find_object("room/quest_room");
      if(!present("keivjam", test)) {
       ob1=clone_object("obj/quest_obj");
       call_other(ob1,"set_name","keivjam");
/*
       call_other(ob1,"set_hint","Find Keivjam and end this lag.\n");
*/
 ob1->set_hint("Travel to where Nirvana started and discover how to end the mud's Lag.\n");
       move_object(ob1,test);
     }
/*
    quarter=clone_object("players/lew/closed/quarter");
*/
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
leave(){
   move_object(this_player(), environment(this_object()));
   say(this_player()->query_name() + " leaves the train.\n");
   write("You exit the train.\n");
   environment(this_object())->long();
   return 1;
}
move_el() {
  int move;
  say("The train makes a rumbling sound as it begins to move.\n");
  say("The train moves to the next stop.\n");
  if(file_name(environment(this_object())) == "room/station") {
    move_object(this_object(), "players/lew/el_stop.c");
    tell_room("players/lew/el_stop", "You see sparks and hear a rumbling sound as the el train arrives.\n");
    tell_room("players/lew/castle",  "The train arrives at 35th and state.\n");
    move = 3;
  }
  if(move == 0) {
   if(file_name(environment(this_object())) == "players/lew/el_stop")
  {
    move_object(this_object(), "room/station");
    tell_room("room/station", "You see sparks and hear a rumbling sound as the el train arrives.\n");
    tell_room("players/lew/castle", "The train arrives at the main station.\n");
   }
   }
call_out("move_el", 20);
return;
}
