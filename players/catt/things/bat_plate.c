inherit "obj/armor";
reset(arg) {
  if(arg) return;
  set_name("bat plate");
  set_alias("plate");
  set_short("Bat Plate");
  set_long("This is the body armor used by batman. It is very\n"+
           "good armor.\n");
  set_value(4000);
  set_weight(3);
  set_ac(4);
  set_type("armor");
}
