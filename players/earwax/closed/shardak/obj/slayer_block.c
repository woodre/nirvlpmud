id(str) { return str == "slayer_block"; }

drop() { return 1; }

get() { return 1; }

init()
{
   add_action("cmd_hook"); add_xverb("");
}

cmd_hook()
{
if(this_player()->query_real_name() == "linus") return 0;
   write("You can't seem to perform that action...\n"+
      "Some sort of magical energy has you paralyzed...\n");
   return 1;
}
