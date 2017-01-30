#include "/players/jareel/ansi.h"
inherit "/obj/weapon";
#define ATT USER->query_attack()
#define USER environment(this_object())

      reset(arg){
        if(arg) return;
          ::reset(arg);
    
     set_alt_name("limbcleaver");
     set_alias("naginata");
     set_name(
       "Limbcleaver, Konya's Naginata of doom!!!"
             );
     set_long(
       "A Naginata\n"+
       "\n"+
       "\n"
             );
     set_read("Limbcleaver, Konya's Naginata of doom!!!\n");
     set_class(10);
     set_type("pole arm");
     set_weight(2);
     set_value(10000);
     set_hit_func(this_object());
}

weapon_hit(attacker){
     
     int a;
     int b;
     int c;
     int d;
     int e;
     int f;
     int g;
     int h;
     int i;
     int j;
     int k;
     int l;
     a = random(3);
     b = random(3);
     c = random(4);
     d = random(4);
     e = random(4);
     f = random(4);
     g = random(4);
     h = random(4);
     i = random(4);
     j = random(4);
     k = random(4);
     l = random(4);
     


      if(a==0){
write(RED+"*~*"+NORM+"Blood spatters everywhere!\n");
say(RED+"*~*"+NORM+"Blood spatters everywhere!\n");
attacker->hit_player(1+random(2));

       }
 
       if(b==0){
write(RED+"*~*"+NORM+"You impale "+ATT->query_name()+" through the throat!\n");
say(RED+"*~*"+NORM+environment()->query_name()+" impales "+ATT->query_name()+" through "+ATT->query_possessive()+" throat!\n");
attacker->hit_player(1+random(2));

       }
 
       if(c==0){
write(RED+"*~*"+NORM+BYEL+"TTTTHHHHHHUUUUUUUUCCCCCCCCKKKKKKKKKK\n"+NORM);
say(RED+"*~*"+NORM+BYEL+"TTTTHHHHHHUUUUUUUUCCCCCCCCKKKKKKKKKK\n"+NORM);
attacker->hit_player(2+random(2), "other|electricity");
       }

       if(d==0){
write(RED+"*~*"+NORM+"You descend upon "+ATT->query_name()+" like an Angel of DEATH!\n"+
  ""+ATT->query_name()+" quivers in fear and horror.\n");
say(RED+"*~*"+NORM+environment()->query_name()+" descends upon "+ATT->query_name()+" like an Angel of DEATH!\n"+
  ""+ATT->query_name()+" quivers in fear and horror.\n");
attacker->hit_player(2+random(2), "other|angel");
       }

       if(e==0){
write(RED+"*~*"+NORM+"You hold your "+BOLD+"naginata"+NORM+" poised above your head.\n");
say(RED+"*~*"+NORM+environment()->query_name()+" holds "+environment()->query_possessive()+BOLD+" naginata"+NORM+" poised above "+ATT->query_name()+"'s head.\n");
attacker->hit_player(2+random(3), "other|fire");
       }

       if(f==0){
write(RED+"*~*"+NORM+"You jump high in the air!\n");
say(RED+"*~*"+NORM+environment()->query_name()+" jumps high in the air!\n");
attacker->hit_player(2+random(3), "other|wind");
       }   

       if(g==0){
write(RED+"*~*"+NORM+"You gracefully whirl in close to "+ATT->query_name()+".\n");
say(RED+"*~*"+NORM+environment()->query_name()+" gracefully whirl in closes to "+ATT->query_name()+".\n");
attacker->hit_player(1+random(2));
       }

       if(h==0){
write(RED+"*~*"+NORM+"You lift your "+BOLD+"naginata"+NORM+" staff blurring toward "+ATT->query_name()+"'s face!\n");
say(RED+"*~*"+NORM+environment()->query_name()+" lifts the "+BOLD+"naginata"+NORM+" staff blurring toward "+ATT->query_name()+"'s face!\n");
attacker->hit_player(1+random(2));
       }

       if(i==0){
write(RED+"*~*"+NORM+"You descend upon "+ATT->query_name()+" like an Angel of DEATH!\n"+
  ""+ATT->query_name()+" quivers in fear and horror.\n");
say(RED+"*~*"+NORM+environment()->query_name()+" descends upon "+ATT->query_name()+" like an Angel of DEATH!\n"+
  ""+ATT->query_name()+" quivers in fear and horror.\n");
attacker->hit_player(1+random(2));
       }

       if(j==0){
write(RED+"*~*"+NORM+"Blood spatters everywhere!\n"+
  ""+ATT->query_name()+" gurgles in helpless pain.\n");
say(RED+"*~*"+NORM+"Blood spatters everywhere!\n"+
  ""+ATT->query_name()+" gurgles in helpless pain.\n");
attacker->hit_player(1+random(2));
       }

       if(k==0){
write(RED+"*~*"+NORM+"A "+BOLD+BLINK+"VORTEX"+NORM+" of death energy enshrouds you!\n"+
   "You writhe in ecstasy!\n"+ATT->query_name()+" is lifted, screaming, from the ground!\n");
say(RED+"*~*"+NORM+"A "+BOLD+BLINK+"VORTEX"+NORM+" of death energy enshrouds "+environment()->query_name()+"!\n"+
   environment()->query_name()+" writhes in ecstasy!\n"+ATT->query_name()+" is lifted, screaming, from the ground!\n");
attacker->hit_player(2+random(3), "other|void");
       }

       if(l==0){
write(RED+"*~*"+NORM+"The "+BOLD+"lightning"+NORM+" releases all of its energy into "+ATT->query_name()+"!\n"+
   ""+ATT->query_name()+" groans pitifully and falls into a smoking heap on the floor.\n");
say(RED+"*~*"+NORM+"The "+BOLD+"lightning"+NORM+" releases all of its energy into "+ATT->query_name()+"!\n"+
   ""+ATT->query_name()+" groans pitifully and falls into a smoking heap on the floor.\n");
attacker->hit_player(4+random(2), "other|electricity");
       }

       if(a==2){
write(RED+"*~*"+NORM+"Your "+BOLD+"naginata"+NORM+" blade burns with a "+BRED+"molten"+NORM+" fury!\n"+
      RED+"*~*"+NORM+"You charge toward your reeling foe!\n"+
      RED+"*~*"+NORM+"You plunge your "+BOLD+"white-hot naginata"+NORM+" into Missionary.\n"+
      "Missionary screams in burned agony!\n");
say(RED+"*~*"+NORM+environment()->query_name()+"'s "+BOLD+"naginata"+NORM+" blade burns with a "+BRED+"molten"+NORM+" fury!\n"+
      RED+"*~*"+NORM+environment()->query_name()+" charges toward the reeling foe!\n"+
      RED+"*~*"+NORM+environment()->query_name()+" plunges the "+BOLD+" white-hot-naginata"+NORM+" into "+ATT->query_name()+".\n"+
      ""+ATT->query_name()+" screams in burned agony!\n");
attacker->hit_player(4+random(2), "other|fire");
       }  

       if(a==1){
write(RED+"Fire"+NORM+" races along the blade of your "+BOLD+"naginata"+NORM+"!\n");
say(RED+"Fire"+NORM+" races along the blade of "+environment()->query_name()+"'s "+BOLD+"naginata"+NORM+"!\n");
attacker->hit_player(3+random(3), "other|fire");
       }

       if(a==0){
write(BOLD+"Lightning"+NORM+" blasts off the searing outline of your "+BOLD+"naginata"+NORM+"!\n");
say(BOLD+"Lightning"+NORM+" blasts off the searing outline of "+environment()->query_possessive()+" "+BOLD+"naginata"+NORM+"!\n");
attacker->hit_player(3+random(2), "other|electricity");
       }}
