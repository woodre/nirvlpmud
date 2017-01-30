# define user environment(this_object())
# define att user->query_attack()
# define attname capitalize(att->query_real_name())
#define ROOM tell_room(environment(user),
id(str) { return str=="lightningspell"; }
short() { return 0; }
long() { return 0; }
reset(arg) {
}
init() {
	add_action("do_damage", "do_damage");
        call_out("start", 5);
        call_out("bolt", 20);
        call_out("lightning", 30);
        call_out("ball", 40 );
        call_out("end", 45);
}
start() {
ROOM "You see a mass of black clouds moving toward you.\n");
        return 1; }
bolt() {
        if(!att || !user) {
		end();
	}
ROOM "A bolt of blue light races from above and slams into the chest of "+attname+".\n");
		command("do_damage", user);
        return 1;
        }
lightning() {
        if(!att || !user) {
		end();
}
ROOM "The sky lights up as lightning shoots from the sky and shocks "+attname+".\n");
		command("do_damage", user);
        return 1;
         }
ball() {
     if(!att || !user) {
		end();
		}
ROOM "The dark clouds glow blood red as a ball of fire falls from the storm.\n");
ROOM ""+attname+" is totally engulfed by a huge ball of flames.\n");
		command("do_damage", user);
        return 1; }
end() {
ROOM "The storm breaks up and the sky is clear once again.\n");
        destruct(this_object());
        return 1; }
do_damage() {
	if(att) {
	att->hit_player(100);
	write("HITTING!\n");
	return 1;
	}
}
get() { return 1; }
