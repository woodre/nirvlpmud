#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/room";
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Tower Entrance";
  long_desc=
	"You stand before the mystic "+HIC+"Tower of Mages"+NORM+".  This huge structure towers\n"+
	"above you, reaching upwards into the sky.  The "+HIC+"Mages Tower"+NORM+" is a source\n"+
	"of "+YEL+"unity"+NORM+" and "+MAG+"power"+NORM+" for the Mages of Nirvana.  Here powerful Wizards meet\n"+
	"to forge and wield magics that could sunder the world.  The mystic silver\n"+
	"gates are open before you.\n";

  dest_dir=({
	ROOM_DIR+"main",		"enter",
	"players/saber/ryllian/ayre",	"leave",
  });

  call_out("random_message", 10);

}


random_message()
{
  int x;
  x = random(10);

  if(x == 0)
  {
	tell_room(this_object(),
	  "A Mage-Apprentice bumps into you and drops a huge pile of books on the ground\n"+
	  "The apprenctice glares at you coldy and starts picking up his books.\n");
   }
  if(x == 1)
  {
	tell_room(this_object(),
	  "An old lady enters the Tower dragging a large iron pot behind her.\n");
   }
  if(x == 2)
  {
	tell_room(this_object(),
	  "Several wizards stop at the gate to discuss something in a quiet voices.\n");
  }
  if(x == 3)
  {
	tell_room(this_object(),
	  "You notice a huge Dragon circling the Tower.\n");
  }
  if(x == 4)
  {
  }
  if(x == 5)
  {
	tell_room(this_object(),
	  "A Mage-Instructor stomps out of the tower swearing profusely.\n"+
	  "You notice a large scorch mark in the seat of his robes.\n");
  }
  if(x == 6)
  {
	tell_room(this_object(),
	  "You hear a strange maniacal laughter from inside the tower.\n");
  }
  if(x == 7)
  {
	tell_room(this_object(),
	  "A Pegasus lands gently at the Tower gates.\n"+
	  "An Arch-Mage dismounts and hurries inside the tower.\n"+
	  "The Pegasus beats its wings and flies off.\n");
  }
  if(x == 8)
  {
	tell_room(this_object(),
	  "A spice peddler enters the Tower to sell his wares.\n");
  }
  if(x == 9)
  {
	tell_room(this_object(),
	  "Two wizards exit the Tower arguing rather loudly.\n"+
	  "One of the wizards reaches into his robes, draws out a magic wand and\n"+
	  "turns the other into a Frog!\n");
  }

  call_out("random_message", 25);
  return 1;

}

