inherit "obj/clean";

id (str) {
	return str == "guide";
}

short () { return "Rocannon's world guide"; }

long () {
	write ("That's the guide to the Rocannon's world. You can 'read' it.\n");  
}

get () { return 1; }

query_weight () { return 1; }

query_value () { return 0; }

init () {
	add_action ("reading", "read");
}

reading (str) {
	if (!id (str)) return 0;
	write ("This is a guide of the Roccanon's world.\n");
	write ("Created by the Comission of the Star League.\n");
	write ("\nHere is the list of races discovered on the planet:\n");
	write ("1) Fiia.\nThey live in small villages.\nThey can transfer their thoughts to each other.\n");
	write ("2) Gdemia.\nHigh level of technology. They contacted with the League Comission and joined\nthe League. They were given a spaceship for their own use.\n");
	write ("3) Liua.\nThey divided into two nations:\n");
	write ("a) Angya.\n'The rulers'. Very strong race. They live in large castles and\nmakes war with each other. They pay debts to the League.\n");
	write ("b) Olgyo.\n'The Middlemen'. Hunters, fishmen etc. They live in small villages or hunt\nalone. There are many Olgyo servants who serve Angya men.\n");
	write ("4) (not sure) A race in the south part of planet.\n");
	write ("5) (not sure) Flying mammals!!!???\n");
	write ("That's all! Good luck in your travel, maybe you'll improve this guide!\n");
	say (this_player()->query_name()+" reads guide to the Rocannon's world.\n");
	return 1;
}
