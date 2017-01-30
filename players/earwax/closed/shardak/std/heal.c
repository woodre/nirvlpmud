/* uses felde's generic heal code, a bit more neato though 
added a settable dest msg, new short(), checks if item is 
   detox or intox or what before it doesn't let you use */

inherit "/obj/generic_heal.c";

#include "../include/ansi.h"

string msg3;

void set_msg3(string str) { msg3 = str; }

string query_msg3() { return msg3; }

int cmd_imbibe(string str)
{
   if(!str || this_object()!=present(str,this_player()) )
      {
      notify_fail(capitalize(query_verb())+" what?\n");
      return 0;
   }
   if(stuff && stuff > 0 && 
         this_player()->query_stuffed() + stuff > (int)this_player()->query_level() * 8)
   {
      notify_fail("You are too full!\n");
      return 0;
   }
   if(soak && soak > 0 &&
         this_player()->query_soaked() + soak > (int)this_player()->query_level() * 8)
   {
      notify_fail("You can't drink anything else!\n");
      return 0;
   }
   if(intox && intox > 0 && 
         this_player()->query_intoxination() > this_player()->query_level()+3)
   {
      notify_fail("You cannot drink any more!\n");
      return 0;
   }
   if(soak) this_player()->drink_soft(soak);
   if(stuff) this_player()->eat_food(stuff);
   this_player()->drink_alcohol(intox);
   charges--;
   this_player()->add_hit_point(hp_heal);
   this_player()->add_alignment(-(33 + random(69)));
   this_player()->add_spell_point(sp_heal);
   write(msg);
   if(msg2) say((string)this_player()->query_name()+msg2);
   if(charges)
      {
      write("There are "+charges+" "+type+" remaining.\n");  
      this_player()->recalc_carry();
      command("mon",this_player());
   }
   else 
      {
      if(!msg3) write("You finish off the last "+type+".\n");
      else write(msg3);
      command("mon",this_player());
      destruct(this_object());
      this_player()->add_weight(-1);
   }
   return 1;
}

short() { return short_desc + RED + " [" + NORM + charges + RED + "]" + NORM; }

query_save_flag() { return 1; }
