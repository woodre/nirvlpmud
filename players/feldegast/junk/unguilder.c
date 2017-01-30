#include "/players/feldegast/defines.h"

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("wand");
  set_alias("unguilder");
  set_short("Unguilding wand");
  set_long(
"A long spiraling wand of oaken wood.  A wizard can use it\n"+
"to <unguild> players who have lost their guild objects.\n");
  set_weight(0);
  set_value(0);
}
init() {
  if(TP->query_level() > 20)
    add_action("unguild","unguild");
}
unguild(str) {
  object target;
  int glev;
  int gxp;
  target=find_player(str);
  if(!str) {
    notify_fail("Usage: unguild <player>\n");
    return 0;
  }
  if(!target) {
    write("Usage: unguild <player>\n");
    return 1;
  }
  target->set_home(0);
  target->set_guild_name(0);
  gxp=target->query_guild_exp();
  glev=target->query_guild_rank();
  target->add_guild_rank(-glev);
  target->add_guild_exp(-gxp);
  target->add_exp(gxp/2);
  write("You have unguilded "+target->query_name()+".\n");
  command("save",target);
  return 1;
}
