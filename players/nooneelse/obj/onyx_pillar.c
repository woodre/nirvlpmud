/*
  onyx_pillar.c - show names of players that have solved the bishops ring quest
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
  string solver_entry, solver_name, solver_date;
  int i, solver_found;
  if (!str) return 0;
  if (str=="pillar" || str=="at pillar" || str=="at onyx pillar")
    str="onyx pillar";
  sscanf(str, "%s %s", str1, str2);
  if (str1 != "onyx" || str2 != "pillar") return 0;
  write(
    "     _____________________________________________________________\n"+
    "    /.   .     .       .          ..      .      ..   .      ..  /|\n"+
    "   /   .  .        .    .    .        ...    .       .    .     / |\n"+
    "  /____________________________________________________________/ .|\n"+
    "  |                                                            | .|\n"+
    "  |     Contained hereon are the names of the fortunate few    |  |\n"+
    "  |     intrepid adventurers who have completed the task of    |. |\n"+
    "  |     destroying the master vampire and returned the         |  |\n"+
    "  |     Bishop's ring to where it belongs.                     | .|\n"+
    "  |                                                            | .|\n");
  i=1;
  solver_entry="x";
  while (solver_entry) {
    solver_entry=read_file(
                     "/players/nooneelse/closed/BISHOPS_RING_QUEST_SOLVERS", i);
    if (solver_entry=="" || solver_entry==0) solver_entry=0;
    if (solver_entry) {
      sscanf(solver_entry,
        "Bishops Ring Quest solved by: %s -- %s\n", solver_name, solver_date);
      if (solver_name) {
        solver_found=1;
        solver_name=extract(capitalize(solver_name)+"                   ",0,20);
        write("  |     "+capitalize(solver_name));
        write(solver_date+"          |  |\n");
      }
      i+=1;
    }
  }
  if (!solver_found) {
    write(
    "  |                                                            | .|\n");
  }
  write(
    "  |                                                            | .|\n"+
    "  |     Congratulations on solving this difficult feat!        |./\n"+
    "  |                                                Nooneelse   |/\n"+
    "  |____________________________________________________________|\n");
  return 1;
}

reset(arg) {
  if (arg) return;

  set_short("A onyx pillar");
  set_long("A thick sheet of onyx with gold letters embedded in it.\n");
}

get() { return 0; }

id(str) {
  return (str=="onyx pillar" || str=="onyx_pillar" || str=="pillar");
}
