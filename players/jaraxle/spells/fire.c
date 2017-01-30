#include "defs.h"
#include "/players/maledicta/ansi.h"
#define level USER->query_level()
#define extralevel USER->query_extra_level()
#define AT USER->query_attack()
#define AAT USER->query_alt_attack()

string location;
int powerlevel;


id(str){ 
	return str == "sigil" || str == "jar_sigil_new" || str == "fire_sigil";
}

short(){
return 0;
}

long(){ 
string pmess;
write(
HIR+".......................::::::"+NORM+RED+"*"+NORM+HIR+"::::::......................."+NORM+"\n");
write(
"   Imprinted on your "+location+" is the symbol of\n"+
"   fire.  It glows with a soft red light. You can\n"+
"   do any of the following to use its power:\n\n"+
"      "+HIR+"set_power"+NORM+"............Sets the power you wish to\n"+ 
"                           pour into invoking the sigil.\n"+
"      "+HIR+"fire"+NORM+"("+HIR+"if"+NORM+").............Invokes the power of the\n"+
"                           sigil into a killing spell.\n");
if(USER->query_extra_level() > 14){
write(
"      "+HIR+"fcone"+NORM+"("+HIR+"ic"+NORM+")............Fires a deadly cone of fire at\n"+
"                           two attackers.\n\n");
}
if(USER->query_extra_level() > 50){
write(
"      "+HIR+"enflame "+HIW+"<"+HIR+"weapon"+HIW+">"+NORM+"......adds the fire element to any weapon.\n"+
"                            (Cost is "+HIR+"high"+NORM+", be careful of overuseage)\n\n");
}
write(
"Use "+HIR+"set_power"+NORM+" alone to see a listing of possible\n"+
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

write("Power is currently set at "+HIR+capitalize(pmess)+NORM+".\n");
write(
HIR+".......................::::::"+NORM+RED+"*"+NORM+HIR+"::::::......................."+NORM+"\n");
	return;
}


query_auto_load(){ 
	return "/players/maledicta/closed/sigils/fire_sigil.c:"+location+"#"+powerlevel;
 }

extra_look(){
return USER->query_name()+" has a glowing "+HIR+"red"+NORM+" sigil on "+USER->query_possessive()+" "+location+"";
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
add_action("invoke_fire","fire");
add_action("invoke_fire","if");
add_action("cone_att","fcone");
add_action("cone_att","ic");
add_action("enflame_it","enflame");
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
"            "+HIR+"OVERLOAD"+NORM+"\n");
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
write("Power level set to "+HIR+"High"+NORM+".\n");
return 1;
}
if(str == "overload" || str == "OVERLOAD"){
	if(extralevel < 5){
write("Type: set_power with no arguments for a listing of settings.\n");
return 1;		
	}
powerlevel = 25;
write("Power level set to "+HIR+"OVERLOAD"+NORM+".\n");
return 1;
}

write("Type: set_power with no arguments for a listing of settings.\n");
return 1;
}


/******** Main attack: equivalent of game spells. Against npc type can get a bonus
          of random(10) damage if willpower > random(500)       *******************/
static invoke_fire(str) {
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
	if(powerlevel < 21){
damage = random(powerlevel*2);
	}
	else{
damage = random(34) + 12;
	}

switch(damage){
case 45..1000:
  sm1 = ""+HIR+"INCINERATED"+NORM+"";
 break;
case 40..44:
  sm1 = ""+HIR+"Devastated"+NORM+"";
  break;
case 33..39:
  sm1 = ""+RED+"Blasted"+NORM+"";
  break;
case 27..32:
  sm1 = "struck";
 break;
case 17..26:
  sm1 = "scorched";
 break;
case 10..16:
sm1 = "hit";
 break;
case 5..9:
sm1 = "grazed";
 break;
case 1..4:
sm1 = "singed";
 break;
default:
sm1 = "missed";
	break;
   }

switch(random(100)+1){
case 75..1000:
  sm2 = "fiery bolt of destruction";
 break;
case 50..74:
  sm2 = "sizzling blast of fire";
  break;
case 25..49:
  sm2 = "bolt of fire";
  break;
case 1..24:
  sm2 = "large ball of flame";
 break;
default:
sm2 = "large ball of flame";
	break;
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
sm1 = "grazed";
}
else{
sm1 = "grazed";
damage = 1;
}
}	
/*******************************************************************************/


tell_object(USER,
"You "+sm1+" "+target->query_name()+" with a "+sm2+".\n");

tell_room(environment(USER),
		  USER->query_name()+" "+sm1+" "+target->query_name()+" with a "+sm2+".\n", ({USER}));
     	msg = "";
        msg2 = "";
        msg3 = "";
        USER->spell_object(target, "fire bolt", damage, powerlevel, 
	msg, msg2, msg3);
        return 1;
}

