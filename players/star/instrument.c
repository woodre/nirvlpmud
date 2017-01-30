/* Guild object of the Bards.
* First version by Saber.
* Version 1.0
* Edited by Illarion in 2003.  Version 1.1
*/
/*
inherit "/players/guilds/bards/obj/skills.c";
*/

static string music, pet_name;
string locked;
static int time_delay;  /* Controls spell delays */

#include "/players/guilds/bards/ansi.h"
#include "/players/guilds/bards/lib/ansi_pad.h"
#include "/players/guilds/bards/extra2.h"

#include "/players/guilds/bards/zpet2.c"

/* saving variables */
int bard_level, bard_xp, age, guild_status, approval, is_gc;
string instr_string, sponsor, pegasus_name;

/* non-saving variables */
static string pretitle, name, title, gender, guild_name, al_title, lastime;
object my_pet;

object pegasus;
object owner;

static int line_flag, is_lit, health_flag;
static int level, ex_lv, XXX, YYY;
static int A, B, C, D, E, F, G, H;

reset(arg)
{
	if (arg)
	return;
	line_flag = 1;
	/* <change by="Erasmios" date="2001-07-04"> */
	is_lit = 0;
	/* </change> */
	set_instrument_string("Harp");
	set_heart_beat(1);
	set_light(0);
	pet_return = ({ 0,0,0,0, });
   pet_names = ({ "0","0","0","0", });
	health_flag = 1;
}

/* allows the object to interact with shapeobj.c - see that file for
 * details
 */
query_shaping_object() { return 1; }
id(str) {
	return lower_case(str) == lower_case(instr_string) || str == "instrument" ||
      str == "bard_obj" || str == "no_spell" || str == "guild_obj" ||
      str == "no_pet" || str == "generic_wc_bonus" || str == "guild_monitor" ||
      str == "kill_check_object";
}

gen_wc_bonus(){
	if(present("alliancebracer", USER)){
		return random(4) + 1;
	}
	return 0;
}


call_pet(){
	if(previous_object()->is_pet()){
		tell_room(environment(USER),
		USER->query_name()+"'s new pet wanders off.\n");
		destruct(previous_object());
		return 1;
	}
	return 1;
}

drop() {
	return 1;
}

get() {
	return 1;
}

can_put_and_get() {
	return 0;
}

query_auto_load() {
	return "/players/guilds/bards/instrument.c:";
}

short()
{
	return "A Bardic Instrument ((" + get_colored_instrument_name(instr_string) + "))";
}

long() {
	write("A glittering Bardic rune marks this as an instrument of\n"
       +"the (in)famous Bards of Ryllian.\n"
	     +"Type <lore> for more information.\n");
}


query_locked(){ return locked; }

set_locked(str){ 
  locked = str;
  tell_object(environment(),"Your powers have been suspended by "+str+".\n");
}
unlock(){
  locked = 0;
  tell_object(environment(),"Your powers have been reinstated.\n");
  return 1;
}
init_arg(str) {
	bard_news();
}

