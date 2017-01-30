inherit "obj/armor";

reset(arg) {
  set_name("chainmail");
  set_alias("mail");
  set_short("Ancient chainmail");
  set_long(
    "This is a tattered suit of chainmail that looks like it's seen\n"+
    "action over several centuries of battles.  It is a tribute to\n"+
    "its original high quality that it is still in as good shape as\n"+
    "it is.\n"
  );
  set_ac(3);
  set_type("armor");
  set_weight(2);
  set_value(300);
}
