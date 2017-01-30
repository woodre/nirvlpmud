/* 
 *  The word chamber of the Bards Guild of Ryllian
 *  v3.0 by Geoffrey Z. / Saber
 *
 */

#define tp this_player()->query_name()

inherit "room/room";

#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

reset(int arg) {  

if(!present("book"))  {
move_object(clone_object("/players/saber/closed/bard/itm/bard_news.c"),this_object());  }
if(!present("journal"))  {
move_object(clone_object("/players/saber/closed/bard/itm/bard_poetry.c"),this_object());  }
 
  if(!arg){

  set_light(1);
  short_desc="Chamber of Words";
 
  long_desc=
 BOLD+"Chamber of Words"+NORM+"\n"+
 "The Chamber of Words is a pleasant room constructed entirely from polished\n"+
 "mahogany wood.   It is furnished with a variety of comfortable couches and\n"+ 
 "padded chairs.   An enormous fireplace is built into the north wall, while\n"+
 "a grand staircase is set against the southern one. A beautiful wooden sign\n"+
 "hangs against the west wall amidst various paintings.\n";

items=({
 "floor","The floor is smooth and dark, and constructed from beautiful mahogany wood",
 "chamber","You are in the "+BOLD+"Chamber of Words"+NORM+"",
 "room","You are in the "+BOLD+"Chamber of Words"+NORM+"",
 "wood","The chamber is constructed entirely from polished mahogany wood",
 "mahogany","The chamber is constructed entirely from polished mahogany wood",
 "couches","There are several comfortable couches positioned about the chamber\n"+
           "Perhaps you could < sit > in one",
 "couch","There are several comfortable couches positioned about the chamber\n"+
         "Perhaps you could < sit > in one",
 "chairs","There are several padded chairs positioned about the chamber\n"+
          "Perhaps you could < sit > in one",
 "chair","There are several padded chairs positioned about the chamber\n"+
         "Perhaps you could < sit > in one",
 "fireplace","An enormous fireplace is built into the north wall",
 "staircase","A grand staircase is set against the southern wall.  It leads to the guarden",
 "stairs","A grand staircase is set against the southern wall.  It leads to the guarden",
 "painting","Many bright and exquisit paintings cover the west wall",
 "paintings","Many bright and exquisit paintings cover the west wall",
 "sign","The sign reads \"Home, Sweet Home\"",
 });

  dest_dir=({
 "/players/saber/closed/bard/r/summon.c","north",
 "/players/saber/closed/bard/r/lore.c","east",
 "/players/saber/closed/bard/r/hall.c","south",
 "/players/saber/closed/bard/r/tool.c","west",
 "/players/saber/closed/bard/r/garden.c","up",
           });
  }   }
  
  
init()  {
 ::init();

if(!present("instrument",this_player()) && this_player()->is_player() &&
   this_player()->query_level() < 21)  {
  
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


sit(str) {

  if (str == "chair" || str == "in chair"){
  write("You sit down in a padded mahogany chair.\n");
  say(tp+" sits down in a padded mahogany chair.\n");
    return 1;   
        }

  if (str == "couch" || str == "in couch" || str == "on couch") {
  write("You sit down in one of the _very_ comfortable couches.\n");
  say(tp+" sits down in one of the couches.\n");
    return 1;
        }
  
  if (str == "floor" || str == "on the floor" || str == "on floor") {
  write("You sit down on the floor.\n");
  say(tp+" sits down upon the floor.\n");
    return 1;
        }
        
  else {
  write("Sit where?\n");
  say(tp+" looks for a place to sit down.\n");
     return 1;
        }
        }
