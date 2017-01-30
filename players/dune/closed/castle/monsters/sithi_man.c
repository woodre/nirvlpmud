inherit "obj/monster";
#include "definitions.h"


id(str)
{
  return str == "sithi" || str == "Sithi";
}


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("sithi");
   set_race("sithi");
   set_alias("sithi");
   set_short("A Sithi");
   set_long(
"     You look upon a beautiful elf-like being. The Sithi is mostly\n"+
"human, but has the smooth features of a feline. The Sithi's hair is\n"+
"pure white.  Its skin is a golden tan.  However, its insane eyes clash\n"+
"against its otherwise peaceful look. This Sithi has gone mad.\n");
   set_level(7);
   set_hp(random(20)+105);
   set_al(-10);
   set_wc(12);
   set_ac(6);
   if(random(3) == 2) set_aggressive(1);
}
