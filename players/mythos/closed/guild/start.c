#include "/players/mythos/closed/guild/def.h"
int talent, glevel, fae, sacrifice, dblade, dring, md;
int sim_on, ward_on, c_area_on, shatter_on, bow_on, pact1, pact2, devil;
int imag_on, ban_on, send_on, pow_on, rev_on;
int helper, sif, dis_on;
string dtitle, ctitle;
object ob, ob2, own;

id(str) { return str == "moo"; }

reset(arg) {
  if(arg) return;
  glevel = 0;
  call_out("setup",3);
}

setup() {
  if(ep) { destruct(this_object()); return 1; }
  restore_object(MEM+"test");
  glevel = 100;
  save_object(MEM+"test");
  destruct(this_object());
return 1; }