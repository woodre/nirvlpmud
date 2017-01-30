inherit "/obj/armor.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("cloak");
  set_alias("hood");
  set_short("A black, hooded cloak");
  set_long(
"This is a dark black cloak with a hood.  It has a rather bad smell\n"+
"to it, but you think you can wear it anyway.\n"
  );
  set_ac(1);
  set_type("misc");
  set_weight(1);
  set_value(300);
}

