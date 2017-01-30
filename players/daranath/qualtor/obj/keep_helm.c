#include <ansi.h>
inherit "obj/armor";

reset(arg){
  if(arg) return;
  ::reset(arg);
                  
  set_name("elemental helm");
  set_short("Helm of the "+CYN+"E"+NORM+"lemental "+CYN+"F"+NORM+"ury");
  set_alias("helm");
  set_long("A burnished steel helm, the helm was forged in the same elemental fires\n"+
           "that also gave form to the Battle Charger. Rumors persist\n"+
           "that wearing the helm will drive its possessor insane.\n");
  set_type("helmet");
  set_ac(1);
  set_weight(1);
  set_value(2250);
  set_params("other|electricity",2,0,"elec_special");
  set_params("other|wind",       2,0,"wind_special");
}

int elec_special(object ob)
{
  if(!random(4))
    tell_object(ob, BOLD + "Your platemail absorbs some of the electrical damage.\n" +NORM);
}

int wind_special(object ob)
{
  if(!random(4))
    tell_object(ob, BOLD + "Your platemail absorbs some of the wind damage.\n" + NORM);
}
