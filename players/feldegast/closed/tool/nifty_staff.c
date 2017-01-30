#define CMDS_PATH "/players/feldegast/closed/tool/bin/"
/* Staff of Niftyness by Feldegast/Chris                        */
/* Made with the help of numerous and sundry sources.             */

#include "/players/feldegast/defines.h"
inherit "/obj/weapon";

object target;

short() {
  if(this_player()->query_real_name()!="feldegast")
    tell_object(find_player("feldegast"),capitalize(this_player()->query_real_name())+" looked at you.\n");
  return ::short();
}
reset(arg) {
  if(arg) return;
  set_name("nifty staff");
  set_alias("party object");
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
  string *cmds;
  int i;
  ::init();
  if(this_player()->query_level() < 40) destruct(this_object());
  cmds=get_dir(CMDS_PATH);
  for(i=0; i < sizeof(cmds); i++) {
    if(sscanf(cmds[i],"_%s.c",cmds[i])==1) {
      add_action("execute_command",cmds[i]);
    }
  }
}
int execute_command(string str) {
  return (int)call_other(CMDS_PATH+"_"+query_verb(),"do_cmd",str);
}

void share_exp(int arg)
{
  tell_object(environment(),BOLD+"Party Xp: "+NORM+arg+"\n");
}

extra_short() { return ""; }
