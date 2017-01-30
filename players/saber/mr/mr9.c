#define tp this_player()->query_name()

inherit "room/room";
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

reset(int arg){

if(!present("minotar"))  {
move_object(clone_object("/players/saber/monsters/mr/minotar.c"),this_object());  }

 if(!arg){

 set_light(1);
 short_desc="In the foothills";

 long_desc="\n"+BOLD+
"      .          .            ..           .        ..        .  .\n"+
"   . ...       .....         ... .       . ...     ...   .   .. ... ..\n"+
". .......  ....... ...  .   ..... ...  ..... ..  . ....  .. .  .. ...\n"+
".............. .. . .......... ....... . ... .. ... ... .. ..... ... ."+NORM+"\n\n"+
NORM+
"  You stand in the foothills of a long stretch of mountains, running\n"+
"  in all directions for as far as the eye can see.  Before you yawns\n"+
"  the the opening of a small cavern.  Unusually strong thermals rise\n"+
"  from the ground, strong enough to lift your body up to the clouds.\n\n";


items=({
 "thermals","Warm breezes drift up from the mountains",
 "thermal","Warm breezes drift up from the mountains",
 "breeze","Warm breezes drift up from the mountains below",
 "wind","Warm breezes drift up from the mountains below",
 "mountains","A long stretch of young mountains run in all directions",
 "foothills","You are in the foothills of the mountains",
 "cavern","A cavern opens up before you.\n"+
          "You detect a flicker of light from within",
 "cloud","Hazy clouds swirl above you",
 "clouds","Hazy clouds swirl above you",
 });


dest_dir=({
 "/players/saber/mr/mr8.c","up",
 "/players/saber/mr/mr10.c","in",
           });
  }   }


init(){
 ::init();
  add_action("search","search");
  add_action("up","u");
  add_action("up","up");
        }


up()  {
 say(tp+" spreads "+this_player()->query_possessive()+" body eagle and catches an updraft.\n"+
     "You watch as "+tp+" rises into the sky...\n");
 write("                                   Up  up\n"+
       "                           up  UP \n"+
       "                         UP\n"+
       "                   up  Up\n"+
       "            Up   UP\n"+
       "     Up  up\n"+
       "  up\n\n"+
       "You spread your body eagle and catch an updraft.\n\n");
call_other(this_player(), "move_player", "up#players/saber/mr/mr8.c");
return 1;
 }

search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1;  
        }
