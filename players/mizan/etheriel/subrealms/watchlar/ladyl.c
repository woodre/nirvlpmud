id(str) { return str == "mermaid" || str == "statue"; }
short() { return "A statue of a mermaid"; }
long() { write("This is a statue of a beautiful mermaid, graceful even in\n"+
	"suspension... and just pleasant to look at... yet sad.. She is looking\n"+
	"upwards wistfully, and her hand seems to be poking out of the surface of\n"+
	"the water.\n"+
	"There is an inscription on the base of the statue.\n"); }
init() { add_action("message","read"); }

message(str) {
if(!str || str!="inscription") return;
write("The inscription reads:\n\n"+
"Come... with me\n"+
"into a cool... blue... stream\n"+
"deep into ocean's dream\n"+
"Burst open wide,\n"+
"take in the tide...\n"+
"Wish for me,\n"+
"Hear all the oceans scream\n"+
"oh cant you be with me,\n"+
"Deeper inside,\n"+
"i'll make you mine\n\n"+
"Take me...\n"+
"down,\n"+
"Down where the voices\n"+
"drown,\n"+
"Down where the only\n"+
"sound...\n"+
"echoes for me...\n\n");
say((this_player()->query_name())+" reads the inscription.\n");
return 1;
}
