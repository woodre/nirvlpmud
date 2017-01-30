/* I'd like to thank Mythos for the code for this */
/* because it is basically like his green snake   */
/* so thanks again */
#include "/players/fred/ansi.h"
inherit "/obj/weapon.c";
object times, ferret;
int x, b;

reset (arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("remains");
  set_alias("remains of overlord");
  set_short("remains of Overlord");
  set_long(
    "    The bloody remains of the Ferret Overlord. This\n"+
    "corpse seems different somehow.  Like it has a different\n"+
    "purpose.\n");
  
     set_type("club");
     set_class(18);
     set_weight(3);
     set_value(5000);
     b = 0;
     set_hit_func(this_object());
    }
      
    weapon_hit(attacker) {
      if(this_player()->query_stuffed() + 10 > (int)this_player()->query_level() * 8){
         return 0; }
      if(this_player()->query_soaked() + 10 > (int)this_player()->query_level() * 8){
         return 0; } 
      if(this_player()->query_intoxication() + 10 > (int)this_player()->query_level() + 3){
         return 0; } 
      if(random(4) == 0) {
        if(0 == random(3)) {
         times = all_inventory(environment(this_player()));
         for(x=0; x <sizeof(times); x++){
         if(times[x]->id("ferret")) { b = b + 1; }
         }
 
       if(b < 5){
        write("A mini-ferret runs into the room yelling: I'm here to help you boss!\n");
        say("A mini-ferret scurries into the room!\n");
       if(attacker){   
       ferret = clone_object("/players/fred/forest/Mon/mferret.c");
       ferret->set_owner(this_player()); 
       move_object(ferret, environment(this_player()));
       ferret->attack_object(attacker); }
       this_player()->add_stuffed(10);
       this_player()->add_soaked(10); }
       b = 0; 
       return -3; }
      this_player()->add_intoxication(15);
      return 7; }
     return -4;
    } 
     
    
    

      
  

