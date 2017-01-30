/* Adapted from Snow's Oblesik 6/12/98 Much thanks to Snow for his help  */

#include "/players/snakespear/closed/ansi.h"
id(str) { return str == "computer"; }
short() {return "A Y2K Computer"; }
long() {
  write("  This is a computer setup to communicate with Snakespear\n"+
        "To give any comments, suggestions, complaints, or whatever\n"+
        "You must: smail <message>\n"+
        "Example: smail Your area rocks, when you making more?\n");
return 1;
    }


init() {

add_action("smail","smail");

   }

smail(arg)  {
if(!arg) { write("smail <message>\n"); return 1; }
else
if(find_player("snakespear")) tell_object(find_player("snakespear"),HIM+"SMAIL: "+NORM+this_player()->query_name()+" smails: "+arg+" ."+HIM+"DONE\n"+NORM);

write_file("/players/snakespear/log/smail",ctime(time())+" "+
      this_player()->query_real_name()+" says: "+arg+"\n");
   write(HIW+"Message sent! Thank you..\n"+NORM);
return 1;

  }
