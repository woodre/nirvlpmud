int w;
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("strong quarterstaff");
set_alias("quarterstaff");
set_type("staff");
set_short("A strong quarterstaff");
set_long("A good quarterstaff, about 5 feet in length. It was cut\n"+
         "from a strong tree.\n");
set_class(13);
set_weight(1);
set_value(75);
}
