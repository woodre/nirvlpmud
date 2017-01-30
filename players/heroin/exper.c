int count;
id(str){return str=="counter";}
query_value(){return 0;}
query_weight() {return 0;}
inc_count(){ 
count++;
if (count >=60) {
write("You have attracted the attention of the Predator!\n");
write("\nYou feel yourself being summoned towards him.\n");
say(capitalize(this_player()->query_name())+" gets sucked up in some kind of beam and vanishes.\n");
move_object(this_player(),"players/heroin/hunting_grounds/predsplace.c");
write("\n\n");
command("look",this_player());
destruct(this_object());
}
}
get(){return 1;}
drop(){return 1;}
