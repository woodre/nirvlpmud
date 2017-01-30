
id(str) { return str=="massage table" || str=="table"; }
reset () {}
short() {
	return "A Massage Table";
}
long() {
write("This is a very comfortable looking massage table.\n"+
"When you finish all your workouts you get get a relaxing massage.\n"+
"Just 'lay on massage table' and let your muscles unwind.\n"+
"Rest (and massage) are the most important parts of training.\n"+
"Getting a massage will give you very beneficial results for your hard training.\n"+
"");
}
get() {
	tell_object(this_player(), "It is too heavy.\n");
	return 0;
	}
query_weight() { return 0; }
query_value() { return 5000; }
