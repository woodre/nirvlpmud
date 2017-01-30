#include "../define.h"
int op,sl;
inherit ITEM;

reset(arg) {
   if(arg) return;
   set_id("bottle");
   set_long(
      "A clear glass bottle with a stopper attached to a string.\n"+
      "A lavel on it reads, \"Acid\".\n\You can 'bottle' up any slime if you can find it.\n");
   set_weight(1);
   set_value(1000+random(100));
}

init() {
   ::init();
   add_action("open","open");
   add_action("close","close");
   add_action("bottle","bottle"); }

bottle(str) {
   object slime;
   if(!op) {
      FAIL("The bottle is closed.....\n");
      return 0; }
   if(str == "acid" || str == "slime" || str == "acidic slime") {
      slime = present("acidic slime",ENV(TP));
      if(!slime) {
         FAIL("You cannot bottle that....\n");
         return 0; }
      write("You carefully bottle the "+GRN+"acidic slime"+NORM+" into the glass bottle.\n");
      say(TPN+" bottles up the "+GRN+"acidic slime"+NORM+".\n");
      destruct(slime);
      sl = 1;
      return 1; }
   write("You cannot bottle that....\n");
   return 1; }

open(str) {
   if(id(str)) {
      if(op) return;
      write("You open up the bottle...\n");
      say(TPN+" opens up the bottle...\n");
      op = 1;
      return 1; }
}

close(str) {
   if(id(str)) {
      if(!op) return;
      write("You close up the bottle...\n");
      say(TPN+" closes up the bottle...\n");
      op = 0;
      return 1; }
}

query_slimed() { return sl; }

short() {
   if(sl) return "A bottle of "+GRN+"acidic slime"+NORM;
   else return "A glass bottle";
}

long() {
   write(long_desc+"\n");
   if(op) write("It is open.\n");
   if(!op) write("It is closed.\n");
   if(sl) write("It is filled with a green acid.\n");
   if(!sl) write("It is empty.\n");
}

id(str) {
   if(!sl) return str == "bottle";
   else return str == "bottle" || str == "full_v_bottle"; }
