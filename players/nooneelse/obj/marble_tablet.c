/*
  marble_tablet.c - advertising to counter lies being told by monks
*/

inherit "obj/treasure";

init() {
  ::init();

  add_action("read", "read");
  add_action("read", "examine", 3);
  add_action("read", "look", 1);
}

read(str) {
  string str1, str2;
  if (!str) return 0;
  if (str=="tablet" || str=="at tablet" || str=="at marble tablet")
    str="marble tablet";
  sscanf(str, "%s %s", str1, str2);
  if (str1 != "marble" || str2 != "tablet") return 0;
  write(
    "     _____________________________________________________________\n"+
    "    /.   .     .       .          ..      .      ..   .      ..  /|\n"+
    "   /   .  .        .    .    .        ...    .       .    .     / |\n"+
    "  /____________________________________________________________/ .|\n"+
    "  |                                                            |  |\n"+
    "  |  Welcome to Nirvana!  This is being placed here to counter |. |\n"+
    "  |  some misinformation being spread.                         |  |\n"+
    "  |                                                            | .|\n"+
    "  |  1. To join the Vampire Guild, you only have to be level 3 |  |\n"+
    "  |     or higher (just like all the other guilds)             |. |\n"+
    "  |                                                            |  |\n"+
    "  |  2. You don't have to be bitten by a wizard member.        | .|\n"+
    "  |     (In fact,the recruitment is left strictly up to the    | .|\n"+
    "  |      player members.)                                      | .|\n"+
    "  |                                                            | .|\n"+
    "  |  3. If you're curious about the abilities of the guild ask |. |\n"+
    "  |     one of the members to lead you to the guild hall.      | ./\n"+
    "  |     There's a description of the guild's abilities.        | /\n"+
    "  |                                                            |/\n"+
    "  |____________________________________________________________|\n");
  return 1;
}

reset(arg) {
  if (arg) return;

  set_short("A marble tablet");
  set_long("A thick sheet of marble with gold letters embedded in it.\n");
}

get() { return 0; }

id(str) {
  return (str=="marble tablet" || str=="marble_tablet" || str=="tablet");
}
