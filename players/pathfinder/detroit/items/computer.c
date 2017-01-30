inherit "obj/treasure";
id(str) { return str == "computer"; }
 
short() {
  write("A Computer.\n");
  }
  
long() {
  write("You look at the computer.  It is the computer that is used for making\n");
  write("reservations and looking up specific information on wizards areas.\n");
  write("If you would like to find out more about a specific wizard's area\n");
  write("just type 'info <wizard>' and it will give you all the information\n");
  write("that we have.\n");
  }
  
get() { return 0; }
 
query_weight() { return 10000; }
 
query_value() { return 0; }
 
 
init() {
  add_action("info_wiz", "info");
}
 
info_wiz(str) {
  if(!str) {
    write("Which Wizard's castle do you want information on?\n");
    return 1;
    }
  cat("/open/info/"+str+"/"+str+".nfo");
  write("Thats all the information we have on "+capitalize(str)+"'s castle for now.\n");
  return 1;
}

