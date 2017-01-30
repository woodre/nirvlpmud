#include <ansi.h>
inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("platemail");
   set_short("Platemail of the "+HIB+"E"+NORM+"lemental "+HIB+"F"+NORM+"ury");
   set_alias("plate");
   set_long("Forged long ago within the elemental fires that also gave form\n"+
            "to the Battle Charger, the armor is made from a burnished steel.\n"+
            "An electrical charge runs along the length of the armor,\n"+
            "increasing the protection that it gives.\n");
   set_type("armor");
   set_ac(4);
   set_weight(3);
   set_value(8750);
   set_params("other|electricity",4,0,"elec_special");
   set_params("other|wind",       4,0,"wind_special");
}

query_save_flag() { return 1;}

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
