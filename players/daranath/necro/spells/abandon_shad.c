#include <ansi.h>
int time;
object quick;
quickshad_on(){
shadow(quick,1);
}

quickshad_off(){
  shadow(quick,0);
  destruct(this_object());
  return 1;
}

query_rescued(){ return 1; }
short(){
  return quick->short()+" (depressed)";
}
attacked_by(ob){
  tell_room(environment(quick),get_msg());
  time--;
  quick->stop_fight();
  quick->stop_fight();
  if(time < 0){
    tell_room(environment(quick),HIR+quick->query_name()+" regains the will to fight!\n"+OFF);
    quickshad_off();
  }
}

attack_object(){
}

set_monster(mon,i){
  if(!mon) return 0;
  quick = mon;
  quickshad_on();
  time = i;
  return 1;
}

query_cursed(str){ 
  if(str == "abandoned") 
    return 1; 
  return 0;
}

do_damage(i){
  call_out("hurtme",0,i);
  quick->stop_fight();
  quick->stop_fight();
  return i;
}

hit_player(i){
  call_out("hurtme",0,i);
  quick->stop_fight();
  quick->stop_fight();
  return i;
}

hurtme(i){
  quick->heal_self(-i);
}

query_prevent_shadow(){ return 1; }

get_msg(){
object ob;
ob = quick;
  switch(random(7)){
   case 0:  return ob->query_name()+BOLD+BLK+" kneels to the ground as depression sets in.\n"+OFF;
   case 1:  return ob->query_name()+BOLD+BLK+" lowers "+ob->query_possessive()+" weapon.\n"+OFF;
   case 2:  return ob->query_name()+BOLD+BLK+" is over come by past memories of sadness.\n"+OFF;
   case 3:  return ob->query_name()+BOLD+BLK+" lowers "+ob->query_possessive()+" head, giving up the fight.\n"+OFF;
   case 4:  return ob->query_name()+BOLD+BLK+" looks very depressed.\n"+OFF;
   case 5:  return ob->query_name()+BOLD+BLK+" tries to attack you but fails as "+ob->query_pronoun()+" abandons all hope.\n"+OFF;
   case 6:  return BOLD+BLK+"Gloom hovers above "+OFF+ob->query_name()+BOLD+BLK+" as the will to fight leaves "+ob->query_possessive()+".\n"+OFF;
  }
}