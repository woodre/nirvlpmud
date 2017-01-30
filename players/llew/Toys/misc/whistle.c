inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("lego whistle");
   set_alias("whistle");
   set_short("A lego whistle");
   set_long("A lego whistle from a police legoman.\n");
   set_value(50);
   set_weight(1);
}

init() {
   ::init();
   add_action("blow","blow");
}

blow(str) {
   if(!str || !id(str)) return 0;
   write("You blow hard into the lego whistle.\n");
   say(this_player()->query_name()+" blows hard into a lego whistle.\n");
   tell_room(environment(this_player()),"\n\tTWWEEEEEEEEEEEEEEET!!!!!\n\n\n");
   return 1;
}
