#include <ansi.h>

int cmd_set_status(string str) {
  call_other("/bin/play/_wizes.c","set_wiz_status",this_player()->query_real_name(),str);
  write("Your status is now: "+(!str?"Available":str)+"\n");
  return 1;
}
