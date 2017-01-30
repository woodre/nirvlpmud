/*
  solve_guild_tasks.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Solve the guild's mini-tasks ---------- */
solve_guild_tasks(str) {
  string str1, str2;
  object fire_sword, stone_sword, frost_sword;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str || !str=="task") return 0;
  str1 = file_name(MY_ROOM);
  sscanf(str1, "%s.c", str2);
  if (!str2) str2 = str1;

  /* solve this to use level 5-7 rank 10 abilities */
  if (MY_GUILD_RANK==1) {
    if (str2=="players/catt/VALLEY/monkroom3")
      ok_solve_it();
    else
      write(NORM+CYN+"You have NOT yet solved the task! Keep looking.\n"+NORM);
    return 1;
  }

  /* solve this to use level 8-11 rank 20 abilities */
  if (MY_LEVEL < 8) {
    write(NORM+CYN+"You must be at least level 8 to solve this task.\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK==10) {
    if (str2=="room/mine/tunnel16")
      ok_solve_it();
    else
      write(NORM+CYN+"You have NOT yet solved the task!\n"+NORM);
    return 1;
  }

  /* solve this to use level 12-14 rank 40 abilities */
  if (MY_LEVEL < 12) {
    write(NORM+CYN+"You must be at least level 12 to solve this task.\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK==20) {
    if (str2=="players/deathmonger/UNDERDARK/maze/baph")
      ok_solve_it();
    else
      write(NORM+CYN+"You have NOT yet solved the task!\n"+NORM);
    return 1;
  }

  /* solve this to use level 15-18 rank 60 abilities */
  if (MY_LEVEL < 15) {
    write(NORM+CYN+"You must be at least level 15 to solve this task.\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK==40) {
    if (str2=="players/nooneelse/mazeforest/m_forest_chamber")
      ok_solve_it();
    else
      write(NORM+CYN+"You have NOT yet solved the task!\n"+NORM);
    return 1;
  }

  /* solve this to use level 19+ rank 80 abilities */
  if (MY_LEVEL < 19) {
    write(NORM+CYN+"You must be at least level 19 to solve this task.\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK==60) {
    fire_sword = present("sword of fire", MY_PLAYER);
    stone_sword = present("stone cutter sword", MY_PLAYER);
    frost_sword = present("sword of frost", MY_PLAYER);
    if (str2=="room/giant_conf" && (fire_sword && stone_sword && frost_sword)) {
      ok_solve_it();
      destruct(fire_sword);
      destruct(stone_sword);
      destruct(frost_sword);
      write(NORM+CYN+
            "A giant water elemental comes and takes the three swords and gives you\n"+
            "some gold.\n"+NORM);
      MY_PLAYER->add_money(3000);
      MY_FANGS->tell_my_room(
                  MY_NAME_CAP+" mumbles something, then you see a giant water\n"+
                  "elemental fly in to collect 3 swords and fly away.");
    }
    else
      write(NORM+CYN+"You have NOT yet solved the task!\n"+NORM);
    return 1;
  }

  if (MY_GUILD_RANK==80)
    write(NORM+CYN+"You have solved all of the guild's tasks!\n"+NORM);
  return 1;
}

ok_solve_it() {
  switch (MY_GUILD_RANK) {
    case 1:  MY_PLAYER->add_guild_RANK(9);  break;
    case 10: MY_PLAYER->add_guild_RANK(10); break;
    case 20: MY_PLAYER->add_guild_RANK(20); break;
    case 40: MY_PLAYER->add_guild_RANK(20); break;
    case 60: MY_PLAYER->add_guild_RANK(20); break;
  }
  MY_PLAYER->save_me();
  write(NORM+CYN+"Excellent!  You have solved this task.\n"+
        "Type 'task' to see what your next task is.\n"+NORM);
}
