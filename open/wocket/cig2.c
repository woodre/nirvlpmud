#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
int x;
reset(int arg) {
   if(arg) return;
   set_id("cigar");
   set_short(BOLD+"cigar"+NORM);
   set_long(
      "This is a big brown cigar.  Boss Hogg loves to smoke these things.\n"+
      "You might like to "+MAG+"smoke cigar."+NORM+"\n");
   set_weight(1);
   set_value(50);
   set_dest_flag(1);
}
init() { 
   ::init();
   add_action("cigar","smoke");
}
cigar(arg) {
   if(arg == "cigar") {
      write(BOLD+"You take a puff of the cigar and feel better."+NORM+"\n");
      say(BOLD+""+TPN+" puffs on "+POS+" cigar."+NORM+"\n");
      TP->heal_self(7);
      call_out("blah1",8);
      return 1; }
}
blah1() {
   write(BOLD+"You take a puff of the cigar and feel better."+NORM+"\n");
   say(BOLD+""+TPN+" puffs on "+POS+" cigar."+NORM+"\n");
   TP->heal_self(7);
   if(x == random(9)) {
      destruct(this_object()); }
   else {
      call_out("blah1",8);
      return 1; }
}
