inherit "obj/treasure";

init() {
::init();

add_action("destroy_orb", "smash");
}

destroy_orb() {
write("You hurl the orb straight towards the ground with all your might,\n"+
       "it smashes against the ground and explodes, releasing all the powers\n"+
      "it contained.\n\n");
write("Congratulations! You have solved this quest.\n");
say(call_other(this_player(),"query_name", 0) + 
 " hurls the orb straight towards the ground, smashing it into a million\n"+
 "pieces!\n"+
 "\n");
command("grin",this_player());
this_player()->set_quest("protoculture");
destruct(this_object());
return 1;
}

reset(arg) {
set_short("Protoculture Orb");
set_long("This Orb contains all the magical powers of generating life. If so\n"+
         "used for good, all life generated will turn out good. Used for\n"+
	 "evil, all life generated will turn out evil. If in the wrong\n"+
	 "possession, who knows what may happen.\n");
set_weight(6);
}
id(str) {return (str == "orb");}

