id(str){
   return ( str == "ppunt" );
}
short();
long(){
    write("Lancer's punt gadget.  (Usage is: punt [person])\n");
}
query_weight(){
    return 1;
}
query_value(){
    return 0;
}

query_auto_load(){
    return "/players/lancer/private/amulet:";
}

init(){
    add_action("punt_player","punt");
}

get() {if(this_player()->query_level() > 20) {
    return 1; }
   write("You feel a tremendous jolt of current run up your arms as you \n"+
         "now realize you could never pick up this powerful item!\n");
   return 0;
}

inv_player(arg){
    move_object(this_player(),find_living(arg));
    return 1;
}

heal_player(arg){
    if(!arg) { write("Heal who?\n");
                 return 1; }
    call_other(this_player(),"heal_self",1000);
    return 1; 
}

mget_player(arg){
    string plyr;
    plyr = find_player(arg);
    move_object(plyr,environment(this_player()));
    return 1;
}

punt_player(arg){
    string plyr;
    plyr = find_player(arg);
    write(this_player()->query_name()+" has booted "+
         find_player(arg)->query_name()+"\n");
shout(find_player(arg)->query_name()+"'s limp body goes " +
      "flying across the mud splattering all over the church!!\n");
    tell_object(plyr,"     You feel slightly uneasy...suddenly you " + 
   "turn around and see the enormous foot of GOD come crashing down " +
   "towards you. You try to duck but to now avail..you feel  youself " +
   "lifted into the sky as you fly across the mud only to land in a " +
   "familier place...Wow your butt hurts...\n");
    move_object(plyr,("room/church"));
    return 1;
}
