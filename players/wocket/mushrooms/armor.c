#include "/players/wocket/closed/ansi.h"
inherit "/obj/armor";

reset(arg){
   set_id("armor");
   set_type("armor");
   set_short("Nonge battle armor");
   set_long("This is the battle of armor of the nonge.  Only a true newbie may wear it.\n");
   set_ac(4);
   set_weight(2);
   set_value(1000);
}

init(){
   ::init();
   add_action("wear","wear");
   add_action("remove","remove");
}

int wear(string str){
   if(!str || str != "armor"){
      notify_fail("What would you like to wear?\n");
      return 0;
   }
   if(this_player()->query_level() > 7){
      write("You are to powerful to wear this armor.\n");
      return 1;
   }
   write("Ok.\n");
   worn_by = this_player();
   worn = 1;
   call_other(this_player(),"wear",this_object());
}
