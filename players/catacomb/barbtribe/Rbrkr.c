inherit "/obj/weapon";
#include "/obj/ansi.h"
#define tpn this_player()->query_name()
#define atn attacker->query_name()

reset (arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("axe");
  set_short(BOLD+RED+"Risk"+HIB+"Breaker"+NORM+", the war axe");
  set_long(
 "  Looking at the bloodstained blade of RiskBreaker, you are able to feel\n"+
 "the souls of all the victims of the barbarian's weapon.  Only a wielder \n"+
 "of great skill and strength could possibly use the weapon efficiently.\n" );
  set_type("axe");
  set_class(16);
  set_weight(4);
  set_value(1000);
  set_hit_func(this_object()); }
  mixed
  weapon_hit(object attacker) {
  string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if((random(20)>10) && (this_player()->query_attrib("str") > 17))
    {
     write("You swing RiskBreaker in a wide arc above your head, bringing it down with\n");
     write(BOLD+BLU+"       Concussive\n"+NORM);
     write("force leaving "+atn+" in a "+HIC+"D"+HIB+"a"+HIC+"Z"+HIB+"e"+NORM+"\n");
     say(name+" swings RiskBreaker in a wide arc "+BOLD+HIC+"STUNNING\n"+
	atn+NORM+"\n");
     return 1; 
     }
     if ((random(100) < 10)&&(this_player()->query_attrib("str")>18))
     {
	write("You take a step back charging up your energy...then\n");
	write("release a fury of\n");
	write(RED+"      RRRRRRR     AA     GGGGGGG     EEEEEEE"+NORM+"\n");
      write(RED+"      RR   RR    AAAA    GG          EE     "+NORM+"\n");
      write(RED+"      RRRRRRR   AA  AA   GG          EEEEE  "+NORM+"\n");
      write(RED+"      RRRRR    AAAAAAAA  GG GGGG     EEEEE  "+NORM+"\n");
      write(RED+"      RR RRR  AA      AA GG   GG     EE     "+NORM+"\n");
      write(RED+"      RR  RRR AA      AA GGGGGGG     EEEEEEE"+NORM+"\n");
      say(name+" steps back and takes a sweeping strike at "+atn+"\n");
      say("leaving them a "+BOLD+HIR+"BlOoDy"+NORM+" mess.\n");
      return 2;
     } 
}

  
