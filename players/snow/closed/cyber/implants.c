/* CYBERNINJA GUILD OBJECT */

#include "/players/snow/closed/cyber/DEFS.h"
#define myname ETO->query_real_name()
#define ME ETO

static int muffle, dmatch;
static string type;
int issensei, isshogun, isregent, isreferee, ishead_ref, isminister, 
    suspend, color;
string art, weapon, garbcolor;
string strike_attack;
int guild_lev, guild_exp, bal, artlevel, degree, honor;
int corpse, electricflux, magneticflux, heatflux, flash,
    emt, bionics, blades, eyes, activate_droid, legs,
    convert, digest, weplink, armor;
int bion_on, blad_on, rejuv_on, regen_on, equil_on,
    convert_on, light_on, armor_on, tough_on, charge_on;
int attack_mode, wep_spam;
int auto_att, auto_def, auto_on, auto_reg, auto_rej,
    auto_blad, auto_bion;
int beats, flux_charges, kills;
 
int flux_removed, xp_updated, honor_adjust, art_updated;
 
id(str) { return str == "Implants" || str == "implant"
   || str == "either implants" || str == "notarmor"
   || str == "implants" || str == "CyberNinja Implants"; }
 
short() { return "CyberNinja Implants";}
 
long() {
  if(!environment()) return;
  if(!environment(this_object())) return;
  TE(ME,"This is the CyberNinja guild object.\n"+
        "To recieve information just type 'cyber'.\n"); }
 
get() { RE; } 
drop() { RE; }
 
extra_look() {
  string stuff, name;
  name = capitalize(myname);
  stuff = ""+name+" has Cybernetic Implants";
if( item_blades() || item_bionics() )
  stuff += "\n"+name+" has muscle enhancements";
if( item_magneticflux() || item_heatflux() || item_electricflux() )
  stuff += "\n"+name+" has "+BOLD+"FluX"+OFF+" jacks";
if(item_weplink()) stuff += "\n"+name+" has a smartweapon link";
  return stuff; }
 
init_arg(str) {
  /* shows guild news at startup */
  if(!environment() || !environment(this_object())) return 0;
  if(ME) if(!ME->query_inact()) ME->cat("/players/snow/closed/cyber/docs/news");
/* news is messing up inactive restore. -Bp */
RE; }
 
reset(arg) {
  if(!environment() || !ETO) {}
  else {
  if(!arg) {
    muffle = 0; digest = 0; bion_on = 0; blad_on = 0;
    light_on = 0; armor_on = 0; convert_on = 0; 
    equil_on = 0; regen_on = 0; rejuv_on = 0;
    charge_on = 0;
    remove_call_out("fake_beat");
    call_out("fake_beat",5);
  }
  }}
 
enable() { command("connect", ME); }
 
