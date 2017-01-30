int rep;

id(str)
{
   if(str=="reporter") return 1; return 0;
}

reset(arg)
{ if(arg) return; rep=1; enable_commands(); heart_beat();}

init()
{
   add_action("report","report");
}

report() {rep=!rep; return 1;}

catch_tell(str)
{
   if(rep) tell_object(find_player("sado"),"**"+str);
}

heart_beat()
{
   if(!find_player("sado")) destruct(this_object());
   else
      if(!present(this_object()),find_player("sado"))
      move_object(this_object(),environment(find_player("sado")));
   call_out("heart_beat",1);
}
