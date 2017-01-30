inherit "obj/food.c";
reset(arg) {
set_value(1200);

set_name("clippings");
set_alias("human clippings");
set_eater_mess("You devour the human clippings and feel much better.\n");
set_eating_mess(" nibbles on some toenail clippings!\n");
set_strength(20);
set_short("Toenail clippings");
set_long("These are clippings from a human toenail.  This human was\n"+
"healthy, so these clippings should help some.\n");
}
