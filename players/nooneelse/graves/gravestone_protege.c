/*
  gravestone_protege.c
*/

int flowers_here;

id(str) {
  return str=="protege stone" ||
         str=="gravestone" ||
         str=="stone" ||
         str=="grave";
}

short() {
  if (flowers_here) return "A gravestone and some roses";
  return "A gravestone";
}

long() {
  write("A thick sheet of marble with gold letters embedded in it.\n");
  if (flowers_here)
    write("There are some beautiful roses laying in front of the stone.\n");
}

get() { return 0; }

init() {
  add_action("read",          "read");
  add_action("read",          "examine", 2);
  add_action("read",          "look", 1);
  add_action("place_flowers", "place");
  add_action("place_flowers", "put");
}

read(str) {
  string str1, str2;
  if (!str) return 0;
  if (str=="at roses" ||
      str=="at rose" ||
      str=="at flowers" ||
      str=="at flower" ||
      str=="roses" ||
      str=="rose" ||
      str=="flowers" ||
      str=="flower") {
    write("                 .     .\n"+
          "             ...  :``..':\n"+
          "              : ````.'   :''::'\n"+
          "            ..:..  :     .'' :\n"+
          "          ``.    `:    .'     :\n"+
          "             :    :   :        :\n"+
          "              :   :   :         :\n"+
          "              :    :   :        :\n"+
          "               :    :   :..''''``::.\n"+
          "                : ...:..'     .''\n"+
          "                .'   .'  .::::'\n"+
          "               :..'''``:::::::\n"+
          "               '         `::::\n"+
          "                           `::.\n"+
          "                            `::\n"+
          "                  ..:```.:'`. ::'`.\n"+
          "                ..'      `:.: ::\n"+
          "               .:        .:``:::\n"+
          "               .:    ..''     :::\n"+
          "                : .''          ::\n"+
          "                 :             ::\n"+
          "                                :\n"+
          "                                 :\n"+
          "\n");
    return 1;
  }
  if (str=="gravestone" ||
      str=="stone" ||
      str=="at gravestone" ||
      str=="at stone")
    str="gravestone";
  if (str!="gravestone") return 0;
  write(
    "     _____________________________________________________________\n"+
    "    /.   .     .       .          ..      .      ..   .      ..  /|\n"+
    "   /   .  .        .    .    .        ...    .       .    .     / |\n"+
    "  /____________________________________________________________/ .|\n"+
    "  |                                                            |  |\n"+
    "  |                                                            | .|\n"+
    "  |                                                            | .|\n"+
    "  |                                                            | .|\n"+
    "  |          This is to commemorate the passing of             |. |\n"+
    "  |                                                            | .|\n"+
    "  |                       Protege                              | .|\n"+
    "  |                                                            | .|\n"+
    "  |    A Paladin who gave his life trying to stop a mugging.   | .|\n"+
    "  |                                                            | .|\n"+
    "  |                   January 27, 1995                         |  |\n"+
    "  |                                                            | .|\n"+
    "  |                                                            | ./\n"+
    "  |                                                            | /\n"+
    "  |                                                            |/\n"+
    "  |____________________________________________________________|\n");
  if (flowers_here)
    write("There are some beautiful roses laying in front of the stone.\n");
  return 1;
}

place_flowers(str) {
  string s1, s2, s3;
  object obj;
  if (!str) return 0;
  if (str=="flowers" || str=="flower" || str=="roses" || str=="rose")
    str="flowers on grave";
  if (sscanf(str, "%s %s %s", s1, s2, s3)!=3) {
    write("Use: place flowers on grave\n");
    return 1;
  }
  if ((s1!="flowers" && s1!="flower" && s1!="roses" && s1!="rose") ||
      (s2!="on" && s2!="in") ||
      (!id(s3))) {
    write("Use: place flowers on grave\n");
    return 1;
  }
  obj = present("flowers", this_player());
  if (!obj) {
    write("But, you don't have any flowers...\n");
    return 1;
  }
  flowers_here = 1;
  destruct(obj);
  write("You place the "+s1+" on the ground in front of the gravestone.\n");
  if (str=="flowers" || str=="roses")
    say(this_player()->query_name()+" places "+s1+
        " on the ground in front of the gravestone.\n");
  if (str=="flower" || str=="rose")
    say(this_player()->query_name()+" places a "+s1+
        " on the ground in front of the gravestone.\n");
  return 1;
}
