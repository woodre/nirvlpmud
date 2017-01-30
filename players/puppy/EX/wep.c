#include "/players/puppy/define.h"
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("sword");
   set_alias("sword");
   set_type("sword");    /* sword/knife/club/axe/bow/polearm   */
      set_short("A sword");
   set_long("This is a description of a sword.\n");
   set_read("This blade was forged by Sengard.\n");
   set_class(0);
   set_weight(0);
   set_value(0);
   set_hit_func(this_object());
   
   message_hit=({
    "impaled","",   
    "pierced","",
    "wounded","",
    "shot","",
    "hit","",
    "winged","",
    "grazed","",
  });
}