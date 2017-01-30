inherit "/obj/weapon.c";
#include <ansi.h>
#define TPN this_player()->query_name()

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("halberd");
  set_short("A halberd");
  set_long(
 " A finely made polearm.  The five foot long shaft ends in a\n"+
 "fancy spear tip.  Tied behind the point, two black ribbons\n"+
 "sway.\n" );
  set_type("polearm");
  set_class(16);
  set_weight(3);
  set_value(2200);
  }

  
