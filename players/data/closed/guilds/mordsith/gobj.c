/*   The Mord-Sith Guild Object   */
/*   Created By Data   */
/*   Date   4/9/2004   */

int muffle;
query_muffle() { return muffle; }

status toggle_muffle(string arg) {
  if (muffle)
    muffle = 0;
  else 
    muffle = 1;

  return muffle;
}

#include <ansi.h>

extra_look(){
object who;
  who = environment(this_object())->query_name();
   if(environment() == this_player())
   write(HIK+"You are"+HIR+" bonded"+HIK+" to the Lord Rahl\n"+NORM);
   else
   write(HIK+who+" is"+HIR+" bonded"+HIK+" to her Lord Rahl\n"+NORM);
}

inherit "/obj/treasure.c";

reset(arg){
set_id("bond");
set_alias("bond");
set_long(HIK+"Data Rahl tells you: type '"+HIR+"bond"+HIK+"' for the help file!!\n"+NORM);
	set_weight(0);
	set_value(0);
     }

   drop(){
	write("You may not drop your Manual.\n");
	return 1;
}
	
query_save_flag(){
return 1;
}
init(){
	::init();
    add_action("toggle_muffle", "toggle");

  if (!environment(this_object()))
    return;

environment(this_object())->set_guild_name("Mord-Sith");

}




