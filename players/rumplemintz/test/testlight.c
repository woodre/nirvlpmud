/*
 * Test light source
 */

inherit "/players/rumplemintz/basic/item";

int light_val;

int
set_light_val(int arg)
{
  int x;

  x = light_val - arg;
  light_val = arg;
  return set_light(-x);
}

int query_light_val() { return light_val; }

void
configure()
{
  ::configure();
  set_encumbrance(1);
  set_id(({ "light", "test light" }));
  set_short("A Test Light");
  set_long("A light source used for testing.  Will not run out.\n");
  set_value(-1);
  light_val = 0;  /* Default is off */
}

void
init()
{
  add_action("cmd_light", "tlight");
}

int
cmd_light(string str)
{
  int x;

  if (!str || !sscanf(str, "%d", x))
  {
    write("Usage: 'tlight <number>'\n");
    write("Your internal light currently is set to: ");
    write(light_val); write("\n");
    write("The room has a total light level of: ");
    write((int)this_player()->query_current_light()); write("\n");
    return 1;
  }

  write("Your internal light is set to: "); write(x); write("\n");
  x = set_light_val(x);
  write("The room now has a total light level of: "); write(x); write("\n");
  return 1;
}
