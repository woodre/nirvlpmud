inherit "obj/armor";
#include "/players/jaraxle/ansi.h"
/**************************************************
*** Special Wep inherit                        ***
*** By Maledicta :: 04.19.01                   ***
*** Special Features:                          ***
*** set_no_break() - makes the wep unbreakable ***
*** two handed wielding                        ***
*** add_(chance, room mess, mess, and damage)  ***
*** add_special_fun(filepath)                  ***
*************************************************/
#define PATH "players/jaraxle/closed/weapon/saves/"
#define USER environment()
#define UPR USER->query_pronoun()
#define UPO USER->query_possessive()
#define UOB USER->query_objective()
#define UN  USER->query_name()
#define URN USER->query_real_name()
#define ATT USER->query_attack()
#define AN ATT->query_name()
#define APR ATT->query_pronoun()
#define APO ATT->query_possessive()
#define AOB ATT->query_objective()

int time_delay;
int *special_damage;
int *special_chance;
string *special_message;
string *special_rmessage;
object *special_fun;
int yup;

add_special_fun(object ob){
	yup = 1;
	if(!special_fun) special_fun = ({ ob });
	else special_fun += ({ ob });
}

static int gen_bonus;
set_gen_bonus(int i){ gen_bonus = i; }
query_gen_bonus(){ return gen_bonus; }

set_time_delay(int i){ time_delay = i; }
query_time_delay(){ return time_delay; }

	if (!id(str))
	return 0;
	if (environment() != this_player()) {
		/* write("You must get it first!\n"); */
		return 0;
	}
	if (worn) {
		write("You already wear it!\n");
		return 1;
	}
/*
	if(wield_func)
	if(!call_other(wield_func,"wield",this_object()))
	return 1;
	wielded_by = this_player();
	call_other(this_player(), "wield", this_object(),silentwield);
	wielded = 1;
	return 1;
}

weapon_breaks(){
	if(no_break) return 1;
	if(broke) return 1;
	tell_object(environment(this_object()), "Your WEAPON BREAKS!!!!\n");
	set_class(class_of_weapon/3);
	broke = 1;
	if(random(100) > 84) broke = 7;
	command("unwield "+name_of_weapon,environment(this_object()));
	command("wield "+name_of_weapon,environment(this_object()));
	return 1;
}
*/

short() {
	string tmp_short;
   if(!environment()) return "Special Armor";
	if(this_player())
	if(call_other(this_player(), "query_level", 0) > 30) {
		tmp_short = short_desc + "  < wc " + class_of_weapon + ","+eff_wc + " >";
		if (worn) tmp_short += " (worn";
		else if(worn) tmp_short += ")";
		return tmp_short;
	}
	tmp_short = short_desc;
	if(broke) tmp_short += " [BROKEN]";
	if (worn) tmp_short += " (worn";
	else if(worn) tmp_short += ")";
	return tmp_short;
}

/*
gen_wc_bonus(){
	int newbonus;
	if(!wielded) return 0;
	newbonus = gen_bonus;
	gen_bonus = 0;
	return newbonus;
}
*/
static int pet_allow;
set_pet_allow(int i){ pet_allow = i; }
query_pet_allow(){ return pet_allow; }

id(str) {
	if(previous_object()){
		if(!test_wear(previous_object())){
			return str == type || str == name_of_weapon ||
			str == alt_name || str == alias_name ||
			str == "weapon" || str == "notarmor" ||
			str == "generic_wc_bonus" ||
			(pet_allow ? (str == "pet_allow_wep") : (str == "weapon"));
		}
	}
	return str == type || str == name_of_armor ||
	str == alt_name || str == alias_name ||
	(pet_allow ? (str == "pet_allow_armor") : (str == "armor"));
	
}


long() {
	write(long_desc);
	write("It is ");
}




