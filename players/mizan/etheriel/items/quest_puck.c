int used_tl;

id(str) { return str == "puck"; }
short() { return "The hockey puck of Squish"; }
long() { write("This is the hockey puck of Squish. It has a sticker on it\n"+
	"that reads: \n\n"+
	"	Best of luck, Squish,\n"+
	"				-Your pal Stassi\n\n");
	}
get() { return 1; }
query_value() { return 1000; }
query_weight() { return 1; }

init() {
  add_action("giveme","give");
}

giveme(str) {
  if(str == "puck to squish" && present("mi627017723", environment(this_player())) && !used_tl) {
  write("You give the puck to Squish.\n");
  used_tl=1;
  move_object(this_object(), present("mi627017723", environment(this_player())));
  ending();
  return 1;
  }
  return 0;
}

ending() {
write("Squish smiles happily and licks you.\n\nYou have successfully solved this quest.\n");
  call_other(this_player(), "set_quest", "hockey_puck");
  return 1;
}
