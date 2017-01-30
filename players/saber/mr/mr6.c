#define tp this_player()->query_name()

inherit "room/room";
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

int gem, number;

reset(int arg){

if(!present("griffon"))  {
  number = random(3) + 2;
  for(gem = 0; gem < number; gem++)  { 
  move_object(clone_object("/players/saber/monsters/mr/rider.c"),this_object()); 
   }
   }
   
if(!arg){

 set_light(1);
 short_desc="Free Falling";

 long_desc="\n"+BOLD+
"              *   *   *   C   L   O   U   D   S   *   *   *\n\n"+NORM+
"You float through the clouds, at once warm from the rising thermals yet\n"+
"wet from the condensed moisture.  Strange sounds assail you, seeming to\n"+
"echo from within the body of the illuminated gloom which surrounds you.\n\n";


items=({
 "thermals","Warm breezes drift up from the mountains below",
 "thermal","Warm breezes drift up from the mountains below",
 "breeze","Warm breezes drift up from the mountains below",
 "wind","Warm breezes drift up from the mountains below",
 "sound","Strange sounds come from the clouds",
 "sounds","Strange sounds come from the clouds",
 "cloud","Hazy clouds swirl around you.\n"+
         "Hay!  It looks like you could go < in > to one",
 "clouds","Hazy clouds swirl around you.\n"+
         "Hay!  It looks like you could go < in > to one",
 });


dest_dir=({
 "/players/saber/mr/mr5.c","up",
 "/players/saber/mr/mr8.c","down",
           });
  }   }


init(){
 ::init();
  add_action("search","search");
  add_action("down","d");
  add_action("down","down");
  add_action("up","u");
  add_action("up","up");
  add_action("in","in");
  add_action("listen","listen");

        }

listen()  {
 write("Strange sounds come from the clouds around you.  You may\n"+
       "want to look at them.\n");
 return 1;
  }

in()  {
call_other(this_player(), "move_player", "into the clouds#players/saber/mr/mr7.c");
return 1;
  }

down()  {
 say(tp+" rotates into a head dive.\n"+
     "You watch as "+tp+" falls from sight...\n");
 write("You rotate your body into a head dive and go\n\n"+
    "    Down\n\n"+
    "           dOwn\n\n"+
    "                  doWn\n\n"+
    "                         dowN\n\n");
call_other(this_player(), "move_player", "down#players/saber/mr/mr8.c");
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
call_other(this_player(), "move_player", "up#players/saber/mr/mr5.c");
return 1;
 }

search() {
 write("You think you see an opening in the clouds.  Try to go < in >\n");
 say (tp +" searches the area.\n");
 return 1;  
        }
