inherit "/obj/treasure.c";
#include <ansi.h>


int pin;

reset()
{
  set_id("grenade");
  short_desc = "A Night Elf Mohawk Grenade";
  long_desc = "A small green grenade with a larger patch of hair on it.\n"+
              "It almost looks like this grenade has a mohawk.  Odd.\n";
  set_weight(1);
}

init()
{
  ::init();
  add_action("Cmd_throw","throw");
 }

Cmd_throw(string str)
{
  object target;
  string who;

  if(!str){ notify_fail("Please use: throw grenade at <player>\n"); return 0; }
  if(!sscanf(str, "grenade at %s", who))
  {
    notify_fail("Please use: throw grenade at <player>\n");
    return 0;
  }

  target = find_player(who);
  if(!target)
  {
    write("Cannot locate that player.\n");
    return 1;
  }
  if(environment()->query_level() < 20 && !present(target, environment(environment(this_object()))))
  {
    write(capitalize(who)+" is not in this room.\n");
    return 1;
  }

  tell_object(environment(),
    "You yell, \"I pity da foo!\", and throw a Night Elf Mohawk Grenade at "+capitalize(who)+".\n"); 
  
  tell_object(environment(),
    "The grenade explodes in a massive cloud of gas and debris.  As the smoke clears you start to notice that\n"+
    ""+capitalize(who)+"'s hair is sticking up in a brilliant mohawk.\n");

  tell_object(target,
    environment()->query_name()+" yells, \"I pity da foo!\", and throws a Night Elf Mohawk Grenade at you.\n");  

  tell_object(target,
    "The grenade explodes in massive cloud of gas and debris.  As the smoke clears you start to notice that\n"+
    "your hair is sticking up in a brilliant mohawk.\n");

  tell_room(target,
    environment()->query_name()+" yells, \"I pity da foo!\", and throws a Night Elf Mohawk Grenade at "+capitalize(who)+".\n", ({ environment(), target }));
 
  tell_room(target,
    "The grenade explodes in a massive cloud of gas and debris as it strikes "+capitalize(who)+".  As the smoke clears you\n"+
    "start to notice that "+capitalize(who)+"'s hair is sticking up in a brilliant mohawk.\n", ({ environment(), target }));

  if(!present("night_elf_affects", target))
    move_object(clone_object("/players/fred/toys/night_elf_affects.c"), target);

  target->set_race("Night Elf Mohawk");

  destruct(this_object());
  return 1;
}  

query_save_flag(){ return 1; }
query_value(){ return 10; }
              
    
