#include "/players/vertebraker/define.h"
inherit ITEM;
int o, h;

reset(x)
{
   if(x) return;
   set_id("bag");
   set_alias("feed bag");
   set_short("A leather feed bag");
   set_save_flag(1);
   h = 5;
}

query_value()
{
   return (h * 30) + 35;
}

short()
{
   return(o ? short_desc+" (open)":short_desc+" (closed)");
}

long()
{
   string x;
   write(
      "A large, brown leather feed bag with a long cord that\n"+
      "acts a drawstring.  It holds a mixture that you may\n"+
      "'feed' to your horse, so that it may regain strength.\n");
   x = (o ? "open" : "closed");
   write("The bag is "+x+".\n");
   x = (h > 1 ? (h > 3 ? "nearly full" : "half full") : "nearly empty");
   if(!h) x = "empty";
   write("The bag is "+x+".\n");
}

init()
{
   ::init();
   add_action("feed_it","feed");
   add_action("open_it","open");
   add_action("close_it","close");
}

feed_it(str)
{
   object horse;
   if(!o)
      {
      write("You must open the bag first.\n");
      return 1;
   }
   if(!h)
      {
      write("You have no more feed remaining in that bag.\n");
      return 1;
   }
   if(!str)
      {
      write("Feed what?\n");
      return 1;
   }
   str = LOWER(str);
   horse = present(str,ENV(TP));
   if(!horse)
      {
      write("Your horse is not here!\n");
      return 1;
   }
   if(!horse->id("warhorse"))
      {
      write("Why would you feed that?\n"+
         "This is food for warhorses.\n");
      return 1;
   }
   if(horse->query_owner() != TP)
      {
      write(horse->QN+" snaps as you try to feed it!\n");
      TP->remote_say(horse->QN+" snaps as "+TPN+" tries to feed it!\n");
      return 1;
   }
   write("  You take some food from the bag and hold it out in front\n"+
      "  of "+horse->QN+"'s mouth.\n\n");
   TP->remote_say(
      TPN+" offers some food for "+possessive(TP)+" horse to eat.\n");
   if(horse->query_hunger() > 2900)
      {
      write("  "+horse->QN+" sniffs the food, but ignores it.\n"+ 
         "  You toss it back into the bag.\n");
      TP->remote_say(horse->QN+" sniffs the food, but ignores it.\n");
      return 1;
   }
   horse->add_hunger(300 + random(150));
   write("  "+horse->QN+" gratefully eats the mixture of grains.\n"+
      "  He looks much more healthy now.\n");
   TP->remote_say(horse->QN+" munches morosely on a mixture of grains.\n");
   h--;
   return 1;
}

open_it(str)
{
   if(!str)
      {
      notify_fail("Open what?\n");
      return 0;
   }
   if(id(str))
      {
      if(o)
         {
         write("The bag is already open.\n");
         return 1;
      }
      write("You open the bag.\n");
      TP->remote_say(TPN+" opens a feed bag.\n");
      o++;
      return 1;
   }
}

close_it(str)
{
   if(!str)
      {
      notify_fail("Close what?\n");
      return 0;
   }
   if(id(str))
      {
      if(!o)
         {
         write("The bag is already closed.\n");
         return 1;
      }
      write("You close the bag.\n");
      TP->remote_say(TPN+" closes a feed bag.\n");
      o--;
      return 1;
   }
}

id(str) { return str == "bag" || str == "feed bag" || str == "feed"; }
