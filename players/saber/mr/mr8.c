#define tp this_player()->query_name()

inherit "room/room";
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

reset(int arg){

 if(!arg){

 set_light(1);
 short_desc="Free Falling";

 long_desc="\n"+BOLD+
"      .          .            ..           .        ..        .  .\n"+
"   . ...       .....         ... .       . ...     ...   .   .. ... ..\n"+
". .......  ....... ...  .   ..... ...  ..... ..  . ....  .. .  .. ...\n"+
".............. .. . .......... ....... . ... .. ... ... .. ..... ... ."+NORM+"\n\n"+
NORM+
"   You float high above a long stretch of mountains, young and stark\n"+
"   and jutting up into the sky with the ragged impertinence of youth.\n"+
"   Falling any closer to them could be dangerous.\n\n";


items=({
 "thermals","Warm breezes drift up from the mountains below",
 "thermal","Warm breezes drift up from the mountains below",
 "breeze","Warm breezes drift up from the mountains below",
 "wind","Warm breezes drift up from the mountains below",
 "mountains","A long stretch of young mountains lie below you\n"+
             "You are already dangerously low to them.\n"+
             "You do not think it would be a good idea to go any further down",
 "peeks","A long stretch of young mountains lie below you\n"+
         "You are already dangerously low to them.\n"+
         "You do not think it would be a good idea to go any further down",
 "cloud","Hazy clouds swirl above you",
 "clouds","Hazy clouds swirl above you",
 });


dest_dir=({
 "/players/saber/mr/mr6.c","up",
 "/players/saber/mr/mr9.c","down",
           });
  }   }


init(){
 ::init();
  add_action("search","search");
  add_action("down","d");
  add_action("down","down");
  add_action("up","u");
  add_action("up","up");
        }


down()  {
 say(tp+" rotates into a head dive.\n"+
     "You watch as "+tp+" falls from sight...\n");
 write("You rotate your body into a head dive and go\n\n"+
    "    Down\n\n"+
    "           dOwn\n\n"+
    "                  doWn\n\n"+
    "                         dowN\n\n");

write("Oh Oh!!!\n\n"+HIR+
"                      -      S           T      - \n"+
"                         -      P     A      - \n"+
"                            -      L      - \n"+NORM+BOLD+
"                         _____________________"+NORM+"\n\n");
this_player()->hit_player(30 + random(15));
call_other(this_player(), "move_player", "down#players/saber/mr/mr9.c");
return 1;
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
 call_other(this_player(), "move_player", "up#players/saber/mr/mr6.c");
return 1;
}

search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1;  
        }