init() {
  string *social_verbs,s;
  if(!environment()) return;
  if(this_player() != environment()) return;
  if(!owner && this_player() == environment()) owner=this_player();
	restore_me();

  CHANNEL->add_instrument(this_object());
    
  add_action("cmd_01","bardnews");
  add_action("cmd_01","emotions");
  add_action("no_no", "kill_players");
	add_action("no_no", "missile", 2);
	add_action("no_no", "shock", 2);
	add_action("no_no", "fireball", 2);
	add_action("no_no", "sonic", 2);
		
	add_action("cmd_05", "ayre");
	add_action("cmd_05", "farsong");
	add_action("cmd_05", "farsonge");
	add_action("cmd_01", "lore");
	add_action("bard_talk", "bt");
  add_action("bard_talk_history", "bth");
	add_action("bard_emote", "bte");
	add_action("cmd_01", "kin");
	add_action("bard_update", "clean_instrument");
	add_action("cmd_01", "bwho");
	add_action("cmd_01", "bury");
	add_action("cmd_04", "bising");
	add_action("cmd_02", "bless");
   /*
       add_action("monitor", "mon");
  */
	add_action("cmd_01", "cantrip");
	add_action("cmd_02", "cant");
	add_action("cmd_02", "song");
	add_action("cmd_02", "cheal");
	add_action("chant_heal", "chant_heal");
	add_action("cmd_03", "charm");
	add_action("cmd_04", "agony");
	add_action("cmd_04", "distort");
  add_action("cmd_05","sphere");
  add_action("cmd_04","ele");
	add_action("cmd_04", "hawks");
  add_action("cmd_08", "healing");
	add_action("cmd_03", "identify");
	add_action("cmd_07", "illusion");
       add_action("cmd_07", "shape");
	add_action("cmd_04", "know");
  add_action("cmd_09", "maskroom");
	
	add_action("cmd_01", "home");
  add_action("new_say"); add_xverb(";");
	add_action("new_say", "say");
	add_action("new_say"); add_xverb("'");
	add_action("cmd_03", "cloak");
	add_action("cmd_01", "pyre");
	add_action("cmd_08", "reflect");
	add_action("cmd_09", "regeneration");
  add_action("cmd_07","starfire");
	add_action("cmd_06", "bind");
	add_action("cmd_01", "succor");
	add_action("cmd_01", "sco");
  add_action("cmd_01", "skills");
	add_action("cmd_03", "strength");
	add_action("strength", "stre");
	add_action("cmd_02", "song");
	add_action("cmd_03", "balance");
	add_action("summon_pet", "companion");
	add_action("toggle", "toggle");
        add_action("cmd_08", "digestion");
	add_action("cmd_09", "true_name");
	add_action("cmd_06", "wealth");
	add_action("cmd_02", "weather");
  add_action("cmd_02","word");

  add_action("cmd_10","make_emotion");
  add_action("cmd_10","battlesong");
  add_action("cmd_10","devil_snare");

  	
/*
	add_action("cmd_emo", "juggle");
	add_action("cmd_emo", "juggle2");
	add_action("cmd_emo", "scarf");
	add_action("cmd_emo", "blueli");
	add_action("cmd_emo", "disappear");
	add_action("cmd_emo", "sing1");
	add_action("cmd_emo", "sing2");
        add_action("cmd_emo", "holo");
	add_action("cmd_emo", "strings");
	add_action("cmd_emo", "clearth");
	add_action("cmd_emo", "tune");
	add_action("cmd_emo", "sparkle");
	add_action("cmd_emo", "bows");
	add_action("cmd_emo", "handkiss");
*/
	add_action("game_over", "quit");
	add_action("save_me", "pppp");
	add_action("check_kill", "kill");
	add_action("bard_song_sing", "sing");
	add_action("name_pet", "petname");
  

  if(is_gc) {
    write("Welcome GC!  GC commands added.\n");
    add_action("cmd_gc", "freeze");
    add_action("cmd_gc", "check_former");
    add_action("cmd_gc", "sponsor");
    add_action("cmd_gc", "unally");
    add_action("cmd_gc", "approve");

  }
  

  if(TP->query_real_name() == "illarion" || TP->query_real_name() == "star") {
    write("Adding Guild Wizard Commands.\n");
    add_action("cmd_gw", "Bset");
    add_action("cmd_gw", "gc");
  }
/* Testing commands */
  if(TP->query_real_name() == "illarion" || TP->query_real_name()=="notharper") {
  }
  
  social_verbs=(mixed)"/players/guilds/bards/socials/bard_social"->get_verbs();
  s=sizeof(social_verbs);
  while(s--)
    add_action("cmd_social",social_verbs[s]);

}

monitor_code(str) {
  switch(str) {
    case "regen": case "regen-b":
      return present("bardic_regeneration_object", environment())?
      (str=="regen"?HIW+"["+HIG+"Regeneration"+HIW+"]"+NORM:"R"):"";
    case "digest": case "digest-b":
      return present("bardic_digestion_object",environment())?
      (str=="digest"?HIW+"["+HIC+"Digestion"+HIW+"]"+NORM:"D"):"";
    case "dist": case "dist-b":
      return present("bard_defend_spell", environment())?
      (str=="dist"?HIW+"["+HIM+"Distorted"+HIW+"]"+NORM:"D"):"";
    case "bat": case "bat-b":
      return present("bard_battle_blessing_object",environment())?
      (str=="bat"?HIW+"["+HIY+"Battlesong"+HIW+"]"+NORM:"B"):"";
  }
  return 0;
}

