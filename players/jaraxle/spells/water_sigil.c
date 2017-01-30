#include "defs.h"
#include "/players/jaraxle/ansi.h"
#define level USER->query_level()
#define extralevel USER->query_extra_level()

string location;
int powerlevel;

object ob, target;

id(str){ 
	return str == "sigil" || str == "jaraxle_sigil_new" || str == "water_sigil";
}

short(){
return 0;
}

long(){ 
string pmess;
write(
HIC+".......................~~~~~~"+NORM+CYN+"*"+NORM+HIC+"~~~~~~......................."+NORM+"\n");
write(
"   Imprinted on your "+location+" is the symbol of\n"+
"   water.  It seems to float under your skin with a\n"+
"   soft liquid haze. You can do any of the following\n"+
"   to use its power:\n\n"+
"      "+HIC+"set_power"+NORM+"............Sets the power you wish to\n"+ 
"                           pour into invoking the sigil.\n"+
"      "+HIC+"water"+NORM+"("+HIC+"iw"+NORM+").............Invokes the power of the\n"+
"                           sigil into a healing spell.\n");
if(USER->query_extra_level() > 14){
write(
"      "+HIC+"hrain"+NORM+"("+HIC+"hr"+NORM+")............Healing water rains upon another player.\n\n");
}
if(USER->query_extra_level() > 20){
write(
 "      "+HIC+"hspring"+NORM+"("+HIC+"hs"+NORM+")...........A healing spring rains upon a room of players.\n\n");
}
write(
"Use "+HIC+"set_power"+NORM+" alone to see a listing of possible\n"+
"settings.\n"+
"To remove the sigil type: remove_sigil\n");
if(level < 10){
	if(powerlevel < 9){
		pmess = "low";
	}
	else if(powerlevel < 16){
		pmess = "medium";
	}
	else if(powerlevel < 22){
		pmess = "high";
	}
	else{
		pmess = "error";
	}
}
else if(level < 15){
if(powerlevel < 12){
		pmess = "low";
	}
	else if(powerlevel < 19){
		pmess = "medium";
	}
	else if(powerlevel < 25){
		pmess = "high";
	}
	else{
		pmess = "error";
	}
}
else if(extralevel < 5){
if(powerlevel < 15){
		pmess = "low";
	}
	else if(powerlevel < 21){
		pmess = "medium";
	}
	else if(powerlevel < 28){
		pmess = "high";
	}
	else{
		pmess = "error";
	}
}
else if(extralevel > 4){
if(powerlevel < 15){
		pmess = "low";
	}
	else if(powerlevel < 22){
		pmess = "medium";
	}
	else if(powerlevel < 28){
		pmess = "high";
	}
	else if(powerlevel > 35){
		pmess = "overload";
	}
	else{
		pmess = "none";
	}
}

else{
	pmess = "none";
}

write("Power is currently set at "+HIC+capitalize(pmess)+NORM+".\n");
write(
HIC+".......................~~~~~~"+NORM+CYN+"*"+NORM+HIC+"~~~~~~......................."+NORM+"\n");
	return;
}


query_auto_load(){ 
	return "/players/jaraxle/spells/water_sigil.c:"+location+"#"+powerlevel;
 }

