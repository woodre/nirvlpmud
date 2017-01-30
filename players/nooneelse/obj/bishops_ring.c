/*
 bishops_ring.c - quest item - player must drop this item in the church to
                               solve the quest
*/

inherit "obj/armor";

string quest_solvers_name, str;

query_save_flag() { return 1; }

init() {
  ::init();

  add_action("read_ring", "read");
  add_action("drop_ring", "drop");
  add_action("set_ring",  "set");
}

/* Clue the player what to do with it. */
read_ring(str) {
  if (!str || str != "ring") return;
  if (quest_solvers_name=="@") {
    write("There's something wrong with this ring!\n");
    destruct(this_object());
    return 1;
  }
  if (lower_case(this_player()->query_name())==quest_solvers_name ||
      this_player()->query_level() > 20)
    write("It says:\n"+
          "   "+capitalize(quest_solvers_name)+
          ", you really should drop this off where you started life.\n");
  else
    write("You can't make the words out.\n");
  return 1;
}


/* Don't solve the quest unless player drops the ring in the Church. */
drop_ring(str) {
  int weight;
  string this_room, str2;
  if (!str || !id(str)) return;
  str2=file_name(environment(environment(this_object())));
  sscanf(str2, "%s.c", this_room);
  if (!this_room) this_room=str2;
  if (this_room!="room/church") {
    write("This is not the correct place!\n");
    return 1;
  }
  if (this_room=="room/church" &&
      this_player()->query_real_name()!=quest_solvers_name &&
      present(str,this_player())==this_object()) {
    write(
      "As a transparent hand takes the ring, you hear a rumbling voice say:\n"+
      "   You are not the quest solver!  How did you get this ring?\n");
    destruct(this_object());
    return 1;
  }
  if (this_room=="room/church" && present(str,this_player())==this_object()) {
    write(
      "As a transparent hand takes the ring, you hear a rumbling voice say:\n"+
      "   Well done "+capitalize(this_player()->query_name())+"!\n"+
      "   You have solved this quest!\n");
    this_player()->set_quest("bishops_ring");
    write_file("/players/nooneelse/closed/BISHOPS_RING_QUEST_SOLVERS",
               "Bishops Ring Quest solved by: "+
               capitalize(this_player()->query_name())+
               " -- "+ctime(time())+"\n");
    destruct(this_object());
    return 1;
  }
}

set_ring(str) {
  string str1, str2;
  if (!str) return 0;
  sscanf(str, "%s %s", str1, str2);
  if (this_player()->query_real_name()!="nooneelse" || str1!="ring")
    return 0;
  set_quest_solver(str2);
  return 1;
}

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("ring");
  set_alias("bishops ring");
  set_short("Bishops Ring");
  set_long("This is an expensive looking ring that might be platinum.\n"+
           "There seems to be something written inside the band.\n");
  set_value(5);
  set_weight(1);
  set_ac(1);
  set_alias("ring");
  set_type("ring");
  set_arm_light(1);
  quest_solvers_name="@";
}

set_quest_solver(str) {
  sscanf(str, "%s", quest_solvers_name);
  return 1;
}

query_quest_solver() {
  write("quest_solvers_name="+quest_solvers_name+"\n");
  return 1;
}
