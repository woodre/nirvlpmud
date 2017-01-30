inherit "/obj/monster";

#include <ansi.h>

/******************************************************************************
 * Program: oakley.c
 * Path: /players/dragnar/WalkingDead/mons
 * Type: Mob
 * Created: June 9th, 2013 by Dragnar
 *
 * Purpose: A high level monster in the WalkingDead area.  Has a much higher
 *          than normal AC/WC, insane heal rate, strong spell attack, and
 *          an ability to do range attacks.  If a player runs or wimpies from
 *          the room arrows will be shot at the player doing up to 700 damage.
 *          Another spell on this mob will also make him wander during combat
 *          causing the range attacks to occur. Range attacks will only work
 *          when the player is in an ajoining room to this mob. Range damage 
 *          + high heal rate makes him a tough mob.  Average coins are < 21000, 
 *          which is much less than the allowed 30k.  Max coins are only given 
 *          if gear is sold in area's shop, which is a hazardous area.
 * History:
 *          06/09/2013 - Dragnar
 *            Created
 *          01/18/2014 - Dragnar
 *            Reduced heal rate slightly, was almost impossible to kill.
 ******************************************************************************/
object target;
int arrows;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("oakley");
  set_race("human");
  set_alias("oak");
  set_short("Oakley"+HIBLK+" - Walker Slayer"+NORM);
set_long(
"Oakley is a good looking young man in his  early to middle\n\
twenties. He is slightly taller than average with blond hair.\n\
He seems like a normal guy at first glance, but there seems to be\n\
something dangerous about the way he moves. His eyes confirm that\n\
he is not someone to be messed with, they are cold and hard.  He\n\
is a survivor, and he is ready to face anything.\n");

  set_gender("male");
  set_level(29);
  set_hp(1800 + random(400));
  set_wc(75);
  set_wc_bonus(30);
  set_ac(50);
  set_heal(35,2);
  
  set_aggressive(0);
  set_al(-1);
  
  move_object(clone_object("/players/dragnar/WalkingDead/obj/kill_check"), this_object());
  move_object(clone_object("/players/dragnar/WalkingDead/armor/kevlar_shirt"), this_object());
  init_command("wear shirt");
  move_object(clone_object("/players/dragnar/WalkingDead/weap/spyder"), this_object());
  init_command("wield bow");
  if( !random(2) )
  	  move_object(clone_object("/players/dragnar/WalkingDead/heals/mons/meth.c"), this_object() );
  else
    move_object(clone_object("/players/dragnar/WalkingDead/heals/mons/percocet.c"), this_object());
  
  set_dead_ob(this_object());
  set_wander_realm("/players/dragnar/WalkingDead/rooms");
  
  set_chat_chance(3);
  load_chat("Oakley says: 'If you want to learn about Walkers, go talk to Mav\n\
              or AJ, I am not in a talking mood.'\n");
  load_chat("Oakley stares out the window.\n");
  load_chat("Oakley says without looking at you: 'You need something stranger?'\n");
  load_chat("Oakley says: 'I suspect one of the guards is up to something, if\n\
              if you notice anything let me know.'\n");
  
  add_spell("short_range_attack",
    "\n#MN# pulls an $HK$arrow$N$ from his quiver and $HR$I M P A L E S$N$ you with the deadly point!\n\n",
    "#MN# pulls an $HK$arrow$N$ from his quiver and $HR$I M P A L E S$N$ #TN# with the deadly point!\n",
    15,"50-160","physical", 5 );
  
  add_spell("range_attack",
    "\n\n$HR$#MN# pulls an $HK$arrow$HR$ from his quiver and nocks it to his bow string.$N$\n\n\n",
    "$HR$#MN# pulls an $HK$arrow$HR$ from his quiver and nocks it to his bow string.$N$\n",
    4,10,"physical",0, "range_move");
  
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
      arrows = 4 + random(4);
    target = attacker_ob;
  }
  
  if( target && arrows > 0 && find_call_out("range_attack") == -1 ) {
    range_attack();
  }
}

/******************************************************************************
 * Func:    do_range_damage
 * Created: June 9th, 2013 by Dragnar
 *
 * Purpose: Called by the rage_attack function.  Sets the messages and 
 *          determines damage done by ranged arrows.  Damage is based on luck,
 *          higher luck means less chance of a more vital area being hit, and
 *          also the severity of the hit.
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
      msg1 = HIR+"PU N  C   H    E      D  through"+NORM;
      dam += 35;
      break;
    case 1:
      msg1 = HIR+"punctured"+NORM;
      dam += 30;
      break;
    case 2:
      msg1 = HIY+"hit to the bone"+NORM;
      dam += 25;
      break;
    case 3:
      msg1 = HIY+"hit very deep"+NORM;
      dam += 20;
      break;
    case 4:
      msg1 = HIG+"hit deep"+NORM;
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
  
  tell_object( target, "You were "+msg1+" in the "+msg+" by an arrow from Oakley's bow!\n");
  tell_room(environment(target), target->query_name()+" is "+msg1+" in the "+msg+" by an arrow fired from Oakley's bow!\n", ({target}) );
  target->hit_player( dam, "physical" ); 
}

/******************************************************************************
 * Func:    range_attack
 * Created: June 9th, 2013 by Dragnar
 *
 * Purpose: Initially called by HB, then call_out as long as mob still has 
 *          arrows to fire.  This attack will do damage to a player that has
 *          attacked this mob, but now is in an adjoining room.  This can happen
 *          if the player runs or wimpies, but also the "range_attack" spell
 *          will cause mob to "wander" and move out of the room.  Attack is 
 *          deadly because of the massive damage arrows can do as well as the
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
  
  if( my_env && target &&  !present(target) && arrows > 0 ) {
    targ = environment( target );
    dest_dir = my_env->query_dest_dir();
    
    if( targ )
      room_path = file_name( targ );

    /** Ensure sure room_path is absolute **/
    if( room_path[0..0] != "/" )
      room_path = "/" + room_path;
    
    if( room_path && ( idx = member_array(room_path, dest_dir) ) >= 0 ) {
    
      tell_room(my_env, "Oakley looses an arrow "+dest_dir[idx+1]+" at "+capitalize(target->query_name())+".\n");
      
      /** Ghost check **/
      if( target->query_ghost() ) {
        tell_object( target, "An arrow fired from Oakley's bow passes right through your incorporeal form!\n");
        target = 0;
      }
      else {
        do_range_damage();
      }
      
      arrows -= 1;
      if( arrows < 1 ) {
        tell_room(my_env, "Oakley quickly grabs another arrow and starts to nock it to his bow string.\n" );
        target = 0;
      }
    }
    else {
      tell_object( target, "Oakley fires an arrow at you, but you are just out of range.\n");
      target = 0;
    }
  }
  if( target ) {
    call_out("range_attack", 3+random(3));
  }
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
