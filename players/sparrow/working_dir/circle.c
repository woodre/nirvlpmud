#include "./defs.h"


#include "/players/guilds/fallen/obj/variables.h"
#include "/players/guilds/fallen/obj/weapon.h"
#include "/players/guilds/fallen/obj/armor.h"
#include "/players/guilds/fallen/obj/id.h"
/*
#include "/players/guilds/fallen/obj/reset.h"
*/
#include "/players/guilds/fallen/obj/hb.h"
#include "/players/guilds/fallen/obj/nightmares.h"
#include "/players/guilds/fallen/obj/function.h"
#include "/players/guilds/fallen/obj/environment_check.h"
#include "/players/guilds/fallen/obj/endurance_check.h"
#include "/players/guilds/fallen/obj/ecolor.h"
#include "/players/guilds/fallen/obj/light_check.h"
#include "/players/guilds/fallen/obj/energy_check.h"
#include "/players/guilds/fallen/obj/spell_failure.h"
/*
#include "/players/guilds/fallen/obj/settings.h"
*/
#include "/players/guilds/fallen/obj/quit.h"
/*
#include "/players/guilds/fallen/obj/init.h"
*/
#include "/players/guilds/fallen/power/chan.h"
#include "/players/guilds/fallen/power/mud_spells.h"
#include "/players/guilds/fallen/power/guild_updates.h"
#include "/players/guilds/fallen/power/dark_ass.h"
#include "/players/guilds/fallen/power/misc_funcs.h"
/*  verte monitor code */
/*
#include "/players/zeus/circle/obj/print_monitor.h"
*/

/* 03/24/06 Earwax: switched this to use lib guild code */
/*
query_auto_load(){ return "/players/zeus/circle/circle.c:"; }
*/

static int num;
string *Skills;

void reset(int arg){
    if(arg) return;
    Skills = ({"dummy"});
    set_heart_beat(2);
}

void
print_monitor()
{
    int a, b, c, d, e, f, g, h, i, j;
    string bonk, k;
    object bzz;

    if(custom_monitor)
    {
	tell_object(USER, MASTER->m_decode(custom_monitor) + "\n");
	return;
    }
    else 
    if(bonk = (string)USER->query_monitor_string())
    {
	tell_object(USER, (string)USER->m_decode(bonk) + "\n");
	custom_monitor = bonk;
	save_circle(1);
	return;
    }

    a = (int)USER->query_level();
    b = (int)USER->query_hp();
    c = (int)USER->query_mhp();
    d = (int)USER->query_spell_point();
    e = (int)USER->query_msp();
    f = (int)USER->query_intoxination()*100 / ((int)USER->query_max_intox());
    g = (int)USER->query_stuffed()*100 / ((int)USER->query_max_stuff());
    h = (int)USER->query_soaked()*100 / ((int)USER->query_max_soak());
    i = (int)USER->query_infuse()*100 / ((a*9)/2);
    j = (int)MASTER->endurance_monitor();

    if(!(bzz = (object)USER->query_attack())) k = 0;

    else
	k = "AHP: " + 
	(((int)bzz->query_hp() * 10) / ((int)bzz->query_mhp())) + 
	"/10";

    tell_object(USER, 
      RED + "[fallen]" + NORM +
      " HP: " + b + "/" + c +"  SP: " + d + "/" + e + "  E: " + j +
      "% ["+f+"% "+g+"% "+h+"% "+i+"%] " + (k ? k : "") + "\n");
}

status
guild_monitor_only()
{
    return 1;
}

focus(){
    int gxp, val, dur, cost, f;
    if(User->query_ghost()) return 0;
    if(!query_skills("focus")){
	notify_fail("You do not have that skill.\n");
	return 0;
    }
    if(PO->light_check()) return 1;
    if(environment(User)->realm() == "NM"){
	tell_object(User, "Your power is being drained here.\n");
	return 1;
    }
    /*
      if(User->query_weapon())
      {
	if(User->query_weapon() != PO)
	{
	  TOU"You may not focus the shadows while using a weapon.\n");
	  return 1;
	}
      }
    */
    if(!PO->spell_failure(1)){
	write("Spell failure!\n");
	return 1;
    }
    if(PO->casting_check()){
	write("Casting already.\n");
	return 1;
    }
    f = PO->query_focus();
    if(f)
    {
	TOU BOLD+BLK+"You strengthen your focus of the shadows.\n"+NORM);
    TRU BOLD+BLK+User->QN+" strengthens "+User->POS+
    " focus of the shadows.\n"+NORM, ({User}));
}
else
{
    TOU BOLD+BLK+"You focus the shadows around you.\n"+NORM);
