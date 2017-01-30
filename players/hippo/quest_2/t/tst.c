#define TP this_player()
#define ENVTO environment(this_object())
string name;

id(str) { return str == name; }
reset(arg) {
  if(!arg) {
      name="test";
  }
  return;
}
long() {
  write("just some test object\n");
}
short() { return name; }
get() { return 1; }
drop() { return 0; }
value() { return 0; }
init() {
  add_action("add","add");
}
add(arg) {
   string obj;
   int tmp;
  if(!arg) { 
     write("Huh?");
      return 0;
   }
   tmp=sscanf(arg,"%s",obj);
  write("Obj: "+obj+"\n");
   if(tmp<1) { write("add what?\n"); }
   if(!present(obj,ENVTO)) {
  write("Obj: "+obj+"\n");
      write("That is not here.\n");
  } else { write("Ok, found "+obj+"\n"); }
  return 1;
}