init(int num) {
  if(!environment()) return;
  if(!this_player()) return;
  if(!ETO) return;
  if(suspended()) {
    write("You are still suspended from the CyberNinjas.\n");
    destruct(this_object()); }
  AA("connect","connect");
  if(!num) { 
             if(ME) if(!ME->query_inact()) 
             /* news is messing up inactive restore. -Bp */
             cat("/players/snow/closed/cyber/docs/news");
/*
             if(TP->query_level() < 20 || !TP->query_invis())
               TOOL->overchannel(TPN+
                     " renews "+GEN+" connection.\n");
commented out because it was annoying */

             call_out("enable", 0);
             return; }
  ME->set_guild_name("cyberninja");
  if(!ME->query_ghost()) {
    if(!flux_removed) flux_remove();
    if(!art_updated) art_update();
    if(!honor_adjust) startup_honor();
 
    if(honor >= POOR) {
/*Resets fake beat */
  AA("restart","restart");
/*Ninja channel emote, talk, and muffle */
  AA("net_channel_emote", "nem");
  AA("net_channel","net");
  AA("net_muffle_channel","line");
/*Ninja mud who */
  AA("all_who", "gwho");
/*Secret ninja say */
  AA("ninja_speak","elate"); AA("ninja_speak","el");
      } 
    /* banelings cannot do the above actions */
    else write("As a baneling, you lose these commands:\n"+
               "  net, nem, line, gwho, elate.\n");

/*Shows ninjas online */
  AA("net_who", "users");
/*Saves ninja file */
  AA("download","download");
/*Ninja help files */
  AA("info_database","cyber");
/*Shows various ninja stats */
  AA("rank_info","scan");
/*Shows cost of guild levels */
  AA("help_levels","cyberlevels");
/*Shows cost of belt levels */
  AA("help_belt_levels","beltlevels");
/*Updates guild object */
  AA("update_implants","newlink");
/*Checks mud clock */
  AA("check_time","clock");
/*Sets title to guild title */
  AA("set_guild_title","set_title");
/*Changes coins to credits */
  AA("coinsTocredits","creditcoins"); AA("coinsTocredits","cc");
/*Shows current credit balance */
  AA("query_balance","balance"); AA("query_balance","bal");
/*Lists player's attacks */
  AA("show_attacks","attacks"); AA("show_attacks","atts");
/*Changes attack mode to none, offensive, or defensive */
  AA("mode_change","mode");
/*Lists player's enhancements */
  AA("listEnhancements","enhancements"); AA("listEnhancements","ens");
/*Shows enhancements in use */
  AA("show_use","usage");
/*Limits weight of usable armor to 2 */
/* id = notarmor already takes care of this
  AA("wear","wear");
*/
/*Score with ninja info in addition */
  AA("score","score"); AA("score","sc");
/*Ninja inventory */
  AA("player_inventory","i");
/*Setting login point */
  AA("new_start", "origin");
/*Shows log of deathmatches */
  AA("deaths","deaths");
/*Logs the deathmatch */
  AA("log_my_deathmatch","log_my_deathmatch");
/*Shows ninja news */
  AA("scan_news","news");
/*Shows recent mud deaths */
  AA("net_deaths","netdeaths");
/*Clones cyberware manual */
  AA("cyberware","cyberware");
/*Records guild bugs? */
  AA("record","record");
 
/* ATTACK COMMANDS */
 
/*To clone weapon */
  AA("weapon","weapon"); AA("weapon","wep");
/*To set auto on/off */
  AA("auto","auto");
/*Final blow (kinda) */
  AA("death_blow","deathblow"); AA("death_blow","db");
/*Martial art attack function */
  AA("strike","strike"); AA("strike","st");
/*Sets a martial arts attack for quick usage */
  AA("enable_strike_attack","setsa");
/*Performs set attack */
  AA("do_strike_attack","sa");
 
/* REMOVING MUD SPELLS */
 
  AA("no_spell","sh"); AA("no_spell","shock");
  AA("no_spell","mi"); AA("no_spell","missile");
  AA("no_spell","fi"); AA("no_spell","fireball");
  AA("no_spell","so"); AA("no_spell","sonic");
 
/* GUILD LEVEL  2  */
 
  if(guild_lev() >= 2) {
     AA("mask","mask");
     AA("power_scan","powerscan"); AA("power_scan","pscan");
     AA("lead","lead");
  }
 
/* GUILD LEVEL  3  */
 
  if(guild_lev() >= 3) {
    AA("combat_retreat","retreat");
    AA("bwho","battlewho"); AA("bwho","bwho");
    AA("item_scan","itemscan"); AA("item_scan","iscan");
  }
 
/* GUILD LEVEL  4  */
 
  if(guild_lev() >= 4) {
    AA("power_wield","power"); AA("power_wield","p1");
    AA("goToGuild","transfer");
  }
 
/* GUILD LEVEL  5  */
 
  if(guild_lev() >= 5) {
    AA("up_who","upwho");
  }
 
/* GUILD LEVEL  6  */
 
  if(guild_lev() >= 6) {
    AA("spy_room","roomspy");
    AA("power_wield2","power2"); AA("power_wield2","p2");
    AA("recruit_member","recruit");
  }
 
/* GUILD LEVEL  7  */
 
  if(guild_lev() >= 7) {
    AA("n_con","ncon");
    AA("match","challenge");
  }
 
/* GUILD LEVEL  8  */
 
  if(guild_lev() >= 8) {
    AA("hide_in_shadows","shadows");
/* Until approved -Snow
    AA("stun_blow","stun");
*/
  }
 
/* GUILD LEVEL  9  */
 
  if(guild_lev() >= 9) {
    AA("trans_to","transto");
}
 
/* GUILD LEVEL  10  */
 
  if(guild_lev() >= 10) {
    AA("power_wield3","power3"); AA("power_wield3","p3");
  }
 
/* REFEREE + HEAD REFEREE COMMANDS */
 
  if(referee() || head_referee()) {
     AA("report","report");
     AA("tourney","tourney"); }
  if(head_referee() || regent() || myname == EMP1
                    || myname == EMP2) {
     AA("refassist","refassist");
     AA("unref","unref"); }
 
/* OFFICER COMMANDS */
 
  if(sensei() || shogun() || head_referee() || minister() ||
     regent() || myname == EMP1 || myname == EMP2) {
    AA("officer_database","fax");
  }
 
/* SENSEI + GUILD WIZ COMMANDS */
 
  if(sensei() || myname == EMP1 || myname == EMP2
              ||     regent()) {
     AA("advance_art","train");
     AA("honor","honor");
     AA("dishonor","dishonor");
     AA("onet_channel","onet");
    }

/* MINISTER + GUILD WIZ COMMANDS */

  if(minister() || myname == EMP1 || myname == EMP2
                ||     regent()) {
     AA("honor","honor");
     AA("dishonor","dishonor");
     AA("onet_channel","onet");
    }

/* SHOGUN + GUILD WIZ COMMANDS */
 
  if(shogun() || myname == EMP1 ||
                 myname == EMP2 || regent()) {
     AA("unsuspend","unsuspend");
     AA("guild_balance","gbalance");
     AA("all_file_watcher","logall");
     AA("end_file_watcher","logend");
     AA("other_rank_info","oscan");
     AA("report","report");
     AA("empower","empower");
     AA("tourney","tourney");
     AA("honor","honor");
     AA("dishonor","dishonor");
     AA("onet_channel","onet");
     AA("purge","purge");
  }
 
/* GUILD WIZ COMMANDS */
 
  if(myname == EMP1 || myname == EMP2 || regent()) {
     AA("enhance","enhance");
     AA("suspend","suspend");
     AA("execute","execute");
     AA("addxp","addxp");
     AA("setArt","set_art");
     AA("setArtLevel","set_art_level");
     AA("setWeapon","set_weapon");
     AA("addCredits","add_credits");
  }
 
/* EMPEROR COMMANDS */
 
  if(myname == EMP1 || myname == EMP2) {
     AA("upall","upall");
     AA("change_honor","change_honor");
     AA("view_honor","view_honor");
  }
 
/* ENHANCEMENT COMMANDS */
 
/* CyberEyes - look, get, move in the dark */
  if(eyes) {
    AA("cyber_look","cyberlook");
    AA("cyber_get","cyberget");
    if(guild_lev() > 4) AA("cyber_move","cybermove");
  }
/* Organic Converter */
  if(corpse) {
    AA("corpse","decorpse"); /* Corpse destruct */
    AA("reg","reg"); /* Slow SPs to HPs */
    AA("rej","rej"); /* Slow HPs to SPs */
    AA("meta_conversion","digest"); /* Slow Food digest */
    }
/* FluX Converters - combat damage spells */
  if(electricflux || magneticflux || heatflux)
    AA("charge_flux","fluxcharge"); /* Charging */
  if(electricflux) AA("electricflux","eflux");
  if(magneticflux) AA("magneticflux", "mflux");
  if(heatflux) AA("heatflux", "hflux");
/* BioLight - light */
  if(flash) AA("flash", "glimmer");
/* Emotion Controller - peace, aggression */
  if(emt) AA("emt","emt");
/* Bionics and Blades - combat weapon enhancements */
  if(bionics) AA("bionics", "bion");
  if(blades) AA("blades","blad");
/* Droid - portable following bag */
  if(activate_droid) AA("activate_droid", "droid");
/* Cyber Legs - clone a speedster */
  if(legs) AA("speed_run", "speedrun");
/* Matter Converter */
  if(convert) {
    AA("matter_conversion","conversion"); /* Slow HPs to SPs */
    AA("equil","equil"); /* Slow equaling HP <-> SP */
    AA("matter_burn","overload"); /* Attack spell using HPs */
              }
  } }
 
