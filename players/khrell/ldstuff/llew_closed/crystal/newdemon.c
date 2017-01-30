#define ANGER_START 0  /* Raise or lower between 0-5 to increase or */
#define ANGER_MOD 3    /* decrease difficulty.  5 is the hardest.   */

#include "/players/llew/closed/ansi.h"

inherit "obj/monster";

int big_att,nofight_BA;
int anger,berserk;

reset(arg) {
   string adj;
   int money_crystals;
   money_crystals=0;
   big_att=0;
   ::reset(arg);
   if(arg) return;
   adj=({"grotesque","deformed","squat","mutated","bloody","writhing","black","green",
      "rippling","irate","snivelling","decayed","screaming","horrible","putrid",
      "smelly","yellow","rotting","horned","huge","barbed","infuriated","maniacal",
      "pestulent","scaled","angry","insane","wailing","psychotic","deranged","cackling"});
   set_name("xetra");
   set_level(20);
   set_race("demon");
   set_hp(random(300)+400+(ANGER_MOD*25));
   set_al(-500-random(600));
   set_aggressive(1);
   set_short("A "+adj[random(sizeof(adj))]+" Xetra");
   set_long("\tA Xetra sucking the light from all around.  Bigger and bigger he\n"+
      "becomes with each particle of blue light.  The light touches the skin of the\n"+
      "Xetra and fades to nothing.\n");
   set_wc(random(16)+20+ANGER_MOD);
   set_ac(random(8)+7+(ANGER_MOD/2));
   set_dead_ob(this_object());
   set_message_hit(({"mutilated"," to a pulpy red mass",
                     "slashed"," spraying the room with blood",
                     "thrashed"," with blood dripping claws",
                     "sliced"," cleanly",
                     "cut","",
                     "grazed","",
                     "scratched"," a glancing blow"}));
   set_chance(10);
   set_spell_mess2("The Xetra reaches into your soul with icy fingers.\n"+
      "Cold evil invades your blood, draining your life.");
   set_spell_mess1("The Xetra eats at a soul.");
   set_spell_dam(20);
   set_a_chat_chance(10);
   load_a_chat("The Xetra eats the blue light.\n");
   load_a_chat("Xetra says:  Hurocdt rufk tri!\n");
   load_a_chat("Xetra says:  Tlurrk bsiri corr.\n");
   load_a_chat("The Xetra reaches for your soul.\n");
   anger=ANGER_START;
   berserk=0;
   nofight_BA=0;
}

heart_beat() {
   if(big_attack()) return;

   ::heart_beat();

   if(berserk) find_target();

   check_anger(0);
   check_fight_self();
   use_heal();
   multiple_attack();
   fight_all_players();

}

monster_died() {
   object crystal;
   crystal=clone_object("/players/llew/Bcrystal/fragment.c");
   move_object(crystal,environment(this_object()));
   say("The Xetra screams in agony as light explodes from it's dying body.\n"+
      "A small fragment of "+crystal->query_info()+" light falls to the ground where it stood.\n");
   if(environment(this_object()) && present("corpse",environment(this_object()))) {
      destruct(present("corpse",environment(this_object())));
   }
}


hit_player(arg) {
   if(!attacker_ob) return 0;
   return ::hit_player(arg); 
}

check_anger(amt) {
   if(amt > -1 && anger + amt < 10-((hit_point*10)/max_hp)) {
      anger = 10-((hit_point*10)/max_hp);
   }
   else {
      anger = anger + amt;
   }
   if(anger <= 2 && !random(4)) whimpy = 1;
   if(anger >= 12 && !random(3)) whimpy = 0;
   if(!berserk && (anger >= 20 - ANGER_MOD || (anger + (ANGER_MOD*3) > random(2000) && attacker_ob))) {
      berserk = 1;   /* Going Berserk.  Yeehaw!  Go, Demon, Go! */
      whimpy = 0;
      if(anger < 15) anger = 15;
      tell_room(environment(),"\n    "+GRY+".."+NORM+"**"+NORM+BOLD+"/ "+NORM+RED+"-"+BOLD+"-"+NORM+RED+"--"+BOLD+"-"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"-"+BOLD+"-"+NORM+RED+"- -"+BOLD+"--"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"- -- "+BOLD+"-"+NORM+RED);
      tell_room(environment()," -- -"+BOLD+"-"+NORM+RED+"- -"+BOLD+"--"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"-"+BOLD+"-"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"--"+BOLD+"-"+NORM+RED+"- "+NORM+BOLD+"\\"+NORM+"**"+GRY+"..\n\n"+NORM);
      tell_room(environment(),"                  The "+RED+"Xetra"+NORM+" is suffused in "+HIR+"red"+NORM+" light.\n\n");
      tell_room(environment(),"               The Demon before you is "+BOLD+"F U R Y"+NORM+" Incarnate!\n\n");
      tell_room(environment(),"    "+GRY+".."+NORM+"**"+NORM+BOLD+"\\ "+NORM+RED+"-"+BOLD+"-"+NORM+RED+"--"+BOLD+"-"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"-"+BOLD+"-"+NORM+RED+"- -"+BOLD+"--"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"- -- "+BOLD+"-"+NORM+RED);
      tell_room(environment()," -- -"+BOLD+"-"+NORM+RED+"- -"+BOLD+"--"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"-"+BOLD+"-"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"--"+BOLD+"-"+NORM+RED+"- "+NORM+BOLD+"/"+NORM+"**"+GRY+"..\n\n"+NORM);
   }
   if(anger >= 25+ANGER_MOD) anger = 25+ANGER_MOD;

}

