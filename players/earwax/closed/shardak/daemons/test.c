#include "../include/def.h"
#include "../include/daemons.h"

#define HIERARCHYD "players/earwax/closed/shardak/daemons/hierarchy"

void reset(status arg) {

  if (arg)
    return;

  HIERARCHYD->add_member("earwax","magus");
  HIERARCHYD->add_member("linus","magus");
  HIERARCHYD->add_member("mosobp","magus");
  HIERARCHYD->add_member("spyder","master");

}
