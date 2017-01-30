#define GUILD_ID "Mizan-guild-object"
#define MORPH_ID "Mizan-morph-object"
#define GUILD_NAME "polymorph"

#define GUILDFILE "/players/mizan/closed/poly/gob.c"
#define MASTER_R "/players/mizan/closed/poly/PDM.c"
#define SAVE_PATH "players/mizan/closed/poly/players/"
#define ENV (environment(this_object()))
#define CHARGE_MAX 2300

/* toggles */
int invis_tl;
int muffle_tl;
int window_tl;
int monitor_tl;
int msg_tl;
int moncharge_tl;
int drain_tl;
int eval_tl;
int news_tl;
int max_tl;
int rf_tl;

/* set variables */
int monitor_interval;
int screen_height;
int wimpy_pct;

string curr_morph;

string saved_pretitle;
string saved_title;
string main_stats;

int news_index;

string panic_key;
int autocharge_tl;
string superstat_key;
string nickname;
string sig;
string doing;
string msgin;
string msgout;
string thingname;
string thingcomm;

int charge_power;
/* others */
static object follow_ob;
static string comm_prefix;
static string self_file;
static string new_hd;
static string new_body;
static int monitor_call;

int computed_EXP;
static int entry_exp;
static int exit_exp;
static int age;
id(str) { return str == GUILD_ID || str == "GI" || str == "ND" || str == "lump" || str == "clay"; }

short() {
  if(invis_tl && this_player()) {
    if(this_player()->query_guild_name() == GUILD_NAME ||
    this_player()->query_level() > 20) return "A lump of magical clay (invis)";
    else return 0;
  }
  return "A lump of magical clay";

}

long() {
  write("This appears to be just any old lump of clay but it has many\n"+

  "powers and abilities, the most important of them keeping the matrix\n"+
  "of your being- which frees you to polymorph into different shapes.\n"+
  "It pulsates with a strangely powerful yet pleasant feeling.\n\n"+

  "Type 'info' for a list of info and abilities.\n");

  if(charge_power) write("There are [" + charge_power + "] charges accumulated in the clay's matrix.\n");
}


get() { return 1; }

drop() { return 1; }

query_original() { return 1; }
query_drain() { return drain_tl; }
query_eval() { return eval_tl; }
query_invis() { return invis_tl; }

query_max() { return max_tl; }
query_monitor() { return monitor_tl; }

query_muffle() { return muffle_tl; }
query_moncharge() { return moncharge_tl; }
query_news_announce() { return news_tl; }
query_window() { return window_tl; }


query_main_stats() { return main_stats; }
query_charge() {
  if(charge_power < 0) charge_power = 0;
  return charge_power;
}
query_morph_comm() { return comm_prefix; }
query_current_morph() { return curr_morph; }

query_pretitle() { return saved_pretitle; }
query_title() { return saved_title; }

query_wimpy_pct() { return wimpy_pct; }

query_nickname() { return nickname; }
query_sig() { return sig; }
query_doing() { return doing; }
query_msgin() { return msgin; }
query_msgout() { return msgout; }
query_panic_key() { return panic_key; }
query_autocharge() { return autocharge_tl; }
query_msg() { return msg_tl; }
query_superstat_key() { return superstat_key; }
query_screen_height() { return screen_height; }
query_monitor_interval() { return monitor_interval; }
query_news_index() { return news_index; }
query_thing_name() { return thingname; }
query_thing_comm() { return thingcomm; }

query_follow_ob() { return follow_ob; }

set_current_morph(str) { curr_morph = str; }

set_morph_comm(str) { comm_prefix = str; }
set_pretitle(str) { saved_pretitle = str; }
set_title(str) { saved_title = str; }

set_nickname(str) { nickname = str; }
set_sig(str) { sig = str; }
set_doing(str) { doing = str; }
set_msgout(str) { msgout = str; }
set_msgin(str) { msgin = str; }
set_panic_key(str) { panic_key = str; }
toggle_autocharge() { autocharge_tl = !autocharge_tl; }
toggle_msg() { msg_tl = !msg_tl; }

