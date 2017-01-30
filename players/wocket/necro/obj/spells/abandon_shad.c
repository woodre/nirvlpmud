#include "/players/wocket/closed/ansi.h"
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
  return quick->short()+" (cursed)";
}
attacked_by(ob){
  tell_room(environment(quick),quick->query_name()+" puts down "+quick->query_possessive()+" weapon and begins to cry.\n");
  quick->stop_fight();
  quick->stop_fight();
}

heart_beat(){
 tell_object(find_player("wocket"),"testing -hb shadow\n");
}

set_monster(mon){
  if(!mon) return 0;
  quick = mon;
  quickshad_on();
  return 1;
}

query_cursed(str){ 
  if(str == "abandoned") 
    return 1; 
  return 0;
}
