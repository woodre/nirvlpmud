/*
  shift_hp.h
*/

#include "/players/eurale/defs.h"

/* --------------- shift hit points to spell points  --------------- */
shift_hp(str) {
  int tmp_amt, xfer_amt, loss, bpcost;

if(!str) {
  write("Use: shift <# hp>\n");
  return 1; }

if(TPL < 12 || TPGEXP < 668 || TP->query_attrib("int") < 16) {
  write("You lack the skills to use that ability.\n");
  return 1; }

xfer_amt = 0;
if(sscanf(str, "%d", xfer_amt) != 1) {
  write("Use: shift <# hp>\n");
  return 1; }

if(xfer_amt <= 0) {
  write("You must specify how much energy to shift.  "+
        "Use: shift <# hp>\n");
  return 1; }

if(TPHP <= xfer_amt) {
  write("If you shifted that many hit points, you'd die!\n");
  return 1; }

bpcost = find_bpcost(xfer_amt);

if(PFANGS->query_BLOODPTS() < bpcost) {
  write("You lack the blood energy to do that.\n");
  return 1; }

tmp_amt = TP->query_msp() - TPSP;
if(xfer_amt > tmp_amt) xfer_amt = tmp_amt;
loss = xfer_amt/10;

/* Do the transfer */
TP->add_spell_point(xfer_amt - random(loss));
TP->add_hit_point(-xfer_amt);
PFANGS->add_BLOODPTS(-bpcost);
write(BOLD+"You CONCENTRATE and exchange energy for magic!"+NORM+"\n");
FANGS->tell_my_room(
  capitalize(TPRN)+" staggers and then looks tired and drained.\n");
return 1;
}

find_bpcost(int num) {
  if(!num) return;
  switch(num) {
    case 1..25: return 1; break;
    case 26..50: return 2; break;
    case 51..75: return 3; break;
    case 76..100: return 4; break;
    case 101..125: return 5; break;
    case 126..150: return 6; break;
    case 151..175: return 7; break;
    case 176..200: return 8; break;
    case 201..225: return 9; break;
    case 226..250: return 10; break;
    case 251..275: return 11; break;
    case 276..300: return 12; break;
    case 301..325: return 13; break;
    case 326..350: return 14; break;
    default: return 0; break;
  }
  return 0;
}
