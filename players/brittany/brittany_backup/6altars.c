/* Room will be refined and implemented with a future quest object */

#include "/open/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

int dummy;
status pointer;
status symbols;

reset(arg) {
   if(arg) return;
   pointer = 1;
   symbols = 1;
   
   short_desc = WHT+"The Great One's Lair"+NORM;
   long_desc =
    "     You have entered a circular pit surrounded by six stone altars.\n"+
    "The altars are of different sizes and each one has a face carved into\n"+
    "it.  A partial wall stands in the middle of the pit.  A small dark niche\n"+
    "is recessed into the wall.  Inside the niche something ticks loudly.\n"+
    "Something about the wall draws your attention.\n";


   items = ({
         "pit","A circular pit surrounded by six stone altars",
         "altars","The six stone altars in a circle around the pit, altar 3 looks different than the rest",
         "clock","A coffin-shaped clock, when the hands move it ticks curiously",
         "altar 3","This altar stood higher than the rest, the face carved into it changes\n"+
         "each time you 'gaze' at it",
         "dial","The face has hieroglypic symbols and time is indicated by pointers",
         "ring","A circular pit in a ring of six altars",
         "symbols","The symbol's resembles each face on the different altars",
         "wall","The wall has hieroglypic symbols carved into it, maybe you could 'feel' them",
        "pointer","The large hand on the clock, maybe you should 'adjust' it",
         "pointers","The pointers indicating time on the clock, one pointer is larger than the other",
         "coffin","A coffin-shaped clock that ticks curiously",
         "hands","The pointers on the face of the clock",
         "niche","A small dark niche recessed into the wall",
         "hieroglyphs","The figure looks like a human face that continuously changes",
         "face","The face on each altar seem to resemble the changing ones in the hieroglyphics",
         "altar 1","The face on the stone resembles a small child",
         "altar 4","The face on the stone resembles a young child",
         "altar 3","The face is not human until you 'gaze' at it",
         "altar 2","The face on the stone resembles a young man",
         "altar 5","The face on the stone resembles an older gentleman",
         "altar 6","The face on the stone resembles a middle-aged man",
          });

   dest_dir = ({
         "/players/brittany/kadath/kadath1.c","out",
      });
}
   
init(){
  ::init();
  add_action("adjust_pointer","adjust");
  add_action("gaze","gaze");
  add_action("search","search");
  add_action("feel_symbols","feel");
  }

feel_symbols(str){
   if(!str ||  str != "symbols") {
   notify_fail("What do you want to feel?\n");
   return 0; }
 
   if(symbols) {
 write("You feel the symbols and the wall begins to move.\n\n"+
   ""+HIW+"The clock is moved outside of the niche."+NORM+"\n");
   move_object(clone_object("/players/brittany/kadath/clock.c"),this_object());
     symbols = 0;
   }
   else write("Nothing happens.\n");
   return 1; }

adjust_pointer(str){
   if(!str ||  str != "pointer") {
   notify_fail("What do you want to adjust?\n");
   return 0; }

   if(pointer) {
 write("The pointer turns, and CLICK!   the door creaks open.\n\n"+ 
   ""+HIR+"The Great One appears."+NORM+"\n");
     move_object(clone_object("/players/brittany/kadath/npcs/carter.c"),this_object());
     pointer = 0;
   }
   else write("The pointer has already been adjusted.\n");
   return 1; }

search(str) {
    if(present("one",this_object())) {
        write("The Great One moves in front of the altar and blocks your entrance.\n");
        return 1; }
    if(!str || str != "altar") {
        notify_fail("Search what?\n");
        return 0; }

move_object(clone_object("/players/brittany/kadath/treasure/gold_box.c"),this_player());
     write("You retrieve a long golden box from the altar.\n");
    return 1;
}

gaze(str){
  if(str != "altar 3")
  return 1;

  dummy = random(6);
  /* dummy++; */
  if(!dummy){
  write("The face of a small child.\n");  return 1; }
  if(dummy == 1){
  write("The face of a young man.\n"); return 1; }
  if(dummy == 2){
  write("The face is not human and oddly shaped.  Maybe you should 'search' it.\n"); return 1; }
  if(dummy == 3){
  write("The face of a young child.\n"); return 1; }
  if(dummy == 4){
  write("The face of an older gentleman.\n"); return 1; }
  if(dummy == 5) {
  write("The face of a middle-aged man.\n"); return 1; }
}
