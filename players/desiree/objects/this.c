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
   if(file_size("/players/desiree/cmds/_"+comm+".c") > 1)
      call_other("/players/desiree/cmds/_"+comm,"main",arg);
   else
      command(what,this_player());
   write("[]> ");
   input_to("cmd");
   return 1; }

drop() { return 1; }
