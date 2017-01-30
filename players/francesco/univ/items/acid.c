#include "/players/francesco/univ/ansi.h"

inherit "/obj/treasure";
object attacker;
reset(arg) {
   
set_id("acid");
set_alias("acid");
set_short("A glass vial filled with acid");
set_long(
   "This glass vial could be very dangerous and must be handled with care.\n"+
   "It is possible to 'throw' it either on someone or on something when the\n"+
   "situation requires it.  Always remember its power and the danger related\n"+
   "to its use.\n");

set_weight(1);
set_value(350);

}
init() {
  ::init();
  add_action("throw","throw");
}

throw() {
  string aname;

  if(environment(this_object()) != this_player()) 
  return 0;
  
  
  attacker=this_player()->query_attack();
  if(!attacker) {notify_fail("You cannot start a fight by throwing that acid!\n"); return 0;}
  aname = attacker->query_name();  
  if(!aname) aname = "Something";

  if(this_player()->query_sp() < 20) { write("You are out of spell points, please heal yourself.\n"); 
  return 1; }
  
  if(!attacker) { write("You aren't fighting anybody!\n"); 
  return 1; }

  if(attacker->is_player()){ write("This can't be used on players!\n"); 
  return 1; }

  write("You throw the acid on "+aname+" which screams in pain.\n");
  say(this_player()->query_name()+" throws the acid on "+aname+" \n");
  say(aname+" screams in pain.\n");
  
  attacker->heal_self(-random(40)-60); 

  this_player()->add_spell_point(-20);     
  destruct(this_object());     
       return 1;
}

