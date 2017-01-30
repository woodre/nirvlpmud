int count;
id(str){return str=="counter";}
query_value(){return 0;}
inc_count(){ 
count++;
if (count >=100) {
write("You have attracted the attention of the Predator!\n");
write("\nYou feel yourself being summoned towards him.\n");
say(capitalize(this_player()->query_name())+" gets sucked up in some kind of beam and vanishes.\n");
move_object(this_player(),"players/heroin/hunting_grounds/predsplace.c");
write("\n\n");
}
}
init(){
add_action("leave_who","leave");
}
leave_who() {
object who;
if(this_player()->query_ghost()) {
write("You are not yet worthy of the hunt..go to the church\n");
move_object(this_player(),"room/church");
command("look",this_player());
destruct (this_object());
return 1;
}
}
get(){return 1;}
drop(){return 1;}
