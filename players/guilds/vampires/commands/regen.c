/*
  Change spell points to hit points
*/

#include "/players/eurale/defs.h"

regen_hp(str) {
  int tmp_amt, xfer_amt, loss, bcost;

if(!str) {
  write("Use: regen <# sp>\n");
  return 1; }

if(TPL < 19 || TPGEXP < 670 || TP->query_attrib("int") < 25) {
  write("You lack the skills to use that ability.\n");
  return 1; }

xfer_amt = 0;
if(sscanf(str, "%d", xfer_amt) != 1) {
  write("Use: regen <# hp>\n");
  return 1; }

if(xfer_amt <= 0) {
  write("You must specify how much energy to shift.  "+
        "Use: regen <# hp>\n");
  return 1; }

if(TPSP <= xfer_amt) {
  write("You don't have that much magic to transfer.\n");
  return 1; }

bcost = find_bcost(xfer_amt);

if(PFANGS->query_BLOODPTS() < bcost) {
  write("You lack the blood energy to do that.\n");
  return 1; }

tmp_amt = TP->query_mhp() - TPHP;
if(xfer_amt > tmp_amt) xfer_amt = tmp_amt;
loss = xfer_amt/10;

/* Do the transfer */
TP->add_hit_point(xfer_amt - random(loss));
TP->add_spell_point(-xfer_amt);
PFANGS->add_BLOODPTS(-bcost);
write(HIR+"You CONCENTRATE and exchange magic for ENERGY!"+NORM+"\n");
FANGS->tell_my_room(
  capitalize(TPRN)+" staggers and then looks stronger.\n");
return 1;
}

find_bcost(int num) {
  if(!num) return;
  switch(num) {
    case 1..25: return 2; break;
    case 26..50: return 4; break;
    case 51..75: return 6; break;
    case 76..100: return 8; break;
    case 101..125: return 10; break;
    case 126..150: return 12; break;
    case 151..175: return 14; break;
    case 176..200: return 16; break;
    case 201..225: return 18; break;
    case 226..250: return 20; break;
    case 251..275: return 22; break;
    case 276..300: return 24; break;
    case 301..325: return 26; break;
    case 326..350: return 28; break;
    case 351..375: return 30; break;
    case 376..400: return 32; break;
    case 401..425: return 34; break;
    case 426..450: return 36; break;
    case 451..475: return 38; break;
    case 476..500: return 40; break;
    default: return 0; break;
  }
  return 0;
}