/******* Cone attack: Splits damage between attacker and alt attacker ****/
static cone_att() {
object target;
int damage, damage2; 
string sm1, sm2, sm3, sm4;
string msg, msg2, msg3;
        if(USER->query_ghost()) return 0;
		if(guild_check()){
			write("The Sigils powers are not available to a guilded player.\n");
			return 1;
		}
        if(USER->query_spell_dam()) return 1;
	    if(USER->query_extra_level() < 14) return 0;
        if(!AT){
			tell_object(USER,
				"You can only use this while in combat!\n");
			return 1;
		}
	  
	  
  if(USER->query_sp() < powerlevel + 10){
	tell_object(USER,
	"Your magical energies are too weak for that.\n");
	return 1;
        }

  damage = random(powerlevel); 
  damage2 = random(powerlevel);
switch(damage){
case 45..1000:
  sm1 = ""+HIR+"INCINERATED"+NORM+"";
 break;
case 40..44:
  sm1 = ""+HIR+"Devastated"+NORM+"";
  break;
case 33..39:
  sm1 = ""+RED+"Enveloped"+NORM+"";
  break;
case 27..32:
  sm1 = ""+HIR+"struck"+NORM+"";
 break;
case 17..26:
  sm1 = ""+HIR+"scorched"+NORM+"";
 break;
case 10..16:
sm1 = ""+HIR+"hit"+NORM+"";
 break;
case 5..9:
sm1 = ""+HIR+"grazed"+NORM+"";
 break;
case 1..4:
sm1 = ""+HIR+"singed"+NORM+"";
 break;
default:
sm1 = "missed";
	break;
   }

switch(damage2){
case 45..1000:
  sm3 = ""+HIR+"INCINERATED"+NORM+"";
 break;
case 40..44:
  sm3 = ""+HIR+"Devastated"+NORM+"";
  break;
case 33..39:
  sm3 = ""+RED+"Enveloped"+NORM+"";
  break;
case 27..32:
  sm3 = ""+HIR+"struck"+NORM+"";
 break;
case 17..26:
  sm3 = ""+HIR+"scorched"+NORM+"";
 break;
case 10..16:
sm3 = ""+HIR+"hit"+NORM+"";
 break;
case 5..9:
sm3 = ""+HIR+"grazed"+NORM+"";
 break;
case 1..4:
sm3 = ""+HIR+"singed"+NORM+"";
 break;
default:
sm3 = "missed";
	break;
   }

switch(random(100)+1){
case 75..1000:
  sm4 = "crashing wave of destruction";
 break;
case 50..74:
  sm4 = "cone of blazing flame";
  break;
case 25..49:
  sm4 = "wave of fire";
  break;
case 1..24:
  sm4 = "large cone of flame";
 break;
default:
sm4 = "large cone of flame";
	break;
   }

switch(random(100)+1){
case 75..1000:
  sm2 = "crashing wave of destruction";
 break;
case 50..74:
  sm2 = "cone of blazing flame";
  break;
case 25..49:
  sm2 = "wave of fire";
  break;
case 1..24:
  sm2 = "large cone of flame";
 break;
default:
sm2 = "large cone of flame";
	break;
   }

tell_object(USER,
""+BOLD+"You invoke the power of the sigil on your "+location+"..."+NORM+"\n\n");
tell_object(USER,
""+RED+"A "+HIR+"blazing"+NORM+" "+RED+"cone of flame streams from the fire sigil!"+NORM+"\n");
tell_room(environment(USER),
		  USER->query_name()+"'s "+location+" begins to "+HIR+"glow"+NORM+"...\n"+
		  "A blazing cone of flame streams from "+USER->query_name()+"!\n", ({USER}));


tell_object(USER,
"You "+sm1+" "+AT->query_name()+" with a "+sm2+".\n");
if(AAT && AAT != AT)
tell_object(USER,
"You "+sm3+" "+AAT->query_name()+" with a "+sm4+".\n");

tell_room(environment(USER),
		  USER->query_name()+" "+sm1+" "+ATTACK->query_name()+" with a "+sm2+".\n", ({USER}));
if(AAT && AAT != AT)
tell_room(environment(USER),
		  USER->query_name()+" "+sm1+" "+ATTACK->query_name()+" with a "+sm2+".\n", ({USER}));
if(AAT && AAT != AT)
AAT->hit_player(damage2);

     	msg = "";
        msg2 = "";
        msg3 = "";
if(AT)
        USER->spell_object(AT, "fire cone", damage, (powerlevel + 10), 
	msg, msg2, msg3);
        return 1;
}

static enflame_it(str){
      int wc;
    status wield_flag;
    object a;

    if(!str) 
    {
      write("What do you wish to enflame?\n"); 
      return 1;
    }
    if(!(a = present(str, this_player())))
    {
      write("You don't have that.\n");
      return 1;
    }
    if(!a->is_weapon() || !a->weapon_class())
    {
      write("That is not a weapon.\n");
      return 1;
    }
    if((wc = (int)a->weapon_class()) == 20)
    {
      write("\
    "+RED+"Flames"+NORM+" erupt from the sigil over "+str+"!\n\
    Magic rips "+str+" apart!\n    "+capitalize(str)+" is destroyed!\n");
      destruct(a);
      return 1;
    }

    if(wc < 20)
      a->set_class(wc + 1);

    write(HIR+"Flames"+NORM+" ignite along "+str+".\n");

    if((object)this_player()->query_weapon() == a)
    {
      wield_flag = 1;
      this_player()->stop_wielding();
    }

    if(!query_attribute("enflamed", a))
    {
      a->set_short((string)a->short() + " " + HIW + "<" + HIR + 
        "enflamed" + HIW + ">" + NORM);
      add_attribute("enflamed", 1, a);
    }

    if(wield_flag)
      a->wield(str);

    return 1;
}


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
