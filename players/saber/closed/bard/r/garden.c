/* 
 *  The life chamber of the Bards Guild of Ryllian
 *  v3.0 by Geoffrey Z. / Saber
 *
 */

#define tp this_player()->query_name()

inherit "room/room";

#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

int NUMBER;

reset(int arg) {  

  NUMBER = 7;
 
  if(!arg){

  set_light(1);
  short_desc="Chamber of Life";
 
  long_desc=
 BOLD+"Chamber of Summoning"+NORM+"\n"+
 "The Chamber of Life is an open rooftop garden set atop Orin's Inn. The\n"+
 "vegetation consists primarily of crystalline rose bushes, artistically\n"+
 "arranged so that their varying chromatic hues blend spectacularly into\n"+
 "unusual patterns.   Legend holds that crystal roses plucked from these\n"+
 "bushes remain connected to their brethren, repeating what they reflect\n"+
 "across vast distances.\n";

items=({
 "floor","The garden dirt is loose and rich",
 "patterns","The hues of the crystal roses form unusual patterns",
 "pattern","The hues of the crystal roses form unusual patterns",
 "chamber","You are in the "+BOLD+"Chamber of Life"+NORM+"",
 "room","You are in the "+BOLD+"Chamber of Life"+NORM+"",
 "vegitation","The vegetation consists primarily of crystalline rose bushes",
 "garden","You are in the "+BOLD+"Chamber of Life"+NORM+"",
 "inn","You are atop the Inn of Orin",
 "bush","Many large rose bushes bloom nearby.\n"+
        "There are "+NUMBER+" roses waiting to be picked.\n"+
        "To pick a rose, type < pick rose >",
 "bushs","Many large rose bushes bloom nearby.\n"+
         "There are "+NUMBER+" roses waiting to be picked.\n"+
         "To pick a rose, type < pick rose >",
 "vegetation","Many large rose bushes bloom nearby.\n"+
        "There are "+NUMBER+" roses waiting to be picked.\n"+
        "To pick a rose, type < pick rose >",
 });

  dest_dir=({
 "/players/saber/closed/bard/r/word.c","down",
           });
  }   }
  
  
init()  {
 ::init();

if(!present("instrument",this_player()) && this_player()->is_player())  {
  
  write("You get the brief image of a "+BLU+"blue circle"+NORM+" before\n\n"+
        BOLD+" * * * * *  B O O M  * * * * *"+NORM+"\n\n"+
        "Your body flies through space.\n\nYou find yourself somewhere new.\n");
  say(tp+" bounces off the "+BLU+"Circle of Warding"+NORM+".\n");
  move_object(this_player(),"/room/void");
  tell_room(environment(this_player()), tp+" falls screaming from the sky.\nTHUD.\n");
  return 1;
        }

  add_action("search","search");
  add_action("sit","sit");
  add_action("pick_rose","pick");
       }


search() {
 write("You find "+NUMBER+" pickable living crystal roses.\n"+
       "To pick a rose, type < pick rose >.\n");
 say (tp +" searches the area.\n");
 return 1; 
       }


pick_rose(str)  {
object ROSE;

 if (str == "rose") {
  if(NUMBER > 0)  {
  NUMBER = NUMBER - 1;
  write("You pick a crystal rose.  There are "+NUMBER+" roses left.\n");
  say(tp+" picks a crystal rose.\n");
  ROSE = clone_object("/players/saber/closed/bard/itm/livingrose.c");
  move_object(ROSE, this_player());
  return 1;
       }
  write("There are no crystal roses left.\n");
  say(tp+" looks at the crystal rose bushes.\n");
  return 1;
       }
       }
