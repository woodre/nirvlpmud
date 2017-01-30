#include <ansi.h>
#define tp this_player()
#define tpn tp->query_name()

inherit "obj/armor";
reset(arg){
   ::reset(arg);

  set_name("silver piercing");
  set_short("A silver tongue "+WHT+"piercing"+NORM);
  set_alias("piercing");
  set_long("A small bar that is meant to be worn through the tongue, this piercing\n"+
           "is both highly fashionable and exotic.\n");
  set_type("misc");
  set_ac(1);
  set_weight(1);
  set_value(350);
}

extra_look() {
if(worn)
write(tpn+" has a silver stud through thier toungue.\n"); 
}


