cmd_ejunk(arg){
    if(!arg){
       write("you must supply a string\n");
       return 1;
    }
    emit_channel("junk", arg+"\n");
    return 1;
}
