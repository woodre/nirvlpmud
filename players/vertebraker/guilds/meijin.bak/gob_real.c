#include "/players/pavlik/guild/defs.h"
#include "/players/pavlik/guild/combat.h"

mapping guild_skills;		/* guild skills */
mapping guild_stats;		/* guild stats */
string guild_skills_array;	/* used to save mapping */
string guild_stats_array;	/* used to save mapping */

int guild_channel;		/* channel muffling */
int endurance;			/* current endurance % */
int monitor_interval;		/* how often we display the health monitor */
int donations;			/* guild donation points */
int tithe;			/* % of xp that goes to the guild */
int practices;			/* guild practice sessions */
int bought_practices;		/* how many practices we have bought with extra xp */
int new_skills;			/* how many new skills we can learn */

string weapon_of_choice;	/* weapon we are studying */
string monitor_color;		/* guild monitor ANSI color */
string enter_msg;		/* login message */
string exit_msg;		/* logout message */
string login_cmds;		/* commands executed at login */
string handed;			/* handedness */
string pet_stats;		/* save string for guild pet */
string pet_descrip;		/* save pet's description */

static int endurance_interval;  /* how often our endurance recovers */
static mapping guild_bonuses;	/* bonuses to guild stats and skills */
static mapping skill_variables;	/* variables for guild skills */
static object off_wield;	/* offwielded weapon */
static int endu_interval;	/* endurance recovery interval */
static old_exp;			/* for calculating exp earned */
static skill_actions;		/* array for add_actions */

id(str) {
  return str == GUILDNAME+"_obj" || str == GUILDNAME+"_guild_obj" || str == "pavlik_guild_obj"
  || str == "band" || str == "armband" || str == "pro_object";
}

/*********************************************/
/* allows us to use some of the paladin code */
/*********************************************/
query_paladin_shield() { return 1; }
query_combat_method() { 
  if(skill_variables["parry"]) return 2;
  if(skill_variables["tubmle"]) return 2;
  return 0;
}

reset(arg) {
  if(arg) return;
  set_heart_beat(1);
  handed = allocate(2);
  handed[0] = "right";
  handed[1] = "left";
  guild_channel = 1;
  login_cmds = 0;
  monitor_interval = 3;
  monitor_color = HIW;
  endu_interval = 4;
  tithe = 50;
  old_exp = 0;
  guild_skills = ([]);
  guild_stats = ([]);
  guild_bonuses = ([]);
  skill_variables = ([]);
  skill_actions = ({ });
  call_out("health_monitor", 3);
}

/*********************************************************************/
/* This function is called when the guild object is first created.   */
/*********************************************************************/
guild_init(silent) {
  string cmd, *cmds;
  int x;

  /* load guild data */
  restore_me();

  /* register with master */
  DAEMON->add_Meijin(this_object());

  /* set up actions array */
  cmds = get_dir(POWERS);
  for(x=0; x<sizeof(cmds); x++) {
	if(sscanf(cmds[x], "%s.c", cmd)) skill_actions += cmd;
  }

  /* login message to guild members */
  DAEMON->broadcast_login(ENV, enter_msg, silent);

  /* execute login commands */
  if(login_cmds && !silent) {
	call_other(POWERS+"dash.c", "main", login_cmds, "aBcD");
  }

  /* log */
  write_file("/players/pavlik/guild/log/LOGIN",
	ctime()+"|"+
	capitalize(ENV->query_real_name())+"|"+ENV->query_age()+"|"+
	ENV->query_level()+"+"+ENV->query_extra_level()+"|"+ENV->query_exp()+"|"+
	ENV->query_guild_rank()+"|"+ENV->query_guild_exp()+"\n");

  if(ENV->query_level() < 20) {
	ENV->set_home(START_ROOM);
	ENV->set_guild_name(GUILDNAME);

	/* make sure out magic_aptitude doesn't excede the guild max */
	if(call_other(ENV, "query_attrib", "mag") > 14) {
		call_other(ENV, "raise_magic_aptitude", -(call_other(ENV, "query_attrib", "mag") - 14));
	}
  }

  call_other(ENV, "wear", this_object());
  return 1;
}

