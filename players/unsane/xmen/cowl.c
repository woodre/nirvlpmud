#include <ansi.h>
inherit "obj/armor";
reset(arg){
   if(arg) return;
   set_ac(0);
   set_value(1000);
   set_weight(1);
   set_name("cowl");
   set_short("A " + MAG + "Purple" + NORM + " Cowl");
   set_alias("purple cowl");
   set_long("This once belonged to Magneto, master of magnetism.  It is a purple mean\n"+
      "looking cowl.  It gives the wearer a devilish appearance.\n");
   set_type("helmet");
   set_params("other|mental", 1, 0, "mental_spec");
}

mental_spec(owner)
{
     if(!random(6))
       tell_object(owner, "The " + MAG + "Cowl" + NORM + " flaps around you.\n");
}
