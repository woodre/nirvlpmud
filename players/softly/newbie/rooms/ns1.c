#include "/players/softly/closed/ansi.h"
#include "/players/softly/newbie/define.h"
inherit "/players/softly/closed/std/room.c";

object club, guide;

void init()
{
  ::init();
  add_action("get_guide", "guide");
  add_action("get_club","club");
  if(this_player()->query_npc()) return;
  if(this_player()->query_level() > 7 && this_player()->query_level() < 20){
    write("You are too big for Adventurer's School!\n");
    move_object(this_player(), "/players/softly/nhall/rooms/n1");
    tell_room(environment(tp), tpn+" arrives suddenly.\n", ({tp}));
    command("look", this_player());
  }
  if(this_player()->query_level() < 20){
    if(this_player()->query_guild_exp() > 0 ||
       this_player()->query_guild_name() != 0 ||
       this_player()->query_guild_rank() > 0){
      write("You don't belong here!\n");
      move_object(this_player(), "/room/vill_green.c");
      tell_room(environment(tp), tpn+" arrives suddenly.\n", ({tp}));
      command("look", this_player());
    }
  }
}

status get_guide(){
    if(present("5n3b13", this_player())) { notify_fail("You already have a guide!\n"); 
    return 0; 
    }
    if(!present("nguide")){
      write ("\n"+HIR+"Drag'oman"+NORM+" speaks:\n\n"+"\tWelcome to Nirvana "  + tpn + ".\n\n\n");
     write("Type "+BOLD+"say help"+NORM+" for Drag'oman to continue.\n");
      guide = clone_object("/players/softly/newbie/mobs/nguide");
      move_object(clone_object("/players/softly/newbie/obj/thing"), this_player());
      guide->set_mynewbie((string)this_player()->query_real_name());
      move_object(guide, this_object());

      return 1;
    }
  return 0;
}

status get_club(){
  if(!present("newbie_wep", this_player())){
    if(!this_player()->add_weight(1)) {
      write("That is too heavy for you to carry.\n");
      return 1;
    }
    club = clone_object("players/softly/newbie/obj/club.c");
    move_object(club, this_player());
    write("You pick up a gnarled club.\n");
    return 1;
  }
  write("You already have a weapon!\n");
  return 1;
}

reset(arg) {
  if(arg) return;

  set_light(1);

  short_desc = "Hall of Apprentices [School]";
  long_desc =
    "  This is the entry to the School of the Apprentices.  Like the\n\
main Hall the walls are made of a white stone set in silver mortar,\n\
but they appear to have old marks and scratches on the lower stones.\n\
The high ceiling and polished floor look like new.  To the south is\n\
the main Hall of the Apprentices.  To the north is a shimmering open\n\
archway through which a brightly lit forest can be seen.  A discreet\n\
sign with silver lettering reads: 'Type "+BOLD+"guide"+NORM+" for a personal tutor'.\n";

  items = ({
    "mist",
    "Swirls of grey and silver cover the archway",
    "path",
    "The stone path is very worn, but clearly defines the way\n\
through the forest",
    "sign",
    "A small sign of polished rock with silver lettering is anchored\n\
on the wall at eye level.  It says 'Say 'guide' for a personal tutor'",
    "walls",
    "Polished white rock which is carefully laid in a silver mortar",
    "stone",
    "A heavy strong stone that is nearly unbreakable",
    "stones",
    "A heavy strong stone that is nearly unbreakable",
    "mortar",
    "An enchanted mortar that holds the hall together",
    "floor",
    "A polished marble floor that you can even see your reflection in",
    "ceiling",
    "A high ceiling made of stone",
    "marks",
    "Lettering in many languages is scribbled on the walls",
    "scratches",
    "Names of former students are scratched in the stone",
    "archway",
    "The large stone archway seems covered with a thin swirling\n\
mist.  Beyond the archway is a bright forest",
    "forest",
    "Sunlight streams down into the open forest.  A broad\n\
stone path begins on the far side of the archway",
  });

  dest_dir = ({
    "/players/softly/newbie/rooms/ns2.c","north",
    "/players/softly/nhall/rooms/n1.c","south",
  });
}

adv_skool() { return 1; }
