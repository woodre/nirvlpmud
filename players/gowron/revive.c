#include "/players/llew/closed/ansi.h"
inherit "obj/treasure";

int delay;
string align, afterlife;
object ob;

reset(arg) {
   if(arg) return;
   set_id("revive");
}

init() {
   ::init();
   align();
   task();
   delay = 0;
}

task() { 
   switch(delay) {
   case 0:
      ob = this_player();
      say(ob);
      say(BOLD+BLK+"Death"+NORM+" grasps your disembodied soul...\n");
      ++delay;
      call_out("task",1,);
      break;
   case 1:
      say(BOLD+BLK+"Death"+NORM+" traces your soul with the Orb of Judgment...\n");
      ++delay;
      call_out("task",1);
      break;
   case 2:
      say(BOLD+BLK+"Death"+NORM+" says, \" I have judged your soul as balanced towards "+align+".\"\n");
      say("I have a task for you, if you wish to redeem your life.\n");
      ++delay;
      call_out("task",1);
      break;
   case 3:
      say(BOLD+BLK+"Death"+NORM+" continues, \"There is an imbalance in the Powers of Good and Evil, and\n"+
          "you are the Chosen to put it right.\"\n");
      ++delay;
      call_out("task",1);
      break;
   case 4:
      say("Go now into "+afterlife+" and destroy the powers that reside there. May Fate be on your side.\n");
      ++delay;
      call_out("task",1);
      break;
   case 5:
      ++delay;
      destination(ob);
      destruct(this_object());
      break;
   }
   return;
}

align() {
   int temp;
   temp = this_player()->query_alignment();
   if(temp > 100) { 
      align = "good";
      afterlife = BOLD+"Heaven"+NORM;
   }
   if(temp <= 100 && temp >= -100) {
      align = "neutral";
      afterlife = "Purgatory";
   }
   if(temp < -100) {
      align = "evil";
      afterlife = HIR+"Hell"+NORM;
   return ;
   }
}

destination() {
   if(align == "good") {
      heaven();
   }
   if(align == "evil") {
      hell();
   }
   if(align == "neutral") {
      purgatory();
   } 
   return;
}


heaven() {
   this_player()->remove_ghost();
   move_object(this_player(), "/ulath/afterlife/heaven_gate.c");
   write(BOLD+BLK+"Death"+NORM+" has moved you to "+afterlife+"\n");
   return;
}

hell() {
   this_player()->remove_ghost();
   move_object(this_player(), "/ulath/afterlife/hell_gate.c");
   write(BOLD+BLK+"Death"+NORM+" has moved you to "+afterlife+"\n");
   return;
}

purgatory(ob) {
   ob->remove_ghost();
   move_object(ob, "/ulath/afterlife/purgatory.c");
   say(BOLD+BLK+"Death"+NORM+" has moved you to "+afterlife+"\n");
   return;
}
   