#include "/players/zeus/closed/all.h"
string *all;
int a, sa;
reset(arg){
  all = ({ "vigor", });
}

get(){ return 1; }
short(){ return "pill"; }
id(str){ return str == "pill"; }

void init(){
  sa = sizeof(all);
  for(a = 0; a < sa; a++)
    add_action("cmd_hook", all[a]);
}

int cmd_hook(string str)
{
  string b,c,d;
  b = "/players/zeus/stuff/test/"+query_verb()+".c";
  write(b);
  if(file_size(b) > 0)
    return (status) b->main(str, this_object(), this_player());
}
