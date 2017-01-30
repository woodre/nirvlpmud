inherit "/obj/armor.c";

void reset(int arg) {
  if(arg) return;
  set_name("leather");
  set_alias("armor");
  set_short("Studded leather armor");
  set_long(
    "A suit of boiled leather armor with metal studs in it.\n"
  );
  set_ac(2);
  set_type("armor");
  set_weight(2);
  set_value(300);
}
