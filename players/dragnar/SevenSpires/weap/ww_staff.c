inherit "obj/weapon";
/******************************************************************************
 * Program: ww_staff.c
 * Path: /players/dragnar/SevenSpires/weap
 * Type: Weapon
 * Created: October 1, 2014 by Dragnar
 *
 * Purpose: An interesting weapon for magic class guilds. The user gets no
 *          weapon damage and no weapon hit message, but the 
 *          weapon_hit causes the attacker obj to have a negative 
 *          resistance to different magic types. Heavily stat based. 
 *          Max damage should be roughly equal to a high end weapon 
 *          like a Gordie Stick, but is more thematic.  Also has a nice 
 *          mage bonus.
 *    NOTE: Soulbound obj, can only be wielded by the person that killed the
 *          mob that has this weapon.
 * History:
 *          10/01/2014 - Gnar
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

#define RCOLOR "RCOLOR"

int special;
string dtype;
string soulbinder;
mapping dtype_matrix;

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
radiate from the staff with power that flows into you.\n" );

  special = 0;
  dtype_matrix = ([ "magical" :       ({ "Magic", RCOLOR }) 
                   ,"other|fire":     ({ "Fire", HIR }) 
                   ,"other|ice":      ({ "Ice" , HIB }) 
                   ,"other|evil":     ({ "Evil" , RED }) 
                   ,"other|good":     ({ "Good" , HIW }) 
                   ,"other|light":    ({ "Light" , HIY }) 
                   ,"other|dark":     ({ "Dark" , HIK }) 
                   ,"other|poison":   ({ "Poison" , HIG }) 
                   ,"other|electric": ({ "Electric" , YEL }) 
                   ,"other|sonic":    ({ "Sonic" , HIM }) ]);
}

set_dtype() {
  int i;
  string* dtypes;
  
  if( !dtype ) {
    dtypes = m_indices(dtype_matrix);
    if( !dtypes || sizeof(dtypes) < 1 )
      return;
    
    dtype = dtypes[random(sizeof(dtypes))];
  }
  dtype = "magical";
}

string dtype_color(string str) {
  string msg;
  int x;
  
  /** Magic is a random color **/
  if( str == RCOLOR ) {
    if( !random(4) )
      msg = BLINK;
    else
      msg = NORM;
    
    x = random(10);
    if(x == 0) msg += HIR; else
    if(x == 1) msg += HIG; else
    if(x == 2) msg += HIY; else
    if(x == 3) msg += HIB; else
    if(x == 4) msg += HIM; else
    if(x == 5) msg += HIC; else
    if(x == 6) msg += BLU; else
    if(x == 7) msg += RED; else
    if(x == 8) msg += HIK; else
    msg += HIW;
  }
  else
    msg = str;
  
  return msg;
}

wield(string str)
{
  if(id(str)) {
    if(!present(this_object(), this_player())) 
      return 0;
/*
    if( this_player()->query_real_name() != soulbinder ) {
      write("You can't bear to wield the power of this weapon.\n");
      return 1;
    }
*/
    if(this_player()->query_total_stats() >= 210 ) {
      write("The power of the witchwood staff sends a jolt of magic coursing through your body.\n");
      say(capitalize(this_player()->query_name())+" shudders as "+this_player()->query_pronoun()+" grasps the witchwood staff.\n");
      special = 1;
      set_dtype();
    }
    return ::wield(str);
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
  
  /** ENSURE STACKING FROM MULTIPLE WEPS NOT POSSIBLE **/
  if( mag ) {
  
    if( !dtype )
      set_dtype();
    
    armor_params = attacker->QueryArmor( this_object() );
    if( armor_params ) {
      mag /= 2;
      tell_object( owner, "weapon_hit: "+armor_params[2]+"\n");
      amt = armor_params[2] - mag/4;
      if( amt < -mag )
        amt = -mag;
      if( amt < armor_params[2] )
        attacker->RegisterArmor(this_object(), ({ dtype, 0, amt, 0 }) );
    }
    else { 
      tell_object( owner, "weapon_hit: "+armor_params+"\n");
      attacker->RegisterArmor(this_object(), ({ dtype, 0, -5, 0 }) );
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

query_short() {
  string msg;
  msg = ::query_short();
  if( dtype )
    msg += HIK+" ["+NORM+ dtype_color(dtype_matrix[dtype][1])+"*"+NORM+HIK+"]"+ NORM;
  
  return msg;
}

long() {
  ::long();
  if( soulbinder )
    write("This weapon is soulbound to "+capitalize(soulbinder)+".\n");
  if( dtype && this_player() && this_player()->query_level() > 60 )
    write("<dtype>: "+dtype+"\n");
}

set_binder( string str ) { soulbinder = str; }
query_binder() { return soulbinder; }

string locker_arg() {
  return "|dtype|"+dtype+"|soulbinder|"+soulbinder+"";
}

void locker_init(string arg) {
  string s1, s2;
  sscanf(arg, "|dtype|%s|soulbinder|%s", s1, s2);
  dtype = s1;
  set_dtype();
  soulbinder = s2;
}

status restore_thing(string arg) {
  restore_object(arg);
  return 1;
}

status save_thing(string arg) {
  save_object(arg);
  return 1;
}
