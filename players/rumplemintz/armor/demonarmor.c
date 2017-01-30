inherit "obj/armor";

void reset(int arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("Demon Garb");
  set_long("A thick, yet suprisingly light garb. Even though it's black,\n"+
           "it is letting of an eerie glow.\n");
  set_arm_light(1);
  set_save_flag(0);
  set_ac(1000);
  set_weight(2);
  set_value(25000);
  set_alias("garb");
  set_name("demongarb");
  set_type("armor");
}
