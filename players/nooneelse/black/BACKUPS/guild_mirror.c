/*
 guild_mirror.c
*/

inherit "obj/treasure";

string str;

init() {
  ::init();

  add_action("look_at_mirror", "look");
  add_action("look_at_mirror", "examine");
}

look_at_mirror(str) {
  string str2;
  if (!str) return;
  if (query_verb()=="examine") str="at mirror";
  sscanf(str, "at %s", str2);
  if (!str2) sscanf(str, "in %s", str2);
  if (str2 != "mirror") return;
  say(this_player()->query_name()+" examines "+this_player()->query_objective()+
      "self carefully in the mirror.\n");
  write("You examine yourself closely in the mirror and realize that\n");
  if (this_player()->query_wc() >= 20) str2="godlike";
  else
  if (this_player()->query_wc() >= 18) str2="awesome";
  else
  if (this_player()->query_wc() >= 16) str2="really good";
  else
  if (this_player()->query_wc() >= 14) str2="good";
  else
  if (this_player()->query_wc() < 14) str2="not very good";
  write("your weapon is "+str2);
  if (this_player()->query_ac() >= 10) str2="godlike";
  else
  if (this_player()->query_ac() >= 8) str2="awesome";
  else
  if (this_player()->query_ac() >= 6) str2="really good";
  else
  if (this_player()->query_ac() < 6) str2="not very good";
  write(" and your armor is "+str2+".\n");
  write("\nYou sense that if you require more detailed information, you must\n"+
        "seek a more modern device called a scanner from something called a\n"+
        "Klingon.\n");
  return 1;
}

reset(arg) {
  set_short("A magic mirror");
  set_long("It is a magic mirror of some sort.\n");
  set_value(0);
  set_weight(666);
}

get() {
  write("It is secured to the ground.\n");
  return;
}

id(str) { return (str=="mirror" || str=="magic mirror"); }
