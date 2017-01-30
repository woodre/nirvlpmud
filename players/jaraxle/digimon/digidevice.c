#include "/players/jaraxle/define.h"
inherit "/obj/armor";

reset(arg)  {
   ::reset(arg) ;
   
   set_short("A DigiDevice");
   set_long("A small hand held computer with a small screen on the front.\n"+
      "With one of these you can DigiVolve a DigiMon!\n"+
      "You can wear it around your wrist like a watch.\n");
   set_weight(1);
   set_ac(1);
   set_alias("device");
   set_type("misc");
   set_value(100+random(50));
}
id(str){ return str == "digi_volver" || str == "digivolver" || str == "digivice" || str == "digidevice" || str == "digi device" || str == "device"; }

