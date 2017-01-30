inherit "/obj/monster";
#include "/players/jareel/ansi.h"
#define TO this_object()

int lives;
int C;
int B;

     reset(arg) {
       ::reset(arg);
       if (!arg) {

     lives = 3;
     set_name("bone");
     set_alias("dead man");
     set_short("Bone");
     set_race("human");
     set_gender("male");
     set_long(
       "\n"+
       "\n"+
       "\n"+
       "\n"+
       "\n");
     set_wc(50);
     set_hp_bonus(1650);
     set_wc_bonus(44);
     set_ac(15);
     set_level(26);
     set_hp(2000);
     set_aggressive(0);
     set_heal(2,1);
     set_al(-1000);
     set_dead_ob(TO);
     set_chance(75);
     set_spell_dam(60);
       set_spell_mess1(BOLD+"A HOWLING BLACK DEMON appears and attacks you and then disappears...\n"+NORM);
       set_spell_mess2(BOLD+"A HOWLING BLACK DEMON appears and attacks you and then disappears...\n"+NORM);
     }
     }

/* Zeus Code */
     life_check()
     {
       if(!present(attacker_ob, environment())) return;
         lives--;
       if(lives == 2)
         set_heal(3,1);
       else if(lives == 1)
         set_heal(4,1);
       tell_room(environment(), 
         BOLD+BLK+"\nBone heals himself.\n\n"+NORM);
           hit_point += 500+random(75); /* Heals 1650 */
           weapon_class += 10+random(7);
           armor_class += 6+random(4);
       }
 



     heart_beat(){
       ::heart_beat();
         if(!environment())
       return ;
         if(!attacker_ob)
         return ;
         C = random(10);
         B = random(10);
           if(attacker_ob){
             if(C <= 3) C_bracer();/* 40% chance for aditional hit +32*/
             if(B <= 3) C_eblur1();/* 40% Chance for 7 damage    +4 */
             if(B == 4) C_eblur2();/* 10% Chance for 10 damage   +1  */
             if(B == 5) C_eblur3();/* 10% Chance for 20 damage   +2  */
             if(C == 4) C_elava(); /* 10% Chance for 15 damage   +1  */
             if(C == 5) C_ehail(); /* 10% Chance for 15 damage   +1  */
             if(C == 6) C_eearth();/* 10% Chance for 15 damage   +1 */
             if(B == 6) C_eblur4();/* 10% Chance for 22 damage   +2  */
         }
 
     if(lives && hit_point <= 400)
       life_check();
     }

     C_bracer() {
       tell_room(environment(TO),
         ""+BOLD+BLU+"Bone's form"+NORM+BOLD+" || |  | blurs |  | ||"+BLU+" as her bracers"+YEL+" glow"+NORM+"...\n");
           already_fight=0;
           attack();
     return;
     }

     C_eblur1()  {
       tell_room(environment(TO),
         ""+BOLD+"Bone blurs in a burst of speed!"+NORM+"\n"+
         "Bone impales "+attacker_ob->query_name()+" with a vicious thrust!\n");
           call_other(attacker_ob,"hit_player",random(5)+10);
     return;
     }

     C_eblur2()  {
       tell_room(environment(TO),
         ""+BOLD+"Bone blurs in a burst of speed!"+NORM+"\n"+
         "Bone impales "+attacker_ob->query_name()+" with a vicious thrust!\n"+
         ""+BOLD+"Bone blurs in a burst of speed!"+NORM+"\n"+
         "Bone impales "+attacker_ob->query_name()+" with a vicious thrust!\n");
           call_other(attacker_ob,"hit_player",random(10)+10);
     return;
     }

     C_eblur3()  {
       tell_room(environment(TO),
         ""+BOLD+"Bone blurs in a burst of speed!"+NORM+"\n"+
         "Bone impales "+attacker_ob->query_name()+" with a vicious thrust!\n"+
         ""+BOLD+"Bone blurs in a burst of speed!"+NORM+"\n"+
         "Bone impales "+attacker_ob->query_name()+" with a vicious thrust!\n"+
         ""+BOLD+"Bone blurs in a burst of speed!"+NORM+"\n"+
         "Bone impales "+attacker_ob->query_name()+" with a vicious thrust!\n");
           call_other(attacker_ob,"hit_player",random(15)+10);
     return;
     }

     C_eblur4()  {
       tell_room(environment(TO),
         ""+BOLD+"Bone blurs in a burst of speed!"+NORM+"\n"+
         "Bone impales "+attacker_ob->query_name()+" with a vicious thrust!\n"+
         ""+BOLD+"Bone blurs in a burst of speed!"+NORM+"\n"+
         "Bone impales "+attacker_ob->query_name()+" with a vicious thrust!\n"+
         ""+BOLD+"Bone blurs in a burst of speed!"+NORM+"\n"+
         "Bone impales "+attacker_ob->query_name()+" with a vicious thrust!\n"+
         ""+BOLD+"Bone blurs in a burst of speed!"+NORM+"\n"+
         "Bone impales "+attacker_ob->query_name()+" with a vicious thrust!\n");
           call_other(attacker_ob,"hit_player",random(20)+10);
     return;
     }

     C_elava() {
       tell_room(environment(TO),
         ""+RED+"\n"+
         "        CRACKS OPEN IN THE EARTH!\n"+
         "\n"+
         "        LAVA SPRAYS FORTH!\n"+
         "\n"+
         "        "+attacker_ob->query_name()+" SCREAMS IN BURNED AGONY!\n"+
         "\n"+
         "HOT PAIN RIPS THROUGH YOU!"+NORM+"\n");     
           call_other(attacker_ob,"hit_player",random(20)+5);
     return;
     }

     C_ehail()  {
       tell_room(environment(TO),
         ""+BLU+"\n"+
         "        THE SKY GROWS DARK!\n"+
         "\n"+
         "         ,', ,', HAIL CRASHES DOWN FROM THE SKY! ,', ,',\n"+
         "\n"+
         "        "+attacker_ob->query_name()+" IS PUMMELED BY THE ICE!\n"+
         ",', ,', THE HAIL SMASHES YOU DOWN! ,', ,',"+NORM+"\n");
           call_other(attacker_ob,"hit_player",random(20)+5);
     return;
     }

     C_eearth() {
       tell_room(environment(TO),
         ""+YEL+"\n"+
         "        * * THE EARTH SHAKES!\n"+
         "\n"+
         "        "+attacker_ob->query_name()+" FALLS TO THE GROUND!\n"+
         " * * * * THE EARTH RISES TO CRUSH YOU! * * * * "+NORM+"\n");     
           call_other(attacker_ob,"hit_player",random(20)+5);
     return;
     }

