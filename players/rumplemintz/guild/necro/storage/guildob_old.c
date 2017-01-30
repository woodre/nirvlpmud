/* THE BASE NECROMANCER OBJECT */

#include "/players/daranath/guild/defs.h"
#define SPELL "/players/daranath/guild/daemon"
#define SAVE "players/daranath/guild/member/"
#define spellfailed write("You lose your concentration.\n"); return 1;

int blood, eye, heart, skin, soul, spine;
int cdust;
int free_skill, perc, val;

query_auto_load() {return "/players/daranath/guild/guildob.c"; }
id(str) {return str == "necro_ob" || str == "skull"; }
short() { return "A small, brightly polished skull"; }
long() {
write("A skull taken from a treasured victory of long ago.\n"+
      "The skull has been meticulously cleaned and taken\n"+
      "care of. The symbol of a true Necromancer.\n"+
      "<"+BOLD+"nhelp"+NORM+"> for necromantic notes.\n");
  }

drop() { return 1;}
get() { return 0;}
/*
extra_look() {
object ex_look;
  ex_look = environment(this_object())->query_name();
  write(ex_look+" has a small skull tattoo upon "+tp()->query_possessive()+" forehead.\n");
}
*/
init() {
if(environment(this_object()) == this_player()) {
  if(!restore_object(SAVE+tpn)) {
    free_skill = 15;
    blood = 0;
    eye = 0;
    heart = 0;
    skin = 0;
    soul = 0;
    spine = 0;
    cdust = 0;
    perc = allocate(32);
    save_object(SAVE+tpn);
  }
  
  /* basic guild abilities */
add_action("guild_chat","nt");
add_action("guild_emote","nte");
add_action("guild_who","nwho");
add_action("guild_score","nsc");
add_action("guild_score","nscore");
add_action("guild_quit","repentance");
add_action("guild_save","nsave");
add_action("guild_notes","nhelp");
add_action("necro_missile","missile");
add_action("necro_shock","shock");
add_action("necro_ball","fireball");
add_action("necro_sonic","sonic");

  /* level 1 spells */
add_action("wraithform","wraithform");
add_action("necro_call","ncall");
add_action("dembrace","embrace_death");
add_action("touch_chill","chill");
add_action("evaluate","evaluate");
add_action("preserve","preserve");
add_action("craft1","craft1");
add_action("autopsy","autopsy");
add_action("toolme","summon_tool");

  /* level 2 spells */
add_action("assasinate","assasinate");
add_action("badmoon","badmoon");
add_action("dis_burial","disturb");
add_action("life_drain","lifedrain");
add_action("consume","consume");
add_action("death_door","ddoor");

  /* level 3 spells */
add_action("abandon","abandon");
add_action("bury_me","buried_alive");
add_action("con_cloak","cloak");
add_action("consecrate","con_grave");

  /* level 4 spells */
add_action("craft2","craft2");
add_action("patchwork","patch");
add_action("ghast_stench","stench");

  /* level 5 spells */
add_action("grave_pact","gravepact");
add_action("haunt_wind","hauntwind");
add_action("cad_touch","ctouch");

  /* level 6 spells */
add_action("drain_spirit","spdrain");
add_action("un_grasp","grasp");
add_action("divination","divine");

  /* level 7 spells */
add_action("grave_hands","hands");
add_action("grafting","graft");
add_action("jester_cos","caress");

  /* level 8 spells */
add_action("blind_ag","agony");
add_action("deathfog","deathfog");

  /* level 9 spells */
add_action("blanket","blanket");

  /* level 10 spells */
add_action("raise_dead","raise");
add_action("death_spell","death");
add_action("dark_intr","intrude");

  /* avatar spells */
add_action("banshee","banshee");
add_action("ceremony","ceremony");
add_action("darkpact","darkpact");
}
  }

add_perc(int mem,int val) {
  set_perc(mem,query_perc(mem) + val);
}

set_perc(int mem,int val) { /* present("necro_obj",tp)->set_perc(0,30); */
 perc[mem] = val;
 save_me();
return 1; }

query_perc(int mem) { return perc[mem]; }
query_blood() {return blood; }
query_skin() {return skin; }
query_eye() {return eye; }
query_spine() {return spine; }
query_heart() {return heart; }
query_soul() {return soul; }
query_cdust() {return cdust; }

save_me() { save_object(SAVE+tpn); return 1; }

add_blood(int num){ blood += num; }
add_skin(int num){ skin += num; }
add_eye(int num){ eye += num; }
add_spine(int num){ spine += num; }
add_heart(int num){ heart += num; }
add_soul(int num){ soul += num; }
add_cdust(int num){ cdust += num; }

guild_notes() {
write("---------------  NECROMANCERS  ----------------\n\n");
return 1;
}
preserve() {SPELL->preserve(); return 1; }
consume() {SPELL->consume(); return 1; }
dembrace() {SPELL->dembrace(); return 1; }

touch_chill(str) { 
  if(!spell_failure(perc[0])) { spellfailed }
    SPELL->touch_chill(str); return 1; }

spell_failure(int j) {
  j = 100;
  if(random(100) > j) return 0;
  else return 1; }
  
