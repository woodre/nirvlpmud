#include "definitions.h"
#define myname ETO->query_real_name()
#define ME ETO

static int muffle, gfollow, hpmon, dmatch;
static string type, follow_ob;
int issensei, isshogun, isregent, isreferee, ishead_ref,
  issenator, isloremaster, iswatcher, isjudge,
  suspend, color, auto_on;
string seq1name, seq2name, seq3name, seq4name,
  art, weapon, garbcolor;
string * seq1; string * seq2; string * seq3; string * seq4;
int guild_lev, guild_exp, bal, artlevel, degree, kills, wimpy_hp;
int corpse, electricflux, magneticflux, heatflux, flash,
  lastic, meld, plate, hide, emt, bionics, blades,
  activate_droid, legs, convert, digest, weplink;
int armor, bion_on, blad_on;
int chop, forearm, finger_jab, palm_flail, quick_punch,
  side_kick, reverse_kick, backfist, drop_kick, front_kick,
  grab, palm_thrust, strong_punch, fierce_punch, head_clap,
  hook, elbow_jab, knee, roundhouse, thrust_kick, uppercut,
  head_butt, lock_and_punch, choke_grab, headlock,
  lock_and_twist, rapid_fist_strike, rapid_kick, lock_and_elbow,
  lock_and_throw, bear_hug, over_the_back_slam, pressure_point;

id(str) { return str == "Implants" || str == "implant"
   || str == "either implants"
   || str == "implants" || str == "CyberNinja Implants"; }
short() { return "CyberNinja Implants";}

long() {
  TE(ME,"This is the CyberNinja guild object.\n"+
        "To recieve information just type 'cyber'.\n");}

extra_look() {
  string stuff, name;
  name = capitalize(myname);
  stuff = ""+name+" has Cybernetic Implants";
if(item_electricflux()) stuff += "\n"+name+" has electric panels";
if(item_emt()) stuff += "\n"+name+" can control emotions";
if(item_magneticflux()) stuff += "\n"+name+" has magnetic panels";
if(item_heatflux()) stuff += "\n"+name+" has heat panels";
if(item_flash()) stuff += "\n"+name+" has bioluminescence";
if(item_lastic()) stuff += "\n"+name+" has super-lastic overarmor";
if(item_meld()) stuff += "\n"+name+" has enduro-meld overarmor";
if(item_plate()) stuff += "\n"+name+" has pressure plate overarmor";
if(item_hide()) stuff += "\n"+name+" has metal hide overarmor";
if(item_corpse()) stuff += "\n"+name+" has a molecular re-organizer";
if(item_bionics()) stuff += "\n"+name+" has bionics";
if(item_blades()) stuff += "\n"+name+" has blades";
if(item_activate_droid()) stuff += "\n"+name+" has a droid unit";
if(item_legs()) stuff += "\n"+name+" has leg actuators";
if(item_convert()) stuff += "\n"+name+" has a matter beam";
if(item_weplink()) stuff += "\n"+name+" has a smartweapon link";
  return stuff; }

get() { return 1; }
drop() { return 1; }

init_arg(str) {
  /* shows guild news at startup */
  cat("/players/dune/closed/guild/docs/news");
return 1; }

reset(arg) {
 if(!arg) {
   muffle = 0; gfollow = 0; hpmon = 0; follow_ob = 0;
    convert = 0; digest = 0;
 }}

enable() { command("connect", ETO); }

