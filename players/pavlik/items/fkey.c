#define ME this_player()->query_real_name()
  object ob;

long() {
 write("This is a small silver key that belongs to your footlocker.\n"+
       "There is a small tag attached to the key that seems to have\n"+
       "some instructions written on it.\n");
}

reset(arg) {
  if(arg)
      return;
 call_other(this_object(),"set_save_flag",0);
}

query_weight() {
    return 5;
}

short() {
  return "Footlocker key";
}

id(str) {
    return str == "key";
}

query_value() {
    return 3000;
}

get() {
    return 1;
}
init(){
  add_action("drop_this","drop");
  add_action("read","read");
}

drop_this(str) {
      if(str == "key") {
   ob = clone_object("players/pavlik/items/box.c");
     ob->set_owner(ME);
      move_object(ob, environment(this_player()));
       move_object(this_object(), ob);
       destruct(this_object());
  write("You pick a good spot for your footlocker and place it\n"+
   "on the ground before you.  The footlocker magically anchors\n"+
   "itself to the ground here, and the lid opens for you.\n");
            return 1;
       }
}
read(str) {
  if(str == "tag" || str == "key") {
write("This is the key to your own personal footlocker!\n"+
 "Once you have purchased a foot locker, it is your to keep.\n"+
 "The locker operates when you drop the key on the ground\n"+
 "(cmd: drop key).  Your locker will magically appear in front\n"+
 "of you.  Once you have chosen the spot for your locker you will\n"+
 "Not be able to move it.  You are the only one that can see what\n"+
 "is in your locker and you are the only one who can take or put\n"+
 "items in or out of it.  The locker can hold an enormous amount\n"+
 "of weight.  The lockers last for as long as the game is up,\n"+
 "but if the game crashes or reboots, your locker and all the items\n"+
 "in it will disappear. \n"+
 " one last note: Dropping several lockers in the same room may result\n"+
 "in complications.  You may not be able to access the desired box,\n"+
 "but only be able to get to the last one dropped in that room.\n");
     return 1;
      }
}

