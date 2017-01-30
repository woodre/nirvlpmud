#pragma strong_types

#include "../def.h"

inherit "room/room";

void reset(status arg) {
  if (arg)
    return;
  ::reset(arg);

  if (!present("board"))
    move_object(clone_object("/players/guilds/dopplegangers/obj/mboard"),
                this_object());

  set_light(1);
  short_desc = "Mystics' Faction Party Room";
  long_desc  = "This is the Mystics' Party Room.\n" +
"You are obviously in the guild so this is the place for you to mingle \n" +
"with everybody and spend some time away from the scum of the mud since, \n" +
"only the chosen can enter this room.\n";
  dest_dir = ({
    "/players/guilds/dopplegangers/room/mystic_entrance", "east",
    "/room/church", "church",
    "/room/shop", "shop",
    "/players/guilds/dopplegangers/room/guildhall", "doppguild",
    "/room/adv_guild", "adventurers",
    "/room/pub2", "pub",
    "/players/guilds/dopplegangers/room/guildhall", "guild",
  });
}

void init() {
  object badge;

  ::init();

  badge = present("V-GUILD", this_player());

  if (!badge->query_faction("mystic")) {
    write("YOU ARE NOT A MYSTIC!\n" +
          "Only the chosen will be allowed to enter this room!\n");
    say(this_player()->query_name() +
        " tried to enter the room but gets kicked out!\n");
    move_object(this_player(), "./mystic_guild_entrance");
    write("Join our guild before entering the faction's party room.\n");
  }
}