hit(attacker){
	int bonus;
	int x;
	int y;
	bonus = 0;

	/****** Call a special function or two, or three... *******/
	if(special_fun){
		for(y = 0; y < sizeof(special_fun); y++){
			if(ATT){
			/*	if(exists(special_fun[y]) && ATT->query_hp() > 0){ */
                if(ATT->query_hp() > 0){ 
					bonus += special_fun[y]->main(USER, this_object(), name_of_weapon, short_desc);
				}
			}
		}
	}

	/****** Call the specials *********************************/
	if(special_chance && special_damage){
		for(x = 0; x < sizeof(special_chance); x++){
			if(random(100) < special_chance[x] && !bonus && !gen_bonus){
				if(special_rmessage)
				if(special_rmessage[x] && ATT)
				tell_room(environment(USER), filter_msg(special_rmessage[x])+"", ({ USER }));
				if(special_message)
				if(special_message[x] && ATT) tell_object(USER, filter_msg(special_message[x])+"");
				if(special_damage)
				if(special_damage[x]) gen_bonus += special_damage[x];
			}
		}
	}
	/****** add a bonus if wielded two handed. Can't wear a shield tho:( ***/
	/****** average of 1-2 bonus wc                               **********/
	if(two_handed_wield && two_handed_wep)
	bonus += random(environment()->query_attrib("str") / 4);
	if (hit_func)
	bonus += call_other(hit_func,"weapon_hit",attacker);
	if(USER->query_level() > 19) tell_object(USER, "Bonus hit = "+bonus+"|"+gen_bonus+"\n");
	return bonus;
}


drop(silently) {
	if (wielded) {
		call_other(wielded_by, "stop_wielding");
		wielded = 0;
		if(two_handed_wield) two_handed_wield = 0;
		if (!silently)
		write("You drop your wielded weapon.\n");
	}
	return 0;
}

un_wield() {
	if (wielded)
	wielded = 0;
	two_handed_wield = 0;
	wielded_by = 0;
}

stopwield() {
	if (environment() != this_player()) return 0;
	call_other(this_player(), "stop_wielding");
	two_handed_wield = 0;
	wielded = 0;
	wielded_by = 0;
	return 1;
}



add_special_chance(int i){
	yup = 1;
	if(!special_chance) special_chance = ({ i });
	else special_chance += ({ i });
}

add_special_message(str){
	yup = 1;
	if(!special_message) special_message = ({ str });
	else special_message += ({ str });
}
add_special_rmessage(str){
	yup = 1;
	if(!special_rmessage) special_rmessage = ({ str });
	else special_rmessage += ({ str });
}

add_special_damage(int i){
	yup = 1;
	if(!special_damage) special_damage = ({ i });
	else special_damage += ({ i });
}


set_two_handed_wield(int i){ two_handed_wield = i; }
query_two_handed_wield(){ return two_handed_wield; }
set_two_handed_wep(int i){ yup = 1; two_handed_wep = i; }
query_two_handed_wep(){ return two_handed_wep; }
set_no_break(int i){ no_break = i; }
query_no_break(){ return no_break; }



mixed replace_string(string str)
{
	string x;
	if(str == "H") x = BOLD;
	if(str == "K") x = BLK;
	if(str == "R") x = RED;
	if(str == "Y") x = YEL;
	if(str == "B") x = BLU;
	if(str == "G") x = GRN;
	if(str == "C") x = CYN;
	if(str == "W") x = WHT;
	if(str == "M") x = MAG;
	if(str == "N") x = NORM;
	if(str == "U") x = ""+USER+"";
	if(str == "UN") x = ""+UN+"";
	if(str == "URN") x = ""+URN+"";
	if(str == "UPO") x = ""+UPO+"";
	if(str == "UPR") x = ""+UPR+"";
	if(str == "UOB") x = ""+UOB+"";
	if(str == "AN") x = ""+AN+"";
	if(str == "APO") x = ""+APO+"";
	if(str == "APR") x = ""+APR+"";
	if(str == "AOB") x = ""+AOB+"";
	return x;
}

mixed filter_msg(string str)
{
	int x; string *words; string tmp;
	words = explode(str,"$");
	for(x=0;x<sizeof(words);x++)
	if(replace_string(words[x])) words[x] = replace_string(words[x]);
	str = (implode(words,""))+NORM;
	return str;
}

two_handed(){ return two_handed_wield; }

shield_check(){
	object inv;
	int x;
	int woo;
	inv = all_inventory(USER);
	for(x = 0; x < sizeof(inv); x++){
		if(inv[x]->query_worn() && inv[x]->query_type() == "shield"){
			return 1;
		}
	}
	return 0;
}

restore_thing(str){  restore_object(str); return 1; }
save_thing(str){     save_object(str);    return 1; }
locker_arg(){        save_object(PATH+URN+time()); return URN+time(); }
locker_init(arg){    restore_object(PATH+arg); rm("/"+PATH+arg+".o");}
