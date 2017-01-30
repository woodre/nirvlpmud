#include "/obj/clean.c"
#define ROT_TIME 100
inherit "obj/treasure";

string part_name;
string donor;
string owner;
string long_desc;
string short_desc;


set_owner(str) { owner = str; }
set_part(str) { part_name = str; }
set_name(str) { donor = str; }

setup(p,d,o) {
	part_name = p;
	donor = d;
	owner = o;
	this_object()->set_short(donor+"'s bloody "+part_name);
	this_object()->set_long(donor+"'s bloody "+part_name+" cut off by "+owner+".\n");
	this_object()->set_alias(part_name);
	this_object()->set_name(part_name);
}


init() {
	add_action("eat", "eat");
	add_action("setup","setup");
	add_action("set_owner","set_owner");
	add_action("set_part","set_part");
	add_action("set_name","set_name");
}

reset() {
	set_value(15);
	short_desc = donor+"'s "+part_name;
	long_desc = donor+"'s "+part_name+" cut off by "+owner+"\n";
	set_short(short_desc);
	set_long(long_desc);
	set_weight(1);
	set_alias(part_name);
}
eat(str){
	if(!str){
	   write("And what pray-tell are you to eat?\n");
	   return 1;
	}
	if(str = part_name) {
	   write("You munch on a bloody "+part_name+".\n");
	   say(this_player()->query_name()+" eats a bloody "+part_name+"\n");
	   tell_object(this_player(), "You eat a "+part_name+" and feel better.\n");
	   this_player()->heal_self(random(8));
	destruct(this_object());
	   return 1;
	}
	else return 0;
}

