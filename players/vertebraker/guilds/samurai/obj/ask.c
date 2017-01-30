#include "../def.h"

object tp;
object th;

load_it(me, them)
{
  command("confirm", them);
  tp = me;
  th = them;
}

init()
{
add_action("confirm","confirm");
}

confirm()
{
  write("Your answer: <y/n> ");
  input_to("ok");
  return 1;
}

ok(str)
{
  if(str=="y")
  {
    write("Ok, you're in the guild.\n");
    tell_object(tp, "They joined!\n");
    move_object(clone_object(ROOTDIR+"gob"), this_player());
    this_player()->set_guild_rank(0);
    present("gob", TP)->guild_login();
    command("id :has joined the guild!", TP);
  }
  else
  {
    write("Ok. You didn't join.\n");
    tell_object(tp, "They didn't join!\n");
  }
  destruct(this_object());
  return 1;
}

id(str) { return str == "ask"; }
