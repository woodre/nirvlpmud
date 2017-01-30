inherit"obj/weapon";

reset(arg) {

   if(!arg) {

   set_name("torch");
   set_weight(3);
   set_class(15);
   set_short("A propane torch");
   set_long("This is a powerful weapon, and can also be used to intimidate"+
" other\npeople.  To give it a blast, type 'flame'.  To blast a specific"+
" person,\ntype 'flame <player>'.\n");
/* Changed value from 1000 to 500 (on a lev.11 monster) */
   set_value(500);
   }
}

init() {
  ::init();

   add_action("flame_me","flame");

}

flame_me(str) {
   if(!str) {
   write("You crank up the propane torch, sending flames throughout the room."+
         "\n");
   say( capitalize(this_player()->query_name()) + " cranks up his propane "+
      "torch, nearly burning your eyebrows off!\n");
   return 1;
   }
   if(str) {
   object target;
   target=find_player(str);
   if(!present(target, environment(this_player()))) {
   write("That player is not in the room");
   return 1;
   }
   if(!living(target)) {
   return 0;
   }
   }
   say(capitalize(this_player()->query_name()) +" whips out his torch and"+
" shoots flames straight at "+ capitalize(target->query_name())+"!!!\n");
   write("You whip out your torch and shoot flames straight at "+
   capitalize(target->query_name()) + "!!!\n");
   return 1;
}
