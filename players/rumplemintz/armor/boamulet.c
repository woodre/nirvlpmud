inherit "obj/armor" ;

void reset(int arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("Bone Amulet");
  set_long("An Amulet made of bone, symbolizing nothing.\n");
  set_ac(1);
  set_weight(1);
  set_value(200);
  set_alias("amulet");
  set_name("Bone Amulet");
  set_type("amulet");
}
