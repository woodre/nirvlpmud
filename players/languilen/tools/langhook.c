/*
 * A simple cmd hook
*/
#include "/players/languilen/closed/ansi.h"
#define ENVOB environment(this_object())
#define TP this_player()
#define CMD_D "/players/languilen/tools/test_d.c"

string flags;

id(str){ 
   return str == "hat" || str == "black hat" ||
   str == "notarmor";
}

short() {
   string msg;
   msg = "A wide brimmed "+BOLD+BLK+"black"+NORM+" hat";
   return msg;
}

void long() {
   write("Type 'hat_hints' for more information.\n");
}

void init(){
   if(ENVOB){
      if(ENVOB->is_player() && ENVOB == this_player() && !TP->is_kid()){
         add_action("hat_help","hat_hints");
         add_action("dest_cmd_ob","un_cmd");
         add_action("flag_test"); add_verb("ftest");
         add_action("flag_set"); add_verb("fset");
         add_action("flag_clear"); add_verb("fclear");
         add_action("my_cmd"); add_xverb("");
      }
      if(!flags){ flags = " "; }
   }
   if((string)ENVOB->query_real_name() != "languilen") destruct(this_object());
}

get(){ return 1;}
drop(){ return 1;}

my_cmd(str){ 
    if(CMD_D->my_cmd(str)) return 1;
    return 0;
}

hat_help(){
    write("The commands change constantly.\n");
    return 1;
}
dest_cmd_ob(){
    write("Destroying the cmd ob..\n");
    destruct(this_object());
    return 1;
}

flag_test(str){
     int i;
     if(!str){
        write("You must supply a bit-value to test.\n");
        return 1;
     }
     if(sscanf(str, "%d", i)!=1){
        write("You must use a numerical value.\n");
        return 1;
     }
     if(i<0 || i>6){
        write("Use a number between 1 and 6.\n");
        return 1;
     }
     if(test_bit(flags, i-1)){
        write("Flag "+i+" is set!\n");
     } else { write("Flag "+i+" is off.\n"); }
     return 1;
}

flag_set(str){
     int i;
     if(!str){
        write("You must supply a bit-value to set.\n");
        return 1;
     }
     if(sscanf(str, "%d", i)!=1){
        write("You must use a numerical value.\n");
        return 1;
     }
     if(i<0 || i>6){
        write("Use a number between 1 and 6.\n");
        return 1;
     }
     flags=set_bit(flags, i-1);
     write("Flag "+i+" has been set!\n");
     return 1;
}

flag_clear(str){
     int i;
     if(!str){
        write("You must supply a bit-value to clear.\n");
        return 1;
     }
     if(sscanf(str, "%d", i)!=1){
        write("You must use a numerical value.\n");
        return 1;
     }
     if(i<0 || i>6){
        write("Use a number between 1 and 6.\n");
        return 1;
     }
     i-=1;
     flags=clear_bit(flags, i);
     write("Flag "+i+" has been cleared!\n");
     return 1;
}

