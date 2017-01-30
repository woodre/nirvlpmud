inherit "obj/monster";

#include <ansi.h>

/******************************************************************************
 * Program: robot.c
 * Path: /players/wicket/ninja_turtles/mobs
 * Type: Mob
 * Created: August 19, 2014 by Wicket/Dragnar
 *
 * Purpose: A mid level mob that is called by donatello to assist him during
 *          fights.
 * History:
 *          08/27/2014 - Gnar
 *            Created
 ******************************************************************************/
int forcefield;
object target;

reset(arg){
  ::reset(arg);
  if(arg) return;
  
  set_name("robot");
  set_race("machine");
  SetMultipleIds( ({ "robot", "machine", "robot warrior", "donatello's robot warrior", "donnie_robot", }) );
  set_short("Donatello's Robot Warrior");
  set_long("A masterfully crafted machine created by Donatello in order to\n\
protect the turtles from the forces of evil.\n");
  set_level(20);
  set_hp(800);
  set_al(0);
  set_wc(75);
  set_ac(50);
  /** Bonus for rockets fired in rocket_spell and chance of extra dmg upon death **/
  set_wc_bonus(30);
  /** AC bonus for forcefield **/
  set_ac_bonus(30);
  add_spell( "rockets",
    "\nCompartments open in the robot's shoulder and $HR$rock$HY$ets$N$ speed toward you!\n",
    "Compartments open in the robot's shoulder and $HR$rock$HY$ets$N$ fly at #TN#!\n",
    30, 10, "other|fire", 6, "rocket_spell");
  add_spell( "forcefield", 0, 0, 15, 0, 0, 0, "forcefield_spell" );
  set_dead_ob(this_object());
}

move_to_target(int stage ) {
  object who;

  if( !target )
    who = find_living("donatello");
  else
    who = target;

  if( !who || !environment(who) )
    return;

  if( stage == 1 ) {
    tell_room( environment(), "The robot's "+HIR+"rock"+HIY+"et "+HIR+"boost"+HIY+"er"+NORM+" fires and it launches skyward.\n");    
    move_object( this_object(), "/room/void" );
    call_out( "move_to_target", 5+random(10) );
  }
  else {
    move_object( this_object(), environment(who) );
    tell_room( environment(), "In a cloud of "+HIBLK+"smoke"+NORM+" the robot lands in the room and disengages it's rocket booster.\n");
  }
     
}

heart_beat() {
  object don;

  ::heart_beat();

  if( !environment() )
    return;

  /** Always hit target **/
  if( target && environment(target) ) {
    if( present(target, environment()) ) {
      if( attacker_ob && !attacker_ob != target )
        attacker_ob = target;
      if( !attacker_ob && !random(3) )
        attacker_ob = target;
    }
    else {
      if( find_call_out( "move_to_target" ) == -1 ) 
        move_to_target( 1 );
    }
  }
  else {
    don = find_living("donatello");
    if( !don || !environment(don) ) {
        tell_room( environment(), "The robot self destructs in a "+HIR+"fir"+HIY+"ey"+HIR+" explos"+HIY+"ion"+NORM+"!\n");
        destruct( this_object() );
        return;
    }
    if( don && !present("donatello", environment()) ) {
      if( find_call_out( "move_to_target" ) == -1 ) 
        move_to_target( 1 );    
    }
  }

}

long() {
  ::long();
  if( forcefield )
    write(query_name()+ " is enveloped by a "+YEL+"feint yellow field."+NORM+"\n");
}

void drop_forcefield() {
  forcefield = 0;
  set_res( 0 );
  if( environment() )
    tell_room( environment(), "\nThe "+YEL+"feint yellow field"+NORM+" enveloping the robot dissipates.\n");
  
}
void forcefield_spell( object target, object room, int damage) {
  if( forcefield || !room )
    return;
  forcefield = 1;
  tell_room( room, "\nA "+YEL+"feint yellow field"+NORM+" envelops the robot.\n");
  set_res( 100 );
  call_out("drop_forcefield", 20+random(10) );
}

void rocket_spell( object target, object room, int damage) {
  int luc, i;
  if( target ) {
    luc = (int) target->query_attrib("luc");
    i = (60 - luc) / 10;
    /** Shoot a number of rockets at the player depending on luck stat **/
    for( ;i > 0; i-- ) {
      tell_room( room, "\tA "+HIR+"rock"+HIY+"et"+NORM+" slams into "+target->query_name()+"!\n");
      target->hit_player( 25, "other|fire" );
    }
  }
}

monster_died() {
  if( !random(4) ) {
    object corpse;
    if( attacker_ob ) {
      corpse = present("corpse", environment());
      if( corpse )
        destruct( corpse );
      tell_room( environment(), "\n\nThe robot "+HIR+BLINK+"SELF DESTRUCTS"+NORM+" causing shrapnel to fly around the room!\n\n");
      attacker_ob->hit_player( 50 + random(150), "physical" );
    }
  }
}

set_target( object ob ) { target = ob; }
query_target() { return target; }
