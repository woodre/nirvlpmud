short() { return "A BIG BRIGHT warning sign (READ IT!!!)"; }
id(str) { return str == "sign" || str == "warning sign"; }
long()  {
  write("This warning sign was put here due to the shack. The shack contains\n");
  write("the most severe monster on the MUD. All I can say is, if you enter the\n");
  write("shack, you risk death (90% chance).\n");
  write("However, if you manage to kill what it contains, the rewards are worth\n");
  write("your time.\n");
  return 1;
}
init() { add_action("read", "read");
}
read(str) { if(id(str)) return long(); }
