inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "budd lynch" ||  str == "budd" || str == "lynch" || str == "Budd Lynch"; } 

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Budd Lynch");
   set_race("human");
   set_gender("male");
   set_al(250+random(100));
   set_level(9);
   set_hp(130);
   set_wc(13);
   set_ac(6);
   add_money(350+random(100));
   set_short(BOLD+WHT+"Budd Lynch"+NORM);
   set_long(
      "Budd Lynch is the public address announcer.  He is an elderly man with\n"+
      "gray hair on top of his balding head.  He is wearing a light brown suit.\n"+
      "Budd used to be the Wing's Radio broadcaster from 1949 to 1975.\n");
}
init() { 
    ::init(); 
add_action("block","announce");
 }
block() {
write("Budd Lynch says: Sorry, but I can't let you play with the microphone.\n");
return 1;}
