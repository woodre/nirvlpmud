/*  TOWN.C - An area of Delnoch Town that has grown between Wall 1 and
    Wall 2.  Eventually I plan to add shops or vendors in the areas
    east and west of here.
    Changes as of 5-31-96:
    Color added, paths changed to fit new directory structure.
    search(str) added.
*/
#include "/players/traff/closed/ansi.h"
inherit "room/room";

reset(arg) {

  if(!present("minion"))  {
  move_object(clone_object("/players/traff/delnoch/mon/minion.c"),this_object());  }

  if(!arg){
  set_light(1);
  long_desc=(BLU+
"Over the years the town surronding Delnoch has expanded.  The\n"+
"area you are in now is between walls 1 and 2.  It is filled with\n"+
"a variety of houses, shops, pubs and inns.  It is bustleing with\n"+
"people and livestock.  It is so crowded in fact, that as you are\n"+
"jostled by the crowd, it seems you may only move north or south.\n"+NORM);

  items=({
"ground","The ground is dirt that has been hard packed from much traffic",
"wall 1","The smallest of the walls is to the north",
"wall 2","The second wall is to your south",
"houses","Mostly small crude structures, they are scattered all around",
"shops","All shapes and sizes, selling almost anything you can imagine",
"pubs","Small pubs for thirsty merchants and travellers",
"inns","They ain't the Hilton, but rooms are available",
"people","Shoppers and merchants and farmers.  Men and women, all sizes",
"livestock","Pigs, sheep, cows, and horses being taken to market",
 });

  dest_dir=({
  "/players/traff/delnoch/town/wall1.c","north",
  "/players/traff/delnoch/town/wall6.c","south",
      });
  }   }


init()  {
 ::init();
  add_action("south","south");
  add_action("search","search");
}

short() {return BLU+"Town of Delnoch"+NORM;}

south()  {

  write("You approach wall 2.  At the last moment you decide to continue on\n");
  write("You pass through the gate and continue south.\n");
  write("You keep going, through gates 3,4, and 5, until you reach wall 6.\n");
  write("You climb the long winding stairs to the top of the wall.\n");

  call_other(this_player(),"move_player","south#players/traff/room/wall6.c");
  return 1;
         }

search(str)  {

  if(!str)  {
    write("Search what?\n");
    return 1;  }
   
    write("You search the "+str+" but find nothing of interest.\n");
    return 1;  }