extra_look(){
return USER->query_name()+" has a glowing "+HIC+"cyan"+NORM+" sigil on "+USER->query_possessive()+" "+location+"";
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
add_action("invoke_water","water");
add_action("invoke_water","iw");
add_action("cone_att","hrain");
add_action("cone_att","hr");
add_action("heal_spring","hspring");
add_action("heal_spring","hs");
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
"            "+HIC+"OVERLOAD"+NORM+"\n");
}
write(
"set_power <type> to change the setting.\n");           
return 1; }
write("Type: set_power with no arguments for a listing of settings.\n");
return 1;
}
if(str == "low"){
	if(level < 10){
		powerlevel = 9;
	}
	else if(level < 15){
        powerlevel = 16;
	}
	else if(extralevel < 5){
		powerlevel = 22;
	}
	else{
		powerlevel = 29;
	}
write("Power level set to "+HIC+"Low"+NORM+".\n");
return 1;
}
if(str == "medium"){
	if(level < 10){
		powerlevel = 12;
	}
	else if(level < 15){
        powerlevel = 19;
	}
	else if(extralevel < 5){
		powerlevel = 25;
	}
	else{
		powerlevel = 32;
	}
write("Power level set to "+HIC+"Medium"+NORM+".\n");
return 1;
}
if(str == "high"){
	if(level < 10){
		powerlevel = 15;
	}
	else if(level < 15){
        powerlevel = 22;
	}
	else if(extralevel < 5){
		powerlevel = 28;
	}
	else{
		powerlevel = 35;
	}
write("Power level set to "+HIC+"High"+NORM+".\n");
return 1;
}
if(str == "overload" || str == "OVERLOAD"){
	if(extralevel < 5){
write("Type: set_power with no arguments for a listing of settings.\n");
return 1;		
	}
powerlevel = 50;
write("Power level set to "+HIC+"OVERLOAD"+NORM+".\n");
return 1;
}

write("Type: set_power with no arguments for a listing of settings.\n");
return 1;
}


/******** Main heal spell, heals the owner ONLY possible
          of random(10) heal if willpower > random(500)       *******************/
static invoke_water(str) {
object target;
int damage;
int rcrit;
int rcrit2; 
string sm1, sm2;
string msg, msg2, msg3;
        
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
	
	if(powerlevel < 21){
damage = random(powerlevel*2);
	}
	else{
damage = random(40) + 11;
	}

switch(damage){
case 45..1000:
  sm1 = ""+HIC+"DROWN"+NORM+"";
 break;
case 40..44:
  sm1 = ""+HIC+"BLAST"+NORM+"";
  break;
case 33..39:
  sm1 = ""+CYN+"Rain down upon"+NORM+"";
  break;
case 27..32:
  sm1 = "wash";
 break;
case 17..26:
  sm1 = "spray";
 break;
case 10..16:
sm1 = "splash";
 break;
case 5..9:
sm1 = "sprinkle";
 break;
case 1..4:
sm1 = "mist";
 break;
default:
sm1 = "missed";
	break;
   }

switch(random(100)+1){
case 75..1000:
  sm2 = "tsunami";
 break;
case 50..74:
  sm2 = "crashing wave";
  break;
case 25..49:
  sm2 = "rolling wave";
  break;
case 1..24:
  sm2 = "waterfall";
 break;
default:
sm2 = "drizzle";
	break;
   }

tell_object(USER,
"You invoke the power of the sigil on your "+location+"...\n");
tell_room(environment(USER),
		  USER->query_name()+"'s "+location+" begins to glow...\n", ({USER}));

rcrit = random(500);
rcrit2 = rcrit;
/********************** Critical heal or miscast ********************************/
if(USER->query_attrib("wil") > rcrit2){
tell_object(USER,
			"]"+HIC+"CRITICAL"+NORM+"[ ");
damage += random(10);
}
else if(rcrit2 > (470 + USER->query_attrib("wil"))){
tell_object(USER,
			"]"+HIR+"MISCAST"+NORM+"[ ");
if(damage > 10){
damage -= random(10);
sm1 = "choked";
}
else{
sm1 = "sprinkled";
damage = 1;
}
}	
/*******************************************************************************/


tell_object(USER,
"You "+sm1+" yourself with a "+sm2+" of water.\n");

tell_room(environment(USER),
            USER->query_name()+" is healed by a "+sm2+" of water.\n", ({USER}));
     	msg = "";
        msg2 = "";
        msg3 = "";
        USER->add_hit_point(damage);
        USER->add_spell_point(-powerlevel);
        return 1;
}

/******* Heal Rain: Allows owner to heal another player ****/

