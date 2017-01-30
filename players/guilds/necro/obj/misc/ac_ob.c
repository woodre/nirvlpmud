int ac;

id(str) { return str == "ac_ob"; }

drop() { return 1; }
get() { return 0; }

extra_look() {
    write(environment()->query_name()+" is currently in wraithform.\n");
}

set_ac(arg) { ac = arg; }

init() {
    if(environment(this_object()))
	if(this_player() == environment(this_object())){
	    this_player()->set_ac(ac);
	    call_out("wipe",1000);
	    return 1;
	} 
}

wipe() {
    if(!environment(this_object())) return 1;
    tell_object(environment(this_object()),"\nWraithform runs its course and you return to your solid form.\n\n");
    environment(this_object())->set_ac(0);
    destruct(this_object());
    return 1;
}
