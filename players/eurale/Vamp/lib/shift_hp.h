/*
  shift_hp.h
*/

#include "/players/eurale/defs.h"

/* --------------- shift hit points to spell points  --------------- */
shift_hp(str) {
  int tmp_amt, xfer_amt;

if(!str) {
  write("Use: shift <# hp>\n");
  return 1; }

if(TPL < 12 || TPGEXP < 668 || TP->query_attrib("int") < 16) {
  write("You lack the skills to use that ability.\n");
  return 1; }

  xfer_amt = 0;
if(sscanf(str, "%d", xfer_amt)!=1) {
  write("Use: shift <# hp>\n");
  return 1; }

if(xfer_amt <= 0) {
  write("You must specify how much energy to send.  "+
        "Use: shift <# hp>\n");
  return 1; }

if(TPHP <= xfer_amt) {
  write("If you shifted that many hit points, you'd die!\n");
  return 1; }

tmp_amt = TP->query_msp() - TPSP;
if(xfer_amt > tmp_amt) xfer_amt = tmp_amt;

/* Do the transfer */
TP->add_spell_point(xfer_amt);
TP->add_hit_point(-xfer_amt);
write(BOLD+"You CONCENTRATE and exchange energy for magic!"+NORM+"\n");
EFANGS->tell_my_room(
  capitalize(TPRN)+" staggers and then looks tired and drained.\n");
return 1;
}