static cone_att(str) {
int damage;
string sm1, sm2;
string msg, msg2, msg3;
 if(!str){ write(CYN+"Usage 'hr <player>' or 'hrain <player>'.\n"+NORM);return 1; }
 ob = present(str, environment(this_player()));
 if(!ob){ write("You can only use Heal Rain on another player!\n"); return 1; }
        if(USER->query_ghost()) return 0;
		if(guild_check()){
			write("The Sigils powers are not available to a guilded player.\n");
			return 1;
		}
        if(USER->query_spell_dam()) return 1;
	if(USER->query_extra_level() < 14) return 0;
           if(!ob->is_player() && !living(ob)) {
			tell_object(USER,
				"'hrain <player> or hr <player>'\n");
			return 1;
		}

        if(!ob->is_player() || !living(ob)){	  
                	tell_object(USER,
				"Hrain can only be used on another player!\n");
			return 1;
		}  

  if(USER->query_sp() < powerlevel + 10){
	tell_object(USER,
	"Your magical energies are too weak for that.\n");
	return 1;
        }

  damage = random(powerlevel); 

switch(damage){
case 45..1000:
  sm1 = ""+HIC+"DROWN"+NORM+"";
 break;
case 40..44:
  sm1 = ""+HIC+"BLAST"+NORM+"";
  break;
case 33..39:
  sm1 = ""+CYN+"Rain down upon"+NORM+"";
  break;
case 27..32:
  sm1 = "wash";
 break;
case 17..26:
  sm1 = "spray";
 break;
case 10..16:
sm1 = "splash";
 break;
case 5..9:
sm1 = "sprinkle";
 break;
case 1..4:
sm1 = "mist";
 break;
default:
sm1 = "missed";
	break;
   }

switch(random(100)+1){
case 75..1000:
  sm2 = "tsunami";
 break;
case 50..74:
  sm2 = "crashing wave";
  break;
case 25..49:
  sm2 = "rolling wave";
  break;
case 1..24:
  sm2 = "waterfall";
 break;
default:
sm2 = "drizzle";
	break;
   }


tell_object(USER,
""+BOLD+"You invoke the power of the sigil on your "+location+"..."+NORM+"\n\n");
tell_object(USER,
""+CYN+"A crashing wave of water pours from the water sigil!"+NORM+"\n");
tell_room(environment(USER),
		  USER->query_name()+"'s "+location+" begins to "+HIC+"glow"+NORM+"...\n"+
		  "A refreshing rain of water streams from "+USER->query_name()+"!\n", ({USER}));


tell_object(USER,
"You "+sm1+" "+ob->query_name()+" with a "+sm2+" of healing water.\n");

tell_room(environment(USER),
             USER->query_name()+" heals "+ob->query_name()+" with a "+sm2+" of water.\n", ({USER}));
                  USER->add_spell_point(-powerlevel);
                  ob->add_hit_point(damage);
        return 1;
}

static heal_spring() {
object ob;
int damage;

        if(USER->query_ghost()) return 0;

	if(guild_check()){
	write("The Sigils powers are not available to a guilded player.\n");
	return 1;
		}

        if(USER->query_spell_dam()) return 1;

	if(USER->query_extra_level() < 20) return 0;
  


  if(USER->query_sp() < powerlevel + 10){
	tell_object(USER,
	"Your magical energies are too weak for that.\n");
	return 1;
        }
if(USER->query_sp() >= powerlevel + 10){
    tell_object(USER,""+BOLD+"You invoke the power of the sigil on your "+location+"..."+NORM+"\n\n");
    tell_room(environment(USER), USER->query_name()+"'s "+location+" begins to "+HIC+"glow"+NORM+"...\n", ({USER}));
}
 
damage = random(powerlevel); 
ob = first_inventory(environment(this_player()));
while(ob){
if(ob->is_player()){
 if(USER->query_sp() < powerlevel + 10){
	tell_object(USER,
	"Your magical energies are not strong enough to continue the healing spring.\n");
	return 1;
        }
    tell_object(USER,"A glistening spray of water heals "+ob->query_name()+".\n");

    tell_object(ob, ""+HIC+"A refreshing mist of water waves over you.\n"+NORM);
    tell_room(environment(USER), "A mist of water sweeps over "+ob->query_name()+".\n", ({USER}));
USER->add_spell_point(-powerlevel);
ob->add_hit_point(damage);
} ob = next_inventory(ob); }
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
