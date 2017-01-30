
#include "std.h"

object board, assassin;

reset(arg){
    if(!arg){
     if(!present("board")){
     board = clone_object("players/deathmonger/MISC/bull_board");
     move_object(board, this_object());
     }
 /*
    if(!present("assassin")){
      assassin = clone_object("players/deathmonger/MONSTERS/recruiter");
      move_object(assassin, this_object());
    }
   */
  }
   set_light(1);
}


init(){
    add_action("up", "up");
    add_action("north", "north");
    add_action("south", "south");
}

up(){
    this_player()->move_player("up#players/deathmonger/CASTLE/change_room");
    return 1;
}

south(){
   this_player()->move_player("south#players/deathmonger/flameroom");
    return 1;
}


north() { write("What?\n"); return 1; }
_old_north(){
    if(present("license", this_player())){
       this_player()->move_player("north#players/pain/closed/ASSASSIN/cenguild");
      return 1;
      }
    else {
        write("Can't you tell when you're not wanted?\n");
     return 1;
      }
}
short(){ return "Complaint room"; }

long(){
write("The basement of the adventurers' guild is a dark, undermaintained\n"+
      "room with walls covered with graffiti.  In order to prevent you\n"+
      "from scribbling on the walls, a bulletin board is here for your\n"+
      "convenience.\n");
write("It is intended to be used for complaints, bitching, and whining.  Feel\n"+
"free to complain about the mud, quests, wizards, other players, or the\n"+
"Guatamalan gorillas who smuggle explosive papayas into Ohio.\n");
   write("There are three obvious exits: up, and south.\n");
}

