 /*### This file controls the 'help' functions ###*/

#define HELPPATH "/players/blue/closed/shadow/help/"
help_subject(str) {
   int lines;
   string file;
   file = HELPPATH+str;
   if(!read_file(file)) {
      write("No info on '"+str+"'.\n");
      return 1;
   }
   lines = sizeof(explode(read_file(file), "\n"));
   if(!lines) {
      write("No info found on "+str+".\n");
      return 1;
   }
   write(read_file(file, 1,lines)+"\n");
   return 1;
}
