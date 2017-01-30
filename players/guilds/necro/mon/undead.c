#include "../defs.h"

inherit "/obj/monster.c";

object mas;
string master, mname, color, bodypart, death_msg;
int guildlev, mlev, follow, autoattack, time, exp_worth, spell_base;

reset(arg){
  ::reset();
  if(arg) return; 
  set_name("nobody");
  set_master("wocket");
  follow = 1;
  autoattack = 1;
  color = BOLD;
  bodypart = "bones";
  set_dead_ob(this_object());
  SetMultipleIds( ({ "dead", "undead", "necro_undead", }) );
  set_short( "The undead remains of a corpse (undead)" );
  set_death_msg( "The "+name+" falls to the ground in a limp pile.\n" );
  set_can_kill(1);
  enable_commands();
}

setup(){
  set_name( "undead" );
  set_short( "The undead remains of "+capitalize(mname)+" (undead)" );
  set_hp(125 + exp_worth / 5000 );
  set_wc( level * 9 / 10 );
  set_ac( level / 3 );

  /** Time undead will be active **/
  time = 180 + exp_worth / 5000;
  /** Set a max to the time, this requires a 1.2 mil exp mob **/
  if( time > 420 ) time = 420;

  /** Spells **/
  spell_base = exp_worth / 8000;
  if( spell_base > 30 ) spell_base = 15 + random(spell_base);
  if( spell_base > 50 ) spell_base = 50;

}

string query_long() {
  string long_des;

  long_des = (string) ::query_long();

  if( (string) this_player()->query_real_name() == master ){
    long_des += HIR+"You may tell your '"+name+"' to: attack, follow, autoassist, collapse, or stop.\n"+OFF;
  }
  return long_des;
}

heart_beat(){
    ::heart_beat();
    if(!mas){ do_whither(); return 1;}
    if(environment(mas) != environment(this_object()) && follow){
	tell_room(environment(this_object()),cap_name+" leaves following "+capitalize(master)+".\n");
	move_object(this_object(),environment(mas));
	tell_room(environment(this_object()),cap_name+" arrives following "+capitalize(master)+".\n");
    }
    if(autoattack && mas->query_attack() && !this_object()->query_attack() && !mas->query_attack()->is_player() ){
	tell_room(environment(this_object()),cap_name+" moves to assist "+capitalize(master)+"'s battle.\n");
	this_object()->attack_object(mas->query_attack());
    } 

  if(!random(20)) {
    /** Undead dies if master is out of spell points **/
    if( mas->query_sp() < UNDEADCOST ) {
      do_whither();
      return 1;
    }
    tell_object(mas,color+"A mist of your energy floods into your "+name+".\n"+OFF);
    mas->add_spell_point(-UNDEADCOST);
  }
    time--;
    if(time == 10 || (time < 10 && !random(3)) ){
	say(BOLD+"The "+name+" begins to waiver.\n"+OFF);
    }
    if(time < 0){
      do_whither();
      return 1;
    }    
}

init(){
  ::init();
  if( this_player() && this_player()->query_real_name() == master )
    add_action("youtalkntome",name);
}

youtalkntome(str){
    string arg;
    object pres;
    int which;
    if(this_player()->query_real_name() != master){
	notify_fail("The "+name+" ignores you.\n");
	return 0;
    }
    if(!str){
	notify_fail("What would you like your "+name+" to do?\n");
	return 0; 
    }
    sscanf(str,"%d %s",which,arg);
    if(!arg){
	if(!which){ which = 1; arg = str; }
    }
    pres = present("necro_undead "+which,environment(this_object())); 
    if(!pres){
	notify_fail("You do not have that many "+name+".\n");
	return 0;
    }
    if(!arg){
	notify_fail("What would you like your number "+which+" "+name+" to do?\n");
	return 0;
    }
    return ohhcommandme(arg);
}

ohhcommandme(arg){
    string cmd,str;
    if(!arg){
	notify_fail("(This shouldn't happen.  Notify Wocket.)\n");
	return 0;
    }
    sscanf(arg,"%s %s",cmd,str);
    if(!str) cmd = arg;
    switch(cmd){
    case "attack":      return do_attack(str);                  break; 
    case "stop":        return do_stop(str);                    break;
    case "follow":      return do_follow(str);                  break;
    case "autoassist":  return do_autoattack(str);              break;
    case "collapse":     return do_whither(str);                 break;
    default:  notify_fail("Your "+name+" looks confused.\n");  return 0;
    }
    return 1;
}

