id(str) { return str == "sign"; }
get() {return 1; }
query_weight() { return 1; }
query_value() { return 7; }
short() { return "A sign that reads: 'KICK ME HARD!!'"; }
long() { write("Looks like someone managed to sneak this onto your back. :)\n"+
"Any one of the following commands will put this sign on the player you\n"+
"designate: pat <plyr>, and sneaksign <plyr>.\n"+
"There is a chance of failure using the 'sneaksign' command, and EVERYONE\n"+
"sees the 'pat' emote.\n\n"+
"-= Another KDY Product! =- Idea courtesy of Loki and Fireknight! [tm]\n");
}
init() {
	add_action("pat","pat");
	add_action("sneaksign","sneaksign");
	}


pat(arg) {
	object vict;
	if(!arg) return 0;

	vict=find_player(arg);
	if(!vict) { write("No such player is currently logged in.\n");
	return 1;
	}
	if(!present(vict, environment(this_player()))) {
	write("The player is not in the same room.\n");
	return 1;
	}
	if((vict->query_level())> 19) {
	write("That would not be a good idea.\n");
	return 1;
	}
	write("You pat "+arg+" on the back and deftly leave the sign there :)\n");
	say((this_player()->query_name())+" pats "+arg+" on the back.\n");
	move_object(this_object(), vict);
	return 1;
	}

sneaksign(arg) {
int chance;
object vict;
	if(!arg) return 0;
	vict=find_player(arg);
	if(!vict) { write("No such player is logged in right now..\n"); return 1; }
	if(!present(vict, environment(this_player()))) {
	write("That player is not in the same room.\n");
	return 1; }
	if((vict->query_level())>19) {
	write("Ahh... not a good idea...\n");
	return 1;
	}
	chance=random(10);
	if(chance > 9) {
		write("You try to sneak the sign on... Doh!! You got caught!\n");
		say((this_player()->query_name())+" tried to sneak a 'Kick me' sign onto "+arg+"'s back...\n");
		tell_object(vict, (this_player()->query_name())+" tried playing a joke on you but got caught.\n");
		return 1;
		}
	write("You sucessfully put the sign on "+arg+"'s back. Hehehehe\n");
	move_object(this_object(), vict);
	return 1;
	}
