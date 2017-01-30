inherit "obj/armor";
int worn, sexy, x;
reset(arg){
   ::reset(arg);
	if(!arg) x=1;
   set_arm_light(0);
set_short("A red condom");
set_long(
	"A red condom.  Maybe you should 'put on condom' so you can have sex\n"+
"without the worries of having a mud kid.  Just type 'sex <name>'.\n");
   set_ac(1);
   set_weight(1);
   set_value(0);
   set_alias("condom");
   set_name("condom");
   set_type("misc");
}
init() {
	::init();
	add_action("sex","sex");
	add_action("put","put");
}
put(str) {
	if(str=="on condom"){
	worn==1;
	command("wear condom", this_player());
	tell_object(this_player(), "You roll on the condom and are ready for battle!\n");
	return 1;
	}
}
sex(str) {
	object owner, ob, sexob;
	owner=environment(this_object());
	if(worn==1){
	if(x > 2) {
	write("The condom is used! God thats sick!\n");
	return 1;
	}
	if(!str) {
	write("Sex who?\n");
	return 1;
	}
	ob=present(str, environment(owner));
	if(!ob){
	write(capitalize(str)+" is not here.\n");
	return 1;
	}
	if(!living(ob)) {
	write("You want to have sex with something that is not living?\n"+
"Buy Dragnar's love doll in his castle!\n");
	return 1;
	}
	if(!find_player(str)) {
	write("You want to have sex with something not human!? You are sick!\n");
	return 1;
	}
	x=x+10;
	sexob=clone_object("/players/dragnar/armor/sexob.c");
	move_object(sexob, find_player(str));
	sexob->set_user(this_player());
	write("You ask "+str+" to have sex.\n");
	tell_object(find_player(str), capitalize(owner->query_real_name())+" wishes to have sex with you.\n"+
"If you want to have sex type sexme.\n");
	return 1;
	}
	return 1;
}
query_value() { return 500; }
