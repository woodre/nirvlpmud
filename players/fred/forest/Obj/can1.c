#include "/players/fred/ansi.h"
inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("can");
  set_alias("cheese");
  set_short("A can of"+HIY+" Easy Cheese"+NORM);
  set_long(
 "  A small can of Easy Cheese(American). There\n"+
 "is something written on the side of the can.\n" );
  set_class(14);
  set_weight(1);
  set_value(500);
  set_hit_func(this_object()); }
  mixed
  weapon_hit(object attacker) {
  string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if(random (50) < 3) {
     write(HIY+"\nCHEESE"+NORM+" flies from the can blinding "+BOLD+attacker->query_name()+NORM+".\n\n");
     say(name+" sprays"+HIY+" CHEESE "+NORM+"in "+HIC+attacker->query_name()+NORM+" eyes.\n");
 return 1; } }

init(){
 ::init();
   add_action("sprayem", "spray");
   add_action("readem", "read");
   }

sprayem(str){
  int stuffed, soaked;
  if(!str) { write("Spray what?\n"); return 1; }
  if(str == "can"){
   if(!this_player()->eat_food(18))
   {
     write("You feel too sick to eat any more...\n");
     return 1;
   }
   this_player()->heal_self(50);
   write("You lift the can up to your mouth and"+BOLD+" SPRAY"+NORM+" the entire can of cheese into your mouth.\n\n");
   write(BOLD+"<<< "+RED+"HP:"+NORM+BOLD+this_player()->query_hp()+NORM+BOLD+"/"+NORM+BOLD+this_player()->query_mhp()+NORM);
   write(BOLD+RED+" SP:"+NORM+BOLD+this_player()->query_sp()+NORM+BOLD+"/"+NORM+BOLD+this_player()->query_msp());  
   write(RED+"   I "+NORM+BOLD+((this_player()->query_intoxication()*100)/(this_player()->query_level()+3))+BOLD+HIB+"%"+NORM);
   write(BOLD+RED+"  F "+NORM+BOLD+((this_player()->query_stuffed()*100)/(this_player()->query_level()*8))+BOLD+HIB+"%"+NORM);
   write(BOLD+RED+"  S "+NORM+BOLD+((this_player()->query_soaked()*100)/(this_player()->query_level()*8))+BOLD+HIB+"%"+NORM);
   write(BOLD+" >>>"+NORM+"\n");
   destruct(this_object());
   return 1; }
  }

readem(str){
  if(!str) { write("Read what?\n"); return 1; }
  if(str == "can"){
   write("You can also use this as a heal just 'spray can'!\n");
   return 1; }
  }

   


  
