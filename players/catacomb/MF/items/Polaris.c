inherit "/obj/weapon.c";
#include "/obj/ansi.h"
#define TPN this_player()->query_name();

reset(arg){
::reset(arg);
    if(arg) return;
set_id("polaris");
set_alias("mace");
set_type("mace");
set_wc(18);
set_short(WHT+"Polaris"+NORM);
set_long(
WHT+"  Polaris"+NORM+" is a short hand-crafted mace.  The mace was forged by\n"+
"Yeroc for his beloved Chelaris.  The two foot handle is beautifully \n"+
"crafted out of a fine dwarven mythril.  At the head of the mace a skull\n"+
"is placed.  The eye sockets of the skull glow a "+HIR+"crimson red"+NORM+".\n");
  set_weight(3);
  set_value(3000);

  set_hit_func(this_object());
}
mixed
weapon_hit(object attacker)
{
   string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;

    if(random (15) <= 3)
    {
     write("\nYou grasp Polaris with both hands\n");
     write(HIW+"       Holy Light"+NORM+"\n");
     write("   blasts through your foe.\n");
     say("Polaris sends a volley of holy light into "+this_player()->query_name()+"'s foe.\n");
     return 4;
    }
    else
    {
     return 0;
    }
}
