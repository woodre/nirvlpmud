#include "/players/maledicta/ansi.h"

inherit "players/maledicta/weapon/weapon.c";


reset(arg){
	::reset(arg);
	if (arg) return;
        set_name("uglystick");
	set_type("sword");
	set_class(12);
	set_weight(1);
	set_value(0);
	add_special_fun("/players/maledicta/weapon/powers/death.c");
   add_special_fun("/players/maledicta/weapon/powers/greed.c");
   add_special_fun("/players/maledicta/weapon/powers/glacier.c");
   add_special_fun("/players/maledicta/weapon/powers/magi.c");
   add_special_fun("/players/maledicta/weapon/powers/cleansing.c");


	set_no_break(1);
	set_hit_func(this_object());
}

init()  {
	::init();
	add_action("whack","whack");
}

whack(str){
	object whackat;
	object ugly;
	string who;
	if(!str) return 0;
	if(str != "")  {
		who = lower_case(str);
		whackat = find_living(who);
		if(whackat && whackat->query_invis() > 19)
		whackat = 0;
		if (whackat && present(whackat, environment(this_player()))) {
			if(present(who, environment(this_player())))  {
				ugly = clone_object("/players/arrina/treas/ugly.c");
				transfer(ugly, whackat);
				say( (this_player()->query_name()) + " whacked " + (whackat->query_name()) +
				" with an Ugly Stick!!\n");
				write("You have whacked "+capitalize(str)+" with an Ugly Stick!\n"+
				"You never noticed how FRIGHTFUL "+str+" was before!\n");
				tell_object(whackat, this_player()->query_name()+ " whacks you with an Ugly Stick!\n"+
				"You are very FRIGHTFUL now!!\n");
				return 1;
			}
			write("No "+str+" here!\n");
			return 1;
		}
	}
}

long(){
	write(
		"This is an Ugly Stick. When you whack someone with this,\n"+
	"the person will turn UGLY! To use, type WHACK <player>.\n");
	if(this_player()){
		if(this_player()->query_real_name() == "kaleia"){
			write("And you can wield it!\n");
		}
	}
	return 1;
}

weapon_hit(attacker){
	if(random(100) < 20) return 10;
	return 6;
}

short(){
	string totshort;
	totshort = "An Ugly Stick";
	if(this_player())
	if(wielded && this_player()->query_real_name() == "kaleia") totshort += " (wielded)";
	return totshort;
}
