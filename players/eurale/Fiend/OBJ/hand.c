#define tpn this_player()->query_name()
inherit "obj/treasure";
object player;

reset(arg) {
  if(arg) return;
set_id("hand");
set_short("A rotting hand");
set_long(
	"This rotting hand has been in the drain for quite some time.\n"+
	"The flesh has turned soft and mushy and certainly has a foul\n"+
	"smell to it.  Tatooed on the middle finger is a small skull\n"+
	"and crossbones.  Two of the fingernails have come loose and\n"+
	"are hanging by threads of gooey material.\n");

	set_weight(1);
    set_value(1);
}

init() {
  ::init();
  add_action("remand","remand");
  add_action("talk","talk");
}

remand(str) {
if(!str) { write("You must want to remand something?\n"); return 1; }
if(str != "hand") {
  write("I don't think that's what you want to remand.\n"); return 1; }

if(str == "hand") {
 if(present("captain hook",environment(this_player()))) {
  player = this_player();
  player->set_quest("hooks_hand");
  call_out("talk",1);
  return 1; }
 else {
  write("There seems to be something amiss here, nothing happens.\n");
  return 1; }
return 1; }
}

talk() {
tell_object(player,
  "Captain Hook takes the rotting hand from you and looks it over very\n"+
  "carefully.  He looks you straight in the eye and says....\n\n");
  call_out("talk1",6);
  return 1; }

talk1() {
tell_object(player,
  "Ahhhhh....... I see by the Jolly Roger tatoo that you've found my\n"+
  "lost hand.  A while back the damn croc bit it off and that crazy\n"+
  "doc promised to try to sew it back on....\n\n");
  call_out("talk2",7);
  return 1; }

talk2() {
tell_object(player,
  "Somehow in all the confusion, it got lost.  Well, I want to thank ye\n"+
  "for your efforts and make it right with you before you go...\n\n");
  call_out("talk3",6);
  return 1; }

talk3() {
tell_object(player,
  "Hook turns and winks at his crew......\n\n");
  call_out("talk4",5);
  return 1; }

talk4() {
tell_object(player,
  "Hook continues......  for your bravery and kindness, and by the powers\n"+
  "vested in me... I award you 10 full quest points toward your goal of\n"+
  "Wizardhood......\n"+
  "           Congratulations, this quest is completed.\n\n");
  destruct(this_object());
  return 1; }
