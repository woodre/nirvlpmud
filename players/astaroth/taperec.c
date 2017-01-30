inherit "obj/weapon";
reset(arg) {
  if (arg) return;
  set_name("recorder");
  set_class(9);
  set_weight(3);
  set_value(150);
  set_short("A pipelined tape recorder");
  set_long("This is piped into the sound system to make it seem like singing\n" +
           "is actually taking place here.\n" +
           "");
}
