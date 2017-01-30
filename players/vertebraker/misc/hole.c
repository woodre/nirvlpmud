#include "/players/vertebraker/closed/lib.h"
inherit "/obj/treasure";

void reset(status x) {
  if(!x && !root())
  {
    set_short("A portable hole");
    set_id("portable hole");
    set_alias("hole");
    set_long("\
A 9x9 animated oval completely devoid of any dimension within.\n\
Any item that comes into contact with the hole and enters it\n\
will automatically be deposited into a tiny, remote pocket\n\
dimension. There are absolutely no sounds or smells emanating\n\
from this blotch of darkness.\n");
    set_weight(0);
    set_value(0);
  }
}

int query_weight()
{
  return ((int)::query_weight()/8);
}

status can_put_and_get() { return 1; }

void init()
{
  object x, e;
  ::init();
  if(e=environment())
    if(living(e)) e->recalc_carry();
  if((x=this_player()) && (x!=e) &&
   environment(x) != this_object())
    add_action("cmd_enter", "enter");
  if(x && (environment(x) != this_object()))
  {
    add_action("cmd_hole", "hole");
    add_action("cmd_hitems", "hitems");
  }
}

status cmd_enter(string str) {
  if(!str)
  {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(!id(str) && (str !="the portable hole"))
  {
    notify_fail("You may only enter the portable hole.\n");
    return 0;
  }
  write("\n\tYou step into the portable hole.\n\t"+
        "You have entered a dimensional gateway.\n\n");
  say(tpn+" steps into the portable hole.\n");
  move_object(tp, to);
  return 1;
}

status exit(object ob) {
  object e;
  if((e=environment()) && (living(e)))
    e->recalc_carry();
}

status cmd_hole(string str) {
  object ob;
  if(env(tp) == to)
    return 0;
  if(!str)
  {
    notify_fail("Usage: 'hole [item]'\n");
    return 0;
  }
  if(!(ob=present(str, tp)))
  {
    if(ob=present(str, env(tp)))
    {
      notify_fail("You must pick that item up to put it in the portable hole.\n");
      return 0;
    }
    notify_fail("You don't see that item anywhere.\n");
    return 0;
  }
  if(transfer(ob,to))
  {
    notify_fail("You can't put that item inside the portable hole.\n");
    return 0;
  }
  else
  {
    write("Ok.\n");
    say(tpn+" puts something into a portable hole.\n");
    return 1;
  }
}

void long(string str) {
  ::long(str);
  if(this_player() != environment())
    write("Type \"hitems\" to view all the items within the hole,\n"+
          "or \"hole [item]\" to put an item into the hole.\n");
}

status cmd_hitems(string str) {
  write("Not implemented yet.\n");
  return 1;
}
