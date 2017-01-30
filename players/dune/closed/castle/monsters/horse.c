inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("stallion");
   set_short( "A wild stallion");
   set_alias("stallion");
   set_level(6);
   set_race("horse");
   set_hp(90);
   set_wc(10);
   set_ac(3);
   set_long(
"     The wild stallion has a beautiful black coat of skin and a long\n"+
"black mane. It runs free and untamed. You have a feeling that it would\n"+
"like to stay that way.\n");
}
