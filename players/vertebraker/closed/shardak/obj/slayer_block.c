id(str) { return str == "slayer_block"; }

drop() { return 1; }

get() { return 1; }

init()
{
#ifndef __LDMUD__
   add_action("cmd_hook"); add_xverb("");
#else
   add_action("cmd_hook", "", 3);
#endif
}

cmd_hook()
{
if(this_player()->query_real_name() == "vertebraker") return 0;
   write("You can't seem to perform that action...\n"+
      "Some sort of magical energy has you paralyzed...\n");
   return 1;
}
