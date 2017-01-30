inherit "obj/armor" ;
#include "/players/pain/color.h"
#define wgl worn_by->query_guild_name()

reset(arg)
{
  ::reset(arg) ;
set_short("The Helm of the CyberTech God <Gritty>");
set_long("A almost clear helmet made of some strong unknown material.\n");
     set_ac(2);
     set_weight(3);
	set_value(100000000000);
	set_alias("helm");
	set_name("helm");
	set_type("helmet");
  }

init() {
add_action("check_wear", "wear");
add_action("afjsgk", "afjsgk");
}

check_wear(str) {
if(str == "helm") {
   ::wear("helm");
   call_out("afjsgk",10);
   return 1;
}
::wear(str);
return 1;
}
afjsgk() {
if(worn) {
   if(wgl == "cyberninja") {
      if(random(3) == 2) { 
         write(PURPLE+"Your mind gets clouded by the Helm.\n"+END);
         write("Cyber Tech God says: submit to me now!\n");
         write("A pain enters your temples.\n");
         worn_by->heal_self(-10);
         call_out("afjsgk", 20+random(20));
         return 1;
      }
      write(LIGHT_BLUE+"The Helm glows bright blue.\n"+END);
      write("You feel a healing sensation wash over you.\n");
      worn_by->heal_self(3+random(7));
      call_out("afjsgk", 20+random(20));
      return 1;
   }
return 1;
}
}
