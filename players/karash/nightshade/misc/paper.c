inherit "obj/treasure";
reset(arg) {
if (arg) return;
set_short("piece of paper");
/*
set_long(
"On the piece of paper you see this:\n"+
"                                    \n"+
"To heal hp: type heal hp.           \n"+
"To heal sp: type heal sp.           \n"+
"To heal both: type heal both.       \n"+
"                                    \n"+
"To transfer sp to hp type this:     \n"+
"          Transfer                \n");
*/
set_long("A blank piece of paper.\n");
set_weight(1);
set_alias("paper");
set_value(0);
}
