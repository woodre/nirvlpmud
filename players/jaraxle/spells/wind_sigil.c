#include "defs.h"
#include "/players/jaraxle/ansi.h"
#define level USER->query_level()
#define extralevel USER->query_extra_level()
#define AT USER->query_attack()
#define AAT USER->query_alt_attack()
#define HURTEM "/players/jaraxle/spells/w_damage"

string location;
int powerlevel;


id(str){ 
	return str == "sigil" || str == "jar_sigil_new" || str == "wind_sigil";
}

short(){
return 0;
}

long(){ 
string pmess;
write(
HIB+".......................()()()"+NORM+BLU+"*"+NORM+HIB+"()()()......................."+NORM+"\n");
write(
"   Imprinted on your "+location+" is the symbol of\n"+
"   wind.  It glows with a soft blue light. You can\n"+
"   do any of the following to use its power:\n\n"+
"      "+HIB+"set_power"+NORM+"............Sets the power you wish to\n"+ 
"                           pour into invoking the sigil.\n"+
"      "+HIB+"calmwind"+NORM+"("+HIB+"cw"+NORM+")........Summon the winds of the sigil to\n"+
"                               calm the area.\n");
if(USER->query_level() > 9){
write(
"      "+HIB+"windport"+NORM+"("+HIB+"wp"+NORM+").............Invokes the power of the sigil\n"+
"                               into a teleporting spell.\n");
}
if(USER->query_extra_level() > 14){
write(
"      "+HIB+"summon_cloud"+NORM+"...........A cloud for you to float on!\n");
}
if(USER->query_extra_level() > 20){
write(
"      "+HIB+"chokewind"+NORM+"("+HIB+"chw"+NORM+")............Unleashes a suffocating wind\n"+
"                           to suck the life of your opponent.\n\n");
}
write(
"Use "+HIB+"set_power"+NORM+" alone to see a listing of possible\n"+
"settings.\n"+
"To remove the sigil type: remove_sigil\n");
if(level < 10){
	if(powerlevel < 4){
		pmess = "low";
	}
	else if(powerlevel < 7){
		pmess = "medium";
	}
	else if(powerlevel < 11){
		pmess = "high";
	}
	else{
		pmess = "error";
	}
}
else if(level < 15){
if(powerlevel < 6){
		pmess = "low";
	}
	else if(powerlevel < 11){
		pmess = "medium";
	}
	else if(powerlevel < 16){
		pmess = "high";
	}
	else{
		pmess = "error";
	}
}
else if(extralevel < 5){
if(powerlevel < 8){
		pmess = "low";
	}
	else if(powerlevel < 15){
		pmess = "medium";
	}
	else if(powerlevel < 21){
		pmess = "high";
	}
	else{
		pmess = "error";
	}
}
else if(extralevel > 4){
if(powerlevel < 9){
		pmess = "low";
	}
	else if(powerlevel < 18){
		pmess = "medium";
	}
	else if(powerlevel < 21){
		pmess = "high";
	}
	else if(powerlevel > 20){
		pmess = "overload";
	}
	else{
		pmess = "error";
	}
}

else{
	pmess = "error";
}

write("Power is currently set at "+HIB+capitalize(pmess)+NORM+".\n");
write(HIB+".......................()()()"+NORM+BLU+"*"+NORM+HIB+"()()()......................."+NORM+"\n");
	return;
}


query_auto_load(){ 
	return "/players/jaraxle/spells/wind_sigil.c:"+location+"#"+powerlevel;
 }

extra_look(){
return USER->query_name()+" has a glowing "+HIB+"blue"+NORM+" sigil on "+USER->query_possessive()+" "+location+"";
}

init_arg(str){
   string locale;
   int pl;
   sscanf(str,"%s#%d",locale,pl);
   location = locale;
   powerlevel = pl;
}

init(){
if(!environment()) return;
if(!powerlevel){
powerlevel = 3;
}
if(guild_check()){
tell_object(environment(),
"Your guild powers interfere with the sigils...It vanishes.\n");
destruct(this_object());
return 1;
}
add_action("power_set","set_power");
add_action("invoke_wind","windport");
add_action("invoke_wind","wp");
add_action("calm_it","calmwind");
add_action("calm_it","cw");
add_action("cone_att","chw");
add_action("cone_att","chokewind");
add_action("summon_cloud","summon_cloud");
add_action("ditch_it","remove_sigil");
if(USER->query_level() > 14){
add_action("new_sc","score", 2);
}
}

