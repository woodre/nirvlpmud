#include <security.h>

status cmd_trans(string str) {
  object ob;
  int  level;
  string out,power;

  if (!str || (level=(int)this_player()->query_level()) < CONTROL)
    return 0;
  if (level >= ITEM_OVER)
    if (sscanf(str,"! %s",power) == 1)
      str = power;
  if(!(ob=find_player(str)) && !(ob=find_living(str)))
  {
    write("No such living thing.\n");
    return 1;
  }
  write("Ok.\n");
  tell_object(ob, "You are magically transfered somewhere.\n");
  if(!(out=(string)ob->query_mmsgin()))
    out=(string)ob->query_name() + " arrives in a puff of smoke.\n";
  else
    out = (string)ob->query_name() + " " + out + ".\n";
  tell_room(environment(this_player()), out);
  if(power)
    move_object(ob, this_player());
  else
    move_object(ob, environment(this_player()));
  return 1;
}
