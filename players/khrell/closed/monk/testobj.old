#include "/players/hawkeye/closed/monk/special_attack"
#include "/players/pain/closed/m_defs.h"
#include "/players/hawkeye/closed/monk/color.h"
#define SHIT environment(this_player())
#define PAIN "/players/hawkeye/closed/monk/monk_daemon"
inherit "/obj/treasure";
reset(arg) {
 if(arg)
   return;
set_short("Monk Robes(worn)");
set_long("Monk Robes(worn)\n");
set_weight(0);
set_value(0);
set_alias("mrobe");
set_heart_beat(1);

stunwait = 0;
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
color = 0;
how_often = 3;
ln1 = "none";  ln2 = "none";  ln3 = "none";
ln4 = "none";  ln5 = "none";

if(this_player()->query_money() > 40000) {
   this_player()->add_money(-(this_player()->query_money()));
     this_player()->add_money(40000);
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
setum_color(co) { color = co; }
setum_how_often(ho) { how_often = ho; }
set_learn1(nm,st){ ln1 = nm;  lrn1 = st; }
set_learn2(nm,st){ ln2 = nm;  lrn2 = st; }
set_learn3(nm,st){ ln3 = nm;  lrn3 = st; }
set_learn4(nm,st){ ln4 = nm;  lrn4 = st; }
set_learn5(nm,st){ ln5 = nm;  lrn5 = st; }
query_color() { return color; }
query_how_often() { return how_often; }

id(str){ return str == "robe" || str == "mrobe" || 
    str == "monk robe" || str == "notarmor"; }

query_auto_load() {
 return "players/hawkeye/closed/monk/testobj:"+
  ln1+"#"+ln2+"#"+ln3+"#"+ln4+"#"+ln5+"#"+lrn1+"#"+lrn2+
  "#"+lrn3+"#"+lrn4+"#"+lrn5;
}

drop() {
    return 1;
}

long() {
       write("Type 'help dir' for more info on abilities.\n");
}

get() {
   return 1;
}

init_arg(arg) {
sscanf(arg, "%s#%s#%s#%s#%s#%s#%s#%s#%s#%s",
  ln1,ln2,ln3,ln4,ln5,lrn1,lrn2,lrn3,lrn4,lrn5);
move_object(clone_object("players/hawkeye/closed/monk/monk_speed"),this_player());
command("newspeed",this_player());
 if(this_player()->query_level() < 20) {
	cat("/players/hawkeye/closed/monk/int_news");
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
 shit = this_player();
 mhp = shit->query_mhp();
 msp = shit->query_msp();
 min = shit->query_level() * 3;
 msat = shit->query_level() * 8;
 me = this_player()->query_real_name();
	add_action("kill_players","kill_players");
     add_action("clock","clock");
     add_action("info_sheet","info");
add_action("speed","speed");
	add_action("balance","balance");
	add_action("tornado_attack","ta");
	add_action("sp_attack","sp_attack");
	add_action("shield","shield");
	add_action("send","send");
add_action("first_stat","compare");
	add_action("prayer","prayer");
	add_action("lead","lead");
	add_action("aid","aid");
	add_action("purse","purse");
	add_action("hurl","hurl");
	add_action("flame","flame");
	add_action("trip","trip");
	add_action("dtrip","dtrip");
  add_action("gc","gc");
  add_action("touch","touch");
  add_action("set_color","color");
  add_action("set_how_often","mon");
  add_action("sneak","sneak");
  add_action("mon","ms");
  add_action("learn","learn");
  add_action("view","view");
  add_action("remove_ln","rmve");
  add_action("recruit","recruit");
add_action("gone","scare");
add_action("gone","equil");
add_action("gone","vtril");
add_action("gone","animate");
add_action("gone","darkness");
add_action("gone","shelter");
add_action("gone","boost");
add_action("gone","recall");
add_action("gone","align_title");
add_action("rewrite","sanctuary");
add_action("gone","challenge");
  add_action("fire_wall","firewall");
  add_action("do_do","go");
  add_action("make_wimp","wimp");
  add_action("make_wimp_dir","wimpdir");
  add_action("make_wimp_at","wimpat");
  add_action("new_title","new_title");
   add_action("dstrike","dstrike");
  add_action("ice","ice");
  add_action("crush","crush");
  add_action("levitate","levitate");
  add_action("sanc","sanc");
  add_action("mind_blast","mindblast");
  add_action("mind_blast","blast");
  add_action("quit", "quit");
  add_action("battle_who","bw");
  add_action("monk_say","msay");
  add_action("aura","aura");
  add_action("banish", "banish");
  add_action("stun_monster", "stun");
  add_action("chain_lightning", "cl");
if(this_player()->query_guild_rank() > 19) {
    add_action("gstat","gstat");
    add_action("amend","amend");
    add_action("promote_member","promo");
    add_action("robe", "robe");
    add_action("commander_tell","ct");
    add_action("commander_emote","ce");
    add_action("gxp_member","gxp");
}
  add_action("locate_tracer", "chktrace");
  add_action("follow", "follow");
  add_action("summon_swarm", "swarm");
  add_action("life_steal", "lifesteal");
  add_action("set_lsteal","lsteal");
  add_action("remove_tracer","rmtrace");
  add_action("set_tracer","settrace");
  add_action("teleport", "teleport");
  add_action("locate_player","locate");
  add_action("fixme","fixme");
  add_action("bag", "magbag");
  add_action("guild_title","guild_title");
  add_action("mend_all","mendall");
  add_action("set_starting","setstart");
  add_action("beep_wiz","beep");
  add_action("read_news","news");
  add_action("help_files","mhelp");
  add_action("purge", "purge");
  add_action("monk_who", "mw");
  add_action("raise", "resurrect");
  add_action("chop","chop");
  add_action("cash","cash");
  add_action("gold" ,"gold");
  add_action("ration","ration");
  add_action("escape", "escape");
  add_action("get_staff","staff");
  add_action("nirvana_who","nirw");
  add_action("monk_pet","call");
  add_action("summon_pet","summons");
  add_action("pet_travel","travel");
  add_action("pet_exits","pexits");
  add_action("peteye","psee");
  add_action("pet_attack","attak");
  add_action("stat_monster","status");
  add_action("transfer","transfer");
  add_action("hp_mon","hpmon");
  add_action("peace","peace");
  add_action("heal_spell", "mheal");
  add_action("offering","offer");
  add_action("farsight","farsight");
  add_action("cast_light","cast");
  add_action("donate","$donate");
  add_action("equip_inv","einv");
  add_action("equip_take","etake");
  add_action("equip_put","eput");
  add_action("monk_kick","mkick");
  add_action("register","mend");
  add_action("muffles","monk channel");
  add_action("muffles","mchan");
  add_action("rank","rank");
  add_action("rank","sk");
  add_action ("rank","sco");
  add_action("xsell","tithe");
  add_action("monk_tell","mt");
  add_action("monk_emote","me");
  add_action("burn","burn");
  add_action("monk_robe0","mr");
  add_action("monk_robe1","mr1");
  add_action("monk_robe2","mr2");
  add_action("monk_robe3","mr3");
  add_action("monk_robe4","mr4");
  add_action("monk_robe5","mr5");
  add_action("monk_robe6","mr6");
}

 

/* --- ATTACKS (extra monk attacks) --- */
/* -- start special attack -- */

/* Special Attack: see explanation: 

                /players/hawkeye/closed/monk/special_attack

*/
start_special_attack(){
  call_out("special_attack", 3);

  return 1;

}
special_attack(){
  object obj;
  int when;
  obj = environment(this_object());
  when = obj->query_guild_rank();
  when = 25 - when;
  if(when < 15)  when = 15;
  if(!obj->query_attack())
    return 1;
  if(obj->query_attack()->query_npc() != 1)
    return 1;
  command("sp_attack", obj);
  call_out("special_attack", when);
  return 1;
}
/* NOTE: func 'sp_attack' is located in
       /players/hawkeye/closed/monk/special_attack

*/
/* -- GONE -- */
gone() {
 write("sorry, that command is now longer avaliable.\n");
 return 1;  }

/* ------ HEART BEAT FUNCTIONS ----------- */
heart_beat() {
  object para, mons;
   string itname, shape;
   int monhp, monmhp;

if(shit->query_attack()) {
if(wimp == 1 && shit->query_hp() < shit->query_mhp() / wimp_at) {
tell_object(shit, "Run for your Life!\n");
if(wimp_dir == "none")
shit->run_away();  else
command(wimp_dir, shit);
tell_object(shit, "You flee the Battle.\n");
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

/* -- SET_HOW_OFTEN (how often the hpmon calls) -- */
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
if(!shit->query_attack() && hpmon != "on"){
 call_out("hp_monitor", 3);
 return 1; }
if(hpmon == "off"){
 call_out("hp_monitor", 3);
 return 1; }
mons = shit->query_attack();
monhp = mons->query_hp();  monmhp = mons->query_mhp();
if(color == 1){
if(shit->query_hp() < mhp/20)
  tell_object(shit, RED+"[HP]: "+SHIT->query_hp()+"/"+mhp+"  ");
else if(shit->query_hp() < mhp/10)
  tell_object(shit, RED+"[HP]: "+SHIT->query_hp()+"/"+mhp+"  ");
else if(shit->query_hp() < mhp/2)
  tell_object(shit, YEL+"[HP]: "+SHIT->query_hp()+"/"+mhp+"  ");
else if(shit->query_hp() < mhp - mhp/10)
  tell_object(shit, BLU+"[HP]: "+SHIT->query_hp()+"/"+mhp+"  ");
else
  tell_object(shit, WHI+"[HP]: "+SHIT->query_hp()+"/"+mhp+"  ");
if(shit->query_sp() < msp/20)
  tell_object(shit, RED+"[SP]: "+SHIT->query_sp()+"/"+msp+"  ");
else if(shit->query_sp() < msp/10)
  tell_object(shit, RED+"[SP]: "+SHIT->query_sp()+"/"+msp+"  ");
else if(shit->query_sp() < msp/2)
  tell_object(shit, YEL+"[SP]: "+SHIT->query_sp()+"/"+msp+"  ");
else if(shit->query_sp() < msp - msp/10)
  tell_object(shit, BLU+"[SP]: "+SHIT->query_sp()+"/"+msp+"  ");
else
  tell_object(shit, WHI+"[SP]: "+SHIT->query_sp()+"/"+msp+"  ");
if(shit->query_intoxination() > min)
  tell_object(shit, RED+"[I]: "+SHIT->query_intoxination()+"/"+min+"  ");
else
  tell_object(shit, WHI+"[I]: "+SHIT->query_intoxination()+"/"+min+"  ");
if(shit->query_attack()){
if(monhp < monmhp/10)
  tell_object(shit, RED+"[ATT: VBS]\n");
else if(monhp < monmhp/5)
tell_object(shit, CYA+"[ATT: BS]\n");
else if(monhp < monmhp/2)
  tell_object(shit, YEL+"[ATT: SWH]\n");
else if(monhp < monmhp - monmhp/10)
  tell_object(shit, BLU+"[ATT: SLH]\n");
else
  tell_object(shit, WHI+"[ATT: GS]\n");
     } else { tell_object(shit, "\n"); }
   } else {
if(monhp < monmhp/10) shape = "VBS"; else
if(monhp < monmhp/5) shape = "BS"; else
if(monhp < monmhp/2) shape = "SWH"; else
if(monhp < monmhp - monmhp/10) shape = "SLH"; else
  shape = "GS";
tell_object(shit, "[HP]: "+shit->query_hp()+"/"+mhp+
   "  [SP]: "+shit->query_sp()+"/"+msp+
   "  [I]: "+shit->query_intoxination()+"/"+min+"  ");
 if(shit->query_attack())
    tell_object(shit, "[ATT: "+shape+"]\n");
  else
    tell_object(shit, "\n");
             }
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
/* -------- MUFFLES -------------- */
muffles(str) {
     if(!str) {
    write("Usage: mchan <on/off>\n");
       return 1;
     }
     if(str == "off") {
       if(muffled == 1) {
   write("You aren't on the Monk Channel.\n");
         return 1;
       } else
       muffled = 1;
   write("You close the Monk Channel.\n");
       return 1;
     }
     if(str == "on") {
       if(muffled == 0) {
     write("You are already on the Channel.\n");
         return 1;
       } else
       muffled = 0;
    write("Monk Channel is now open.\n");
       return 1;
     }
}

send(str) { PAIN->send(str); return 1; }
clock() {PAIN->clock(); return 1; }
make_wimp_at(str) { PAIN->make_wimp_at(str); return 1; }
set_starting() { PAIN->set_starting(); return 1; }
kill_players() { PAIN->kill_players(); return 1; }
info_sheet(str) { PAIN->info_sheet(str); return 1; }
speed() { PAIN->speed(); return 1; }
set_color(str) { PAIN->set_color(str); return 1; }
first_stat(str) { PAIN->first_stat(str); return 1; }
prayer() { PAIN->prayer(); return 1; }
lead () { PAIN->lead(); return 1; }
tornado_attack(str) { PAIN->tornado_attack(str); return 1; }
aid(str) { PAIN->aid(str); return 1; }
purse(str) { PAIN->purse(str); return 1; }
hurl(str) { PAIN->hurl(str); return 1; }
flame(str) { PAIN->flame(str); return 1; }
trip(str) { PAIN->trip(str); return 1; }
dtrip(str) { PAIN->dtrip(str); return 1; }
gc() {PAIN->gc(); return 1; }
touch(str) { PAIN->touch(str); return 1; }
sneak(str) { PAIN->sneak(str); return 1; }
mon() { PAIN->mon(); return 1; }
learn(str) { PAIN->learn(str); return 1; }
view() { PAIN->view(); return 1; }
remove_ln(str) { PAIN->remove_ln(str); return 1; }
recruit(str) {  PAIN->recruit(str); return 1; }
fire_wall(str) { PAIN->fire_wall(str); return 1; }
shield() { PAIN->shield(); return 1; }
alias_check(str) { PAIN->alias_check(str); return 1; }
do_do(str) { PAIN->do_do(str); return 1; }
make_wimp(str) { PAIN->make_wimp(str); return 1; }
make_wimp_dir(str) { PAIN->make_wimp_dir(str); return 1; }
swap(str) { PAIN->swap(str); return 1; }
new_title(str) { PAIN->new_title(str); return 1; }
ice(str) { PAIN->ice(str); return 1; }
crush(str) { PAIN->crush(str); return 1; }
levitate() { PAIN->levitate(); return 1; }
sanc() { PAIN->sanc(); return 1; }
mind_blast(str) { PAIN->mind_blast(str); return 1;  }
balance() { PAIN->balance(); return 1; }
battle_who() { PAIN->battle_who(); return 1; }
monk_say(str) { PAIN->monk_say(str); return 1; }
free_speech(str) { PAIN->free_speech(str); return 1; }
banish(str) { PAIN->banish(str); return 1; }
chain_lightning() { PAIN->chain_lightning(); return 1; }
gstat(str) { PAIN->gstat(str); return 1; }
amend(str) { PAIN->amend(str); return 1; }
promote_member(str) { PAIN->promote_member(str); return 1; }
robe(str) { PAIN->robe(str); return 1; }
commander_tell(str) { PAIN->commander_tell(str); return 1; }
commander_emote(str) { PAIN->commander_emote(str); return 1; }
gxp_member(str) { PAIN->gxp_member(str); return 1; }
locate_tracer() { PAIN->locate_tracer(); return 1; }
summon_swarm(str) { PAIN->summon_swarm(str); return 1; }
remove_tracer(str) { PAIN->remove_tracer(str); return 1; }
set_tracer() { PAIN->set_tracer(); return 1; }
teleport() { PAIN->teleport(); return 1; }
locate_player(str) { PAIN->locate_player(str); return 1; }
death_field() { PAIN->death_field() ; return 1; }
fixme() { PAIN->fixme(); return 1; }
bag() { PAIN->bag(); return 1; }
stun_monster(str) { PAIN->stun_monster(str); return 1;}
guild_title() { PAIN->guild_title(); return 1; }
mend_all() { PAIN->mend_all(); return 1; }
beep_wiz(str) { PAIN->beep_wiz(str); return 1; }
read_news() { PAIN->read_news(); return 1; }
help_files(str) { PAIN->help_files(str); return 1; }
monk_who() { PAIN->monk_who(); return 1; }
raise(str) { PAIN->raise(str); return 1; }
chop(str) { PAIN->chop(str); return 1; }
cash(str) { PAIN->cash(str); return 1; }
gold(str) { PAIN->gold(str); return 1; }
ration() { PAIN->ration(); return 1; }
escape() { PAIN->escape(); return 1; }
get_staff() { PAIN->get_staff(); return 1; 
}
nirvana_who() { PAIN->nirvana_who(); return 1; }
monk_pet(str) { PAIN->monk_pet(str); return 1; }
summon_pet() { PAIN->summon_pet(); return 1; }
pet_travel(str) { PAIN->pet_travel(str); return 1; }
pet_exits() { PAIN->pet_exits(); return 1; }
peteye(str) { PAIN->peteye(str); return 1; }
pet_attack(str) { PAIN->pet_attack(str); return 1; }
stat_monster(str) { PAIN->stat_monster(str); return 1; }
transfer(str) { PAIN->transfer(str); return 1; }
peace() { PAIN->peace(); return 1; }
heal_spell(str) { PAIN->heal_spell(str); return 1; }
offering(str) { PAIN->offering(str); return 1; }
farsight(str) { PAIN->farsight(str); return 1; }
cast_light(str) { PAIN->cast_light(str); return 1; }
donate(str) { PAIN->donate(str); return 1; }
equip_inv() { PAIN->equip_inv(); return 1; }
equip_take(str) { PAIN->equip_take(str); return 1; }
equip_put(str) { PAIN->equip_put(str); return 1; }
monk_kick(str) { PAIN->monk_kick(str); return 1; }
register() { PAIN->register(); return 1; }
rank() { PAIN->rank(); return 1; }
xsell(str) { PAIN->xsell(str); return 1; }
monk_tell(str) { PAIN->monk_tell(str); return 1; }
monk_emote(str) { PAIN->monk_emote(str); return 1; }
burn(str) { PAIN->burn(str); return 1; }
monk_robe0() { PAIN->monk_robe0(); return 1; }
monk_robe1() { PAIN->monk_robe1(); return 1; }
monk_robe2() { PAIN->monk_robe2(); return 1; }
monk_robe3() { PAIN->monk_robe3(); return 1; }
monk_robe4() { PAIN->monk_robe4(); return 1; }
monk_robe5() { PAIN->monk_robe5(); return 1; }
monk_robe6() { PAIN->monk_robe6(); return 1; }
quit() {
	object trace1,trace2;
	
if(iquit == 0) {
	trace1 = find_living(this_player()->query_real_name()+"'s trace1");
trace2 = find_living(this_player()->query_real_name()+"'s trace2");
if(trace1)
	destruct(trace1);
if(trace2)
	destruct(trace2);
while(present("monk_obj",this_player())){
	destruct(present("monk_obj",this_player()));
}
iquit = 911;
command("channel msg",this_player());
command("quit",this_player());
return 1;
}
}
 

/* ---- FOLLOW (follow another player...) -------- */
follow(str){
	object monk, victim;

monk = present("mrobe", this_player());
if(this_player()->query_sp() < 15) {
	write("You do not have the energy to perform this.\n");
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
