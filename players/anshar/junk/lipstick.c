/*
 *  Lipstick, based on Saber's paintball gun
 *
 */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "obj/weapon";

object kmark;
int i, charges;

reset(arg)
{
  charges = 10;
  if(arg) return;
  set_name("tube of lipstick");
  set_alias("lipstick");
  set_short("A tube of lipstick");
  set_long("A tube of bright red lipstick.\n\
Type <apply> to put on some lipstick.\n\
Type <left> to see how many applications are left.\n\
Type <bigkiss> <player> <where> to leave an incriminating mark on someone.\n");
  set_class(3);
  set_weight(1);
  set_value(0);
}

init()
{
  ::init();
  add_action("bigkiss","bigkiss");
  add_action("left","left");
  add_action("apply","apply");
}

left()
{
  write("It looks like there are "+charges+" applications left.\n");
  return 1;
}

apply()
{
  if(!(charges > 0))
  {
    write("You are out of lipstick?\n");
    return 1;
  }
  i = 1;
  write("You apply some of the garish lipstick.\n");
  say(this_player()->query_name()+" puts on some bright "+RED+"RED "
      +NORM+"lipstick.\n");
  charges -=1;
  return 1;
}

bigkiss(str)
{
  object kissed;
  object plyr;
  string who, where;
  if(!str) { write("Kiss <who <where>?\n"); return 1; }
  if(sscanf(str,"%s %s",who,where) != 2)
  {
    write("Kiss <who> <where>?\n");
    return 1;
  }
  plyr = present(who, environment(this_player()));
  if(!plyr)
  {
    write(capitalize(who)+" is not in the same room as you.\n");
    return 1;
  }
  if(i !=(1))
  {
    say(this_player()->query_name()+" kisses "+capitalize(who)+
        " but leaves no mark.\n");
    write("You kiss "+capitalize(who)+", but you need apply more lipstick.\n");
    return 1;
  }
  kissed = find_living(who);
  write("You kiss "+capitalize(who)+" leaving a bright "+RED+"RED "+
        NORM+"mark!\n");
  say(this_player()->query_name()+" kisses "+capitalize(who)+
      " leaving a bright "+RED+"RED "+NORM+"mark!\n",kissed);
  tell_object(kissed, this_player()->query_name()+
              " kisses you leaving a bright "+RED+"RED "+NORM+"mark!\n");
  i = 0;
  kmark = clone_object("/players/anshar/junk/kmark.c");
  kmark->set_where(where);
  transfer(kmark, kissed);
  return 1;
}
