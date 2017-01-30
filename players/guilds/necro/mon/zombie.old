#include "../DEFS"

inherit "/obj/monster.c";

#define SPCOST 1

object mas;
string master;
string mname;  /* Change to mname - Rumplemintz */
int lev;
int guildlev;
int mlev;
int follow;
int autoattack;

id(str){ return str == "zombie" || str == "dead" || str == "undead" || str == "necro_zombie"; } 


short(){ return BOLD+"The zombie of "+capitalize(mname)+OFF; }
long(){  
    write("The undead skeleton of "+capitalize(mname)+".  It stand errect, held together only\n"+
      "by the magical power of "+capitalize(master)+".  If a skull could have different looks\n"+
      "this one would be as blank as an unused canvas.  It is here only to do its masters bidding.\n");
    if(this_player()->query_real_name() == master){
	write(HIR+"You may tell your 'zombie' to: attack, follow, autoassist, colpase, or stop.\n"+OFF);
    }
    return 1;
}

reset(arg){
    ::reset();
    if(arg) return; 
    set_name("nobody");
    set_master("wocket");
    follow = 1;
    set_dead_ob(this_object());
}

setup(){
    set_hp( level*40);
    set_wc( (level*4)/3 );
    set_ac(0);
}

heart_beat(){
    ::heart_beat();
    if(!mas){ do_whither(); return 1;}
    if(environment(mas) != environment(this_object()) && follow){
	tell_room(environment(this_object()),cap_name+" leaves following "+capitalize(master)+".\n");
	move_object(this_object(),environment(mas));
	tell_room(environment(this_object()),cap_name+" arrives following "+capitalize(master)+".\n");
    }
    if(autoattack && mas->query_attack() && !this_object()->query_attack()){
	tell_room(environment(this_object()),cap_name+" moves to assist "+capitalize(master)+"'s battle.\n");
	this_object()->attack_object(mas->query_attack());
    }
    if(this_object()->query_attack()){
	if(mas->query_sp() > 2){
	    mas->add_spell_point(-2);
	    if(this_object()->query_attack()->query_attack() != this_object()){
		secondhitme(this_object()->query_attack());
	    }

	}
    }
    if(mas->query_sp() < SPCOST){
	say(GRN+"The zombie falls into a pile of rotting flesh.\n"+OFF);
	move_object(clone_object(OBJ+"/bodyparts/flesh.c"),environment(this_object()));
	destruct(this_object());
	return 1;
    }    
    if(!random(20)){
	tell_object(mas,GRN+"A green mist of your energy floods into your zombie.\n"+OFF);
    }
    mas->add_spell_point(-SPCOST);
}

secondhitme(targ){
    int dam;
    string verb;
    if(random(100) < 33){
	dam = random(targ->query_wc());
	switch(dam){
	case 0:  verb = " misses "; break;
	case 1..3:  verb = " grazes "; break;
	case 4..9:  verb = " hits "; break;
	case 10..15: verb = " smashes "; break;
	case 16..25: verb = " crushes "; break;
	default: verb = " pulverizes "; break;
	}
	tell_room(environment(this_object()),this_object()->query_attack()->query_name()+verb+cap_name+" with a side attack.\n");
	hit_player(dam);
    }
}

init(){
    ::init();
    add_action("youtalkntome","zombie");
}

youtalkntome(str){
    string arg;
    object pres;
    int which;
    if(this_player()->query_real_name() != master){
	notify_fail("The zombie ignores you.\n");
	return 0;
    }
    if(!str){
	notify_fail("What would you like your zombie to do?\n");
	return 0; 
    }
    sscanf(str,"%d %s",which,arg);
    if(!arg){
	if(!which){ which = 1; arg = str; }
    }
    pres = present("necro_zombie "+which,environment(this_object())); 
    if(!pres){
	notify_fail("You do not have that many zombies.\n");
	return 0;
    }
    if(!arg){
	notify_fail("What would you like your number "+which+" zombie to do?\n");
	return 0;
    }
    if(present(pres,environment(this_object())) == this_object()){
	if(ohhcommandme(arg)) return 1; else return 0;
    }
    return 0;
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
    case "colapse":     return do_whither(str);                 break;
    default:  notify_fail("Your zombie looks confused.\n");  return 0;
    }
    return 1;
}

