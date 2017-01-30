/* spock.c: a tribute to spock, cuz he's the fucking man */
short() { return "A marvelously crafted granite statue"; }
id(str) { return str == "statue" || str == "granite statue" || str == "crafted granite status" || str == "spock"; }
get() { write("You couldn't possibly pick this up!\n"); return 0; }
long() {
  write("A marvelously crafted granite statue, dedicated to the greatest and\n");
  write("most logical player this mud has ever seen, Spock. His granite ears\n");
  write("point perfectly vertical, and his right hand is raised with his\n");
  write("fingers parted. You stand in awe of such an amazing player.\n");
  write("By the sheer magnitude and power of this statue, you know in your\n");
  write("mind that the statue before you is of Nirvana's greatest player.\n");
  write("\nAt the base of the statue, there is an engraving.\n");
}
init() { add_action("read_me","read"); }
read_me(s) {
  if(s != "engraving" && !id(s)) return 0;
  write("The engraving clearly spells out the following words:\n");
  write("\tLive Long and Prosper.\n");
  return 1;
}
