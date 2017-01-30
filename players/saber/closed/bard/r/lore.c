/* 
 *  The lore chamber of the Bards Guild of Ryllian
 *  v3.0 by Geoffrey Z. / Saber
 *
 */

#define tp this_player()->query_name()

inherit "room/room";

#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

reset(int arg) {  

if(!present("tuyen"))  {
move_object(clone_object("/players/saber/closed/bard/mon/tuyen.c"),this_object());  }
 
  if(!arg){

  set_light(1);
  short_desc="Chamber of Lore";
 
  long_desc=
 BOLD+"Chamber of Lore"+NORM+"\n"+
 "The Chamber of Lore is spacious room of mahogany construct, filled with shelf\n"+
 "upon shelf of scrolls and books.  In the easter corner rests the work desk of\n"+
 "Tuyen. The western wall is covered with a detailed map of Ryllian, as wall as \n"+
 "a few maps of the many different worlds Nirvana.\n"+
 "Commands: maps, scrolls\n";

items=({
 "floor","The floor is smooth and dark, and constructed from beautiful mahogany wood",
 "chamber","You are in the "+BOLD+"Chamber of Lore"+NORM+"",
 "room","You are in the "+BOLD+"Chamber of Lore"+NORM+"",
 "wood","The chamber is constructed entirely from polished mahogany wood",
 "mahogany","The chamber is constructed entirely from polished mahogany wood",
 "shelf","The shelves are filled with books and scrolls",
 "book","Many books line the shelves",
 "books","Many books line the shelves",
 "desk","The work desk of Tuyen is covered with musical scores",
 "scrolls","There are many scrolls upon the shelves.  Type < scrolls > for a list",
 "scroll","There are many scrolls upon the shelves.  Type < scrolls > for a list",
 "map","Many maps cover the walls.  Type < maps > for a list", 
 "maps","Many maps cover the walls.  Type < maps > for a list",
 });

  dest_dir=({
 "/players/saber/closed/bard/r/vision.c","north",
 "/players/saber/closed/bard/r/word.c","west",
           });
  }   }
  
  
init()  {
 ::init();

if(!present("tuyen"))  {
move_object(clone_object("/players/saber/closed/bard/mon/tuyen.c"),this_object());  }

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
  add_action("maps","maps");
  add_action("scrolls","scrolls");
       }


search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1; 
       }


maps(str)  {

  if(!str)  {
  write("List of maps:\n"+
  "1)  Map of Ryllian.\n"+
  "\nType < maps > < # > to get a map.\n");
  return 1;
        }
        
  if(str == "1")  {
  move_object(clone_object("players/saber/stuff/flier.c"),this_player());
  write("You take a map.\n");
  say(tp+" takes a map from the shelf.\n");
  return 1;
        }
        
  write("There is no map by that name.\n");
  say(tp+" searches the shelf.\n");
  return 1;
        }


scrolls(str)  {

  if(!str)  {
  write("List of scrolls:\n"+
  "10)  Bard trial hints.\n"+
  "11)  Mini Guild Scroll.\n"+
  "\nType <scrolls> <#> to get a scroll.\n");
  return 1;
        }

  if(str == "11")  {
  move_object(clone_object("/players/saber/closed/new_mini/scroll.c"),this_player());
  write("You take a scroll.\n");
  say(tp+" takes a scroll.\n");
  return 1;
        }

  if(str == "10")  {
  say(tp+" reads a scroll.\n");
  write(
  "\nHints on Bardic Trials...\n\n"+
  "K.I.S.S (keep it simple stupid) - try the simple stuff first, THAN get complex.\n\n"+
  "Know your Bardic abilities.\n\n"+
  "If a Bardic trial doesn't start when you think it should, type < invoke >\n\n"+
  "Make sure that you're in the right place.\n\n"+
  "Check the 'exact' wording of what is asked of you.\n\n"+
  "Use bard speach  - ; works better than the say ' for trials.\n\n"+
  "Be sure to use lower case when answering questions.\n\n");
  return 1;
        }
        
  write("There is no scroll by that name.\n");
  say(tp+" searches the shelf.\n");
  return 1;
        }
        
