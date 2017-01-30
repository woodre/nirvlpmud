/* **********************************************************************
*
********************************************************************** */

inherit "/obj/monster";
#include "/players/jareel/define.h"

     reset(arg) {
       ::reset(arg);
         if(arg) return;

     set_race("troll");
     set_name("lord");
     set_alt_name("zorak");
     set_short("A "+BOLD+BLK+"Zorak Zoran - Death Lord"+NORM);
     set_long(
      "\n"+
      "\n"+
      "\n"+
      "\n"+
      "\n"
     );
     if(!random(2)) set_gender("male"); else set_gender("female");
     set_level(23);
     set_wc(40);
     set_ac(21);
     set_hp(800);
     set_al(-1000);
     add_money(5500+random(2500));
     set_chance(30);
     set_spell_mess1(
       "The Death Lord strikes at its foe.\n");
     set_spell_mess2(
       "With blinding speed the Death Lord strikes at you.\n"); 
     set_spell_dam(50);
     }

     heart_beat() {
       ::heart_beat();
         if(attacker_ob) {
           already_fight=0;
             attack();
           already_fight=0;
             attack();
           already_fight=0;
             attack();
     }
}

     init() {
       ::init();
         add_action("stop","west");
         add_action("stop","north");
         add_action("stop","east");
         add_action("stop","south");
     }

     stop() {
       if(TP->query_ghost() == 1) { return 0; }
         else{
       if(TP->query_level() >8 && TP->query_level() <20) {
         write("Lord blocks your exit.\n");
           attack_object(this_player());
         return 1; }}
     }
