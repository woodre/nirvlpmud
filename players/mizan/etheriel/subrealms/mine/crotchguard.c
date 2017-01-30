#include <ansi.h>
inherit "/obj/armor";

reset(arg)
{
   ::reset(arg);
   if(arg) return;
  
   set_id("Mithril Crotchguard");
   set_alias("crotchguard");
   set_weight(1);
   set_short(HIY + "Mithril" + NORM + " crotchguard");
  
   set_type("underwear");
   set_ac(1);
  
   set_long("This is a strange little device... it appears to be a combination jockstrap\n" +
            "and cup meant to protect the wearer's crotch... Not so strange? Well...\n" +
            "1) It is made of elven Mithril.\n"+
            "2) There is a phallic depiction of a giant ball of fire eminating from it.\n"+
            "3) It appears to smell of kerosene, or some sort of burning oil.\n"+
            "\nThis device looks as if it is meant to be worn.\n");

   set_params("other|fire", 1, 0, "do_extra_hit");
}

do_extra_hit(object wearer)
{
   if(1 == random(5))
   {
      if(wearer && wearer->query_attack())
      {
         tell_room(environment(wearer), "\n" + HIR + 
         "A giant ball of fire eminates from " + wearer->query_name() + "'s crotch towards " +
         (wearer->query_attack())->query_name() + "!\n" + NORM);
         (wearer->query_attack())->hit_player(5+random(5), "other|fire");
      }
   }
}
