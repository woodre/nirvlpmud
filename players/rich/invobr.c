short() {
  return;}
long() {
  return;}
id(str) {
   return str=="fake inv";
}
get() {
  return 1;
}
drop(str) {
if (str=="all") {
  destruct(this_object());
  return 1;
  }
 return 1;
}

query_auto_load() {
     return "players/rich/invob.c:";
  }
init() {
     add_action("look" ,"look");
     add_action("l", "l");
      }
look() {
  write("You are in a giant vat of pudding.\n");
  write("You have a feeling of something oozing into your pants.\n");
  write("The only exit is get lost schmuck.\n");
  return 1;
 }
l() {
  if (this_player()->query_real_name()=="rich") {
  tell_object(this_player(),environment(this_player())->long());
  return 1;
  }
   write("You are in a giant vat of pudding.\n");
   write("You have a feeling of something oozing into your pants.\n");
   write("The only exit is get lost schmuck!!!\n");
   return 1;
  }
