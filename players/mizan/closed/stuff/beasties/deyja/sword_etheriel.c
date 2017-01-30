inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Sword named Etheriel");
    set_long("This is an interim object :) Nobody will kill Deyja :)\n");
    set_short("A Sword named Etheriel");
    set_class(21);
    set_value(30000);
    set_alias("sword");
    set_weight(6);
    set_hit_func(this_object());

}
}
