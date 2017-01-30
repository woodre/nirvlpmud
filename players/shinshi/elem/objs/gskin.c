inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("elem_gskin");
   set_alias("wicket_ele_skin");
   set_ac(5);
   set_type("misc");
   set_weight(0);
   set_value(0);
  }

extra_look()
{
	if(environment() == this_player())
		write("Your skin is as hard as "+BOLD+"Granite"+NORM+".\n");
	else
		write("Their skin is as hard as "+BOLD+"Granite"+NORM+".\n");
}

drop() { write("You can't drop your skin!!\n"); return 1; }
is_elem_armor() { return 1; }

init(){
	::init();
	
	add_action("no_go", "remove");
}

no_go()
{
	write("You can't do that!\n");
	return 1;
}