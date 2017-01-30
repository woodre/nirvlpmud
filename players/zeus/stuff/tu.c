#include <ansi.h>
inherit "/obj/treasure.c";

reset(arg){
  set_long("type 'tu <str>' to send a tell to zeus.\n");
}

id(str){ return str == "tu"; }
short(){ if(this_player() == environment()) return "tu"; return 0; }
get(){ return 0; }
drop(){ return 1; }
can_put_and_get(){ return 0; }

init(){  ::init();  add_action("tu", "tu");  write(HIG+long_desc+NORM); }

tu(str){
  object god;
  if(!str) return 0;
  if(!present(this_object(), this_player())) return 0;
  if(!(god = find_player("zeus"))) return(notify_fail("not on\n"),0);
  if(!god->query_interactive()) return(notify_fail("dc'd\n"),0);
  tell_object(god, capitalize((string)this_player()->query_real_name())+
    " tells you: "+str+"\n\n");
  return 1;
}
