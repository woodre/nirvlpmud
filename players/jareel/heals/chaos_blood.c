#include "/players/jareel/ansi.h"
inherit "/obj/generic_heal.c";
#define TQL  (int)this_player()->query_level()
#define TQA  (int)this_player()->query_alignment()


void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("stone");
  set_short(BOLD+"[evilheal]"+NORM);
  set_long("Evil heal\n");
  set_type("evils");
  set_type_single("evil");
set_msg_precharges(HIW+"[");
set_msg_postcharges(NORM+HIW+"]"+NORM);
  set_msg("You mutter a few words.\n"+
          "A black aura washes over you, you feel sick.\n");
  set_msg2(" is washed by a black aura.\n");
  add_cmd("evil");
  set_heal(50,50);
  set_charges(3);
  set_soak(5);
  set_stuff(5);
  this_player()->add_alignment((TQA * 2 / (30 - TQL) - (TQL * 6)));
  set_value(0);
}

query_save_flag(){
  return 1;
  }
