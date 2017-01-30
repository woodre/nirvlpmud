/***********
This Mob and the Mob it comes from is not designed to be "Fair" or "Nice" or something that a player should
just be able to kill over an over again.  The Monster is designed with the idea that some players may want to
have a challenge and may want to see if it can be done.  Now as a player who is like this I may be the only 
player who is like this and may be the only one who ever really tries to kill this monster past the first
attempt or so.  That being said there is a place fore bigger than life mobs and such things should not be
put in a padded room just because they do not fit a mold.  No one is making people fight this mob it will be
in a very remote place in my realm and will probably sit there for a long time.
************/
inherit "/obj/monster";
#include "/players/jareel/define.h"
#define TO this_object()
#define RIP RED+"The Zombie slashes at "+attacker_ob->query_name()+" leaving a bloody mess"+NORM
#define REND HIR+"The Zombie Claws at "+attacker_ob->query_name()+"'s flesh gashing away the skin"+NORM


object target;

reset(arg)  {
    ::reset(arg);
  if (arg) return;
  set_name("Undead Minion - "+HIR+"["+HIK+"Raised by Necrosan"+NORM+HIR+"]"+NORM+" (Evil)");
  set_alias("minion");
  set_alt_name("undead");
  set_race("zombie");
  set_al(-1000);
  set_level(21);
  set_hp(300);
  set_ac(19);
  set_heal(30,1);
  set_armor_params("other|light",0,-100,"prot_from_light"); 
  set_armor_params("other|dark",0,100,"prot_from_dark"); 
  set_armor_params("other|fire",0,-100,"prot_from_fire"); 
  set_armor_params("other|ice",0,10,"prot_from_ice"); 
  set_armor_params("other|evil",0,100,"prot_from_evil"); 
  set_armor_params("other|wind",0,10,"prot_from_wind"); 
  set_armor_params("other|electric",0,10,"prot_from_electric"); 
  set_armor_params("other|good",0,-100,"prot_from_good"); 
  set_armor_params("other|water",0,10,"prot_from_water"); 
  set_armor_params("other|earth",0,10,"prot_from_earth"); 
  set_armor_params("other|laser",0,100,"prot_from_laser"); 
  set_armor_params("other|poison",0,100,"prot_from_poisen"); 
 /* set_armor_params("other|physical",0,25,0);*/
  set_res(25);
  set_armor_params("other|magical",0,25,"prot_from_magical");
  set_armor_params("other|sonic",0,25,"prot_from_sonic"); 
  set_armor_params("other|mental",0,25,0);  
  set_wc(65);
  set_ac_bonus(25);
  set_wc_bonus(65); 
  set_gender("male");
  add_money(2000+random(1000));
  set_dead_ob(this_object());
  set_short("Undead Minion - "+HIR+"["+HIK+"Raised by Necrosan"+NORM+HIR+"]"+NORM+" (Evil)");
  set_long(
    "Maggot eaten flesh loosely drapes over the stark white bones that tear past the rotten skin.\n"+
    "Green ooze drips out of the crevasses of every crease and fold animated by the walking corpse.\n"+
    "The dull greyish skin has been devoid of life long for the flies to look for other forms of\n"+ 
    "nutrients.\n");
  add_spell(
    "hand slash",
	HIK+"The Zombie bites into #TN# ripping away flesh\n"+NORM,
    HIK+"The Zombie bites into #TN# ripping away flesh\n"+NORM,
  35,40,"other|physical");

  add_spell(
    "flesh rend",
	HIK+"The Zombie chews a chunk of skin from #TN#'s arm\n"+NORM,
    HIK+"The Zombie chews a chunk of skin from #TN#'s arm\n"+NORM,
  65,70,"other|physical");
}

status zombie_check(object ob) {
  return (status) ob->query_jareel_zombie() > 1 && ob->query_target() && ob != this_object();
}

heart_beat(){

  int V,i;
  object ob;
  object *inv;

  if(!environment())  
    return;

  if( target ) {
    tell_room( environment(), "Target is: "+target->query_name()+"\n");
    if( attacker_ob != target && present(target->query_real_name()) )
      attack_object( target );
  }

  if( !attacker_ob ) {
#ifndef __LDMUD__ 
    inv = filter_array(all_inventory(environment()),"zombie_check", this_object());
#else
    inv = filter(all_inventory(environment()), "zombie_check", this_object());
#endif 
    tell_room( environment(), "Size is: "+sizeof(inv)+"\n");
    if( sizeof(inv) > 0 )
      target = inv[ random(sizeof(inv)) ]->query_target();
  }
  /**** ???
  if(ob = present("zombie", environment())) { 
    if(ob->query_attack()) 
      attack_object(ob->query_attack()); 
  ******/

    ::heart_beat();
    if(attacker_ob) {
      already_fight=0;
      V = random(3);
      if(attacker_ob){
        if(V == 1) Z_Slash();
        if(V == 2) Z_Crush();
      }
    }
}

Z_Slash()  {
    tell_room(environment(TO),
    REND+"\n");
    call_other(attacker_ob,"hit_player",random(25)+10);
  return;
}

Z_Crush() {
    tell_room(environment(TO),
    RIP+"\n");
    call_other(attacker_ob,"hit_player",random(46)+35);
  return;
}

set_target( object ob ) { target = ob; }
query_target() { return target; }

query_jareel_zombie() { return 2; }
