inherit "/obj/monster";
#include "/players/jareel/define.h"
#define TO this_object()

     int V;
     int spear;
     int armor;

     reset(arg)  {
       ::reset(arg);
         if (arg) return;

     set_name("doran");
     set_alias("elite");
     set_alt_name("guard");
     set_race("human");
     set_al(0);
     set_level(21);
     set_aggressive(0);
     set_hp(600);
     set_ac(19);
     MOCO("/players/jareel/weapons/yelmspear.c"),this_object());
       init_command("wield spear");
     set_wc(34);
     set_wc_bonus(64); /* two additional attackers, the weapon, and the special specials */
     set_gender("male");
     add_money(2000+random(1000));
     set_dead_ob(this_object());
     set_short(
"Doran - "+RED+"["+BOLD+YEL+"Yelmalian"+NORM+RED+"] "+BOLD+YEL+"Elite General"+NORM+"  (neutral) ");
    set_long(
      "Doran is an older man.  Having seen many years of\n"+
      "battle, his far-away stare makes you believe he has\n"+
      "been in too many fights.  You get the sense that a dark\n"+
      "hatred fills his soul.  \n");
    set_chance(50);
    set_spell_mess1(
      "Vandar shoots out a bolt of energy.\n");
    set_spell_mess2(
      "Vandar casts a disruption at you.\n"+
      "\n"+
      "                     Your skin"+RED+" B O I L S!\n"+
      ""+NORM+"\n");
    set_spell_dam(30);
    set_chat_chance(2);
      load_chat("Doran says:  The creatures of Darkness will die on the head of my spear.\n");
      load_chat("Doran says:  We will vanquish all in this realm of Darkness!\n");
    }

    heart_beat(){
      object ob;
      object att;
      object next;
        if(!environment()) return;
          if(ob = present("guard", environment())) { if(ob->query_attack()) 
attack_object(ob->query_attack()); } ;
      ::heart_beat();
        if(attacker_ob) {
          already_fight=0;
          V = random(3);
            if(attacker_ob){
            if(V == 1) V_stab();
            else if(V == 2) V_bladesharp();
     }
  }
}

     V_stab()  {
       tell_room(environment(TO),
         "Doran stabs you with his spear.\n");
           call_other(attacker_ob,"hit_player",random(25)+10);
     return;
}

     V_bladesharp() {
       tell_room(environment(TO),
         "Doran unleashes solar energy....\n"+
         "\n"+
         "      "+BLINK+HIY+" F L A M E S "+NORM+" engulf his foe.\n"+
         "\n");
           call_other(attacker_ob,"hit_player",random(26)+45);
     return;
     }
