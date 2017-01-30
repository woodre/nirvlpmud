/* clone to player command */

#include "/players/forbin/define.h"

main() {
  string silence;
  if(present("please_leave_me_the_FuCK_AlONe", this_player())) {
    destruct(present("please_leave_me_the_FuCK_AlONe", this_player()));
    write(HIW+"Silence has been lifted...\n"+NORM);
      return 1;
  }
  silence = CO("/players/forbin/closed/silencer");
  MO(silence, this_player());
  write(HIW+"A Cloak of Silence envelopes you...\n"+NORM);
    return 1; 
}
