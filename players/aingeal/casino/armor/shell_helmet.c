/* Robin Williams's Tortoise Shell Helmet from 'Jumanji' */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit"obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("tortoise shell helmet");
  set_alias("helmet");
  set_short("Tortoise Shell Helmet");
  set_long("This rugged "+GRN+"tortoise shell helmet"+NORM+" was worn by Robin Williams in 'Jumanji'.\n");
  set_weight(2);
  set_value(1200);
  set_ac(2);
  set_type("helmet");
}
