#include "/players/llew/closed/ansi.h"

deed(str) {

   string datetime, junk;

   if(!str) {
      write("Please enter something to report.\n");
      return 1;
   }
   if(str == "list") {
      write(BOLD+"\tLog of recent events\n"+NORM);
      tail("/players/llew/VALIANT_DEEDS");
      write("\n");
      return 1;
   }

   datetime = ctime(time());
   sscanf(datetime, "%s %s", junk, datetime);

   write_file("/players/llew/VALIANT_DEEDS", HIB+"["+NORM+BOLD+datetime+HIB+"] "+NORM);
   str=format(str,64);
   str=implode(explode(str[0..(strlen(str)-2)],"\n"),"\n"+pad("",23));
   write_file("/players/llew/VALIANT_DEEDS",str+"\n");
   write("Ok.\n");
   return 1;
}
