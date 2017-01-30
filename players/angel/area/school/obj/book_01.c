#include <ansi.h>
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("the dark tower VII");
  set_alias("book");
  set_short("The Dark Tower VII");
  set_long("\
The Dark Tower VII, a book about gunslingers who come\n\
out shooting and face a host of enemies\n"
  );
  set_ac(1);
  set_type("misc");  
  set_weight(1);
  set_value(300);
}