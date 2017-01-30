/*
	Filename: gob.c
	Date:     07/23/98
	Author:   Pain
	Purpose:  Death's Legion Guild Object

	Description:
		The guild object will contain the code to ensure
		that the guild members only use issued equipment
		and that the monetary regulations are enforced.

		There will not be many guild commands in this 
		guild as the legionnaires are not magic users.
*/
/* inherit "/obj/armor"; */
#include "/players/pain/color.h"

/*
	Definitions
*/
#define LEGION "players/pain/Legion/members/"
#define TP this_player()
#define TPSTR this_player()->query_attrib("str")
#define TPSTL this_player()->query_attrib("stl")
#define TPLUC this_player()->query_attrib("luc")
#define TPMAG this_player()->query_attrib("mag")
#define TPSTA this_player()->query_attrib("sta")
#define TPWIL this_player()->query_attrib("wil")
#define TPINT this_player()->query_attrib("int")
#define TPPIE this_player()->query_attrib("pie")
#define SP this_player()->query_sp()
#define HP this_player()->query_hp()
#define GOB present("l_gob",this_player())
#define GLVL this_player()->query_level()

/*
	Variables
*/
string muffs;
query_muffs() { return muffs; }
set_muffs(str) { muffs = str; }

string color;
query_color() { return color; }
set_color(str) { color = str; }

int shield;
query_shield() { return shield; }
set_shield(str) { shield = str; }

int ssword;
query_ssword() { return ssword; }
set_ssword(str) { ssword = str; }

int lsword;
query_lsword() { return lsword; }
set_lsword(str) { lsword = str; }

int mace;
query_mace() { return mace; }
set_mace(str) { mace = str; }

int flail;
query_flail() { return flail; }
set_flail(str) { flail = str; }

int axe;
query_axe() { return axe; }
set_axe(str) { axe = str; }

int bow;
query_bow() { return bow; }
set_bow(str) { bow = str; }

int gshield;
query_gshield() { return gshield; }
set_gshield(str) { gshield = str; }

int w_repair;
query_w_repair() { return w_repair; }
set_w_repair(str) { w_repair = str; }

int a_repair;
query_a_repair() { return a_repair; }
set_a_repair(str) { a_repair = str; }

int crit_hit;
query_crit_hit() { return crit_hit; }
set_crit_hit(str) { crit_hit = str; }

static int total;
query_total() { 
return shield+ssword+lsword+mace+flail+axe+bow+gshield+w_repair+a_repair+crit_hit; 
}
/*
	Initialize the Guild Object
*/
id(str) { 
	return str == "l_gob" || str == "tattoo" || str == "no_spell"; 
}

drop() { return 1; }
get() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }
short() { return; }
long() { 
	write("A tattoo of a skull imposed on a flaming sword.\n"+
	      "Looking at it you realize you are a member of an\n"+
	      "elite fighting force in the service of Death.\n"+
	      "To get more information type <help legion\>.\n");
}

reset(arg) {
   if(arg)
	return;
   call_out("fixd",5);
}

init_arg() {
        if(restore_object(LEGION+this_player()->query_real_name())) {
            write("Your stats are being restored. . . .\n");
        }
        else {
            write("Creating a stat file, please hold. . . .\n");
            saveme();
        }
        cat("/players/pain/legion_news");
        return;
}

init() {
	add_action("skills", "skills");
	add_action("skills", "sk");
	add_action("guild_talk", "gt");
	add_action("guild_emote", "ge");
	add_action("saveme", "lsave");
	add_action("restoreme", "lrestore");
	add_action("repair", "repair");
	add_action("legion_who", "lwho");
	add_action("help_legion", "help");
	add_action("l_color", "l_color");
	add_action("l_muffle", "l_muffle");
}

/*
	Functions
*/

/*
	skills()

	Show the guild member an in depth listing of his/her
	current skills and stats.
*/
skills() {
int temp;
int nlvl;


if(this_player()->query_level() < 21) {
temp = call_other("players/pain/Legion/adv_guild","get_next_exp",this_player()->query_level());
nlvl = temp - this_player()->query_exp();
}
write("\n");
if(this_player()->query_level() < 21) {
	write("Experience to next level: "+nlvl+"\n");
}
write("Total Skill Points: "+query_total()+"\n\n");
write("*(%%%%|===========================> <===========================|%%%%)*\n");
write("   Skills Acquired in the Service of Death\n\n");
write("   Shield: "+query_shield()+"\t\tShortsword: "+query_ssword()+"\n");
write("   Longsword: "+query_lsword()+"\t\tMace: "+query_mace()+"\n");
write("   Flail: "+query_flail()+"\t\tAxe: "+query_axe()+"\n");
write("   Bow: "+query_bow()+"\t\tGreatshield: "+query_gshield()+"\n");
write("   Critical Hit: "+query_crit_hit()+"\n");
write("   Weapon Repair: "+query_w_repair()+"\tArmor Repair: "+query_a_repair()+"\n");
write("*(%%%%|===========================> <===========================|%%%%)*\n");
return 1;
}

