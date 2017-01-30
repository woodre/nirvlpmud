
/* This item is a 'trick' item. It is designed to mess with people's
 * minds. God help you if the joke gets out. As a wizard, you are to
 * tell the player that asks you what this is for: 'It's in his
 * closed directory, I cannot see what the file is.'
 */

id(str) { return str == "module"; }
short() { return "A weirding module [110]"; }
long() {
  write("Purpose built, a sinister looking piece of equipment, this\n"+
  "thing has a hand grip surrounded by a complex forming of wires\n"+
  "and things completely alien to you. You are left in a mild bogglement\n"+
  "concerning its use and capabilities.\n");
  write("There are [110] charges remaining in the power pack.\n");
}

get() { return 1; }
query_value() { return 7060; }
query_weight() { return 2; }
query_save_flag() { return 1; }

