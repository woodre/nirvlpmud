short() { return 0; }
int x;
object user;
reset(arg) {
	if(arg) return;
	set_heart_beat(1);
	enable_commands();
	if(!arg) user=0;
x=0;
}
id(str) { return str=="sexob"; }
set_user(ob) { user=ob; }
init() {
	add_action("sexme","sexme");
}
heart_beat() {
	x=x+1;
	if( x > 50) {
	destruct(this_object());
	}
	if(user==0){
	destruct(this_object());
	}
}
sexme() {
	write("You have sex with "+capitalize(user->query_real_name())+".\n");
	tell_object(user, "You have sex with "+capitalize(this_player()->query_real_name())+".\n");
	destruct(this_object());
	return 1;
}
get() { return 1; }
query_user() { return user; }
