id(str) { return str=="key" || str=="half1"; }
reset() {}
init() {
call_out("hb",10);
}
short() {
	return "A glowing key";
}
long() {
	write("Half of a magical key.\n");
}
hb() {
	object magkey;
	if(present("half2", environment(this_object()))){
	magkey=clone_object("/players/dragnar/WasteLands/obj/quest/magkey.c");
	move_object(magkey, environment(this_object()));
	tell_object(environment(this_object()), "Two halves of the magical key assemble themselves into\n"+
"the magical key.\n");
	destruct(present("half2", environment(this_object())));
	destruct(this_object());
	}
call_out("hb",10);
}
query_save_flag() { return 1; }
get() { return 1; }
query_value() { return 20; }
