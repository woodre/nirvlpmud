/* Slow hp->sp transfer */

#define TP this_player()
#define TO this_object()
#define ENV environment
#define PRE present
#define RE return 1

id(str) { return str == "transferobj"; }
long() { write("Energy transfer device\n"); RE; }
get() { RE; }
drop() { RE; }

init() {
  if(!PRE("either implants",TP)) destruct(TO);
       }

energy_transfer() {
  int hps, mhps, sps, msps;
    if(!living(ENV(TO))) destruct(TO);
  hps = ENV(TO)->query_hp();
  mhps = ENV(TO)->query_mhp();
  sps = ENV(TO)->query_sp();
  msps = ENV(TO)->query_msp();
  if(sps == msps) { call_out("energy_transfer",10); RE; }
  if(hps < mhps/5) { call_out("energy_transfer",10); RE; }
  tell_object(ENV(TO),"Converting...\n");
  if(hps > mhps / 4) {
    if(sps < (msps - 5)) {
      ENV(TO)->add_hit_point(-5);
      ENV(TO)->add_spell_point(5);
      call_out("energy_transfer",10);
      RE;                }
    ENV(TO)->add_hit_point(-2);
    ENV(TO)->add_spell_point(2);
    call_out("energy_transfer",5);
    RE;                      }
  ENV(TO)->add_hit_point(-1);
  ENV(TO)->add_spell_point(1);
  call_out("energy_transfer",5);
  RE;    }