new_sc(){
if(!guild_check() && USER->query_level() < 20){
USER->score();
write(
" I ["+(USER->query_intoxination()*100)/(level+3)+"%]  F ["+(USER->query_stuffed()*100)/(level*8)+"%]"+
"  S ["+(USER->query_soaked()*100)/(level*8)+"%]\n"); 
if(USER->query_fight_area()){
write(" Fight Zone: "+HIR+"PK Area"+NORM+"   ");
}
else{
write(" Fight Zone: "+BOLD+"NON-PK Area"+NORM+"  ");
}
if(environment(USER)->realm() == "NT"){
write(" Room Port: "+BOLD+"Non-Port"+NORM+"\n");
}
else{
write(" Room Port: "+BOLD+"Port"+NORM+"\n");
 }
return 1;
}
return;
}

ditch_it(){
write("You feel a burning sensation on your "+location+"...\n"+
	  "The Sigil fades away.\n");
destruct(this_object());
return 1;
}


set_slocale(str){
location = str;
return 1;
}

/**************** Test Functions only ******************/
set_num(int i){
	powerlevel = i;
	return 1;
}



set_locale(str){
tell_object(USER, 
			"location set to "+str+".\n");
	location = str;
return 1;
}
/********************************************************/

power_set(str){
if(guild_check()){
			write("The Sigils powers are not available to a guilded player.\n");
			return 1;
		}
	if(level < 5){
		write("You are not high enough level to invoke the sigil!\n");
		return 1;
	}
	
	if(!str){
		if(USER->query_level() < 5){
			write("You are not high enough level to invoke the sigil!\n");
			return 1;
		}
		if(USER->query_level() > 4){
write(
"You have the following power levels available:\n\n"+
"            low\n"+
"            medium\n"+
"            high\n");

if(USER->query_extra_level() > 4){
write(
"            "+HIB+"OVERLOAD"+NORM+"\n");
}
write(
"set_power <type> to change the setting.\n");           
return 1; }
write("Type: set_power with no arguments for a listing of settings.\n");
return 1;
}
if(str == "low"){
	if(level < 10){
		powerlevel = 3;
	}
	else if(level < 15){
        powerlevel = 5;
	}
	else if(extralevel < 5){
		powerlevel = 7;
	}
	else{
		powerlevel = 8;
	}
write("Power level set to "+HIR+"Low"+NORM+".\n");
return 1;
}
if(str == "medium"){
	if(level < 10){
		powerlevel = 6;
	}
	else if(level < 15){
        powerlevel = 10;
	}
	else if(extralevel < 5){
		powerlevel = 14;
	}
	else{
		powerlevel = 17;
	}
write("Power level set to "+HIR+"Medium"+NORM+".\n");
return 1;
}
if(str == "high"){
	if(level < 10){
		powerlevel = 10;
	}
	else if(level < 15){
        powerlevel = 15;
	}
	else if(extralevel < 5){
		powerlevel = 20;
	}
	else{
		powerlevel = 20;
	}
write("Power level set to "+HIB+"High"+NORM+".\n");
return 1;
}
if(str == "overload" || str == "OVERLOAD"){
	if(extralevel < 5){
write("Type: set_power with no arguments for a listing of settings.\n");
return 1;		
	}
powerlevel = 25;
write("Power level set to "+HIB+"OVERLOAD"+NORM+".\n");
return 1;
}

write("Type: set_power with no arguments for a listing of settings.\n");
return 1;
}

/******** Teleport Spell base cost 40 with random of 10 uses same random
          miscast as all other teleport spells                 ********/

static invoke_wind(){

object env;
string where; 

if(environment(USER)->realm() == "NT"){
write("The winds cannot reach you here.\n");
return 1; }
   
        if(USER->query_ghost()) return 0;
        if(guild_check()){
			write("The Sigils powers are not available to a guilded player.\n");
			return 1;
		}
		if(USER->query_spell_dam()) return 1;
	    if(USER->query_level() < 5) return 0;

if(TP->query_sp() < 50){
      write("You find yourself too weak for that spell.\n");
      return 1;
   }
   TP->add_spell_point(-40-random(11));
/* This line removes the chance of teleport error! -Feldegast 12-31-00
   if(random(1))
*/
     if(where = call_other("obj/base_tele","teleport")) {
        write("]"+HIR+"MISCAST"+NORM+"[ The winds angrilly gust you to an unknown location! ]"+HIR+"MISCAST"+NORM+"[\n"+NORM);
               TP->move_player("with in a gust of angry wind#"+where);
        write("]"+HIR+"MISCAST"+NORM+"[ The winds angrilly gust you to an unknown location! ]"+HIR+"MISCAST"+NORM+"[\n"+NORM);
        return 1;
      }
   write(HIB+"A strong gust of wind enters the room and whisks you away.\n"+NORM);
     say(this_player()->query_name()+"'s "+location+" begins to glow...\n");
   TP->move_player("into the clouds#/players/jaraxle/spells/avatar_room");
   return 1;
}

