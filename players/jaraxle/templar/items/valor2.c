#include "/players/jaraxle/define.h"

#define USER environment()
int duration;
int blah;

reset(arg){
   if(arg) return;
   if(!root())
      set_heart_beat(1);
   duration = 60;
}
id(str){ return str == "valor_object"; }
heart_beat(){
   object my_att, enemy_att;
   blah = random(2);
   duration -= 1;
   if(environment()->query_ghost()){
      call_other(USER, "recalc_carry");
      destruct(this_object());
      return 1; }
   if(!duration){
      call_other(USER, "recalc_carry");
      tell_object(USER, GRN+"Your valor returns to normal.\n"+NORM);
      destruct(this_object());
      return 1; }
   /*
   if((blah) && (my_att=USER->query_attack()) && (enemy_att=my_att->query_attack()) && (enemy_att==USER) && (other_knights_atking(USER, enemy_att))) {
      */
      if((my_att=USER->query_attack()) && (enemy_att=my_att->query_attack()) && (enemy_att!=USER) && (other_knights_atking(USER, enemy_att))) {
         switch(random(3)){
            case 0:   tell_object(USER, "You feel "+RED+"strength"+NORM+" from your brother's "+HIC+"encouragement"+NORM+".\n");
            break;
            case 1:   tell_object(USER, HIC+"Valor"+NORM+" consumes your "+HIR+"heart"+NORM+", "+HIC+"encouraging"+NORM+" you to fight harder.\n");
            break;
            case 2:   tell_object(USER, "You feel "+HIC+"valor"+NORM+" from your fighting.\n");
            break; 
         }
         USER->add_hit_point(1+random(3));
      }
   }
   query_weight(){ return 0; }
   drop(){ return 0; }
   
   other_knights_atking(user, enemy)
   {
      object ob;
      object oc;
      if(!environment(user)) return 0;
      ob=first_inventory(environment(user));
      while(ob) {
         oc=next_inventory(ob);
         if((ob->query_attack()==enemy) && (present("KnightTemplar",ob)) && (enemy->query_attack()==user))
            return 1;
         else
            ob=oc;
         ob=oc;
         return 0;
         return 0;
}
}
