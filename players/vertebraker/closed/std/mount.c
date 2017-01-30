/* mountable inherit (c) Vert@Nirvana [2001]
     [closed/std/mount] 
   damn it feels good to be a gangsta */

#define N (string)this_player()->query_name()
#define remote(S) tell_room(environment(), S, ({ this_player() }))


inherit "/players/vertebraker/closed/std/monster";

void reset_mount();

object MountedBy;

int silent_dismount, silent_mount;

void
init()
{
    object Ob;

    ::init();

    if((Ob = this_player()) && Ob)
      if((Ob == MountedBy) && 
       ((mixed)Ob->query_mounted() != this_object()))
        reset_mount();

    add_action("cmd_mount", "mount");
    add_action("cmd_dismount", "dismount");
}

status
query_save_flag()
{
    return 1;
}    

status
cmd_mount(string str)
{

    if(!str || !id(str)) return 0;

    if(this_player()->query_mounted() 
        || MountedBy) return 0;

    if(function_exists("mountable", this_object()))
      if(!this_object()->mountable(this_player())) 
        return 0;

    if(this_player()->query_attack()) {
      write("You too occupied with fighting to mount anything.\n");
      return 1;
    }
    if(!silent_mount)
    { 
      write("You mount " + short() + ".\n");
      remote(N + " mounts " + short() + ".\n");
    }

    this_player()->set_mounted(this_object());
    MountedBy = this_player();
    return 1;
}

status
cmd_dismount(string str)
{

    if(((mixed)this_player()->query_mounted() != this_object())
       || MountedBy != this_player()) return 0;

    if(!silent_dismount)
    {
      write("You dismount " + short_desc + ".\n");
      remote(N + " dismounts " + short_desc + ".\n");
    }

    reset_mount();
    return 1;
}

void
reset_mount()
{
    if(MountedBy)
    {
      MountedBy->clear_mounted();
      MountedBy = 0;
    }
}

string
on_what()
{
    return short_desc;
}

mixed
short()
{
    if(MountedBy) return 0;
    else return ::short();
}

void
set_silent_dismount()
{
    silent_dismount = 1;
}

void
set_silent_mount()
{
    silent_mount = 1;
}

void
heart_beat()
{
    ::heart_beat();
    if(!environment()) return;
    if(MountedBy && !present(MountedBy, environment()))
      if(environment(MountedBy)) move_object(this_object(), environment(MountedBy));
}

void
catch_tell(string s)
{
    object m, e;
    string x, y;
    if(!MountedBy) return;
    if((sscanf(s, "%s leaves on " + on_what() + " %s.\n", x, y) == 2) && ((string)MountedBy->query_name() == x))
      command(y, this_object());
}

move_player(x)
{
    object a;
    string y, z;

    if(!MountedBy) return ::move_player(x);
    sscanf(x, "%s#%s", y, z);
    if(!(a = find_object(z))) z->load_it();
    a = find_object(z);
    move_object(this_object(), a);
}
