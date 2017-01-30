#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object temp, guard;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(4)) return 0;
  temp = (object)PO->query_guard();
  if(!str)
  {
    if(temp)
      TOU"You are currently guarding "+temp->query_name()+".\n"+
      "Type 'guard stop' to stop guarding "+temp->query_name()+".\n");
    else
      TOU"You are not currently guarding anyone.\n");
  }
  else if(str == "end" || str == "stop")
  {
    if(temp)
    {
      TOU "You stop guarding "+temp->query_name()+".\n");
      PO->set_guard(0);
      /*
      PO->toggle_guarding();
      */
      if((guard = present("bf_guard_ob", temp)))
        guard->end();
      return 1;
    }
    else
      TOU "You are not currently guarding anyone.\n");
  }
  else if(temp)
    TOU "You are currently guarding "+temp->query_name()+".\n");
  else if(!(temp = present(str, environment(User))))
    TOU"What do you want to guard?\n");
  else if(!living(temp))
    TOU"You cannot guard "+temp->query_name()+".\n");
  else if(temp == User)
    TOU "You can't guard yourself!\n");
  else if(PO->query_guarding())
    TOU "You can't guard someone again yet.\n");
  else {
    if(PO->query_dur() >= PO->query_max_dur())
      return (notify_fail("You can not handle another duration ability.\n"),0);

    guard = clone_object("/players/fred/closed/bloodfist/obj/guard_obj.c");
    if(temp->is_player())
      TOU"You ask "+temp->query_name()+" if you can guard them.\n");
    else {
      TOU"You guard "+temp->query_name()+".\n");
      TRU Name+" begins to guard "+temp->query_name()+".\n", ({ User }));
    }
    move_object(guard, temp);
    guard->set_owner(User, PO);
    command("aethethoeahgpghaepgh", temp);
    PO->toggle_guarding();
    PO->add_dur();
  }
  return 1;
}

