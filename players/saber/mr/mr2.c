#define tp this_player()->query_name()

inherit "room/room";
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

reset(int arg){

 if(!arg){

 set_light(1);
 short_desc="Free Falling";

 long_desc="\n"+HIB+
"                  .   .   .   W   I   N   D   .   .   ."+NORM+"\n\n"+
"You float on the thermals far above the sharp mountain peaks. Below you \n"+
"hazy clouds swirl into strange patterns, distorted by the rising heat.\n\n";


items=({
 "thermals","Warm breezes drift up from the mountains below",
 "thermal","Warm breezes drift up from the mountains below",
 "breeze","Warm breezes drift up from the mountains below",
 "wind","Warm breezes drift up from the mountains below",
 "heat","Warm breezes drift up from the mountains below",
 "mountains","A long stretch of young mountains lie below you",
 "peeks","A long stretch of young mountains lie below you",
 "cloud","Hazy clouds swirl below you",
 "clouds","Hazy clouds swirl below you",
 });


dest_dir=({
 "/players/saber/mr/mr3.c","up",
 "/players/saber/mr/mr5.c","down",
 "/players/saber/mr/mr1.c","west",
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
call_other(this_player(), "move_player", "down#players/saber/mr/mr5.c");
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
call_other(this_player(), "move_player", "up#players/saber/mr/mr3.c");
return 1;
 }

search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1;  
        }
