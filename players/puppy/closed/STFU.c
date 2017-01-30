/*  an object to quiet annoying players  */

id(str) { return str == "muzzle"; }

init() {
  add_action("trap_command"); add_xverb("");
}

trap_command(str) {
if(!environment(this_object())) {
  destruct(this_object()); }
if(!this_player()) return;
if(this_player() != environment(this_object())) return;
if(lower_case(str) == "quit") {
  this_player()->quit();
  return 1; }
write("You have been silenced by Puppy.  You have two choices:\n"+
  	"  You can wait until he releases you or\n"+
	"  You can quit.\n"+
	"\n  Take your pick and learn from it!\n");
  return 1; }

get() { return 1; }
drop() { return 1; }
