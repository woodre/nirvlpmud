#include <ansi.h>

inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("Masonic Saber");
  set_alias("saber");
  set_type("sword");
  set_short(HIY+"M"+HIW+"asonic"+NORM+" "+HIY+"S"+HIW+"aber"+NORM);
  set_long("  This popular saber has a quality stainless-steel blade with a central\n\
vein from top to bottom. The hilt and quillons are engraved with\n\
numerous Masonic designs. The scabbard is made of premium-quality\n\
black leather. The metallic protection (pipe and head), in an aged-\n\
silver style, add to the majestic appearance of the scabbard.\n");
  set_class(1);
  set_weight(2);
  set_value(50);

}