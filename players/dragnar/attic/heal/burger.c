id(str) { return str=="burger" || str=="hamburger"; }
reset () {}
long () {write("A delicous hamburger.\n" +
      "You feel like gobbleing the whole thing.\n"); }
short () { return "A hamburger"; }
init() {
   add_action("gobble"); add_verb("gobble");
   add_action("drop_object"); add_verb("drop");
}
gobble(arg) {
   say(call_other(this_player(), "query_name") + "gobbles a burger.\n");
/* WHERE THE FUCK IS THE CALL TO EAT FOOD???? this is changed to a 3 point
heal. -Bp*/
   call_other(this_player(), "heal_self",3);
   write("You gobble the burger and throw the wrapper on the ground.\n");
   destruct(this_object());
   return 1;
}
get()   { return 1; }
query_weight() { return 0; }
query_value() { return 1000; }
drop_object(str) {
   if (str == "all") {
      drop_object("burger");
      return 0;
   }
   if (!str || !id(str))
      return 0;
   write("The hamburger falls to the ground and is ruined.\n");
   say(capitalize(this_player()->query_real_name()) + "drops the burger and it falls to the ground, ruined.\n");
   destruct(this_object());
   return 1;
}
