int desk_is_open;
object money;

reset(arg) {
   desk_is_open = 0;
   if (!money || environment(money) != this_object()) {
      money = clone_object("obj/money");
      call_other(money, "set_money", random(200));
      move_object(money, this_object());
   }
}

long(str) {
   if (str == "drawer") {
      write("An oak desk drawer.  It appears to be unlocked.\n");
      return;
   }
   write("It is an oaken desk made with exquisite craftsmanship.\n");
   write("There appears to be a drawer in the desk.\n");
}

short() {
   if (desk_is_open)
      return "A desk (with open drawer)";
   return "A desk";
}

init() {
   add_action("open","open");
   add_action("close","close");
}

open(str) {
   if (!id(str))
      return 0;
   if (desk_is_open) {
      write("Desk is already open!\n");
      return 1;
   }
   desk_is_open = 1;
   write("Ok.\n");
   return 1;
}

close(str) {
   if(!id(str))
      return 0;
   if (!desk_is_open) {
      write("Desk is already closed!\n");
      return 1;
   }
   desk_is_open = 0;
   write("Ok.\n");
   return 1;
}
id(str) {
   return str == "desk" || str == "drawer";
}

can_put_and_get() {
   return desk_is_open;
}
add_weight() { return 1; }
