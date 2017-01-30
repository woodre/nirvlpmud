mixed 
file_check(string str)
{
   if(str[0] == '~') str = "/players/" + 
     this_player()->query_real_name()+
     str[1..strlen(str) - 1];
   if(str[0] != '/') str = this_player()->get_path() + 
     str[0..strlen(str) - 1];
   if(str[strlen(str) - 2] != '.')
     str += ".c";
  if(file_size(str) < 1) return 0;
   else return str;
}
