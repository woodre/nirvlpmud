#include "/players/sami/mdefine.h"
inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("bomb");
   set_short("a small "+HIR+"bomb"+NORM+"");
   set_long("I KEEL YOU!.\n");
}


init() {
  add_action("drop_object", "drop");
  write(""+HIB+"[]"+HIG+"*"+HIB+"[]"+HIG+"*"+HIB+"[]"+HIY+">"+NORM+" ");
   input_to("cmd");
}


drop_object(str) {
    if (str == "all") {
        drop_object("bomb");
        return 0;
    }
    if (!str || !id(str))
        return 0;
    write("The bomb Explodes upon contact with the ground.\n");
    say(call_other(this_player(), "query_name") + " drops a armed bomb!\n");
    destruct(this_object());
    return 1;
}


cmd(what) {
   string comm, arg;
   
   
   if(sscanf(what,"%s %s",comm,arg));
   if(!arg) comm = what;
   if(file_size("/players/sami/misc/stuff/_"+comm+".c") > 1)
      call_other("/players/sami/misc/stuff/_"+comm,"main",arg);
   else
      command(what,TP);
   write(""+HIG+"[]"+HIY+"*"+HIG+"[]"+HIY+"*"+HIG+"[]"+HIB+">"+NORM+" ");
   input_to("cmd");
   return 1; }