#include "/players/guilds/bards/bard_lib/lib.h"
#include <ansi.h>
#define tp this_player()->query_name()
inherit ROOM;

realm() { return "NT"; }
query_no_fight(){ return 1; }

void create() {
	::create();

  if(!present("tuyen",this_object())){
  move_object(
    clone_object("/players/guilds/bards/tuyen.c"),
  this_object()); }

  set_short(HIM+"The Bard Lore Chamber"+NORM);
  set_long(HIM+
    "The Bard Lore Chamber\n"+NORM+
    "The Lore room is a pleasant chamber filled with shelf upon\n"+
    "shelf of scrolls and books.  The western wall is covered with\n"+
    "maps of both Ryllian and Nirvana.  In the eastern corner sits\n"+
    "Tuyen, the song master of the Bards.  In the center of the room\n"+
    "is a large leather bound book.  To the east is the Common\n"+
    "room and to the north is Star's Greenery.\n"+
    "Commands: maps, books and scrolls.\n"
    );
  set_items(([
    "floor" :
    "The floor is made from a beautiful mahogany wood.\n",
    "scrolls" :
    "The room is filled with shelf upon shelf of scrolls.\n",
    "book" :
    "A large leather bound book filled with the lore of the city of\n"+
    "Ryllian.\n",
    "maps" :
    "The west wall is covered with maps.  Type <maps> for help.\n",
    ]));
  set_smells(([
    "default" :
    "The musty smell of old paper.\n",
    ]));
  set_sounds(([
    "default" :
    "It is silent here.\n",
    ]));
  set_exits(([
    "east" : "/players/guilds/bards/bardrooms/common",
    "north" : "/players/guilds/bards/bardrooms/advance",
    ]));
  set_light(1);
  replace_program(ROOM);
}

init(){
::init();
add_action("search","search");
add_action("maps","maps");
add_action("scrolls","scrolls");
add_action("books","books");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

books()  {
  write("Books to come later.              -- Reflex.\n");
  return 1;
        }

maps(str)  {
  if(!str)  {
  write("List of maps:\n"+
  "1)  Map of Ryllian.\n"+
  "\nType <maps> <#> to get a map.\n");
  return 1;
        }
  if(str == "1")  {
  move_object(clone_object("players/saber/stuff/flier.c"),this_player());
  write("You take a map.\n");
  say(tp+" takes a map from the shelf.\n");
  return 1;
        }
  write("There is no map by that name.\n");
  say(tp+" searches the shelf.\n");
  return 1;
        }

scrolls(str)  {
  if(!str)  {
  write("List of scrolls:\n"+
  "1 - 9 (bard trials)\n"+
  "h)  Bard trial hints.\n"+
  "m)  Mini guild scroll.\n"+
  "\nType <scrolls> <#> to get a scroll.\n");
  return 1;
        }
  if(str == "m" || str=="M")  {
  move_object(clone_object("/players/saber/mini/mini.c"),this_player());
  write("You take a scroll.\n");
  say(tp+" takes a scroll.\n");
  return 1;
        }
  if(str == "1")  {
  say(tp+" reads a scroll.\n");
  write(
 "Bard Trial One:\n"+
 "\nFind Johnathin de Oro downstairs and ask about <bard task 1>.\n\n");
  return 1;
        }
  if(str == "2")  {
  say(tp+" reads a scroll.\n");
  write(
 "Bard Trial Two:\n\n"+
 "Go to the Library of Ryllian (check a map if you need to) and\n"+
 "search for the root of your instrumental magical powers.\n\n");
  return 1;
        }
  if(str == "3")  {
  say(tp+" reads a scroll.\n");
  write(
 "Bard Trial Three:\n\n"+
 "Summon the ghost of Selsase.  She will test your bardic abilities.\n"+
 "BE WARNED: this bard trial can be fatal.  Be sure that you know\n"+
 "all of the lore found within the library and be aware of all your\n"+
 "bardic powers before you attempt to advance.\n"+
 "\nTo summon the ghost of Selsase, you will need a sapphire.\n"+
 "She will only respond to a summoning played upon a Violin.\n"+
 "Go to the clearing north of the rift in the mountains and\n"+
 " <summon selsase> to find the ghost.  <begin> when you are ready.\n"+
 "Be prepaired.\n\n");
  return 1;
        }
  if(str == "4")  {
  say(tp+" reads a scroll.\n");
  write(
 "Bard Trial Four:\n\n"+
 "Find the gypsy camp in the green valley.\n");
  write("Type <begin> when you do\n");
  return 1;
        }
  if(str == "5")  {
  say(tp+" reads a scroll.\n");
  write(
  "Bard Trial Five:\n\n"+
  "Go to the Valley of Rock (in the Spine of the Moon) and\n"+
  "cause the stones do dance and cry.  You may need to\n"+
  "<yell> to begin your trial.\n\n");
  return 1;
        }
  if(str == "7")  {
  say(tp+" reads a scroll.\n");
  write(
  "Bard Trial Seven:\n\n"+
  "Collect the following:\n"+
  "The fruit of a clam.\n"+
  "Bottled ghosts.\n"+
  "A silver gypsy medallion.\n"+
  "A stone of blood.\n"+
  "\nTake these materials to Johnathin de Oro and ask <scroll> for a scroll.\n"+
  "Read the scroll to visit the faerie court where you will be tested.\n\n"+
  "Type <begin> to start.\n");
  return 1;
        }
  if(str == "6")  {
  say(tp+" reads a scroll.\n");
  write(
  "\nBard Trial Six:\n\n"+
  "Find the Ebony Orb and give it to Star.\n"+
  "The Orb can be found within the realm of dreams, in Asgard.\n"+
  "(Check the well north of the post office).\n\n"+
  "Look for Loki.\n\n");
  return 1;
        }
  if(str == "8")  {
  say(tp+" reads a scroll.\n");
  write(
  "\nBard Trial Eight:\n\n"+
  "In the common room of Orin's Inn is a door leading south.\n"+
  "To go south, <translate> the <elvish> on the door.\n\n"+
  "Type <begin> to start.\n");
  return 1;
        }
  if(str=="9")  {
  say(tp+" reads a scroll.\n");
  write(
  "\nBard Trial Nine:\n\n"+
  "Beyond the Song room is the Emotions room.  To prove\n"+
  "yourself worthy of the title of Legendary Bard, you must\n"+
  "add to the repertoire of Bard emotions.\n\n");
  return 1;
  }
  if(str == "h" || str=="H")  {
  say(tp+" reads a scroll.\n");
  write(
  "\nHints on Bardic Trials...\n\n"+
  "K.I.S.S (keep it simple stupid) - try the simple stuff first, THEN\n"+
  "  get complex.  Most stuff isn't THAT hard.\n\n"+
  "Know your abilities.  Bard Trials are there to make sure that bards\n"+
  "  are aware of what powers they possess.\n\n"+
  "If a Bardic trial doesn't start when you think it should, type 'begin'\n"+
  "\nMake sure that you're in the right place.\n\n"+
  "Check the 'exact' wording of what is asked of you.\n\n"+
  "For some reason, the bard speach ; works better than the say ' for trials.\n\n"+
  "Be sure to use lower case when answering questions.\n\n"+
  "If you are VERY confused, ask for a clue.  Don't ask for help,\n"+
  "  because you don't want to get other bards in trouble...\n\n");
  return 1;
        }
  write("There is no scroll by that name.\n");
  say(tp+" searches the shelf.\n");
  return 1;
}
