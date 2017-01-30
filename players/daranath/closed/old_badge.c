/* Quite obviously, taken from Verte's golden earring
       (hopefully) with permission     -Dar   */
/* This object is not in play anywhere.... so don't get all pissy */

#include "/players/vertebraker/define.h"
inherit ARMOUR;

reset(arg) {
   if(arg) return;
   ::reset();
   set_id("bone badge");
set_short(WHT+"Badge of Bone"+NORM);
   set_alias("badge");
   set_weight(1);
   set_ac(1);
   set_type("misc");
set_value(1950);
}

wear(string str) {
   while(remove_call_out("regen_sp") != -1);
   if(!id(str) || environment() != this_player() || worn) return 0;
   ::wear(str);
   if(worn) call_out("regen_sp", 5 + random(2));
   return 1; }

remove(string str) {
   if(!id(str) || environment() != this_player() || !worn) return 0;
   ::remove(str);
   while(remove_call_out("regen_sp") != -1);
   return 1; }

long() {
write("The Bone Badge is a small, palm sized talisman fashioned of black\n"+
      "onyx and silver in the shape of a skull blindfolded and \n"+
      "gagged by lengths of chain.\n");
}

regen_sp() {
   string msg;
    if(USER && USER->is_player())
    {
      switch(random(3)) {
case 0: msg = "The badge grows cold against your chest.\n";  break;
case 1: msg = "A chill spreads throughout your body.\n"; break;
case 2: msg = "The chill of the afterlife fills your body.\n"; break;
}
      if(!random(20)) tell_object(USER,msg);
      if(!random(100000)) {
         tell_object(USER,"Suddenly, your chest burns hot!\n");
         tell_object(USER,RED+"Your flesh is scorched!\n"+NORM);
         USER->add_hit_point(-(5+random(5)));
         while(remove_call_out("regen_sp") != -1);
         call_out("regen_sp", 5 + random(2));
         return 1; }
      USER->add_spell_point(3+random(2));
    }
      while(remove_call_out("regen_sp") != -1);
      call_out("regen_sp",5+random(2));
}

query_save_flag() { return 1; }

drop()
{
   while(remove_call_out("regen_sp") != -1);
   ::drop();
}
