inherit "/obj/treasure";

object player;

set_player(p)
{
  player = p;
  set_id(p->query_real_name());
  set_short(p->query_name()+", floating high up in the air");
  set_long(p->query_name()+".\n");
  set_heart_beat(1);
}

heart_beat()
{
  if(!player || !present(player, this_object()))
  {
    return destruct(this_object());
  }
}

long()
{
  if(environment(this_player()) != this_object())
    return player->long();
  else
    write("You are floating high above "+environment()->short()+".\n"+
           "Type [ground] to lower yourself to the ground.\n");

}

short()
{
  if(environment(this_player())==this_object())
    return "High above "+environment()->short();
  else
    return ::short();
}

init()
{
  ::init();
  if(environment(this_player()) == this_object())
    add_action("cmd_ground","ground");
}

cmd_ground()
{
 int s;
  object *inv;
  s = sizeof(inv = all_inventory(this_object()));
  while(s--)
  move_object(inv[s], environment());
  write("\nYou land safely back on the ground.\n");
  say(this_player()->query_name()+" lands safely back on the ground.\n");
  destruct(this_object());
  return 1;
}

reset(arg)
{
  if(arg) return;
}

get()
{
  return 0;
}

realm()
{
  return "NT";
}

is_soar()
{
  return 1;
}
