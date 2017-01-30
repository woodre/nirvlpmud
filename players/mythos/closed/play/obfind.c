id(str) { return str == "obfind"; }

drop() { return 1; }

init() {
add_action("obf","obf");
}

obf(str) {
string name;
object ob;
int i,h;
int count;
int num;
object j;
ob = users();
count = -1;
num = 0;
write("Who has objects created by "+str+"\n");
for(i=0;i<sizeof(ob);i++) {
  j = deep_inventory(ob[i]);
  for(h=0;h<sizeof(j);h++) {
   if(creator(j[h]) == str) {
   if(count == -1) count = 0;
     if(!count) { write(ob[i]->query_real_name()+" ");
    num = num + 1; }
     count = count + 1;
   } }
  if(count != -1)
     {
  if(count) { write(count); count = -1; }
else write("0");
  write("\n");
  }
}
  write("people: "+num+"/"+sizeof(ob)+"\n");
return 1; }
