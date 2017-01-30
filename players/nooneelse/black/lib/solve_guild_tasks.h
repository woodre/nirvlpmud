/*
  solve_guild_tasks.h
*/

#include "defs.h"

/* -------- Solve the guild's mini-tasks ---------- */
solve_guild_tasks(str) {
  string str1, str2, solved_msg;
  object fire_sword, stone_sword, frost_sword;
if(!str || str != "task") { write("Solve what?\n"); return 1; }
  str1 = file_name(MY_ROOM);
  sscanf(str1, "%s.c", str2);
  solved_msg="Very well.  You have solved this task.  \n"+
             "Type 'task' to see what your next task is.\n";
  if (!str2) str2 = str1;

  /* Guild Task 1 - solve for level 3 abilities */
if(MY_GUILD_EXP==666) {
  if(str2 == "players/catt/AREAS/TEMPLE/monkroom3") {
    if(MY_GUILD_EXP > 666) {
      write("You have already done this one.\n");
      return 1; }
    ok_solve_it();
  }
else {
  write("You have NOT yet solved the task!\n");
  return 1; }
}

  /* Guild Task 2 - solve for level 4-5 abilities */
if(MY_LEVEL < 4) {
  write("You must be at least level 4 to solve this task.\n");
  return 1; }
if(MY_GUILD_EXP==667) {
  if(str2=="room/mine/tunnel16") {
    if(MY_GUILD_EXP > 667) {
      write("You have already done this one.\n");
      return 1; }
    ok_solve_it();
  }
else {
  write("You have NOT yet solved the task!\n");
  return 1; }
}

  /* Guild task 3 - solve for level 7-10 abilities */
if(MY_LEVEL < 7) {
  write("You must be at least level 7 to solve this task.\n");
  return 1; }
if(MY_GUILD_EXP==668) {
  if(str2=="players/deathmonger/UNDERDARK/maze/baph") {
    if(MY_GUILD_EXP > 668) {
      write("You have already done this one.\n");
      return 1; }
    ok_solve_it();
  }
else {
  write("You have NOT yet solved the task!\n");
  return 1; }
}

  /* Guild task 4 - solve to use level 12 abilities */
if(MY_LEVEL < 12) {
  write("You must be at least level 12 to solve this task.\n");
  return 1; }
if(MY_GUILD_EXP==669) {
  if(str2=="players/nooneelse/mazeforest/m_forest_chamber") {
    if(MY_GUILD_EXP > 669) {
      write("You have already done this one.\n");
      return 1; }
    ok_solve_it();
  }
else {
  write("You have NOT yet solved the task!\n");
  return 1; }
}

  /* Guild task 5 - solve to use level 15 abilities */
if(MY_LEVEL < 15) {
  write("You must be at least level 15 to solve this task.\n");
  return 1; }
if(MY_GUILD_EXP==670) {
  fire_sword = present("sword of fire", MY_PLAYER);
  stone_sword = present("stone cutter sword", MY_PLAYER);
  frost_sword = present("sword of frost", MY_PLAYER);
  if(str2=="room/giant_conf" && (fire_sword && stone_sword && frost_sword)) {
    if(MY_GUILD_EXP > 670) {
      write("You have already done this one.\n");
      return 1; }
    ok_solve_it();
    destruct(fire_sword);
    destruct(stone_sword);
    destruct(frost_sword);
    write("A giant gold bat comes and takes the three swords and gives\n"+
            "you some gold.\n");
    MY_PLAYER->add_money(3000);
    MY_FANGS->tell_my_room(
            MY_NAME_CAP+" mumbles something, then you see a giant gold\n"+
                  "bat fly in to collect 3 swords and fly away.");
  }
else {
  write("You have NOT yet solved the task!\n");
  return 1; }
}

  /* Guild task 6 - solve to use level 18+ abilities */
if(MY_LEVEL < 18) {
  write("You must be at least level 18 to solve this task.\n");
  return 1; }
if(MY_GUILD_EXP==671) {
  if(present("triceratop egg", MY_PLAYER) && present("vamptask6", MY_PLAYER)) {
    if(MY_GUILD_EXP > 671) {
      write("You have already done this task!\n");
      return 1; }
    ok_solve_it();
    destruct(present("triceratop egg", MY_PLAYER));
    destruct(present("vamptask6", MY_PLAYER));
    return 1; }
else {
  write("You have NOT yet solved the task!\n");
  return 1; }
}

if(MY_GUILD_EXP==672)
  write("You have solved the guild's tasks!\n");
  return 1; }

ok_solve_it() {
  MY_PLAYER->add_guild_exp(1);
  MY_PLAYER->save_me();
  write("You have solved the guild's task!\n");
}
