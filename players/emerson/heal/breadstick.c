inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("breadstick");
set_short("A Hot Breadstick");
set_eater_mess("The breadstick melts in your mouth, you feel much better!\n");
set_long("A tasty looking breadstick from Pizza Hut.\n");
	set_strength(20);
	}
}
query_save_flag()
{
return 1;
}
