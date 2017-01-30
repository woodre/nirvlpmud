 
id(str) { return str == "sign"; }
 
short() {
  return "A sign";
}
 
long() { 
  write("Maybe you should read it!\n");
  return 1;
}
 
query_weight() { return 10000; }
query_value() { return 0; }
 
init() {
  add_action("read_it","read");
}
 
read_it(arg) {
  if(!arg || arg != "sign") {
    write("Read What?\n");
    return 1;
    }
  write("\n\n");
  write("The sign reads:\n\n");
  write("Welcome to Detroit, where the weak are killed and eaten.\n");
  write("\n\n");
  return 1;
}
  

