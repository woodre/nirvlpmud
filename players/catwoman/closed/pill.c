id(str){ return str == "pill";}
init(){
	add_action("swallow","swallow");
}
swallow(){
object victim;
string vname;
int arg, amt;
call_other(this_player,"add_phys_at(3,105)");
write("ok\n");
	return 1;}
