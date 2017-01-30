#include "definitions.h"
#define myname ETO->query_real_name()
#define ME ETO

static int muffle, dmatch;
static string type;
int issensei, isshogun, isregent, isreferee, ishead_ref,
  suspend, color, tough_on;
string art;
string weapon, garbcolor;
int guild_lev, guild_exp, bal, artlevel, degree, kills, wimpy_hp;
int corpse, electricflux, magneticflux, heatflux, flash,
  lastic, meld, plate, hide, emt, bionics, blades,
  activate_droid, legs, convert, digest, weplink;
int armor, bion_on, blad_on;
int rejuv_on, regen_on, equil_on, auto_att, auto_def;

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
  cat("/players/snow/closed/cyber/docs/news");
return 1; }

reset(arg) {
 if(!arg) {
    muffle = 0;
    convert = 0; digest = 0;
    bion_on = 0; blad_on = 0; 
    equil_on = 0; regen_on = 0; rejuv_on = 0;
    /* set_heart_beat(1);  - changed by Mythos <1-30-96> */
    call_out("faked_beat",5);
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
/* Closed until further notice. -Bp */
/*
write("The Cybers are disabled until further notice. -Bp \n");
if(this_player())
if(this_player()->query_level() > 20){
*/
write("I have lifted the closing for the time being. -Bp. \n");
  add_action("coinsTocredits","creditcoins");
  add_action("coinsTocredits","cc");
  add_action("query_balance","balance");
  add_action("query_balance","bal");
  add_action("weapon","weapon");
  add_action("weapon","wep");
  add_action("show_attacks","attacks");
  add_action("show_attacks","atts");
  add_action("listEnhancements","enhancements");
  add_action("listEnhancements","ens");
  add_action("goToGuild","transfer");
  add_action("wear", "wear");
  add_action("color","color");
  add_action("score","sc");
  add_action("score","score");
  add_action("all_who", "gwho");
  add_action("new_start", "origin");
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
  add_action("auto","auto");
  add_action("death_blow","db");
  add_action("death_blow","deathblow");
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
     add_action("mislead","mislead"); }
  if(guild_lev() >= 5) {
    }
  if(guild_lev() >= 6) {
     add_action("recruit_member","recruit"); }
  if(guild_lev() >= 7) {
    add_action("n_con","ncon");
     add_action("match","challenge"); }
  if(guild_lev() >= 9) {
  add_action("hide_in_shadows","shadows");
}
  if(guild_lev() > 10) {
     add_action("officer_database","fax"); }
  if(sensei() || shogun() || head_referee()) {
    add_action("officer_database","fax"); }
  if(sensei() || myname == EMP1 || myname == EMP2
              ||     regent()) {
     add_action("advance_art","train");
    }
  if(shogun() || myname == EMP1 ||
                 myname == EMP2 || regent()) {
     add_action("unsuspend","unsuspend");
     add_action("guild_balance","gbalance");
     add_action("all_file_watcher","logall");
     add_action("end_file_watcher","logend");
     add_action("other_rank_info","oscan");
     add_action("report","report");
     add_action("empower","empower");
     add_action("tourney","tourney"); }
  if(myname == EMP1
              || myname == EMP2 || regent()) {
     add_action("enhance","enhance"); }
  if(myname == EMP1 ||
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
    add_action("reg","reg");
    add_action("rej","rej");
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
    add_action("equil","equil");
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
int query_wimpy_hp() { return wimpy_hp; }
set_xp(int amount) { guild_exp = amount;}
add_xp(int amount) { guild_exp += amount;}
set_sensei(int new) { issensei = new; }
int sensei() { return issensei; }
set_shogun(int new) { isshogun = new; }
int shogun() { return isshogun; }
int regent() { return isregent; }
set_regent(int new) { isregent = new; }
int referee() { return isreferee; }
int head_referee() { return ishead_ref; }
set_head_referee(int new) { ishead_ref = new; }
set_referee(int new) { isreferee = new; }
string query_art() { return "Ninjitsu"; }
int query_art_level() { return artlevel; }
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
set_garbcolor(string new) { garbcolor = new; }
string query_garbcolor() { return garbcolor; }
set_color(int new) { color = new; }
int query_color() { return color; }
int query_kills() { return kills; }
add_kills(int new) { kills += new; }
set_kills(int new) { kills = new; }
get_deathmatch_permission(int new) { dmatch = new; }
int query_deathmatch_permission() { return dmatch; }
do_light(int new) { if(new > 2) new = 2;  
                    if(new < -2) new = -2;
                     set_light(new); }

set_tough(int num) { tough_on = num; }
int query_tough() { return tough_on; }
int query_digest() { return digest; }
set_digest(int num) { digest = num; }
set_rejuv(int num) { rejuv_on = num; }
int query_rejuv() { return rejuv_on; }
set_regen(int num) { regen_on = num; }
int query_regen() { return regen_on; }
set_equil(int num) { equil_on = num; }
int query_equil() { return equil_on; }

set_armor(int new) { armor = new; }
int query_armor() { return armor; }
set_bion_on(int new) { bion_on = new; }
int query_bion_on() { return bion_on; }
set_blad_on(int new) { blad_on = new; }
int query_blad_on() { return blad_on; }
set_auto_att(int num) { auto_att = num; }
int query_auto_att() { return auto_att; }
set_auto_def(int num) { auto_def = num; }
int query_auto_def() { return auto_def; }


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
empower(str) { TOOL->empower(str); return 1; }
weapon(str) { TOOL->weapon(str); return 1; }
show_attacks() { TOOL->show_attacks(); return 1; }
listEnhancements(str) { TOOL->listEnhancements(str); return 1; }
setArtLevel(str) { TOOL->setArtLevel(str); return 1; }
setWeapon(str) { TOOL->setWeapon(str); return 1; }
addCredits(str) { TOOL->addCredits(str); return 1; }
goToGuild() { TOOL->goToGuild(); return 1; }
officer_database(str) { TOOL->officer_database(str); return 1; }
wear(str) { TOOL->wear(str); return 1; }
color() { TOOL->color(); return 1; }
score() { TOOL->score(); return 1; }
mislead(str) { TOOL->mislead(str); return 1; }
report(str) { TOOL->report(str); return 1; }
tourney() { TOOL->tourney(); return 1; }
new_start() { TOOL->new_start(); return 1; }
combat_retreat() { TOOL->combat_retreat(); return 1; }
lead() { TOOL->lead(); return 1; }
power_scan(str) { TOOL->power_scan(str); return 1; }
bwho() { TOOL->bwho(); return 1; }
all_who() { TOOL->all_who(); return 1; }
ninja_speak(str) { TOOL->ninja_speak(str); return 1; }
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
hide_in_shadows() {
    write("This command has been removed. -Bp\n");
    write("Wizard abilities are not for players if u bitch to me the best\n"+
          "that will happen is u will be ingored.\n");
    return 1;
   /*TOOL->hide_in_shadows(); return 1;*/ 
 }
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
reg() { TOOL->reg(); return 1; }
rej() { TOOL->rej(); return 1; }
equil() { TOOL->equil(); return 1; }
meta_conversion() { TOOL->meta_conversion(); return 1; }

update_implants() {
   object implants, this_ob; TE(ME, "Updating implants.\n");
  implants = clone_object("/players/snow/closed/cyber/implants.c");
   this_ob = present("implants", ME);
   move_object(implants, ME); destruct(this_ob);
   implants->init(1); return 1; }

faked_beat() {   /* was originally heart_beat... changed by Mythos <1-30-96> */
/*
  TE(ETO,"HEARTBEAT ON\n");
*/
  if(regen_on == 1) TOOL->regenerate(ETO);
  if(rejuv_on == 1) TOOL->rejuvenate(ETO);
  if(equil_on == 1) TOOL->equilibrate(ETO);
  if(environment(this_object())){
  if(!ATTACK && bion_on) TOOL->bionics(ETO);
  if(!ATTACK && blad_on) TOOL->blades(ETO);
  }
  call_out("faked_beat",5);
  return 1;
}
