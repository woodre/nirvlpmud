#include <ansi.h>
id(str) { return str == "ips"; }

drop() { return 1;}
get() { return 0;}

init() { 
         add_action("ips","ips"); 
         add_action("rooms","rooms");
         add_action("combats","combats");
         add_action("weps","weps");
         add_action("arms","arms");}

ips() {
object p;
int h, n, flag;
string check, chome;
p = users();
for(h=0;h<sizeof(p);h++) {
flag = 0;
  check = query_ip_number(p[h]);
  chome = p[h]->query_hostname();
  for(n=0;n<sizeof(p);n++) {
    if((query_ip_number(p[n]) == check || p[n]->query_hostname() == chome) &&
    p[n] != p[h]) {
    if(!flag) { 
      write(BOLD+capitalize(p[h]->query_real_name())+NORM+NORM+
      "  ip  "+RED+check+" : "+chome+NORM+"  ");
      write(environment(p[h]));
      write("\n\t ");
      flag = 1; }
      write(p[n]->query_real_name()+" ");
    } }
    if(flag) { write("\n");}
  }
write("\nIps done.\n");
return 1;}

rooms() {
object p, check;
int h, n, flag;
p = users();
for(h=0;h<sizeof(p);h++) {
flag = 0;
  check = environment(p[h]);
  for(n=0;n<sizeof(p);n++) {
    if(environment(p[n]) == check && p[n] != p[h]) {
    if(!flag) { 
      write(BOLD+capitalize(p[h]->query_real_name())+NORM+NORM+
      "  room "+RED);
      write(check);
      write(NORM+"\n\t ");
      flag = 1; }
      write(p[n]->query_real_name()+" ");
    } }
    if(flag) { write("\n");}
  }
write("\nrooms done.\n");
return 1;}

combats() {
object p;
int h;
p = users();
for(h=0;h<sizeof(p);h++) {
  if(p[h]->query_level()) {
  if(p[h]->query_attack()) { 
  write(HIC+p[h]->query_real_name()+NORM+"  "+
  (p[h]->query_attack())->query_name()+"  ");
  write(environment(p[h]));
  write("\n");
  }
  }
  }
write("\ncombat done.\n");
return 1;}

weps(str) {
object j, k;
int i,m,da;
int moo;
string cao;
string mooed;
int where;
mooed = ({""});
moo = ({0});
if(!str) da = 0;
else da = 1;
j = users();
  for(i = 0; i < sizeof(j); i++) {
    k = deep_inventory(j[i]);
    for(m = 0; m <sizeof(k); m++) {
      if(k[m]->weapon_class()) {
        write(HIG+j[i]->query_real_name()+"  "+NORM);
        if(!da) write(k[m]->short());
        else  write(k[m]); 
        write(" wc "+RED+
          k[m]->weapon_class()+NORM+GRN+"  "+creator(k[m])+"\n"+NORM);
           cao = creator(k[m]);
          if(member_array(cao,mooed) != -1) { 
            where = member_array(cao,mooed);
            moo[where] = 
               moo[where] + 1;
          } else {
            mooed += ({creator(k[m])});
            moo += ({1});
          }
        }
      }
    }
    m = 0;
    i = 0;
   j = 0;
    while(m < sizeof(moo)) {
     if(moo[m]) {
      i = i + 1;
      write(BLU+mooed[m]+NORM);
      write(" "); 
      write(RED+moo[m]+"  "+NORM);
      j += moo[m];
      if(i >5) { write("\n"); i = 0; }}
      m = m + 1; }
 write("\nweapon check done- total:"+RED+(j)+NORM+"\n");
return 1;}

arms(str) {
object j, k;
int i,m,da;
if(!str) da = 0;
else da = 1;
j = users();
  for(i = 0; i < sizeof(j); i++) {
    k = all_inventory(j[i]);
    for(m = 0; m <sizeof(k); m++) {
      if(k[m]->armor_class()) {
        write(HIG+j[i]->query_real_name()+"  "+NORM);
        if(!da) write(k[m]->short());
        else write(k[m]);
        write(" ac "+RED+
          k[m]->armor_class()+NORM+GRN+" "+creator(k[m])+"\n"+NORM);
        }
      }
    }
 write("\narmor check done\n");
return 1;}
