/*** Light object ***/


inherit "obj/armor";

int level;

create()
{
  add_property("magic");
}

set_level(l)
{
  level = l;
  if(level < 0) {
    set_id("darkness");
    set_long(0);
  }
  else if (level > 0) {
    set_id("light");
    set_long("You have to look away from it, it's too bright!\n");
  }
  set_short(0);
}

set_duration(d)
{
  int i, j;
  write("Dispel in: "+d+" seconds.\n");
  call_out("dispel",d);
  i = set_light(0);
  j = set_light(level);
  write(environment(this_player())->short()+"\n");
  if (i <= 0 && j > 0)
    tell_room(environment(this_player()), "A glowing ball lights up the room.\n");
  else if (i > 1 && j <= 0)
    tell_room(environment(this_player()), "A cloak of darkness falls upon you.\n");
  return level;
}

dispel()
{
  int i, j;
  i = set_light(0);
  j = set_light(-level);
  if (i <= 0 && j > 0)
    tell_room(environment(this_player()), "The darkness dissolves.  You can see again.\n");
  else if (i > 1 && j <= 0)
    tell_room(environment(this_player()), "The light from the globe fades away, leaving you in the darkness.\n");
  destruct(this_object());
}