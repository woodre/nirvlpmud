/*Originally created by Wocket adopted by Snakespear @Nirvana 1/27/98 */

#include "/players/snakespear/closed/ansi.h"
#define OWNER environment()
inherit "obj/treasure";
extra_look() {
  return OWNER->query_name()+" holds a small, sharp rose in "+OWNER->query_possessive()+" teeth";
}
reset(arg){
   if(arg) return;
set_short(BLU+"--,-`-"+HIB+"("+GRY+"@"+NORM);
set_long("  This rose is a special tell to Snakespear.\n\n"+
         "'Only those that live through respect and honor\n"+
         " shall possess such a rose that resides in the\n"+
         " darkest part of the Forbidden Forest.'\n"+
     GRY+"            -Snakespear-\n\n"+NORM+
     HIW+"      You have the choice of:\n"+HIR+
         "     ss              tell to Snakespear\n"+    
         "     sse            emote to Snakespear\n"+
         "     drop rose     get rid of this beauty\n"+NORM);
set_id("rose");
set_alias("stell");
}
get(){ return 0; }
drop() {return 1;}
query_auto_load() { return "/players/snakespear/tools/arose.c:"; }
init(){
   add_action("stell","ss");
   add_action("stelle","sse");
}

stell(str){
   if(find_player("snakespear")){
      if(str){
     tell_object(find_player("snakespear"),HIB+"~*{"+HIC+"SS"+HIB+"}*~"+HIW+this_player()->query_name()+" speaks: "+HIC+str+"\n"+NORM);
     write(HIB+"~*{"+HIC+"SS"+HIB+"}*~"+HIW+this_player()->query_name()+" speaks: "+HIC+str+"\n"+NORM);
         return 1;
      }
     notify_fail(HIB+"~*{"+HIC+"SS"+HIB+"}*~"+HIC+"You gonna talk or stand there and "+BLINK+HIR+"bleed"+NORM+HIC+"??\n"+NORM);
      return 0;
   }
   notify_fail(BLINK+GRY+"The Dark Gentleman is not here"+HIR+"....\n"+NORM);
   return 0;
}

stelle(str){
   if(find_player("snakespear")){
      if(str){
     write(HIB+"~*{"+HIC+"SS"+HIB+"}*~"+HIW+this_player()->query_name()+HIC+" "+str+".\n"+NORM);
     tell_object(find_player("snakespear"),HIB+"~*{"+HIC+"SS"+HIB+"}*~"+HIW+this_player()->query_name()+HIC+" "+str+".\n"+NORM);
         return 1;
   }
   notify_fail(HIB+"~*{"+HIC+"SS"+HIB+"}*~"+HIW+"Trying to emote again, eh?? :)\n"+NORM);
      return 0;
   }
   notify_fail(BLINK+GRY+"The Dark Gentleman is not here"+HIR+"....\n"+NORM);
   return 0;
}
