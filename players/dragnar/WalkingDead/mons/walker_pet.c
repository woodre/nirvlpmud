#include <ansi.h>
#include "../defs.h"

inherit "/obj/monster";

/******************************************************************************
 * Program: walker.c
 * Path: /players/dragnar/WalkingDead/mons
 * Type: Mob
 * Created: October 19th, 2016 by Dragnar
 *
 * Purpose: A special walker mob that will grow over time if it is not killed.
 *          It will cap out at level 30. This walker is not tracked by the
 *          area daemon.
 * History:
 *          10/19/2016 - Gnar
 *            Created
 ******************************************************************************/
int walker_level;
int timestamp;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  
  if( !restore_object( get_save_path() ) )
  {
    walker_level = WALKER_START + 3;
    /* Static walker information is set here */
    reset_walker_ids();
    set_race("human");
    set_long("A Walking Dead.");

  
    set_aggressive(0);
    set_al(-1000);
  
    move_object(clone_object("/players/dragnar/WalkingDead/obj/kill_check"), this_object());
    msgin = "shambles in";
    msgout = "stumbles";
    message_hit=({
        "eviscerates"," with a vicious slash",
        "bites"," with a sound of tearing flesh",
        "gouges"," very deeply",
        "gouges"," deeply",
        "gashes","",
        "wounds","",
        "scratches",""
    });
    set_wander_realm("/players/dragnar/WalkingDead/rooms");
  
  }  
  else {
    /** set level based on time since it was killed **/
    walker_level = WALKER_START + 3 + ( ( time() - timestamp)  / 28880 );
    if( walker_level > 30 )
      walker_level = 30; 
  }
  set_dead_ob(this_object());
  set_walker_stats();

}

string get_save_path() {
  int i;
  string save_path;
  string *path;
  
  path = explode( basename( this_object() ), "/" );
  i = sizeof(path) - 1;
  if( i > 0 ) {
    /** expand the array by 1 by repeating the last entry **/
    path += ({ path[i] });
    /** replace the previous entry with save **/
    path[i] = "save";
  }
  save_path = implode( path, "/" );
  return save_path;
}

status player_filter( object ob ) {
  return (status) ob->is_player() && ob->query_level() < 20 && !present("walker_guts", ob);
}

heart_beat() { 
  object *players;
  object env;
  
  ::heart_beat();
  
  env = environment();
  
  if( env && !random(9) ) {   
    if( !attacker_ob || !present(attacker_ob, environment()) ) {
#ifndef __LDMUD__ 
  players = filter_array(all_inventory( env ), "player_filter", this_object() );
#else
  players = filter(all_inventory( env ), "player_filter" );
#endif
      if( sizeof(players) > 0 )
        attack_object( players[random(sizeof(players))] );
      
    }
  }
}

