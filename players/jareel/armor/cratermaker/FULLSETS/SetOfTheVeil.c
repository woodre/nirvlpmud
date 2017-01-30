/* Combining the 4 armor Pieces makes them only cover 3 slots Belt, Gloves Boots The ring slot enchants the gear 
and is where you get the bonus stats from that and the 80k you invest along with the time.  This is a part of
a recipe for another crafted set also so this is a tier two piece of armor */

#include "/players/jareel/define.h"
#define ATT USER->query_attack()
#define USER environment(this_object())

#define GUILDID         "mageobj"
#define BONUS_TYPE      "power"
#define BONUS_AMOUNT    2 /* +6 Non the tier 2 set gives a small bonus for Necro  */
inherit "/obj/armor.c";

void reset(status arg)
{
   ::reset(arg);
   
   set_name("necromancer");
   set_ac(0);
   set_res(3); /* +1 for each armor slot  major upgrade will keeping with the armor to this stage in the evolution*/
   set_value(80000);
   set_weight(1);  /* Magic Ment for Mage Use */
   set_types( ({"earring", "bracelet", "amulet", }) );
   set_short(
"Dark "+BOLD+BLK+"Amulet"+NORM+" of the Mana ("+HIG+"Full Set Power"+NORM+")\n\
Dark "+BOLD+BLK+"Earring"+NORM+" of Mana ("+HIG+"Full Set of Power"+NORM+")\n\
Dark "+BOLD+BLK+"Bracelet"+NORM+" of Mana ("+HIG+"Full Set of Power"+NORM+")\n\
   ");
   set_long("\
      "+HIG+"Full Set of Power"+NORM+"       \n\
      The Full Set is finely crafted magical golden gear  It's a very rare\n\
      and powerful armor that requires the accumulation of its components\n\
      and then having them forged into one set.  Few ever see this armor,\n\
      far fewer possess it.\n");
}

status id(string arg)
{
   return ( ::id(arg) || arg == "fullplate"
      || arg == "amulet"
      || arg == "earrings"
      || arg == "bracelet"
      || arg == "full set"
      || arg == "full set power"
      || arg == "mana"
      || arg == "mana set");
}

string short() {

  if ((status)this_object()->query_worn())
    return("Dark "+BOLD+BLK+"Amulet"+NORM+" of Mana ("+HIG+"Full Set of Power"+NORM+") (worn)\n Dark "+BOLD+BLK+"Earring"+NORM+" of Mana ("+HIG+"Full Set of Power"+NORM+") (worn)\n Dark "+BOLD+BLK+"Bracelet"+NORM+" of Mana ("+HIG+"Full Set of Power"+NORM+") (worn)\n");

  return("Dark "+BOLD+BLK+"Amulet"+NORM+" of Mana ("+HIG+"Full Set of Power"+NORM+")\n Dark "+BOLD+BLK+"Earring"+NORM+" of Mana ("+HIG+"Full Set of Power"+NORM+")\n Dark "+BOLD+BLK+"Bracelet"+NORM+" of Mana ("+HIG+"Full Set of Power"+NORM+")\n");
}


int query_save_flag() { return 0; }

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

     do_special(owner)    {
        int i;
          i = random(3);
        if(i==1){
         tell_room(environment(USER),
         ""+BOLD+" <<>>"+RED+"Power returns to "+environment()->query_name()+"'s body "+NORM+BOLD+"<<>>\n"+NORM);
		 USER->add_spell_point(15+random(15));
             return 0;}
             return 0;}