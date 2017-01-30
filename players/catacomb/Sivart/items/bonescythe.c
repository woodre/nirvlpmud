inherit "/obj/weapon.c";
#include <ansi.h>
#define TP this_player()
#define TPN this_player()->query_name()

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("bonescythe");
  set_alias("dagger");
  set_short(HIW+"Bone"+HIR+"Scythe"+NORM);
  set_long(BOLD+RED+
 " The dreaded blade of Rhuerj of the house Werjor.  The rust-colored\n"+
 "blade waves back and forth with two razor sharp edges.  The base of \n"+
 "the dagger forms into a D.  Sharp spikes protrude from the hand guard\n"+
 "of the handle.\n"+NORM);
  set_type("dagger");
  set_class(18);
  set_weight(1);
  set_value(5000);
  set_hit_func(this_object()); }
  mixed
  weapon_hit(object attacker) {
  string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if((random(100) > 90) && (TP->query_attrib("dex") >= 25)) 
    {
     write("\n                You deftly "+RED+"SLAM"+NORM+" the spikes into\n");
     write("        your enemy leaving a giant gash on "+attacker->query_name()+"'s face.\n");
     say("\n    "+TPN+" SLAMS the Bonescythe into "+attacker->query_name()+"'s face\n");
     return 3;
    }
    if ((random(50) > 45) && (TP->query_attrib("ste") > 28) && (TP->query_attrib("dex") >= 28))
    {
     write("\n      You dodge from an attack and slip behind "+attacker->query_name()+"\n");
     write(" You grin in sadistic glee as the blade slides through flesh.\n");
     say("    "+TPN+" slips behind "+attacker->query_name()+" and grins as flesh is cut.\n");
     return 4;
    }
  }

  
