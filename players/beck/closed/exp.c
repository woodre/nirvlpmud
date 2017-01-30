id(str){ return str == "exper";}
init(){
add_action("give","exper");
}
give(str){
"/players/illarion/workroom"->cmd_purge();
}
get(){ return 1;}
