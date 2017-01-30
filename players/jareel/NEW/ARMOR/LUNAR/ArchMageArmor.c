/* Snows Arch Mage Robes Gives +'s to many more stats with no draw backs, this has a net of only 2 +'s the energy return 
will only happen when you take hits and with Mimage this will not happen often.  Not sure this will be a goto item for a 
mage but it is a cool option. */

#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

#define GUILDID "mageobj"
#define BONUS_TYPE "evocation"
#define BONUS_TYPE2 "power"
#define BONUS_TYPE3 "will"
#define BONUS_TYPE4 "enchantment"
#define BONUS_TYPE5 "wisdom"
#define BONUS_AMOUNT  4 
#define BONUS_AMOUNT2 2
#define BONUS_AMOUNT3 2
#define BONUS_AMOUNT4 2
#define BONUS_AMOUNT5 2
inherit "obj/armor";

     reset(arg) {
       ::reset(arg);

     set_name("robes");
     set_ac(0); /* No AC Will have a Return rather than an AC */
	 set_res(4); /* Same as WarpStone Armor */
     set_value(4200);
     set_weight(1); /* Light Robes */
     set_type("armor");
     set_short(RED+"Arch Mage Robes"+NORM+" of the "+HIR+"["+HIK+"Crater Makers"+NORM+RED+"]"+NORM);
     set_long(
       "A swirling red and white crystal encrusted in a soft golden polished metal.  Raw energy\n"+
       "pulsates within the amulets core crystal.  A thick gold chain allows the amulet to be worn\n"+
       "a persons neck.  This does not look like it would provide much protection\n");

}


query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player()))
  {
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2, BONUS_AMOUNT2);
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE3, BONUS_AMOUNT3);
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE4, -BONUS_AMOUNT4);
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE5, -BONUS_AMOUNT5);                            
   }
}

remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
  {
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2,-BONUS_AMOUNT2);
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE3,-BONUS_AMOUNT3);
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE4, BONUS_AMOUNT4);
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE5, BONUS_AMOUNT5);    
  }
}

do_special(ob){
   object me;
   object att; 
   att = ATT;
   att = ATT; if (!att) return; /* See above */
   me = worn_by;
   if(!me) me = environment();
   if(!me) return;
   if(!living(me)) return;
   if(!ob) return;
   if(!random(3)){ /* High Special is Due to Main Armor having no AC Value With just a Spell point return */
tell_object(USER,
BOLD+RED+"You are surrounded by a crimson aura.\n"+NORM);
tell_room(environment(USER),
BOLD+RED+CAP(USER->query_name())+" is surrounded by a Crimson aura."+NORM+"\n", ({ USER }) );
ATT->add_spell_point(-15+random(15)); /* Only works against other players so is a PK weapon like LifeBlood*/
USER->add_spell_point(5+random(5));
return 0;}
return 0;}


