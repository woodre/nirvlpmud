/*
 * CyberNinja Defensive Skills
 * Reduces damage from 0-75% depending on mode
 */

#include "/players/dune/closed/guild/DEFS.h"

object player;
int damage;

query_defense() { return 1; }

start_defense(who) {
   player = who;
   shadow(player, 1);
   return 1;
}

stop_defense() {
   shadow(player, 0);
   destruct(this_object());
   return 1;
}

quit() {
   shadow(player, 0);
   player->quit();
   return 1;
}

hit_player(dam) {
   int tmp_dam, modenum, defnum;
   object att_obj, gob;
   string attname, defmsg;
   att_obj = this_player();
   attname = att_obj->query_name();
   gob = present(GUILD_ID, player);
   modenum = gob->query_attack_mode();

/* DEFENSE MODE - MAX OF 75% DAMAGE REDUCTION */
  if(modenum == 2) {
    defnum = gob->query_art_level() * 5;
    if(defnum > 75) defnum = 75;
  }

/* ATTACK MODE - 5% DAMAGE INCREASE */
  if(modenum == 1) { defnum = -5; }

/* NORMAL MODE - DAMAGE REDUCTION OF 0-68% */
  if(!modenum) {
    defnum = random(gob->query_art_level() * 4); }

/* SHOW DEFENSIVE MESSAGE */
  if(defnum > 0 && defnum <= 10)
    show_move(random(5), player, environment(this_object()));
  if(defnum > 10 && defnum <= 40)
    show_move((random(10)+4), player, environment(this_object()));
  if(defnum > 40)
    show_move(random(18)+4, player, environment(this_object()));
tell_object(find_player("snow"), "DEFNUM = "+defnum+"\n");
/* SUB-DERMAL ARMORING - DAMAGE REDUCTION OF (RANDOM(10)+ 1) % */
  if(gob->query_armor()) defnum += (random(10)+ 1);
tell_object(find_player("snow"), "ARMOR ADDED = "+defnum+"\n");
   tmp_dam = (100-defnum)*dam/100;
   player->hit_player(tmp_dam);
   return tmp_dam;
}

show_move(int num, object player, object room) {
  string pmsg, rmsg, me;
  me = player->query_name()+" ";

if(num == 0) {
pmsg = "You cringe.";
rmsg = me+"cringes."; }

if(num == 1) {
pmsg = "You duck and pray.";
rmsg = me+"ducks and prays."; }

if(num == 2) {
pmsg = "You exhale at the moment of impact!";
rmsg = me+"exhales at the moment of impact!"; }

if(num == 3) {
pmsg = "You step back slightly.";
rmsg = me+"steps back slightly."; }

if(num == 4) {
pmsg = "You lean back.";
rmsg = me+"leans back."; }

if(num == 5) {
pmsg = "You twist slightly to the left.";
rmsg = me+"twists slightly to the left."; }

if(num == 6) {
pmsg = "You twist slightly to the right.";
rmsg = me+"twists slightly to the right."; }

if(num == 7) {
pmsg = "You step to the right.";
rmsg = me+"steps to the right."; }

if(num == 8) {
pmsg = "You step to the left.";
rmsg = me+"steps to the left."; }

if(num == 9) {
pmsg = "You perform a left forearm cross-parry.";
rmsg = me+"performs a left forearm cross-parry."; }

if(num == 10) {
pmsg = "You perform a right forearm cross-parry.";
rmsg = me+"performs a right forearm cross-parry."; }

if(num == 11) {
pmsg = "You shoulder-roll to your left.";
rmsg = me+"shoulder-rolls to the left."; }

if(num == 12) {
pmsg = "You shoulder-roll to your right.";
rmsg = me+"shoulder-rolls to the right."; }

if(num == 13) {
pmsg = "You flash-roll to your left!";
rmsg = me+"flash-rolls to the left!"; }

if(num == 14) {
pmsg = "You flash-roll to your right!";
rmsg = me+"flash-rolls to the right!"; }

if(num == 15) {
pmsg = "You flash-roll back!";
rmsg = me+"flash-rolls back!"; }

if(num == 16) {
pmsg = "You perform a back handspring!";
rmsg = me+"performs a back handspring!"; }

if(num == 17) {
pmsg = "You flip to your left!";
rmsg = me+"flips to the left!"; }

if(num == 18) {
pmsg = "You flip to your right!";
rmsg = me+"flips to the right!"; }

if(num == 19) {
pmsg = "You flip-turn left!";
rmsg = me+"flip-turns left!"; }

if(num == 20) {
pmsg = "You flip-turn right!";
rmsg = me+"flip-turns right!"; }

if(num == 21) {
pmsg = "You flip-turn back!";
rmsg = me+"flip-turns back!"; }

  tell_object(player, BOLD+pmsg+OFF+"\n");
  room_tell(rmsg+"\n");
  return; }

room_tell(string rmsg) {
  object allroom;
  int i;
  allroom = all_inventory(environment(player));
  for(i=0; i < sizeof(allroom); i++) {
    if(allroom[i] != player) tell_object(allroom[i], rmsg); }
  return; }
