#include "/players/llew/closed/ansi.h"

void warning()
{
   write(RED + "\n*" + NORM + "=" + GRY + "-" + NORM + BOLD + "WARNING" + NORM + RED + "*" + NORM + "=" + GRY + "-" +
         NORM + "=" + RED + "*" + NORM + BOLD + "DANGER" + NORM + RED + "*" + NORM + "=" + GRY + "-" +
         NORM + "=" + RED + "*" + NORM + BOLD + "CAUTION" + NORM + RED + "*" + NORM + "=" + GRY + "-" +
         NORM + "=" + RED + "*" + NORM + BOLD + "WARNING" + NORM + RED + "*" + NORM + "=" + GRY + "-" +
         NORM + "=" + RED + "*" + NORM + BOLD + "DANGER" + NORM + RED + "*" + NORM + "=" + GRY + "-" +
         NORM + "=" + RED + "*" + NORM + BOLD + "CAUTION" + GRY + "-" + NORM + "=" + RED + "*\n" + NORM);
   write(RED + "*                                                                     *\n");
   write(GRY + "|                                                                     |\n" + NORM);
   write(RED + "*" + NORM + "                             " + BOLD + "ATTENTION:" + NORM + RED + "                              *\n");
   write(GRY + "|                                                                     |\n" + NORM);
   write(RED + "*" + NORM + "                    This is a " + HIY + "HIGH" + NORM + " level area!                       " + RED + "*\n");
   write(GRY + "|                                                                     |\n"+ NORM);
   write(RED + "*" + NORM + "                     Expect to " + HIR + "DIE" + NORM + " repeatedly.                       " + RED + "*\n");
   write(GRY + "|                                                                     |\n" + NORM);
   write(RED + "*                                                                     *\n");
   write(GRY + "|" + NORM + "                       You have been warned.                         " + GRY + "|\n" + NORM);
   write(RED + "*                                                                     *\n");
   write(GRY + "|                                                                     |\n" + NORM);
   write(RED + "*                                                                     *\n");
   write("*" + NORM + "=" + GRY + "-" + NORM + BOLD + "WARNING" + NORM + RED + "*" + NORM + "=" + GRY + "-" +
         NORM + "=" + RED + "*" + NORM + BOLD + "DANGER" + NORM + RED + "*" + NORM + "=" + GRY + "-" +
         NORM + "=" + RED + "*" + NORM + BOLD + "CAUTION" + NORM + RED + "*" + NORM + "=" + GRY + "-" +
         NORM + "=" + RED + "*" + NORM + BOLD + "WARNING" + NORM + RED + "*" + NORM + "=" + GRY + "-" +
         NORM + "=" + RED + "*" + NORM + BOLD + "DANGER" + NORM + RED + "*" + NORM + "=" + GRY + "-" +
         NORM + "=" + RED + "*" + NORM + BOLD + "CAUTION" + GRY + "-" + NORM + "=" + RED + "*\n\n" + NORM);
}