check_fight_self() {
   if(attacker_ob==this_object() && !random(3)) {
      object rob;
      tell_room(environment(),BOLD+"The xetra screams in rage!\n"+NORM);
      rob=first_inventory(environment());
      attacker_ob=0;
      while(!attacker_ob && rob) {
         if(living(rob) && rob->query_race() != "demon") {
            attacker_ob=rob; }
         else rob=next_inventory(rob);
      }
      check_anger(3+ random(ANGER_MOD/2));
   }
}

fight_all_players() {
   object first,*ri;
   int x,so,number_of_attackers;

   first=attacker_ob;
   number_of_attackers=1;
   for(x=0,ri=all_inventory(environment()),so=sizeof(ri);so>x;x++) {
      if(ri[x] && living(ri[x]) && ri[x] != first && ri[x]->query_attack() == this_object()) {
         if(ri[x]->is_player() || berserk) {
            already_fight=0;
            attack_object(ri[x]);
            attack();
         }
         number_of_attackers++;
      }   
         attack_object(first);
   }
   if(random(16)+1-ANGER_MOD < number_of_attackers * number_of_attackers) check_anger(1);
}

find_target() {
   int x;
   object *ri;
   if((!attacker_ob && random(2)) || !random(4)) {
      ri=all_inventory(environment());
      x=random(sizeof(ri));
      while(!living(ri[x]) || ri[x]->query_race() == "demon") x=random(sizeof(ri));
      attacker_ob = ri[x];


   }
}
         

multiple_attack() {
   int X;

   X=2;
   while(!random(X) && attacker_ob) {
      already_fight=0;
      attack();
      if((!(anger/10 > 0) && random(2)) || !(berserk && random(3)) ) X++;
      if(X > 3 && random(2)) check_anger(1);
   }
}


big_attack() {
   int ba;

   if(big_att || !random(12 - (berserk*9))) {
      if(attacker_ob && environment(attacker_ob) == environment()) {
         if(big_att == 0 && (anger + random(7)) > 15-ANGER_MOD) big_att++;
         switch(big_att) {
            case 0: 
               tell_room(environment(),BOLD+"The Xetra stops fighting.\n"+NORM);
               big_att++;
               nofight_BA=1;
               break;
            case 1:
               tell_room(environment(),BOLD+"\nThe Xetra sucks in the "+HIC+"Blue"+NORM+BOLD+" light.\n\n"+NORM);
               if(anger + random(7) > 10-ANGER_MOD) big_att++;
               big_att++;
               break;
            case 2:
               big_att++;
               break;
            case 3:
               tell_room(environment(),BOLD+"The Xetra unleashes all it's rage!\n"+NORM);
               tell_room(environment(),RED);
               for(big_att=3+ANGER_MOD+random(anger/2),ba=0;ba<big_att;ba++) {
                  already_fight=0;
                  attack();
               }
               tell_room(environment(),NORM);
               big_att=0;
               nofight_BA=0;
               check_anger(1+random(ANGER_MOD/2));
               return 1;
         }
         return nofight_BA;
      }
   }
}


use_heal() {
   if(present("money_crystal")) {
      if( (hit_point*100)/max_hp < 70 + random(20) && anger - random(10) - ANGER_MOD - 1 <= 0 && random(2)) {
         say("     The xetra takes a crystal in its claws, crushing it to tiny dust.\n");
         say("            White light breaks free, surrounding the demon.\n\n");
         heal_self((present("money_crystal")->query_value()/25)+random(16)-8);
         if(!random(ANGER_MOD)) check_anger(-1);
         destruct(present("money_crystal"));
      }
   }
}

stop_fight() {
   if (this_player() && this_player()->query_level() > 21)
   {
      ::stop_fight();
      return 0;
   }
   if(attacker_ob && alt_attacker_ob && !berserk) {
      if(!random((25-anger)/3)) {
         check_anger(1);
         return 0;
      }
   }
   if(berserk == 1 && random(2)) return 0;
   ::stop_fight();
   if(!attacker_ob) {
      big_att=0;
      nofight_BA=0;
      check_anger(-1);


   }
}

prevent_exit() {
   if(!(attacker_ob && (attacker_ob == this_player() || this_player()->query_attack() == this_object()))) return 0;
   if((berserk && random(5)) || random(anger+ANGER_MOD) > 7 || (big_att && random(3))) return 1;
}
