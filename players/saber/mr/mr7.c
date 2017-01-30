#define tp this_player()->query_name()

inherit "room/room";
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

int gem, number;
object griffon;

reset(int arg){

if(!present("griffon"))  {
  number = random(3) + 2;
  for(gem = 0; gem < number; gem++)  { 
  griffon = clone_object("/players/saber/monsters/mr/rider.c");
  griffon->set_chat_chance(0);
  griffon->set_agressive(1);
  move_object(griffon,this_object()); 
   }
   }
   
if(!arg){

 set_light(1);
 short_desc="Cloud Cavern";

 long_desc=
"You stand within a cavern carved from living cloud.  This appears to be\n"+
"a staging area for the griffon riders, for piles of supplies and weapons\n"+
"are stacked about the chamber. The air is think with moisture, as wisps\n"+
"of cloud shift haphazardly to and from the walls.\n";


items=({
 "cloud","Hazy clouds swirl around you",
 "clouds","Hazy clouds swirl around you",
 "cavern","You stand within a cavern carved from living cloud",
 "chamber","You stand within a cavern carved from living cloud",
 "walls","The air is think with moisture",
 "air","The air is think with moisture",
 "cloud","The air is think with moisture",
 "clouds","The air is think with moisture",
 "supplies","Yuk!  Griffon chow",
 "weapons","On closer inspection, these appear to be griffon flight gear",
 "weapon","On closer inspection, these appear to be griffon flight gear",
 });


dest_dir=({
 "/players/saber/mr/mr6.c","jump",
           });
  }   }


init(){
 ::init();
  add_action("search","search");
  add_action("jump","jump");
        }


jump()  {
 say(tp+" jumps through the clouds.\n"+
     "You watch as "+tp+" falls from sight...\n");
 write("You jump through the clouds and fall\n\n"+
    "    Down\n\n"+
    "           dOwn\n\n"+
    "                  doWn\n\n"+
    "                         dowN\n\n");
 call_other(this_player(), "move_player", "through the clouds#players/saber/mr/mr6.c");
return 1;
}


search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1;  
        }
