#include <ansi.h>
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("swivel bracelet");
  set_alias("bracelet");
  set_short("Swivel Bracelet");
  set_long("\
This bracelet is made of brass swivels that came out of a\n\
tackle box. It reminds you how Jesus said we are all fishers\n\
of men.\n"
  );
  set_ac(1);
  set_type("bracelet");
  set_weight(1);
  set_value(200);
}