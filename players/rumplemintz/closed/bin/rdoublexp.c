#include <ansi.h>

rdoublexp(str) {
  object *us;
  object ob;
  int s;

  if(!str) {
  s = sizeof(us = users());

  while(s--) {
    if (us[s] && (int)us[s]->query_level() < 20) {
      if (!present("double_xp_object", us[s])) {
        ob = move_object(clone_object("/obj/secure/double_obj.c"), us[s]);
        tell_object(us[s],
          "\n"+this_player()->query_name()+" casts "+HIR+"Double Experience"+NORM+" on you!!\n\n");
      }
    }
  }
  write("Ok.\n");
  return 1;
  }
}
