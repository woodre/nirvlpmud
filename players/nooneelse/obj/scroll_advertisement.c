/*
  scrolladvertisement.c
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
"             /                                             /  \\ \n"+
"            |                                             |___/ \n"+
"            |                                             |     \n"+
"            |   Check out Nooneelse's Souvenir Shop!      |     \n"+
"            |                                             |     \n"+
"            |   From the clearing west of the church,     |     \n"+
"            |   go north to the end of the mines, then go |     \n"+
"            |   west twice.                               |     \n"+
"            |                                             |     \n"+
"            |   There, you will find the Restaurant/Pub,  |     \n"+
"            |   Pie Shop, Souvenir Ship and Sign/Note     |     \n"+
"            |   Shop.                                     |     \n"+
"            |                                             |     \n"+
"            |   The Magic Shop will open soon.            |     \n"+
"            |   (Scrolls, potions, rods, wands, staves,   |     \n"+
"            |    magic weapons, magic armor!)             |     \n"+
"            |                                             |     \n"+
"            |    (Continually adding fun, new items)      |     \n"+
"            |                                             |     \n"+
"          _____________________________________________   |     \n"+
"         /                                            /   /     \n"+
"         \\____________________________________________\\__/      \n\n");
  return 1;
}

query_value() { return 1; }

query_weight() { return 1; }

get() { return 1; }

drop() { return 0; }

id(str) { return str=="scroll" || str=="nooneelse ad scroll"; }
