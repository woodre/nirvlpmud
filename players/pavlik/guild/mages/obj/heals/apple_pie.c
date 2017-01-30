/* 60 tox/150 heal = .4  cost = 8 per heal, 8*150 = 1200 .. except this
   is not a straight 1hp:1sp heal. Per heal1, 1 hp or sp counts as 2/3 instead */

inherit "/obj/generic_heal";

#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name(YEL+"Apple Pie"+NORM);
  add_alias("apple pie");
  add_alias("pie");
  add_alias("apple");
  set_short("An "+YEL+"Apple Pie"+NORM);
  set_long("An "+YEL+"Apple Pie"+NORM+" - One of Helen's finest!\n"+
           "You can \"eat\" it or also \"splat\" another player.\n");
  set_type("bites");
  set_type_single("bite");
  set_msg("You quickly gobble down a piece of Helen's "+YEL+"Apple Pie"+NORM+".\n"+
          "Boy, Helen really outdid herself this time!\n");
  set_msg2(" eats a piece of "+YEL+"Apple Pie"+NORM+".\n");
  set_empty_msg("You have finished the entire pie (you pig).\n");
  add_cmd("bite");
  add_cmd("eat");
  set_heal(25,75);
  set_charges(3);
  set_stuff(10);
  set_soak(10);
  set_value(250);
}

void init()
{
  ::init();
  add_action("cmd_splat","splat");
}

int cmd_splat(string str)
{
  object obj;
o
  if(!str)
  {
    write("Splat who?\n");
    return 1;
  }

  obj = find_player(str, 1);

  if(!obj || obj->query_invis())
  {
    write(capitalize(str)+" isn't around.\n");
    return 1;
  }

  if((int)obj->query_level() > 19)
  {
    write("You can't splat a wizard!\n");
    return 1;
  }

  write(
    "You splat "+(string)obj->query_name()
    +" in the face with a pie!\n"+
    "Little "+YEL+"chunks of fruit"+NORM+" slide down "+
    (string)obj->query_name()+"'s face.\n");
  tell_object(obj, (string)this_player()->query_name()+
    " splats you in the face with an apple pie!\n"+
    YEL+"Chunks of fruit"+NORM+" slide down your face.\n");
  tell_room(environment(obj), (string)this_player()->query_name()+
    " splats "+(string)obj->query_name()
    +" in the face with a "+YEL+"pie"+NORM+"!\n", ({obj}));
  
  destruct(this_object());
  return 1;
}