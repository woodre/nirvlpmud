inherit "obj/treasure.c";

#include <ansi.h>

#define ENV environment
#define QN query_name()

int x;

id(str){ return str == "pk_tourney_heal" || str == "prize_heal" || str == "potion"; }

reset(arg)
{
  set_short(CYN+"A mystical healing potion"+NORM);
  set_long(
    "This is one of the prizes for winning the PK Tournament.\n"+
    "It has the capabilities to heal both hps and sps over a\n"+
    "certain time period.  Just 'drink potion'.\n");
  x=0;
}

init()
{
  ::init();
  add_action("Cmd_drink", "drink");
}

drop()
{
  if(x)
    return 1;
 
  return 0;
}

Cmd_drink(str)
{
  if(!str)
  {
    notify_fail("Drink what?\n");
    return 0;
  }
  if(str != "potion")
  {
    notify_fail("Drink what?\n");
    return 0;
  }

  tell_object(ENV(),
    "You drink the potions and feel "+CYN+"mystical"+NORM+" energy course through your body.\n");

  tell_room(ENV(ENV()),
    ENV()->QN+" drinks a "+CYN+"mystical"+NORM+" potion.\n", ({ ENV() }));

  call_out("heal_me", 2);
  call_out("bye", 1200);
  
  x=1;

  this_object()->set_short(0);

  return 1;
}

heal_me()
{
  int amt;
  int hp,sp,mhp,msp;

  amt = 5+random(10);

  hp = ENV()->query_hp();
  mhp = ENV()->query_mhp();
  sp = ENV()->query_sp();
  msp = ENV()->query_msp();

  ENV()->heal_self(amt);

  remove_call_out("heal_me");
  call_out("heal_me", 1+random(4));

  return 1;
}

bye()
{
  tell_object(ENV(),
    "\n\n"+CYN+"The mystical energy escapes your body.\n\n"+NORM);
 
  destruct(this_object());
}

  

  
    
