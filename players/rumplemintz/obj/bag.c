#ifdef __LDMUD__

#include <persistence.h>

inherit "complex/container";

#define MAX_WEIGHT 6

private string bag_long()
{
  if (first_inventory(this_object()))
    return
      capitalize(describe(this_object()))+
      ". There is something in it.\n";
  else
    return
      capitalize(describe(this_object()))+
      ". You can put things into it.\n";
}

void
configure()
{
  container::configure();
  remove_persistent_variable("long");
  set_persistence("obj/bag", PER_KEEP_VARS);
  set_long(#'bag_long);
  set_id(({"bag"}));
  set_name("bag");
  set_short("bag");
  set_value(12);
  set_max_encumbrance(MAX_WEIGHT*2500);
  set_encumbrance(2500);
}
#endif

