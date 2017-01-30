#define user environment(this_object())
id(str) { return str=="timer"; }
short() { return 0; }
long() { return 0; }
int x;
reset(arg) {
	if(!arg) x=0;
}
init() {
	call_out("hb",1);
	call_out("hb5",300);
	call_out("hb2",480);
	call_out("hb1",540);
	call_out("hb30", 570);
	call_out("hbend",600);
}
hb() {
	tell_object(user, "You hear a machanical voice from far away: 10 minutes until missile impact.\n");
	return 1; }
hb5() {
	tell_object(user, "You hear a machanical voice from far away: 5 minutes until missile impact.\n");
	return 1; }
hb2() {
	tell_object(user, "You hear a machanical voice from far away: 2 minutes to missile impact.\n");
	return 1; }
hb1() {
	tell_object(user, "You hear a machanical voice from far away: 1 minute to missile impact.\n");
	return 1; }
hb30() {
	tell_object(user, "You hear a machanical voice from far away: 30 seconds to missile impact.\n");
	return 1; }
hbend() {
	tell_object(user, "You see a bright flash of white light as the missles impact.\n");
	tell_object(user, "You feel yourself being blown through time and space.\n");
	tell_object(user, "\n\n");
	move_object(user, "room/church");
	command("look", user);
	destruct(this_object());
	}
get() { return 1; }
drop() { return 1; }
