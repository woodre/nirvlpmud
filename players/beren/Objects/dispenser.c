inherit "obj/clean";

object ob;
id (str) {
	return str == "dispenser";
}
id2 (str) {
	return str == "button";
}

short () { return "Star League dispenser"; }

long () {
	write ("This is Rocannon's world guide dispenser.\n'Push button' to get the guide.\n");

}

get () { return 0; }

query_weight () { return 1; }

query_value () { return 0; }

init () {
	add_action ("pushing", "push");
}

pushing (str) {

	if (!id2 (str)) return 0;
	write ("You've gotten something from the dispenser.\n");
	ob = clone_object ("players/beren/Objects/guide.c");
	move_object (ob, this_player ());
	say (this_player()->query_name()+" has gotten something from the dispenser.\n");
	return 1;
}
