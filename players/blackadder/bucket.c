int full;

id(str) {
   if (str == "bucket" && full)
      return 1;
   return str == "bucket";
}

short() {
   if (full)
      return "a bucket of long island ice tea";
   return "empty bucket";
}

/* The shop only buys empty bottles ! */

query_value()
{
   if (!full) return 10;
   return 0;
}

long() {
   write(short() + ".\n");
}

reset(arg) {
   if (arg)
      return;
   full = 1;
}

drink(str)
{
   if (str && str != "bucket" && str != "from bucket")
      return 0;
   if (!full)
      return 0;
   if (call_other(this_player(),"query_level") < 10) {
      write("Try again when you're level 10.\n");
      return 1;
   }
   if (!call_other(this_player(), "drink_alcohol", 10)) {
      write("You are already drunk, compadre!\n");
      return 1;
   }
   full = 0;
   write("Whoa!  That hit the spot!\n");
   say(call_other(this_player(), "query_name", 0) +
      " slams a bucket of long island ice tea!\n");
   call_other(this_player(),"heal_self",20);
   return 1;
}

init() {
   add_action("drink","drink");
}

get() {
   return 1;
}

query_weight() {
   return 1;
}
