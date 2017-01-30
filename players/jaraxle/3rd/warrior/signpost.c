#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("signpost");
   set_short("A signpost [updated 1."+HIY+"7"+NORM+"]");
   set_long("A short wooden post with a flat board attached to it by\n"+ 
      "dried out vines.  There is some writing you can read from\n"+
      "the board.\n");
   
   
   set_weight(0);
   set_value(0);
}
init(){
   ::init();
   add_action("read","read");
}
read(arg){
   if(arg == "writing" || arg == "signpost"){
      write("This is the entrance to Jaraxle's area.  Jaraxle has kindly made\n"+
         "it possible for anyone to write whenever in his realm.  From any-\n"+
         "where in his area. The commands are as follows:\n"+
       "\n"+HIW+"j_opinion"+NORM+" <"+HIW+"message"+NORM+"> : To give your opinion on anything in the area.\n"+
         ""+HIW+"j_idea "+NORM+"<"+HIW+"message"+NORM+"> : To stress any ideas you might have for Jaraxle.\n"+
         ""+HIW+"j_typo "+NORM+"<"+HIY+"typo"+NORM+"> : To let Jaraxle know of any typos you find.\n"+
         ""+HIW+"j_bug "+NORM+"<"+HIR+"bug"+NORM+"> : If you find a bug, or an error, please type that here.\n\n"+
"Type "+HIG+"'"+HIW+"j_help"+HIG+"'"+NORM+" to get a listing of cmds from anywhere in the area.\n"+
         "\nYou will have to look carefully while in this area.  There are a lot of\n"+
         "secrets and hidden things to be found in here.  Keep an eye on the room\n"+
         "descriptions.\nJar.\n");
write(HIW+"\n\t["+HIR+" The Phoenix Tower has been modified: *Be "+NORM+RED+"warned*"+HIW+" ]\n"+NORM);
      say(TPN+" reads the signpost.\n");
      return 1; }
   notify_fail("Read signpost?\n"); return 0; }
get(){
   write("You cannot get this!\n");
   return 0; }
