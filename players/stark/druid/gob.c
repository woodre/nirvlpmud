#include "/players/stark/defs.h"
#include "/players/stark/druid/defs.h"
#include "/players/stark/druid/help.h"
#include "/players/stark/druid/cmd/who.c"
#include "/players/stark/druid/cmd/healing_rain.c"


query_auto_load(){
	save_object("players/stark/druid/player/"+TP->query_real_name());
	return "/players/stark/druid/gob:";
}

int baseglvl;
int mana;
int manalimit;
int exp_weather;
int exp_pet;
int exp_aura;
int exp_calls;
int exp_vision;
int exp_blessing;
int exp_plague;
int meditate_state;

short() { return "A small stone"; }
extra_look(){ return "~~Testing Guild~~"; }
long(){ return write("Starks guild.\n\nd_help\nlist"); }
id(string str) { return str == "stone"; }
drop() { return 1; }
get() { return 1; }

reset(arg){
    if(arg) return;
}


init(){
restore_object("players/stark/druid/player/"+TPRN);

baseglvl=1;
if(exp_plague>2 || exp_blessing>2 || exp_vision>2 || exp_calls>2 || exp_aura>2 || exp_weather>2){
	baseglvl=2;
}
if(exp_plague>3 || exp_blessing>3 || exp_vision>3 || exp_calls>3 || exp_aura>3 || exp_weather>3){
	baseglvl=3;
}
if(exp_plague>4 || exp_blessing>4 || exp_vision>4 || exp_calls>4 || exp_aura>4 || exp_weather>4){
	baseglvl=4;
}
if(exp_plague>5 || exp_blessing>5 || exp_vision>5 || exp_calls>5 || exp_aura>5 || exp_weather>5){
	baseglvl=5;
}
if(exp_plague>6 || exp_blessing>6 || exp_vision>6 || exp_calls>6 || exp_aura>6 || exp_weather>6){
	baseglvl=6;
}
manalimit=baseglvl*150;

add_action("list_int","list");
add_action("druid_help","d_help");
add_action("meditate","meditate");

add_action("sky_mana","s_mana");
add_action("light_of_sol","light_of_sol");
add_action("light_of_luna","light_of_luna");
add_action("wind_peace","winds_of_peace");
add_action("healing_rain","healing_r");
add_action("plague_one","plague_o");
add_action("call_faith","call_faith");
add_action("aura1","aura1");
add_action("aura2","aura2");
add_action("aura3","aura3");
add_action("aura4","aura4");
add_action("aura5","aura5");
add_action("aura6","aura6");
add_action("druid_who","dwho");
add_action("save_guild","save");
add_action("guild_tool","stark");


}

list_int(){
	write("baseglvl:"+baseglvl+" manalimit:"+manalimit+" mana:"+mana+" weather:"+exp_weather+" pet"+exp_pet+" aura:"+exp_aura+" calls:"+exp_calls+" vision:"+exp_vision+" blessing:"+exp_blessing+" plague:"+exp_plague+"\n");
	return 1;
}

light_of_sol(){
	int light_on;
	if(exp_weather){
		if(light_on){
			tell_object(USER,"Light of Sol off\n");
			set_light(0);
			light_on=0;
			return 1;
		}
		else if(mana>39){
			set_light(1);
			light_on=1;
			tell_object(USER,"Light of Sol on\n");
			return 1;
		}
		else
		tell_object(USER,"You lack mana.\n");
	}
	else
	tell_object(USER,"Your weather is too low\n");
	return 1;
}

light_of_luna(){
	int luna_on;
	if(exp_weather>1){
		if(luna_on){
			tell_object(USER,"Light of Luna off\n");
			dark_sight_object(0);
			luna_on=0;
			return 1;
		}
		else if(mana>69){
			dark_sight_object(1);
			luna_on=1;
			tell_object(USER,"Light of Luna on\n");
			return 1;
		}
		else
		tell_object(USER,"You lack mana.\n");
	}
	else
	tell_object(USER,"Your weather is too low\n");
	return 1;
}


meditate(){
	if(meditate_state){
		meditate_state=0;
		write("You stop meditating\n");
		return 1;
	}
	else
	if(USER->query_sp() < 50){
		tell_object(USER,"You cannot concentrate\n");
		return 1;
	}
	else
	/* Create object that stops all other cmds */
	USER->add_sp(-50);
	meditate_state=1;
	write("you begin your meditations.\n");
	manaloop();
	return 1;
}

manaloop(){
	if(!meditate_state){return 1;}
	if(USER->query_sp()<2 | USER->query_hp()<2 | mana>(manalimit-1)) {
		meditate_state=0;
		tell_object(USER,"You stop meditating\n");
		return 1;
	}
	else
	USER->add_sp(-1);
	USER->add_hp(-1);
	add_mana(1);
	tell_object(USER,"mana convert\n");
	call_out("manaloop",1);
	return 1;
}


add_mana(mi){mana=mana+mi;}
add_exp_weather(wi){exp_weather+wi;}
add_exp_pet(pi){exp_pet+pi;}
add_exp_aura(ai){exp_aura+ai;}
add_exp_calls(ci){exp_calls+ci;}
add_exp_vision(vi){exp_vision+vi;}
add_exp_blessing(bi){exp_blessing+bi;}
add_exp_plague(pi){exp_plague+pi;}

save_guild(){
	save_object("players/stark/druid/player/"+TP->query_real_name());
	write("Saving Druid GOB\n");
}
