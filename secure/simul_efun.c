/*
 * $Author: rumplemintz $
 * $Revision: 1.0 $
 * $Date: 2015/02/17 13:36:23 $
 *
 */

#pragma strict_types
#pragma no_clone
#pragma no_inherit

#include "/include/config.h"
#include "/include/mudlib.h"

#include "/secure/simul/add_ansi.c"
#include "/secure/simul/compat.c"
#include "/secure/simul/add_worth.c"
#include "/secure/simul/base_file.c"
#include "/secure/simul/create_wizard.c"
#include "/secure/simul/log_file.c"
#include "/secure/simul/living_handlers.c"
#include "/secure/simul/living.c"
#include "/secure/simul/rooms.c"
#include "/secure/simul/rtime.c"
#include "/secure/simul/snoop.c"
#include "/secure/simul/subst.c"
#include "/secure/simul/type_handlers.c"
#include "/include/fn/shout.h"

void shout(string str) {
  check_shout(str, 0);
}

