/*  an elixir of virtue  */
#include "/players/eurale/closed/ansi.h"

reset(arg) {
  if(arg) return;
}

long() { write(
	"This is an Elixir of Virtue.  It will help change your align-\n"+
	"ment toward the 'white lord' end.  This elixir is a one-shot\n"+
	"item that should cure your evil ways.  All you need to do is\n"+
	"[guzzle] the elixir.\n");
	}

short() { return "An "+BOLD+"Elixir"+NORM+" of "+BOLD+CYN+"Virtue"+NORM; }

query_weight() { return 1; }

query_value() { return 250; }

init() {
  add_action("guzzle","guzzle");
}

guzzle(str) {
  if(str == "elixir" || str == "virtue" || str == "virtue elixir") {
/*
    if(this_player()->query_alignment() > 1500) {
      this_player()->add_alignment(0); }
    else {
      this_player()->add_alignment(1500); }
*/
  this_player()->add_alignment(1500);
  write("You guzzle the "+HIC+"Elixir of Virtue"+NORM+" and feel much better...\n");
  write("You feel the evilness in your soul dissipate..\n");
  say("You sense a righteous presence in the room.....\n");
  destruct(this_object());
  return 1; }
}

get() { return 1; }

id(str) { return str == "elixir" || str == "virtue"; }
