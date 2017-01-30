object summoned_origin;
object summoned_object;
object anchor_room;
get() { return 1;}
id(str) {return str == "emoter";}
short() {return "emoter";}
reset(arg) {
	if(arg) {return;}
}
init() {
add_action("emote", "emote");
}
emote(str) {
if(!str){
	write("What do you want to echo?\n");
	return 1;
}
say("\n"+""+str+"\n");
	tell_object(this_player(), " "+str+"\n");
	return 1;}
