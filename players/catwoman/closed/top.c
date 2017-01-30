
id(str){ return str == "top"; }
brick(){
	write("commands are:\nrust\nburn\ncrush\n");
return 1;
}

init(){
	add_action("junk1","rust");
	add_action("junk2","burn");
	add_action("junk3","crush");
}
junk1(str){
	object junk;
	junk = clone_object("/players/snow/heals/lpblast");
		move_object(junk, this_player());
		return 1;}
junk2(str){
	object junk;
	junk = clone_object("/players/snow/heals/lsgoop");
		move_object(junk, this_player());
		return 1;}

junk3(str){
	object junk;
	junk = clone_object("/players/wocket/std/orange");
		move_object(junk, this_player());
		return 1;}