print_monitor() { 
  string monstring;
  string before,after;
  string digest, dist, regen, bat;
  if(present("bard_defend_spell", environment()))
    dist = HIW+"["+HIM+"Distorted"+HIW+"]"+NORM;
  if(present("bardic_digestion_object", environment()))
    digest = HIW+"["+HIC+"Digestion"+HIW+"]"+NORM;
  if(present("bardic_regeneration_object", environment()))
    regen = HIW+"["+HIG+"Regeneration"+HIW+"]"+NORM;
  if(present("bard_battle_blessing_object",environment()))
    bat = HIW+"["+HIY+"Battlesong"+HIW+"]"+NORM;
  if(!TP->query_monitor_string()) {
    monstring=(dist?"   "+dist:"")+(digest?"  "+digest:"")+(regen?"  "+regen:"")+(bat?"  "+bat:"");
    if(monstring!="")
      write(monstring+"\n");
  }
  return 1;
}


home(){
	if(TP->query_level() > 19) return 0;
	if(TP->query_home() == "/room/church" || TP->query_home() == 0){
		TP->set_home("/players/guilds/bards/bardrooms/common.c");
		write("Home now set to Bard Common Room.\n");
		return 1;
	}
	TP->set_home("/room/church");
	write("Home now set to the Village Church.\n");
	return 1;
}


int toggle()
{
	if (line_flag)
  	write(BARD_OFF);
	else
  	write(BARD_ON);
	line_flag = !line_flag;
	return 1;
}

int query_on() {
	return line_flag;
}

game_over() {
  CHANNEL->check_logout(this_object());
	save_me();
}

void bard_sing(string str,status override) {
  if((line_flag || override) && owner)
    tell_object(owner,str);
}

int bard_talk(string str) {
	return (int)CHANNEL->bard_sing(str, 0);
}

int bard_emote(string str) {
	return (int)CHANNEL->bard_sing(":"+str, 0);
}

int bard_talk_history() {
	CHANNEL->display_history();
	return 1;
}


bard_update() {
	string temp;
	object temp2;
	object OBJ;
	
	save_me();
	this_player()->set_guild_name("bard");
	temp = TO->query_pet_name();
	temp2 = TO->my_pet();
	OBJ = clone_object("/players/guilds/bards/instrument.c");
	destruct(this_object());
	move_object(OBJ, this_player());
	OBJ->set_pet_name(temp);
	OBJ->my_pet(temp2);
	write("Your " + instr_string + " shines like new.\n");
	return 1;
}


query_instrument() {
  return get_colored_instrument_name(instr_string);
}

set_instrument_string(str) {
	instr_string = str;
}


query_health_flag() {
	return health_flag;
}



set_bard_level(str) {
	int ark;
	
	if (sscanf(str, "%d", ark)) {
		bard_level = ark;
		save_me();
	}
}

set_approval(int i){ approval = i; save_me(); }
query_approval(){ return approval; }

status query_is_gc() { return is_gc; }
void set_is_gc(status x) { is_gc = x; }
query_bard_level()
{
	return bard_level;
}

query_bard_xp()
{
	return bard_xp;
}

set_bard_xp(str)
{
	bard_xp = str;
}

set_guild_status(str)
{
	guild_status = str;
}

set_sponsor(str)
{
	sponsor = str;
}

query_sponsor()
{
	return sponsor;
}

no_no()
{
   write("HEY!  That is NOT a bardic thing to do!\n\n");
	return 1;
}

check_kill(str)
{
	object target;
	
	if(!str) return 0;
	if (target = present(str, environment(this_player()))) {
		if (target->is_player()) {
			write("NO PLAYER KILLING!!!\n\n");
			return 1;
		}
	}
}

save_me()
{
	string file;
	
	file =
	"players/guilds/bards/stats/" +
	environment()->query_real_name();
	if (!save_object(file)) {
		tell_object(environment(TO), "Error in saving guild score!\n");
		} else {
		tell_object(environment(TO),
		HIM + "Guild scores saved.  Party on!\n" + NORM);
	}
	environment(this_object())->set_guild_name("bard");
	return 1;
}

