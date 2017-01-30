/* 
 *  The summoning chamber of the Bards Guild of Ryllian
 *  v3.0 by Geoffrey Z. / Saber
 *
 */

#define tp this_player()->query_name()

inherit "room/room";

#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

reset(int arg) {  

 if(!present("circle"))  {
 move_object(clone_object("/players/saber/closed/bard/itm/pet_thing.c"), this_object());  }
 
  if(!arg){

  set_light(1);
  short_desc="Chamber of Summoning";
 
  long_desc=
 BOLD+"Chamber of Summoning"+NORM+"\n"+
 "You have entered the Chamber of Summoning, constructed entirely from polished\n"+
 "mahogany wood.  The floor is smooth and dark, riddled with cryptic wood grain\n"+
 "lines which shift patterns under your gaze.  The room is lit by the dim light\n"+
 "of the glowing blue circle.  Behind the circle rests a dark portal, it's deep\n"+
 "shadow leading into the legendary Dark Chamber.\n";

items=({
 "floor","The floor is smooth and dark, and constructed from beautiful mahogany wood",
 "lines","The wood grain lines shift patterns under your gaze",
 "line","The wood grain lines shift patterns under your gaze",
 "patterns","The wood grain lines shift patterns under your gaze",
 "pattern","The wood grain lines shift patterns under your gaze",
 "chamber","You are in the "+BOLD+"Chamber of Summoning"+NORM+"",
 "room","You are in the "+BOLD+"Chamber of Summoning"+NORM+"",
 "wood","The chamber is constructed entirely from polished mahogany wood",
 "light","The room is lit by the dim light of the glowing "+BLU+"blue"+NORM+" circle",
 "portal","The portal leads to the legendary Dark Chamber",
 });

  dest_dir=({
 "/players/saber/closed/bard/r/word.c","south",
 "/players/saber/closed/bard/r/ward.c","west",
 "/players/saber/ryllian/portal.c","portal",
 "/room/church","church",
           });
  }   }
  
  
init()  {
 ::init();

 if(!present("circle"))  {
 move_object(clone_object("/players/saber/closed/bard/itm/pet_thing.c"), this_object());  }

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
       }


search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1; 
       }


sit(str)  {
  if (str == "circle"){
  write("You sit down in the circle of "+BLU+"blue"+NORM+" power.\n"+
        "Try later.  Circle powers not yet at full potential.\n");
  say(tp+" sits in the "+BLU+"blue circle"+NORM+" of power.\n");
  return 1;   
       }
 
 if (str == "floor")  {
  write("You sit down on the floor.\n");
  say(tp+" sits down upon the floor.\n");
  return 1;
       } else {
  
  write("Sit where?\n");
  say(tp+" looks for a place to sit down.\n");
  return 1;
       }
       }

