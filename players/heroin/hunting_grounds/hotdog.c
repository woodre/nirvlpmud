inherit "obj/food.c";
reset(arg) {
set_value(1200);

set_name("hot dog");
set_alias("hot dog");
set_eater_mess("You eat up the hot dog, even though you have no relish\n");
set_eating_mess("Sucks that weiner right out of the bun!\n");
set_strength(20);
set_short("A cold hot dog");
set_long("This is a half rotten weiner.  Its cold, so it should still\n"+
"be good...or at least you hope.\n");
}
