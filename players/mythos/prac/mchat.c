#include "/players/mythos/closed/ansi.h"
#define TITLE BOLD+"<"+NORM+RED+chan+NORM+BOLD+"> "+NORM
#define MAX 1000
#define tp this_player()
#define tpn tp->query_real_name()

string name;
string mem1,mem2,mem3,mem4,mem5;
int node;

id(str) { return str == "master_chat"; }

reset(arg) {
  if(arg) return;
  name = allocate(MAX);
  mem1 = allocate(MAX);
  mem2 = allocate(MAX);
  mem3 = allocate(MAX);
  mem4 = allocate(MAX);
  mem5 = allocate(MAX);
  node = ({-1});
  set_heart_beat(1);
}

chat(str) {
string chan,what,null;
int chnum;
string msg;
if(sscanf(str,"%s %s",chan,what) != 2) return 0;
chnum = chat_name(chan);
if(chnum == -1) return 0;
if(!mem_chat(chnum,tpn)) return 0;
msg = TITLE+capitalize(tpn)+" ";
if(sscanf(what,":%s",null)) { null = format(null,40);
                              msg += null; }
else { what = "chats: "+what; what = format(what,40);
       msg += what; }
anonchat(chnum,msg); 
return 1; }

chat_name(str) {
  return member_array(str,name);
}

mem_chat(int n,string wh) {
  if(mem1[n] == wh) return 1;
  if(mem2[n] == wh) return 2;
  if(mem3[n] == wh) return 3;
  if(mem4[n] == wh) return 4;
  if(mem5[n] == wh) return 5;
return 0; }

query_mem1(int n) { if(n < 0 || n > MAX) return 0; 
                    return mem1[n]; }
query_mem2(int n) { if(n < 0 || n > MAX) return 0; 
                    return mem2[n]; }
query_mem3(int n) { if(n < 0 || n > MAX) return 0; 
                    return mem3[n]; }
query_mem4(int n) { if(n < 0 || n > MAX) return 0; 
                    return mem4[n]; }
query_mem5(int n) { if(n < 0 || n > MAX) return 0; 
                    return mem5[n]; }


chat_who(str) {
int chnum;
string dude;
int h;
  chnum = chat_name(str);
  if(chnum == -1) return 0;
  if(!mem_chat(chnum,tpn)) return 0;
  write(""+
  "name\t\tgender\t\tlevel\t\tstatus\n"+RED+
  "_________________________________________________________\n\n"+NORM);
  h = 0;
dude = 0;
  while(h < 5) {
  if(h == 0) dude = mem1[chnum];
  if(h == 1) dude = mem2[chnum];
  if(h == 2) dude = mem3[chnum];
  if(h == 3) dude = mem4[chnum];
  if(h == 4) dude = mem5[chnum];
  if(dude) if(find_player(dude)) {
    write(capitalize(dude));
    if(strlen(dude) < 8) write("\t");
    write("\t"+find_player(dude)->query_gender()+
          "\t\t");
    write(find_player(dude)->query_level()+"\t\t");
    if(find_player(dude)->query_attack()) 
       write(BLU+"C"+NORM);
    if(find_player(dude)->is_ghost()) 
       write(BOLD+"D"+NORM);
    if(!find_player(dude)->query_interactive()) 
       write("dc");
    else if(query_idle(find_player(dude)) > 100) 
       write("I");
    write("\n");
  }
  dude = 0;
  h++; }
  write("\n"+RED+
  "_________________________________________________________\n"+
  " Status:<i> idle,<C> combat,<D> dead,<dc> discon   chat:"+str+"\n"+NORM);
  hearts();
return 1; }

checkfull(int which){
int j,i;
string dude;
j = 0;
i = 0;
 dude = 0;
  while(j < 5 && !i) {
  if(j == 0) dude = mem1[which];
  if(j == 1) dude = mem2[which];
  if(j == 2) dude = mem3[which];
  if(j == 3) dude = mem4[which];
  if(j == 4) dude = mem5[which];
  if(!dude) i = 1;
  j++; }
if(!i) return -1;
return (j-1); }

checkempty(int noop) {
int k,z;
string clue;
k = 0;
z = 1;
clue = 0;
while(k < 5 && z) {
  if(k == 0) clue = mem1[noop];
  if(k == 1) clue = mem2[noop];
  if(k == 2) clue = mem3[noop];
  if(k == 3) clue = mem4[noop];
  if(k == 4) clue = mem5[noop];
  if(clue) z = 0;
  k++; }
return z; }

createchat(string chann) {
int chnum;
if(!chann) return 0;
if(strlen(chann) > 5) return 0;
chnum = chat_name(chann);
if(chnum != -1) return 0;
chnum = clearedchat();
if(chnum == -1) return 0;
if(!clearmem(chnum)) return 0;
name[chnum] = chann;
node += ({chnum});
addmem(chann,tpn);
return 1; }

