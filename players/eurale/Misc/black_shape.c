#include "/players/eurale/closed/ansi.h"
string name;
status is_lighted;


reset(arg) {
  if(arg) return;
name = "dodecahedron";
is_lighted = 0;
}

short() {
  if(is_lighted) { return "Dodecahedon (pulsing); }
  return "Dodecahedon"; }

long() {
  write(
  "This magical dodecahedron has been blessed by the darkest of the\n"+
  "Gods.  You may summon its magical powers with 'dark on' and 'dark\n"+
  "off'.  You may not ever give it away or drop it.  Your only hope\n"+
  "of ridding yourself of it is to 'crush' it.\n");
  if(is_lighted) {
    write("The dodecahedron is currently pulsing.\n"); }
  else {
    write("The dodecahedron is currently quiet.\n"); }
}

query_weight() { return 1; }

id(str) { return str == "dodecahedron"; }

get() { return 1; }
drop() {
  write("The magical attachment is too strong...\n"); return 1; }

init() {
  add_action("dark","dark");
  add_action("crush","crush");
}

dark(str) {
int ac;

if(!str) { write("What are you trying to do?\n"); return 1; }
if(str == "on") {
  if(is_lighted) { write("The dodecahedron already pulses.\n"); return 1; }
is_lighted = 1;

ac = this_player()->query_ac();
ac = ac + 1;

if(set_light(1) == 1) {
this_player()->set_ac(ac);
  write("You whisper magic words and the dodecahedron begins to pulse!\n");
  say(call_other(this_player(),"query_name") +
    " whispers and the dodecahedron begins to pulse!\n");
  return 1; }
else {
  write("Okay, done....\n"); return 1; }
}

if(str == "off") {
  if(!is_lighted) return 0;
is_lighted = 0;

ac = this_player()->query_ac();
ac = ac - 1;
this_player()->set_ac(ac);

if(set_light(-1) == 0) {
  write("You whisper and the dodecahedron's pulsing quiets.\n");
  say(call_other(this_player(),"query_name") +
    " whispers and the dodecahedron's pulsing fades..\n");
  return 1; }
else {
  write("Okay, done....\n"); return 1; }
return 1; }
}

crush(str) {
if(!str) { write("Crush what?\n"); return 1; }
if(str == "dodecahedron" && is_lighted == 0) {
  write("You grasp the fragile dodecahedron between your hands and\n"+
	"CRUSH it into tiny fragments....\n");
  this_player()->add_money(150 + random(50));
  destruct(this_object());
  return 1; }
else {
  write("You burn your hands on the pulsing dodecahedron.....\n");
  this_player()->heal_self(-random(50));
  return 1; }
}
