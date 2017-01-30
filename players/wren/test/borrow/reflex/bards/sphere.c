#define tp this_player()->query_name()
string charges_count, player_info;

int n, ahp;
int time_delay;

init()
{
	add_action("sphere", "orb");
	add_action("globe", "globe");
	add_action("slarf", "slarf");
}

query_save_flag(){ return 1; }

short(){ return "A globe of chromatic spheres"; }
long(){
write("A hazy globe filled with chromatic spheres.\n" +
		"To use the chromatic sphere, type <orb monster>.\n" +
		"To destruct the globe, type <slarf>.\n" +
		"To check the number of spheres left, type <globe>.\n");
return 1;
}

query_weight(){ return 1; }
query_value(){ return 0; }
id(str){ return str == "sphere" || str == "globe" || str == "sphere_bard"; }

reset(arg)
{
   if(arg) return;
	charges_count = 0;
	player_info = 0;
	count();
	}

sphere(str)
{
	object ob;

	if (!str) {
		write("Sphere what?\n");
		return 1;
	}
	if(time_delay >= time()) return 1;
	ob = present(str, environment(this_player()));
	if (!ob || !living(ob)) {
		write("To use 'sphere <monster>'.\n");
		return 1;
	}
	if (ob->query_npc()) {
		n = random(20) + 10;
		ahp = ob->query_hp();
		if (n > ahp) {
			n = ahp - 1;
		}
		ob->hit_player(n);
		time_delay = time();
		count();
		str = capitalize(str);
		write("You hurl a chromatic sphere at " + str + ".\n" +
			  str + " is blasted by a burst of chromatic colors.\n");
		say(tp + " hurls a chromatic sphere at " + str + ".\n" +
			str + " is blasted by a burst of chromatic colors.\n");
		this_player()->attack_object(ob);
		if (living(ob))
			ob->attack_object(this_player());
		if (charges_count > 4) {
			write
				("The chromatic sphere fades back into the chaos from which it was formed.\n");
			say(tp +
				"'s chromatic sphere fades back into the chaos from which it was formed.\n");
			destruct(this_object());
			return 1;
		}
		return 1;
	}
	write("You cannot attack players with this.\n");
	return 1;
}

drop()
{
	return 1;
}

get()
{
	return 1;
}

slarf()
{
	write
		("The colors of the globe fade back into the streams of chaos.\n");
	destruct(this_object());
	return 1;
}

can_put_and_get()
{
	return 0;
}

count()
{
	charges_count = charges_count + 1;
	player_info = 5 - charges_count;
}

query_count()
{
	return player_info;
}

globe()
{
	write("You have " + query_count() + " spheres left.\n");
	return 1;
}
