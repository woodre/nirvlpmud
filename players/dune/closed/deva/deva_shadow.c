/*
 * Modified from Paladin protection from evil
 * 1/2 stuff, intox, soak
 * Protection from evil and monster types
 */
 
#include "def.h"
object player;
int damage, tot_pro;
 
query_deva_shadow() { return 1; }
query_damage() { return damage; }
query_tot_pro() { return tot_pro; }
 
#define LEV player->query_level() + player->query_extra_lev()
 
start_deva_shadow(who) {
   player = who;
   shadow(player, 1);
   return 1; }
 
stop_deva_shadow() {
   shadow(player, 0);
   destruct(this_object());
   return 1; }
 
quit() {
   shadow(player, 0);
   player->quit();
   return 1; }
 
short() { 
  int tlev;
  tlev = this_player()->query_level();
  if(tlev < 20 && tlev + this_player()->query_extra_lev() < LEV) {
    return BOLD+"A shining being of light"+OFF; }
  else return player->short(); }
 
drink_alcohol(int num) {
  int alc, alcnum;
  alc = player->query_intoxination();
  alcnum = (player->query_level() + 3)/2;
  if(num + alc > alcnum) {
    tell_object(player, "Your holy body rejects so much impurity.\n");
    return 0; }
  else player->drink_alcohol(num);
  return 1; }
 
eat_food(int num) {
  int stuf, stufnum;
  stuf = player->query_stuffed();
  stufnum = player->query_level() * 4;
  if(num + stuf > stufnum) {
    tell_object(player, "Your holy body rejects so much impurity.\n");
    return 0; }
  else player->eat_food(num);
  return 1; }
 
drink_soft(int num) {
  int soak, soaknum;
  soak = player->query_soaked();
  soaknum = player->query_level() * 4;
  if(num + soak > soaknum) {
    tell_object(player, "Your holy body rejects so much impurity.\n");
    return 0; }
  else player->drink_soft(num);
  return 1; }
 
hit_player(dam) {
  int tmp_dam, sub, att_aln;
  object att_obj, gob;
  string hit_msg;
 
  att_obj = this_player();
  gob = present(GUILDID, player);
  if(att_obj) att_aln = att_obj->query_alignment();
  damage += dam;
 
/* CANNOT FIGHT GOOD */
  if(att_obj && att_aln > 0) {
    att_obj->stop_fight(); att_obj->stop_hunted();
    if(player->query_attack() == att_obj) {
      player->stop_fight(); player->stop_hunted(); }
  }
 
/* MINOR DAMAGE NEGATED (max 8) */
  if(dam < (gob->query_setting(CLASS) + 1)) return 1;
 
  sub = 1;
 
/* MONSTER TYPE PROTECTION */
  if(spec_mon(att_obj)) sub += 2;
 
  tmp_dam = dam *(10-sub)/10;
  tot_pro += (dam - tmp_dam);
  hit_msg = "** Part of "+att_obj->query_name()+
            "'s power is absorbed by your goodness! **\n";
  if(gob->query_setting(COLOR)) { TE(player, BOLD+hit_msg+OFF); }
  else TE(player, hit_msg);
  player->hit_player(tmp_dam);
  return tmp_dam;
}
 
spec_mon(object ob) {
  if(call_other(ob, "id") == "demon"   ||
     call_other(ob, "id") == "devil"   ||
     call_other(ob, "id") == "undead"  ||
     call_other(ob, "id") == "imp"     ||
     call_other(ob, "id") == "shadow"  ||
     call_other(ob, "id") == "shade"   ||
     call_other(ob, "id") == "daemon"  ||
     call_other(ob, "id") == "spirit"  ||
     call_other(ob, "id") == "ghost") return 1;
  else return 0; }

add_alignment(x) {
  int num;
  if(x >= 0) num = x + 100;
  if(x < 0) num = x - 100;
  player->add_alignment(num);
  return 1; }
