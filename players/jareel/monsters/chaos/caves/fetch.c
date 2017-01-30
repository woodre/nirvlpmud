inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/jareel/ansi.h"
#include "/players/zeus/closed/all.h"

     int lives;
     int M;
     
       reset(arg) {
       ::reset(arg);
       if (!arg) {
     lives = 3;
     set_name("fetch");
     set_alias("spirit");
     set_short(BOLD+"A Fetch"+NORM);
     set_race("spirit");
     set_long(
       "This is a huge transparent spirit manifested by his friend and \n"+
       "college to protect him from your aggressive posture.\n");
     set_wc(69);
     set_hp_bonus(1800);
     set_wc_bonus(75);
     set_ac(40);
     set_level(26);
     set_hp(600);
     set_aggressive(1);
     set_heal(2,1);
     set_aggro(1, 10, 100);
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
           BOLD+"\n\nThe Fetch reforms itself in a swirl of energy.\n\n"+NORM);
           hit_point += 500+random(75); /* Heals 1800 */
           weapon_class += 10+random(7);
           armor_class += 1+random(4);
       }
 



     heart_beat(){
       ::heart_beat();
         if(attacker_ob) 
           M = random(10);
               if(attacker_ob){
               if(M == 3) M_blades();
               if(M <= 2) M_POWER();
               else if(M >= 4) M_POWER();
         }
         if(lives && hit_point <= 400)
           life_check();
    }

     M_blades()  {
       tell_room(environment(TO),
         ""+HIC+"The Fetch looks into "+attacker_ob->query_name()+"'s soul.\n"+
         "          "+HIC+attacker_ob->query_name()+" soul is torn at by the Fetch"+NORM+"\n");
         attacker_ob->hit_player(random(50)+50, "other|spirit");
     return;
     }

     M_POWER() {
       tell_room(environment(TO),
          "The Fetch rises up and slashes at "+attacker_ob->query_name()+".\n");
          attacker_ob->hit_player(random(40)+40, "other|spirit");

       return;
     }

monster_died() {
return 0;}
