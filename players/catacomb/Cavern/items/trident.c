inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("trident");
  set_short("A Durkor trident");
  set_long(
 "  A finely crafted polearm that very few of the Durkor use.  The \n"+
 "few that do use the tridents are masters of the weapon.\n");
  set_type("polearm");
  set_class(14);
  set_weight(2);
  set_value(500);
  set_hit_func(this_object());
}

  