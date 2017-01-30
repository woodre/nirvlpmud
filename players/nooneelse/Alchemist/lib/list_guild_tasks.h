/*
  list_guild_tasks.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* List the guild's tasks */
list_guild_tasks() {
  object obj;

  write(NORM+CYN+"To use the next level of abilities, you must:\n\n");
  switch (MY_GUILD_RANK) {
    case 10:  /* solve this to use level 5-7 rank 10 abilities */
      write("Find the demon priest of the Demon Lord in his monastery.\n");
      break;
    case 20:  /* solve this to use level 8-11 rank 20 abilities */
      write("Find the sturdy, short guy.  (Don't forget your rope & torch.)\n");
      break;
    case 40:  /* solve this to use level 12-14 rank 40 abilities */
      write("Search the bones and find the Lord of Minotaurs, Baphomet.\n"+
	        "(You don't need to kill him.  Just find him, then type\n"+
            " 'solve task'.)\n");
    case 60:  /* solve this to use level 15-18 rank 60 abilities */
      write("Find the ironwood coffin near Sebastian the Druid.\n");
      break;
    case 80:  /* solve this to use level 19+ rank 80 abilities */
      write("Kill the four giants.  Get their swords and 'solve task'\n"+
            "in their conference room.\n");
      break;
  }
  write(NORM);
  if (MY_GUILD_RANK>=80)
    write(NORM+CYN+"\nYou have solved the guild's tasks!  CONGRATULATIONS!\n"+NORM);
  return 1;
}
