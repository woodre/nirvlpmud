/******************************************************************************
 * Program: ball.c
 * Path: /players/coldwind/desert/weapons
 * Type: Weapon
 * Created: 
 *
 * Purpose: Weapon will special wield functions and special that heals the
 *          player wielding the weapon. Thanks to 'FRED' for his big help 
 *          with the short function!
 * History:
 *          
 *          06/12/2003 - Eurale
 *            This healed WAY too much and too often.  Read 
 *            /doc/build/RULES/heals/healing_items and try to keep that in mind 
 *            when coding subsequent items.
 *          05/19/2014 - Dragnar
 *            Added bonus for Mage guild.
 ******************************************************************************/

#include "/players/coldwind/define.h"
inherit "obj/weapon.c";

#define GUILDID "mageobj"
#define BONUS_TYPE "intelligence"
#define BONUS_TYPE2 "evocation"
#define BONUS_AMOUNT 2
#define BONUS_AMOUNT2 1

reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("crystal ball");
set_alias("ashgan's crystal ball");
set_alt_name("ball");
set_long(
"    A cold piece of crystal of the size of an apple and the color of\n"+
"pure water.  Blood red mist swirls softly around the magical ball. \n"+
"Mysterious thoughts invade your mind as you look at it.  The ball to\n"+
"float around you if you try to carry it and floats inches away from\n"+
"the ground if you try to drop it.\n"+NORM);
set_type("exotic");
set_class(19);
set_weight(3);
set_value(4000);
set_hit_func(this_object());
}
short(){
if (wielded) 
{
return 
HIC+"Crystal ball of Intellect "+NORM+"("+NORM+HIR+"held"+NORM+")"+NORM;
}
else {
 return
HIC+"Crystal ball of Intellect "+NORM+"("+NORM+HIR+"floating"+NORM+")"+NORM;

}
}

wield(str) {
if(str!= "ball"){ return 0; }
  ::wield(str);
  if(!present("ball",this_player())) {notify_fail("Try to get it first!\n"); 
  return 0;}

   if(tp->query_attrib("int") < 24)
    {
      write("Crystal ball spins madly as it drains your power...\n"+
	  "The ball floats away!\n");
      tp->add_hit_point(-random(15));
	   tp->add_spell_point(-random(15));
      call_other(tp,"stop_wielding");
      wielded = 0;
      wielded_by = 0;
      return 1;
    }
	if(tp->query_attrib("int") > 16)
    {
      write("Red mist surrounds you, as the crystal rests in your hand...\n"+
	  "You feel tired.\n");
	  tp->add_hit_point(-30-random(40));
	   tp->add_spell_point(-30-random(40));
	   return 1;
	   }
	   return 0;
	  }
weapon_hit(attacker){
int W;
object user;
 if(!attacker || !environment()) return;
user = environment(this_object())->query_name();
W = random(20);
if(W>13)  
if( random(tp->query_attrib("int")) > 18)
  {
      say(HIR+" \n"+
          "                     *\n"+
   ""+RED+"                  ~"+HIR+"*   *"+NORM+RED+"~        \n");
  say(RED+"               ~"+HIR+"*         *"+NORM+RED+"~  \n"+   
          "      ------"+HIR+"-*  "+HIY+"E N E R G Y  "+HIR+"*-"+NORM+RED+"------\n");           
  say(RED+"               ~"+HIR+"*         *"+NORM+RED+"~  \n"+ 
          "                  ~"+HIR+"*   *"+NORM+RED+"~\n"+
          "              "+HIR+"       *\n"+
		  " \n"+
    ""+HIY+"A ball of pure energy hits "+ attacker->query_name() +"."+NORM+"\n");

  write(HIR+" \n"+
          "                     *\n"+
   ""+RED+"                  ~"+HIR+"*   *"+NORM+RED+"~        \n");
  write(RED+"               ~"+HIR+"*         *"+NORM+RED+"~  \n"+   
          "      ------"+HIR+"-*  "+HIY+"E N E R G Y  "+HIR+"*-"+NORM+RED+"------\n");           
  write(RED+"               ~"+HIR+"*         *"+NORM+RED+"~  \n"+ 
          "                  ~"+HIR+"*   *"+NORM+RED+"~\n"+
          "              "+HIR+"       *\n"+
		  " \n"+
  ""+HIY+"A ball of pure energy hits your foe.\n"+NORM);
   this_player()->heal_self(random(3));
  return 8;

   }
if(W>9)  {
  say(HIY+""+user+" releases massive energy into "+ attacker->query_name() +"."+NORM+"\n");

  write(HIY+"Crystal ball releases massive energy into "+ attacker->query_name() +"."+NORM+"\n");

   this_player()->heal_self(1 + random(4));
  return 4;
   }

  return ;
}

count_misses(w) {
  return 1;
}

count_hit_made(w) {
  return 1;
}

query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player())) {
	  present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
    present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2, BONUS_AMOUNT2);
  }
}

remove_guild_bonus()
{
  if(present(GUILDID, this_player())) {
	  present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
    present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2, -BONUS_AMOUNT2);
  }
}
