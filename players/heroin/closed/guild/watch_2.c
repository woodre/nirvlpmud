#include "/players/heroin/closed/guild/defs.h"
#define ENVTP environment(this_player())
#define MERCH "/players/heroin/closed/guild/test1_daemon"
#define TP this_player()
#define ENVENTO environment(this_object())
#define RN this_player()->query_real_name()
#define CAP capitalize
#define ENVTP environment(this_player())
#define TO this_object()

int muffled;
int m_gold;
int arm_1, arm_2, arm_3, arm_4;
int wea_1, wea_2, wea_3, wea_4;
int misc_1, misc_2, misc_3, misc_4;
inherit "/obj/treasure";
reset(arg) {
 if(arg)
   return;
set_short("A stylish pocket watch (worn) ");
set_weight(0);
set_value(0);
set_alias("watch");
set_heart_beat(1);
 
lsteal = 50;
stunwait = 0;
mltpy = 0;
old_hp = 0;
hpmon = "battle";
shadow = 0;
iquit = 0;
wimp = 1;
wimp_at = 10;
wimp_dir = "none";
HB = 0;
how_often = 3;
ln1 = "none";  ln2 = "none";  ln3 = "none";
ln4 = "none";  ln5 = "none";
 
if(this_player()->query_money() > 80000) {
   this_player()->add_money(-(this_player()->query_money()));
     this_player()->add_money(80000);
}
if(this_player()->query_guild_rank() < 1) {
  this_player()->add_guild_rank(1); }
if(this_player()->query_guild_exp() < 1) {
  this_player()->add_guild_exp(1); }
this_object()->set_guild_rank(this_player()->query_guild_rank());
this_object()->set_guild_exp(this_player()->query_guild_exp());
call_out("hp_monitor", 1);
 
call_out("start_special_attack", 2);
}
 
sett_lsteal(str){ lsteal = str; }
set_guild_rank(s) { guild_rank = s; }
set_guild_loan(ln) { guild_loan = ln; }
query_guild_loan() { return guild_loan; }
set_guild_exp(a) { guild_exp = a; }
query_guild_exp() { return guild_exp; }
query_guild_rank() { return guild_rank; }
set_muffled(mf) { muffled = mf; }
query_muffled() { return muffled; }
query_followee() {return 1;}
query_wimp() { return wimp; }
query_wimp_at() { return wimp_at; }
query_wimp_dir() { return wimp_dir; }
set_wimp(wp) { wimp = wp; }
set_wimp_at(wat) { wimp_at = wat; }
set_wimp_dir(wir){ wimp_dir = wir; }
setum_how_often(ho) { how_often = ho; }
set_learn1(nm,st){ ln1 = nm;  lrn1 = st; }
set_learn2(nm,st){ ln2 = nm;  lrn2 = st; }
set_learn3(nm,st){ ln3 = nm;  lrn3 = st; }
set_learn4(nm,st){ ln4 = nm;  lrn4 = st; }
set_learn5(nm,st){ ln5 = nm;  lrn5 = st; }
query_how_often() { return how_often; }
 
id(str){ return str == "watch" || str == "merwatch" || 
    str == "merchant watch" || str == "notarmor"; }
 
query_auto_load() {
 return "players/heroin/closed/guild/watch_2:"+
  ln1+"#"+ln2+"#"+ln3+"#"+ln4+"#"+ln5+"#"+lrn1+"#"+lrn2+
  "#"+lrn3+"#"+lrn4+"#"+lrn5;
}
 
drop() {
    return 1;
}
 
long() {
       write("This stylish time piece distinguishes \n"+
       "you as a member of the upper eschellon of society.\n"+
       "For help typr merchinfo.\n"); 
       return 1;
}
extra_look() {
return "You are looking at a distinguished member of High Society.\n";
}
get() {
   return 1;
}
 
