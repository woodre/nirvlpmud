inherit "/obj/monster";

#include <ansi.h>

#define LOG "/players/dragnar/WasteLands/log/MONS_DEATH"

#include "/players/beck/MortalKombat/MKQuestNPC.c"

/******************************************************************************
 * Program: master.c
 * Path: /players/dragnar/WasteLands/mons
 * Type: Mob
 * Created: 1993 by Dragnar
 *
 * Purpose: A high level monster in the Wastelands area & part of the Wastelands
 *          quest. This mob has a much higher than normal AC, high heal rate, 
 *          strong spell attack, and an ability to do range attacks.  If a 
 *          player runs or wimpies from the room stars will be thrown at the 
 *          player doing up to 400 damage.  Another spell on this mob will 
 *          also knock player out of the room causing massive damage. High 
 *          range damage + high heal rate makes him a tough mob. Average 
 *          coins are 20k.
 *          If the player does not clear the room east of this mob and they
 *          get thrown from the room it is almost certain death because of the
 *          agrro mobs in that room.
 * History:
 *          09/15/2013 - Dragnar
 *            Updated stats, spells, and added special range attack.
 *          12/18/2013 - Dragnar
 *            Updated path for the key for the quest, was causing monster_died
 *            to fail.
 *          07/11/2014 - Dragnar
 *            Tweaked damage slightly so special has higher chance of knocking
 *            player from the room. Added code to deal with clan walls.
 ******************************************************************************/
#define DEBUG 0
 
object target;
int shots;

reset(arg){
   object scar,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("master ninja");
   set_race("human");
   set_alias("ninja");
   set_short("A Master Ninja");
	set_long("This is the master ninja warrior.  He is the keeper of the skills\n" +
	"of the ancients. Since his birth he has been trained to be a pure\n" +
	"Ninja and keep the secret of the forest safe. You will only be able\n"+
   "to gain his knowledge by killing him.\n");
   set_level(29);
   set_hp(1800 + random(400));
   set_al(-random(600));
   set_wc(70);
   set_ac(28);
   set_gender("male");

   set_chat_chance(5);
   load_chat("Ninja whispers: You will not gain the power of passage from me.\n");
   set_a_chat_chance(20);
   load_a_chat("Ninja says: I have bled more and seen victory.\n");
   add_money(10000+random(15000));
   set_dead_ob(this_object());
   set_wc_bonus(30);
   set_heal(40,2);
   
   armor=clone_object("players/dragnar/WasteLands/armor/suit.c");
   weapon=clone_object("players/dragnar/WasteLands/weap/sword.c");
   move_object(armor, this_object());
   move_object(weapon, this_object ());
   scar=clone_object("players/dragnar/MKScar/scar.c");
   move_object(scar, this_object());
  
  add_spell("roundhouse1",
    "\n\n#MN# B L U R S as he does a roundhouse kick that $HR$C R U S H E S$N$ your head!\n\n\n",
    "#MN# B L U R S as he does a roundhouse kick that $HR$C R U S H E S$N$ #TN#'s head!\n",
    15,"90-160","physical", 6, "roundhouse_kick" );

  add_spell("roundhouse2",
    "\n#MN# B L U R S as he does a roundhouse kick that $HY$S L A M S$N$ into your chest!\n",
    "#MN# B L U R S as he does a roundhouse kick that $HY$S L A M S$N$ into #TN#'s chest!\n",
    20,"60-120","physical", 6, "roundhouse_kick" );
    
    
  add_spell("roundhouse3",
    "#MN# B L U R S as he does a roundhouse kick that $HK$CONNECTS$N$ with your torso.\n",
    "#MN# B L U R S as he does a roundhouse kick that $HK$CONNECTS$N$ with #TN#'s torso.\n",
    25,"40-70","physical" );
    
  add_spell("roundhouse4",
    "#MN# B L U R S as he does a roundhouse kick that $G$Bruises$N$ your leg.\n",
    "#MN# B L U R S as he does a roundhouse kick that $G$Bruises$N$ #TN#'s leg.\n",
    40,"30-60","physical" );
}

