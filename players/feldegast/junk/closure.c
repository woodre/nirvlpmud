#include "/players/feldegast/closed/ansi.h"
#include "/players/feldegast/std/colorize.h"
inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("rod");
  set_alias("colors");
  set_short("Rod of Colors");
  set_long(
"This is a two foot long rod with a colorful inscription written on\n"+
"it.  You doubt it's very useful except for its colorfulness.\n"
  );
  set_value(0);
  set_weight(0);
  set_read(
"    "+RED+"RED"+NORM+HIR+"HIR"+"\n"+NORM+
"    "+GRN+"GRN"+NORM+HIG+"HIG"+"\n"+NORM+
"    "+YEL+"YEL"+NORM+HIY+"HIY"+"\n"+NORM+
"    "+BLU+"BLU"+NORM+HIB+"HIB"+"\n"+NORM+
"    "+MAG+"MAG"+NORM+HIM+"HIM"+"\n"+NORM+
"    "+CYN+"CYN"+NORM+HIC+"HIC"+"\n"+NORM+
"    "+WHT+"WHT"+NORM+HIW+"HIW"+"\n"+NORM
  );
}
init() {
  ::init();
  add_action("ctell","ctell");
  add_action("cmd_ruler","ruler");
}
cmd_ruler(str) {
  int tf;
  tf=closurep('#call_out);
  write("Answer: "+tf+"\n");
  return 1;
}
