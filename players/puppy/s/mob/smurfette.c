#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("smurfette");
   set_short(""+HIB+"Smurfette"+NORM+"");
   set_alt_name("smurf");
   set_race("smurf");
   set_long(
      "The wicked Gargamel originally created Smurfette to stir up\n"+
      "trouble in the village. But Papa Smurf's magic turned her\n"+
      "into the Smurf that everyone knows and loves today.\n");
   set_level(6);
   set_hp(250);
   set_wc(6);
   set_ac(6);
   set_al(150);
   set_chat_chance(9);
   load_chat("Smurfette winks at you.\n");
   load_chat("Smurfette blows you a kiss.\n");
   
}
