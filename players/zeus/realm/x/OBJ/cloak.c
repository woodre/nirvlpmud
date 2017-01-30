#include <ansi.h>
inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("cloak");
   set_short(BOLD+BLK+"A billowing cloak of shadows"+NORM);
   set_type("misc");
   set_ac(1+random(2));
   set_weight(1+random(2));
   set_value(random(5000));
}

long(){
  if(ac == 1)
  {
    write(
      "This is a cloak made from shadows.  It is incredibly light, and\n"+
      "somewhat transparent.  As the wind touches it, the cloak almost\n"+
      "seems alive.  It is a very beautiful cloak.\n");
  }
  else if(ac == 2)
  {
    write(
      "This is a cloak made from shadows.  It is incredibly light, and\n"+
      "somewhat transparent.  As the wind touches it, the cloak almost\n"+
      "seems alive.  It is a very beautiful cloak, and also provides\n"+
      "excellent protection from attacks.\n");
  }
}

query_save_flag(){    return 1; }