roundhouse_kick( object target, object room, int damage ) {
  /** Code borrowed from Zeus' Ani **/
  int ran1, i;
  string str;
  object wall;
  string *the_dirs;
  
  if( room && target && damage - target->query_attrib( "str" ) > 110  ) {
    wall = present( "clan_wall_blocker_obj" );
    
    the_dirs = (room->query_dest_dir());
    ran1 = random(sizeof(the_dirs)-1);
    i = ran1 / 2 * 2;
    str = the_dirs[i+1];
    str += "#";
    str += the_dirs[i];
    tell_room( room, "\n\n\n\n"+target->query_name()+" tries to recover but the force of the blow knocks them out of the room!\n" );
    
    if( wall ) {
      destruct( wall );
      tell_room( room, target->query_name()+" flies right through the wall shattering it to pieces!\n" );
      target->hit_player( 50 + random(50) - target->query_attrib( "luc") );
    }
    
    target->move_player(str);
    command( "look", target );
  }
}

monster_died() {
  object key, room;
  
  write_file(LOG, ctime(time())+" "+
    query_attack()->query_real_name()+" killed Master Ninja.\n");
  
  room = environment(this_object());
  if( room ) {
    tell_room( room, "\nNinja cries out: You are a strong warrior.\n\
You are worthy of the power of knowledge. You may enter the ice\n\
caves here and venture into the darkness. But beware, there are\n\
many hideous creatures that were once human waiting for you.\n");
  tell_room( room, "\nThey protect secrets that are hidden within. I am only \n\
here to protect you from the danger, but you have proven your worth.\n\
Go now and find the portal of the past and save this wasteland.\n\n");
  }

  key = clone_object("/players/dragnar/WasteLands/obj/quest/mag3.c");
  move_object(key, this_object());
  return 0; 
}

heart_beat() {
    
  ::heart_beat();
  
  if( attacker_ob ) {
    if( !target || target != attacker_ob )
      shots = 1 + random(4);
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
      msg1 = HIR+"RI P  P   E    D  through"+NORM;
      dam += 35;
      break;
    case 1:
      msg1 = HIR+"sliced to the bone"+NORM;
      dam += 30;
      break;
    case 2:
      msg1 = HIY+"sliced"+NORM;
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
  
  tell_object( target, "You were "+msg1+" in the "+msg+" by a Shuriken thrown by Master Ninja!\n");
  tell_room(environment(target), target->query_name()+" is "+msg1+" in the "+msg+" by a Shuriken thrown by Master Ninja!\n", ({target}) );
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
      
    if( DEBUG ) {
      tell_room( my_env, "Room: "+room_path+"\n" );
      tell_room( my_env, "Dest: " + dest_dir[0]+"\n");
      tell_room( my_env, "Dest: " + dest_dir[1]+"\n");
    }
    
    if( room_path && ( idx = member_array(room_path, dest_dir) ) >= 0 ) {
    
      tell_room(my_env, "Master Ninja throws a Shuriken "+dest_dir[idx+1]+" at "+capitalize(target->query_name())+".\n");
      
      /** Ghost check **/
      if( target->query_ghost() ) {
        tell_object( target, "A Shuriken thrown by Master Ninja passes right through your incorporeal form!\n");
        target = 0;
      }
      else {
        do_range_damage();
      }
      
      shots -= 1;
      if( shots < 1 ) {
        tell_room( my_env, "Master Ninja pulls a Shuriken from his belt and shifts his ready stance.\n"); 
        target = 0;
      }
    }
    else {
      tell_object( target, "Master Ninja throws a Shuriken at you, but you are just out of range.\n");
      target = 0;
    }
  }
  if( target )
    call_out("range_attack", 3+random(3));
}
