#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("slouchy");
   set_alt_name("smurf");
   set_short(""+CYN+"Slouchy Smurf"+NORM+"");
   set_race("smurf");
   set_long(
      "Slouchy isn't lazy, he just doesn't really want to do much of\n"+
      "anything.  If you ask him to do something, he will, but very,\n"+
      "very slowly.  You don't see him having a nervious breakdown\n"+
      "anytime in the near future.  He absolutely idolizes Lazy Smurf.\n");
   set_level(1);
   set_ac(2);
   set_wc(2);
   set_hp(40);
   set_al(5);
}