init(int num) {
  if(suspended()) {
    write("You are still suspended from the CyberNinjas.\n");
    destruct(this_object()); }
  add_action("restore_me","connect");
  if(!num) call_out("enable", 0);
  if(!num) return;
  ME->set_guild_name("cyberninja");
  if(!ETO->query_ghost()) {
  add_action("save_me","download");
  add_action("net_who", "users");
  add_action("net_channel_emote", "nem");
  add_action("net_channel","net");
  add_action("net_muffle_channel","line");
  add_action("info_database","cyber");
  add_action("rank_info","scan");
  add_action("help_levels","cyberlevels");
  add_action("help_belt_levels","beltlevels");
  add_action("update_implants","newlink");
  add_action("check_time","clock");
  add_action("set_guild_title","set_title");
  add_action("coinsTocredits","creditcoins");
  add_action("coinsTocredits","cc");
  add_action("query_balance","balance");
  add_action("query_balance","bal");
  add_action("weapon","weapon");
  add_action("weapon","wep");
  add_action("listMyAttacks","attacks");
  add_action("listMyAttacks","atts");
  add_action("listEnhancements","enhancements");
  add_action("listEnhancements","ens");
  add_action("listMySequences","sequence");
  add_action("listMySequences","sq");
  add_action("attack_seq","seq");
  add_action("executeSequence","att");
  add_action("goToGuild","transfer");
  add_action("guild_follow1","follow");
  add_action("follow_off","followoff");
  add_action("wear", "wear");
  add_action("color","color");
  add_action("score","sc");
  add_action("score","score");
  add_action("all_who", "gwho");
  add_action("new_start", "origin");
  add_action("wimpy_set","wimpyset");
  add_action("deaths","deaths");
  add_action("scan_news","news");
  add_action("net_deaths","netdeaths");
  add_action("ninja_speak","elate");
  add_action("ninja_speak","el");
  add_action("log_my_deathmatch","log_my_deathmatch");
  add_action("strike","strike");
  add_action("strike","st");
  add_action("cyberware","cyberware");
  add_action("record","record");
  add_action("ninja_kill","kill");
  add_action("auto","auto");
  add_action("death_blow","db");
  add_action("death_blow","deathblow");
/*
  add_action("mon","mon");
*/
  if(guild_lev() >= 2) {
     add_action("mask","mask");
       add_action("power_scan","powerscan");
      add_action("power_scan","pscan");
     add_action("lead","lead"); }
  if(guild_lev() >= 3) {
    add_action("combat_retreat","retreat");
    add_action("bwho","battlewho");
     add_action("bwho","bwho"); }
  if(guild_lev() >= 4) {
     add_action("guild_follow2","stalk");
     add_action("mislead","mislead"); }
  if(guild_lev() >= 5) {
     add_action("align","align"); }
  if(guild_lev() >= 6) {
     add_action("recruit_member","recruit"); }
  if(guild_lev() >= 7) {
    add_action("n_con","ncon");
     add_action("match","challenge"); }
  if(guild_lev() >= 9) {
     add_action("hide_in_shadows","shadows"); }
  if(guild_lev() > 10) {
     add_action("officer_database","fax"); }
  if(sensei() || shogun() || head_referee() || watcher() ||
     senator()) { add_action("officer_database","fax"); }
  if(sensei() || myname == EMP1 || myname == EMP2
              ||     regent()) {
     add_action("advance_art","train");
     add_action("change_art","redirect");
     add_action("pick_attack","pick");
     add_action("change_attack","change_attack"); }
  if(shogun() || judge() || myname == EMP1 ||
                 myname == EMP2 || regent()) {
     add_action("unsuspend","unsuspend");
     add_action("guild_balance","gbalance");
     add_action("all_file_watcher","logall");
     add_action("end_file_watcher","logend");
     add_action("other_rank_info","oscan");
     add_action("report","report");
     add_action("empower","empower");
     add_action("tourney","tourney"); }
  if(shogun() || myname == EMP1
              || myname == EMP2 || regent()) {
     add_action("enhance","enhance"); }
  if(judge() || myname == EMP1 ||
                myname == EMP2 || regent()) {
     add_action("suspend","suspend");
     add_action("execute","execute"); }
  if(referee() || head_referee()) {
     add_action("report","report");
     add_action("tourney","tourney"); }
  if(head_referee() || regent() || myname == EMP1
                    || myname == EMP2) {
     add_action("refassist","refassist");
     add_action("unref","unref"); }
  if(watcher()) {
     add_action("all_file_watcher","logall");
     add_action("end_file_watcher","logend"); }
  if(regent() || myname == EMP1 || myname == EMP2) {
     add_action("addxp","addxp");
     add_action("setArt","set_art");
     add_action("setArtLevel","set_art_level");
     add_action("setWeapon","set_weapon");
     add_action("addCredits","add_credits"); }
  if(myname == EMP1 || myname == EMP2) {
     add_action("upall","upall"); }
  /* enhancements */
  if(corpse) {
    add_action("corpse","decorpse");
    add_action("regenerate","regenerate");
    add_action("rejuvenate","rejuvenate");
    add_action("meta_conversion","digest");
    }
  if(electricflux) add_action("electricflux","eflux");
  if(magneticflux) add_action("magneticflux", "mflux");
  if(heatflux) add_action("heatflux", "hflux");
  if(flash) add_action("flash", "glimmer");
  if(lastic) add_action("lastic", "lastic");
  if(meld) add_action("meld", "meld");
  if(plate) add_action("plate", "plate");
  if(hide) add_action("hide", "hide");
  if(emt) add_action("emt","emt");
  if(bionics) add_action("bionics", "bion");
  if(blades) add_action("blades","blad");
  if(activate_droid) add_action("activate_droid", "droid");
  if(legs) add_action("speed_run", "speedrun");
  if(convert) {
    add_action("matter_conversion","conversion");
    add_action("matter_burn","overload");
              }
  } }

