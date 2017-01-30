#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("signpost");
   set_short(YEL+"A wooden signpost"+HIW+" ["+BLINK+HIR+"READ ME"+NORM+HIW+"]"+NORM);
   set_long(
   "  A splintered and rotted wooden post sits here with a very\n"+ 
   "large wooden board hammered to it with rusted nails.  There\n"+
   "appears to be some sort of writing on it that you can read.\n");
   set_weight(0);
   set_value(0);
}
init(){
   ::init();
   add_action("read","read");
}
read(arg){
   if(arg == "writing" || arg == "signpost"){
      write(
   HIW+"  Welcome to Khrell's area.  Feel free to explore\n"+
   "and fight the denizens within.  I have decided to\n"+
   "be less spammy on the main board on the green so \n"+
   "any additions will be low key and players should \n"+
   "check here often to see if anything has been added.\n"+
   HIC+" Skaven coin drops have been modified. 06/10/09"+NORM+"\n");
      say(TPN+" reads the signpost.\n");
      return 1; }
   notify_fail("Read signpost?\n"); return 0; }
get(){
   write("You cannot get this!\n");
   return 0; }
   