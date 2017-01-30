/*
 * This object is _required_ to get into the fortress.
 */

reset(arg){
  if(arg) return;
}

id(str){
  return str == "key" || str == "fortress_key" || str == "rune key" ||
  str == "rune";
}

long(){
  write(
  "The rune key is a small twisted piece of metal covered with\n"+
  "the indeciphrable symbols of magic.\n");
  return;
}

short(){
  return "The Rune Key";
}

get() {
  return 1;
}

query_weight() {
  return 3;
}

query_value() {
  return 500;
}

query_save_flag() {
  return 1;
}

