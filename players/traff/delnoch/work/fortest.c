/*  FOREST1.C - Part of Skoda forest in Delnoch
    Changes as of 6-1-96:
    Color added, paths changed to fit new directory structure.
*/
#include "/players/traff/closed/ansi.h"
inherit "room/room";
int m;

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
"/players/traff/delnoch/work/fortest.c","north",
"/players/traff/delnoch/work/fortest.c","south",
      });
  }   }

short() { return HIG+"Skoda Forest"+NORM;}

init()  {
 ::init();
  add_action("north","north");
  add_action("south","south");
  add_action("search","search");
}

north()  {

  call_other(this_player(),"move_player","north#players/traff/delnoch/work/fortest.c");
  if(!(this_player()->is_player())) { return 1; }
m += 1;
if (m < 11) {
move_object(clone_object("/players/traff/delnoch/mon/girl.c"),this_object());
return 1;}
  return 1;
         }

south()  {

  call_other(this_player(),"move_player","south#players/traff/delnoch/work/fortest.c");
  if(!(this_player()->is_player())) { return 1; }
m += 1;
if (m < 11) {
move_object(clone_object("/players/traff/delnoch/mon/girl.c"),this_object());
return 1;}
  return 1;
         }

search(str)  {

  if(!str)  {
    write("Search what?\n");
    return 1;  }
   
    write("You search the "+str+" but find nothing of interest.\n");
    return 1;  }
