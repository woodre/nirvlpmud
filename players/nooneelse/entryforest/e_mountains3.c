/*
  e_mountains3.c
*/

inherit "room/room";

int question_answered;

set_question_answered() { question_answered=1; }

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="High mountains";
  long_desc="You are at the peak of some low mountains overlooking a\n"+
           "granite walled canyon.  There are some deep claw marks in\n"+
           "the dirt here as if something very large comes here every\n"+
           "so often.  There is a path leading down to the lower peaks.\n";
  items=({
          "path", "The narrow path is faint, but clear\n",
          "dirt", "There are some deep claw marks and paw prints in it\n",
          "ground", "There are some deep claw marks and paw prints in it\n",
          "canyon",
            "Steep, unclimable granite walls define this deep crevass\n",
          "scratch", "The claw mark is deeply etched into the ground\n",
          "scratches", "The claw marks are deeply etched into the ground\n",
          "marks", "The claw marks are deeply etched into the ground\n",
          "claw marks", "The claw marks are deeply etched into the ground.\n",
          "prints", "The paw prints are deeply pressed into the ground\n",
          "claw prints",
            "The paw prints are deeply pressed into the ground\n",
        });
  dest_dir=({
             "players/nooneelse/entryforest/e_mountains2", "down",
           });
}

init() {
  ::init();

  add_action("sniff", "sniff");
  add_action("say",   "say");
  add_action("say",   "shout");
  add_action("say",   "sing");
  add_action("say",   "scream");
}

sniff() {
  object obj;
  if (question_answered &&
      !present("garlic") &&
      !present("garlic", this_player())) {
    obj=clone_object("players/nooneelse/obj/garlic");
    move_object(obj, this_object());
    write("You sniff and discover what the stong odor was.  "+
          "You spot a clove of garlic you hadn't noticed before.\n");
  }
  else
    write("You sniff and notice a strong odor of garlic.\n");
  return 1;
}

say(str) {
  if (query_verb()=="sing") str="doe rae me fa so la ah ti...";
  if (query_verb()=="scream") str="AAARRRGGGHHH!!!";
  if (!str) return 0;
  call_out("echo", 2, str);
  return 0;
}

echo(str) {
  tell_room(this_object(),
            "After a moment, you hear a faint echo saying:\n"+
            "\n   "+str+"...\n\n");
  call_out("call_sphinx", 4);
  return 1;
}

call_sphinx() {
  object sphinx;
  tell_room(this_object(),
            "The wings of a huge creature buffet you as it lands.\n");
  if (!find_living("sphinx") || !environment(find_living("sphinx"))) {
    sphinx=clone_object("players/nooneelse/mon/sphinx");
    move_object(sphinx, this_object());
  }
  return 1;
}
