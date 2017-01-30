#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object ob;
	int num, corpse_check, mult;
	
	ob = present("corpse", environment(User));
	
	if(!ob) ob = present("corpse", User);
	
	if(!ob) {
	notify_fail("There is no corpse present.\n"); return 0; }
	num = ((int) ob->query_exp_worth() / 1000 + ( (int)ob->heal_value() * 5 ));
        if( num > 1000 )
          num = 1000;
	write("You lift the "+ob->short()+" into the air.\n\n");
	say(User->query_name()+" lifts the "+ob->short()+" into the air.\n\n");
	tell_room(environment(User),BOLD+"\tA WHIRLWIND APPEARS BEFORE YOU!\n\n"+OFF);
	tell_room(environment(User),"Sand swirls away...\n");
	corpse_check = !ob->query_inv_dervish_corpse();
  destruct(ob);
  
	if(str && (str == "to the sand" || str == "to the sands")) {
	  if( corpse_check ) {
            PO->add_sand_points(num);
#if 0
  write("SP: "+num+"\n");
#endif
            write(BOLD+"\nThe Sand receives your sacrifice.\n\n"+OFF);
          }
    else
      write("\nThe sands "+HIR+"reject"+NORM+" your offering.\n\n");
	   return 1; 
  }
  
	User->heal_self(num);
	return 1; }
