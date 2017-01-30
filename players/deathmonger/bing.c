
init(){
   call_out("thing", 60);
}
id(str){ return str=="thing"; }

thing(){
    if(find_player("mizan")){
   tell_object(find_player("mizan"), "Barney tells you: Are you still editing?  I'll try again later.");
}
   call_out("thing", 60);
    return 1;
}
