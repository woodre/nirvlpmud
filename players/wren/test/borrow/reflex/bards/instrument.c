/* Guild object of the Bards.
* First version by Saber.
* Version 1.0
*/

static string music, pet_name;
string locked;
static int time_delay;  /* Controls spell delays */

#include "/players/reflex/lib/include/ansi.h"
/*
#include "/players/sandman/paladin_old/dual/weap_pro.h"
*/
#include "/players/reflex/lib/include/esc.h"
#include "/players/reflex/guilds/bards/extra2.h"
#include "/players/reflex/guilds/bards/zhealing.c"
#include "/players/reflex/guilds/bards/zcantrip.c"
#include "/players/reflex/guilds/bards/zlore.c"
#include "/players/reflex/guilds/bards/ztitle.c"
#include "/players/reflex/guilds/bards/zevocation.c"
#include "/players/reflex/guilds/bards/zillusion.c"
#include "/players/reflex/guilds/bards/zinstr.c"
#include "/players/reflex/guilds/bards/zpet2.c"
#include "/players/reflex/guilds/bards/zsongs.c"
#include "/players/reflex/guilds/bards/zemotions.c"
#include "/players/reflex/guilds/bards/zhelp.c"
#include "/players/reflex/guilds/bards/zgc.c"
#include "/players/reflex/guilds/bards/zpal.c"

static int line_flag, is_lit, health_flag;
static int level, ex_lv, XXX, YYY;
static int A, B, C, D, E, F, G, H;
int bard_level, bard_xp, age, guild_status;
string instr_string, sponsor;
static string pretitle, name, title, gender, guild_name, al_title, lastime;
object my_pet;

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

