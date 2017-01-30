#define message "You experience a sudden rush of awareness"
#define value 300
#define strength -13

reset(arg) {
    if (arg) return;
}

id(str) { return str=="wakeup"; }
short() { return "A wakeup call (detox)"; }
long() { write("A wakeup call.  To use: detox\n"); }

init() {
  add_action("Detox","detox");
}

Detox() {
  write("You experience a sudden rush of awareness.\n");
  call_other(this_player(),"drink_alcohol",strength);
  destruct(this_object());
  return 1; }

query_value() { return value; }
query_weight() { return 2; }
get() { return 1; }
