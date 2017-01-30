id(str) { return str == "sisco"; }
reset () {}
long () {write("A pitcher of sisco.\n" +
"You feel like pounding the whole thing.\n"); }
short () { return "Pitcher of sisco"; }
init() {
add_action("pound"); add_verb("pound");
add_action("drop_object"); add_verb("drop");
}
pound(arg) {
say(call_other(this_player(), "query_name") + "pounds a pitcher of sisco.\n");
call_other(this_player(), "heal_self",20);
/* 350 heal for 5k coin? you are just insane -Bp axed to 25 */
write("You pound the sisco and smash the pitcher on the ground.\n");
destruct(this_object());
return 1;
}
get()   { return 1; }
query_weight() { return 0; }
query_save_flag(){return 1;}
query_value() { return 5000; }
drop_object(str) {
if (str == "all") {
drop_object("sisco");
return 0;
}
if (!str || !id(str))
return 0;
write("The pitcher breaks and the sisco soaks into the ground.\n");
say(capitalize(this_player()->query_real_name()) + " drops the pitcher and the sisco soaks into the ground.\n");
destruct(this_object());
return 1;
}
