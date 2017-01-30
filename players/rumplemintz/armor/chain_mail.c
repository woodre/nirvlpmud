inherit "obj/armor.c";

void reset(int arg) {
  ::reset(arg);
  if(arg)
    return;
  set_name("chain mail");
  set_short("A suit of chain mail");
  set_type("armor");
  set_ac(4);
  set_weight(5);
  set_value(500);
  set_alias("mail");
}
