/* An elixir of Malice  */
#include "/players/eurale/closed/ansi.h"

reset(arg) {
  if(arg) return;
}

long() { write(
	"This is an Elixir of Malice.  It will help change your align-\n"+
	"ment toward the 'evil lord' end.  This elixir is a one-shot\n"+
	"item that should cure your good ways.  All you need to do is\n"+
	"[guzzle] the elixir.\n");
	}

short() { return "An "+BOLD+"Elixir"+NORM+" of "+BOLD+RED+"Malice"+NORM; }

query_weight() { return 1; }

query_value() { return 250; }

init() {
  add_action("guzzle","guzzle");
}

guzzle(str) {
  if(str == "elixir" || str == "malice" || str == "malice elixir") {
/*
    if(this_player()->query_alignment() < -1500) {
      this_player()->add_alignment(0); }
    else {
      this_player()->add_alignment(-1500); }
*/
  this_player()->add_alignment(-1500);
  write("You guzzle the "+HIR+"Elixir of Malice"+NORM+" and feel much better...\n");
  write("You feel the goodness in your soul dissipate..\n");
  say("You sense an evil presence in the room....\n");
  destruct(this_object());
  return 1; }
}

get() { return 1; }

id(str) { return str == "elixir" || str == "malice"; }
