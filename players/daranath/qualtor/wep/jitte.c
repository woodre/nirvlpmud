 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("jitte");
    set_alias("Jitte");
    set_type("dagger");
    set_short("A steel Jitte");
    set_long("A small steel weapon, the Jitte was used more to backup your\n"+
             "main weapon then as an offensive threat.\n");
    set_class(11);
    set_weight(1);
    set_value(300);
}
