#define TP this_player()
#define CAN_DO ({ "n","s","e","w","ne","nw","se","sw","u","d" })
 
string speed_dirs;
 
id(str) { return str == "ninjaspeed" || str == "actuators"
              || str == "leg actuators" || str == "speedobj"; }
get() { return 1; }
drop() { return 1; }
long() {
   write("Powerful leg actuators that will let you use your ninja speed\n"+
         "to its fullest potential. To activate, 'ninjaspeed <dir>,<dir>'\n"+
         "for any number of <dir>'s. 'ns <dir>,<dir>,etc' works as well.\n"+
         "You may only ninjaspeed [n,s,w,e,nw,ne,sw,se,u,d] at this time.\n");
  return 1;
}
 
init() {
  if(!present("CyberNinja Implants",TP)
     && TP->query_real_name() != "snow"
     && TP->query_real_name() != "dune") {
        write("You cannot use this sorry.\n");
        destruct(this_object());
  }
  if(!TP->query_ghost()) {
   add_action("ninja_speed","ninjaspeed");
   add_action("ninja_speed","ns");
  }
}
 
ninja_speed(str) {
   int i;
   if(!str) {
     write("Usage: speed <dir>,<dir>,etc.\n");
     return 1;
   }
   speed_dirs = str;
   write("~~LEG ACTUATORS ACTIVATED: NINJA SPEED MODE~~\n"+"\n");
   do_speed();
   return 1;
}
 
do_speed() {
   string cmd_now, cmd_more;
   while(speed_dirs &&
         sscanf(speed_dirs, "%s,%s", cmd_now, cmd_more) == 2) {
     if(member_array(cmd_now, CAN_DO) == -1) {
       write("You cannot SPEED ["+cmd_now+"]\n");
       speed_dirs = 0;
     } else {
       write("~~SPEEDING~~ ["+cmd_now+"]\n");
       command(cmd_now,TP);
       speed_dirs = cmd_more;
     }
   }
   if(speed_dirs) {
     if(sscanf(speed_dirs, "%s,", cmd_now) == 1) {
       if(member_array(cmd_now, CAN_DO) == -1) {
         write("You cannot SPEED ["+cmd_now+"]!\n");
         return 1;
       }
       write("~~SPEEDING~~ ["+cmd_now+"]\n");
       command(cmd_now,TP);
     } else {
       if(member_array(speed_dirs, CAN_DO) == -1) {
         write("You cannot SPEED in that direction!\n");
         return 1;
       }
       write("~~SPEEDING~~ ["+speed_dirs+"]\n");
       command(speed_dirs,TP);
     }
   }
   return 1;
}
