  inherit "obj/armor";

reset(arg) {
  if(arg) return;
  set_name("bat armor");
  set_alias("armor");
  set_short("Bat Armor: extra strength brand");
  set_long("Bat armor is supper strong and protects you in the\n"+
           "worse conditions. It is blue with black intermixed.\n"+
           "it comes with its own cape.\n");
  set_value(6000);
  set_weight(8);
  set_ac(9);
  set_type("armor, ring, helmet, boots, cloak, shield");
}
