inherit "/obj/weapon.c";
#include <ansi.h>
#define TPN this_player()->query_name()

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("axe");
  set_short("A battle axe");
  set_long(
 " A large double bladed battle axe.\n");
  set_type("axe");
  set_class(15);
  set_weight(3);
  set_value(1500);
  }

  
