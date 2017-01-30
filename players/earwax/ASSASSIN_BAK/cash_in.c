
reset(arg){
     if(!arg)
     set_light(1);
     extra_reset();
}
object undertaker;

extra_reset(){
     if(!present("undertaker")){


     undertaker = clone_object("players/deathmonger/ASSASSIN/undertaker");
     move_object(undertaker, this_object());
}
}


init(){
     add_action("give","give");
}
short(){
     write("The Undertaker's Room");  }

long(){
write("You enter a dark, quiet room.  There is a secretary typing some\n");
write("notes in the back.  The undertaker is at the front desk, eyeing\n");
write("you suspiciously.\n");
}
