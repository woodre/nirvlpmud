/* Can be purchased for 1800 from Randal at the Qual'tor Market Square */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";
string Color;
int A;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  A = random(6);
  if(A == 0) {Color = HIR; }
  if(A == 1) {Color = HIG; }
  if(A == 2) {Color = HIY; }
  if(A == 3) {Color = HIB; }
  if(A == 4) {Color = HIM; }
  if(A == 5) {Color = HIC; }

  set_name("shot");
  add_alias("pack");
  add_alias("shots");
  add_alias("jello shots");
  add_alias("jello");
  set_short("A pack of "+Color+"jello shots"+NORM);
  set_long("A pack of jello shots. You can "+HIW+"shoot"+NORM+" the jello shots\n"+
           "down for a warm, yet drunken, feeling.\n");

  set_msg("You shoot down a "+Color+"jello shot"+NORM+" and smile.\n");
  set_msg2(" shoots down a "+Color+"jello shot"+NORM+" and grins wickedly\n");
  add_cmd("shoot");
  set_type("shot");

  set_heal(50,50);
  set_charges(3);
  set_intox(14);
  set_value(175);
}

query_save_flag(){
  return 1;
  }
