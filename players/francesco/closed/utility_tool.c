#define tp this_player()
#define tl tp->query_level()
#define tpn tp->query_real_name()
#define master "/obj/wiz_tool_master.c"
#define to this_object()
#define ep environment(to)
#define eep environment(ep)
#include "/players/francesco/univ/ansi.h"

id(str) { return str == "fran_tool" ; }

short() { return capitalize(ep->query_real_name())+"'s "+
          "tool (used)"; }

long() { 
   write("This is Fran's utility tool.\n"+
         "Commands:\n"+
         "change_title     changes the title.\n"+
         "change_align     changes the alignment\n");
}

drop() { destruct(to); return 1; }
get() { if(tl > 20) return 1;  else destruct(to); return 1;}

init() {
  if(tl < 21) { destruct(to); return 1; }
  add_action("set_title", "change_title");
  add_action("set_align","change_align");
 }

set_title(){
tp->set_title("");
/*
tp->set_title("will never forget her.");
tp->set_title(HIW+"Th"+HIR+"e "+HIY+"Me"+MAG+"ch"+GRN+"an"+HIB+"ic"+HIG+"al "+HIB+"En"+GRN+"gi"+HIC+"ne"+WHT+"er"+NORM+"");
*/
return 1;
}

/*
set_align(){tp->set_al_title(HIW+"Associate Professor"+NORM);
return 1;}
*/
