#include "../x.h"

inherit N_EFUN;

int cmd_burrow(string str)
{
 string *cmds;
 int    v, s;
 object me;

 if(!str)
 {
  write("Usage: 'burrow <dir1,dir2,etc.>\n");
  return 1;
 }
 me = TP;
 if(!ENV(me)->query_nimh_hole())
 {
  tell_object(me,"\
You must be in an earthen tunnel dug by a NIMH Rat\n\
to be able to burrow.\n");
  return 1;
 }
 else
 {
  object robot;
  if(!ENV(me)->query_location() ||
     catch((ENV(me)->query_location())->load_me()))
  {
   tell_object(me,"Bad location for this hole.\n"+
         "Cannot burrow further.\n");
   return 1;
  }
  tell_object(me,"Cloning robot...\n");
  robot = CO(N_OBJ+"burrow_robot");
  robot->set_level((int)me->QL);
  robot->set_extra_level((int)me->QXL);
  tell_object(me,"Moving robot to "+(string)ENV(me)->query_location()+"\n");
  MO(robot, (string)ENV(me)->query_location());
  MO(CO(N_OBJ+"burrow_robot_obj"), robot);
  robot->init();
  robot->yeah();
  tell_object(me, "Robot moved to "+file_name(ENV(robot))+"\n");
  cmds = explode(str,",");
  tell_object(me,"\n");
  if(s = sizeof(cmds))
   for(v=0;v<s;v++)
   {
    if(v >= 5)
    {
     if(robot) destruct(robot);
     return (tell_object(me,"\
You cannot burrow more than five directions at a time.\n"), 1);
    }
    if(ENV(me)->query_exit(cmds[v]))
    {
     tell_object(me,HIG+"Already found exit: "+cmds[v]+"\n"+NORM);
     command(cmds[v],me);
    }
    else
    {
     object old_env, new_env, hole;
     if(robot)
     {
      old_env = ENV(robot);
      if(!command(elongate_exit(cmds[v])), robot)
      {
        tell_object(me,"Command: \""+elongate_exit(cmds[v])+"\" failed.\n");
        tell_object(me,"Trying "+shorten_exit(cmds[v])+".\n");
        if(!command(shorten_exit(cmds[v]), robot))
         tell_object(me, "Command: \""+shorten_exit(cmds[v])+"\" failed.\n");
      }
      new_env = ENV(robot);
      if(old_env != new_env)
      {
       tell_object(me,"Old robot position: "+(string)old_env->short()+"\n");
       tell_object(me,"New robot position: "+(string)new_env->short()+"\n");
       tell_object(me,YEL+"   Burrowing "+elongate_exit(cmds[v])+"...\n"+NORM);
       say((string)me->QN+" burrows furiously "+elongate_exit(cmds[v])+"!\n");
       tell_object(me,"querying reverse_exit\n");
       cmds[v]=shorten_exit(cmds[v]);
       tell_object(me,"shortened exit: "+cmds[v]+"\n");
       tell_object(me,"reversed exit: "+reverse_exit(cmds[v])+"\n");
       if(reverse_exit(cmds[v]))
       {
        object nwr_env;
        tell_object(me,"found reverse exit.\ncommanding robot...\n");
        command(reverse_exit(cmds[v]), robot);
        nwr_env = ENV(robot);
        if(nwr_env == old_env)
        {
         tell_object(me,"adding reverse exit: "+reverse_exit(cmds[v])+"\n");
         ENV(me)->add_exit(reverse_exit(cmds[v]), FN(new_env));
        }
        tell_object(me,"moving robot back to new_env\n");
        MO(robot, new_env);
       }
       hole = CO(N_OBJ+"hole");
       hole->add_exit(str, FN(new_env));
       hole->set_creator((string)me->RN);
       hole->set_location(file_name(new_env));
       MO(hole, new_env);
       MO(me, hole);
       command("look", me);
      }
      else
       tell_object(me,"Cannot burrow "+elongate_exit(cmds[v])+"\n");
     }
     else
      tell_object(me,"Error! Contact X immediately!\n");
    }
   }
  destruct(robot);
  tell_object(me,"\n");
  tell_object(me,"Burrow done.\n");
  write("");
  return 1;
 }
}