set_wimpy_pct(arg) { wimpy_pct = arg; }
set_superstat_key(str) { superstat_key = str; }

set_screen_height(str) { screen_height = str; }
set_monitor_interval(str) { monitor_interval = str; }
set_news_index(str) { news_index = str; }
set_thing_name(str) { thingname = str; }
set_thing_comm(str) { thingcomm = str; }

set_follow_ob(arg) { follow_ob = arg; }
set_main_stats(str) { main_stats = str; }

reset(arg) {
  if(!arg) call_out("delayed_reset", 1);
}

delayed_reset() {
  if(ENV) {
   if(ENV->query_level() < 21)
    log_file("mizan.gob", (ENV->query_real_name()) + " " + ctime() + "\n");
    self_file = ENV->query_real_name();
    if(!restore_object(SAVE_PATH + self_file) && ENV->query_level() < 21) destruct(this_object());
    if(!curr_morph) curr_morph = "none";
    if(!panic_key) panic_key = "c";
    if(!superstat_key) superstat_key = "q";
    if(!monitor_interval) monitor_interval = 3;
    if(!screen_height) screen_height = 23;
    if(!doing) doing = "wandering";
    if(!msgin) msgin = "enters the confusion.";
    if(!msgout) msgout = "has left the building.";
    if(!sig) sig = ENV->query_name();
    command("set statkey " + superstat_key, ENV);
    command("set panic " + panic_key, ENV);
    MASTER_R->entrance(ENV);
    monitor_display();
    fake_beat();
    /* added by wizardchild to allow invis login */
    if(ENV->query_invis() < 40)
    if(msgin && msg_tl) command("vibe :" + msgin, ENV);
  entry_exp = ENV->query_exp();

  }
}


fake_beat() {
  if(ENV) {
  if(wimpy_pct && ENV->query_attack() &&
  ((ENV->query_hp() * 100) / ENV->query_mhp()) < wimpy_pct)
  {
    if(follow_ob) {
      tell_object(ENV, "You disengage follow.\n");
      follow_ob = 0;
    }
    tell_object(ENV, "You panic and flee for your life!\n");
    ENV->run_away(); }

    if(curr_morph != "none" && !present(MORPH_ID, ENV)) MASTER_R->undo_polymorph(ENV);
    if(ENV->query_dead()) MASTER_R->undo_polymorph(ENV);
    if(follow_ob) update_follow();

    if(ENV->query_attack()) monitor_display();
    else if(monitor_tl && monitor_call >= monitor_interval) monitor_display();
    if(autocharge_tl && ENV->query_sp() == ENV->query_msp()) {
  /* added afterthought -mizan */
  if(!ENV->query_attack())
      if(curr_morph == "none" || curr_morph == "wombat") command("charge 10", ENV);
    }
    monitor_call++;
  }
  age ++;
  remove_call_out("fake_beat");
  call_out("fake_beat",1);
}


monitor_display() {
  if(max_tl) {
    if(ENV->query_mhp() == ENV->query_hp() &&
    ENV->query_msp() == ENV->query_sp()) return 0;
  }
/*
  if(window_tl) MASTER_R->superstat_window(ENV, screen_height);
 */
  if(moncharge_tl) MASTER_R->superstat(ENV, charge_power);
  else MASTER_R->superstat(ENV);
  monitor_call = 0;
}

