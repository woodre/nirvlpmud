#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("snappy");
   set_alt_name("smurf");
   set_short(""+CYN+"Snappy Smurf"+NORM+"");
   set_race("smurf");
   set_long(
      "Snappy is a living ball of energy.  He never seems to stop\n"+
      "for anything or anyone.  If you ask him to do something he\n"+
      "will jump right to it and get going.  Be careful or he may\n"+
      "wear you out.\n");
   set_level(3);
   set_hp(100);
   set_wc(4);
   set_ac(4);
   set_al(25);
}
