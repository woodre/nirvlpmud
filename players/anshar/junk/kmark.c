#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "obj/treasure";

string place;
reset(arg)
{
  if (arg) return;
  set_id("kmark");
  set_short();
  set_long();
  call_out("bye", 1000);
}

init()
{
  ::init();
  add_action("wipeoff","wipe");
}

bye() { destruct(this_object()); }
drop()  { return 1; }

wipeoff(str)
{
  if(!str)
  {
    write("What?\n");
    return 1;
  }
  if(str != "mark")
  {
    write("Wipe what?\n");
    return 1;
  }
  write("You wipe off the incriminating mark.\n");
  destruct(this_object());
  return 1;
}

set_where(str)
{
  if(!str)
  { 
    place = "cheek"; 
    return 0;
  }
  place = str;
  return 1;
}

extra_look()
  {
    object ex_look;
    ex_look = environment(this_object())->query_name();
    write(ex_look+" has a bright "+RED+"RED "+NORM+
          "kiss mark on the "+place+"!\n");
}
