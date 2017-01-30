gline() {
object ob;
int h;
string msg;
ob = users();
write(GRN);
write("........................................................................\n");
write(NORM);
write("      Name\t\tLevel\thp/10\tWhere\n");
write(GRN);
write("........................................................................\n");
write(NORM); 
for(h=0;h<sizeof(ob);h++) {
if(ob[h]) {
if(ob[h]->query_invis() < tl || tl > 99 && ob[h]->query_level() > 0) {
msg = "";
if(!interactive(ob[h])) msg += "x";
if(ob[h]->is_ghost()) msg += "*";
if(query_idle(ob[h]) > 120) msg += "i"; 
if(ob[h]->query_attack()) msg += "C";
if(ob[h]->query_invis()) msg += "#";
while(strlen(msg) < 6) msg += " ";
msg += capitalize(ob[h]->query_real_name());
if(strlen(ob[h]->query_real_name()) < 2) msg += "\t";
if(strlen(ob[h]->query_real_name()) < 10) msg += "\t";
msg += "\t";
msg += ob[h]->query_level();
msg += "\t";
msg += ob[h]->query_hp() * 10 / ob[h]->query_mhp();
msg += "/10";
if(!environment(ob[h])) msg += "\tLOGIN\n";
else msg += "\t"+environment(ob[h])->short()+"\n";
write(msg); 
} } }
write("\nx = Disconnected, * = ghost, i = idle, C = Combat, # = invis\n"); 
write(GRN);
write("........................................................................\n");
write(NORM); 
return 1; }
