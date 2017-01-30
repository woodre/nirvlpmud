/* bones.c: small collection of bones */
int val;
short() { return "A small pile of bones"; }
long()  {
  write("A small grouping of bones, apparently from whatever the creature ate last.\n");
  write("After a careful examination, you notice that they are about the size of you,\n");
  write("less the gnawed off ends.\n");
  write("They're probably worth something to somebody.\n");
  return 1;
}
query_value() { return val; }
get() { return 1; }
id(str) { return str == "bones" || str == "pile of bones" || str == "small pile of bones"; }
reset(arg) {
  if(arg)
    return ;
  val = 800+random(800);
}
