#define testers ({ "verte", "maledicta", "zeus", "wocket", "fakir", "boltar", "feldegast", "vertebraker", "vital", "reflex" })
/*
 * SERVANTS shows all registered guildmembers
 */
#pragma strict_types
#include "../include/def.h"
#include "../include/std.h"

#include "../include/daemons.h"
inherit CMD;

status
main()
{
  string *output;
  int i, siz;

  output = (string*) HIERARCHYD->dump_members();

  siz = sizeof(output);

  for (i = 0; i < siz; i++)
    tell_object(this_player(),output[i]);

  return 1;
}
