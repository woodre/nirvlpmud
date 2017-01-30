inherit "obj/weapon";
/******************************************************************************
 * Program: ww_staff.c
 * Path: /players/dragnar/SevenSpires/weap
 * Type: Weapon
 * Created: October 1, 2014 by Dragnar
 *
 * Purpose: A powerful weapon for magic class guilds. The user gets no
 *          weapon damage and no weapon hit message, but the 
 *          weapon_hit causes the attacker obj to have a negative 
 *          resistance to different magic types. Heavily stat based. 
 *          Max damage should be roughly equal to a high end weapon 
 *          like a Gordie Stick, but is more thematic.  Also has a nice 
 *          mage bonus.
 * History:
 *          10/01/2013 - Gnar
 *            Created
 ******************************************************************************/

 
#include <ansi.h>

#define GUILDID "mageobj"
#define BONUS_TYPE "evocation"
#define BONUS_TYPE2 "conjuration"
#define BONUS_TYPE3 "necromancy"
#define BONUS_TYPE4 "enchantment"
#define BONUS_TYPE5 "illusion"
#define BONUS_AMOUNT 2


int special;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("staff");
  set_class(0);
  set_weight(3);
  set_type("staff");
  SetMultipleIds( ({ "witchwood staff", "witchwood", "no_msg_hit", }) );
 
  set_value( 6000 );
  set_hit_func(this_object());
  set_short( HIBLK+"Witchwood Staff"+NORM );
  set_long( "A hand carved staff made from black witchwood. There are runes\n\
carved through the length of the staff which are so complex you cannot\n\
begin to understand their ancient meaning. A veil of darkness seems to\n\
radiate from the staff with power that flows through you.\n" );

  special = 0;
}

wield(string str)
{
  if(id(str) && present(this_object(), this_player()) &&
    this_player()->query_weapon() == this_object()){
    ::wield(str);
    return 1;
  }
  ::wield(str);
  if(id(str))
  {
    if(!present(this_object(), this_player())) return 0;
    if(this_player()->query_total_stats() >= 210 ) {
      write("The power of the witchwood staff sends a jolt of magic coursing through your body.\n");
      say(capitalize(this_player()->query_name())+" shudders as "+this_player()->query_pronoun()+" grasps the witchwood staff.\n");
      special = 1;
    }

    return 1;
  }
}

weapon_hit(object attacker) {
  int mag, amt;
  object owner;
  mixed *armor_params;
  
  owner = environment();

  if( !owner || !attacker || !special )
    return;
  
  mag = owner->query_attrib( "mag" );
  
  /** Need to randomize && ENSURE STACKING FROM MULTIPLE WEPS NOT POSSIBLE **/
  if( mag ) {
  
    armor_params = attacker->QueryArmor( this_object() );
    if( armor_params ) {
      mag /= 2;
      tell_object( owner, "weapon_hit: "+armor_params[2]+"\n");
      amt = armor_params[2] - mag/4;
      if( amt < -mag )
        amt = -mag;
      if( amt < armor_params[2] )
        attacker->RegisterArmor(this_object(), ({ "magical", 0, amt, 0 }) );
    }
    else { 
      tell_object( owner, "weapon_hit: "+armor_params+"\n");
      attacker->RegisterArmor(this_object(), ({ "magical", 0, -5, 0 }) );
    }
  }
  return 0;
}

query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player()))
  {
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2, BONUS_AMOUNT);
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE3, BONUS_AMOUNT);
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE4, BONUS_AMOUNT);
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE5, BONUS_AMOUNT);
   }
}

remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
  {
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2,-BONUS_AMOUNT);
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE3,-BONUS_AMOUNT);
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE4,-BONUS_AMOUNT);
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE5,-BONUS_AMOUNT);
  }
}


query_wear() {
  return 1;
}

weapon_breaks() {
  return 1;
}
