inherit "/obj/monster";
#include "/players/jareel/ansi.h"
#include "/players/zeus/closed/all.h"

     int lives;
     int M;
     int B;
     int D;
     reset(arg) {
       ::reset(arg);
       if (!arg) {
     lives = 3;
     set_name("konya");
     set_alias("kon");
     set_short("A statue of the "+BOLD+RED+"Angel"+NORM+" of "+BOLD+BLK+"Death Konya the "+NORM+RED+"~ "+BLU+"Ele"+GRN+"men"+NORM+BOLD+"tal Cybe"+NORM+GRN+"rDae"+BLU+"mon "+RED+"~ "+NORM+"( "+BOLD+BLK+"Nirvana's Badass Legend"+NORM+" )"+NORM);
     set_race("human");
     set_gender("female");
     set_long(
       "\n"+
       "\n"+
       "\n"+
       "\n"+
       "\n");
     set_wc(69);
     set_hp_bonus(1800);
     set_wc_bonus(75);
     set_ac(40);
     set_level(26);
     set_hp(600);
     set_aggressive(1);
     set_heal(2,1);
     set_al(-500);
     set_dead_ob(TO);
     }
     

}
/* Zeus Code */
     life_check()
     {
       if(!present(AO, environment())) return;
         lives--;
       if(lives == 2)
         set_heal(3,1);
       else if(lives == 1)
         set_heal(4,1);
       tell_room(environment(), 
           MAG+"\nKonya heals himself.\n"+NORM);
           hit_point += 500+random(75); /* Heals 1800 */
           weapon_class += 10+random(7);
           armor_class += 1+random(4);
       }
 



     heart_beat(){
       ::heart_beat();
         if(attacker_ob) 
           M = random(10);
           B = random(3); 
           D = random(5);
             if(attacker_ob){
               if(B == 1) B_heal();
               if(D == 0) D_1();
               if(D == 1) D_2();
               if(D == 2) D_3();
               if(D == 3) D_4();
               if(D == 4) D_5();  
               if(M <= 2) M_blades();
               if(M == 3) M_POWER();
               else if(M >= 4) M_POWER();
         }
         if(lives && hit_point <= 400)
           life_check();
    }

     M_blades()  {
       tell_room(environment(TO),
         "Double laser disruption funnels thunder from Konya's eyes and slam into you!\n"+
         "Double laser disruption funnels thunder from Konya's eyes and slam into "+attacker_ob->query_name()+".\n"+
         ""+RED+attacker_ob->query_name()+" is impaled on Konya's blades!"+NORM+"\n");
         attacker_ob->hit_player(random(50)+50, "other|jareel");
     return;
     }

     M_POWER() {
       tell_room(environment(TO),
         "Double laser disruption funnels thunder from Konya's eyes and slam into you!\n"+
         "Double laser disruption funnels thunder from Konya's eyes and slam into "+attacker_ob->query_name()+".\n");
          attacker_ob->hit_player(random(40)+40, "other|jareel");

       return;
     }

     B_heal() {
       tell_room(environment(TO),
         "Konya squeezes some splooge inher mouth.\n");
           heal_self(random(20)+30);
       return;
     }

     D_1() {
       tell_room(environment(TO),
         "Konya flash-rolls to the left!\n");
            return;
     }
    
     D_2() {
       tell_room(environment(TO),
         "Konya performs a right forearm cross-parry.\n");
           return;
     }

     D_3() {
       tell_room(environment(TO),
         "Konya leans back.\n");
           return;
     }

     D_4() {
       tell_room(environment(TO),
         "Konya steps back slightly.\n");
           return;
     }

     D_5() {
       tell_room(environment(TO),
         "Konya shoulder-rolls to the left.\n");
           return;
     }


monster_died() {
return 0;}