/*********************************************************************/
/* This function is called when the player leaves the game.          */
/*********************************************************************/
guild_quit(silent) {

  if(!ENV) {
	destruct(this_object());
	return 1;
  }

  /********************************/
  /* Cannot quit while in combat! */
  /********************************/
  if(ENV->query_attack() && present(ENV->query_attack(), environment(ENV))) {
	tell_object(ENV, PRED+HIW+"You cannot quit now!\n"+NORM);
	return 1;
  }

  /* save guild data */
  save_me();

  /* remove from master */
  DAEMON->remove_Meijin(this_object());

  /* logout message to guild members */
  DAEMON->broadcast_logout(ENV, exit_msg, silent);

  /* make sure out magic_aptitude doesn't excede the guild max */
  if(ENV->query_level() < 20) {
	if(call_other(ENV, "query_attrib", "mag") > 14) {
		call_other(ENV, "raise_magic_aptitude", -(call_other(ENV, "query_attrib", "mag") - 14));
	}
  }

  command("save", this_player());
  destruct(this_object());
}
 
get() { return 1; }
drop() { return 1; }
short() { return; }
long() {
  write("This is the "+capitalize(GUILDNAME)+"'s symbol.\n");
  write("For more information type 'xhelp'.\n");
  return;
}

extra_look() {
  if(this_player() == ENV)
	return "A "+HIY+"golden"+NORM+" armband encircles your "+HAND+" forearm";
  else
	return "A "+HIY+"golden"+NORM+" armband encircles "+ENV->query_possessive()+" "+
	HAND+" forearm";
}

add_endurance(x) {
  endurance += x;
  if(endurance > query_max_endurance()) endurance = query_max_endurance();
}
query_endurance() { return endurance; }
query_max_endurance() {
  return 300 + (query_guild_stat("endurance") * 6) + (ENV->query_guild_rank() * 7)/2;
}

set_login_cmds(str) { login_cmds = str; }
query_login_cmds() { return login_cmds; }

set_guild_channel(x) { guild_channel = x; }
query_guild_channel() { return guild_channel; }

query_practices() { return practices; }
add_practices(i) { practices += i; }

query_bought_practices() { return bought_practices; }
add_bought_practices(i) { bought_practices += i; }

query_new_skills() { return new_skills; }
add_new_skills(i) { new_skills += i; }

query_pet_stats() { return pet_stats; }
set_pet_stats(str) { pet_stats = str; }
query_pet_descrip() { return pet_descrip; }
set_pet_descrip(str) { pet_descrip = str; }

set_monitor_interval(x) {
	remove_call_out("health_monitor");
	if(monitor_interval >= 1) call_out("health_monitor", x);
	monitor_interval = x;
}
query_monitor_interval() { return monitor_interval; }
set_monitor_color(str) { monitor_color = str; }
query_monitor_color() { return monitor_color; }

query_handed(x) { return handed[x]; }
set_handed(x, str) { handed[x] = str; }

query_tithe() { return tithe; }
set_tithe(i) { tithe = i; }

query_donations() { return donations; }
add_donations(i) {
  donations += i;
  if(donations > DONATION_MAX) {
	tell_object(ENV, 
	"\n"+PRE+"You recieve 1 "+HIW+"practice session"+NORM+" for your generous donations!\n\n");
	donations = random(100);
	add_practices(1);
  }
}

set_weapon_of_choice(str) { weapon_of_choice = str; }
query_weapon_of_choice() { return weapon_of_choice; }

set_enter_msg(str) { enter_msg = str; }
query_enter_msg() { return enter_msg; }
set_exit_msg(str) { exit_msg = str; }
query_exit_msg() { return exit_msg; }

set_off_wield(ob) { off_wield = ob; }
query_off_wield() {
  if(!off_wield) return 0;
  if(!present(off_wield, ENV)) return 0;
  if(off_wield == ENV->query_weapon()) return 0;
  return off_wield;
}

/************ Guild Stats ****************/
query_stat(str) { return guild_stats[str]; }
query_guild_stat(str) { return guild_stats[str] + guild_bonuses[str]; }
add_guild_stat(str, x) { guild_stats[str] += x; if(guild_stats[str] > 100) guild_stats[str] = 100; }
query_guild_stats() { return guild_stats; }

