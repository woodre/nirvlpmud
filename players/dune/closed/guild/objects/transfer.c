/* Slow hp->sp transfer */
#include "../DEFS.h"

status id(string str) { return str == TRANSFER_ID; }
void long()   { write("Energy transfer device\n"); }
status get()  { return 1; }
status drop() { return 1; }

void init() {
  if(!present(AFFILIATE,TP)) destruct(this_object());
}

status energy_transfer() {
  int hps, mhps, sps, msps;
  if(!environment()) return 1;
  if(!living(environment(this_object()))) destruct(this_object());
  if(!environment()->query_interactive()) return 1;
  hps  = (int)environment(this_object())->query_hp();
  mhps = (int)environment(this_object())->query_mhp();
  sps  = (int)environment(this_object())->query_sp();
  msps = (int)environment(this_object())->query_msp();
  if(sps == msps)  { call_out("energy_transfer",10); return 1; }
  if(hps < mhps/5) { call_out("energy_transfer",10); return 1; }
  tell_object(environment(this_object()),"Converting...\n");
  if(hps > mhps / 4) {
    if(sps < (msps - 5)) {
      environment(this_object())->add_hit_point(-5);
      environment(this_object())->add_spell_point(4);
      call_out("energy_transfer",10);
      return 1;
    }
    environment(this_object())->add_hit_point(-2);
    environment(this_object())->add_spell_point(2);
    call_out("energy_transfer",5);
    return 1;
  }
  environment(this_object())->add_hit_point(-1);
  environment(this_object())->add_spell_point(1);
  call_out("energy_transfer",5);
  return 1;
}

