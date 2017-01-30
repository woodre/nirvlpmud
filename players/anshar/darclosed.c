#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "/obj/treasure";

short() { return "Teller"; }

long() { write("    Room under repair\n"); }

id(str) { return str == "repair"; }

init()
{
  call_out("check",1);
}

get(){ return 0; }

check()
{
  object target;
  object env;
  env="/players/daranath/qualtor/mansion/depository";
  target=first_inventory(env);
  while(target)
  {
    if(living(target))
    {
      target->move_player("out#/players/daranath/qualtor/merch_way.c");
      write("Room closed for repair\n");
    }
   target=next_inventory(target);
  }
  call_out("check",1);
  return 1;
}
