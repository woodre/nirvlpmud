
long() {
write("An archery target.  This is a target that the novices\n"+
 "are using for target practice.  From the looks of these guys\n"+
  "need alot more practice still!\n");
}


query_weight() {
    return 666;
}


short() {
    return "A target";
}

id(str) {
  return str == "target" || str == "archery  target" || str == "target";
}

query_value() {
    return 50;
}


get() {
    return 1;
}

init() {
  add_action("read","read");
 }
read(str) {
  if(str == "necklace" || str == "amulet") {
  write("Stone of Comprehension.  To understand what\n"+
    "you might not without.\n\n"+
  "                      compliments of the managment\n");
  return 1;
  }
}
