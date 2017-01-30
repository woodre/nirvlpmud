string sponsor;
string name;
int ok;
reset(arg) {
if(arg) return;

return 1;
}
add_sponsor(name){
sponsor = name;
	return 1;
}
query_sponsored() { return ok;}
query_auto_load() { return "players/boltar/templar/sponsor.c:"+sponsor+""; }
id(str) {
return str == "templar_sponsorob";
}
init_arg(arg) {
sscanf(arg,"%s",sponsor);
}
check_sponsor(name) {
if(sponsor == name) 
return 1;
return 0;
}
is_sponsored(){ return name; }
drop(str) { return 1;}
