#include <ansi.h>
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("gym shorts");
  set_alias("shorts");
  set_short("A pair of plain cotten shorts");
  set_long("\
A pair of plain cotton shorts. They are grey and go to the knees.\n"
  );
  set_ac(1);
  set_type("pants");  
  set_weight(1);
  set_value(300);
}