inherit "/players/vertebraker/closed/std/treasure";
#include "/players/jaraxle/ansi.h"

int worn;

void
reset(int arg)
{
   if(arg) return;
   set_id("phoenix mask");
   add_id("mask");
   set_short(HIR+"Phoenix Mask"+NORM);
   set_long("\
      A small mask made from the feathers of a Phoenix.\n\
      You can wear it over your face.\n");
   set_value(400 + random(1000));
}

status
drop()
{
   object z;
   
   if((z = this_player()) && worn)
      command("remove phoenix mask", z);
}

void
init()
{
   ::init();
   add_action("cmd_wear", "wear");
   add_action("cmd_remove", "remove");
}

status
cloak_check(object heh)
{
   object ung;
   
   ung = first_inventory(heh);
   while(ung)
   {
      if((status)ung->id("phoenix mask") && (status)ung->query_worn())
         return 1;
      ung = next_inventory(ung);
   }
   
   return 0;
}


status
cmd_wear(string str)
{
   object z;
   
   if(id(str) && (environment() == (z = this_player())))
      {
      if(worn)
         {
         notify_fail("You are already wearing it!\n");
         return 0;
      }
      if(cloak_check(z))
         {
         notify_fail("You are already wearing a mask.\n");
         return 0;
      }
      write("You place the mask over your face.\n");
      say((string)z->query_name() + " wears a mask.\n");
      worn = 1;
      return 1;
   }
   
   return 0;
}

status
cmd_remove(string str)
{
   object z;
   if(id(str) && (environment() == (z = this_player())))
      {
      if(!worn)
         {
         notify_fail("You aren't wearing it.\n");
         return 0;
      }
      write("You remove the phoenix mask.\n");
      say((string)z->query_name() + " removes a phoenix mask.\n");
      worn = 0;
      return 1;
   }
   
   return 0;
}

string
short()
{
   return ::short() + (worn ? " (worn)" : "");
}

status
query_worn()
{
   return worn;
}

status
is_armor()
{
   string vrb;
   if((vrb = query_verb()) && (vrb == "ready" || vrb == "#"))
      return 1;
   else return 0;
}
