object destination;

id(str) {
   return str == "scroll" || str == "teleport" || str == "scroll of teleport";
}
short() { return "scroll of teleport"; }
long() {
   if(!destination) {
      write("A scroll of teleport:\n");
      write("To use the scroll properly, first go to the place where you\n");
      write("later want to teleport to.  Type \"set scroll\" to enscribe\n");
      write("the scroll.  When you want to teleport back to the location,\n");
      write("type \"use scroll\" and you will be magically moved.\n");
   }
   if(destination) {
      write("There is something written on the scroll:\n");
      write("\n");
      destination->long();
   }
}
init() {
   add_action("read_scroll","read");
   add_action("set_destination","set");
   add_action("use_scroll","use");
}

/*  read_scroll(string str) - same as long description  */
read_scroll(str) {
   if(!id(str)) return;
   long();
   return 1;
}

/*  set_destination(string str) - set the current environment of the player */
/*     to the place to teleport to.  after it is set it cannot be changed.  */
set_destination(str) {
   if(!id(str)) return;
   if(environment() != this_player()) {
      tell_object(this_player(),"You must get it first.\n");
      return 1;
   }
   if(destination) {
      write("The scroll is already enscribed with a destination.\n");
      return 1;
   }
   destination = environment(this_player());
   if(!destination) {
      write("This shouldn't happen.  Alert Omega by mail.\n");
      return 1;
   }
   write("Strange runes magically appear on the scroll.\n");
   return 1;
}

/*  use_scroll(string str) - if a destination is set, then move the player */
/*     to the destination.                                                 */
use_scroll(str) {
   if(!id(str)) return;
   if(environment() != this_player()) {
      tell_object(this_player(),"You must get it first.\n");
      return 1;
   }
   if(!destination) {
      write("Nothing happens.\n");
      return 1;
   }
   say(this_player()->query_name()+
      " disappears in a blinding flash of light!\n");
   write("You read the scroll and are suddenly elsewhere!\n");
   move_object(this_player(), destination);
   this_player()->glance();
   say(this_player()->query_name()+
      " appears from out of the blue!\n");
   write("The scroll has crumbled to dust.\n");
   destruct(this_object());
   return 1;
}
get() { return 1; }
query_value() { return 15; }
query_weight() { return 1; }
reset(arg) {
   if(arg) return;
}