static calm_it(){

   object ob;

 if(TP->query_sp() < 25){
 write("You find yourself too weak for that spell.\n");
     return 1; }

    TP->add_spell_point(-20-random(6));
     say(this_player()->query_name()+"'s "+location+" begins to glow...\n");

   if(1 == random(this_player()->query_attrib("wil"))) {
     write("]"+HIR+"MISCAST"+NORM+"[ Winds rush through the area passing by everything. ]"+HIR+"MISCAST"+NORM+"[\n");
     say("Winds rush through the area passing by everything.\n");
return 1; }

/* Taken from Eurale's calm wand.  */

   ob = first_inventory(environment(this_player()));
   while(ob) {
      ob->stop_fight();
      ob->stop_fight();
      ob = next_inventory(ob);
   }
    write("A tornado of wind blows into the room, inturupting the battle!\n");
   write("The winds calms all those around you.\n");
   say("A tornado of wind blows into the room, disrupting everything.\n");
   return 1;
   
}

/******** Spell attack: equivalent of game spells. Against npc type can get a bonus
          of random(10) damage if willpower > random(500)       *******************/

static cone_att(str){
object target, w_damage;
int rcrit, rcrit2, do_damage, set_amnt, damage;
set_amnt = powerlevel*3;

      if(USER->query_ghost()) return 0;
        if(guild_check()){
			write("The Sigils powers are not available to a guilded player.\n");
			return 1;
		}
		if(USER->query_spell_dam()) return 1;
	    if(USER->query_level() < 5) return 0;
        
	  
	  
  if(USER->query_sp() < powerlevel){
	tell_object(USER,
	"Your magical energies are too weak for that.\n");
	return 1;
        }
	if(!str && USER->query_attack())
		target = USER->query_attack();

	else if(str)
		target = present(str, environment(USER));

	else if(!str && !USER->query_attack())
		return 0;

	if(!target){
		tell_object(USER,
		"You don't see "+str+" here.\n");
		return 1;
	}

	if(!living(target)){
		tell_object(USER,
		"You cannot attack "+str+"!\n");
		return 1;
	}

       if(present("wind_sigil_damage", environment(str))){ write("The winds are already restless.\n"); }
else{
        w_damage = clone_object("/players/jaraxle/spells/w_damage");
        w_damage->set_power(set_amnt);
        move_object(w_damage,str);
        TP->add_spell_point(-powerlevel*4-random(21));
      return 1;
    }
	if(powerlevel < 21){
damage = random(powerlevel*2);
	}
	else{
damage = random(34) + 12;
	}

tell_object(USER,
"You invoke the power of the sigil on your "+location+"...\n");
tell_room(environment(USER),
		  USER->query_name()+"'s "+location+" begins to glow...\n", ({USER}));

rcrit = random(500);
rcrit2 = rcrit;
/********************** Critical hit or miscast ********************************/
if(USER->query_attrib("wil") > rcrit2){
tell_object(USER,
			"]"+HIR+"CRITICAL"+NORM+"[ ");
damage += random(10);
}
else if(rcrit2 > (470 + USER->query_attrib("wil"))){
tell_object(USER,
			"]"+HIR+"MISCAST"+NORM+"[ ");
if(damage > 10){
damage -= random(10);
}
else{
damage = 1;
}
}	
}
/*******************************************************************************/


summon_cloud(){
if(TP->query_sp() < 25){
      write("You find yourself too weak for that spell.\n");
      return 1;
   }
write("You call on the winds to push a cloud into the room.\n");
TP->add_spell_point(-20-random(6));
move_object(clone_object("/players/jaraxle/spells/cloud.c"), environment(this_player()));
command("kadabra onmenow",TP);
return 1; }




/********** Keep guilded from using the sigil **************/
guild_check(){
  if(USER->query_level() > 19) return 0;
  if(USER->query_guild_name() && USER->query_guild_name() != 0){ return 1; }
  if(USER->query_guild_rank()){ return 1; }
  if(USER->query_guild_exp()){ return 1; }
return 0;
}
/*************************************************************/

drop(){
	return 1;
}

get(){
	return 0;
}