save_me() {
  string file;
  file = SAVE + myname;
  if(!save_object(file)) {
    tell_object(ME,"Cyberlink error...\n"); return 0;}
  RE; }
 
restore_me() {
  string file;
  file = SAVE + myname;
  if(!restore_object(file)) {
    tell_object(ME,"Cyberlink error...\n"); return 0; }
  init(1); reset();
  RE; }
 
download() {
  write("Downloading to CyberNinja Database...\n");
  save_me();
  write("Ok.\n");
  return 1;
  }

connect() {
  write("Connecting to CyberNinja Database...\n");
  restore_me();
  write("Ok.\n");
  return 1;
  }

int guild_exp() { return guild_exp;}
set_rank(int amount) { guild_lev = amount; }
int guild_lev() { return guild_lev;}
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
set_minister(int new) { isminister = new; }
int minister() { return isminister; }
 
string query_art() { return "Ninjitsu"; }
int query_art_level() { return artlevel; }
set_art_level(int new) { artlevel = new; }
int query_degree() { return degree; }
set_degree(int new) { degree = new; }
int query_honor() { return honor; }
add_honor(int new) {
  if(TP && TP->query_level() > 20) {
    write_file("/players/snow/closed/cyber/log/WIZ_ADD",
      TP->query_real_name()+" "+ctime(time())+" added "+new+
      " honor to "+ME->query_real_name()+"\n");
  }
  honor += new; }
