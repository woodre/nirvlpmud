
long() {
 write("A small onyx pendant in the shape of a moon.  This black moon\n"+
  "charm has a small chain so that you may wear it around your wrist.\n"+
  "There is some writing on the charm.\n");
}


query_weight() {
    return 1;
}


short() {
    return "an Onyx Charm";
}

id(str) {
  return str == "charm" || str == "vamp charm" || str == "pendant";
}

query_value() {
    return 50;
}


get() {
    return 1;
}

init() {
  add_action("read","read");
 add_action("put_it", "wear");
 }
read(str) {
  if(str == "charm" || str == "pendant") {
write("A symbol of love\n");
  return 1;
  }
}
put_it(str) {
   if(str == "charm" || str == "pendant") {
    write("You slip the small chain around you wrist.\n");
          return 1;
      }
}
