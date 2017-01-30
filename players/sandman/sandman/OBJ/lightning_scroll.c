id(str) { return str == "scroll" || str == "scroll of lightning"; }

init() {
   add_action("read","read");
   add_action("lightning","lightning");
}

read(str) {
   write("This scroll will inflict damage upon a foe. To use this scroll,\n"
+ "type 'lightning <monster name>.\n");
   return 1;
}

lightning(str) {
   object target;
   if(!str) {
      write("You must specify a target!\n");
      return 1;
   }
   target = present(str, environment(this_player()));
   if(!target) {
     write("Your intended target is not in the room.\n");
     return 1;
   }
   if(target->query_npc() == 0) {
     write("This spell does not work on player...sorry...*grin*.\n");
     return 1;
   }
   write("You cast a lightning bolt at your foe!\n");
   write("The scroll crumbles to dust.\n");
   target->hit_player(25);
   target->attacked_by(this_player());
   destruct(this_object());
   return 1;
}

get() {
   return 1;
}

query_weight() {
   return 1;
}

long() {
   write("A crumpled parchment with red runes upon it.\n");
}

short() {
   return "scroll of lightning";
}
