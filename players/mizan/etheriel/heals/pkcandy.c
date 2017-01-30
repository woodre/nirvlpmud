inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("candy");
	set_short("A piece of butterscotch candy");
	set_long("This is an ordinary looking piece of butterscotch candy. Yum!\n");
	set_eating_mess(" picks up a piece of shit off the ground and eats it.\n");
	set_strength(1);
	set_value(5);
	}
}
