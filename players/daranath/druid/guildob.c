/* First draft of the Druid guild object...  my basic format for a guildob...
   started Aug 8th, 2002   -Dar */

#include "/players/daranath/druid/defs.h"
#include <ansi.h>
#define CHAT "/players/daranath/druid/chatter.c"
#define SAVE "players/daranath/druid/member/"
#define SPELL "/players/daranath/druid/daemon.c"

int favor_fire, favor_air, favor_water, favor_earth;
int guild_lvl, touch;
int skill_herb, skill_heal, skill_emp, skill_plant, skill_ele;
#if 0 /* Rumplemintz, you redifine right below */
int skill_pts, an_comp, an_change;
#endif
int skill_pts, an_comp, an_change;  /* an_change of 1 means you can select again */
/* 1 = mistletoe, lesser; 2 = mistletoe, greater; 3 = berries; 4 = fire berries;
   5 = ice berries; 6 = herbs; 7 = crystal quartz; 8 = pure water */
int comp1, comp2, comp3, comp4, comp5, comp6, comp7, comp8;
string enter_msg, leave_msg, title;
string animal_name;

query_auto_load() {return "/players/daranath/druid/guildob.c:"; }
id(str) {return str == "druid_ob" || str == "staff" || str == "guildob"; }
short() {return (HIG+"Staff of the Woodlands"+NORM); }
long() {
write("A simple wooden staff made from an ancient tree.\n"+
      "type "+GRN+"<< "+HIW+"druid"+NORM+GRN+" >>"+NORM+" for powers.\n");
  }

drop() { return 1;}
get() { return 0;}

extra_look() {
    if(environment() == this_player())
   write("You are a member of the local druid society.\n");
    else write(environment()->query_name() + " belongs to the " +
        HIG + "Druid's Grove" + NORM + ".\n");
}

init() {
if(environment(this_object()) == this_player()) {
  if(!restore_object(SAVE+tpn)) {
if(tp->query_level() > 19){
  guild_lvl = 60;
} else {
  guild_lvl = 1;  }
  skill_pts = 1; touch = 0; 
  favor_fire = 0; favor_air = 0; favor_water = 0; favor_earth = 0;
  skill_herb = 0; skill_emp = 0; skill_heal = 0; skill_plant = 0; skill_ele = 0;
  enter_msg = "enters the game.";
  leave_msg = "leaves the game.";
  animal_name = "killer";
  an_comp = 0; an_change = 0;
CHAT->chat_line("has joined the Druid Guild",tp->query_real_name(),1);
   save_object(SAVE+tpn);
  }
if(tp->query_level() < 20) {
  tp->set_guild_name("Druid");
  if(tp->query_guild_rank() != guild_lvl) tp->add_guild_rank(guild_lvl - tp->query_guild_rank());
tp->save_character(); }
  CHAT->add_membr(tp);
 if(!tp->query_invis()) {
  call_other(CHAT,"chat_line",enter_msg,this_player()->query_name(),1); }

/* insert guild news here */

add_action("world_emote","emote");
add_action("druid_score","score");
add_action("druid_score","sc");
add_action("druid_who","dr_who");
add_action("druid_gwho","druids");
add_action("druid_update","druid_update");
add_action("druid_quit","leave_guild");
add_action("druid_chat","dc");
add_action("druid_emote","dce");
add_action("druid_title","dr_title");
add_action("druid_help","druid");
add_action("quit","quit");
add_action("druid_save","save");
add_action("druid_muffles","dr_hush");
add_action("druid_unmuffles","dr_unhush");
add_action("druid_comps","comps");
add_action("druid_tend","tend");
add_action("druid_block","missile",2);
add_action("druid_block","fireball",2);
add_action("druid_block","shock",2);
add_action("druid_block","sonic",2);
add_action("animal_select","an_select");
add_action("animal_name","an_name");

/* Spells for Druid levels 1-15 */
add_action("ele_spark","spark");
add_action("druid_decorpse","dtouch");
add_action("cure_minor","cureminor");
add_action("ob_mist","mist");
add_action("lesser_fang","fang");
add_action("rabbit_feet","rabbit");
add_action("summon_alay","summon");
add_action("ele_strike","frost");
add_action("ele_arrow","arrow");
add_action("entangle","entangle");
add_action("ele_shockwave","shockwave");
add_action("lesser_cry","wolf_cry");
add_action("greater_cry","dire_cry");
add_action("barkskin","barkskin");
add_action("faerie_fire","faerie");
add_action("ele_spikestone","spike");
add_action("cure_light","curelight");
add_action("ele_flameblade","blade");
}
  }

