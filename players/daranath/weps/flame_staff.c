 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("staff");
    set_alias("flame staff");
    set_short("A flame red staff");
    set_long("The staff is the standard weapon of the pyromancers, its\n"+
             "coloring from thier favorite element: flame.\n");
    set_class(16);
    set_weight(1);
    set_value(250);
}
