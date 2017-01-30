inherit "obj/treasure";
object player;

reset(arg) {
  if(arg) return;
    set_id("key");
set_short("An ornate skeleton key");
set_long(
	"This fairly large and ornate skeleton key has been buried for\n"+
	"a very long time.  It has a twisted vine wreath for it's head\n"+
	"and 3 seperate teeth for opening it's locks.  A careful look\n"+
	"tells you that this key is for something very special.\n");
    set_weight(1);
    set_value(50);
set_save_flag();
}

init() {
  ::init();
  add_action("unlock","unlock");
  add_action("talk","talk");
}

unlock(str) {
if(!str) { write("Unlock what?\n"); return 1; }
if(present("questman",environment(this_player())) && str == "secret") {
  write("You whisper into the well.....\n");
  player = this_player();
  this_player()->set_quest("key_quest");
  call_out("talk",2);
  return 1; }
else {
  write("Something is incorrect or missing, sorry.\n");
  return 1; }
}

talk() {
if(!player) return destruct(this_object()); /* verte 10-4-01 */
tell_object(player,
  "\n\n"+
  "A tiny voice from deep in the well whispers back....\n\n"+
  "The quest for Wizardship takes intelligence and patience...\n"+
  "You have earned the right to know the secret.....\n\n");
  call_out("talk1",7);
  return 1; }

talk1() {
if(!player) return destruct(this_object()); /* verte 10-4-01 */
tell_object(player,
  "The SECRET is that you've managed to complete this quest....\n"+
  "and for doing so, the God of Quests has seen fit to bestow upon\n"+
  "you the honor of another 13 quest points.....\n\n"+
  "Congratulations, warrior, on a job well done!\n\n");
  destruct(this_object());
  return 1; }
