#define TOOL "/players/dune/closed/guild/ninjadaem.c"
#define TP this_player()
#define ENV environment
#define TO this_object()
#define CAP capitalize
#define ENVTP environment(this_player())
#define ENVTO environment(this_object())
#define SAVE "players/dune/closed/guild/ninjas/"
#define RN this_player()->query_real_name()

static string logo;
static int muffle;
int guild_lev, guild_exp;

query_auto_load() {
  return "/players/dune/closed/guild/implants.c:";
  }

id(str) { return str == "Implants" || str == "implant"
   || str == "implants" || str == "CyberNinja Implants"; }

short() {
  string short;
  short = "CyberNinja Implants";
  return short;
  }

long() {
  tell_object(ENVTO,"This is the CyberNinja guild object.\n"+
                    "To recieve information just type 'cyber'.\n");
  }

extra_look() {
  return ""+capitalize(TP->query_name())+
         " has Cybernetic Implants.";
  }

get() { return 1; }
drop() { return 1; }

reset(arg) {
 if(!arg) {
 }
 }

init() {
  restore_me();
  TP->set_ac(guild_lev());
  add_action("net_who", "users");
  add_action("net_channel_emote", "nem");
  add_action("net_channel","net");
  add_action("net_muffle_channel","line");
  add_action("enhance", "enhance");
  add_action("addxp", "addxp");
  add_action("advance_member", "advance");
  add_action("info_database","cyber");
  add_action("rank_info", "bodyscan");
  add_action("help_levels","cyberlevels");
  add_action("update_implants","newlink");
  add_action("save_me","download");
  add_action("check_time","internal_clock");
  add_action("set_guild_title","set_title");
  add_action("exchange_exp","exchange");
  add_action("leave_ninjas","leave_ninjas");
  add_action("recruit_member","recruit");
  add_action("join_member","join");
}

save_me() {
  string file;
  file = SAVE + RN;
  if(!save_object(file)) {
    tell_object(ENVTO,"Cyberlink error...\n");
    return 0;
    }
  tell_object(ENVTO,"Saving data...\n");
  return 1;
}

restore_me() {
  string file;
  file = SAVE + RN;
  if(!restore_object(file)) {
    tell_object(TP,"Cyberlink error...\n");
    return 0;
    }
  tell_object(TP,"Cyberlink connected...\n");
  return 1;
}

int guild_exp() {
  return guild_exp;}

int guild_lev() {
  return guild_lev;}

set_rank(int amount) {
  guild_lev = amount;}

set_xp(int amount) {
  guild_exp = amount;}

add_xp(int amount) {
  guild_exp += amount;}

int muffled() {
  return muffle;}

set_muffle(int new_muffle) {
  muffle = new_muffle;}

change_title(string new_title) {
  TP->set_title(new_title);
  write("You set your title to "+new_title+"\n");}

guild_tell(str) { TOOL->guild_tell(str); return 1; }
guild_emote(str) { TOOL->guild_emote(str); return 1; }
guild_who() { TOOL->guild_who(); return 1; }
enhance(str) { TOOL->enhance(str); return 1; }
addxp(str) { TOOL->addxp(str); return 1; }
advance_member() { TOOL->advance_member(); return 1; }
info_database(str) { TOOL->info_database(str); return 1; }
help_levels() { TOOL->help_levels(); return 1; }
update_implants() { TOOL->update_implants(); return 1; }
net_channel_emote(str) { TOOL->net_channel_emote(str); return 1; }
net_muffle_channel(str) { TOOL->net_muffle_channel(str); return 1; }
net_who() { TOOL->net_who(); return 1; }
net_channel(str) { TOOL->net_channel(str); return 1; }
rank_info() { TOOL->rank_info(); return 1; }
check_time() { TOOL->check_time(); return 1; }
leave_ninjas() { TOOL->leave_ninjas(); return 1; }
exchange_exp(arg) { TOOL->exchange_exp(arg); return 1; }
guild_title(arg) { TOOL->guild_title(arg); return 1; }
set_guild_title() { TOOL->set_guild_title(); return 1; }
join_member() { TOOL->join_member(); return 1; }
recruit_member(str) { TOOL->recruit_member(str); return 1; }