save_me() {
  string file;
  file = SAVE + myname;
  if(!save_object(file)) {
    tell_object(ME,"Cyberlink error...\n");
    return 0;}
  return 1;}

restore_me() {
  string file;
  file = SAVE + myname;
  if(!restore_object(file)) {
    tell_object(ME,"Cyberlink error...\n");
    return 0;}
  init(1);
  return 1;}

int guild_exp() { return guild_exp;}
set_rank(int amount) { guild_lev = amount; }
int guild_lev() { return guild_lev;}
set_wimpy_hp(int new) { wimpy_hp = new; }
int query_wimpy_hp() { return wimpy_hp; }
set_xp(int amount) { guild_exp = amount;}
add_xp(int amount) { guild_exp += amount;}
set_sensei(int new) { issensei = new; }
int sensei() { return issensei; }
set_shogun(int new) { isshogun = new; }
int shogun() { return isshogun; }
int watcher() { return iswatcher; }
set_watcher(int new) { iswatcher = new; }
int regent() { return isregent; }
set_regent(int new) { isregent = new; }
int referee() { return isreferee; }
int head_referee() { return ishead_ref; }
set_head_referee(int new) { ishead_ref = new; }
set_referee(int new) { isreferee = new; }
set_senator(int new) { issenator = new; }
set_judge(int new) { isjudge = new; }
int judge() { return isjudge; }
int senator() { if(issenator || isjudge) return 1;
                else return 0; }
set_loremaster(int new) { isloremaster = new; }
int loremaster() { return isloremaster; }
string query_art() { return art; }
int query_art_level() { return artlevel; }
set_art(string new) { art = new; }
set_art_level(int new) { artlevel = new; }
int query_degree() { return degree; }
set_degree(int new) { degree = new; }
int muffled() { return muffle;}
set_muffle(int new_muffle) { muffle = new_muffle;}
int balance() { return bal; }
addToBalance(int amount) { bal += amount; }
string query_weapon() { return weapon; }
set_weapon(string wep) { weapon = wep; }
int suspended() { return suspend; }
set_suspended(new) { suspend = new; }
string * query_attack_seq1() { return seq1; }
string * query_attack_seq2() { return seq2; }
string * query_attack_seq3() { return seq3; }
string * query_attack_seq4() { return seq4; }
set_attack_seq1(string * new) { seq1 = new; }
set_attack_seq2(string * new) { seq2 = new; }
set_attack_seq3(string * new) { seq3 = new; }
set_attack_seq4(string * new) { seq4 = new; }
string query_seq1_name() { return seq1name; }
string query_seq2_name() { return seq2name; }
string query_seq3_name() { return seq3name; }
string query_seq4_name() { return seq4name; }
set_seq1_name(string new) { seq1name = new; }
set_seq2_name(string new) { seq2name = new; }
set_seq3_name(string new) { seq3name = new; }
set_seq4_name(string new) { seq4name = new; }
int query_gfollow() { return gfollow; }
set_gfollow(int new) { gfollow = new; }
string query_follow_ob() { return follow_ob; }
set_follow_ob(string new) { follow_ob = new; }
int query_hpmon() { return hpmon; }
set_hpmon(int new) { hpmon = new; }
set_garbcolor(string new) { garbcolor = new; }
string query_garbcolor() { return garbcolor; }
set_color(int new) { color = new; }
int query_color() { return color; }
int query_kills() { return kills; }
add_kills(int new) { kills += new; }
set_kills(int new) { kills = new; }
get_deathmatch_permission(int new) { dmatch = new; }
int query_deathmatch_permission() { return dmatch; }
do_light(int new) { set_light(new); }
int auto_mon() { return auto_on; }
set_auto(int new) { auto_on = new; }
int query_auto() { return auto_on; }
int query_digest() { return digest; }
set_digest(int num) { digest = num; }