/************ Guild Skills ***************/
query_skill(str) { str=strcheck(str); return guild_skills[str]; }
query_guild_skill(str) { str=strcheck(str); return guild_skills[str] + guild_bonuses[str]; }
add_guild_skill(str, x) { guild_skills[str] += x; if(guild_skills[str] > 100) guild_skills[str] = 100; }
remove_guild_skill(str) { guild_skills = m_delete(guild_skills, str); }
query_guild_skills() { return guild_skills; }

/******** Skill and Stat Bonuses **********/
query_guild_bonus(str) { str=strcheck(str); return guild_bonuses[str]; }
add_guild_bonus(str, x) { str=strcheck(str); guild_bonuses[str] += x; }
query_guild_bonuses() { return guild_bonuses; }

/************ Skill Variables **************/
query_skill_variable(str) { return skill_variables[str]; }
set_skill_variable(str, x) { skill_variables[str] = x; }
remove_skill_variable(str) { skill_variables = m_delete(skill_variables, str); }
query_skill_variables() { return skill_variables; }

strcheck(str) {
  if(str == "knife") return "dagger";
  if(str == "hammer") return "mace";
  if(str == "club") return "mace";
  if(str == "trident") return "spear";
  if(str == "whip") return "flail";
  if(str == "crossbow") return "bow";
  if(str == "stick") return "staff";
  return str;
}

init() {
  int x;

  if(ENV->query_wimpy()) {
	write(PRE+HIW+"You must turn wimpy OFF.  Use 'wimpy off' to do this.\n"+NORM);
  }

  /* cannot execute commands when raging */
  if(skill_variables["xrage"] == 1) {
	if(ENV->query_attack()) {
		add_action("no_action"); add_xverb("");
		add_action("no_action"); add_xverb("xrage");
		return;
	}
	else {
		write(PRE+"Your thirst for blood subsides.\n");
		write(PRE+"You are no longer "+HIR+"raging"+NORM+".\n");
		xrage_delay_start();
	}
  }

  /* this is for wizards, avoids wierd file_error msg */
  if(in_editor(ENV)) return;

  for(x=0; x<sizeof(skill_actions); x++) {
	add_action("guild_cmd", skill_actions[x]);
  }
  add_action("refresh_object", "xregister");
  add_action("save_me", "saveme");
  add_action("restore_me", "restoreme");
  add_action("guild_quit", "quit");
  add_action("not_allowed","ready");
  add_action("not_allowed","#");
  add_action("not_allowed","so");
  add_action("not_allowed","sonic");

  if(ENV->query_level() > 20) {
	add_action("debug","xdebug");
	add_action("guild_test", "xtest");
  }

  if(ENV->query_level() < 20) ENV->set_al_title(BLU+" Meijin "+NORM);
  if(ENV->query_money() > MONEY_MAX) {
	int amt;
	amt = ENV->query_money() - MONEY_MAX;
	ENV->add_money(-amt);
	add_donations((amt * 2) / 3);
  }

}

guild_cmd(str) {
	if(file_size(POWERS+query_verb()+".c") <= 0) {
		notify_fail("Invalid command.\n");
	}
	return (int)call_other(POWERS+query_verb(), "main", str);
}

no_action(str) {
  if(query_verb() == "xrage") {
	write("\n"+PRE+"You excerise amazing self control and stop raging.\n\n");
	xrage_delay_start();
	endurance -= 10;
	return 1;
  }
  write(PRE+HIW+"You are "+HIR+"raging!"+NORM+"\n");
  return 1;
}

/*****************************/
/* register the guild object */
/*****************************/
refresh_object() {
  string cmd, *cmds;
  int x;

  /* set up actions array */
  cmds = get_dir(POWERS);
  for(x=0; x<sizeof(cmds); x++) {
	if(sscanf(cmds[x], "%s.c", cmd)) skill_actions += cmd;
  }
  write(PRE+"Refreshing ... "+HIB+"ok!\n"+NORM);
  DAEMON->add_Meijin(this_object());

  if(!TP->query_ghost()) {
	TP->set_heart_beat(1);
	TP->heart_beat();
	call_other(TP, "reset", 1);
	TP->recalc_quest();
	TP->recalc_carry();
	set_heart_beat(1);
  }
  return 1;
}

