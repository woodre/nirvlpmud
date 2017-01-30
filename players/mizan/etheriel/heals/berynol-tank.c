/*
VERY OLD->>     Scooter helped me BIG time with the code on this
                jug. (The part involving the sscanf function.
                I got this idea from Genocide. More functions are
                being worked out....

NEW->>	This item is gradually going to be phased out of service.
	Reason: It needs to be revamped, and BIG time. It was carried
	over because people actually like it- really! they do :)
	1 Dec 93
*/
object ob;
string kick;
int pow_int;
id(str) { return str == "tank" || str == "MI-tank"; }
short() { return "A blue plastic tank"; }
long() {

write("This is an empty blue plastic tank. It appears to be nearly WORTHLESS!\n");

        }

get() { return 1; }
query_weight() { return 2; }
query_value() { return 300; }

