#include "/players/mokri/define.h"

string modify_path(string str) {
   int x, a;
   string my_dir, new_str;
   string *tmp_me, *tmp_str;
   
   if(str && extract(str,0,0) == "/") return str;
   my_dir = (string)this_player()->get_path();
   tmp_str = explode(str,"/");
   tmp_me = explode(my_dir,"/");
   my_dir = ""; new_str = "";
   
   for(x = 0; x < sizeof(tmp_str); x++) {
      if(tmp_str[x] == "..") a += 1;
      if(tmp_str[x] != "..") new_str += "/"+tmp_str[x]; }
   
   str = extract(new_str,1);
   for(x = 0; x < (sizeof(tmp_me)-a); x++) my_dir += "/"+tmp_me[x];
   my_dir = extract(my_dir,1);
   if(str == "~me") str = "/players/"+TPRN;
   if(strlen(str) > 3 && extract(str,0,3) == "~me/") str = "/players/"+TPRN+"/"+extract(str,4);
   
   if(str[0] == '~') str = "/players/"+extract(str,1);
   if(str == "here" && file_size("/"+my_dir+"/here") < 1)
      str = "/"+file_name(environment(this_player()))+".c";
   if(str[0]!='/') str = "/"+my_dir+"/"+str;
   return str; 
}
