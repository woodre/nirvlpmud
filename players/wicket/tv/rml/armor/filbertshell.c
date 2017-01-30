inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shell");
   set_alias("filbert shell");
   set_short(HIK+"Fil"+HIC+"b"+HIK+"ert"+NORM+"'\ "+HIC+"s"+HIK+" She"+HIC+"l"+HIK+"l"+NORM+"");
   set_long(
      "a very durable turleshell that use to be part of Filbert's Body.\n"
   );
   set_ac(3);
   set_type("armor");
   set_weight(1);
   set_value(1500);
  }