set_armor(int new) { armor = new; }
int query_armor() { return armor; }
set_bion_on(int new) { bion_on = new; }
int query_bion_on() { return bion_on; }
set_blad_on(int new) { blad_on = new; }
int query_blad_on() { return blad_on; }

int query_chop(){return chop;}
set_chop(int new){chop=new;}
int query_forearm(){return forearm;}
set_forearm(int new){forearm=new;}
int query_finger_jab(){return finger_jab;}
set_finger_jab(int new){finger_jab=new;}
int query_palm_flail(){return palm_flail;}
set_palm_flail(int new){palm_flail=new;}
int query_quick_punch(){return quick_punch;}
set_quick_punch(int new){quick_punch=new;}
int query_side_kick(){return side_kick;}
set_side_kick(int new){side_kick=new;}
int query_reverse_kick(){return reverse_kick;}
set_reverse_kick(int new){reverse_kick=new;}
int query_backfist(){return backfist;}
set_backfist(int new){backfist=new;}
int query_drop_kick(){return drop_kick;}
set_drop_kick(int new){drop_kick=new;}
int query_front_kick(){return front_kick;}
set_front_kick(int new){front_kick=new;}
int query_grab(){return grab;}
set_grab(int new){grab=new;}
int query_palm_thrust(){return palm_thrust;}
set_palm_thrust(int new){palm_thrust=new;}
int query_strong_punch(){return strong_punch;}
set_strong_punch(int new){strong_punch=new;}
int query_fierce_punch(){return fierce_punch;}
set_fierce_punch(int new){fierce_punch=new;}
int query_head_clap(){return head_clap;}
set_head_clap(int new){head_clap=new;}
int query_hook(){return hook;}
set_hook(int new){hook=new;}
int query_elbow_jab(){return elbow_jab;}
set_elbow_jab(int new){elbow_jab=new;}
int query_knee(){return knee;}
set_knee(int new){knee=new;}
int query_roundhouse(){return roundhouse;}
set_roundhouse(int new){roundhouse=new;}
int query_thrust_kick(){return thrust_kick;}
set_thrust_kick(int new){thrust_kick=new;}
int query_uppercut(){return uppercut;}
set_uppercut(int new){uppercut=new;}
int query_head_butt(){return head_butt;}
set_head_butt(int new){head_butt=new;}
int query_lock_and_punch(){return lock_and_punch;}
set_lock_and_punch(int new){lock_and_punch=new;}
int query_choke_grab(){return choke_grab;}
set_choke_grab(int new){choke_grab=new;}
int query_headlock(){return headlock;}
set_headlock(int new){headlock=new;}
int query_lock_and_twist(){return lock_and_twist;}
set_lock_and_twist(int new){lock_and_twist=new;}
int query_rapid_fist_strike(){return rapid_fist_strike;}
set_rapid_fist_strike(int new){rapid_fist_strike=new;}
int query_rapid_kick(){return rapid_kick;}
set_rapid_kick(int new){rapid_kick=new;}
int query_lock_and_elbow(){return lock_and_elbow;}
set_lock_and_elbow(int new){lock_and_elbow=new;}
int query_lock_and_throw(){return lock_and_throw;}
set_lock_and_throw(int new){lock_and_throw=new;}
int query_bear_hug(){return bear_hug;}
set_bear_hug(int new){bear_hug=new;}
int query_over_the_back_slam(){return over_the_back_slam;}
set_over_the_back_slam(int new){over_the_back_slam=new;}
int query_pressure_point(){return pressure_point;}
set_pressure_point(int new){pressure_point=new;}

