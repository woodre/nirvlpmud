#include "/players/fakir/color.h"
inherit "obj/armor";
int x;
reset(arg) {
   if(arg) return;
   set_id("shield");
   set_short(BOLD+WHITE+"Spirit Shield"+OFF);
   set_long(
      "A shield of protection granted by a grateful heart...set free into the\n"+
      "arms of death.  It will provide wonderful protection to one who first\n"+
      "accepts its power.  It may only be worn a single time, so beware.\n");
   set_weight(1);
   set_type("shield");
   set_save_flag();
   set_ac(2);
   set_value(350+random(1000)); }

wear(str) {
   if(!id(str) || environment() != this_player()) return 0;
   if(worn) {
      notify_fail("The shield's "+BOLD+WHITE+"power"+OFF+" is already protecting you!\n");
      return 0; }
   if(x) {
      notify_fail("Its"+BOLD+WHITE+" power "+OFF+"is spent.  It will no longer protect you from harm.\n");
      return 0; }
   ::wear(str);
   if(worn)
      {
      x=1;
      write("The shield's "+BOLD+WHITE+"power"+OFF+" bonds with you and creates a spirit shield....\n");
      say("The shield's "+BOLD+WHITE+"spirit"+OFF+" bonds with "+this_player()->query_name()+".....\n");
   }
   return 1;
}

remove(str) {
   if(!id(str) || environment() != this_player()) return 0;
   if(x) new_desc(); 
   if(!worn) {
      notify_fail("You are not wearing the shield!\n");
      return 0; }
   ::remove(str);
   if(!worn) {
      write("The "+BOLD+WHITE+"spirit shield"+OFF+" dies and releases its bond with you...\n");
      say("The "+BOLD+WHITE+"spirit shield"+OFF+" dies and releases its bond on "+this_player()->query_name()+".....\n");
   }
   return 1; }

drop() {
   if(x) new_desc();
   ::drop();  }

new_desc() {
   short_desc ="Spirit Shield";
   long_desc = "With its"+WHITE+" power "+OFF+"spent, the shield given from a grateful heart\n"+
   "will no longer serve as an armor.  You might be able to fetch a fair\n"+
   "price for it at a shop or trading post.\n";
}
