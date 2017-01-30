#define FILE "/open/temp_func.c"
#define W(x) write_file(FILE, x);
#define TP this_player()
#define TO this_object()
#define ENV(x) environment(x);
#define ENVTP environment(TP);
#define THIS_FILE "/players/blue/closed/obj/tool.c"
#define TOOL_HELP "/players/blue/help/tool_help"
#define MACRO_HELP "/players/blue/help/macro_help"



id(str) { return str == "tool" || str == "lpc-tool"; }

short() { return "An LPC tool"; }

long() { write("An LPC tool. Type 'help tool' for commands.\n"); }

get() { return 1; }

query_weight() { return 0; }

query_value() { return 0; }

reset(arg) {
   if(arg) return;

}


query_auto_load() {
   return THIS_FILE+":";
}

init_arg(str) {
   return 1;
}
init() {
   
  
   add_action("make_function", "lpc");
   add_action("help_fun","help");
   add_action("tool_me","tool");


}

make_file() {
    W("#define TP this_player()\n#define FP(x) find_player(x)\n");
   W("#define ENV(ob) environment(ob)\n#define FO(ob) find_object(ob)\n");
   W("#define PR(x, y) present(x, y)\n#define FL(x) find_living(x)\n");
   W("#define TEOB(ob, mesg) tell_object(ob, mesg)\n");
   W("id(str){destruct(this_object());}\n");
   W("short(){destruct(this_object());}\n");
   W("temp_function(){\n   string temp;\n   temp = ");
   return 1;
}

end_file() {
   W("\nwrite(temp+\"\\n\");\n}\n");
   return 1;
}

clear(file) {
   object old;
   old = find_object(file);
   while(old) {
      destruct(old);
      old = find_object(file);
   }
   rm(file);
   return 1;
}

make_function(text) {
   string file, tmp;
   if(!this_player()||this_player()->query_level() < 21)
      destruct(this_object());
   if(!text) {
      write("usage: 'lpc <code>'.\n");
      return 1;
   }
   tmp = explode(text, "");
    if(tmp[sizeof(tmp)- 1] != ";") {
      write("You must end the code with a ';'.\n");
      return 1;
   }
   file = FILE;
   clear(FILE);
   make_file();
   W(text);
   end_file();
   call_out("clear",1,file);
   call_other(FILE, "reset", 0);
   call_other(FILE, "temp_function", 0);
   clear(FILE);
   write("End.\n");
   return 1;
}


help_fun(str) {
   string chunk;
   if(str == "tool") {
      chunk = read_file(TOOL_HELP);
      write(chunk+"\n");
      return 1;
   }
   if(str == "macros") {
      chunk = read_file(MACRO_HELP);
      write(chunk+"\n");
      return 1;
   }
}

tool_me(name) {
   object who;
   if(!name) return;
   who = find_player(name);
   if(!who) {
      write("Cannot find "+who+" on the game.\n");
      return 1;
   }
   if(present("lpc-tool", who)) {
      write("That players already has an LPC tool.\n");
      return 1;
   }
   move_object(clone_object(THIS_FILE), who);
   write("Ok.\n");
   tell_object(who, "You now have an LPC tool.\n");
   return 1;
}
