#define CON capitalize(owner->query_real_name())
#define CTP capitalize(this_player()->query_real_name())
id(str) { return str=="summon"; }
object owner;
reset(arg){
	if(arg) return;
	if(!arg) owner=0;
}
set_owner(ob) { owner=ob; }
init(){
call_out("hb",2);
input_to("domehard");
	add_action("domehard","domehard");
}
domehard(str){
	if(str=="yes" || str=="y"){
	say(CON+"'s dragon descends from the sky and takes "+CTP+" away.\n");
	move_object(this_player(), environment(find_player(owner->query_real_name())));
	command("look", this_player());
	say(CON+"'s dragon drops "+CTP+" to the ground and flies into the sky.\n");
	destruct(this_object());
	return 1;
	} else{
	tell_object(owner, capitalize(this_player()->query_real_name())+ " has refused your summons.\n");
	write("You refuse "+capitalize(owner->query_real_name())+"'s summon.\n");
	destruct(this_object());
	return 1;
	}
}
hb(){
	if(owner==0){
	destruct(this_object());
	}
call_out("hb",2);
}
get() { return 1; }
