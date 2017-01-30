#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

object gold;
int loc_now;

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   no_clean = 1;
   set_name("The Game Crasher");
   set_alt_name("game crasher");
   set_race("human");
   set_short("The Game Crasher");
   set_level(29);
   set_hp(2500+random(1001));
   set_al(0);
   set_wc(90);
   set_assist("/players/jaraxle/3rd/alt/mobs/minion", 30, 5, 7);
   set_wc_bonus(120);
   set_ac(50);
   set_aggressive(0);
   set_heart_beat(1);
   set_dead_ob(this_object());
   set_heal(5,2);
   set_chance(20);
   set_spell_dam(50);
   set_spell_mess1(
      "The Game Crasher drives his fist into your stomach.\n");
   set_spell_mess2(
      "The Game Crasher drives his fist into your stomach.\n");
   gold = clone_object("obj/money");
   gold->set_money(25000 + random(8000));
   move_object(gold,this_object());
   loc_now = 0;
   enable_commands();
   
}

long(){
   write(
      "He is firmly concentrated on counting.\n");
   return 1;
}


heart_beat(){
   ::heart_beat();
   if(attacker_ob){
      if(random(100) < 50){
         if(attacker_ob && !attacker_ob->query_ghost()){
            already_fight=0;
            tell_object(attacker_ob,
               "The Game Crasher raises his hands to the sky. . .\n"+
               RED+"Fire "+NORM+"and"+BLK+BOLD+" Brimstone"+NORM+" rain over the room "+HIR+"burning"+NORM+" your flesh!\n");
            tell_room(environment(),
               "The Game Crasher raises his hands to the sky . . .\n"+
               RED+"Fire "+NORM+"and"+BLK+BOLD+" Brimstone"+NORM+" rain over the room "+HIR+"burning"+NORM+" "+attacker_ob->query_name()+"'s flesh!\n",
               ({attacker_ob}));
            attacker_ob->hit_player(random(90), "other|fire");
         }
      }
      if(random(100) < 30){
         if(attacker_ob && !attacker_ob->query_ghost()){
            already_fight=0;
            tell_object(attacker_ob,
               "The Game Crasher murmurs something in a strange tongue.\n"+
               "\t"+BWHT+BLK+BOLD+" beam of light shoots through your body.\n"+NORM);
            tell_room(environment(),
               "The Game Crasher murmurs something in a strange tongue.\n"+
               "\t"+BWHT+BLK+BOLD+" beam of light shoots through "+attacker_ob->query_name()+"'s body.\n"+NORM,
               ({attacker_ob}));
            attacker_ob->hit_player(30+random(31), "other|light");
         }
      }
      if(random(100) < 30){
         if(attacker_ob && !attacker_ob->query_ghost()){
            already_fight=0;
            attack();
         }
      }
   }
}

monster_died(){
   object misc_treas;
   
   tell_room(environment(),
      HIB+"  The Game Crasher falls to the ground, lifeless.\n"+NORM);
   return 1;
}
