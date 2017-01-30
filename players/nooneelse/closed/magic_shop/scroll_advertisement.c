/*
  curse_scroll.c - the read/activation mechanism was inspired by boltar's
                   scrolls on nirvana
*/

init() {
  add_action("read", "read");
  add_action("read", "examine");
  add_action("read", "look");
}

read(str) {
  if (str=="at scroll") str="scroll";
  if (!str || !id(str)) return 0;
  long();
  return 1;
}

reset(arg) { return 0; }

short() { return "A scroll"; }

long() {
  write(
"\n"+
"              ________________________________________________  \n"+
"             /                                             /  \ \n"+
"            |                                             |___/ \n"+
"            |                                             |     \n"+
"            |   Check out Nooneelse's Souvenir Shop!      |     \n"+
"            |                                             |     \n"+
"            |   From the clearing west of the church,     |     \n"+
"            |   go north to the violet mist.  Enter it.   |     \n"+
"            |   Then figure out how to get one of the     |     \n"+
"            |   amulets of membership to the Rainbow      |     \n"+
"            |   Inn.  Then go north to get to the         |     \n"+
"            |   Restaurant/pub, pie shop, souvenir ship   |     \n"+
"            |   magic shop and sign/note shop.            |     \n"+
"            |                                             |     \n"+
"            |    (Continually adding fun new items)       |     \n"+
"            |                                             |     \n"+
"          _____________________________________________   |     \n"+
"         /                                            /   /     \n"+
"         \____________________________________________\__/      \n\n");
  return 1;
}

query_value() { return 0; }

query_weight() { return 1; }

get() { return 1; }

drop() { return 0; }

id(str) { return str=="scroll"; }
