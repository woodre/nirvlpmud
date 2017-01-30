/*  FOREST1.C - Part of Skoda forest in Delnoch
    Changes as of 6-1-96:
    Color added, paths changed to fit new directory structure.
*/
#include "/players/traff/closed/ansi.h"
inherit "room/room";

reset(arg){

  if(!arg){
  set_light(1);
  long_desc=(GRN+
"You have wandered into the Skoda forest.  This forest covers\n"+
"hundreds of square miles of the lower part of the Skoda mountains\n"+
"You are surounded by trees that all look pretty much alike.\n"+
"It would be easy to get lost here.\n"+NORM);

items=({
"ground","The ground is covered with pine needles",
"trees","Mostly conifers, they are tall and green",
"mountains","The mountains rise steadily to the north.  You see snow capped peaks",
 });

  dest_dir=({
"/players/traff/delnoch/town/dmain.c","south",
"/players/traff/delnoch/forest/forest1.c","east",
"/players/traff/delnoch/forest/forest1.c","west",
      });
  }   }

short() { return HIG+"Skoda Forest"+NORM;}

init()  {
 ::init();
  add_action("northwest","northwest");
  add_action("search","search");
}

northwest()  {

if(this_player()->query_real_name() != "trafftoo") {
  write("What?\n");
  return 1;
     }
  call_other(this_player(),"move_player","northwest#players/traff/delnoch/forest/forest2.c");
  return 1;
         }

search(str)  {

  if(!str)  {
    write("Search what?\n");
    return 1;  }
   
    write("You search the "+str+" but find nothing of interest.\n");
    return 1;  }
