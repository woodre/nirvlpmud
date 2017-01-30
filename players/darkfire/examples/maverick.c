inherit "/obj/monster";

#include <ansi.h>

/******************************************************************************
 * Program: maverick.c
 * Path: /players/dragnar/WalkingDead/mons
 * Type: Mob
 * Created: June 9th, 2013 by Dragnar
 *
 * Purpose: A high level monster in the WalkingDead area.  Has a much higher
 *          than normal AC/WC, high heal rate, strong spell attack, and
 *          an ability to do range attacks.  If a player runs or wimpies from
 *          the room rounds will be shot at the player doing up to 700 damage.
 *          Another spell on this mob will also make him wander during combat
 *          causing massive damage.  High range damage + high heal rate makes
 *          him a tough mob.  Average coins are < 12k, which is much less
 *          than the allowed 14k. Lots of gear on this mob, but none has
 *          any specials. All standard armor.
 * History:
 *          06/09/2013 - Dragnar
 *            Created
 *          01/18/2014 - Dragnar
 *            Beefed up hps and spell damage, left loot the same.
 ******************************************************************************/
object target;
int shots;

reset(arg) {

  ::reset(arg);
  if(arg) return;
  set_name("maverick");
  set_race("human");
  set_alias("mav");
  set_short("Maverick"+HIBLK+" - Walker Slayer"+NORM);
set_long(
"Maverick is a man in his late twenties or early thirties. He has long\n\
dark brown hair and hazel eyes. He is lean and tall, but muscular, and\n\
looks very capable of doing serious damage if provoked. He would be a\n\
good person to have on your side if a Horde of Walkers was nearby.\n");

  set_gender("male");
  set_level(26);
  set_hp(1400+random(250));
  set_wc(80);
  set_wc_bonus(30);
  set_ac(40);
  set_heal(30,2);
  
  set_aggressive(0);
  set_al(-100);
  
  move_object(clone_object("/players/dragnar/WalkingDead/obj/kill_check"), this_object());
  move_object(clone_object("/players/dragnar/WalkingDead/weap/rem870"), this_object());
  init_command("wield gun");
  move_object(clone_object("/players/dragnar/WalkingDead/armor/swat_vest.c"), this_object());
  init_command("wear vest");
  move_object(clone_object("/players/dragnar/WalkingDead/armor/balaclava.c"), this_object());
  init_command("wear balaclava");
  move_object(clone_object("/players/dragnar/WalkingDead/armor/swat_helmet.c"), this_object());
  init_command("wear helmet");
  move_object(clone_object("/players/dragnar/WalkingDead/armor/bdu_pants.c"), this_object());
  init_command("wear pants");
  move_object(clone_object("/players/dragnar/WalkingDead/armor/boots.c"), this_object());
  init_command("wear boots");
  move_object(clone_object("/players/dragnar/WalkingDead/armor/riot_shield.c"), this_object());
  init_command("wear shield");
  move_object(clone_object("/players/dragnar/WalkingDead/armor/ammo_belt.c"), this_object());
  init_command("wear belt");
  move_object(clone_object("/players/dragnar/WalkingDead/armor/gloves.c"), this_object());
  init_command("wear gloves");
  if( !random(3) )
  	  move_object(clone_object("/players/dragnar/WalkingDead/heals/mons/meth.c"), this_object() );
  
  set_chat_chance(3);
  load_chat("Maverick says: 'This is the last bottle of booze in here and there is\n\
                no way I am sharing it with anyone.'\n");
  load_chat("Maverick pours a shot of whiskey and slams it down.\n");
  load_chat("Maverick turns his head and peers at you. He doesn't look concerned.\n");
  load_chat("Maverick says: 'I've seen things not even booze can make me forget.'\n");
  load_chat("Maverick says: 'The blood on the floor...I put it there.'\n");
  load_chat("Maverick says: 'Walkers aren't bad alone, but when they get in a mob...'\n");
  load_chat("Maverick says: 'The only way to get past a Walker is to\n\
                smell as bad as they do.'\n");
  load_chat("Maverick says: 'If you have the stomach for it, you\n\
                can dismember a Walker corpse.'\n");
  
  set_dead_ob(this_object());
  set_wander_realm("/players/dragnar/WalkingDead/rooms");
  
  add_spell("short_range_attack",
    "\n#MN# $HK$PISTOL WHIPS$N$ you with the butt of his $HK$Remington 870$N$!\n\n",
    "#MN# $HK$PISTOL WHIPS$N$ #TN# with the butt of his $HK$Remington 870$N$!\n",
    20,40-120,"physical", 5 );
  
  add_spell("range_attack",
    "\n\n$HK$#MN# pulls some shells from his ammo belt and loads them into his shotgun.$N$\n\n\n",
    "$HK$#MN# pulls some shells from his ammo belt and loads them into his shotgun.$N$\n",
    4,5,"physical",0, "range_move");
  
}