init_arg(arg) {
sscanf(arg, "%s#%s#%s#%s#%s#%s#%s#%s#%s#%s",
  ln1,ln2,ln3,ln4,ln5,lrn1,lrn2,lrn3,lrn4,lrn5);
 if(this_player()->query_level() < 20) {
        cat("/players/heroin/closed/guild/news-help/int-help");
MERCH->quild_echo("($) "+CAP(RN)+" greets you all with a nod.\n");
tell_object(TP,"\nWelcome to High Society.\n");
tell_object(TP,"To get the latest news type 'wallstree'.\n");
tell_object(TP, "Mail Heroin and/or Unsane if you have questions or problems.\n");
TP->set_al_title("DEVIOUS");
}
this_player()->set_guild_file(0);
 
if(this_player()->query_guild_rank() < 5) this_player()->set_ac(4);
if(this_player()->query_guild_rank() >= 5) this_player()->set_ac(8);
if(this_player()->query_guild_rank() == 5) this_player()->set_ac(8);
if(this_player()->query_guild_rank() > 8) this_player()->set_ac(11);
     return;
}
 
init() {
::init();
/*
mhp = ENVTP->query_mhp();
 mersp = ENVTP->query_msp();
 min = ENVTP->query_level() * 3;
 msat = ENVTP->query_level() * 8;
 me = this_player()->query_real_name();
*/
        add_action("kill_players","kill_players");
add_action("borrow","borrow");
     add_action("info_sheet","info");
        add_action("sp_attack","sp_attack");
        add_action("shield","shield");
        add_action("send","send");
add_action("first_stat","compare");
        add_action("lead","lead");
        add_action("checkbk","checkbk");
  add_action("gc","gc");
  add_action("touch","touch");
  add_action("set_how_often","mon");
  add_action("sneak","sneak");
  add_action("mon","ms");
  add_action("learn","learn");
  add_action("recruit","recruit");
  add_action("make_wimp","wimp");
  add_action("make_wimp_dir","wimpdir");
  add_action("make_wimp_at","wimpat");
  add_action("new_title","new_title");
  add_action("quit", "quit");
  add_action("battle_who","bw");
  add_action("merch_say","msay");
  add_action("banish", "banish");
/*
if(this_player()->query_guild_rank() > 19) {
*/
add_action("alttitle","altitle");
    add_action("gstat","gstat");
    add_action("amend","amend");
    add_action("promote_member","promo");
    add_action("watch", "watch");
    add_action("commander_tell","ct");
    add_action("commander_emote","ce");
    add_action("gxp_member","gxp");
  add_action("follow", "follow");
  add_action("locate_player","locate");
  add_action("fixme","fixme");
  add_action("guild_title","guild_title");
  add_action("set_starting","setstart");
  add_action("read_news","wallstreet");
  add_action("help_files","mhelp");
  add_action("merch_who", "mw");
  add_action("cash","cash");
  add_action("extract" ,"extract");
  add_action("escape", "escape");
  add_action("nirvana_who","nirw");
  add_action("stat_monster","status");
  add_action("hp_mon","hpmon");
  add_action("payoff","payoff");
  add_action("heal_spell", "booster");
  add_action("cast_light","cast");
add_action("register","rewind");
  add_action("muffles","merch channel");
  add_action("muffles","mchan");
  add_action("rank","rank");
  add_action("rank","sk");
  add_action ("rank","sco");
  add_action("auction","auction");
add_action("borrow","borrow");
  add_action("merch_tell","mt");
  add_action("merch_emote","me");
}
 
/* ------ Heartbeat ish ----------- */
heart_beat() {
  object para, mons;
   string itname, shape;
   int monhp, monmhp;
 
if(ENVTP->query_attack()) {
if(wimp == 1 && shit->query_hp() < shit->query_mhp() / wimp_at) {
tell_object(shit, "Run for your Life! Run as fast as you can WEINER!\n");
if(wimp_dir == "none")
ENVTP->run_away();  else
command(wimp_dir, ENVTP);
tell_object(ENVTP, "You flee the Battle.\n");
follow = 0;
     }
}
 
if(follow == 1){
      if(environment(followee) != environment(environment(this_object()))){
         move_object(environment(this_object()), environment(followee));
         tell_object(environment(this_object()),
            "You continue following "+followee->query_name()+".\n");
         command("look", environment(this_object()));
      }
   }
return 1;
}
 
