inherit "/obj/treasure";

void reset(int arg) {
  ::reset(arg);
  if (arg)
    return;
  set_name("doppleganger_light_object");
  set_short(0);
  set_long("Allows dopplegangers to see in the dark while morphed.\n");
  set_weight(0);
  set_value(0);
  set_light(1);
}

int drop() { return 1; }