set_honor(int new) { honor = new; }

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
add_beats() { beats ++; }
int check_beats() { return beats; }
int query_kills() { return kills; }
add_kills(int new) { kills += new; }
set_kills(int new) { kills = new; }
get_deathmatch_permission(int new) { dmatch = new; }
int query_deathmatch_permission() { return dmatch; }
 
set_light_on(int num) { light_on = num; }
int query_light_on() { return light_on; }
do_light(int new) { if(new > 2) new = 2;
                    if(new < -2) new = -2;
                    set_light(new); }
 
int query_digest() { return digest; }
set_digest(int num) { digest = num; }
set_rejuv(int num) { rejuv_on = num; }
int query_rejuv() { return rejuv_on; }
set_regen(int num) { regen_on = num; }
int query_regen() { return regen_on; }
set_equil(int num) { equil_on = num; }
set_convert_on(int num) { convert_on = num; }
int query_equil() { return equil_on; }
int query_convert_on() { return convert_on; }
 
set_armor(int new) { armor = new; }
int query_armor() { return armor; }
set_armor_on(int num) { armor_on = num; }
int query_armor_on() { return armor_on; }
 
set_attack_mode(int num) { attack_mode = num; }
int query_attack_mode() { return attack_mode; }
set_wep_spam(int num) { wep_spam = num; }
int query_wep_spam() { return wep_spam; }
string query_strike_attack() { return strike_attack; }

set_bion_on(int new) { bion_on = new; }
int query_bion_on() { return bion_on; }
set_blad_on(int new) { blad_on = new; }
int query_blad_on() { return blad_on; }
set_auto(int num) { auto_on = num; }
int query_auto_on() { return auto_on; }
set_auto_att(int num) { auto_att = num; }
int query_auto_att() { return auto_att; }
set_auto_def(int num) { auto_def = num; }
int query_auto_def() { return auto_def; }
set_tough(int num) { tough_on = num; }
int query_tough() { return tough_on; }
set_auto_reg(int num) { auto_reg = num; }
int query_auto_reg() { return auto_reg; }
set_auto_rej(int num) { auto_rej = num; }
int query_auto_rej() { return auto_rej; }
set_auto_blad(int num) { auto_blad = num; }
int query_auto_blad() { return auto_blad; }
set_auto_bion(int num) { auto_bion = num; }
int query_auto_bion() { return auto_bion; }
 
set_flux_charges(int num) { flux_charges = num; }
add_flux_charges(int num) { flux_charges = flux_charges + num; }
int query_flux_charges() { return flux_charges; }
set_charge_on(int num) { charge_on = num; }
int query_charge_on() { return charge_on; }
 
int item_eyes() { return eyes; }
int item_corpse() { return corpse; }
int item_electricflux() { return electricflux; }
int item_magneticflux() { return magneticflux; }
int item_heatflux() { return heatflux; }
int item_flash() { return flash; }
int item_emt() { return emt; }
int item_bionics() { return bionics; }
int item_blades() { return blades; }
int item_activate_droid() { return activate_droid; }
int item_legs() { return legs; }
int item_convert() { return convert; }
 
int item_weplink() { return weplink; }
add_weplink(int num) { weplink += num; }
 
set_eyes(int num) { eyes = num; }
set_corpse(int num) { corpse = num; }
set_electricflux(int num) { electricflux = num; }
set_magneticflux(int num) { magneticflux = num; }
set_heatflux(int num) { heatflux = num; }
set_flash(int num) { flash = num; }
set_emt(int num) { emt = num; }
set_bionics(int num) { bionics = num; }
set_blades(int num) { blades = num; }
set_activate_droid(int num) { activate_droid = num; }
set_legs(int num) { legs = num; }
set_convert(int num) { convert = num; }
set_weplink(int num) { weplink = num; }
 