range_move( object target,object room,int damage ) {
  call_out("wander", 2+random(3));
}


init() {
  ::init();
}

heart_beat() {
    
  ::heart_beat();
  
  if( attacker_ob ) {
    if( !target || target != attacker_ob )
      shots = 4 + random(4);
    target = attacker_ob;
  }
  
  if( target && shots > 0 && find_call_out("range_attack") == -1 ) {
    range_attack();
  }
}

/******************************************************************************
 * Func:    do_range_damage
 * Created: June 9th, 2013 by Dragnar
 *
 * Purpose: Called by the rage_attack function.  Sets the messages and 
 *          determines damage done by ranged shots.  Damage is based on luck,
 *          higher luck means less chance of a more vital area being hit, and
 *          also the serverity of the hit.
 ******************************************************************************/
do_range_damage() {
  string msg, msg1;
  int dam, luck;
  
  if( !target || !environment(target) )
    return;
    
  luck = target->query_attrib( "luc" );
  
  switch( random(luck/4) ) {
    case 0:
      msg = HIR+"eye"+NORM;
      dam = 65;
      break;
    case 1:
      msg = HIC+"neck"+NORM;
      dam = 55;
      break;
    case 2:
      msg = HIG+"chest"+NORM;
      dam = 45;
      break;
    case 3:
      msg = HIB+"thigh"+NORM;
      dam = 40;
      break;
    case 4:
      msg = YEL+"shoulder"+NORM;
      dam = 25;
      break;
    default:
      msg = GRY+"foot"+NORM;
      dam = 20;
      break;
  }
  
  switch( random(luck/4) ) {
    case 0:
      msg1 = HIR+"BL A S  T   E    D"+NORM;
      dam += 35;
      break;
    case 1:
      msg1 = HIR+"torn to shreds"+NORM;
      dam += 30;
      break;
    case 2:
      msg1 = HIY+"wounded deeply"+NORM;
      dam += 25;
      break;
    case 3:
      msg1 = HIY+"wounded"+NORM;
      dam += 20;
      break;
    case 4:
      msg1 = HIG+"hit directly"+NORM;
      dam += 15;
      break;
    case 5:
      msg1 = HIG+"hit"+NORM;
      dam += 10;
    default:
      msg1 = "grazed";
      dam += 5;
      break;
  }
  
  tell_object( target, "You were "+msg1+" in the "+msg+" by a round from Maverick's shotgun!\n");
  tell_room(environment(target), target->query_name()+" is "+msg1+" in the "+msg+" by a round fired from Maverick's shotgun!\n", ({target}) );
  target->hit_player( dam, "physical" ); 
}

/******************************************************************************
 * Func:    range_attack
 * Created: June 9th, 2013 by Dragnar
 *
 * Purpose: Initially called by HB, then call_out as long as mob still has 
 *          shots to fire.  This attack will do damage to a player that has
 *          attacked this mob, but now is in an adjoining room.  This can happen
 *          if the player runs or wimpies, but also the "range_attack" spell
 *          will cause mob to "wander" and move out of the room.  Attack is 
 *          deadly because of the massive damage shots can do as well as the
 *          high heal rate of this mob.  If the player moves 2 rooms away the
 *          range attacks will stop.
 ******************************************************************************/
range_attack() {
  int idx;
  object targ, my_env;
  string room_path;
  string *dest_dir;
  
  if( !target ) {
    return;
  }
  
  my_env = environment();
  
  if( my_env && target &&  !present(target) && shots > 0 ) {
    targ = environment( target );
    dest_dir = my_env->query_dest_dir();
    
    if( targ )
      room_path = file_name( targ );

    /** Ensure sure room_path is absolute **/
    if( room_path[0..0] != "/" )
      room_path = "/" + room_path;
    
    if( room_path && ( idx = member_array(room_path, dest_dir) ) >= 0 ) {
    
      tell_room(my_env, "Maverick fires a round from his shotgun "+dest_dir[idx+1]+" at "+capitalize(target->query_name())+".\n");
      
      /** Ghost check **/
      if( target->query_ghost() ) {
        tell_object( target, "A round fired from Maverick's shotgun passes right through your incorporeal form!\n");
        target = 0;
      }
      else {
        do_range_damage();
      }
      
      shots -= 1;
      if( shots < 1 ) {
        tell_room( my_env, "Maverick pulls some shells from his belt and reloads his shotgun.\n"); 
        target = 0;
      }
    }
    else {
      tell_object( target, "Maverick fires an round at you, but you are just out of range.\n");
      target = 0;
    }
  }
  if( target )
    call_out("range_attack", 3+random(3));
}

monster_died() {
  object corpse;
  object item;
  
  corpse = present( "corpse", environment() );
  if( corpse ) {
    item = present( "kill_check_object", corpse );
    if( item )
      destruct( item );
  }
    return 0; 
}
