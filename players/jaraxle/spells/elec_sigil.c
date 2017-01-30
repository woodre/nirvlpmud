#include "defs.h"
#include "/players/maledicta/ansi.h"
#define level USER->query_level()
#define extralevel USER->query_extra_level()
#define AT USER->query_attack()
#define AAT USER->query_alt_attack()
#define SHIELD "/players/jaraxle/spells/shield"
inherit "players/balowski/std/work/monster";
#undef DEBUG
string location;
int powerlevel;


id(str){ 
	return str == "sigil" || str == "jar_sigil_new" || str == "elec_sigil";
}

short(){
return 0;
}

long(){ 
string pmess;
write(
HIY+"_._._._._._._._._._._._//////"+NORM+YEL+"|"+HIY+"\\\\\\\\\\\\_._._._._._._._._._._._"+NORM+"\n");
write(
"   Imprinted on your "+location+" is the symbol of Electrical\n"+
"   Energy. It glows with a soft yellow light. You can\n"+
"   do any of the following to use its power:\n\n"+
"      "+HIY+"set_power"+NORM+"............Sets the power you wish to\n"+ 
"                           pour into invoking the sigil.\n");
write("      "+HIY+"field"+NORM+"..........Summons the power of the sigil into a\n"+
"                           protective shield.\n");
write("      "+HIY+"electrify corpse"+NORM+".....Turn a corpse into a living slave!\n");
if(USER->query_extra_level() > 14){
write("      "+HIY+"electricity"+NORM+"("+HIY+"el"+NORM+")......Invokes the power of the\n"+
"                           sigil into a killing spell.\n"); }

write(
"Use "+HIY+"set_power"+NORM+" alone to see a listing of possible\n"+
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
write("Power is currently set at "+HIY+capitalize(pmess)+NORM+".\n");
write(
HIY+"_._._._._._._._._._._._\\\\\\\\\\\\"+NORM+YEL+"|"+NORM+HIY+"//////_._._._._._._._._._._._"+NORM+"\n");
	return;
}


query_auto_load(){ 
	return "/players/jaraxle/spells/elec_sigil.c:"+location+"#"+powerlevel;
 }

extra_look(){
return USER->query_name()+" has a glowing "+HIY+"yellow"+NORM+" sigil on "+USER->query_possessive()+" "+location+"";
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
add_action("field_me","field");
add_action("ditch_it","remove_sigil");
add_action("electrify_it","electrify");
if(USER->query_level() > 14){
add_action("invoke_elec","electricity");
add_action("invoke_elec","el");
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
"            "+HIY+"OVERLOAD"+NORM+"\n");
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
write("Power level set to "+HIY+"Low"+NORM+".\n");
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
write("Power level set to "+HIY+"Medium"+NORM+".\n");
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
write("Power level set to "+HIY+"High"+NORM+".\n");
return 1;
}
if(str == "overload" || str == "OVERLOAD"){
	if(extralevel < 5){
write("Type: set_power with no arguments for a listing of settings.\n");
return 1;		
	}
powerlevel = 25;
write("Power level set to "+HIY+"OVERLOAD"+NORM+".\n");
return 1;
}

write("Type: set_power with no arguments for a listing of settings.\n");
return 1;
}


/******** Main attack: equivalent of game spells. Against npc type can get a bonus
          of random(10) damage if willpower > random(500) can also miscast, about the
		  same chance as bonus. ****************************************************/
static invoke_elec(str) {
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
  sm1 = ""+HIY+"ANNIHILATED"+NORM+"";
 break;
case 40..44:
  sm1 = ""+HIY+"Devastated"+NORM+"";
  break;
case 33..39:
  sm1 = ""+YEL+"Blasted"+NORM+"";
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
sm1 = "numbed";
 break;
case 1..4:
sm1 = "grazed";
 break;
default:
sm1 = "missed";
	break;
   }

switch(random(100)+1){
case 75..1000:
  sm2 = "an intense beam of electrical energy";
 break;
case 50..74:
  sm2 = "a bolt of electrical power";
  break;
case 25..49:
  sm2 = "a charged ball of electricity";
  break;
case 1..24:
  sm2 = "a lance of electrical energy";
 break;
default:
sm2 = "a lance of electrical energy";
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
			"]"+HIY+"CRITICAL"+NORM+"[ ");