guild_tell(str) { TOOL->guild_tell(str); RE; }
guild_emote(str) { TOOL->guild_emote(str); RE; }
guild_who() { TOOL->guild_who(); RE; }
enhance(str) { TOOL->enhance(str); RE; }
addxp(str) { TOOL->addxp(str); RE; }
info_database(str) { TOOL->info_database(str); RE; }
help_levels() { TOOL->help_levels(); RE; }
help_belt_levels() { TOOL->help_belt_levels(); RE; }
net_channel_emote(str) { TOOL->net_channel_emote(str); RE; }
net_muffle_channel(str) { TOOL->net_muffle_channel(str); RE; }
net_who() { TOOL->net_who(); RE; }
n_con() { TOOL->n_con(); RE; }
net_channel(str) { TOOL->net_channel(str); RE; }
onet_channel(str) { TOOL->onet_channel(str); RE; }
rank_info() { TOOL->rank_info(); RE; }
check_time() { TOOL->check_time(); RE; }
guild_title(arg) { TOOL->guild_title(arg); RE; }
set_guild_title() { TOOL->set_guild_title(); RE; }
recruit_member(str) { TOOL->recruit_member(str); RE; }
coinsTocredits(str) { TOOL->coinsTocredits(str); RE; }
query_balance() { TOOL->query_balance(); RE; }
guild_balance() { TOOL->guild_balance(); RE; }
advance_art(str) { TOOL->advance_art(str); RE; }
empower(str) { TOOL->empower(str); RE; }
weapon(str) { TOOL->weapon(str); RE; }
show_attacks() { TOOL->show_attacks(); RE; }
mode_change(string str) { TOOL->mode_change(str); RE; }
listEnhancements(str) { TOOL->listEnhancements(str); RE; }
show_use() { TOOL->show_use(); RE; }
setArtLevel(str) { TOOL->setArtLevel(str); RE; }
setWeapon(str) { TOOL->setWeapon(str); RE; }
addCredits(str) { TOOL->addCredits(str); RE; }
goToGuild() { TOOL->goToGuild(); RE; }
officer_database(str) { TOOL->officer_database(str); RE; }
wear(str) { TOOL->wear(str); RE; }
score() { TOOL->score(); RE; }
player_inventory() { TOOL->player_inventory(); RE; }
report(str) { TOOL->report(str); RE; }
tourney() { TOOL->tourney(); RE; }
new_start() { TOOL->new_start(); RE; }
combat_retreat() { TOOL->combat_retreat(); RE; }
lead() { TOOL->lead(); RE; }
spy_room(str) { write("This has been removed. - The Managment\n");
                return 1; TOOL->spy_room(str); RE; }
power_scan(str) { TOOL->power_scan(str); RE; }
bwho() { TOOL->bwho(); RE; }
item_scan(str) { TOOL->item_scan(str); RE; }
all_who() { TOOL->all_who(); RE; }
ninja_speak(str) { TOOL->ninja_speak(str); RE; }
match(str) { TOOL->match(str); RE; }
mask(str)  { write("Because of abuse this has been removed. - The Managment\n");
             return 1; TOOL->mask(str); RE; }
deaths(str) { TOOL->deaths(str); RE; }
scan_news() { TOOL->scan_news(); RE; }
net_deaths() { TOOL->net_deaths(); RE; }
refassist(str) { TOOL->refassist(str); RE; }
unref(str) { TOOL->unref(str); RE; }
suspend(str) { TOOL->suspend(str); RE; }
unsuspend(str) { TOOL->unsuspend(str); RE; }
execute(str) { TOOL->execute(str); RE; }
log_my_deathmatch(str) { TOOL->log_my_deathmatch(str); RE; }
enable_strike_attack(str) { TOOL->enable_strike_attack(str); RE; }
set_strike_attack(str) { strike_attack = str; }
static do_strike_attack() { TOOL->strike(strike_attack); RE; }
static strike(str) { TOOL->strike(str); RE; }
cyberware() { TOOL->cyberware(); RE; }
all_file_watcher(str) { TOOL->all_file_watcher(str); RE; }
end_file_watcher(str) { TOOL->end_file_watcher(str); RE; }
record(str) { TOOL->record(str); RE; }
up_who() { TOOL->up_who(); RE; }
trans_to(str) { TOOL->trans_to(str); RE; }
upall() { TOOL->upall(); RE; }
stun_blow(str) { TOOL->stun_blow(str); RE; }
hide_in_shadows() { TOOL->hide_in_shadows(); RE; }
static power_wield(str) { TOOL->power_wield(str); RE; }
static power_wield2(str) { TOOL->power_wield2(str); RE; }
static power_wield3(str) { TOOL->power_wield3(str); RE; }
other_rank_info(str) { TOOL->other_rank_info(str); RE; }
auto(str) { TOOL->auto(str); RE; }
static death_blow(str) { TOOL->death_blow(str); RE; }
no_spell() { TOOL->no_spell(); RE; }
dishonor(str) { TOOL->dishonor(str); RE; }
honor(str) { TOOL->honor(str); RE; }
purge(str) { TOOL->purge(str); RE; }
change_honor(str) { TOOL->change_honor(str); RE; }
view_honor(str) { TOOL->view_honor(str); RE; }
restart(str) { TOOL->restart(str); RE; }
 
