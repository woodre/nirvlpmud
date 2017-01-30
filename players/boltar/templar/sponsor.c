string sponsors;
int ok;
reset(arg) {
if(arg) return;
sponsors=allocate(4);
return 1;
}
add_sponsor(name,rank){
if(!sponsors[0] && rank < 9){ sponsors[0]=name; return 1;}
if(!sponsors[1] && rank < 9 ){ sponsors[1]=name; return 1;}
if(!sponsors[2]) sponsors[2]=name;
if(sponsors[2]) ok = 2;
if(rank > 8) ok = 2;
return 1;
}
query_sponsored() { return ok;}
query_auto_load() {return "players/boltar/templar/sponsor.c:"+sponsors[0]+"~~"+sponsors[1]+"~~"+sponsors[2]+"~~"+ok; }
id(str) {
return str == "templar_sponsorob";
}
init_arg(arg) {
sscanf(arg,"%s~~%s~~%s~~%d",sponsors[0],sponsors[1],sponsors[2],ok);
}
check_sponsor(name) {
if(sponsors[0] == name || sponsors[1] ==name || sponsors[2] == name) 
return 1;
return 0;
}
drop(str) { return 1;}
