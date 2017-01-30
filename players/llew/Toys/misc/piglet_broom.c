inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("broom");
   set_short("A straw broom");
   set_long("A short handled broom made with straw and twine.\n"+
            "Not really much use unless you've some dirt around.\n");
   set_value(200);
   set_weight(1);
}

init() {
   add_action("sweep","sweep");
}

sweep() {
   write("You sweep vigorously, rearranging the dirt nicely.\n");
   say(this_player()->query_name()+" rearranged some dirt with "+this_player()->query_possessive()+" broom.\n");
   return 1;
}
