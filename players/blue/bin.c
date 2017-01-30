#define PATH "/players/blue/"
#define VERB query_verb()

id(str) { return str == "bin"; }
short() { return "A test bin"; }
get() { return 1; }

reset(arg) {
   if(!arg) {



   }
}

init() {
   string files, file;
   int size, n;
   if(this_player()->query_level() < 20) return;
   files = get_dir(PATH);
   size = sizeof(files);
   n = 0;
   while(n < size) {
      file = explode(files[n], "");
      if(file[0] == "_") {
         file -= ({ file[0] });
         file -= file[sizeof(file) - 1];
         file -= file[sizeof(file) - 1];
         file = implode(file, "");
         write("Adding action for "+file+"...\n");
         add_action("cmd_hook", file);
      }
      n++;
   }
}


cmd_hook(str) {
   write("Here.\n");
   write(PATH+"_"+VERB+".c" + "    command_"+VERB +"\n");
   if(!call_other(PATH+"_"+VERB+".c", "command_"+VERB, str))
      return 0;
   return 1;
}

