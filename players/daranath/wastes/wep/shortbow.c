 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("bow");
set_alias("shortbow");
set_short("A shortbow");
set_long("Polished black wood makes you think whoever owned this bow once cared\n"+
     "greatly for it.\n");
set_class(15);
set_weight(1);
set_value(250);
}
