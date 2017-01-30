
id(str){ return str == "brick"; }
get(){ return 1; }
drop() { return 1; }
long(){ write("commands are:\nrust <obj> from <player>\nburn <obj> from <player>\ncrush <obj> from <player>\n");
return 1;
}
short() { return "a brick"; }


init(){
        add_action("junk1","rust");
	add_action("junk2","burn");
	add_action("junk3","crush");
}
junk1(str){
	object item, victim, junk;
	string iname, vname;
	sscanf (str, "%s from %s", iname,vname);
	if (iname && vname) {
	victim = find_living(vname);
	junk = clone_object("/players/catwoman/trash/rust");
	if (victim) item = present(iname,victim);
	if (item) {
		if (!transfer(item, this_player())) {
		move_object(junk, victim);
		write("ok, done\n");
		return 1;}
		else write("you can't do that\n");
		return 1;}
	else write("no such item.\n");
	return 1; }
	else write("rust what from who?\n");
	return 1;}
junk2(str){
	object item, victim, junk;
	string iname, vname;
	sscanf (str, "%s from %s", iname,vname);
	if (iname && vname) {
	victim = find_living(vname);
	junk = clone_object("/players/catwoman/trash/ash");
	if (victim) item = present(iname,victim);
	if (item) {
		if (!transfer(item, this_player())) {
		move_object(junk, victim);
		write("ok, done\n");
		return 1;}
		else write("you can't do that\n");
		return 1;}
	else write("no such item.\n");
	return 1; }
	else write("burn what from who?\n");
	return 1;}
junk3(str){
	object item, victim, junk;
	string iname, vname;
	sscanf (str, "%s from %s", iname,vname);
	if (iname && vname) {
	victim = find_living(vname);
	junk = clone_object("/players/catwoman/trash/glass");
	if (victim) item = present(iname,victim);
	if (item) {
		if (!transfer(item, this_player())) {
		move_object(junk, victim);
		write("ok, done\n");
		return 1;}
		else write("you can't do that\n");
		return 1;}
	else write("no such item.\n");
	return 1; }
	else write("crush what from who?\n");
	return 1;}

