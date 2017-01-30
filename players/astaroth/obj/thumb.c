id(str) { 
    if ((str == "thumb") || (str == "device"))
                          return 1;
    return 0;
}
 
reset(arg) {
}
 
long() {
  write("This is a highly sophisticated sub-etha signalling device commonly\n");
  write("known as an electronic thumb.  It has been found by many to be a\n");
  write("good way to hitch a ride from passing spaceships, though who knows\n");
  write("what a spaceship would be doing in this world.\n");
}
 
short() {
     return "A sub-etha signalling device";
}
 
query_value()
{
    return 250;
}
 
init() {
    add_action("use"); add_verb("use");
    add_action("use"); add_verb("activate");
}
 
use(str) {
 
   if (str != "thumb")
      return 0;
   if (call_other(environment(this_player()),"hitchhike") == 0) {
      write("There are no ships within signalling range.\n");
      return 1;
   }
   return 1;
}
 
get() {
    return 1;
}
 
query_weight() {
    return 1;
}
