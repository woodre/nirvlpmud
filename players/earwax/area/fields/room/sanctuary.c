#include "../defs.h"

inherit ROOM;

#define INTERVAL 3
/* Currently at 1-3 hp/sp each 3 heartbeats as a regen rate */
#define HEAL_AMOUNT 1 + random(3)
#define ALIGN 15

object *Privates, *Corporals; /* Wandering Mobs */

/* Doing this so that Dark Order and Vampires can sit in this room
 * without taking light damage.
*/

status
leave_room(string arg)
{
  object ob;
  string verb, t;

  verb = query_verb();

  if (verb == "north" || verb == "n")
  {
    write(line_wrap("As you start walking north, you feel the healing energies disappear as abruptly as the clearing turns into valley and the grass turns into a dirt path.\n"));
    this_player()->move_player("north#"+RPATH+"road1");
/*
    say((string)this_player()->query_name() + " heads off to the north.\n",this_player());
    move_object(this_player(), RPATH+"road1");
*/
  }
  else
  {
    write("You feel the healing energies disappear as you enter the tunnel.\n");
/*
    say((string)this_player()->query_name()+" enters the tunnel to the south.\n", this_player());
    move_object(this_player(), RPATH+"tunnel3");
*/
    this_player()->move_player("south#"+RPATH+"tunnel3");
  }


/* Doing this differently now, so no need for this shit
  write((string)environment(this_player())->short()+"\n");
  ob = first_inventory(environment(this_player()));

  while(ob)
  {
    if (ob != this_player() && (t = (string)ob->short()))
      write(t+".\n");

    ob = next_inventory(ob);
  }
*/
  return 1;
}

status
query_property(string arg)
{
  if (arg != "no_fight")
    return 0;

  write("This is a sanctuary, not a PK zone.  Take it elsewhere.\n");
  return 1;
}

int
figure_align(object ob)
{
  string g;

  g = (string)ob->query_guild_name();

  switch(g)
  {
    case "shardak"         : return -ALIGN;
    case "Dark Order"      : return -ALIGN;
    case "Knights Templar" : return ALIGN;
    case "Rangers"         : return ALIGN;
    default                : return 0;
  }
}

status
check_for_players()
{
  object ob;

  ob = first_inventory(this_object());

  while(ob)
  {
    if (living(ob) && (status)ob->is_player())
      return 1;

    ob = next_inventory(ob);
  }

  return 0;
}

int
do_heal()
{
  object ob;

  while(remove_call_out("do_heal") != -1);

  if (!check_for_players())
    return 0;

  ob = first_inventory(this_object());

  while(ob)
  {
    if ((status)ob->is_player())
    {
      ob->add_alignment(figure_align(ob));
      ob->heal_self(random(HEAL_AMOUNT));
    }

    ob = next_inventory(ob);
  }

  call_out("do_heal", INTERVAL);
}

void
on_init()
{
  if (!this_player())
    return;

  write(HIG+"You feel at peace as you enter this clearing.\n"+NORM+NORM);

  /* changed by illarion - the NPC room was eating pets */
  if(this_player()->is_npc() && !this_player()->is_pet())
  {
    if (creator(this_player()) == "earwax")
    {
      move_object(this_player(), RPATH+"fields"+(random(10)+1));
      tell_room(environment(this_player()), (string)this_player()->query_name() + " arrives.\n");
    }

/* Changed - if monster guild goes back in I'll re-add this - Earwax
    move_object(this_player(), DROP_ROOM);
*/
    return;
  }

  call_out("do_heal",INTERVAL);
}

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("A Sanctuary");
  set_long("This is a small clearing, covered in thick grass.  The clearing is bound to the east and west by sheer rock faces, and to the south is a tunnel set into a mountainface.  The northern edge of the clearing is marked by the abrupt beginning of a dirt road.");
  add_exit("south", "&leave_room");
  add_exit("north", "&leave_room");
  move_object(clone_object(OPATH+"fountain"), this_object());
  add_desc("grass", "The grass abruptly ends at a dirt road, and shows no signs of wear.");
  add_desc("road", "A dirt road begins at the northern edge of this clearing.");
  add_desc("dirt road", "A dirt road begins at the northern edge of this clearing.");
  add_desc("tunnel", "A tunnel into the mountainface marks the southern edge of this clearing.");
  add_desc("mountainface", "A mountain range dominates the skyline to the south.");
  add_desc("rock faces", "This is a small valley surrounded on all sides except the northern, by sheer cliffs.");
  add_desc("faces", "This is a small valley surrounded on all sides except the northern, by sheer cliffs.");
  add_desc("cliffs", "They surround you.  You can't climb them, they're there as boundaries.");

  Privates = allocate(6);
  Corporals = allocate(2);

/* Changing these to simple mobs, experiment over.
  MOBD->set_fake_hb(1);
  move_object(MOBD, this_object());
*/
}

void
on_reset()
{
  object ob;

  if (!present("dispenser", this_object()))
    move_object(clone_object(DISPENSER), this_object());
}
