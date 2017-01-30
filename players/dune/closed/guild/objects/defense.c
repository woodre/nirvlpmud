
/*
 * CyberNinja Defensive Skills
 * Reduces damage from 0-75% depending on mode
 */

#include "../DEFS.h"

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
  if(modenum == 2) {
/* DEFENSE MODE - MAX OF 75% DAMAGE REDUCTION */
    defnum = gob->query_art_level() * 5;
    if(defnum > 75) defnum = 75;
  }
  if(modenum == 1) {
/* ATTACK MODE - 5% DAMAGE INCREASE */
    defnum = -5; }
  if(!modenum) {
/* NORMAL MODE - DAMAGE REDUCTION OF 0-68% */
    defnum = random(gob->query_art_level() * 4); }
  if(defnum > 0) defmsg = "some";
  if(defnum > 20) defmsg = "a lot";
  if(defnum > 50) defmsg = "most";
  if(defnum > 70) defmsg = "nearly all";
  if(defnum > 0)
    tell_object(player,BOLD+"~~ You block "+defmsg+" of "+attname+"'s attack!\n"+OFF);
   tmp_dam = (100-defnum)*dam/100;
   player->hit_player(tmp_dam);
   return tmp_dam;
}

