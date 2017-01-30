#include "../defs.h"
#include "/players/pestilence/ansi.h"
status main()
{
  write("<"+HIK+"Dark Order"+NORM+"> Guild Status Saved.\n");
  previous_object()->save_me();
  CHAND->remove_channel( CHAN_NAME, this_player() );
  return 0;
}