clearedchat() {
int jl,li;
jl = 0;
li = 0;
while(jl < sizeof(name) && !li) {
  if(!name[jl]) li = 1;
  jl++;
}
if(!li) return -1;
return (jl - 1); }

clearmem(int num) {
if(num < 0 || num > MAX - 1) return 0;
mem1[num] = 0;
mem2[num] = 0;
mem3[num] = 0;
mem4[num] = 0;
mem5[num] = 0;
return 1; }

addmem(string chan,string nam) {
int chnum,where;
if(!chan || !nam) return 0;
chnum = chat_name(chan);
if(chnum == -1) return 0;
if(!find_player(nam)) return 0;
if(mem_chat(chnum,nam)) return 0;
where = checkfull(chnum);
if(where == -1) return 0;
if(where == 0) mem1[chnum] = nam;
if(where == 1) mem2[chnum] = nam;
if(where == 2) mem3[chnum] = nam;
if(where == 3) mem4[chnum] = nam;
if(where == 4) mem5[chnum] = nam;
anonchat(chnum,TITLE+capitalize(nam)+
                   " has joined the channel.\n");
return 1; }

removemem(string chan,string nam) {
int chnum;
if(!chan || !nam) return 0;
chnum = chat_name(chan);
if(chnum == -1) return 0;
if(!mem_chat(chnum,nam)) return 0;
if(mem_chat(chnum,nam) == 1) mem1[chnum] = 0;
if(mem_chat(chnum,nam) == 2) mem2[chnum] = 0;
if(mem_chat(chnum,nam) == 3) mem3[chnum] = 0;
if(mem_chat(chnum,nam) == 4) mem4[chnum] = 0;
if(mem_chat(chnum,nam) == 5) mem5[chnum] = 0;
anonchat(chnum,TITLE+capitalize(nam)+
                   " has left the channel.\n");
return 1; }

anonchat(int nj,string what) {
int h;
string dude;
h = 0;
dude = 0;
while(h < 5) {
  if(h == 0) dude = mem1[nj];
  if(h == 1) dude = mem2[nj];
  if(h == 2) dude = mem3[nj];
  if(h == 3) dude = mem4[nj];
  if(h == 4) dude = mem5[nj];
if(dude) if(find_player(dude)) if(present("chatter",find_player(dude)))
  tell_object(find_player(dude),what+"\n");
h++;
dude = 0;
}
hearts();
return 1; }

heart_beat() {
int q;
int jj;
string cho;
for(q=0;q<sizeof(node);q++) {
  jj = 0;
  cho = 0;
  jj = node[q];
  if(jj != -1) {
    if(!checkempty(jj)) {
      cho = name[jj];
      if(mem1[jj]) if(!find_player(mem1[jj])) removemem(cho,mem1[jj]); 
                   else if(!present("chatter box",find_player(mem1[jj])))
                        removemem(cho,mem1[jj]); 
      if(mem2[jj]) if(!find_player(mem2[jj])) removemem(cho,mem2[jj]);
                   else if(!present("chatter box",find_player(mem2[jj]))) 
                        removemem(cho,mem2[jj]); 
      if(mem3[jj]) if(!find_player(mem3[jj])) removemem(cho,mem3[jj]); 
                   else if(!present("chatter box",find_player(mem3[jj]))) 
                        removemem(cho,mem3[jj]); 
      if(mem4[jj]) if(!find_player(mem4[jj])) removemem(cho,mem4[jj]);
                   else if(!present("chatter box",find_player(mem4[jj]))) 
                        removemem(cho,mem4[jj]); 
      if(mem5[jj]) if(!find_player(mem5[jj])) removemem(cho,mem5[jj]);
                   else if(!present("chatter box",find_player(mem5[jj]))) 
                        removemem(cho,mem5[jj]); 
    } else {
      name[jj] = 0;
      clearmem(jj);
      node -= ({jj});
    }
  }
}
}

hearts() { set_heart_beat(0); set_heart_beat(1); }

query_chats() {
int poo;
int how;
  if(this_player()->query_level() < 100) return 0;
how = 0;
  for(poo=0;poo<MAX - 1;poo++) {
    if(name[poo]) {
   how = how + 1;
   write(how+" ");
      write("Channel: "+name[poo]+" Mem: ");
      if(mem1[poo]) write(mem1[poo]+"  ");
      if(mem2[poo]) write(mem2[poo]+"  ");
      if(mem3[poo]) write(mem3[poo]+"  ");
      if(mem4[poo]) write(mem4[poo]+"  ");
      if(mem5[poo]) write(mem5[poo]);
      write("\n");
    }
    }
  write("\nChatter Channels Done\n");
return 1; }