/****************************************************************/
/* heart_beat:  i know heart_beat is frowned upon by some, but  */
/* it seems to be the only reliable way to get somethings done. */
/****************************************************************/
heart_beat() {

  if(!ENV) {
	destruct(this_object());
	return 1;
  }

  /************************************************************************/
  /* keep this object at the top of the player inventory                  */
  /* it is important to keep this object first so that the guild commands */
  /* take precedence over the add_actions from other objects              */
  /************************************************************************/
  move_object(this_object(), ENV);

  /************************************************************************/
  /* this is for calculating guild exp earned.  guild experience is       */
  /* automatically seperated from the regular experience that players     */
  /* earn.  the amount converted to guild xp is based in the tithe.       */
  /************************************************************************/
  if(old_exp < 1) old_exp = ENV->query_exp();
  if(old_exp < ENV->query_exp()) {
	int gexp;
	gexp = ENV->query_exp() - old_exp;
	gexp = (gexp * tithe) / 100;
	ENV->add_guild_exp(gexp);
	ENV->add_exp(-gexp);
  }
  old_exp = ENV->query_exp();

  /************************************************************************/
  /* this is for skills that have a regular endurance cost                */
  /************************************************************************/
  add_endurance(skill_variables["end_mod"]);

  /************************************************************************/
  /* guild combat methods, contained in combat.h                          */
  /************************************************************************/
  if(ENV->query_attack()) {
	if(skill_variables["xrage"] == 1 && ENV->query_attack()->query_npc()) {
		ENV->query_attack()->hit_player(rage_beat());
	}
	else {
		ENV->set_spell_dam(combat_beat());
	}
  }

  /*********/
  /* xrage */
  /*********/
  if(skill_variables["xrage"] == 1) {
	if(endurance <= 0) {
		tell_object(ENV, "\n"+PRE+"You have become too tired.  Your rage subsides.\n\n");
		xrage_delay_start();
	}
  }

  /*************************************************/
  /* Meditate - Currently not avaliable to players */
  /*************************************************/
  if(skill_variables["meditate"] == 1) {
	if(environment(ENV) != skill_variables["meditate_env"]) {
		ENV->hit_player(5+random(15));
		skill_variables["meditate_env"] = environment(ENV);
	}
	if(ENV->query_hp() > skill_variables["meditate_hp"]) {
		ENV->add_hit_point(-(ENV->query_hp() - skill_variables["meditate_hp"]));
	}
	if(ENV->query_sp() > skill_variables["meditate_sp"]) {
		ENV->add_spell_point(-(ENV->query_sp() - skill_variables["meditate_sp"]));
	}
	if(ENV->query_attack()) {
		tell_object(ENV, PRE+"Your meditation is interupted!\n");
		command("xmeditate", ENV);
	}
  }

  /************************************************************************/
  /* this is for endurance point recovery                                 */
  /* endurance recovers every *5* heart beats.                            */
  /************************************************************************/
  if(endu_interval) {
	endu_interval--;
  }
  else {
	int end_amt;
	end_amt = query_guild_stat("constitution") / 10;
	if(end_amt < 2) end_amt = 2;
	add_endurance(end_amt);
	if(skill_variables["meditate"] == 1) endu_interval = 2;
	else endu_interval = 4;
  }
}

/*************************************************************/
/* guild health monitor - needed to monitor endurance points */
/*************************************************************/
health_monitor() {
  object attk, pet;
  string pname;
  int x;

  if(!ENV) {
	call_out("health_monitor", monitor_interval);
	return 1;
  }

  if(monitor_interval <= 0) return;

  attk = ENV->query_attack();
  if(attk) {
	if(monitor_color) tell_object(ENV, monitor_color);
	tell_object(ENV,
	"[Hp: "+ENV->query_hp()+"/"+ENV->query_mhp()+"] "+
	"[Sp: "+ENV->query_sp()+"/"+ENV->query_msp()+"] "+
	"[En: "+endurance+"/"+query_max_endurance()+"] ");
	pet = present(ENV->query_real_name()+"'s meijin_pet", environment(ENV));
	if(pet) {
		pname = extract(pet->query_name(), 0, 2);
		tell_object(ENV, "["+pname+": "+pet->query_hp()+"/"+pet->query_mhp()+"] ");
	}
	x = (attk->query_hp() * 100) / attk->query_mhp();
	x = (x / 10) * 10;
	tell_object(ENV,
	"[Att: "+x+"%]\n");
	if(monitor_color) tell_object(ENV, NORM);
  }
  call_out("health_monitor", monitor_interval);
  return 1;
}

