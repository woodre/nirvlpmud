#define tp this_player()->query_name()

inherit "room/room";
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

reset(int arg){

if(!present("drake"))  {
move_object(clone_object("/players/saber/monsters/mr/sundrake.c"),this_object());  }

 if(!arg){

 set_light(2);
 short_desc="Free Falling";

 long_desc="\n"+
"The thermals brush against your"+BOLD+HIR+"   \\  /   "+NORM+"skin, warming you from below\n"+
"while the sweltering fires of  "+BOLD+HIR+"  - "+HIY+"() "+HIR+"-  "+NORM+" the sun bake you from above.\n"+  
"Flying any higher could quickly"+BOLD+HIR+"   /  \\   "+NORM+"become exceedingly dangerous.\n\n";


items=({
 "thermals","Warm breezes drift up from the mountains below",
 "thermal","Warm breezes drift up from the mountains below",
 "breeze","Warm breezes drift up from the mountains below",
 "wind","Warm breezes drift up from the mountains below",
 "heat","Warm breezes drift up from the mountains below",
 "sun","You are so high that you can almost touch the sun",
 });


dest_dir=({
 "/players/saber/mr/mr4.c","up",
 "/players/saber/mr/mr2.c","down",
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
call_other(this_player(), "move_player", "down#players/saber/mr/mr2.c");
return 1;
 }

up()  {
if(present("sun cloak", this_player()))  {
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
 write("\nWoah -   "+BOLD+HIR+" S U N F I R E"+NORM+"\n\n");
call_other(this_player(), "move_player", "up into the sun#players/saber/mr/mr4.c");
return 1;
 }
 else {
 say(tp+" spreads "+this_player()->query_possessive()+" body eagle and catches an updraft.\n"+
     "You watch as "+tp+" rises into the sky...and is "+HIR+"BURNT"+NORM+" by the Sun!\n"+
     tp+" stops ascending.\n");
 write("                                   Up  up\n"+
       "                           up  UP \n"+
       "                         UP\n"+
       "                   up  Up\n"+
       "            Up   UP\n"+
       "     Up  up\n"+
       "  up\n\n"+
       "You spread your body eagle and catch an updraft.\n\n"+
       "AGGG!!  "+HIR+"FIRE!  FIRE"+NORM+"...You stop ascending...\n\n"); 
 this_player()->hit_player(random(30));
 return 1;
 
 }
 }

search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1;  
        }