int item_corpse() { return corpse; }
int item_electricflux() { return electricflux; }
int item_magneticflux() { return magneticflux; }
int item_heatflux() { return heatflux; }
int item_flash() { return flash; }
int item_lastic() { return lastic; }
int item_meld() { return meld; }
int item_plate() { return plate; }
int item_hide() { return hide; }
int item_emt() { return emt; }
int item_bionics() { return bionics; }
int item_blades() { return blades; }
int item_activate_droid() { return activate_droid; }
int item_legs() { return legs; }
int item_convert() { return convert; }
int item_weplink() { return weplink; }
add_weplink(int num) { weplink += num; }

set_corpse(int num) { corpse = num; }
set_electricflux(int num) { electricflux = num; }
set_magneticflux(int num) { magneticflux = num; }
set_heatflux(int num) { heatflux = num; }
set_flash(int num) { flash = num; }
set_lastic(int num) { lastic = num; }
set_meld(int num) { meld = num; }
set_plate(int num) { plate = num; }
set_hide(int num) { hide = num; }
set_emt(int num) { emt = num; }
set_bionics(int num) { bionics = num; }
set_blades(int num) { blades = num; }
set_activate_droid(int num) { activate_droid = num; }
set_legs(int num) { legs = num; }
set_convert(int num) { convert = num; }
set_weplink(int num) { weplink = num; }

guild_tell(str) { TOOL->guild_tell(str); return 1; }
guild_emote(str) { TOOL->guild_emote(str); return 1; }
guild_who() { TOOL->guild_who(); return 1; }
enhance(str) { TOOL->enhance(str); return 1; }
addxp(str) { TOOL->addxp(str); return 1; }
info_database(str) { TOOL->info_database(str); return 1; }
help_levels() { TOOL->help_levels(); return 1; }
help_belt_levels() { TOOL->help_belt_levels(); return 1; }
net_channel_emote(str) { TOOL->net_channel_emote(str); return 1; }
net_muffle_channel(str) { TOOL->net_muffle_channel(str); return 1; }
net_who() { TOOL->net_who(); return 1; }
n_con() { TOOL->n_con(); return 1; }
net_channel(str) { TOOL->net_channel(str); return 1; }
rank_info() { TOOL->rank_info(); return 1; }
check_time() { TOOL->check_time(); return 1; }
guild_title(arg) { TOOL->guild_title(arg); return 1; }
set_guild_title() { TOOL->set_guild_title(); return 1; }
recruit_member(str) { TOOL->recruit_member(str); return 1; }
coinsTocredits(str) { TOOL->coinsTocredits(str); return 1; }
query_balance() { TOOL->query_balance(); return 1; }
guild_balance() { TOOL->guild_balance(); return 1; }
advance_art(str) { TOOL->advance_art(str); return 1; }
change_art(str) { TOOL->change_art(str); return 1; }
pick_attack(str) { TOOL->pick_attack(str); return 1; }
change_attack(str) { TOOL->change_attack(str); return 1; }
empower(str) { TOOL->empower(str); return 1; }
weapon(str) { TOOL->weapon(str); return 1; }
listMyAttacks(str) { TOOL->listMyAttacks(str); return 1; }
listEnhancements(str) { TOOL->listEnhancements(str); return 1; }
listMySequences(str) { TOOL->listMySequences(str); return 1; }
setArt(str) { TOOL->setArt(str); return 1; }
setArtLevel(str) { TOOL->setArtLevel(str); return 1; }
setWeapon(str) { TOOL->setWeapon(str); return 1; }
addCredits(str) { TOOL->addCredits(str); return 1; }
attack_seq(str) { TOOL->attack_seq(str); return 1; }
executeSequence(str) { TOOL->executeSequence(str); return 1; }
goToGuild() { TOOL->goToGuild(); return 1; }
guild_follow1(str) { TOOL->guild_follow1(str); return 1; }
guild_follow2(str) { TOOL->guild_follow2(str); return 1; }
follow_off() { TOOL->follow_off(); return 1; }
mon() { TOOL->mon(); return 1; }
officer_database(str) { TOOL->officer_database(str); return 1; }
wear(str) { TOOL->wear(str); return 1; }
color() { TOOL->color(); return 1; }
score() { TOOL->score(); return 1; }
mislead(str) { TOOL->mislead(str); return 1; }
guide(str) { TOOL->guide(str); return 1; }
report(str) { TOOL->report(str); return 1; }
tourney() { TOOL->tourney(); return 1; }
new_start() { TOOL->new_start(); return 1; }
wimpy_set(str) { TOOL->wimpy_set(str); return 1; }
combat_retreat() { TOOL->combat_retreat(); return 1; }
lead() { TOOL->lead(); return 1; }
power_scan(str) { TOOL->power_scan(str); return 1; }
bwho() { TOOL->bwho(); return 1; }
all_who() { TOOL->all_who(); return 1; }
ninja_speak(str) { TOOL->ninja_speak(str); return 1; }
align(str) { TOOL->align(str); return 1; }
match(str) { TOOL->match(str); return 1; }
mask(str)  { TOOL->mask(str); return 1; }
deaths(str) { TOOL->deaths(str); return 1; }
scan_news() { TOOL->scan_news(); return 1; }
net_deaths() { TOOL->net_deaths(); return 1; }
refassist(str) { TOOL->refassist(str); return 1; }
unref(str) { TOOL->unref(str); return 1; }
suspend(str) { TOOL->suspend(str); return 1; }
unsuspend(str) { TOOL->unsuspend(str); return 1; }
execute(str) { TOOL->execute(str); return 1; }
log_my_deathmatch(str) { TOOL->log_my_deathmatch(str); return 1; }
strike(str) { TOOL->strike(str); return 1; }
cyberware() { TOOL->cyberware(); return 1; }
hide_in_shadows() { TOOL->hide_in_shadows(); return 1; }
all_file_watcher(str) { TOOL->all_file_watcher(str); return 1; }
end_file_watcher(str) { TOOL->end_file_watcher(str); return 1; }
record(str) { TOOL->record(str); return 1; }
upall() { TOOL->upall(); return 1; }
other_rank_info(str) { TOOL->other_rank_info(str); return 1; }
ninja_kill(str) { TOOL->ninja_kill(str); } /* do not return */
auto(str) { TOOL->auto(str); return 1; }
death_blow(str) { TOOL->death_blow(str); return 1; }

