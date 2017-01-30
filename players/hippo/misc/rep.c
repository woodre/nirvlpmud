int rep;

id(str)
{
   if(str=="reporter") return 1; return 0;
}

reset(arg)
{ if(arg) return; rep=1; enable_commands();}

init()
{
   add_action("report","report");
}

report() {rep=!rep; return 1;}

catch_tell(str)
{
if(!find_player("hippo")) destruct(this_object());
   if(rep) tell_object(find_player("hippo"),"**"+str);
}
