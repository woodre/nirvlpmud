#include "../defs.h"
#include "/players/pestilence/define.h"
main(str)
{
  string pre;

  if(!str) {
    write("Say What?\n");
    return 1;
  }

  if(!CHAND) {
    write("The guild line is currently down.\n");
    return 1;
  }

  pre = HIK+"<"+HIR+"DARK"+NORM+HIK+"> ";
  if( str[0] == ':' )
    pre += NORM;
  else
    pre += this_player()->query_name() + " says: "+ HIK;

  CHAND->channel_message( CHAN_NAME, str, pre );
  return 1;
}
