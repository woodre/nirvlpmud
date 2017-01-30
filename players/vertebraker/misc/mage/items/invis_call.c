int cnt, loaded;

void
init()
{
    if(environment() && !loaded)
    {
      call_out("uninvis", 600);
      loaded = 1;
    }
}

void
uninvis()
{
    object e;

    if(!(e = environment()))
    {
      destruct(this_object());
      return;
    }

    tell_object(e, "You suddenly fade back into reality...\n");
    command("visible", e);
    destruct(this_object());
}

status
id(string str)
{
    return str == "verte_invis_thing";
}

status
drop()
{
    return 1;
}

void
reset(status arg)
{
    if(arg) return;
    set_heart_beat(1);
}

void
heart_beat()
{
    if(!environment())
    {
      set_heart_beat(0);
      destruct(this_object());
      return;
    }

    environment()->set_invs_sp();
}
