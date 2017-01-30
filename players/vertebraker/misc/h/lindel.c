#include "/players/vertebraker/define.h"
inherit NPC;
#define PATH "/players/vertebraker/misc/h/"

reset(arg)  
{
   ::reset(arg);
   if(arg) return;
   set_name("lindel");
   set_race("human");
   set_short("Lindel");
   set_gender("female");
   set_long(
      "     Enchantingly beautiful with a devilish sparkle in her eye, Lindel\n"+
      "helps out in the stables from time to time.  It is rumored by some she\n"+
      "is somehow related to Master Bolmont, but no one seems to know for sure.\n"+
      "You can 'buy' feed from her, a mixture of oats, hay, fresh pasture grass,\n"+
      "and salt.  It is a valuable commodity.\n");
   set_level(5);
   set_hp(75);
   set_al(1000);
   set_wc(9);
   set_ac(5);
   add_money(5+random(100));
   set_chat_chance(5);
   load_chat("Lindel smiles at you.\n");
   load_chat("Lindel says: would you like to buy some feed dear?\n");
}

init()
{
   ::init();
   add_action("buy_it","buy");
   add_action("buy_it","purchase");
}

buy_it(str)
{
   if(str == "feed" || id(str) || str == "food")
      {
      if(TP->query_money() < 300)
         {
         write("Lindel says: It costs 300 coins per pouch.\n"+
            "You do not have enough money.\n");
         return 1;
      }
      if(!TP->add_weight(1))
         {
         write("Lindel says: You cannot carry anymore, I'm afraid.\n");
         return 1;
      }
      write("Lindel gratefully takes 300 coins from your hand.\n\n"+
         "Lindel gives you a leather feed bag, tied with a drawstring.\n\n"+
         "Lindel thanks you.\n");
      TP->add_money(-300);
      MO(CO(PATH+"feed"),TP);
      return 1;
   }
}
