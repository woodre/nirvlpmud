inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("elven longbow");
set_type("bow");
set_short("Elven longbow");
set_long("Elven longbows are perfect in quality, made by the finest fletchers in\n"+
         "the land. Not very powerful, but the elves are capable of putting\n"+
         "repeated shots into a target in seconds.\n");
set_class(15);
set_weight(1);
set_value(300);
}

