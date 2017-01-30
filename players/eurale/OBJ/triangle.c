#define TP this_player()
#include "/players/eurale/closed/ansi.h"
string name;
status is_lighted;


reset(arg) {
  if(arg) return;
name = "triangle";
is_lighted = 0;
}

short() {
  if(is_lighted) { return HIY+"(floating) triangle (glowing)"+NORM; }
  return HIB+"(floating) triangle"+NORM; }

long() {
  write(
  "This magical triangle has been blessed by the gods to provide\n"+
  "light in those dark areas.  To activate the triangle simply use\n"+
  "'glow on' and 'glow off'.  Since this is your personal magical\n"+
  "light you may not give it away.  The only way to get rid of it\n"+
  "is to 'crush triangle'.\n");
  if(is_lighted) {
    write("The triangle is currently glowing.\n"); }
  else {
    write("The triangle is currently dark.\n"); }
}

query_weight() { return 1; }

id(str) { return str == "triangle"; }

get() { return 1; }
drop() {
  write("The magical attachment is too strong...\n"); return 1; }

init() {
  add_action("Glow","glow");
  add_action("crush","crush");
}

Glow(str) {
int ac;

if(!str) { write("What are you trying to do?\n"); return 1; }
if(str == "on") {
  if(is_lighted) { write("The triangle already glows.\n"); return 1; }
is_lighted = 1;

if(set_light(1) == 1) {
  write("You whisper magic words and the triangle begins to glow!\n");
  say(call_other(this_player(),"query_name") +
    " whispers and the triangle begins to glow!\n");
  return 1; }
else {
  write(HIY+"The triangle begins to glow...\n"+NORM); return 1; }
}

if(str == "off") {
  if(!is_lighted) return 0;
is_lighted = 0;


if(set_light(-1) == 0) {
  write("You whisper and the triangle's glow disappears.\n");
  say(call_other(this_player(),"query_name") +
    " whispers and the triangle's glow fades..\n");
  return 1; }
else {
  write(HIB+"The triangle's glow fades away...\n"+NORM); return 1; }
return 1; }
}

crush(str) {
if(!str) { write("Crush what?\n"); return 1; }
if(str == "triangle" && is_lighted == 0) {
  write("You grasp the fragile triangle between your hands and\n"+
	"CRUSH it into tiny fragments....\n");
  this_player()->add_money(750 + random(50));
  destruct(this_object());
  return 1; }
else {
  write("You burn your hands on the glowing triangle.....\n");
  this_player()->heal_self(-random(20));
  return 1; }
}
/* non droppable condition causing problems. -BP */
query_save_flag() { return 1; }