init() {
  add_action("guild_function","guild");
  add_action("polymorph_function","polymorph");
  add_action("set_function","set");
  add_action("info_function","info");
  add_action("toggle_function","toggle");

  add_action("guild_tell","vibe");
  add_action("guild_tell","gt");
  add_action("guild_emote_alias","ge");
  add_action("superwho","superwho");
  add_action("regain_corpse","regain");
  add_action("regain_corpse","rc");
  add_action("charge_clay","charge");
  add_action("atomize_object","atomize");
  add_action("survey_area","survey");
  add_action("helpme","helpme");
  add_action("ether","ether");
  add_action("fast_Do","Do");

  add_action("revert","revert");
  add_action("follow","follow");


  add_action("do_clock","clock");
  add_action("do_score","score");
  add_action("do_score","sc");
  add_action("do_quit","quit");

  add_action("b_pretitle","pretitle");
  add_action("b_kill_player","kill_players");
  add_action("mod_say", "say");
  add_action("mod_emote", "emote");

#ifndef __LDMUD__
  add_action("mod_say"); add_xverb(";");
  add_action("mod_say"); add_xverb("\"");
  add_action("mod_say"); add_xverb("`");
#else
  add_action("mod_say", ";", 3);
  add_action("mod_say", "\"", 3);
  add_action("mod_say", "`", );
#endif

  add_action("mod_emote", ":");

/*
  add_action("news_delete_group","Nk");
*/
  add_action("news_post","Np");
  add_action("news_read","Nr");
  add_action("news_delete","Nd");
/*
  add_action("news_add_group","Na");
 */
  add_action("news_headers","Nh");
  add_action("news_grouplist","Nl");
  add_action("news_next_group","Nn");
  add_action("news_goto_group","Ng");

  add_action("beatfix","beatfix");
  if(panic_key) add_action("flee",panic_key);
  if(superstat_key) add_action("superstat",superstat_key);
  if(this_player()->query_level() > 19) {
    add_action("promo_player","promo");
  }
}

beatfix() {
  object ob;
  this_player()->reset(1);
  this_player()->set_heart_beat(1);
  fake_beat();
  ob = present(MORPH_ID, this_player());
  if(ob) ob->fake_beat();
  write("You thump yourself in the chest and your heart starts beating again.\n");
  return 1;
}
add_charge(arg) {
  charge_power = charge_power + arg;
  if(charge_power > CHARGE_MAX) {
    charge_power = CHARGE_MAX;
    write("Charges have been maximized at [" + charge_power + "].\n");
    if(autocharge_tl) {
      write("Autocharge turned OFF.\n");
      toggle_autocharge();
    }
  }
  record_attribs();
}

toggle_eval() { eval_tl = !eval_tl; }
toggle_drain() { drain_tl = !drain_tl; }
toggle_invis() { invis_tl = !invis_tl; }
toggle_muffle() { muffle_tl = !muffle_tl; }
toggle_moncharge() { moncharge_tl = !moncharge_tl; }
toggle_news_announce() { news_tl = !news_tl; }

toggle_max() { max_tl = !max_tl; }
toggle_window() { window_tl = !window_tl; }
toggle_monitor() { monitor_tl = !monitor_tl; }

do_clock() { return MASTER_R->do_clock(); }
do_score() { return MASTER_R->do_score(); }
do_quit() {
  if(curr_morph != "none")
  MASTER_R->undo_polymorph();
  /* added by wizardchild to allow invis logout */
  if(this_player()->query_invis() < 40)
  if(msgout && msg_tl) command("vibe :" + msgout, this_player());
  exit_exp = this_player()->query_exp();
    computed_EXP = entry_exp - exit_exp;
  if(computed_EXP > 1) {
  if(age > 1800)
    log_file("mizan.gl", (this_player()->query_real_name()) +
    " " + (computed_EXP / (age / 1800)) + "\n");
  }
  record_attribs();
  this_player()->quit();
}


b_pretitle(str) { write("Use 'set pretitle <arg>'.\n"); return 1; }
b_kill_player() { 

  if(curr_morph != "none") {

    write("You fail.\n");
    return 1;
  } else {
    write("In becoming a player killer you can no longer polymorph.\n");
    return 0;
  }
}

mod_say(str) { return MASTER_R->mod_say(str); }
mod_emote(str) { return MASTER_R->mod_emote(str); }

