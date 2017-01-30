#pragma strict_types

#include <ansi.h>

inherit "/obj/armor";


int big_teeth, small_teeth;

void
reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("gator tooth necklace");
  set_alias("tooth necklace");
  SetMultipleIds(({"gator necklace"}));
  set_type("necklace");
  set_ac(1);
}

string
short()
{
  short_desc="gator "+HIW+"tooth"+NORM+" necklace";
  short_desc += " (has "+(big_teeth+small_teeth)+" teeth)";
  return (string)::short();
}

void
long()
{
  long_desc="\
A hemp necklace, lined with various gator teeth.  There\n\
are " + big_teeth + " large teeth, and " + small_teeth + " small gator \
teeth\n\
within its lining.\n\
You could string more teeth on it if you wish.\n";
  ::long();
}

int
query_weight()
{
    return 1;
}

int
query_value()
{
    return((400 * small_teeth) + (2500 * big_teeth) + 100);
}

status
generic_object()
{ 
    return 1;
}

string
locker_arg()
{
    return "X" + big_teeth +"CHINGY" + small_teeth + "X";
}

void
locker_init(string arg) 
{
    string bunny, foofoo;

      if(sscanf(arg, "X%sCHINGY%sX",bunny,foofoo) < 2)
        sscanf(arg, "%sCHINGY%s",bunny,foofoo);
    if(!bunny) bunny = "0";
    if(!foofoo) foofoo = "0";
    sscanf(bunny,"%d",big_teeth);
    sscanf(foofoo,"%d",small_teeth);
}

status
restore_thing(string str)
{
    restore_object(str);
    return 1;
}

status
save_thing(string str)
{
    save_object(str);
    return 1;
}

void
add_tooth(int type)
{
    if(type == 1)
      small_teeth ++;
    else
      big_teeth ++;
}

void
set_teeth(int small, int big)
{
    big_teeth = big;
    small_teeth = small;
}
