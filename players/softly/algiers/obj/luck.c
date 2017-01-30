int old_luck;

status
id(string str)
{
    return str == "50ft_root";
}

void
set_old_luck(int l)
{
    old_luck = l;
}

void
init()
{
    if(environment() && (find_call_out("game_over") == -1))
      call_out("game_over", 600);
}

void
game_over()
{
    if(!environment())
    {
      destruct(this_object());
      return;
    }
    tell_object(environment(), "You feel less lucky.\n");
    environment()->set_attrib("luc", old_luck);
    old_luck = 0;
    destruct(this_object());
}

void
remove_object()
{
    if(environment())
    {
      tell_object(environment(), "You feel less lucky.\n");
      environment()->set_attrib("luc", old_luck);
    }
}

status
drop()
{
    return 1;
}
