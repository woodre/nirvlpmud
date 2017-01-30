#include "/players/snow/guild/def.h"

object player;
int damage;

query_cyborg() { return 1; }

start_cyborg(who) {
   player = who;
   shadow(player, 1);
   return 1;
}

stop_cyborg() {
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
   int tmp_dam, defnum;
   object att_obj, gob;
   string attname, defmsg;
   att_obj = this_player();
   attname = att_obj->query_name();
   gob = present("cyborg_slave", player);

/* Make sure we don't interfere with objects or spells that damage ourself */
  if(this_player() == player) { player->hit_player(dam); return dam; }

/* SUB-DERMAL ARMORING - DAMAGE REDUCTION OF (RANDOM(10)+ 1) % */
  if(gob->query_armor()) defnum += (random(10)+ 1);
   tmp_dam = (100-defnum)*dam/100;
   player->hit_player(tmp_dam);
/* Testing for Snow */
  if(player->query_real_name() == "snow") tell_object(player, "DAMAGE TAKEN: "+tmp_dam+"/"+dam+"\n");
   return tmp_dam;
}

find_side() {
  if(random(2)) return "right";
  else return "left"; }

room_tell(string rmsg) {
  object allroom;
  int i;
  allroom = all_inventory(environment(player));
  for(i=0; i < sizeof(allroom); i++) {
    if(allroom[i] != player) tell_object(allroom[i], rmsg); }
  return; }
