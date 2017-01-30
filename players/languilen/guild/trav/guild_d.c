#include "guilddefs.h"

guild_cmd(str){
     string command, arg, cmd_file;
     if(!str || str == "") return 0;
     if (sscanf(str, "%s %s", command, arg) != 2) command = str;
     cmd_file = GUILDCMDS + "_" + command;
     if(file_size(cmd_file+".c") > 0) return (int)call_other(cmd_file,"cmd_" + command, arg);
     return 0;
}

string query_guild_title(){
     switch(TP->query_guild_rank()){
           case 0: return "";                     break;
           case 1: return "The Curious";          break;
           case 2: return "The Wanderer";         break;
           case 3: return "The Nomad";            break;
           case 4: return "The Journeyman";       break;
           case 5: return "The Worldly";          break;
           case 6: return "The Bard";             break;
           case 7: return "The Traveler";         break;
     }
}

