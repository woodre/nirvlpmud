#include <ansi.h>
inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("crusader platemail");
   set_short(WHT+"Crusader Platemail"+NORM);
   set_alias("platemail");
   set_long("Fully armored and well protected when wearing this armor, the knights of\n"+
            "of Qual'tor wore this armor shoulder to shoulder in defense of\n"+
            "the city. Not many suits are left now, mostly useless relics\n"+
            "of a time long past.\n");
   set_type("armor");
   set_ac(4);
   set_weight(2);
   set_value(3775);
}
