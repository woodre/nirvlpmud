inherit "obj/treasure";
int no_move, wait;
object move;
init() {
  add_action("movement","north");
  add_action("movement","east");
  add_action("movement","west");
  add_action("movement","south");
  add_action("movement","southwest");
  add_action("movement","southeast");
  add_action("movement","northwest");
  add_action("movement","northeast");
  add_action("movement","n",1);
  add_action("movement","s",1);
  add_action("movement","w",1);
  add_action("movement","e",1);
  add_action("movement","sw");
  add_action("movement","se");
  add_action("movement","nw");
  add_action("movement","ne");
  add_action("movement","up");
  add_action("movement","down");
  add_action("movement","u",1);
  add_action("movement","d",1);
  add_action("quit","quit");
  ::init();
 }
reset(arg) {
   if (arg) return;
   wait = 120; /* # of seconds */
   no_move = time() + wait;
   set_id("sglue");
   set_weight(0);
   set_value(0);
}
movement() {
   if (this_player()->query_attack()) {
     write("Somebody is attacking you!\nThe glue instantly disolves from"+
           "under your feet.\n");
     destruct(this_object());
     return 1;
   } else {
  if (no_move>=time()) {
 say(this_player()->query_name()+" tries to move but his feet are super glued to the ground.\n");
 write("Your feet are super glued to the floor, you can't move.\n");
 }
 if (no_move<time()) {
  destruct(this_object());
  }
 return 1;
  }
 }
quit() {
  destruct(this_object());
  }