do_whither(){
    write("You tell your "+name+" to collapse.\n");
    say( query_death_msg() );
    if(environment()) /* added by verte 6.6.01 */
	move_object(clone_object(OBJ+"/bodyparts/"+bodypart+".c"),environment(this_object()));
    destruct(this_object());
    return 1;
}

do_autoattack(str){
    if(autoattack){
	notify_fail("Your "+name+" is already autoassist.\n");
	return 0;
    }
    write("With your unspoken connection you tell your "+name+" to autoassist.\n");
    write("Your "+name+" nods.\n");
    say(cap_name+" nods.\n",this_player());
    autoattack = 1;
    return 1;
}

do_attack(str){
    object meat;
    if(!str){
	notify_fail("Who do you want your "+name+" to attack?\n");
	return 0;
    }
    meat = present(str,environment(this_object()) );
    if(!meat){
	write("The "+name+" does not find that to attack.\n");
	return 1;
    }
    if(meat->is_player()){
	write("Your "+name+" refuses to attack that.\n");
	return 1;
    }
    write("Your "+name+" slowly moves to attack "+meat->short()+".\n");
    this_object()->attack_object(meat);
    return 1;
}

do_follow(str){
    if(follow){
	notify_fail("Your "+name+" is already following.\n");
	return 0;
    }
    write("You tell your "+name+", through your unspoken connection, to follow you.\n");
    say(cap_name+" nods.\n");
    follow = 1;
    return 1;
}

do_stop(str){
    if(!str){
	notify_fail("What would you like your zombie to stop doing?\n");
	return 0;
    }
    switch(str){
    case "attacking":     return stop_attacking();          break;
    case "following":     return stop_following();          break;
    case "autoassisting": return stop_autoattacking();      break;
    default: notify_fail("Your "+name+" doesn't understand.\n"); return 0;
    }
}

stop_attacking(){
    if(!this_object()->query_attack()){
	notify_fail("Your "+name+" is not attacking.\n");
	return 0;
    }
    write("You, through your unspoken connection, tell "+cap_name+" to stop attacking.\n");
    write("Your "+name+" nods.\n");  say(cap_name+" nods.\n",this_player());
    write("Your "+name+" moves out of combat.\n");
    this_object()->stop_fight();
    return 1;
}

stop_following(){
    if(!follow){
	notify_fail("Your "+name+" is not following.\n");
	return 0;
    }
    write("You, through your unspoken connection, tell "+cap_name+" to stop following.\n");
    write("Your "+name+" nods.\n");  say(cap_name+" nods.\n",this_player());
    write("Your "+name+" stops following you.\n");
    follow = 0;
    return 1; 
}

stop_autoattacking(){
    if(!autoattack){
	notify_fail("Your "+name+" is not autoassisting.\n");
	return 0;
    }
    write("You, through your unspoken connection, tell "+cap_name+" to stop autoassistinging.\n");
    write("Your "+name+" nods.\n");  say(cap_name+" nods.\n",this_player());
    write("Your "+name+" stops autoassisting you.\n");
    autoattack = 0;
    return 1;
}

monster_died(){
    if(present("corpse",environment(this_object()))){
	say( color +query_death_msg()+ OFF );
	destruct(present("corpse",environment(this_object())));
	move_object(clone_object(OBJ+"/bodyparts/"+bodypart+".c"),environment(this_object()));
    }
    return 1;
}

set_master(m){ 
  master = m; 
  mas = find_player(master);
}
set_mname(n){ 
  mname = n; 
}
set_m_glevel(l){ guildlev = l; }
set_m_level(l){ mlev = l; }
set_color( string c ) { color = c; }
set_bodypart( string str ) { bodypart = str; }
set_death_msg( string str ) { death_msg = str; }
set_exp_worth(int cexp ) { exp_worth = cexp; }

query_master(){ return master; }
query_mas(){ return mas; }
query_name(){ return cap_name; }
query_real_name(){ return mname; }
string query_color() { return color; }
string query_bodypart() { return bodypart; }
string query_death_msg() { return death_msg; }
int query_exp_worth() { return exp_worth; }
