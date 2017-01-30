/* Staff of Niftyness by Feldegast/Chris                        */
/* Made with the help of numerous and sundry sources.             */

#include "/players/feldegast/defines.h"
inherit "/obj/weapon";

object target;

short() {
  if(this_player() && this_player()->query_real_name()!="feldegast")
    tell_object(find_player("feldegast"),capitalize(this_player()->query_real_name())+" looked at you.\n");
  return ::short();
}
reset(arg) {
  if(arg) return;
  set_name("staff");
  set_alias("feldstaff");
  set_short("Staff of Niftyness");
  set_long(
"This is a two meter long staff made out of black oak with a\n"+
"crystal prism at the top.  Type 'staff_help' for more info.\n"
  );
  set_weight(0);
  set_class(1);
  set_hit_func(this_object());
  set_value(80000);
}
init() {
  ::init();
  if(environment())
  if(environment()->query_real_name()!="feldegast") {
    destruct(this_object());
  }
  add_action("logger","Wlog");
  add_action("exec","exec");
  add_action("detain","detain");
  add_action("fdest","fdest");
  add_action("ftell","tell");
  add_action("fclone","fclone");
  add_action("quick","quick");
  add_action("hist","hist");
  add_action("gossip","cg");
  add_action("spy","spy");
  add_action("gossip","cgossip");
  add_action("wizzes","wizzes");
  add_action("familiar","familiar");
  add_action("fnote","fnote");
  add_action("notes","fnotes");
  add_action("fin","fin");
  add_action("do_clean","clean");
}
logger(str) {
  return "/players/feldegast/closed/tool/logger"->logger(str);
}
exec(str) {
  return "/players/feldegast/closed/tool/exec"->exec(str);
}
ftell(str) {
  return "/players/feldegast/closed/tool/tell.c"->ftell(str);
}
quick(str) {
  return "/players/feldegast/closed/tool/quick"->quick(str);
}
familiar() {
  move_object(clone_object("/players/feldegast/closed/tool/familiar"),this_player());
  write("You summon a familiar to serve you.\n");
  return 1;
}
fnote(str) {
  return "/players/feldegast/closed/tool/fnote"->fnote(str);
}
fin(str) {
  return "/players/feldegast/closed/tool/mfinger"->ffinger(str);
}
do_clean() {
  return "/players/feldegast/closed/tool/clean"->do_clean();
}
wizzes() {
  "/players/feldegast/closed/tool/wizzes"->wizzes();
  return 1;
}
notes(str) {
  return "/players/feldegast/closed/tool/fnote"->notes(str);
}
gossip(str) {
  "/players/feldegast/closed/tool/gossip"->cgossip(str);
  return 1;
}
spy(str) {
  return "/players/feldegast/closed/tool/spy"->spy(str);
}
hist(str) {
  "/players/feldegast/closed/tool/hist.c"->history(str);
  return 1;
}
