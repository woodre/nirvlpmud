/*
  list_guild_tasks.h
*/

#include "defs.h"

/* List the guild's tasks */
list_guild_tasks() {
  object obj;

if (MY_GUILD_EXP < 666 || MY_GUILD_EXP > 672) {
  write("Something is wrong with your guild experience points.\n"+
        "You need to type 'restart guild exp'.\n");
  return 1; }

if (MY_GUILD_EXP < 672)
  write("To use the next level of abilities, you must:\n\n");

  /* solve this to use level 3 abilities */
if (MY_GUILD_EXP==666) {
  write("Find the demon priest of the Demon Lord in his monastery.\n");
  return 1; }

  /* solve this to use level 5 abilities */
if (MY_GUILD_EXP==667) {
  write("Find the sturdy, short guy.  (Don't forget your rope.)\n");
  return 1; }

  /* solve this to use level 7-10 abilities */
if (MY_GUILD_EXP==668) {
  write("Search the bones and find the Lord of Minotaurs, Baphomet.\n"+
        "(You don't need to kill him.  Just find him, then type\n"+
        " 'solve task'.)\n");
  return 1; }

  /* solve this to use level 12 abilities */
if (MY_GUILD_EXP==669) {
  write("Find the ironwood coffin near Sebastian the Druid.\n");
  return 1; }

  /* solve this to use level 16 abilities */
if (MY_GUILD_EXP==670) {
  write("Kill the four giants.  Get their swords and 'solve task'\n"+
        "in their conference room.\n");
  return 1; }

  /* solve this to use level 19 abilities */
/* this task has been replaced by the one created by Eurale - see below
  if (MY_GUILD_EXP >= 671) {
    write("Find the gloves of thievery.  While worn by a vampire,\n"+
          "they'll protect them from harm while holding holy objects.\n"+
          "Their hiding place will change periodically.\n"+
          "At this time, they are buried ");
    call_other(MASTER_WORKROOM, "???", 0);
    obj=find_object(MASTER_WORKROOM);
    write(obj->query_gloves_desc_name()+".\n");
    if (MY_GUILD_EXP==671) return 1;
  }
*/
  /* new level 19 task description by Eurale */
if (MY_GUILD_EXP == 671) {
  write("You must discover and unearth a rare triceratops egg.\n");
  return 1; }

if (MY_GUILD_EXP==672)
  write("\nYou have solved the guild's tasks!  CONGRATULATIONS!\n");
  return 1; }