save_me() {save_object(SAVE+epn); return 0; }

druid_save() { save_me(); tell_object(ep,GRN+"<< "+HIG+"Druid"+NORM+" "+GRN+">>"+NORM+" Druid status saved.\n"); return 0; }

druid_update() {
  move_object(clone_object("/players/daranath/druid/guildob.c"),tp);
  write(GRN+"<< "+HIG+"Druid"+NORM+" "+GRN+">>"+NORM+" Druid status updated.\n");
  save_me();
  destruct(this_object());
return 1; }

druid_muffles() {write(GRN+"<< "+HIG+"Druid"+NORM+GRN+" >>"+NORM+" Guild chat line disabled.\n");
  CHAT->sub_membr(tp);
return 1; }

druid_unmuffles() {write(GRN+"<< "+HIG+"Druid"+NORM+GRN+" >>"+NORM+" Guild chat line enabled.\n");
  CHAT->add_membr(tp);
return 1; }

druid_chat(str) {
  if(!str) { write("What do you want to say over the guild chat line.\n"); return 1; }
  if(str == "history") {
tail("/players/daranath/druid/history");
return 1; }
  CHAT->chat_line(str,tp->query_name());
write_file("/players/daranath/druid/history",GRN+"<< "+HIG+"Druid"+NORM+" "+GRN+">> "+NORM+tp->query_name()+" says: "+str+"\n");
return 1; }

druid_emote(str) {
  if(!str) { write("What do you want to emote over the guild chat line.\n"); return 1; }
  CHAT->chat_line(str,tp->query_name(),1);
write_file("/players/daranath/druid/history",GRN+"<< "+HIG+"Druid"+NORM+" "+GRN+">> "+NORM+tp->query_name()+" "+str+"\n");
return 1; }

druid_title() {
 title = ("the "+WHT+"Marketeer of Bone"+NORM);
  tp->set_title(title);
  write("<"+HIW+"Market"+NORM+"> Bone Marketeer Title Set.\n");
return 1; }

druid_quit() {
 tp->reset(1);
  command("save",tp);
  write("You have decided to leave the Druids guild.\nGoodbye!\n");
	  CHAT->sub_membr(tp);
	  CHAT->chat_line("has left the comfort of the Grove",tp->query_real_name(),1);
      rm("/"+SAVE+tpn+".o");
 destruct(this_object());
return 1; }

quit() {
  druid_save();
  CHAT->sub_membr(ep);
return 0;
}

check(int chk) {
  if(chk > query_glvl()) {
tell_object(ep, GRN+"<< "+HIG+"Druid"+NORM+GRN+" >> You are not advanced enough for that spell."+NORM+"\n");
return 0; }
return 1;
}

world_emote(str) {
  if(!str) return 0;
  tell_room(environment(tp),tp->query_name()+" "+str+"\n");
return 1; }

