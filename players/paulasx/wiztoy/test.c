id(str) { return str=="test"; }
short() { return 0; }
long() { write("This is the long.\n"); }
drop() { return 1; }
get() {return 1;}
init() {
add_action("hpt","hpt");
}
hpt(str) {
object ob;
if(!str) return;
ob = find_living(str);
if(!ob){
write("WAND:  Nope, not there.\n");
return 1; }
write ("HP: "+ob->query_hp()+" / "+ob->query_mhp()+"  ");
write("SP: "+ob->query_sp()+" / "+ob->query_msp()+"\n");
return 1;
}
