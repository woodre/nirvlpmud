#include "/players/llew/closed/ansi.h"

inherit "obj/weapon";

reset(arg) {
   set_id("staff");
   set_class(18);
   set_light(2);
   set_hit_func(this_object());
   align();
}

init() {
   ::init();
   add_action("wepclass"); add_verb("wepclass");
   add_action("cmd_hook"); add_xverb("");
   add_action("lt","lt");
   add_action("lt","lte");
   if(this_player()->query_real_name() != "llew") destruct();
}

wepclass(int num) {
   set_class(num);
   write(GRN+"Staff: "+NORM+" Weapon class set to "+num+".\n");
   return 1;
}

cmd_hook(str) {
  string cmd, args, file;
  if(this_player()->query_real_name() != "llew" && this_player()->query_real_name() != "llewboto") return 0;
  if(!str) return 0;
  if(sscanf(str, "%s %s", cmd, args) != 2) cmd = str;
  file = "/players/llew/tool/"+cmd+".c";
  if(file_size(file) > 0)
    return call_other(file, cmd, args);
  return 0;
}

weapon_hit(attacker) {
   int hitp,hitmax,life;
   hitp=attacker->query_hp();
   hitmax=attacker->query_mhp();
   if(hitmax && hitp) {
      life=(100*hitp)/hitmax;
      write(GRN+"Staff: "+NORM+attacker->query_name()+" "+hitp+"/"+hitmax+" "+life+"%\n");
   }
}

short() {
   return "Oak Staff";
}

align() {
   "/players/llew/tool/align"->align();
   call_out("align",600);
}

lt(str) {
   "/players/llew/tool/lt"->lt(str);
   return 1;
}

drop() { return 1; }
