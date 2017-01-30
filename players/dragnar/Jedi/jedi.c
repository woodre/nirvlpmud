/*         Jedi Guild by Dragnar/Maledicta              */

#include "defs.h"
#include <ansi.h>
#include "lib/variables.h"
#include "lib/sets.h"
#include "lib/reflect.h"
#include "lib/dodge.h"
#include "lib/darkside.h"

id(string str) {

  if(previous_object()) {
    if(previous_object()->query_weight() > 4
      || previous_object()->query_type() == "shield") {
      return str == "guild_object" || str == "jedi_object" 
        || str == "notarmor" || str == "guild_death_object" 
        || str == "no_spell" || str == "pro_object" | str == "generic_wc_bonus";
    }
    
  }
  
  if(str=="notweapon" && query_verb() == "offwield"
    && offwep && offwep->query_wielded_by() == this_player())
  {
    write( "You are already offwielding "+offwep->query_name()+".\n" );
    return 1;
  }

  return str == "guild_object" || str == "jedi_object" 
    || str == "no_spell" || str == "guild_death_object" 
	|| str == "generic_wc_bonus" || str == "gob"
    || str == "pro_object" || str == "dark_sight_object";
}


init() {
  string *ks; int i;

  if(environment() == this_player() && this_player()->is_player() ) {
    CHAN->add_channel( CHAN_NAME, environment() );
    restore_stats();

    add_action("no_who", "ppl");
    add_action("no_who", "Mwho");
    add_action("no_who", "who2");
    add_action("no_who", "s_who");
    add_action("no_wimpy","wimpy");
	
	/* Testing functions, to be removed before Beta test */
    add_action("jedirank", "glevel");
    add_action("wep_coloring", "colorwep");
    add_action("ls_life", "setlife");
    add_action("view_vars","vvars");
    /*************************************************/

    if (cmds = ACTIONS->query_cmds()) {
      i = sizeof(ks = keys(cmds));
      while (i--) add_action("jedi_hook", ks[i]);
    }
    else write_file(ERROR,ctime(time())+" cmds not set!\n");
    if( sizeof(ks) < 10) {
      write_file(ERROR,ctime(time())+" cmds is "+sizeof(ks)+" big!\n");
    }
  }
}

reset(arg){
  if(arg) return;
  set_mon_color("auto");
  set_goodness_pool(75);
  set_heart_beat(1);
  cp = 100;
  set_mcp(100);
}

remove_object() {
   CHAN->remove_channel( CHAN_NAME, environment() );
   destruct(this_object());
   return 1;
}

guild_death() {
  DEATH->jedi_death(USER);
  CHAN->transmit_message( CHAN_NAME, HIB+"\n\t\tYou feel a disturbance cause a ripple in the force.\n\n" );
}

int gen_wc_bonus() {
  write("wc_bonus:\n");
  USER->RegisterWeapon(this_object(), ({ "physical", 25, "jedi_extra_hit" }));
  return 20;
}

jedi_extra_hit( object atk ) {
  write("You maul your attacker.\n");
}

query_message_hit( int dam ) {
  object Saber;
  
  Saber = present("jedi_saber",USER);
  if( Saber )
    return Saber->query_message_hit( dam );
  
  return 0;
}
 
jedi_hook(string str) {
    string cmd;
	
    if (cmd = cmds[query_verb()])
	return (status) cmd->main(str);
}

save_stats() {
  string file;

  if(!USER) return 0;
  file = SAVE_PATH + environment()->query_real_name();
  if (!save_object(file)) {
     tell_object(USER, "Error in saving guild stats!\n");
     return 0;
  } else return 1;
}

restore_stats() {
  if(!USER || !USER->is_player()) return 0;
  skills = allocate(8);

  if(!restore_object(SAVE_PATH + USER->query_real_name())) {
    skills = ({ "saber",0,"telekinesis",0,"physical",0,"telepathy",0,});
    save_stats();
  }
  return 1;
}

get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

