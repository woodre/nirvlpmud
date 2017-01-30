#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(arg){

    if(!arg){

    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor"+NORM+" (Hilltop)");
    long_desc=
  "The roadway breaks out from the dark forest onto the top of a small hill. At the\n"+
  "base of the hill lies a sprawling cityscape, with many residents scurrying about.\n"+
  "Gaping holes and piles of broken stone mark the outer wall in a variety of places,\n"+
  "although many of the buildings within still stand. Signs of new construction are \n"+
  "everywhere, save for the blackened shell of the central keep.\n\n"+
  "The main entrance of Qual'tor lies to the north of your position.\n";

items=({
   "road","The roadway here is of new construction and in good shape",
   "roadway","The roadway here is of new construction and in good shape",
   "forest","The dark forest extends from the hilltop to the south",
   "hill","You stand upon a small hill with light grass growing upon it. Qual'tor\n"+
          "lies to the north",
   "hilltop","You stand upon a small hill with light grass growing upon it. Qual'tor\n"+
             "lies to the north",
   "cityscape","The vast cityscape of Qual'tor extends to the north. A variety of new\n"+
               "buildings are under construction",
   "resident","The local residents of Qual'tor are busy with a variety of activities",
   "residents","The local residents of Qual'tor are busy with a variety of activities",
   "holes","The holes in the city's outer wall are grim reminders of a recent siege",
   "piles","The piles of stone are what remain of the city's outer wall",
   "stone","The piles of stone are what remain of the city's outer wall",
   "wall","Vast gaps in the outer wall are a reminder of the dark times within",
   "building","Construction has begun within the city to restore many destroyed buildings",
   "buildings","Construction has begun within the city to restore many destroyed buildings",
   "shell","The shell of the former keep within the city is a ruined reminder of\n"+
           "Qual'tors former glory",
   "keep","The shell of the former keep within the city is a ruined reminder of\n"+
          "Qual'tors former glory",
   "entrance","The main entrance to Qual'tor lies to the north",
   "qual'tor","The city of Qual'tor lies north of here",
   "construction","A variety of construction projects are underway within Qual'tor",
 });


dest_dir=({
 "/players/daranath/qualtor/wayin2.c","north",
 "/room/deep_forest1.c","leave",
           });
        }
        }

init(){
  ::init();
add_action("search","search");
add_action("listen","listen");
}

search(){
  write("A variety of tracks run along the roadway, as well as either side of it.\n");
  say(tp +" searches the area.\n");
    return 1;
}

listen(){
  write("Nothing seems out of the ordinary.\n");
  say(tp +" seems to concentrate for a minute.\n");
    return 1;
}