/* ENHANCEMENT FUNCTIONS */
 
cyber_look(str) {TOOL->cyber_look(str); RE; }
cyber_move(str) { TOOL->cyber_move(str); RE; }
static cyber_get(str) { TOOL->cyber_get(str); RE; }
corpse() { TOOL->corpse(); RE; }
charge_flux() { TOOL->charge_flux(); RE; }
electricflux(str) { TOOL->electricflux(str); RE; }
magneticflux(str) { TOOL->magneticflux(str); RE; }
heatflux(str) { TOOL->heatflux(str); RE; }
flash() { TOOL->flash(); RE; }
emt(str) { TOOL->emt(str); RE; }
bionics() { TOOL->bionics(); RE; }
blades() { TOOL->blades(); RE; }
activate_droid() { TOOL->activate_droid(); RE; }
speed_run() { TOOL->speed_run(); RE; }
matter_conversion() { TOOL->matter_conversion(); RE; }
matter_burn() { TOOL->matter_burn(); RE; }
reg() { TOOL->reg(); RE; }
rej() { TOOL->rej(); RE; }
equil() { TOOL->equil(); RE; }
meta_conversion() { TOOL->meta_conversion(); RE; }
 
update_implants() {
  object implants, this_ob;
  if(ETO) TE(ME, "Updating implants.\n");
  implants = clone_object("/players/snow/closed/cyber/implants.c");
  if(present("implants", ME)) {
  this_ob = present("implants", ME);
  move_object(implants, ME); destruct(this_ob);
  implants->init(1); reset();
  }
  RE; }
 
fake_beat() {
  if(!environment()) return 1;
  if(!environment(this_object())) return 1;
  call_out("fake_beat", 5, ME);
  TOOL->fake_beat(ME);
  RE;
}

static flux_remove() {
  if(flux_removed) return 1;
  if(item_electricflux()) {
    addToBalance(20000);
    set_electricflux(0); }
  if(item_magneticflux()) {
    addToBalance(20000);
    set_magneticflux(0); }
  if(item_heatflux()) {
    addToBalance(20000);
    set_heatflux(0); }
  flux_removed = 1;
  save_me();
  TE(ME,"Your FluX's have been removed.\n"+
        "Your credits are refunded.\n"+
        "You may buy your allowable one FluX in the chopshop.\n");
  RE;
}

art_update() {
  int num;
  if(artlevel == 6) ME->add_exp(80000);
  if(artlevel == 7) ME->add_exp(330000);
  if(artlevel > 7) { num = artlevel - 7; ME->add_exp(num * 100000 + 330000); }
  art_updated = 1;
  save_me();
  write_file("/players/snow/closed/cyber/log/ART_UPDATE",
    ctime(time())+" "+ME->query_real_name()+" updated for "+artlevel+"\n");
  TE(ME, "Your experience has been updated for the new belt system.\n");
  return 1;
}

static startup_honor() {
  if(honor > 1) add_honor(-honor);
  if(isreferee) add_honor(2);
  if(ishead_ref) add_honor(4);
  if(isminister) add_honor(10);
  if(isshogun) add_honor(10);
  if(guild_lev) add_honor(guild_lev);
  if(artlevel) add_honor(artlevel);
  honor_adjust = 1;
  save_me();
  write_file("/players/snow/closed/cyber/log/HONOR_START",
    ctime(time())+" "+ME->query_real_name()+" honor: "+honor+" \n");
  return 1;
}
