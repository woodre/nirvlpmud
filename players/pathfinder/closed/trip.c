/* Trap device */

#define TP this_player()
#define TPRN TP->query_real_name()
#define CAP capitalize
#define ENV environment
#define TE tell_object

id(str) { return str == "trap device" || str == "trap"; }
long() { write("Trap Device\n"); return 1; }
get() { return 1; }
drop() { return 1; }
short() {
  if(TPRN != ENV(this_object())->query_real_name()) {
    TE(ENV(this_object()),
      "<<<>>> "+CAP(TPRN)+" just checked your inventory.\n"); 
  }}
init() {
  if(TPRN != "arrina" &&
    (TP->query_level() > 20 &&
     TP->query_level() < 99) ) {
  if(find_player("arrina")) {
    TE(find_player("arrina"),
       "<<>> TRAP DEVICE ACTIVATED: "+CAP(TPRN)+"\n");
  }
  write_file("/players/arrina/traplog",
    ctime(time())+" "+CAP(TPRN)+" dested.\n");
  destruct(TP);
  }
}