/* enhancement functions */
corpse() { TOOL->corpse(); return 1; }
electricflux(str) { TOOL->electricflux(str); return 1; }
magneticflux(str) { TOOL->magneticflux(str); return 1; }
heatflux(str) { TOOL->heatflux(str); return 1; }
flash() { TOOL->flash(); return 1; }
lastic() { TOOL->lastic(); return 1; }
meld() { TOOL->meld(); return 1; }
plate() { TOOL->plate(); return 1; }
hide() { TOOL->hide(); return 1; }
emt(str) { TOOL->emt(str); return 1; }
bionics() { TOOL->bionics(); return 1; }
blades() { TOOL->blades(); return 1; }
activate_droid() { TOOL->activate_droid(); return 1; }
speed_run() { TOOL->speed_run(); return 1; }
matter_conversion() { TOOL->matter_conversion(); return 1; }
matter_burn() { TOOL->matter_burn(); return 1; }
regenerate() { TOOL->regenerate(); return 1; }
rejuvenate() { TOOL->rejuvenate(); return 1; }
meta_conversion() { TOOL->meta_conversion(); return 1; }

update_implants() {
   object implants, this_ob; TE(ME, "Updating implants.\n");
   implants=clone_object("/players/dune/closed/guild/implants.c");
   this_ob = present("implants", ME);
   move_object(implants, ME); destruct(this_ob);
   implants->init(1); return 1; }

fake_beat(int num) {
  if(num == 0) { remove_call_out("fake_beat"); return 1; }
  if(num == 1) {
    if(hpmon == 0) return -1;
    TOOL->combat_monitor(ME);
    call_out("fake_beat",3,1);
    return 1;
  }
  if(num == 2) {
    if(!bion_on) return -2;
    TOOL->biodam(ME);
    call_out("fake_beat",5,2);
    return 1;
  }
  if(num == 3) {
    if(!blad_on) return -3;
    TOOL->bladedam(ME);
    call_out("fake_beat",8,3);
    return 1;
  }
}
