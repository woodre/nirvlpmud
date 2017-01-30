#define COMM this_object()->wonk()
inherit "/obj/monster";

/*
#include "/players/beck/DarkRangers/RangerDefs.h"
*/

reset(arg) {
   ::reset(arg);
     set_name("hermit");
     set_short("Hermit");
     set_race( "human");
     set_gender("male");
     set_alt_name("gray");
     set_long(
"\tAs you peer more closely at the Hermit, you see a dark, scowling\n"+
"visage famed by locks of dirty brown hair. He appears to be human\n"+
"but is dressed in such a bundle of shoddy clothing that you cannot\n"+
"tell for sure. He reeks of some dark, subterranean substance and has\n"+
"an evil twinkle in his eyes.\n");
     set_level(20);
     set_ac(25);
     set_wc(45);
     set_hp(450);
/* NEW CODE */
set_ac_bonus(6);
set_wc_bonus(38);
     set_al(-750);
     set_aggressive(0);
     set_chat_chance(8);
     set_a_chat_chance(8);
     load_chat("The hermit leers at you.\n");
     load_chat("The hermit says: What do you want?\n");
     load_chat("The hermit digs furiously into the dirt for a second.\n");
     load_a_chat("The hermit spins gracefully in his dance of death!\n");
}

heart_beat() {
  ::heart_beat();
  if(query_hp() < query_mhp()) heal_self(random(5)+1);
  if(attacker_ob == this_object()) { stop_fight(); stop_fight(); stop_hunted(); }
  if(attacker_ob && environment(attacker_ob) == environment()) combat_mode();
}

combat_mode() {
  if(!attacker_ob || environment(attacker_ob) != environment()) return;
  if(!random(3)) punch(attacker_ob);
  if(!random(4)) kick(attacker_ob);
  if(!random(10)) pressure_point(attacker_ob);
  return 1; }

punch(object ob) {
  tell_room(environment(),
    "The Hermit screams:\n\t\tKatumagi-Chop!\n\n");
  ob->hit_player(random(20)+30);
  return 1; }

kick(object ob) {
  tell_room(environment(),
    "The Hermit screams:\n\t\tSaru-Gata-Kick!\n\n");
  ob->hit_player(random(40)+40);
  return 1; }

pressure_point(object ob) {
  tell_room(environment(),
    "\n\tThe Hermit touches "+ob->query_name()+" lightly.\n");
  tell_object(ob, "\n\n\n\t\tYOUR BODY BURSTS INTO FLAME!\n\n");
  ob->hit_player(random(30) + 60, "other|fire");
  return 1; }

init() {
  ::init();
  if(COMM) {
  string type;
    if(COMM->QKarateLevel() == 9){
      if(COMM->QKarateExtraLevel() == 8){ type = "none"; }
      if(COMM->QKarateExtraLevel() == 7){ type = "8th degree"; }
      if(COMM->QKarateExtraLevel() == 6){ type = "7th degree"; }
      if(COMM->QKarateExtraLevel() == 5){ type = "6th degree"; }
      if(COMM->QKarateExtraLevel() == 4){ type = "5th degree"; }
      if(COMM->QKarateExtraLevel() == 3){ type = "4th degree"; }
      if(COMM->QKarateExtraLevel() == 2){ type = "3rd degree"; }
      if(COMM->QKarateExtraLevel() == 1){ type = "2nd degree"; }
      if(COMM->QKarateExtraLevel() == 0){ type = "1st degree"; }
    }
    if(COMM->QKarateLevel() == 8){ type = "black"; }
    if(COMM->QKarateLevel() == 7){ type = "brown"; }
    if(COMM->QKarateLevel() == 6){ type = "purple"; }
    if(COMM->QKarateLevel() == 5){ type = "blue"; }
    if(COMM->QKarateLevel() == 4){ type = "green"; }
    if(COMM->QKarateLevel() == 3){ type = "red"; }
    if(COMM->QKarateLevel() == 2){ type = "orange"; }
    if(COMM->QKarateLevel() == 1){ type = "yellow"; }
    if(COMM->QKarateLevel() == 0){ type = "white"; }
    COMM->TrainRanger("Hermit", type);
  }
}

#include "/players/earwax/closed/shardak/misc/hermit_task.c"
