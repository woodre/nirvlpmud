/*  Saloon owner - Miss Kitty  */

inherit "obj/monster";
object player;

reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("kitty");
set_race("human");
set_short("Miss Kitty");
set_alias("miss kitty");
set_long(
	"  Miss Kitty is a busty, bawdy lady who has been around the block \n"+
	"a few times.  Her natural charm makes her a favorite of the local \n"+
	"cowboys and she's been seen 'cleaning house' on occasion \n");
set_level(16);
set_hp(400);
set_al(0);
set_wc(22);
set_ac(13);
set_aggressive(0);

gold = clone_object("obj/money");
gold->set_money(random(50)+850);
move_object(gold,this_object());
}

init() {
  ::init();
  add_action("ask","ask"); }

ask(str) {
string s1,s2;
  if(!str) { write("Who did you want to ask?\n"); return 1; }
  sscanf(str,"%s %s",s1,s2);
  if(s1 != "miss") { write("Try being a little more formal.\n");
	return 1; }
if( (s1 == "miss") && (s2 == "kitty") ) {
  write("Miss kitty pauses, looks you right in the eye and begins..\n\n");
  player = this_player();
  call_out("story1",8);
  return 1; }
return 1;
}

story1() {
tell_object(player,
	"Kitty whispers....\n"+
	"  'You'll have to keep this under your hat because folks around\n"+
	"here are pretty touchy about strangers asking questions.'\n\n");
	call_out("story2",9); return 1; }

story2() {
tell_object(player,
	"Kitty looks around to make sure nobody is listening...\n\n");
	call_out("story3",9); return 1; }

story3() {
tell_object(player,
	"Kitty continues.....\n"+
	"  'It seems that legend has it that Drygulch was once a green\n"+
	"and lush area with lots of water around.  The eternal feuding\n"+
	"between right and wrong was at a peak.  One moonless night,\n"+
	"the darkest of the dark managed to sneak into town and steal\n"+
	"the sacred rood from his arch nemesis, Dontayne.'\n\n");
	call_out("story4",9); return 1; }

story4() {
tell_object(player,
	"Kitty leans closer....\n"+
  "'Now, mind you, I'm not sure but I think Dontayne was a man of\n"+
  "the cloth.  Anyways, the dark one was so afraid of being hunted\n"+
  "and killed that he hired hands to dig mazes of caverns under\n"+
  "and around Drygulch so he could hide.'\n\n");
	call_out("story5",9); return 1; }

story5() {
tell_object(player,
	"  'As the men worked on the caverns, they struck a bottomless\n"+
	"hole that caved in.  Slowly, all the water from the area \n"+
	"began to drain away... leaving this a parched and dry desert\n"+
	"land.'\n\n");
	call_out("story6",9); return 1; }

story6() {
tell_object(player,
  "'Dontayne, having lost his beloved rood and his ability to\n"+
  "survive with no water, went in search of the dark one in the\n"+
  "maze of caverns.  Rumor has it that he still wanders the dark\n"+
  "caverns in hopes of finding what was taken from him.  It's\n"+
  "said that if the rood were ever restored to Dontayne, the rift\n"+
  "in the fabric of light would be repaired and great fortune\n"+
  "bestowed upon the restorer...'\n\n");
	call_out("story7",9); return 1; }

story7() {
tell_object(player,
	"Kitty glances over the room again.....\n"+
	"  'That's all I know of this legend.  There's nothing left \n"+
	"for me to tell you.  Be careful in the caverns if you find\n"+
	"them as many have gone off and not come back from there.\n"+
	"I hope what I've told you has been of some help'....\n\n"+
	"Kitty turns and walks to another table.....\n\n");
	return 1; }
