#define ND_DAEMON "/obj/verte/nd-daem"

/*
Originally written by Mythos for his Sci-watch.
Modified by Feldegast for use in /bin
4-14-00
*/
#define ESC ""
#define GRN ESC+"[32m"          /* Green    */
#define NORM ESC+"[2;37;0m"      /* Puts everything back to normal */

int cmd_time(string str) {
 string data;
  write("\nDisplay: "+GRN+ctime()+NORM+" CST\n");
  call_other("/room/church.c","long","clock");
  write("\n");

/*
 switch(data=(string)ND_DAEMON->query_data_string())
 {
  case "dawn":
   write("Dawn is rising upon Nirvana.\n");
   break;
  case "day":
   write("Day has spread throughout Nirvana.\n");
   break;
  case "dusk":
   write("Dusk is slowly falling.\n");
   break;
  case "night":
   write("Night has fallen upon Nirvana.\n");
   break;
  default:
   write("Unknown case "+data+": Contact Vertebraker immediately.\n");
   log_file("nd-daem.error",
    ctime()+" Bad case: "+data+"\n");
   break;
 }
*/
  say(capitalize((string)this_player()->query_name())+" checks the time.\n");
  return 1;
}
