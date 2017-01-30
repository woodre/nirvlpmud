inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("brush");
   set_short("A pink brush");
   set_long("The prety pink brush has flowery designs along the handle.\n");
   set_value(100);
   set_weight(1);
}

init() {
   ::init();
   add_action("brush","brush");
}

brush(str) {
   if(!str || str != "hair") {
      notify_fail("You brush the air rapidly, but it doesn't accomplish anything.\n");
      return 0;
   }
   write("You brush your hair with the pretty pink brush.\n"+
         "Don't you look just beautiful.\n");
   say(this_player()->query_name()+" brushes "+this_player()->query_possessive()+" hair with a pretty pink brush.\n");
   return 1;
}
