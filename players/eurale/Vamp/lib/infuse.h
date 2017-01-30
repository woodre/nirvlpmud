/*
  infuse.h
*/

#include "/players/eurale/defs.h"

  /* infuse a vampire  */
infuse(str) {
  object target;
  string target_name;
  int sp_amt;

if(TPL < 19 || TPGEXP < 670) {
  write("You can't use that abilitiy yet.\n");
  return 1; }

sp_amt = 0;
if(sscanf(str, "%s %d", target_name, sp_amt) != 2) {
  write("Use: infuse <who> <sps>\n");
  return 1; }

target = find_player(target_name);
if(TP == target) {
  write("You cannot infuse yourself.\n");
  return 1; }

if(!target || target->query_invis() > 0) {
  write(capitalize(target_name)+" can't be found to infuse.\n");
  return 1; }

if(!present(target,ROOM)) {
  write(capitalize(str)+" must be in the room with you.\n");
  return 1; }

if(!present("vampire fangs", target)) {
  write(capitalize(str)+" isn't a vampire and can't be infused\n"+
          "with energy.\n");
  return 1; }

if(sp_amt <= 0) {
  write("You must specify how much energy to send.  "+
        "Use: infuse <who> <sp>\n");
  return 1; }

if(TPSP < sp_amt) {
  write("You don't have that much magic\n");
  return 1; }

TP->add_spell_point(- sp_amt);
  /* lose up to 20% in transfer */
sp_amt = sp_amt - random(((sp_amt / 10) * 2));
target->add_spell_point(sp_amt);
write(HIR+"You CONCENTRATE and send "+sp_amt+" of your magic to "+
      capitalize(target_name)+".\n"+NORM);
EFANGS->tell_my_room(HIR+
  capitalize(target_name)+" jerks as if shocked...\n"+NORM);
return 1;
}
