inherit "/obj/generic_heal.c";

#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("firewater");
  add_alias("bottle");
  add_alias("bottle of firewater");
  add_alias("water");
  add_alias("alcohol");
  set_short("Bottle of "+RED+"Firewater"+NORM+"");
  set_long("In the middle ages, fear and magic ruled the land. Against a backdrop\n\
of marauding barbarians, alchemists were on an endless quest to find\n\
the Elixir of Life. According to the legend, this potion would cure\n\
all ailments and lengthen life. Their powerful magic drink is said to\n\
have caused water to burn and man to breathe fire. Although no one\n\
knows whether life was lengthened, many claimed to have seen visions\n\
of flame breathing dragons. They called their potion "+RED+"Fire Water"+NORM+".\n");    
  set_type("drink");
  set_msg("You take a drink of the "+RED+"Firewater"+NORM+".\n");
  set_msg2(" takes a drink of the "+RED+"Firewater"+NORM+".\n");
  add_cmd("drink");
  add_cmd("gulp");
  add_cmd("sip");
  set_heal(50,50);
  set_charges(3);
  set_intox(15);
  set_value(550);
}

