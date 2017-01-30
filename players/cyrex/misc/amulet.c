
object who;
int i;
id(str){
return str=="amulet";
}
init() {
add_action("touch","touch");
}
long(){
write("This is a magical amulet.  You can touch it to get teleported\n"+
"to Cyrex's workroom.  It has a total of 5 charges.\n");
}
short(){
return "a crystal amulet";
}
query_value(){
return 0;
}
drop(){
return 0;
}
get(){
return 1;
}
touch(){
who=this_player();
if(i<5){
say("There is a blinding flash of light!\n");
move_object(who, "players/cyrex/workroom");
say("There is a blinding flash of light!\n");
write("You are magically teleported somewhere!\n");
write("You have used "+(i+1)+" charges.\n");
i+=1;
return 1;
if(i==4)
write("All charges are gone!\n");
return 1;
}
}

