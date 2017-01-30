#include "std.h"
id(str) { return str == "toilet"; }
short() { return "A toilet"; }
long() { 
write("It looks like you can flush things down this toilet.\n"); 
}
init() {
	add_action("flush","flush");
	}
flush(str) {
object t1, t2;
	if(!str) return 0;
	command("drop "+str, this_player());
	t1=present("tststs");
	if(!t1) {
    write("Now you would just love to do that, would'nt you?\n");
    return 1;
  }
  if(living(t1) || !t1->get()) {
    write("Nopers.\n");
    return 1;
  }
	write("You flush a "+str+" down the toilet. Whee!\n");
	destruct(present(str));
	say((this_player()->query_name())+" flushes a "+str+" down the toilet.\n");
	return 1;
	write("You flush the shirt down the toilet and something odd happens!\n"+
	"The toilet explodes! You find something amid the rubble.\n");
	t2=clone_object("players/mizan/munchies/twinkie.c");
	destruct(present(t1));
	move_object(t2, environment(this_object()));
	say((this_player()->query_name())+" flushes the shirt down the toilet and it explodes!\n");
	destruct(this_object());
	return 1;
	}
