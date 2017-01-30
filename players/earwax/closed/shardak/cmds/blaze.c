/*
 * Written 2000 by Verte
 * Creates a blaze around the room
 * which does randomized dmg :)
 */

#include "/players/vertebraker/ansi.h"

#include "../def.h"
#include "../std.h"
#include "../macros.h"

string
take_it()
{
    string z;

    switch(random(8))
    {
      case 0:
        z = "Flames leap around the area...\n";
        break;
      case 1:
        z = "Scores of flames burn around you...\n";
        break;
      case 2:
        z = "The heat in the room builds into a fiery crescendo...\n";
        break;
      case 3:
        z = "Fire rages all around you...\n";
        break;
      case 4:
        z = "Dark, twisted bursts of fire erupt around the area!\n";
        break;
      case 5:
        z = "Demonik fire twists and scorches the area...\n";
        break;
      case 6:
        z = "Pulses of withering blasts of flame engorge the area!\n";
        break;
      case 7:
        z = "Deathly, blood red flames constrict around you...\n";
        break;
    }

    return ((0 == random(3) ? HIR : RED) + z + NORM);
}

status 
main()
{
    string msg;
    object a, room, flames, z;

    needrank(4);
    needmana(100);
    
    flames = (mixed)previous_object()->query_flames();

    if(this_player()->query_ghost()) return 0;

    if(!flames && !(flames = present("shardak_fire", environment(this_player()))))
    {
      notify_fail("\
You must conjure some of the dark flames in order\n\
to cast this spell.\n");
      return 0;
    }
    room = environment(a = this_player());
    if(file_name(room)[0..3] == "room" ||
       room->query_no_fight())
    {
      notify_fail(
"There is some otherworldly protection in this room\n\
that forbids this action from occuring.\n");
      return 0;
    }
    if((status)room->query_shardak_blaze())
    {
      notify_fail("\
This room is already burning...\n");
      return 0;
    }
    write("\
You hold your right hand up in the air.\n\
The mark carved into your hand twinges with red.\n");

    tell_room(room,
(string)a->query_name() + " holds " + 
  possessive(a) + " right hand aloft into the air.\n");

    if(0 == random(3))
      tell_room(room, "\t\
Heat simmers around the room....\n\n", ({ a }));

    msg = take_it();

    tell_room(room, msg);

    z = clone_object(OBJDIR + "blaze");
    this_player()->add_spell_point(-100);
    z->set_caster(a);
    flames->reduce_strength(4 + random(6));
    z->start_shadow(room);

    return 1;
}
