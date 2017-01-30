/* command to stop no idle quitting */

#include "/players/forbin/define.h"

main() {
  this_player()->set_noidlequit();
  write(HIW+"No quitting tonight!\n"+NORM);
  write(HIW+"Ok.\n"+NORM);  
    return 1; 
}
 


