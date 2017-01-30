/*
  shift_hp.h
*/

#include "defs.h"

/* --------------- shift hit points to spell points  --------------- */
shift_hp(str) {
  int tmp_amt, xfer_amt;
  if (!str) {
    write("Use: shift <# hp>\n");
    return 1;
  }
  if (MY_LEVEL < 15 || MY_GUILD_EXP < 670) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  xfer_amt = 0;
  if (sscanf(str, "%d", xfer_amt)!=1) {
    write("Use: shift <# hp>\n");
    return 1;
  }
  if (xfer_amt <= 0) {
    write("You must specify how much energy to send.  "+
          "Use: shift <# hp>\n");
    return 1;
  }
  if (MY_HIT_POINTS <= xfer_amt) {
    write("If you shifted that many hit points, you'd die!\n");
    return 1;
  }
  tmp_amt = MY_PLAYER->query_msp() - MY_SPELL_POINTS;
  if (xfer_amt > tmp_amt) xfer_amt = tmp_amt;

/* Do the transfer */
  MY_PLAYER->add_spell_point(xfer_amt);
  MY_PLAYER->add_hit_point(-xfer_amt);
write(BOLD+"You CONCENTRATE and exchange energy for magic!"+NORM+"\n");
MY_FANGS->tell_my_room(
  MY_NAME_CAP+" staggers and then looks tired and drained.\n");
return 1;
}
