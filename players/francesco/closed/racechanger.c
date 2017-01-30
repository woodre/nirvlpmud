
string race;

drop() {destruct(this_object()); return 1;}

reset(arg) {}

init() {
  add_action("set_race","newrace");
::init();
}
set_race(str) { race = str; }
