#include "/players/mokri/define.h"

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("this");
   set_short("a this");
   set_long("blah\n");
}

init() {
   write("[]> ");
   input_to("cmd");
}

cmd(what) {
   string comm, arg;
   
   
   if(sscanf(what,"%s %s",comm,arg));
   if(!arg) comm = what;
   if(file_size("/players/mokri/cmds/_"+comm+".c") > 1)
      call_other("/players/mokri/cmds/_"+comm,"main",arg);
   else
      command(what,TP);
   write("[]> ");
   input_to("cmd");
   return 1; }

drop() { return 1; }
