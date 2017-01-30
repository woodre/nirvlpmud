#include "/players/jareel/ansi.h"
#define USER environment(shadwep) 

  object shadwep;
  
  int no_wear_out;
  
  int enchant_total;

  add_shadow(object ob){
    shadwep = ob; 
    shadow(shadwep, 1); 
}

  remove_shadow(){ 
    shadow(shadwep, 0); 
    destruct(this_object()); 
  return 1; 
}

short(){ return shadwep->short()+" "+BOLD+"( "+BLU+"Lightning charged"+NORM+BOLD+" ) "+NORM; }

hit(attacker){
  int dam_tot;
  dam_tot = 0;
   
  dam_tot += shadwep->hit(attacker);
   
  if(enchant_total >= 500){
    tell_object(USER, "Your "+HIY+"matrix"+BLK+" fades"+NORM+".\n");
  remove_shadow();
  }
  if(random(5)){
    tell_room(environment(USER),
    USER->query_name()+" unleashes lightning\n\n"+BOLD+BLINK+" L I G H T N I N G"+NORM+" charges the room."+NORM+"\n");
      dam_tot += (2+random(4), "other|electricity");
  }
  enchant_total +=random(2);
  return dam_tot;
}

query_shadowed() { return 1; }