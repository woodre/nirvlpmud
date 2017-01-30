#include "../define.h"
inherit ARMOUR;

/*
void
set_type(string str)
{
    type = str;
}
*/
/* edited by Tallos 05-17-07 by Tallos to add mage guild Bonus*/
#define GUILDID "mageobj"
#define BONUS_TYPE "wisdom"
#define BONUS_AMOUNT 1
inherit "/obj/armor";
reset(arg) {
   ::reset(arg);
  if(arg) return;
   set_short(MAG+"Flowing purple robes"+NORM);
   set_id("robes");
   set_alias("purple robes");
   set_type("robes");
   set_ac(0);
   set_long(
      "Long, velvety robes that you can wear over\n"
      +"your usual armor.  They are regal-looking\n"
      +"but you doubt they would offer much in the\n"
      +"way of protection.\n");
   set_weight(1);
   set_value(100+random(30));
}
query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player()))
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
			
}

remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
	
}
do_special(owner) {
   if(!random(6)) {
      tell_object(owner, "Your robes shimmer a bit, and then blink back into reality...\n");
    return 1;
   }
}

query_save_flag() { return 0; }
