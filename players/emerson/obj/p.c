inherit "/obj/treasure.c";
reset(arg)  {
	if(arg) return;
set_short("A pinball machine");
set_long("You can 'play pinball' for sp/hp but it will cost you sp to play.\n");
set_id("machine");
  set_alias("pinball machine");
	set_weight(1000);
}
init() {
	::init();
	add_action("play","play");
}
play(str) {
	object pinball;
	if(str=="pinball") {
	if(this_player()->query_sp() < 35) {
	write("You don't have enough spell points!\n");
	return 1;
	}
	this_player()->add_spell_point(-35);
	write("You put your spell points in the machine and pull back on the lever.\n");
	write("Boing! Boing! Boing!\n");
	write("The ball flies around inside the machine!\n");
	call_out(write("Awwwww....the last ball slips past you!\n"),15);
	write("The game flashes your score for all to see.\n");
	say(capitalize(this_player()->query_real_name())+" loads the pinball machine and plays a quick game.\n");
	if (random(100) < 10) {
	this_player()->heal_self(350);
	write("Alright!! You kicked ass!! You've got the high score!\n");
	say(capitalize(this_player()->query_real_name())+" got the high score!\n");
	}
	else if (random(100) < 25) {
	this_player()->heal_self(20);
    write("Good job! You made the top ten!\n");
	say(capitalize(this_player()->query_real_name())+" made the top ten!\n");
	}
	else {
	write("Damn, you better practice some more, you didn't even make the top ten!\n");
	say(capitalize(this_player()->query_real_name())+" didn't even make the top ten!\n");
	}
  	return 1;
	}
  	} 
