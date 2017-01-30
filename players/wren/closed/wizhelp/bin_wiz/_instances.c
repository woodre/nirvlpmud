/* _instances version 2.2 */

#include <security.h>
#include <user/resolve_path.h>

/* Coded by Vertebraker (c) 2002 */
/* Thanks Cobain!  You little Vietnamese genius. */

#define MAX_OBJ_EVAL 8000

status invis_chk(object ob, object me) {
  if(!ob || !ob->is_player() || !ob->query_invis())
    return 0;
  return ((int)ob->query_level() > (int)me->query_level());
    return 1;
}

varargs void
do_loop(mixed *data)
{
    string   my_arg, inst_data;
    int      current_max, current_init, total_cloned_objs, inc, cnt;
    object   ob, me;

    my_arg            = data[0];
    current_init      = data[1];
    total_cloned_objs = data[2];
    current_max       = data[3];
    me                = data[4];
    inst_data         = data[5];
    cnt               = data[6];

    if(!current_max)
    {
      if(total_cloned_objs < MAX_OBJ_EVAL)
        current_max = total_cloned_objs;
      else
        current_max = MAX_OBJ_EVAL;
    }

    for(inc = current_init; inc < current_max; inc ++)
      if((ob=find_object(my_arg+"#"+inc)))
      {
        if(!invis_chk(ob,me) && (!environment(ob) || !invis_chk(environment(ob),me)))
        {
          inst_data += "\t@" + inc +":\t" + ((ob=environment(ob)) ? 
           (ob->is_player() ?
           capitalize((string)ob->query_real_name()) : 
           file_name(ob)) : 
           "None") + "\n";
          cnt ++;
        }
      }

    if(current_max == total_cloned_objs)
      return tell_object(me, inst_data + "\n\t\t" + (cnt ? 
                       ("" + cnt + " instances found.\n\n") :
                       "No instances found.\n"));

    current_init = current_max;

    if(current_max < total_cloned_objs)
    {
      if((total_cloned_objs - current_max) <= MAX_OBJ_EVAL)
        current_max = total_cloned_objs;
      else
        current_max += MAX_OBJ_EVAL;
    }

    tell_object(me, "Building instance data... (Please wait)\n->>");

    call_out("do_loop", 0, 
     ({ my_arg, current_init, total_cloned_objs, 
        current_max, me, inst_data, cnt }));
}

int
cmd_instances(string arg)
{
    int last, i;
    string junk_val;
    object ob;
   
    if((int)this_player()->query_level() < APPRENTICE)
      return 0;

    if(!stringp(arg))
      return (notify_fail("Usage: \"instances <arg>\"\n"), 0);

    arg = resolve_path(arg, ".c");
    if(!exists(arg))
      return (notify_fail("The file you have specified does not exist.\n"), 0);

    sscanf(arg, "%s.c", arg);
   
    sscanf(file_name(ob = clone_object(file_name(this_object()))),
      "%s#%d", junk_val, last);
    destruct(ob);
   
    do_loop(({arg,0,last,0,this_player(),"\n\t\tInstances of " + 
                    capitalize(arg) + ":\n\n",0}));
   return 1;
}
