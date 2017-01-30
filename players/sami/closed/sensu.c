inherit "/obj/treasure";
#pragma combine_strings
#include <ansi.h>
#define TP this_player()
#define TPN this_player()->query_name()
#define TPRN this_player()->query_real_name()
#define POS this_player()->query_possessive()
#define MOCO move_object(clone_object
#define TO this_object()

query_save_flag() { return 1; }
id(str) { return str == "sensu" || str == "bean" || str == "sensu bean"; }
short(){ return ""+YEL+"Sensu bean"+NORM+""; }
long() {
   write(
      "This is a "+YEL+"sensu bean"+NORM+" cultivated by Korin. Few have seen these\n"+
      "magical beans. Rumor has it they have mystical powers.\n");
   return 1;
}
query_weight() { return 1; }
get() { return 1; }
value() { return 0; }
init() {
   add_action("eat_bean","eat");
}
eat_bean(str){
      object typ;
      object spell;
      int spm,hpm;
      spm = hpm = 0;
   if(!id(str)){ notify_fail("Eat what?\n"); return 0; }
   if(!str){ notify_fail("Eat what?\n"); return 0; }
   if(present("jar_str",TP)){ write("You do not think you could bare to eat another sensu bean.\n"); return 1; }
      
      if(TP->query_real_name() == "guest") { write("You may not be healed.\n"); return 1; }
      typ = "str";
      spell = clone_object("/players/sami/closed/str.c");
      spell->start(typ);
      
      write("You consume the "+YEL+"sensu bean"+NORM+" greedily.\n"+
         "You feel your arms swell and your muscles grow stronger.\n");
      say(TPN+" consumes "+YEL+"sensu bean"+NORM+".\n");
	  this_player()->heal_self(1000);
      call_other(this_player(),"drink_alcohol",-1000);
      call_other(this_player(),"drink_soft",-1000);
      call_other(this_player(),"eat_food",-1000);
      destruct(this_object());
       this_player()->recalc_carry();
return 1;
}