#include "def.h"

mapping Cmds;

string *saved_cmds;

void 
reset(int arg)
{
    if(arg) return;
    saved_cmds = ({ "clap" });
    Cmds = ([ ]);
}

void 
login_object()
{
    int index;

    if(!environment()) return;

    restore_object(SAVE + ((string)environment()->query_real_name()));

    for(index = 0; index < sizeof(saved_cmds); index += 2)
      if(!Cmds[saved_cmds[index]])
        Cmds[saved_cmds[index]] = -1;

}

void 
dump_cmd_keys()
{
    int i;
    string *k;

    saved_cmds = ({ });
    k = keys(Cmds);
  
    for(i = 0; i < sizeof(k); i ++)
      saved_cmds += ({ k[i], Cmds[k[i]] });

} 


void 
backup_object()
{
    if(!environment()) return;

    dump_cmd_keys();
    save_object(BACKUP + ((string)environment()->query_real_name()));
}

void
destroy_object()
{
    if(!environment()) return;

    dump_cmd_keys();
    save_object(SAVE + ((string)environment()->query_real_name()));
}

void
init()
{
    int i; string *k;

    if(environment() && (string)environment()->query_real_name())
    {
      login_object();

      k = keys(Cmds);

      for(i = 0; i < sizeof(k); i ++)
        add_action("cmd_hook", k[i]);

      add_action("cmd_debug","debug");
    }
}

status 
cmd_hook()
{
    if((status)(CMDDIR + query_verb())->main())
      return 1;
    else
      return 0;
}

status
id(string str)
{
    return (str == "meta_object" || str == "guild_object");
}

status
remove_object()
{
    destroy_object();
}

status
drop()
{
    return 1;
}

status
get()
{
    return 1;
}
status
cmd_debug()
{
    int i, z;
    string r, *k;

    if((r = (string)this_player()->query_real_name()) 
        && (member_array(r, GWIZ) != -1))
    {
      write("Debug mode.\n[map] Cmds: ");
      k = keys(Cmds);
      for(i = 0; i < sizeof(k); i ++)
      {
        write(k[i]);
        if(stringp(Cmds[k[i]]))
          write("<string> " + Cmds[k[i]] + "\n");
        else if(intp(Cmds[k[i]]))
          write("<int>    " + Cmds[k[i]] + "\n");
        else if(pointerp(Cmds[k[i]]))
        {
          write("<array>  ");
          for(z = 0; z < sizeof(Cmds[k[i]]); z ++)
            write("   " + Cmds[k[i]][z] + "\n");
        }
        else if(objectp(Cmds[k[i]]))
        {
          write("<object> ");
          if(file_name(Cmds[k[i]]))
             write(file_name(Cmds[k[i]]));
        }
        else write("<unknown> " + Cmds[k[i]] + "\n");
      }
      return 1;
    }
    else return 0;
}
