inherit "obj/food.c";
reset(arg) {
set_value (1200);

set_name("apple");
set_alias("rotten apple");
set_eater_mess("You devour the apple and feel much better.\n");
set_eating_mess(" tells you: You cant have any!\n");
set_strength(20);
set_short("A half-eaten apple");
set_long("This was once a nice red, delicious apple. Now, it is a\n"+
"rotten core of lifeless fruit..but if you are hungry....?\n");
}