/* -- SET-HOW-OFTEN  hpmon calls -- */
set_how_often(str){
if(!str){
 write("Usage: mon <1-50>.\n");
 return 1; }
sscanf(str, "%d", how_often);
if(how_often > 50) how_often = 50;
if(how_often < 1) how_often = 1;
write("Monitor Call: "+how_often+".\n");
return 1;
}
 
/* -- HPMON (the health monitor) -- */
hp_monitor(){
string colhp, colsp, colin, colat, shape;
object mons;
int when, monhp, monmhp;
  when = how_often;
if(!ENVTP->query_attack() && hpmon != "on"){
 call_out("hp_monitor", 3);
 return 1; }
if(hpmon == "off"){
 call_out("hp_monitor", 3);
 return 1; }
mons = ENVTP->query_attack();
monhp = mons->query_hp();  monmhp = mons->query_mhp();
  
if(monhp < monmhp/10) shape = "VBS"; else
if(monhp < monmhp/5) shape = "BS"; else
if(monhp < monmhp/2) shape = "SWH"; else
if(monhp < monmhp - monmhp/10) shape = "SLH"; else
  shape = "GS";
tell_object(ENVTP, "[HP]: "+ENVTP->query_hp()+"/"+mhp+
   "  [SP]: "+ENVTP->query_sp()+"/"+msp+
   "  [I]: "+ENVTP->query_intoxination()+"/"+min+"  ");
 if(ENVTP->query_attack())
    tell_object(ENVTP, "[ATT: "+shape+"]\n");
  else
    tell_object(ENVTP, "\n");
call_out("hp_monitor", when);
return 1;
}
 
 
/* ---------- HP_MON ---------- */
hp_mon(str) {
if(str == "on"){
        write("Monitor on.\n");
        hpmon = "on";
        call_out("hp_monitor",1);
        return 1;
        }
if(str == "off"){
        write("Monitor off.\n");
        hpmon = "off";
        return 1;
        }
if(str == "battle") {
        write("Monitor on for battle only.\n");
        hpmon = "battle";
        call_out("hp_monitor",1);
        return 1;
        }
write("Usage: hpmon <on/off/battle>.\n");
return 1;
}
/* -------- The Big Quiet -------------- */
muffles(str) {
     if(!str) {
    write("Usage: mchan <on/off>\n");
       return 1;
     }
     if(str == "off") {
       if(muffled == 1) {
   write("You are already being UNSOCIABLE.\n");
         return 1;
       } else
       muffled = 1;
   write("You close the Merchant Channel.\n");
       return 1;
     }
     if(str == "on") {
       if(muffled == 0) {
     write("You are already on the Channel.\n");
         return 1;
       } else
       muffled = 0;
    write("Merchant Channel is now open.\n");
       return 1;
     }
}
 
