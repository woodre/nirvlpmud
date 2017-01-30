id(str) {
     if(str=="trans") {return 1;}
    }
short() {return 0;}
drop() {return 0;}
get() {return 0;}
weight() {return 0;}
  object play1;
     string play;
init() {
    write(play);
    write(" would like to beam you to the Enterprise.\n");
    write("To be beamed up type beam me up .\n");
    input_to("beam");
  }
reset(arg){
if(arg) return;
call_out("dest_me", 60);
}
dest_me(){
tell_room(environment(), "You reject the offer.\n");
tell_object(play1,this_player()->query_name());
  tell_object(play1," did not wish to be beamed aboard.\n");
destruct(this_object());
return 1;
}
set_play(str) {
   play=str;
  }
set_play1(arg) {
  play1=arg;
  }
beam(str) {
    object beam;
       beam=find_player(play);
    if(str=="beam me up") {
        energize();
        tell_object(play1,this_player()->query_name());
        tell_object(play1," has been beamed aboard.\n");
remove_call_out("dest_me");
     destruct(this_object());
        return 1;
       }
     tell_object(play1,this_player()->query_name());
     tell_object(play1," did not wish to be beamed aboard.\n");
     write("You have not been beamed aboard.\n");
remove_call_out("dest_me");
     destruct(this_object());
     return 1;
}
energize() {
    write("You have a strange feeling.\n");
    write("You see your see your own body from above.\n");
    write("You`re not dead.\n");
    write("You are in a transporter beam.\n");
    write("You rematerialize.\n");
    write("\n\n\n");
    write("To get healed either go all the way n to pub,\n");
    write("or go to upper level all the way s in main hallway.\n");
    write("To sell something go to the quartermasters[n,n,w,n].\n");
    write("\n\n\n");
    write("also if you have any characters related to sci-fi you would like\n");
    write("to kill,send me(rich) a mail message and i`ll see what i can do.\n");
    write("\n\n");
    say(this_player()->query_name());
    say(" disappears in a blinding flash of light and sound.\n");
    call_other(this_player(),"move_player","#players/rich/trans_room");
remove_call_out("dest_me");
destruct(this_object());
    return 1;
}
