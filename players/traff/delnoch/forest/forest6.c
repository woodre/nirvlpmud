/*
  I'm still working on this.  It is a LONG way from done.
  It is not well commented yet, but I'm starting to add
  comments.  While I plan to add quite a bit more to this
  file, what is here now, does work and has been tested.
*/
#include "/players/traff/closed/ansi.h"
#define FR "/players/traff/delnoch/forest/"
inherit "players/traff/delnoch/forest/forest2";

reset(arg){

  if(!arg){
  set_light(1);
  long_desc=(GRN+
"You have wandered into the Skoda forest.  This forest covers\n"+
"hundreds of square miles of the lower part of the Skoda mountains\n"+
"You are surounded by trees that all look pretty much alike.\n"+
"It would be easy to get lost here.\n"+NORM);

items=({
"ground","The ground is cover with pine needles",
"trees","Mostly conifers, they are tall and green",
"mountains","The mountains rise steadily to the north.  You see snow capped peaks",
 });

  dest_dir=({
"/players/traff/delnoch/work/forest1.c","north",
"/players/traff/delnoch/work/forest1.c","south",
"/players/traff/delnoch/work/forest1.c","east",
"/players/traff/delnoch/work/forest1.c","west",
      });
  }   }

short() { return HIG+"Skoda Forest"+NORM;}

init() {
  ::init();
    add_action("search","search");
    add_action("path","path");
}

path() {
  if(!path) {
    write("What?\n");
    return 1; }
  path = 0 ;
  write("You move off, down the path.\n");
  call_other(this_player(),"move_player","down a path#"+FR+"forest4.c");
  return 1; }

search(str)  {

  if(!str)  {
    write("Search what?\n");
    return 1;  }
   
  path = 1;
  write("You search the "+str+" and find a path.\n");
  write("Perhaps the 'path' leads somewhere.\n");
  return 1;  }