do_whither(){
    write("You tell your zombie to colapse.\n");
    say("The zombie of "+cap_name+" falls to the ground, forming a pile of rotting flesh.\n");
    move_object(clone_object(OBJ+"/bodyparts/flesh.c"),environment(this_object()));
    destruct(this_object());
    return 1;
}

do_autoattack(str){
    if(autoattack){
	notify_fail("Your zombie is already autoassist.\n");
	return 0;
    }
    write("With your unspoken connection you tell your zombie to autoassist.\n");
    write("Your zombie nods.\n");
    say(cap_name+" nods.\n",this_player());
    autoattack = 1;
    return 1;
}

do_attack(str){
    object meat;
    if(!str){
	notify_fail("Who do you want your zombie to attack?\n");
	return 0;
    }
    meat = present(str,environment(this_object()) );
    if(!meat){
	write("The zombie does not find that to attack.\n");
	return 1;
    }
    if(!meat->is_npc()){
	write("Your zombie refuses to attack that.\n");
	return 1;
    }
    write("Your zombie slowly moves to attack "+meat->short()+".\n");
    this_object()->attack_object(meat);
    return 1;
}

do_follow(str){
    if(follow){
	notify_fail("Your zombie is already following.\n");
	return 0;
    }
    write("You tell your zombie, through your unspoken connection, to follow you.\n");
    write("Your zombie nods.\n");
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
    default: notify_fail("Your zombie doesn't understand.\nWhat would you like your zombie to stop doing?\n"); return 0;
    }
}

stop_attacking(){
    if(!this_object()->query_attack()){
	notify_fail("Your skeleton is not attacking.\n");
	return 0;
    }
    write("You, through your unspooken connection, tell "+cap_name+" to stop attacking.\n");
    write("Your zombie nods.\n");  say(cap_name+" nods.\n",this_player());
    write("Your zombie moves out of combat.\n");
    this_object()->stop_fight();
    return 1;
}

stop_following(){
    if(!follow){
	notify_fail("Your zombie is not following.\n");
	return 0;
    }
    write("You, through your unspooken connection, tell "+cap_name+" to stop following.\n");
    write("Your zombie nods.\n");  say(cap_name+" nods.\n",this_player());
    write("Your zombie stops following you.\n");
    follow = 0;
    return 1; 
}

stop_autoattacking(){
    if(!autoattack){
	notify_fail("Your zombie is not autoassisting.\n");
	return 0;
    }
    write("You, through your unspooken connection, tell "+cap_name+" to stop autoassistinging.\n");
    write("Your zombie nods.\n");  say(cap_name+" nods.\n",this_player());
    write("Your zombie stops autoassisting you.\n");
    autoattack = 0;
    return 1;
}

monster_died(){
    if(present("corpse",environment(this_object()))){
	destruct(present("corpse",environment(this_object())));
	move_object(clone_object(OBJ+"/bodyparts/bones.c"),environment(this_object()));
    }
    return 1;
}

hit_player(dam){
    tell_object(mas,"I was hit "+dam+".\n");
    return 0;
}

set_master(m){ master = m; mas = find_player(master);}
set_mname(n){ mname =n; cap_name = BOLD+capitalize(mname)+"'s zombie carcass"+OFF; }
set_level(l){ lev = l; }
set_m_glevel(l){ guildlev = l; }
set_m_level(l){ mlev = l; }

query_master(){ return master; }
query_mas(){ return mas; }
query_name(){ return cap_name; }
query_real_name(){ return mname; }
qurey_level(){ return lev; }
