#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("sword");
  set_short("A steel broadsword");
  set_long(
    "This is a strong steel broadsword with a brass crosspiece\n"+
    "and a leather grip.\n"
  );
  set_type("sword");
  set_class(17);
  set_weight(3);
  set_value(550+random(100));
}

void init()
{
  ::init();
  add_action("wield", "wield");
}
int wield(string str)
{
  int w;
  w = wielded;
  if(!::wield(str))
    return 0;
  if(w) return 1;
  write("Insert message here.\n");
  say("Insert message here.\n");
  this_player()->add_hit_point(-4);
  this_player()->add_spell_point(-4);
  this_player()->heal_self(-4);
  return 1;
}