druid_comps() {
write(GRN+"<< --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(HIG+"       Material Components"+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write("   Mistletoe, Greater: "+query_comp2()+"\n");
write("   Mistletoe, Lesser: "+query_comp1()+"\n");
write("   Berries: "+query_comp3()+"\n");
write("   Herbs: "+query_comp6()+"\n");
if(query_comp5() > 1) {
write("   Ice Berries: "+query_comp5()+"\n"); }
if(query_comp4() > 1) {
write("   Fire Berries: "+query_comp4()+"\n"); }
if(query_comp7() > 1) {
write("   Crystal Quartz: "+query_comp7()+"\n"); }
if(query_comp8() > 1) {
write("   Pure Water: "+query_comp8()+"\n"); }
write(GRN+"<< --- --- --- --- --- --- --- --- >>"+NORM+"\n");
return 1;
}

query_earth() { return favor_earth; }
query_fire() { return favor_fire; }
query_air() { return favor_air; }
query_water() { return favor_water; }
query_touch() { return touch; } /* Touch of Nature Ranking */
query_comp1() { return comp1; }  /* Lesser Mistletoe */
query_comp2() { return comp2; }  /* Greater Mistletoe */
query_comp3() { return comp3; }  /* Berries */
query_comp4() { return comp4; }  /* Fire Berries */
query_comp5() { return comp5; }  /* Ice Berries */
query_comp6() { return comp6; }  /* Herbs */
query_comp7() { return comp7; }  /* Crystal Quartz */
query_comp8() { return comp8; }  /* Pure Water */
query_herbskill() { return skill_herb; }
query_healskill() { return skill_heal; }
query_empskill() { return skill_emp; }
query_plantskill() { return skill_plant; }
query_eleskill() { return skill_ele; }
query_skillpts() { return skill_pts; }
query_glvl() { return guild_lvl; }
query_animal() { return an_comp; }
query_animal_change() { return an_change; }
query_animal_name() { return animal_name; }

add_firefav(int num) { favor_fire += num; }
add_waterfav(int num) { favor_water += num; }
add_earthfav(int num) { favor_earth += num; }
add_airfav(int num) { favor_air += num; }
add_touch(int num) { touch += num; }
add_skillpts(int num) { skill_pts += num; }
add_herbskill(int num) { skill_herb += num; }
add_healskill(int num) { skill_heal += num; }
add_empskill(int num) { skill_emp += num; }
add_plantskill(int num) { skill_plant += num; }
add_eleskill(int num) { skill_ele += num; }
add_comp1(int num) { comp1 += num; }
add_comp2(int num) { comp2 += num; }
add_comp3(int num) { comp3 += num; }
add_comp4(int num) { comp4 += num; }
add_comp5(int num) { comp5 += num; }
add_comp6(int num) { comp6 += num; }
add_comp7(int num) { comp7 += num; }
add_comp8(int num) { comp8 += num; }
add_animal_change(int num) { an_change += num; }

change_animal(int num) { an_comp = num; }
change_glvl(int num) { guild_lvl = num; }
add_glvl(int num) { guild_lvl += num; }

druid_score() {SPELL->druid_score(); return 1; }
druid_who() {SPELL->druid_who(); return 1; }
druid_gwho() {SPELL->druid_gwho(); return 1; }
druid_help(str) {SPELL->druid_help(str); return 1; }

druid_decorpse(str) {SPELL->druid_decorpse(str); return 1; }
cure_minor(str) {SPELL->cure_minor(str); return 1; }
ele_spark(str) { if(check(2)) SPELL->ele_spark(str); return 1; }
ele_arrow(str) { if(check(2)) SPELL->ele_arrow(str); return 1; }
ele_strike(str) { if(check(2)) SPELL->ele_strike(str); return 1; }
ele_shockwave(str) { if(check(2)) SPELL->ele_shockwave(str); return 1; }
ob_mist(str) { if(check(2)) SPELL->ob_mist(str); return 1; }
lesser_fang() { if(check(3)) SPELL->lesser_fang(); return 1; }
rabbit() { if(check(3)) SPELL->rabbit(); return 1; }
summon(str) { if(check(4)) SPELL->summon(str); return 1; }
entangle(str) { if(check(5)) SPELL->entangle(str); return 1; }
lesser_cry(str) { if(check(6)) SPELL->lesser_cry(str); return 1; }
barkskin() { if(check(7)) SPELL->barkskin(); return 1; }
faerie_fire(str) { if(check(8)) SPELL->faerie_fire(str); return 1; }
ele_spikestone(str) { if(check(8)) SPELL->ele_spikestone(str); return 1; }

