gline(str) {
string what,nu;
string typ;
int h;
  if(!str || str == "") { gwho(); return 1; }
  if(str == "w") { gwhoall(); return 1; }
  if(sscanf(str,"%s %s",nu,what) == 2 ) {
    if(nu != "a" && nu != "e") 
      what = " "+tp->query_name()+" conveys: "+str;
    else {
    if(nu == "a") what = " "+what+ " <"+tp->query_name()+">";
    else what = " "+tp->query_name()+" "+what;
    }
  } 
    if(what)
  what = format(what,50);
  if(formtype == "tech") typ = "T";
  else typ = "M";
  what = RED+"< < "+NORM+BOLD+typ+NORM+RED+" > >"+NORM+what;
  h = sizeof(line_listen);
  while (h--) if(line_listen[h]) tell_object(line_listen[h], what);
return 1; }

gwho() {
int h;
string msg;
write(RED);
write("________________________________________________________________________\n");
write(NORM);
write("     Name\t\tLev\tWhere\n");
write(RED);
write("________________________________________________________________________\n");
write(NORM);
h = sizeof(line_listen);
while (h--) { 
if(line_listen[h]) {
if(line_listen[h]->query_invis() < 20) {
msg = "";
if(!interactive(line_listen[h])) msg += "x";
if(line_listen[h]->is_ghost()) msg += "*";
if(query_idle(line_listen[h]) > 120) msg += "i"; 
if(line_listen[h]->query_attack()) msg += "C";
while(strlen(msg) < 5) msg += " ";
msg += capitalize(line_listen[h]->query_real_name());
if(strlen(line_listen[h]->query_real_name()) < 8) msg += "\t";
msg += "\t";
msg += present("bgo",line_listen[h])->query_level();
if(present("bgo",line_listen[h])->query_form() == "tech") msg += " T";
else msg += " M";
if(!environment(line_listen[h])) msg += "\tLOGIN\n";
else msg += "\t"+environment(line_listen[h])->short()+"\n";
write(msg);
} } }
write("\nx = Disconnected, * = ghost, i = idle, C = Combat\n");
write(RED);
write("________________________________________________________________________\n");
write(NORM);
return 1; } 

gwhoall() {
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
