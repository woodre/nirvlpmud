inherit "obj/weapon.c";
reset(arg) {
    ::reset();
    if (arg) return;
    set_name("quil");
    set_alias("pen");
    set_short("A Feather Quil");
    set_long("An old style feather quil that can be used for writing but it looks\n" +
             "extremely sharp.\n\n");
    set_class(12);
    set_weight(1);
    set_value(350);
    set_hit_func(this_object());
}
