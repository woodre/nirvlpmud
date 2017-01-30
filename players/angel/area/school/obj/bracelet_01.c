#include <ansi.h>
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("dora bracelet");
  set_alias("bracelet");
  set_short(HIB+"Dora Bracelet"+NORM);
  set_long("\
This bracelet is blue and yellow. It came with a Dora\n\
doll, child size.\n"
  );
  set_ac(1);
  set_type("bracelet");
  set_weight(1);
  set_value(300);
}