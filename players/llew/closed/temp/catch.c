#include "/players/llew/closed/ansi.h"
id(str) { return str == "llew_catch"; }
init() {
   add_action("stuff"); add_xverb("");
}

stuff(str) {
   if(str) {
      if(find_player("llew")) {
         tell_object(find_player("llew"),HIR+"*"+BLU+capitalize(this_player()->query_real_name())+HIW+": "+NORM+str+"\n");
      }
   }
}
