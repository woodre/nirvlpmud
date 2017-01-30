int timer;
int lineno;
string filename;
reset(arg)
{
   if(arg) return; timer=1; }
init()
{
   add_action("set_file","set_file");
   add_action("set_timer","set_timer");
}
set_file(str)
{
   filename=str;
   lineno=1;
   add_action("blip","blip");
   add_action("blip",filename);
   return 1;
}
set_timer(str)
{
   sscanf(str,"%d",timer);
   return 1;
}
blip()
{
   string line;
   line = read_file(filename,lineno,1);
   if(0 == line) destruct(this_object());
   else
      {
      "/players/sado/toys/patchsupp.c"->pt(line[0..-2]);
      lineno++;
      call_out("blip2",timer);
   }
   return 1;
}
blip2()
{
   command(filename,environment(this_object()));
}
get(){return 1;}
id(str){return "patcher"==str;}
