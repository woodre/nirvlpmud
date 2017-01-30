my_cmd(str){
    string command, arg, cmd_file;
    if(!str || str == "") return 0;
    if (sscanf(str, "%s %s", command, arg) != 2) command = str;
    cmd_file = "/players/languilen/tools/cmds/_" + command;
    if(file_size(cmd_file + ".c") > 0) return (int)call_other(cmd_file,"cmd_" + command, arg);
    return 0;
}
