/* Used formula from heal1 and heal3 only healing sps 1 sp point = 2/3 of a regular heal point
based on that i calculated cost 2 ways
took total tox 14*3=42/total heal 150 = .28 which costs 12 per heal point
using the 2/3 of 150 = 100 so 12 * 100 = 1200
also used tox 14*3= 42/ 2/3 of total heal 150 =100 which was 42/100 = .42 at scale
8 pt per heal point
8 *150 total heal = 1200 */
inherit "/obj/generic_heal.c";
#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name(""+BLU+"blackberry pie"+NORM+"");
  add_alias("blackberry pie");
  add_alias("blackberry");
  add_alias("berry");
  add_alias("pie");
  add_alias("berry pie");
  set_short(""+BLU+"a blackberry pie"+NORM+"");
  set_long("This is a "+BLU+"blackberry pie"+NORM+".\n"+
           "It looks like it would taste extremely good.\n");    
  set_type("eat");
  set_msg("You take a big bite of the "+BLU+"blackberry pie"+NORM+".\n");
  set_msg2(" takes a big bite of the "+BLU+"blackberry pie"+NORM+".\n");
  add_cmd("bite");
  add_cmd("eat");
  set_heal(0,50);
  set_charges(3);
  set_stuff(7);
  set_soak(7);
  set_value(400);
}
query_save_flag(){
  return 1;
  }
