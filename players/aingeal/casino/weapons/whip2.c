/* Siegfried and Roy whip */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "obj/weapon.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("whip");
   set_alias("whip");
   set_short("Siegfried's Black Leather Whip");
   set_long("This long, dangerous-looking whip is made of shiny black\n\
leather, and is suitable for taming animals of all kinds.\n");
   set_class(1);
   set_weight(1);
   set_value(1);
   set_type("whip");
}

drop(silently)
{
  if(wielded) { command("unwield whip",this_player()); }
  write("\n\tSiegfried's whip suddenly disintegrates\n\
\t\t        into a bright, shimmering waterfall\n\
\t\t\t           of twinkling  "+HIW+"S I L V E R"+NORM+"  glitter!\n\n");
  destruct(this_object());
  return 1;
}
