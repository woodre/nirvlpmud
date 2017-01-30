inherit "obj/clean";

int number;

id (str)
{
return (str == "grog") || (str == "bottle");
}
short () { return "A large bottle of Angya grog"; }

long () {
        write ("It's a large bottle of Angya grog.\nThere are "+
		number + " portions left.\n");
}

get () { return 1; }

query_weight () { return 1; }

query_value () { return 400 * number; }

init () {
	number = 10;
        add_action ("drink", "drink");
}

drink (str) {
	if (!id (str)) return 0;
	if (number == 0) { write ("There are no more grog left!\n"); return 1;  }
	write ("You feel much stronger after drinking the Angya grog.\n" +
	       "There are " + (number - 1) + " portions left!\n");
        say (this_player()->query_name()+" drinks the grog and smiles.\n");
        this_player()->add_hit_point (40);
	this_player()->add_spell_point (40);
	this_player()->add_intoxination (14);
	number --;
	return 1;
}