set_walker_stats() {
  int lev_diff, level, wc, hp, ac, heal_amt, spell_dam, alt_dam_flag;
  string name;
  string longstr;
  
  lev_diff = walker_level - WALKER_START;
  
  level = walker_level;

  wc = 30 + lev_diff * 5;
  hp = 500 + (lev_diff * 250) + random(lev_diff * 20) + random(50);
  ac = 17 + lev_diff * 4;
  heal_amt = 20 + lev_diff * 6;
  spell_dam = 20 + lev_diff * 22;
  /* random alt attack */
  alt_dam_flag = 1 + random(7);
  
  if( walker_level == WALKER_START ) {
    name = "walker";
    if( !random(2) )
      set_gender("male");
    else
      set_gender("female");
  }
  
  switch( lev_diff ) {
    case 0:
      set_short("A Walking "+HIBLK+"Dead"+NORM);
      /* No alt attack */
      alt_dam_flag = 0;
      break;
    case 1:
      set_short("A Pair of "+HIBLK+"Walking Dead"+NORM);
      add_walker_id( "pair" );
      name = "pair of walkers";
      /* No alt attack */
      alt_dam_flag = 0;
      gender = 0;
      break;
    case 2:
      set_short("A Trio of "+HIBLK+"Walking Dead"+NORM);
      add_walker_id( "trio" );
      name = "trio of walkers";
      gender = 0;
      break;
    case 3:
      set_short("A Small Group of "+HIBLK+"Walking Dead"+NORM);
      add_walker_id( "group" );
      add_walker_id( "small group" );
      name = "small group of walkers";
      gender = 0;
      break;
    case 4:
      set_short("A "+HIBLK+"Large Group "+NORM+"of "+HIBLK+"Walking Dead"+NORM);
      add_walker_id( "group" );
      add_walker_id( "large group" );
      name = "large group of walkers";
      gender = 0;
      break;
    case 5:
      set_short("A "+RED+"Swarm "+NORM+"of "+HIBLK+"Walking Dead"+NORM);
      add_walker_id( "swarm" );
      name = "swarm of walkers";
      gender = 0;
      break;
    case 6:
      set_short("A "+HIR+"Horde "+NORM+"of "+HIBLK+"Walking Dead"+NORM);
      add_walker_id( "horde" );
      name = "horde of walkers";
      gender = 0;
      break;
    case 7:
      set_short("An enlarged "+HIR+"Horde "+NORM+"of "+HIBLK+"Walking Dead"+NORM);
      add_walker_id( "horde" );
      name = "enlarged horde of walkers";
      gender = 0;
      break;
    case 8:
      set_short("A medium sized "+HIR+"Horde "+NORM+"of "+HIBLK+"Walking Dead"+NORM);
      add_walker_id( "horde" );
      name = "medium sized horde of walkers";
      gender = 0;
      break;
    case 9:
      set_short("A "+HIW+"Large "+HIR+"Horde "+NORM+"of "+HIBLK+"Walking Dead"+NORM);
      add_walker_id( "horde" );
      name = "large horde of walkers";
      gender = 0;
      break;
    default:
      set_short("A "+HIR+"Massive Horde "+NORM+"of "+HIBLK+"Walking Dead"+NORM);
      add_walker_id( "horde" );
      name = "massive horde of walkers";
      gender = 0;
      break;
  }
  
  set_name( name );

  
  longstr = "A Walking Dead Zombie straight from your nightmares. The dead milky\n\
eyes, rotten stink, exposed tissues, and unending appetite for human\n\
flesh are there but more terrifying than you ever realized. Every\n\
instinct inside you is screaming for you to run from this creature.\n";
  if( query_walker_size() > 1 )
    longstr += "This is a mob of "+HIW+ query_walker_size() +NORM+" walkers.\n";

  set_long( longstr );

  set_level( level );

  set_hp( hp );
  set_wc( wc );
  set_wc_bonus( lev_diff );
  set_ac( ac );
  set_heal(heal_amt, 3);

  /* Reset spells so we can increase damage */
  remove_spell("bite");
  remove_spell("tackle");
  
  add_spell("bite",
    "\n#MN# lunges suddenly and $R$ B I T E S$N$ you!\n\n",
    "#MN# lunges suddenly and $R$B I T E S$N$ #TN#!\n",
    25,spell_dam,"physical",alt_dam_flag);
  add_spell("tackle",
    "#MN# jumps at you and $HK$tackles$N$ you to the ground!\n",
    "#MN# jumps at #TN# and $HK$tackles$N$ them to the ground!\n",
    15,spell_dam,"physical",alt_dam_flag);
}

transfer_inventory(object mob1, object mob2 ) {
  int i, size;
  object *inv;
  
  inv = all_inventory( mob1 );
  for( i=0, size = sizeof(inv); i < size; i++ ) {
    if( inv[i]->id("kill_check_object" ) )
      destruct(inv[i]);
    else
      move_object(inv[i], mob2 );
  }
}

