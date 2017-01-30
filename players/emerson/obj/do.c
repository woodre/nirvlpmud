/* Primitive lag-fighter, created by Dune (march 1995) */
#define TP   this_player()
short() { return "Mr. Do"; }
long() { 
  write("This is a speedster.  Usage: do <cmd1, cmd2, etc.>\n");
  write("Maximum of 8 different commands, seperated by commas.\n");
  }id(str) { return str == "do"; }
get() { return 1; }
drop() { return 0; }

init() { add_action("do_cmds","do"); }

do_cmds(string str) {
  string c1, c2, c3, c4, c5, c6, c7, c8;
  if(this_player()->query_level() <= 20) {
    write("Mr. Do does not serve people like you!\n");
    return 1; }
  if(!str) return 0;
  if(sscanf(str, "%s, %s, %s, %s, %s, %s, %s, %s", 
                 c1, c2, c3, c4, c5, c6, c7, c8) == 8) {
    command(c1, TP); command(c2, TP); command(c3, TP); command(c4, TP);
    command(c5, TP); command(c6, TP); command(c7, TP); command(c8, TP);
    return 1; }
  if(sscanf(str, "%s, %s, %s, %s, %s, %s, %s", 
                 c1, c2, c3, c4, c5, c6, c7) == 7) {
    command(c1, TP); command(c2, TP); command(c3, TP); command(c4, TP);
    command(c5, TP); command(c6, TP); command(c7, TP);
    return 1; }
  if(sscanf(str, "%s, %s, %s, %s, %s, %s", 
                 c1, c2, c3, c4, c5, c6) == 6) {
    command(c1, TP); command(c2, TP); command(c3, TP); command(c4, TP);
    command(c5, TP); command(c6, TP);
    return 1; }
  if(sscanf(str, "%s, %s, %s, %s, %s", c1, c2, c3, c4, c5) == 5) {
    command(c1, TP); command(c2, TP); command(c3, TP); command(c4, TP);
    command(c5, TP);
    return 1; }
  if(sscanf(str, "%s, %s, %s, %s", c1, c2, c3, c4) == 4) {
    command(c1, TP); command(c2, TP); command(c3, TP); command(c4, TP);
    return 1; }
  if(sscanf(str, "%s, %s, %s", c1, c2, c3) == 3) {
    command(c1, TP); command(c2, TP); command(c3, TP);
    return 1; }
  if(sscanf(str, "%s, %s", c1, c2) == 2) {
    command(c1, TP); command(c2, TP);
    return 1; }
  if(sscanf(str, "%s", c1) == 1) {
    command(c1, TP);
    return 1; }
  return 1;
}