restore_me(name)
{
	object player;
	
	if (!name) {
		if (!environment(this_object())
		|| !environment(this_object())->query_name())
		return 0;
		name = environment(this_object())->query_real_name();
	}
	player = find_player(name);
	if (!player)
	return 0;
	tell_object(player, "Checkin your Bard stats...\n");
	restore_object("players/guilds/bards/stats/" + name);
	if (guild_status == -1) {
            destruct(this_player());
	}
	if (guild_status == -2) {
		write("You have been placed on suspension from the Bards.\n" +
		"Mail Illarion if you don't agree.\n");
		destruct(TO);
	}
	environment(this_object())->set_guild_name("bard");
	return 1;
}

aceme(str) {
	if (this_player()->query_level() >= 30) {
		set_bard_level(str);
		write("ok.\n");
		return 1;
	}
}

bard_news()
{
  write(HIM);
  cat("/players/guilds/bards/NEWS");
  write("\n"+NORM);
  return 0;
}

my_pet(x) { return (x ? (my_pet=x) : my_pet); }

static int pk_defense;

query_pk_defense() { return pk_defense; }

heart_beat(){
int yes;
if(!environment()) return;
pk_defense = 0;
if(pet_return[0] > 0){
   pet_return[0] -= 1;
   }
if(pet_return[1] > 0){
   pet_return[1] -= 1;
   }
if(pet_return[2] > 0){
   pet_return[2] -= 1;
   }
if(pet_return[3] > 0){
   pet_return[3] -= 1;
   }

if(environment()->query_attack()){
   if(environment()->query_attack()->is_player()) {
     pk_defense = 1;
  }
   if(present("defend_spell", environment())){
    yes = 1;
    tell_object(environment(), HIW+"  ["+HIM+"Distorted"+HIW+"]  "+NORM);
    }
   if(present("regen", environment())){
    yes = 1;
    tell_object(environment(), HIW+"  ["+HIG+"Regeneration"+HIW+"]"+NORM);
    }
   if(yes) tell_object(environment(), "\n");
  }
}
query_is_lit() { return is_lit; }
set_is_lit(x) {
  if(x && !is_lit) {
    is_lit=1;
    set_light(1);
  } else if(!x && is_lit) {
    set_light(-1);
    is_lit=0;
  }
}
cmd_01(str) {
  return call_other(NEW_SPELLS+"01_"+query_verb(),"main",str);
}
cmd_02(str) {
  return call_other(NEW_SPELLS+"02_"+query_verb(),"main",str);
}
cmd_03(str) {
  return call_other(NEW_SPELLS+"03_"+query_verb(),"main",str);
}
cmd_04(str) {
  return call_other(NEW_SPELLS+"04_"+query_verb(),"main",str);
}
cmd_05(str) {
  return call_other(NEW_SPELLS+"05_"+query_verb(),"main",str);
}
cmd_06(str) {
  return call_other(NEW_SPELLS+"06_"+query_verb(),"main",str);
}
cmd_07(str) {
  return call_other(NEW_SPELLS+"07_"+query_verb(),"main",str);
}
cmd_08(str) {
  return call_other(NEW_SPELLS+"08_"+query_verb(),"main",str);
}
cmd_09(str) {
  return call_other(NEW_SPELLS+"09_"+query_verb(),"main",str);
}

cmd_10(str) {
  return call_other(NEW_SPELLS+"10_"+query_verb(),"main",str);
}

new_say(str) {
  return call_other(EMO+"say","main",str);
}
cmd_emo(str) {
  return call_other(EMO+query_verb(),"main",str);
}
cmd_gc(str) {
  return call_other(NEW_SPELLS+"gc_"+query_verb(),"main",str);
}
cmd_gw(str) {
  return call_other(NEW_SPELLS+"gw_"+query_verb(),"main",str);
}
string get_colored_instrument_name(string instr) {
  return (string)MASTER->get_colored_instrument_name(instr);
}

bard_song_sing(str) {
  return "/players/guilds/bards/obj/song_master"->bard_song_sing(str);
}

kill_check(object what) {
  object mod;
  mod=present("bard_acwc_modifier",what);
  if(mod) mod->recover();
}

cmd_social(arg) {
  return call_other("/players/guilds/bards/socials/bard_social","try_social",
                    query_verb(),arg);
}
