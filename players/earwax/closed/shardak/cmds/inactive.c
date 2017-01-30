/* Override the inactive command.  No inactive pussies in this guild.
 * -Earwax
*/
#include "../include/ansi.h"

status
main(string arg) 
{

  write("The voice of Shardak whispers in your ear...\n\
"+RED+"          \"I have no use for inactive members of my army.  If you wish to go\n\
            \inactive, you must leave this guild\".\n"+NORM);

  write(HIR+"NOTE: NO restorations will be given if you leave the guild.\n"+NORM);
  return 1;

}
