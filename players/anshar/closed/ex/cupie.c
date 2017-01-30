inherit "/obj/treasure";

short() { return "A cupie doll"; }

long() { write("     What a cute cupie doll! You must have done something\n"+
	       "great to have won this. The prize of your dreams! Wow!\n");}

id(str) { return str == "doll" || str == "cupie"; }

