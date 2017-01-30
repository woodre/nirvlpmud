#include "../defs.h"

init_arg(ackughbleh)
{
 object x,y;
 int    comp;
 if((x = this_player()))
 {
  tell_object(x,"NEWMARK cloned to you\n");
  y = clone_object(GUILDOBJ);
  move_object(y,x);
  y->init_arg();
  if ((int)x->query_level() < 20)
  {
    x->set_home(LOGIN);
    x->set_guild_name("shardak");
  }
  command("save", x);
  cat(NEWS);
  destruct(this_object());
 }
}

drop()
{
 return 1;
}

reset(status arg) {
  return;
}
