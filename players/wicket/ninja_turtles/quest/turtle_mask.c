/*
 * Ninja Turtle Mask
 * Used in the quest for the Pizza Hut Manager
 * Rumplemintz
 */
#pragma strong_types

inherit "obj/treasure";
#include <ansi.h>

string color;

string get_ansi_color(string color);
int consolidate_files(object player);
string query_color() { return color; }

string get_ansi_color(string color) {
  string ansi_color;

  switch(color) {
    case "orange":
      ansi_color = YEL;
      break;
   case "red":
     ansi_color = HIR;
     break;
   case "blue":
     ansi_color = HIB;
     break;
   default:
     ansi_color = MAG;
     break;
  }
  return ansi_color + color +NORM;
}

void set_color(string str) {
  if (!str)
    return;
  color = str;
  set_short((color == "orange" ? "An" : "A") + " " + get_ansi_color(color) + " bandana mask");
  set_long("\
This is " + (color == "orange" ? "an" : "a") + " " + color +
" mask that is worn around the head like a bandana.\n\
It would be a good choice for ninjas trying to hide thier identity.\n");
}

void reset(int arg) {
  ::reset(arg);
  if (arg)
    return;
  color = "wierd";
  set_name("mask");
  set_alias("bandana mask");
  set_short("A clear bandana mask");
  set_long("\
This is a clear mask that is worn around the head like a bandana.\n\
Clearly a bad choice for Ninjas that want to hide their identity.\n");
  set_value(2000);
  set_weight(1);
}

void init() {
  ::init();
  add_action("turn_in", "turn");
  add_action("no_wear", "wear");
}

int turn_in(string str) {
  string questfile;

  if (!str)
    return 0;
  if (str != "in mask") {
    notify_fail("Turn in mask?\n");
    return 0;
  }
  if (!present("manager", environment(this_player()))) {
    notify_fail("There is no one here that wants that mask.\n");
    return 0;
  }

  questfile = "/players/wicket/ninja_turtles/quest/" +
              (string)this_player()->query_real_name() + "." + color;

  if (color == "blue" || color == "purple") {
    if (file_size(questfile) > 0) {
      notify_fail("The Manager says: You've already given me that mask.\n");
      return 0;
    }
    write_file(questfile, ctime() + "\n");
    present("manager", environment(this_player()))->start_quest(color,
                                                                this_player());
    destruct(this_object());
    return 1;
  }
  if (color == "red") {
    if ( (file_size("/players/wicket/ninja_turtles/quest/" +
                    (string)this_player()->query_real_name() + ".blue") < 0) ||
         (file_size("/players/wicket/ninja_turtles/quest/" +
                    (string)this_player()->query_real_name() + ".purple") < 0)
       ) {
      notify_fail("The Manager says: That's not the mask I'm looking for.\n");
      return 0;
    }
    if (file_size(questfile) > 0) {
      notify_fail("The Manager says: You've already given me that mask.\n");
      return 0;
    }
    write_file(questfile, ctime() + "\n");
    if (file_size("/players/wicket/ninja_turtles/quest/" +
                  (string)this_player()->query_real_name() + ".orange") > 0) {
      consolidate_files(this_player());
      present("manager", environment(this_player()))->end_quest(this_player());
      destruct(this_object());
      return 1;
    } else {
      present("manager", environment(this_player()))->one_more("orange",
                                                               this_player());
      destruct(this_object());
      return 1;
    }
  }
  if (color == "orange") {
    if ( (file_size("/players/wicket/ninja_turtles/quest/" +
                    (string)this_player()->query_real_name() + ".blue") < 0) ||
         (file_size("/players/wicket/ninja_turtles/quest/" +
                    (string)this_player()->query_real_name() + ".purple") < 0)
       ) {
      notify_fail("The Manager says: That's not the mask I'm looking for.\n");
      return 0;
    }
    if (file_size(questfile) > 0) {
      notify_fail("The Manager says: You've already given me that mask.\n");
      return 0;
    }
    write_file(questfile, ctime() + "\n");
    if (file_size("/players/wicket/ninja_turtles/quest/" +
                  (string)this_player()->query_real_name() + ".red") > 0) {
      consolidate_files(this_player());
      present("manager", environment(this_player()))->end_quest(this_player());
      destruct(this_object());
      return 1;
    } else {
      present("manager", environment(this_player()))->one_more("red",
                                                               this_player());
      destruct(this_object());
      return 1;
    }
  }
}

int no_wear(string str) {
  if (str == "mask" || str == "bandana" || str == "bandana mask") {
    write("Only Ninja Turtles can wear such a mask.\n");
    return 1;
  }
  return 0;
}

int consolidate_files(object player) {
  string pname, path, file_contents;
 
  name = (string)player->query_real_name();
  path = "/players/wicket/ninja_turtles/quest/";
  file_contents = "";

  file_contents += "Blue : ";
  file_contents += read_file(path + name + ".blue");
  file_contents += "Purple : ";
  file_contents += read_file(path + name + ".purple");
  file_contents += "Orange : ";
  file_contents += read_file(path + name + ".orange");
  file_contents += "Red : ";
  file_contents += read_file(path + name + ".red");
  write_file(path + name + ".final", file_contents);

  rm(path + name + ".blue");
  rm(path + name + ".purple");
  rm(path + name + ".orange");
  rm(path + name + ".red");
  return 1;
}

query_save_flag() { return 1; }