flee() {
  if(curr_morph == "tetrapod" || curr_morph == "spiral") {
    write("You would rather stand and die fighting that flee like a coward.\n");
    return 1;
  }  
  if(this_player()->query_attack()) {
    this_player()->run_away();
    return 1;
  } else {
    write("Relax! You're not fighting anything...\n");
    return 1;
  }

}

record_attribs() { save_object(SAVE_PATH + self_file); }

polymorph_function(str) { return MASTER_R->polymorph_function(str); }
toggle_function(str) { return MASTER_R->toggle_function(str); }
set_function(str) { return MASTER_R->set_function(str); }

info_function(str) { return MASTER_R->info_function(str); }
guild_function(str) { return MASTER_R->guild_function(str); }

fast_Do(str) { return MASTER_R->fast_Do(str); }

guild_tell(str) { return MASTER_R->guild_tell(str); }
guild_emote_alias(str) { return MASTER_R->guild_tell(":" + str); }
superstat() { MASTER_R->superstat(ENV, charge_power); return 1; }
superwho(str) { return MASTER_R->superwho(str); }

regain_corpse() { return MASTER_R->regain_corpse(); }
charge_clay(arg) { return MASTER_R->charge_clay(arg); }
atomize_object(str) { return MASTER_R->atomize_object(str); }
survey_area() { return MASTER_R->survey_area(); }

helpme() { return MASTER_R->helpme(); }
ether(str) { return MASTER_R->ether(str); }
all_player_charges() { return MASTER_R->all_player_charges(); }

promo_player(str) { return MASTER_R->promo_player(str); }

revert(arg) {
  object mob;
  if(curr_morph == "none") {
    write("You are not polymorphed as anything.\n");
    if(!arg || arg != "me") return 1;
    else return MASTER_R->undo_polymorph(ENV,1);
  }
    mob = present(MORPH_ID, ENV);
    if(!mob) return MASTER_R->undo_polymorph();
    mob->unstrap_all();
    return MASTER_R->undo_polymorph();
}

follow(str) { return MASTER_R->follow(str); }

update_follow() {
  if(environment(ENV) == environment(follow_ob)) return 0;
  ENV->say((ENV->query_name()) + " leaves following " + (follow_ob->query_name()) + ".\n"); 
  move_object(ENV, environment(follow_ob));
  ENV->say((ENV->query_name()) + " arrives following " + (follow_ob->query_name()) + ".\n"); 
    tell_object(ENV, "You follow " + (follow_ob->query_name()) +
  ", Destination: [" + environment(ENV)->short() + "].\n");
  if(environment(ENV)->query_realm() == "NT") {
    ENV->say((ENV->query_name()) + " suddenly gets distracted and breaks off follow.\n"); 
    tell_object(ENV, "Something in this room negates your follow.\n");
    follow_ob = 0;
  }
}

/* news stuff */

news_read(str) { return MASTER_R->news_read(str); }
news_delete(str) { return MASTER_R->news_delete(str); }
news_delete_group(str) { return MASTER_R->news_delete_group(str); }
news_add_group(str) { return MASTER_R->news_add_group(str); }
news_headers() { return MASTER_R->news_headers(); }
news_grouplist() { return MASTER_R->news_grouplist(); }
news_next_group() { return MASTER_R->news_next_group(); }
news_goto_group(arg) { return MASTER_R->news_goto_group(arg); }

news_post(str) {
  if(!MASTER_R->news_post_check(str)) return 1;
  input_to("get_body");
  new_hd = str;
  new_body = "";
  return 1;
}



get_body(str) {
  if(str == "**") {
    MASTER_R->news_feed(new_hd,new_body);
    new_body = 0; new_hd = 0;
    return 1;
  }
  if(str == "~q") {
    write("\n>> Aborted.\n");
    new_body = 0; new_hd = 0;
    return 1;
  }
  new_body = new_body + str + "\n";
  write("]");
  input_to("get_body");
}


