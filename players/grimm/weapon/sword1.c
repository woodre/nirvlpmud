inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return;
        set_name("carpathian sword");
        set_alt_name("sword");
        set_short("Carpathian Sword");
        set_long("This is the weapon of choice for great vampires!\n");
        set_class(15);
        set_weight(5);
        set_value(2700);
}
