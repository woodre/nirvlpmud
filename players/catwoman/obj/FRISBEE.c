
string name;
id(str){
return(str == "frisbee");}
get(){return 1;}
short(){return "A frisbee";}
long(){write("A neon green frisbee. To throw type: Throw <player>\n");}
reset(){}
init(){
add_action("throw","throw");
}
throw(str){
object ob;
ob = find_player(str);
if(!ob){
write("No person is playing right now!\n");
return 1;
}
write("You throw the frisbee to "+capitalize(str)+".\n");
move_object(this_object(), ob);
gossip("A frisbee flies over your head to "+ capitalize(str)+".\n");
tell_object(ob, "You gracefully catch a frisbee thrown to you.\n");
return 1;
}

