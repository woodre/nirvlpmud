id(str) { return str=="key" || str=="mag3"; }
reset() {}
init() {
/* added by verte */
while(remove_call_out("hb") != -1);
call_out("hb",10);
}
short() {
	return "A glowing key";
}
long() {
	write("A piece of a magical key.\n");
}
hb() {
	object half2;
	if(present("mag4", environment(this_object()))){
	half2=clone_object("/players/dragnar/WasteLands/obj/quest/half2.c");
	move_object(half2, environment(this_object()));
	tell_object(environment(this_object()), "Two pieces of the magical key assemble themselves into\n"+
"a half of the magical key.\n");
	destruct(present("mag4", environment(this_object())));
	destruct(this_object());
         return; /* added by verte 6.9.01 */
	}
/* added by verte */
while(remove_call_out("hb") != -1);
call_out("hb",10);
}
query_save_flag() { return 1; }
get() { return 1; }
query_value() { return 20; }