/*
	saveme()
	
	Save guild members stats and information.
*/
saveme() {
save_object(LEGION+this_player()->query_real_name());
write("Legion stats and information saved. . . .\n");
return 1;
}

/*
	restoreme()

	Restore guild member stats and information.
*/
restoreme() {
if(restore_object(LEGION+this_player()->query_real_name())) {
	write("Your Legion stats are being restored. . . .\n");
   return 1;
}
else {
	write("Creating a Legion stat file, please hold. . . .\n");
	saveme();
   return 1;
}
}

/*
	check_wear(str)
	
	Check to make sure that the armour that the player is 
	attempting to wear is allowed by guild rules.
*/
check_wear(str) {
object what;

what = present(str,this_player());
if(!what) {
        write("You have no "+str+".\n");
        return 1;
}
if(what->query_id() != "legion_armor") {
        write(capitalize(str)+" is not acceptable armor for legionnaires.\n");
        return 1;
}
else {
        return 0;
}
}

/*
	check_wield(str)

	Check to make sure that the weapon that the player is
	attempting to wield is allowed by guild rules.
*/
check_wield(str) {
object what;

what = present(str,this_player());
if(!what) {
        write("You have no "+str+".\n");
        return 1;
}
if(what->query_type() != "legion_weapon") {
        write(capitalize(str)+" is not an acceptable weapon for legionnaires.\n");
        return 1;
}
else {
        return 0;
}
}

/*
	fixd()
	
	Ensure that the guild object is the first object in the players
	inventory and that the player doesn't have more than 40k coins.
*/
fixd() {
if(environment(this_object())) {
        move_object(this_object(),environment(this_object()));
     if(this_player())
	if(this_player()->query_money() > 40000) {
   		this_player()->add_money(-(this_player()->query_money()));
     		this_player()->add_money(40000);
	}	
}
call_out("fixd",100);
return 1;
}

/*
	help(str)

	Provide the member with help on the Legion and its skills.
*/
help_legion(str) {

if(str != "legion") {
	return 0;
}
	write("You are a soldier in the service of "+RED+"Death"+END+"\n");
	write("As such you have been awarded certain skills and abilities.\n");
	write("In order to best serve Death, and his Imperator Pain you must\n");
	write(BOLD+"train"+END+" in the following skills so that you may "+BOLD);
	write("advance"+END+":\n");
	write(BOLD+"shield\tshortsword\tlongsword\tmace\tflail\taxe"+END+"\n");
	write(BOLD+"bow\tgreatshield\tweapons_repair\tarmor_repair"+END+"\n");
	write("and "+BOLD+"critical_hit"+END+"\n");
	write("You may also obtain help on these other commands:\n");
	write(BOLD+"l_muffle"+END+" and "+BOLD+"l_color"+END+"\n");
	return 1;
}

/*
	l_color(str)

	Turn guild color either on or off.
*/
l_color(str) {
if(!str && str != "on" && str != "off") {
	write("Usage l_color <on/off>\n");
	return 1;
}
if(str == "on" && query_color() == "on") {
	write(RED+"Legion color"+END+" is already on.\n");
	return 1;
}
if(str == "off" && query_color() == "off") {	
	write("Legion color is already off.\n");
	return 1;
}
else {
        if(query_color() == "off") {     
                set_color(str);
                write("Setting "+RED+"Legion color"+END+" to "+str+".\n");
                return 1;
        }
        else {
                set_color(str);
                write("Setting Legion color to "+str+".\n");
                return 1;
        }
}
return 0;
}

/*
	l_muffle(str)
	
	Set the Legion channel muffle to either off or on.
*/
l_muffle(str) {
if(!str && str != "on" && str != "off") {
        write("Usage l_muffle <on/off>\n");
        return 1;
}
if(str == "on" && query_muffs() == "on" && query_color() == "on") {
        write(RED+"Legion muffle"+END+" is already on.\n");
        return 1;
}
if(str == "on" && query_muffs() == "on" && query_color() == "off") {
        write("Legion muffle is already on.\n");
        return 1;
}
if(str == "off" && query_muffs() == "off" && query_color() == "on") {
        write(RED+"Legion muffle"+END+" is already off.\n");
        return 1;
}
if(str == "off" && query_muffs() == "off" && query_color() == "off") {
        write("Legion muffle is already off.\n");
        return 1;
}
else {
	if(query_color() == "on") {
        	set_muffs(str);
		write("Setting "+RED+"Legion muffle"+END+" to "+str+".\n");
        	return 1;
	}
	else {
                set_muffs(str);
                write("Setting Legion muffle to "+str+".\n");
                return 1;
	}
}
return 0;
}



query_auto_load() { return "players/pain/Legion/gob.c:"; }

extra_look() {
write(environment(this_object())->query_name()+" has a "+RED+
      "Death's Head"+END+" tattoo.\n");
}

