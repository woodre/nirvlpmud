#include "../define.h"
inherit "/obj/monster";
int w, wander_time;
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("guard");
   set_bullshit(0, 20);
   set_heart_beat(2);
   set_short("A village guard");
   set_long(
      "  Stocky and strong, this man handles security for the village.\n"+
      "Currently he looks distracted from his job as though he is\n"+
      "helping in a search.  He wears a simple plate of wooden splint\n"+
      "armor and holds a large wooden bladed staff.\n");
   set_race("human");
   MO(CO(OBJ_DIR+"bladed_staff"),TO);
   MO(CO(OBJ_DIR+"splint_mail"),TO);
   enable_commands();
   command("wield staff",TO);
   command("wear armor",TO);
   set_level(20);
   GUIDE->calc_stats(20);
   set_wc(GUIDE_WC+5);
   set_ac(17);
   set_hp(GUIDE_HP);
   set_gender("male");
   set_spell_dam(40);
   set_spell_mess1("The guard dodges left, then right.\n"+
      "The guard leaps into his opponent!\n");
   set_spell_mess2("The guard dodges your attack.\n"+
      "The guard leaps into you, slashing in a frenzy!\n");
   set_chance(15);
   set_chat_chance(5);
   set_a_chat_chance(15);
   load_chat("The guard calls out for Celia.\n");
   load_chat("The guard looks at you with disdain.\n");
   load_chat("Guard says, \"Have you spoken with Juribel?\"\n");
   load_chat("The guard wanders on.\n");
   load_chat("The guard looks through some brush.\n");
   load_chat("Guard says, \"I'd hate to have to go into the swamp...\"\n");
   load_a_chat("The guard slashes into you with fury!\n");
   load_a_chat("The guard concentrates deeply....\n");
   load_a_chat("The guard rips into you with his bladed staff!\n"); }

heart_beat(){
   ::heart_beat();
   if(wander && !query_attack()) {  
      if(wander_time++ > wander && !random(4)) {
         random_move();  
      } 
   }
}   

void set_bullshit(int chance, int time) {  
   wander = time;  
   set_heart_beat(1); 
}  
