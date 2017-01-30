#include <ansi.h>
#define SHOT "/players/rumplemintz/obj/shot.c"

int rshots(string str) {
  object *us;
  int s;

  if (!str) {
    s = sizeof(us = users());
    while(s--) {
      if (!present("shot", us[s])) {
        move_object(clone_object(SHOT), us[s]);
        tell_object(us[s],
            "\n" + this_player()->query_name() +
            " orders a round of " + HIW + "Rumplemintz" + NORM +
            " for the entire realm!!!\n\n");
      }
    }
  } 
  else if (str == "beer") {
    s = sizeof(us = users());
    while (s--) {
      if ((int)us[s]->query_level() < 20) {
        move_object(clone_object("/obj/beer"), us[s]);
        tell_object(us[s],
            "\n" + this_player()->query_name() +
            " orders a round of " + HIY + " BEERS" + NORM +
            " for all the players!!!\n\n");
      }
    }
  } else {
    if (find_player(str)) {
      move_object(clone_object(SHOT), find_player(str));
      tell_object(find_player(str), "\n" + this_player()->query_name() +
                  " orders you a shot of " + HIW + "Rumplemintz" + NORM +
                  "!!!\n\n");
  } else
    write("Cannot find player! (" + str + ")\n");
  }
  write("Ok.\n");
  return 1;
}