TRU BOLD+BLK+User->QN+" focuses the shadows around "+User->OBJ+".\n"+
NORM, ({User}));
}
gxp = PO->query_guild_exp();
if(gxp < 200000)
{
    if(User->query_level() < 14)
	cost = User->query_level() * -1;
    else
	cost = -14;
}
else if(gxp < 500000)
    cost = -15-random(6);
else if(gxp < 2000000)
    cost = -15-random(10);
else
    cost = -15-random(16);
if(gxp < 800000)
    val = 7 + random(6);
else
    val = 8 + (gxp / 800000);
if(gxp < 1000000)
    dur = 5 + random(2);
else
    dur = 5 + (gxp / 1000000);
if(val > 18)
    val = 18;
if(f)  /* if already focused */
{
    if(0 == random(7) && gxp < 2000000)
	dur += 2;
    else if(0 == random(4))
	val += 2;
    else if(0 == random(8))
	User->add_spell_point(2);
    else if(0 == random(3) && gxp < 500000)
	PO->add_endurance(3);
}
User->add_spell_point(cost);
if(gxp < 500000)
    User->add_hit_point(-1);
else if(gxp < 1500000)
    User->add_hit_point(val * -1 / 2);
else
    User->add_hit_point(val * -1);

if(gxp < 2000000 && User->query_attack())
{
    if(User->query_attack()->query_attack() == User)
	val += 4;
}

PO->set_focus(val,dur);
PO->energy_check();
PO->add_endurance(-1);
return 1;
}

drop(){ return 1; }
get(){ return 1; }

query_weight(){ return 0; }
query_value(){ return 0; }

set_dark_ass(int i){ dark_ass = i; }
query_dark_ass(){ return dark_ass; }

set_shadowcloak(int i){ shadowcloak = i; }
query_shadowcloak(){ return shadowcloak; }

set_rage(int i){ rage = i; }
query_rage(){ return rage; }

query_siphon(){ return siphon; }
set_siphon(){ siphon = 1; }

set_sshield(i){ shadow_shield = i; }
query_sshield(){ return shadow_shield; }

set_end_mon(x){ endurance_monitor = x; }
query_end_mon(){ return endurance_monitor; }

set_weave(x){ weave = x; }

set_focus(x,y){
    focus = x; duration = y;
    if(focus > 24) focus = 24;
    if(duration > 15) duration = 15;
}
add_focus(x,y){
    focus += x; duration += y;
    if(focus > 24) focus = 24;
    if(duration > 15) duration = 15;
}
query_focus(){ return duration; }

add_endurance(x){ endurance += x; }
set_endurance(x){ endurance = x; }
query_endurance(){ return endurance; }
set_max_endurance(x){ max_endurance = x; }
query_max_endurance(){ return max_endurance; }
display_endurance(){
    int j;
    j = (10 * endurance) / (max_endurance * 10);
    if(j < 0) j = 0;
    if(j > 100) j = 100;
    return j;
}

set_guild_exp(int i){ guild_exp = i; }
query_guild_exp(){ return guild_exp; }
rm_guild_exp(int i){  guild_exp -= i; }
add_guild_exp(i){  guild_exp += i;  }

set_vigor(int i){ vigor = i; }
query_vigor(){ return vigor; }
set_vigor_level(int i){ vigor_level = i; }
set_vigor_bonus(int i){ vigor_bonus = i; }
query_vigor_bonus(){ return vigor_bonus; }

query_combat_method(){ return 2; }
query_paladin_shield(){ return 1; }

int query_Skills(){
    write("Skills: "+implode(Skills, "*")+".\n");
    return 1;
}

int query_skills(string str){
    if(member_array(str, Skills) == -1) return 0;
    else return 1;
}

int set_skills(string str){
    int size;
    write("Setting skill "+str+"\n");
    if(!Skills) { 
      Skills = ({str});
      write("NO SKILLS ARRAY.\n");
    }
    else {
      size = sizeof(Skills);
      Skills[size] = str;
    }
    return 1;
}
remove_skills(string str){ Skills -= ({ str }); }

set_special_title(y){  special_title = y; }
query_special_title(){ return special_title; }

set_perc(x){  percent = x;  }
query_percent(x){
    if(x)
	return percent;
    else
    {
	if(guild_exp >= 8000000)
	    return "Master";
	else if(percent == 0)
	    return "Zero";
	else if(percent < 35)
	    return "Low";
	else if(percent < 65)
	    return "Medium";
	else if(percent >= 65)
	    return "High";
    }
}

int getit(int hp_sp, int max){
    int x, z;
    z = ((hp_sp * 100) / max);
    for(x = 100; x > 0; x -= 5){
	if(z >= x)
	    return x;
    }
}

set_custom_monitor(m) { custom_monitor = m; }
query_custom_monitor() { return custom_monitor; }

