inherit "/obj/monster";
#include "/players/jareel/define.h"

     int V;
     int spear;
     int armor;

     reset(arg)  {
       ::reset(arg);
         if (arg) return;

     set_name("jalon");
     set_alias("elite");
     set_alt_name("guard");
     set_race("human");
     set_al(0);
     set_level(21);
     set_aggressive(0);
     set_hp(600);
     set_ac(19);

     MOCO("/players/jareel/weapons/yelmalian_elite_spear.c"),this_object());
       init_command("wield spear");
     MOCO("/players/jareel/armor/yelmalian_elite_battle_armor.c"),this_object());
       init_command("wear armor");
    set_wc(34);
    set_wc_bonus(24);
    set_gender("male");
    add_money(2000+random(1000));
    set_dead_ob(this_object());
    set_short(
      "Jalon - "+RED+"["+BOLD+YEL+"Yelmalian"+NORM+RED+"] "+BOLD+YEL+"Elite Lieutenant"+NORM+"  (neutral)  [leader of party [Hunting Party]");

    set_long(
      "Jalon stares at you from under his full helm.  Flowing\n"+
      "blond hair flows down his back.  Battle seems to have made  \n"+
      "his soul dark with hatred.  Blood stains his padding yet his\n"+
      "armor glows with a pristine.  \n"
            );

    set_chance(20);
    set_spell_mess1(
      "Vandar shoots out a bolt of energy.\n");
    set_spell_mess2(
      "Vandar casts a disruption at you.\n"+
      "\n"+
      "                     Your skin"+RED+" B O I L S!\n"+
      ""+NORM+"\n");
    set_spell_dam(40);
}

    heart_beat(){
      object ob;
      object att;
      object next;
        if(!environment()) return;
          if(ob = present("elite", environment())) { if(ob->query_attack())             attack_object(ob->query_attack()); } ;
      ::heart_beat();
        if(attacker_ob) {
          already_fight=0;
          V = random(4);
            if(attacker_ob){
            if(V == 2) V_stab();
            else if(V == 3) V_bladesharp();
     }
  }
}

     V_stab()  {
       tell_room(environment(TO),
         "Jalon stabs you with his spear.\n");
           call_other(attacker_ob,"hit_player",random(25)+10);
     return;
}

     V_bladesharp() {
       tell_room(environment(TO),
         "Jalon unleashes a blast of solar energy...\n"+
         "\n"+
         "      "+BLINK+CYN+" E N E R G Y "+NORM+" leaps from the blade.\n"+
         "\n");
           call_other(attacker_ob,"hit_player",random(30)+35);
     return;
     }
