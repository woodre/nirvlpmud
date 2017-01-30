id(str) { return str == "hunter"; }
int hunting;
string victim;
reset(arg) {
if (arg) return;
hunting = 0;
}
short() {
if (hunting) return capitalize(victim->query_name()) + "'s hunter";
return "A hunter";
}
long() {
write("A hunter sent to annoy you.\n");
return 1;
}
get() { return 0; }
drop() { return 0; }
init() {
add_action("hunt","hunt");
add_action("nope","dest");
add_action("nope1","Destruct");
add_action("nope","destruct");
add_action("nope","clean");
add_action("stop","terminate");
}

hunt(str) {
if (hunting) {
write("Hunter says: I am already hunting "+ victim->query_name() + "\n");
return 1;
}
victim = find_living(str);
if (!victim) {
write("No such living thing.\n");
return 1;
}
hunting = 1;
call_out("annoy",3);
return 1;
}

annoy() {
if (!present(victim, environment(this_object()))) {
move_object(this_object(), environment(victim));
tell_object(victim, "A hunter comes to annoy you.\n");
}
if (present(victim, environment(this_object()))) {
tell_object(victim, "Hunter pokes you.\n");
tell_object(victim, "Hunter slaps you!\n");
tell_object(victim, "Hunter pukes on you!\n");
}
call_out("annoy",3);
return 1;
}

nope() {
write("Hunter says: I cannot allow that.\n");
say("Hunter refuses to be destroyed.\n");
return 1;
}

nope1() {
write("Hunter says: I cannot allow that.\n");
say("Hunter refuses to be destroyed.\n");
return 1;
}

stop() {
write("Ok.\n");
say("Hunter destroyed.\n");
destruct(this_object());
return 1;
}

