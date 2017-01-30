reset(arg){
  if(arg) return;
}

id(str) {
  return str == "opal" || str == "gem" || str == "demonbane_gem";
}

long(){
  write(
  "A small opal gemstone.  The opal is a magnificent stone that\n"+
  "reflects a rainbow of beautiful colors.  One side of the small\n"+
  "opal is completely flat, the rest of the stone is round.  There\n"+
  "is a small inscription on the flat side of the gem.\n");
  return;
}

short(){
  return "An Opal";
}

get() {
  return 1;
}

query_weight() {
  return 1;
}

query_value() {
  return 350;
}

query_save_flag() {
  return 1;
}

init() {
  add_action("read","read");
}

read(str) {
  if(id(str)) {
    write("There tiny lettering is faded, but you can read:\n");
    write("[de on an !]\n");
    return 1;
  }
}

