#include "def.h"
inherit "/obj/treasure.c";

int fuel;
int lit;

string short()
{
  return lit?"A lamp("+HIY+"lit"+NORM+")":"A lamp(unlit)";
}

void long()
{
  write("A gas lamp with a glass cover and a handle on the side so\n"+
        "that it can be carried.\n");
  if(this_player()->query_level() > 20)
    write("Wiz: There is "+fuel+" fuel remaining.\n");
}

int id(string str) { return str=="lamp"; }

void reset(int arg) {
  if(arg) return;
  fuel=10000;
  set_weight(1);
  set_value(100);
}

void init()
{
  add_action("cmd_light","light");
  add_action("cmd_turn","turn");
}

int cmd_light(string str)
{
  notify_fail("Light what?\n");
  if(!str) return 0;
  if(!id(str)) return 0;
  if(lit)
  {
    notify_fail("It is already lit.\n");
    return 0;
  }
  lit=1;
  set_light(1);
  call_out("lights_out",fuel);
  write("You light the lamp.\n");
  say(TPN+" lights a lamp.\n");
  return 1;
}

int cmd_turn(string str)
{
  notify_fail("Turn off what?\n");
  if(!str) return 0;
  if(str=="off lamp" || str == "lamp off") {
    if(!lit) {
      notify_fail("The lamp is not lit.\n");
      return 0;
    }
    write("You turn off the lamp.\n");
    say(TPN+" turns off the lamp.\n");
    lit=0;
    set_light(-1);
    fuel=find_call_out("lights_out");
    remove_call_out("lights_out");
    return 1;
  }
  if(str=="on lamp" || str=="lamp on") {
    if(lit) {
      notify_fail("It is already lit.\n");
      return 0;
    }
    lit=1;
    set_light(1);
    write("You light the lamp.\n");
    say(TPN+" lights a lamp.\n");
    call_out("lights_out",fuel);
    return 1;
  }
}

lights_out() {
  if(living(environment()))
    tell_object(environment(),"The lamp goes out.\n");
  else
    tell_room(environment(),"The lamp goes out.\n");
  lit=0;
  set_light(-1);
}

