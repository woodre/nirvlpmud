inherit "obj/weapon";
reset(arg) {
  if(arg) return;
  set_name("Dagger");
  set_short("Dagger");
  set_long("A dagger ready to fight.\n");
  set_weight(3);
  set_class(8);
  set_alias("dagger");
  set_value(20+random(5));
  set_read("'Dagger by Grimm'\n");
}
