#include "/players/wocket/closed/ansi.h"
inherit "obj/treasure";

reset(arg){
   if(arg) return;
   set_id("sign");
   set_alias("sign");
   set_short("A shattered sign");
   set_long("A broken sign barely readable.\n");
   set_value(0);
}

init(){
   add_action("read_sign","read");
}

read_sign(str){
   if(str != "sign"){
      notify_fail("What would you like to read?\n");
      return 0;
   }
   write("\nTh s area  s full of chaos.   he world h  b en tuned  nto   wasteland\n" +
      "wi   great destruction.  T er  a e no enforcers he e, no rules to play\n" +
      "by.  T e only th ng th t matters he e is survival.  Any  e can attack\n" +
      "any     e e reg  d ess of le  l or whether or not player kill  s set.\n"+
      "There are many adventures here  n the f  u e, but your l fe will be\n"+
      "taken  f you  re weak.\n");
   return 1;
}
get(){ return 0; }
drop(){ return 0; }
