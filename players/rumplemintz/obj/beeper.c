#include <ansi.h>

inherit "obj/treasure";

reset(arg) {
   set_id("beeper");
   set_short("A beeper");
   set_long("It's a beeper for Rumplemintz.  To use type 'beep rump'\n");
   set_weight(1);
   set_value(50);
}

init() {
   ::init();
   add_action("beep_rump", "beep");
}

beep_rump(str){
   if(str=="rump"){
      if(find_player("rumplemintz")){
         tell_object(find_player("rumplemintz"),
            this_player()->query_name()+" is beeping you!\n"+
            BEEP+BEEP+BEEP+"\n");
         return 1;
      }
      write("Rumplemintz is not available at this time.\n");
      return 1;
   }
   return 0;
}
