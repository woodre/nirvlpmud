#include "/players/dusan/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("hammer");
set_alias("warhammer");
set_short(""+HIR+"War"+NORM+""+BOLD+""+BLK+"hammer"+NORM+"");
set_long(
  "This is a large, unidentifiable, gray, metal rectangle with a strange lacquered\n"+
  "thigh bone that is thrust through it and used as a handle. \n");

set_type("hammer"); 
set_class(18);
set_weight(3);
set_value(2000);
set_hit_func(this_object());
}
 
weapon_hit(attacker){
int W, strength, race;
object user;
user = environment(this_object())->query_name();
W = (environment()->query_attrib("sta"));
strength =(environment()->query_attrib("str")/4);
if(attacker->query_race() == "skeleton" && random(6)<=1){ 
write(
  "The hammer enhances your strength and you...       \n"+
  "                                                    \n"+           
  "                      "+BOLD+""+HIR+"((<<** CRUSH **>>))"+NORM+"   \n"+        
  "                                                      \n"+    
  "                              your enemy with a downward blow . \n"+
  "You hammer into the skeleton sending chuncks of bone flying.\n");
return strength*2; }
if(W>random(60))  {
 
  say(
  ""+user+" roars then...                                   \n"+
  "                  "+BOLD+""+HIR+"((<<** CRUSHES **>>))"+NORM+"\n"+
  "                                 his enemy with a powerful blow.\n");

  write(
  "The hammer enhances your strength and you...       \n"+
  "                                                    \n"+           
  "                      "+BOLD+""+HIR+"((<<** CRUSH **>>))"+NORM+"   \n"+        
  "                                                      \n"+    
  "                              your enemy with a downward blow . \n");
  return strength; 
  
  }
return;
}