send(str) { MERCH->send(str); return 1; }
make_wimp_at(str) { MERCH->make_wimp_at(str); return 1; }
set_starting() { MERCH->set_starting(); return 1; }
kill_players() { MERCH->kill_players(); return 1; }
info_sheet(str) { MERCH->info_sheet(str); return 1; }
first_stat(str) { MERCH->first_stat(str); return 1; }
lead () { MERCH->lead(); return 1; }
checkbk(str) { MERCH->checkbk(str); return 1; }
gc() {MERCH->gc(); return 1; }
touch(str) { MERCH->touch(str); return 1; }
sneak(str) { MERCH->sneak(str); return 1; }
mon() { MERCH->mon(); return 1; }
learn(str) { MERCH->learn(str); return 1; }
view() { MERCH->view(); return 1; }
recruit(str) {  MERCH->recruit(str); return 1; }
shield() { MERCH->shield(); return 1; }
alias_check(str) { MERCH->alias_check(str); return 1; }
make_wimp(str) { MERCH->make_wimp(str); return 1; }
make_wimp_dir(str) { MERCH->make_wimp_dir(str); return 1; }
new_title(str) { MERCH->new_title(str); return 1; }
battle_who() { MERCH->battle_who(); return 1; }
monk_say(str) { MERCH->merch_say(str); return 1; }
free_speech(str) { MERCH->free_speech(str); return 1; }
banish(str) { MERCH->banish(str); return 1; }
gstat(str) { MERCH->gstat(str); return 1; }
amend(str) { MERCH->amend(str); return 1; }
promote_member(str) { MERCH->promote_member(str); return 1; }
watch(str) { MERCH->watch(str); return 1; }
commander_tell(str) { MERCH->commander_tell(str); return 1; }
commander_emote(str) { MERCH->commander_emote(str); return 1; }
gxp_member(str) { MERCH->gxp_member(str); return 1; }
teleport() { MERCH->teleport(); return 1; }
locate_player(str) { MERCH->locate_player(str); return 1; }
death_field() { MERCH->death_field() ; return 1; }
fixme() { MERCH->fixme(); return 1; }
guild_title() { MERCH->guild_title(); return 1; }
mend_all() { MERCH->mend_all(); return 1; }
read_news() { MERCH->wallstreet(); return 1; }
help_files(str) { MERCH->help_files(str); return 1; }
merch_who() { MERCH->merch_who(); return 1; }
cash(str) { MERCH->cash(str); return 1; }
extract(str) { MERCH->extract(str); return 1; }
escape() { MERCH->escape(); return 1; }
nirvana_who() { MERCH->nirvana_who(); return 1; }
buyoff() { MERCH->buyoff(); return 1; }
heal_spell(str) { MERCH->heal_spell(str); return 1; }
cast_light(str) { MERCH->cast_light(str); return 1; }
register() { MERCH->register(); return 1; }
rank() { MERCH->rank(); return 1; }
xsell(str) { MERCH->xsell(str); return 1; }
merch_tell(str) { MERCH->merch_tell(str); return 1; }
merch_emote(str) { MERCH->merch_emote(str); return 1; }
/* ----- QUIT (set all modifiers, counters, etc Zip) -- */
quit(){
 object trace1, trace2;
if(iquit == 0){
 trace1 = find_living(this_player()->query_real_name()+"'s trace 1");
 trace2 = find_living(this_player()->query_real_name()+"'s trace 2");
    if(trace1) destruct(trace1);   if(trace2) destruct(trace2);
while(present("merch_obj", this_player())){
    destruct(present("merch_obj", this_player()));
                     }
 iquit = 911;
command("quit", this_player());
return 1;
}
}             
 
 
/* ---- follow another -------- */
follow(str){
        object merch, victim;
 
merch = present("watch", this_player());
if(this_player()->query_sp() < 15) {
        write("Rest-up. You do not have the energy to perform this.\n");
        return 1;
        }
 
if(str == "off"){
        write("Follow has been turned off\n");
        set_heart_beat(0);
        follow = 0;
        return 1;
        }
followee = find_player(str);
if(!present(str, environment(this_player()))){
        write("That is not here.\n");
        return 1;
        }
if(followee->query_level() > 20){
        write("You can't follow wizards.\n");
        return 1;
        }
if(!str){
        write("Usage: follow <who> or follow off\n");
        return 1;
        }
if(follow == 1){
        write("You are already following someone.\n");
        return 1;
        }
else {
        write("You begin following "+followee->query_name()+".\n");
        follow = 1;
        this_player()->add_spell_point(-15);
        set_heart_beat(1);
        return 1;
        }
}