heart_beat(){
  object Saber;
  int amt;

  /********* Guild exps bonus for a kill *********/
  if(!old_exps) old_exps = USER->query_exp();
  exps = USER->query_exp();
  if(exps - old_exps > 19) 
    USER->add_guild_exp((exps - old_exps)/5);
  old_exps = exps;

  /********* Set up for Dodge and Reflect info *********/
  if(!old_hp) old_hp = HP;
  new_hp = (int) USER->query_hp();
  damage = (old_hp - new_hp);
  if(damage < 0) damage = 0;
  if(attack)
    old_hp = new_hp;

  /**************** Telekinesis Carry ****************/
  if(carry_obj) {
    if(!present(carry_obj,USER)) {
      carry_obj = 0;
      carry_obj_name = 0;
    }
    else {
      if(cp < 10) DropCarry();
      else cp -= random(3)+1;
    }
  }

  /**************** Lightsaber life adjusts ***************/
  Saber = present("jedi_saber",USER);
  if(Saber && Saber->query_ignited()) { 
    Saber->adj_wep_life(-1);
    if(Saber->query_wep_life() < 1) Saber->NoEnergy();
  }
  else if(USER->query_attack() && Saber) {
    command("ignite saber", USER);
    tell_object(USER, "You turn to face your enemy.\n");
  }
  else if(USER->query_attack() && !Saber && wep_life) {
    command("unlatch saber", USER);
	tell_object(USER, "The force flows through you.\n");
  }

  /* delay counter */ 
  if(force_delay){
	force_delay --;
	if(force_delay < 0) force_delay = 0;
  }

  /* absorb counter */
  if(absorb && USER->query_attack()){
	absorb --;
	if(absorb < 0) absorb = 0;
  }

  /* rage counter */
  if(rage) {
	  rage--;
	  if(rage < 0) rage = 0;
		if( rage == 0 ) {
			tell_object(USER, BOLD + BLK +"Your "+HIR+"Anger "+BOLD + BLK +"finally burns itself out.\n" + NORM);
		}
  }
  
  if(!USER->query_attack() && cp < mcp &&   !USER->query_intoxination()) {
    if(random(100) < ((USER->query_guild_rank()*2)+5)){
      cp ++;
      if(cp > mcp) cp = mcp;
    }
  }

  if(USER->query_attack() && query_skill("telekinesis") > 2 && damage
    && random(100) < random(query_skill("telekinesis"))+1){
      Reflect();
  }

  /* Jedi dodge */
  if (USER->query_attack() && query_skill("physical") > 3 && damage &&
    random(100) < (random(query_skill("physical"))+1)) {
      Dodge();
  }

  if(USER->query_attack() && mon_on){
    command("mon", USER);
  }
  
  if(!darkside) {
    if(USER->query_money() > MAXCOINS){
  	  USER->add_money(-(USER->query_money() - MAXCOINS));
    }
  }
  
  if(meditate){
    amt = random(Rank)+1;
    if(SP > amt && (mcp - cp) > amt) {
      USER->add_spell_point(-amt);
      tell_object(USER, "amt: "+amt+".\n");
      adj_cp(amt);
    }
    else command("awaken",USER);
  }

 if(goodness_pool <= 0 && !darkside){
   DarksideFall();
 }
 
} /* heart_beat() */

DropCarry() {

  if(!carry_obj) return;
  tell_object(USER, "You lose your concentration on the "+carry_obj_name+".\n");
  tell_room(environment(USER), USER->query_name()+" loses "+USER->query_possessive()+" concentration and drops the "+carry_obj_name+".\n", ({USER,}));
  carry_obj->drop();
  move_object(carry_obj, environment(USER));
  carry_obj = 0;
  carry_obj_name = 0;
  return;
}

no_who(){
if(this_player()->query_level() > 19) return 0;
write("You do not have that command available any longer. Use 'who'.\n");
return 1;
}
			
no_wimpy() {
  if(darkside) {
    write("Your bond with the Force keeps you from running.\n");
    return 1;
  }
  return 0;
}

/* Test functions, to be removed before Beta testing */
wep_coloring(string str){
	wep_color = str;
	tell_object(USER, "Wep set to : "+wep_color+".\n");
	save_stats();
	return 1;
}

ls_life(str){
  int i;

  sscanf(str, "%d", i);
	wep_life = i;
  save_stats();
  return 1;
}

view_vars(){
	write("Rage:        "+rage+"\n");
	write("Darkside:    "+darkside+"\n");
	write("Force Delay: "+force_delay+"\n");
	write("Light Pool:  "+goodness_pool+"\n");
	write("Mind:        "+mind_shield+"\n");
	write("Absorb:      "+absorb+"\n");
	return 1;
}

jedirank(str) {
    int amount;
    int target;

   amount = USER->query_guild_rank();
   sscanf(str, "%d", target);
   USER->add_guild_rank(-amount);
   USER->add_guild_rank(target);
   write("Your guild rank is now: "+target+".\n");
   save_stats();
   return 1;
}