damage += random(10);
}
else if(rcrit2 > (470 + USER->query_attrib("wil"))){
tell_object(USER,
			"]"+HIY+"MISCAST"+NORM+"[ ");
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
"You "+sm1+" "+target->query_name()+" with "+sm2+".\n");

tell_room(environment(USER),
		  USER->query_name()+" "+sm1+" "+target->query_name()+" with "+sm2+".\n", ({USER}));
     	msg = "";
        msg2 = "";
        msg3 = "";
        USER->spell_object(target, "electrical bolt", damage, powerlevel, 
	msg, msg2, msg3);
        return 1;
}
static field_me(){
   string n;
   object shield, x;
   int stime;
   stime = powerlevel*3;
  
   write("An electronic voltage electrical field expands from the sigil around you.\n");
      say((n = (string)(x = this_player())->query_name()) + "'s "+location+" glows...\n");

      if(!present("magi@shield", x))
      {
        write(HIY + "\
\tAn electricial shield flashes into sight around you!\n" + NORM);
        say(HIY + "An elecctrical shield flashes around " + n + ".\n" + NORM);
   shield = clone_object("/players/jaraxle/spells/shield.c");
        shield->set_limit(stime);
        move_object(shield,this_player());
           TP->add_spell_point(-powerlevel*4-random(21));
      }

      else
        write("You are currently shielded.\n");

      return 1;
    }

static electrify_it(str){

 object corpse;
    int lvl, OBJDIR;
    OBJDIR = "/players/jaraxle/closed/";

    if(str != "corpse"){
    write("There is no corpse here!\n");
    return 1; }
 

    if (!(corpse = present("corpse", environment(this_player())))) {
	this_player()->add_spell_point(-10);
	write("There is nothing for you to electrify.\nYour spell fails.\n");
	return 1;
    }
    if (living(corpse)) {        /* sounds silly, doesn't it? */
	write("The corpse is already occupied by another presence.\n");
	return 1;
    }
    lvl = this_player()->query_extra_level();
    if (lvl < 1) lvl = 1;
    else if (lvl > 50) lvl = 50 + random(lvl - 50);

    write("\
Speaking the magic words you invite  "+capitalize((string)corpse->query_name())+" to take residence in\n\
the pile of bones. Slowly they fit together again and come alive.\n");
    say(this_player()->query_name() + "\
 makes some arcane gestures over the pile of bones. As " +
this_player()->query_pronoun() + "\n\
mutters some incomprehensible words, the bones start to rattle.\n");

    this_player()->add_spell_point(-50);
    call_out("MakeMeLive", 2, this_player());
    return 1;
}

void
MakeMeLive(object summoner)
{
    object dead, corpse;
    int OBJDIR, lvl;

    if (!summoner) return;
    
    /* 
     * since 3.1.2-DR does not support more than 1 extra arg for
     * call_outs, I have to duplicate some code. Argh! :-)
     */
    corpse = present("corpse", environment(summoner));
    if (!corpse || !present(corpse, environment(summoner))) {
	tell_object(summoner, "The corpse is gone!\n");
	return;
    }

    lvl = (int)environment(this_object())->query_extra_level();
    if (lvl < 1) lvl = 1;
    else if (lvl > 50) lvl = 50 + random(lvl - 50);

    dead = clone_object("/players/jaraxle/closed/zombie");
    dead->set_owner(summoner);
    dead->set_name("Zombie");
    dead->set_alt_name("zombie");
    dead->set_short("The Zombie of "+capitalize((string)corpse->query_name())+"");
    dead->set_long("\
The spirits of "+capitalize((string)corpse->query_name())+" have taken residence in this frail set of pale\n\
body parts to bring death to living creatures. "+capitalize((string)corpse->query_name())+" stumbles to a halt\n\
and turns its dreadful grin towards you. Two tiny green dots of light\n\
sparkle in the black eye sockets.\n");
    dead->set_level(lvl);
    dead->set_ep(0);
    dead->set_al(-350);         /* black knight range */
    dead->set_wc(3);            /* bare handed */
    dead->set_ac(0);
    dead->set_hp(lvl*5 - random(lvl));

    tell_object(summoner, "The zombie of "+capitalize((string)corpse->query_name())+" awakes from the dead to serve you.\n");
    say("The corpse of "+capitalize((string)corpse->query_name())+" rises from the ground.\n", summoner);
    destruct(corpse);
    move_object(dead, environment(summoner));
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