monster_died() {
  object corpse, corpse1;
  object room;
  object treasure;
  string tmp;

  /** Save the status of the mob **/
  if( attacker_ob && attacker_ob->query_level() < 20 ) {
    timestamp = time();
    save_object( get_save_path() );
  }

  room = environment(this_object());
  corpse1 = present( WALKER_CORPSE, environment());
  
  corpse = clone_object("/players/dragnar/WalkingDead/obj/corpse");
  corpse->set_name(name);
  corpse->set_level(level);
  corpse->set_mhp(max_hp);
  corpse->set_ac(armor_class);
  corpse->set_wc(weapon_class);

  if( corpse1 ) {
    transfer_inventory(corpse1, corpse);
    corpse->set_exp_worth( corpse1->query_exp_worth() );
    destruct(corpse1);
  }

  if((tmp=this_object()->query_corpse_name()))
    corpse->add_id(tmp);
  if((tmp=this_object()->query_corpse_short()))
    corpse->set_short(tmp);
  if((tmp=this_object()->query_corpse_long()))
    corpse->set_long(tmp);
  move_object(corpse, room);

  /** Extra gear cloned for bigger mob not handled by daemon **/
  treasure = clone_object("/players/dragnar/WalkingDead/obj/walker_obj");
  switch( walker_level ) {
    case 27:
      treasure->set_value_tier( 2 );
      break;
    case 28:
      treasure->set_value_tier( 3 );
      break;
    case 29:
      treasure->set_value_tier( 4 );
      break;
    case 30:
      treasure->set_value_tier( 5 );
      break;
    default:
      treasure->set_value_tier( 1 );
      break;
  }
  treasure->set_object_stats();
  move_object( treasure, corpse );

  tell_room(room,
    "As the "+name+" collapses, blood pours into the ground.\n");

  return 0; 
}

/******************************************************************************
 * Func:    move_me
 * Created: Jan 14th, 2014 by Dragnar
 *
 * Purpose: Called by catch_tell when the Walker is following a player from the
 *          room. Code borrowed from monster.c wander() function to check and
 *          ensure that the Walker does not follow a player outside of the
 *          intended area.
 ******************************************************************************/
int
move_me( string dir ) {
  int i;
  string *dest_dir;
  string tmp;
  
  if(!this_object() || !environment()) return 1;

  /* wander_realm is required! */
  if(!wander_realm) return 1;

  dest_dir = (string *) environment()->query_dest_dir();
  
  /** Ensure direction is a valid room exit **/
  i = member_array( dir, dest_dir );
  
  if( i > 0 ) {
    /** Ensure direction is in the wander realm **/
    if(sscanf(dest_dir[i-1], wander_realm+"%s", tmp) == 1) {
      call_out( "do_move_me", 1+random(3), dir );
	  }
  }
  
}

void 
catch_tell(string str) {
  string *dir;
  string who, where, junk;
  
  if( sscanf( str, "%s leaves %s.\n",who, where) == 2) {
	dir = explode( where, " " );
	where = dir[ sizeof( dir ) - 1 ];
    if(!attacker_ob || (string) attacker_ob->query_name() == who )
        move_me( where ); 
  }
}

void
do_move_me( string dir ) {
  command(dir); 
}

add_walker_id( string id ) {
  multipleIds += ({ id });
}

reset_walker_ids() {
  SetMultipleIds( ({ "walker", "undead", "zombie", "biter", "geek", "dead", "walking dead" }) );
}

add_walker_level(int amt) { 
  if( !amt )
    walker_level++;
  else
    walker_level += amt;

  set_walker_stats();
}

del_walker_level(int amt) { 
  if( !amt )
    walker_level--;
  else
    walker_level -= amt;
  set_walker_stats();
}

set_walker_level(int i) { 
  walker_level = i;
  set_walker_stats();
}

query_walker_level() { return walker_level; }

query_walker_size() { 
  return query_walker_level() - WALKER_START + 1; 
}

query_corpse_name() {
  return WALKER_CORPSE;
}