not_allowed() {
  write("Sorry, this command is not avaliable to you.\n");
  return 1;
}

save_me(silent) {
  string *tmp_array;
  int i;

  guild_skills_array = ({});
  guild_stats_array = ({});

  tmp_array = m_indices(guild_skills);
  for(i=0; i<sizeof(tmp_array); i++)
	guild_skills_array += tmp_array[i] + "|" + guild_skills[tmp_array[i]];

  tmp_array = m_indices(guild_stats);
  for(i=0; i<sizeof(tmp_array); i++)
	guild_stats_array += tmp_array[i] + "|" + guild_stats[tmp_array[i]];
  
  save_object(SAVEPATH+ENV->query_real_name());
  if(!silent) tell_object(ENV, PRED+HIW+"Meijin Stats Saved. "+HIB+"<<"+NORM+"\n");
  return 1;
}

restore_me() {
  string *tmp_array;
  string name;
  int i, amt;

  restore_object(SAVEPATH+ENV->query_real_name());

  for(i=0; i<sizeof(guild_stats_array); i++) {
	if(sscanf(guild_stats_array[i], "%s|%d", name, amt) != 2) {
		tell_object(ENV, "Error!  There was a problem retrieving your stats.\n");
		return 1;
	}
	guild_stats[name] = amt;
  }

  for(i=0; i<sizeof(guild_skills_array); i++) {
	if(sscanf(guild_skills_array[i], "%s|%d", name, amt) != 2) {
		tell_object(ENV, "Error!  There was a problem retrieving your stats.\n");
		return 1;
	}
	guild_skills[name] = amt;
  }
  return 1;
}

/******************/
/* wizard command */
/******************/
debug(str) {
  if(!str) {
	write("Debug on/off ?\n");
	return 1;
  }
  if(str == "on") {
	write("Debug is on.\n");
	skill_variables["debug"] = 1;
	return 1;
  }
  if(str == "off") {
	write("Debug is off.\n");
	skill_variables["debug"] = 0;
	return 1;
  }
}

night_vision_start() {
  set_light(2);
  skill_variables["end_mod"] -= 1;
  skill_variables["nightvision"] = 1;
}

night_vision_stop() {
  set_light(-2);
  skill_variables["end_mod"] += 1;
  remove_skill_variable("nightvision");
}

focus_delay_start() {
  skill_variables["focus_delay"] = 1;
  call_out("focus_delay_end", 35);
}

focus_delay_end() {
  remove_skill_variable("focus_delay");
}

bind_delay_start() {
  skill_variables["bind"] = 1;
  call_out("bind_delay_end", 60);
}

bind_delay_end() {
  remove_skill_variable("bind");
}

xrage_delay_start() {
  remove_action("");
  remove_skill_variable("xrage");
  skill_variables["xrage_delay"] = 1;
  call_out("xrage_delay_end", 50+random(200));
}

xrage_delay_end() { remove_skill_variable("xrage_delay"); }

xpsyche_start(x) {
  skill_variables["xpsyche"] = x;
  call_out("xpsyche_stop", 200+random(400));
}

xpsyche_stop() {
  string *stats;
  int i;
  stats = m_indices(guild_stats);
  for(i=0; i<sizeof(stats); i++) {
	add_guild_bonus(stats[i], -(skill_variables["xpsyche"] + 2));
  }
  tell_object(ENV, PRED+"Your "+HIB+"pyschic"+NORM+" abilities fade away.\n");
  tell_object(ENV, PRED+"You feel tired.\n");
  skill_variables["xpsyche"] = -2;
  call_out("xpsyche_clear", 100+random(300));
  return 1;
}

xpsyche_clear() {
  string *stats;
  int i;
  stats = m_indices(guild_stats);
  for(i=0; i<sizeof(stats); i++) add_guild_bonus(stats[i], -skill_variables["xpsyche"]);
  remove_skill_variables("xpsyche");
  return 1;
}

guild_test(str) {
  write("Removing mapping: "+str+".\n");
  guild_skills = deletem(guild_skills, str);
  write("Ok!\n");
  return 1;
}

