#include "DEFS.h"
inherit "room/room";
int drac,K;   /*  Make sure only 1 dracula and key  */

reset(arg) {
if(!present("mummy")) {
  move_object(clone_object("players/eurale/Fiend/NPC/mummy"),TO); }
  if(arg) return;
set_light(0);
drac = 1;
K = 1;

short_desc = "Crypt";
long_desc =
	"  This crypt was made of concrete blocks on all sides including\n"+
	"the ceiling and floor.  The floor has been covered with a thick\n"+
	"layer of dirt and packed smooth.  There is no means of light\n"+
	"except what the open door lets in.  An ornate casket sits upon\n"+
	"a stone table, raising it from the floor.\n";
	

items = ({
	"dirt","Black, rich and loamy",
	"table","A granite table.  The legs are carved with bats and\n"+
		"gargoyles and human sacrifice",
	"casket","A polished black casket with an inlaid gold crest\n"+
		"matching the one on the crypt door",
	"blocks","Concrete with cement between making an almost impen-\n"+
	"ibrable structure, both physically and elementally",
});

dest_dir = ({
	"players/eurale/Fiend/mm35.c","out",
});

}

init() {
  ::init();
  add_action("open","open");
  add_action("forage","forage");
  add_action("search","search");
  TP->set_fight_area();
}

open(str) {
if(str == "casket" || str == "coffin") {
if(present("mummy")) {
  write("The mummy moves between you and the casket..\n");
  say("The mummy moves between "+capitalize(TPRN)+" and the casket..\n");
  return 1; }
if(drac == 0 && !present("dracula")) {
  write("The casket is empty and caked with dried blood..\n"); return 1; }
if(drac == 1 && !present("dracula")) {
  drac = 0;
  call_out("talk",2);
  return 1; }

 return 1; }
return 1; }

talk() {
  say(
	"\nThe casket door creaks as the lid is slowly raised...\n\n");
	call_out("talk1",5); return 1; }

talk1() {
  say(
	"A musty odor escapes from inside the coffin.....\n\n");
	call_out("talk2",5); return 1; }

talk2() {
  say(
	"A loud HISS is heard.........\n\n");
	call_out("talk3",5); return 1; }

talk3() {
  say(
	"And in the blink of an eye, standing before you is....\n\n"+
	"                  "+BOLD+"Count Dracula"+NORM+"\n\n");
    move_object(clone_object("players/eurale/Fiend/NPC/dracula"),TO);
	drac = 0;
	return 1; }

forage(str) {
if(drac == 1 && present("dracula")) {
  write("Dracula pushes you back from his casket.\n"); return 1; }

if(drac == 0) {
if(!str) { write("What would you like to forage?\n"); return 1; }

if(!present("dracula") && str == "sarcophagus" || str == "casket") {
  write("You forage around the outside of casket and find nothing.\n");
  write("Maybe you need to concentrate on the materials inside.\n");
  return 1; }

if(!present("dracula") && str == "glebe") {
  write("I'm not quite sure what you want to forage?\n"); return 1; }

if(!present("dracula") && str == "earth" || str == "dirt") {
  if(K == 1) {
    write("You forage through the casket earth and find a key.\n");
    move_object(clone_object("players/eurale/Fiend/OBJ/key"),TP);
    say(capitalize(TPRN)+" seems to have found something.\n");
    K = 0;
    return 1; }
  else {
    write("You forage through the casket earth and find nothing.\n");
    return 1; }
 return 1; }

return 1; }
}

search() {
  if(drac == 1 || present("dracula")) {
    write("You can't do that yet, sorry.\n"); return 1; }
  write("You need to take another look at the clue, sorry.\n");
  return 1; }