int query_casting(){ return casting; }
void set_casting(int x){ casting = x; }
int interrupt_casting(int x){
    if(!casting || !x) return 0;
    if(x == 1){  /* embrace interrupt */
	USER->add_hit_point(-50);
	USER->add_spell_point(-20);
	endurance -= 10;
    }
    tell_object(USER,
      "You feel pain in your head as your casting is interrupted.\n");
    destruct(previous_object());
    return 1;
}
int casting_check(){
    if(casting){
	tell_object(USER, "You are currently casting a spell.\n");
	return 1;
    }
    return 0;
}

void init(){
    if(!environment()) return;
    if(!file_size("/"+SAVE_PATH+this_player()->query_real_name()+".o")) return;
    if(!this_player()->is_player()) return;
    /* 03/24/06 Earwax: Added this: */
    this_player()->set_guild_file("/players/guilds/fallen/circle.c");
    history = allocate(MAX);
    call_out("nightmare", 1800+random(1800), environment());
    Skills = ({"dummy"});
    posendcol = WHT;
    negendcol = HIR;
    restore_circle();
    norm = NORM;
    casting = 0;
    if(environment()->query_level() < 21)
	call_other("/players/guilds/fallen/daemon/daemon","XXX");
    /****--  spells  --****/
    add_action("wither_spell", "wither");
    add_action("shadowblast", "blast");
    add_action("drain_spell", "drain");
    add_action("teleport", "teleport");
    add_action("dark_prayer", "dark");
    add_action("repulsion", "repulsion");
    add_action("dark_assistance", "assistance");
    add_action("empower", "empower");
    add_action("shadowring", "web");
    add_action("shadowweave", "weave");
    add_action("deweave", "deweave");
    add_action("shadowform", "shadowform");
    add_action("shadowrage", "rage");
    add_action("vanish", "vanish");
    add_action("shadowcloak", "shadowcloak");
    add_action("siphon", "siphon");
    add_action("weaken", "weaken");
    add_action("mud_spell", "mi");
    add_action("mud_spell", "missle");
    add_action("mud_spell", "sh");
    add_action("mud_spell", "shock");
    add_action("mud_spell", "fi");
    add_action("mud_spell", "fireball");
    add_action("mud_spell", "so");
    add_action("mud_spell", "sonic");
    add_action("focus", "focus");
    add_action("descend", "descend");
    add_action("descend", "dscnd");
    add_action("meditate", "meditate");
    add_action("new_invis", "invisible");
    add_action("see", "see");
    add_action("sshield", "shield");
    add_action("know", "know");
    add_action("vigor", "vigor");
    add_action("beckon", "beckon");
    add_action("summon", "summon");
    add_action("embrace", "embrace");
    /****--  commands  --****/
    add_action("quit_out", "quit");
    add_action("score_cmd", "sc");
    add_action("set_percent", "set_percent");
    add_action("endurance_mon", "toggle_endurance");
    add_action("set_ecolor", "ecolor");
    /*
      add_action("who2_new", "who2");
    */
    add_action("remove_all", "remove");
    add_action("emote_cmd", "emote");
    add_action("guild_cmd", "guild");
    add_action("chelp_cmd", "chelp");
    add_action("update_obj", "cupdate");
    add_action("save_circle", "csave");
    add_action("restore_circle", "crestore");
    add_action("back_me_up", "cbackup");
    add_action("upistrfrsf", "upistrfrsfdpfor");
    add_action("set_title", "set_title");
    add_action("speak_cmd", "speak");
    add_action("speak_cmd", "sp");
    add_action("meditate", "meditate");
    add_action("drift", "drift");
    add_action("c_monitor", "mon");
    add_action("c_setmon", "setmon");
    add_action("stop_casting", "stop");
    /****--  emotes  --****/
    add_action("shadow_wave", "swave");
    add_action("stand", "stand");
    add_action("battle_cry", "bcry");
    add_action("fdraw", "fdraw");
    add_action("scoff_cmd", "scoff");
    add_action("wait_cmd", "wait");

    call_other(this_player(), "wear", this_object(), 1, "shield",
      ({"physical",0,0,"shield_bonus"}));
    /*
      call_other(this_player(), "wear", this_object());
      set_type("shield");
      set_ac(0);
      worn_by = this_player();
      worn = 1;
    */
    set_class(3);
    wielded_by = environment();
    call_other(environment(), "wield", this_object(), 1);
    wielded = 1;
    set_hit_func(this_object());
    message_hit=({
      "massacre"," to small fragments",
      "massacre"," to small fragments",
      "smashed"," with a bone crushing sound",
      "hit"," very hard",
      "hit"," hard",
      "hit","",
      "grazed","",
      "tickled"," in the stomach",
    });
    if(!custom_monitor && (string)this_player()->query_monitor_string())
    {
	custom_monitor = (string)environment()->query_monitor_string();
	environment()->set_monitor_string(0);
    }
}

