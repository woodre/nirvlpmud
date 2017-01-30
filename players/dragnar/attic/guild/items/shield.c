# define user environment(this_object())
#define t_pac this_player()->query_ac()
int class, rank;
id(str) { return str=="shieldmax"; }
short() { return 0; }
long() { return 0; }
init() {
	add_action("armor","armor");
	add_action("shieldoff","shieldoff");
	call_out("reduction", (1000 + (80*rank)));
}
shield() {
	if(user->query_ac() > ((t_pac + class) - 1)) {
	write("Your shield is already at maximun.\n");
	return 1; }
	tell_object(user, "Setting shields back to max.\n");
	find_player(user->query_real_name())->set_ac(t_pac + class);
	return 1;
	}
reduction() {
	shieldoff();
   return 1;
}
shieldoff() {
	this_player()->set_ac(t_pac - class);
	write("The dark cloud surrounding you fades away.\n");
	say("The dark cloud surrounding "+capitalize(user->query_real_name())+" fades away.\n");
	destruct(this_object());
	return 1;
}
set_rank(RANK) { rank = RANK; }
set_class(AC) { class = AC; }
get() { return 1; }
