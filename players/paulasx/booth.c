
id(str){ return str == "booth" || str == "death booth"; }
short(){ return "a Dangerous Escape from Reality!"; }
reset(arg){
     if(!arg){
     phone = clone_object("players/deathmonger/ASSASSIN/phone");
     move_object(phone, this_object());
     move_object(this_object(), "room/alley");
     }
}
long(){ 
    if(present(this_player(), this_object())){
       write("An immaculately clean phone booth.  No one dares write any graffiti here.\n");
    }
    else {
   write("This phone booth is painted red.  It seems to have an important\n");
   write("purpose.  Maybe if you have some sort of emergency you should\n");
   write("enter the booth.\n");
   }
}

init(){
   add_action("enter", "enter");
   add_action("leave", "leave");
}

enter(str){
    if(str == "booth"){
     say(capitalize(this_player()->query_name())+" enters the phone booth.\n");
     write("You enter the phone booth.\n");
     move_object(this_player(), this_object());
     return 1;
}
}

leave(){
     say(capitalize(this_player()->query_name())+" leaves the phone booth.\n");
     write("You leave the phone booth.\n");
     tell_room(find_object("room/alley"),
     capitalize(this_player()->query_name())+" leaves the phone booth.\n");
     move_object(this_player(), "room/alley");
     return 1;
}