id(str)
{
	return str == instr_string || str == "instrument" || str == "bard_obj"
        || str == "no_spell"
	|| str == "guild_obj" || str == "no_pet" || str == "generic_wc_bonus";
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

drop()
{
	return 1;
}

get()
{
	return 1;
}

can_put_and_get()
{
	return 0;
}

query_auto_load()
{
	return "/players/reflex/guilds/bards/instrument.c:";
}

short()
{
	/*
	if(TP != environment()) tell_object(environment(),
	"You were just viewed by "+this_player()->query_name()+"\n");
	*/
	return "A Bardic Instrument ((" + instr_string + "))";
}

long()
{
	write("A test version of the guild object of the Bards.\n");
	write("Type <lore> for more information.\n");
}


query_locked(){ return locked; }
set_locked(str){ locked = str;
     tell_object(environment(),
      "Your powers have been suspended by "+str+".\n");
}
unlock(){ locked = 0;
     tell_object(environment(),
      "Your powers have been reinstated.\n");
return 1;
}
init_arg(str)
{
	bard_news();
}

init()
{
	if(!environment()) return;
	if(this_player()->query_level() > 19 &&
		this_player()->query_real_name() != "reflex" &&
		this_player()->query_real_name() != "maledicta" &&
		this_player()->query_real_name() != "boltar" &&
		this_player()->query_real_name() != "vertebraker" &&
		this_player()->query_real_name() != "saber"){
		tell_object(this_player(),
			"For roleplaying purposes, this guild is restricted from\n"+
		"cloning without the permission of Reflex.\n");
		destruct(this_object());
		return 1;
	}
	restore_me();
	add_action("no_no", "missile", 2);
	add_action("no_no", "shock", 2);
	add_action("no_no", "fireball", 2);
	add_action("no_no", "sonic", 2);
	
	add_action("GC", "gc");
	
	add_action("approve", "approve");
	add_action("ayre_of_ability", "ayre");
	add_action("bard_farsing", "farsong");
	add_action("bard_faremote", "farsonge");
	add_action("bard_lore", "lore");
	add_action("bard_talk", "bt");
	add_action("bard_title", "bard_title");
	add_action("bard_title_list", "bard_title_list");
       add_action("remove_alliance", "unally");
	add_action("bard_instrument_list", "instrument_list");
	add_action("bard_instrument_name", "instrument_name");
	add_action("bard_emote", "bte");
	add_action("bard_kin", "kin");
	add_action("bard_update", "clean_instrument");
	add_action("bard_who", "bwho");
	add_action("bury_corpse", "bury");
	add_action("bard_image", "bising");
	add_action("bless", "bless");
        add_action("monitor", "mon");
	add_action("cantrip", "cantrip");
	add_action("bards_cant", "cant");
	add_action("canticle_of_darkness", "song");
	add_action("chant_heal", "cheal");
	add_action("chant_heal", "chant_heal");
	add_action("charm", "charm");
	add_action("chord_of_agony", "agony");
	add_action("chord_of_distortion", "distort");
	add_action("chromatic_sphere", "sphere");
	add_action("elemental_tune", "elemental");
	add_action("elemental_tune", "ele");
	add_action("hawk_eyes", "hawks");
	add_action("hymn_of_healing", "healing");
	add_action("identify", "identify");
	add_action("song_of_illusion", "illusion");
	add_action("know_monster", "know");
        add_action("song_of_masking", "maskroom");
	
	add_action("home", "home");
	add_action("new_say", ";");
	add_action("new_say", "say");
	add_action("new_say"); add_xverb("'");
	add_action("note_of_cloaking", "cloak");
	add_action("pyre_corpse", "pyre");
	add_action("reflect", "reflect");
	add_action("regeneration", "regeneration");
	add_action("requiem_of_stars", "starfire");
	add_action("spectral_binding", "bind");
	add_action("succor", "succor");
	add_action("score_new", "sco");
	add_action("strength", "strength");
	add_action("strength", "stre");
	add_action("sing_light", "song");
	add_action("out_light", "song");
	add_action("song_of_balance", "balance");
	add_action("summon_pet", "companion");
	add_action("toggle", "toggle");
	add_action("true_name", "true_name");
	add_action("wealth", "wealth");
	add_action("weather", "weather");
	add_action("words_of_pain", "word");
	
       add_action("freeze", "freeze");
	add_action("juggle", "juggle");
	add_action("juggle2", "juggle2");
	add_action("scarf", "scarf");
	add_action("blueli", "blueli");
	add_action("disappear", "disappear");
	add_action("sing1", "sing1");
	add_action("sing2", "sing2");
	add_action("holo", "holo");
	add_action("strings", "strings");
	add_action("clearth", "clearth");
	add_action("tune", "tune");
	add_action("sparkle", "sparkle");
	add_action("bows", "bows");
	add_action("handkiss", "handkiss");
	add_action("game_over", "quit");
	add_action("save_me", "pppp");
	add_action("no_no", "kill_players");
	add_action("check_kill", "kill");
	add_action("bard_set", "Bset");
	add_action("bard_song_sing", "sing");
	add_action("sponsor", "sponsor");
	add_action("name_pet", "petname");
	add_action("leave_bards", "leave_bards");
}

monitor(str){ 
if(str) return;
this_player()->print_monitor();
if(present("defend_spell", environment())){
 tell_object(environment(), HIW+"  ["+HIM+"Distorted"+HIW+"]  "+NORM);
}
if(present("regen", environment())){
 tell_object(environment(), HIW+"  ["+HIG+"Regeneration"+HIW+"]"+NORM);
}
tell_object(environment(), "\n");
return 1;
}
leave_bards(){
	TP->set_home(0);
	TP->set_guild_file(0);
	TP->set_guild_rank(0);
	TP->set_guild_name(0);
	TP->add_guild_exp(-TP->query_guild_exp());
	TP->add_guild_rank(-TP->query_guild_rank());
	write("You take your instrument in hand and crack it over you knee!\n"+
	"You are no longer a Bard.\n");
	rm("/players/reflex/guilds/bards/stats/"+TP->query_real_name()+".o");
	destruct(this_object());
	return 1;
}

home(){
	if(TP->query_level() > 19) return 0;
	if(TP->query_home() == "/room/church" || TP->query_home() == 0){
		TP->set_home("/players/reflex/guilds/bards/bardrooms/common.c");
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
	line_flag = 1 - line_flag;
	return 1;
}

int query_on()
{
	return line_flag;
}

game_over()
{
	save_me();
}

int bard_sing(string str, int i_emote)
{
	object instrument, person, *list;
	int i, c;
	string temp, color_temp;
	
	instrument = present("instrument", TP);
	if (spell(-400, 1, 1) == -1)
	return 0;
	if (!instrument) {
		notify_fail(NO_INSTRUMENT);
		return 0;
	}
	if (!instrument->query_on()) {
		notify_fail
		("You must tune your instrument if you want to talk to your kin. <toggle>\n");
		return 0;
	}
	if (!str) {
		notify_fail
		("It is a wise Bard that says something when they talk.\n");
		return 0;
	}
	temp = HIB + "*" + HIM + "" + tp + "" + NORM;
	if (!i_emote)
	temp = temp + " sings:";
	temp = temp + " " + str;
	c = 0;
	list = users();
	for (i = 0; i < sizeof(list); ++i) {
		person = list[i];
		instrument = present("instrument", person);
		if (instrument && (int) instrument->query_on()) {
          tell_object(person, temp+"\n");
			++c;
		}
	}
	if (c == 1)
	write("There are no other Bards within the realms of magic.\n");
	return 1;
}

int bard_talk(string str)
{
	return bard_sing(str, 0);
}

int bard_emote(string str)
{
	return bard_sing(str, 1);
}


bard_update()
{
	string temp;
	object temp2;
	object OBJ;
	
	save_me();
	this_player()->set_guild_name("bard");
	temp = TO->query_pet_name();
	temp2 = TO->my_pet();
	OBJ = clone_object("/players/reflex/guilds/bards/instrument.c");
	destruct(this_object());
	move_object(OBJ, this_player());
	OBJ->set_pet_name(temp);
	OBJ->my_pet(temp2);
	write("Your " + instr_string + " shines like new.\n");
	return 1;
}

sing_light(str)
{
	if (str == "light") {
		/* <change by="Erasmios" date="2001-07-04"> */
		if (is_lit) {
			/* </change> */
			write("You have already used the Canticle of Light.\n");
			return 1;
		}
		if (spell(-100, 2, 10, TO) == -1)
		return 0;
		set_light(1);
		/* <change by="Erasmios" date="2001-07-04"> */
		is_lit = 1;
		/* </change> */
		write("You weave a mixture of prayers and song into a canticle.\n"
		+ "You are surrounded by an aura of light.\n");
		say(tp +
			" weaves a mixture of prayers and song into a canticle.\n" +
		tp + " is surrounded by an aura of light.\n");
		call_other(TP, "add_spell_points", -10);
		return 1;
	}
}

out_light(str)
{
	if (str == "out light") {
		/* <change by="Erasmios" date="2001-07-04"> */
		if (!is_lit) {
			/* </change> */
			write("You have not yet whispered the Canticle of Light.\n");
			return 1;
		}
		set_light(-1);
		/* <change by="Erasmios" date="2001-07-04"> */
		is_lit = 0;
		/* </change> */
		write("You sing a single word, causing the light to fade.\n" +
		"The area dims.\n");
		say(tp + " sings a single word.\n" +
			"The area dims as the aura of light surrounding " + tp +
		" fades away.\n");
		return 1;
	}
}

/*
b_help()
{
cat("/players/reflex/guilds/alliance/bard_bard");
return 1;
}
*/

score_new()
{
	string temp, temp1, temp2;
	int tmp1;
	object obj;
	
	write("\n");
	write(HIM+"* "+NORM+TP->query_pretitle()+" "+tp+" "+TP->query_title()+"\n");
	write(HIM+"*"+NORM+BOLD+" Guild Level:  "+NORM+TO->query_bard_level()+"\n");
	write(HIM+"*"+NORM+BOLD+" Game Level:   "+NORM+pad(TP->query_level(), 26)+
	BOLD+" Strength: "+NORM+TP->query_attrib("str")+"\n");
	write(HIM+"*"+NORM+BOLD+" Ex_Level:     "+NORM+pad(TP->query_extra_level(), 26)+
	BOLD+" Stamina: "+NORM+TP->query_attrib("sta")+"\n");
	write(HIM+"*"+NORM+BOLD+" Hit Points:   "+NORM+pad(TP->query_hp() + "/" + TP->query_mhp(), 26)+
	BOLD+" Magic: "+NORM+TP->query_attrib("mag")+"\n");
	write(HIM+"*"+NORM+BOLD+" Spell Points: "+NORM+pad(TP->query_sp() + "/" + TP->query_msp(), 26)+
	BOLD+ " Intelligence: "+NORM+TP->query_attrib("int")+"\n");
	write(HIM+"*"+NORM+BOLD+" Experience:   "+NORM+pad(TP->query_exp(), 26)+
	BOLD+" Will Power: "+NORM+TP->query_attrib("wil")+"\n");
	write(HIM+"*"+NORM+BOLD+" Golden Coins: "+NORM+pad(TP->query_money(), 26)+
	BOLD+" Piety: "+NORM+TP->query_attrib("pie")+"\n");
	write(HIM+"*"+NORM+BOLD+" Quest Points: "+NORM+pad(TP->query_quest_point(), 26)+
	BOLD+" Stealth: "+NORM+TP->query_attrib("ste")+"\n");
	write(HIM+"*"+NORM+BOLD+" Gender:       "+NORM+pad(TP->query_gender(), 26)+
	BOLD+" Luck: "+NORM+TP->query_attrib("luc")+"\n");
	write(HIM+"*\n"+NORM);
	write(HIM+"*"+NORM+BOLD+" Intox: "+NORM+TP->query_intoxination()+
		BOLD+"              Stuffed: "+NORM+TP->query_stuffed()+
	BOLD+"         Soaked: "+NORM+TP->query_soaked()+"\n");
	temp = TP->query_wimpy();
	if (temp == 1) {
		temp = "yes";
		} else {
		temp = "no ";
	}
	temp1 = TP->query_crime();
	if (temp1 == 1) {
		temp1 = "yes";
		} else {
		temp1 = "no ";
	}
	obj = present("base_obj", TP);
	if (!obj) {
		temp2 = "none";
		} else {
		temp2 = obj->query_newguild();
	}
	write(HIM+"*"+NORM+BOLD+" Wimpy: "+NORM+temp +
		BOLD+"            Crime: "+NORM+temp1+
	BOLD+"         Mini Guild: "+NORM+temp2+"\n");
	write(HIM+"* "+NORM);
	check_age();
	write(HIM+"*\n"+NORM);
	write(HIM+"*"+NORM+" You are an active member of the Bards Guild of Ryllian.\n"+
	HIM+"*"+NORM+" Type <lore> to get an extensive help file.\n");
	return 1;
}

check_age(str)
{
	int a;
	
	write("Age:\t");
	if (!str) {
		a = TP->query_age();
		} else {
		a = age;
	}
	if (a / 43200) {
		write(a / 43200 + " days ");
		a = a - (a / 43200) * 43200;
	}
	if (a / 1800) {
		write(a / 1800 + " hours ");
		a = a - (a / 1800) * 1800;
	}
	if (a / 30) {
		write(a / 30 + " minutes ");
		a = a - (a / 30) * 30;
	}
	write(a * 2 + " seconds.\n");
}

query_instrument()
{
	return instr_string;
}

set_instrument_string(str)
{
	instr_string = str;
}



query_health_flag()
{
	return health_flag;
}



set_bard_level(str)
{
	int ark;
	
	if (sscanf(str, "%d", ark)) {
		bard_level = ark;
		save_me();
	}
}

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
	write("HAY!  That is NOT a bardic thing to do!\n\n");
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
	"players/reflex/guilds/bards/stats/" +
	environment()->query_real_name();
	if (!save_object(file)) {
		tell_object(environment(TO), "Error in saving guild score!\n");
		} else {
		tell_object(environment(TO),
		HIM + "Guild scores saves.  Party on!\n" + NORM);
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
	restore_object("players/reflex/guilds/bards/stats/" + name);
	if (guild_status == -1) {
            destruct(this_player());
	}
	if (guild_status == -2) {
		write("You have been placed on suspension from the Bards.\n" +
		"Mail Saber is you don't agree.\n");
		destruct(TO);
	}
	environment(this_object())->set_guild_name("bard");
	return 1;
}

aceme(str)
{
	if (this_player()->query_level() >= 30) {
		set_bard_level(str);
		write("ok.\n");
		return 1;
	}
}

bard_news()
{
	write(HIM +
		"Welcome to the Bards of Ryllian.\n" +
		"Guild Creator : Saber (saber@ryllian.com)\n"+
		"Guild Master  : Reflex (reflex@blarg.net)\n"+
		"Assistant GM  : Maledicta\n"+
		"\nMail Reflex with bug reports.\n"+
	NORM);
	return 0;
}

my_pet(x) { return (x ? (my_pet=x) : my_pet); }

heart_beat(){
int yes;
if(!environment()) return;
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
