#pragma strict_types;
#include "/players/feldegast/closed/guild/defines.h"

object *members=({ });
int num_members;

reset(arg) {
  if(arg) return;
  members=allocate(num_members);
}

query_num_members() {
  return num_members;
}
query_members() {
  return members;
}
add_member(object ob) {
  object *temp;
  int i;
  temp=members;
  for(i=0;i<num_members-1;i++) {
    if(ob==members[i])
      return;
  }
  members=allocate(++num_members);
  for(i=0;i<num_members-1;i++) {
    members[i]=temp[i];
  }
  members[i]=ob;
}
remove_member(ob) {
  members-=({ob});
  num_members--;
}
broadcast(str) {
  int i, max;
  max=sizeof(members)-1;
  for(i=0;i<=max;i++) {
    tell_object(members[i],
HIB+"("+HIR+"*"+HIB+")"+NORM+" "+str+"\n"
    );
  }
}
