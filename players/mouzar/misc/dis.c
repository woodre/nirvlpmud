id(str) {return str == "machine";}
short() {return "A Koosh Machine";}
long() {write("An old koosh machine.  You can try to pull lever to see if\n"+
	      "it still works.  You see some words on the side saying 'Kooshs\n"+
	      "only 200 coins'.\n");return;}

get() {return 0;}
init () {
	add_action("pull","pull");
}
pull(str) {
	int value;
        value = 200;
if(!str || str!="lever"){
	return 0;
}
else{
if(str == "lever"){
if(this_player()->query_money() < value) {
		write("You DON'T have 200 coins!\n");
		return;
	}
else {
this_player()->add_money(-value);
	move_object(clone_object("/players/mouzar/closed/koosh"),this_player());
	write("You are kooshed by the machine!  You can hear Mouzar laughing in \n"+
	      "the distance.\n");
	say(capitalize(this_player()->query_real_name())+ " is kooshed by the machine.\n");
	return 1;
	}
}
}
}
