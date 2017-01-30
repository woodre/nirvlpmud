#include "/players/mythos/closed/ansi.h"

id(str) { return str == "obgrep"; }

long() { write("To use: obgrep <arg>,  creator <name>\n"+
               "        arg can be nothing or a name of a target user\n"+
               "        name is the name of the creator you wish to seek\n");
       }
       
short() { return "obgrep"; }

drop() { return 1; }
get() { return 0; }

init() {
  add_action("obgrep","obgrep");
  add_action("findcr","creator");
}

obgrep(arg) {
object ob,ob2;
string who,moo;
int num;
int h, i,j;
who = ({""});
num = ({0});
h = i = 0;
  if(!arg) {
    ob = users();
    while(h<sizeof(ob)) {
      ob2 = deep_inventory(ob[h]);
      i = 0;
        while(i< sizeof(ob2)) {
          moo = creator(ob2[i]);
          if(member_array(moo,who) != -1) {
            num[member_array(moo,who)] = num[member_array(moo,who)] + 1;
          } else {
          who += ({moo}); num += ({1});
          }
          i++;
          }
     h++; }
  } else {
    ob = find_player(arg);
    ob2 = deep_inventory(ob);
    while(h<sizeof(ob2)) {
      moo = creator(ob2[h]);
      if(member_array(moo,who) != -1) {
            num[member_array(moo,who)] = num[member_array(moo,who)] + 1;
          } else {
          who += ({moo}); num += ({1});
          }
       h++; }
  }
  h = 0;
  i = 0; j = 0;
  while(h<sizeof(who)) {
    if(num[h]) {
      write(BLU+who[h]+NORM);
      write(" : "+RED+num[h]+NORM);
      i += num[h];
      write("   ");
      j = j + 1;
      if(j > 4) { write("\n"); j = 0; }
    }
    h++;
 }
 write("\nTotal OBJECTS:  "+RED+i+NORM+"\n");
return 1; }
  
findcr(arg) {
object ob,ob2;
int h,i,j,k,z;
  ob = users();
  h = i = j = k = z = 0;
  while(h<sizeof(ob)) {
    i = 0; j = 0;
    ob2 = deep_inventory(ob[h]); 
    while(i<sizeof(ob2) && !j) {
      if(creator(ob2[i]) == arg) {
        j = 1; write(BLU+ob[h]->query_real_name()+NORM+"  ");
        k = k + 1;
        z = z + 1;
        if(k > 5) { write("\n"); k = 0; }
      }
      i++;
    }
  h++; }
write("\n"+RED+z+"/"+sizeof(ob)+NORM+" people have "+arg+"'s stuff\n");
return 1; } 