#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
int x;
int time;
int nospam = 1;
object dude;

reset(arg) {
  if(arg) return;
  set_id("cigar");
set_short(BOLD+"cigar"+NORM);
set_long(
"This is a big brown cigar.  Boss Hogg loves to smoke these things.\n"+
"You might like to "+MAG+"smoke cigar."+NORM+"\n");
set_weight(1);
set_value(100);
}
init() { 
::init();
add_action("cigar","smoke");
}
cigar(arg) {
time = 5+random(17);
if(environment() != this_player()) return;
dude = this_player();
if(!arg) { write("What do you want to smoke?\n"); return 1; }
if(arg != "cigar") { write("What do you want to smoke?\n"); return 1; }
if(nospam == 2 && arg == "cigar") {write(BOLD+"You are already smoking it."+NORM+"\n"); return 1;}
if(nospam != 2 && arg == "cigar") {
tell_object(dude, BOLD+"You take a puff of the cigar and feel better."+NORM+"\n"); 
say(BOLD+""+TPN+" lights a cigar."+NORM+"\n");
dude->add_spell_point(4);
  nospam = 2;
call_out("blah1",time);
return 1; }}
blah1() {
tell_object(dude, BOLD+"You take a puff of the cigar and feel better."+NORM+"\n"); 
dude ->add_spell_point(4);
if(x == random(9)) {
tell_object(dude, "Your cigar burns out.\n"); 
destruct(this_object()); }
else {
call_out("blah1",time);
return 1; }
}
drop() {if(nospam == 2) {write("You should hold on to this, after all, it's lit.\n");
 return 1;}}
