/* /players/eurale/Keep/dmso.c
 * Approved by Wizardchild 11/12/96 
 * *prior* to open of area which it pertains to
*/
/*  DiMethyl SulfOxide Antitoxin  */

#include "/players/eurale/closed/ansi.h"
#define TP this_player()
#define TO this_object()
#define tpn this_player()->query_name()  /* player name  */

id(str) { if(str == "dmso" || str == "antitoxin") return 1; }
get() { return 1; }
short() { return BOLD+"DMSO"+NORM+" Antitoxin"; }
query_value() { return 1000; }
query_save_flag() { return 1; }
long() { write(
	"This small tube of DiMethyl Sulfoxide Antitoxin will travel\n"+
	"into the blood stream instantly once you 'apply' it to cure\n"+
	"most poisonous conditions.\n");
	}

reset(arg) {
  if(arg) return;
}

init() {
  add_action("apply","apply"); }

apply(str) {
if(!str) { write("You must <apply something>.\n"); return 1; }
if(str == "dmso" || str == "antitoxin" || str == "DMSO") {

if(present("scorptox",TP)) {
  write("You dab DMSO into the scorpion puncture and feel relief.\n");
  destruct(present("scorptox",TP));
  destruct(TO);
  return 1; }

if(present("hcl",TP)) {
  write("You spread DMSO over the acid burns and cure them.\n");
  destruct(present("hcl",TP));
  destruct(TO);
  return 1; }

if(present("toadtox",TP)) {
  write("You apply the DMSO and dissipate the deadly toad poison.\n");
  destruct(present("toadtox",TP));
  destruct(TO);
  return 1; }

if(present("toxin",TP)) {
  write("You apply the DMSO and feel immediate relief from the poison\n"+
	"coursing through your veins.\n");
  destruct(present("toxin",TP));
  destruct(TO);
  return 1; }

if(present("toxin2",TP)) {
  write("You rub the DMSO on and feel the disir poison disappear.\n");
  destruct(present("toxin2",TP));
  destruct(TO);
  return 1; }

if(present("poison",TP)) {
  write("As you rub the DMSO on your wound, you feel the powerful\n"+
	"poison leave your body...\n");
  destruct(present("poison",TP));
  destruct(TO);
  return 1; }


write("You apply the DMSO and taste smoked oysters.\n");
destruct(TO);
return 1; }
}
