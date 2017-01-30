inherit "/obj/weapon.c";
#include <ansi.h>
#define TP this_player()
#define TPN this_player()->query_name()

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("hexfire");
  set_alias("sword");
  set_short(BOLD+YEL+"Hex"+RED+"fire"+NORM);
  set_long(HIY+
 " A well honed, razor-sharp sword.  Along its slender blade a\n"+
 "carving of a heron is seen.  The heron marked blade is the mark\n"+
 "of a blademaster to the Durkors.  The handle is made of ivory, \n"+
 "carved to resemble a dragon's head.  Embedded in the eyes of the\n"+
 "dragon are a fire ruby and a jet black onyx.\n"+NORM);
  set_type("sword");
  set_class(18);
  set_weight(2);
  set_value(6000);
  set_hit_func(this_object()); }
  mixed
  weapon_hit(object attacker) 
  {
  string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if((random(50) > 45) && (TP->query_attrib("mag") >= 30)) 
    {
     write(HIB+"\nAs you attack "+attacker->query_name()+BOLD+YEL+" Hex"+RED+"fire"+NORM+HIB+" spits out\n");
     write(HIB+"an engulfing flame, burning through "+attacker->query_name()+"\n"+NORM);
     say("\n"+BOLD+YEL+"Hex"+RED+"fire"+NORM+HIB+" engulfs "+attacker->query_name()+" in flames.\n"+NORM);
     this_player()->hit_player(random (15), "other|fire");
     this_player()->add_spell_point(-(random(10)+5));
     return 1;
    } 
    if (random(30) > 15)
    {
     write(BOLD+RED+"\nYou send the sword into a seductive dance of death leaving thin\n");
     write(  "          lines of blood covering "+attacker->query_name()+".\n"+NORM);
     say(name+" sends "+BOLD+YEL+"Hex"+RED+"fire"+NORM+" into a vicious onslaught.\n");
     return 1;
    }
  }
