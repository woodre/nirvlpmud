#define NAME "Dune"
#define DEST "room/plane8"
/*
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */


id(str) { return str == "world" || str == "lothlorien" ||
                 str == "ard"   || str == "lorien"     ||
                 str == "oracle"; }


init() { add_action("pass", "pass"); }


short() { return "The Lothlorien Oracle"; }


long()
{
  write(
"     Before you stands the beautiful sculptures of two sphinxes.\n"+
"They stand 50 feet tall, their marvelous wings stretch into the\n"+
"heavens.  A bright blue glow emanates from their sparkling stone\n"+
"flesh.  However beautiful they are, they may also be a ward against\n"+
"evil.  For beyond lies a land torn and shattered.  The sphinxes\n"+
"stand guard, facing eachother.  Beyond them spans the unknown.\n"+
"Are you bold enough to 'pass through the oracle'?\n");
}


reset(arg)
{
  object quest;
  if (!present("lost_cities", find_object("room/quest_room.c")))
  {
    quest = clone_object("/obj/quest_obj.c");
    quest->set_name("lost_cities");
    quest->set_hint(
      "\n"+
      "       ~~~~~~~~~~Lothlorien Oracle~~~~~~~~~~\n"+
      "       Oracle of blue and twin watching eyes\n"+
      "       Manacle of black and skull of despise\n"+
      "       ~~~~~Seek Amerasu~~~Say her name~~~~\n");
    move_object(quest, "/room/quest_room.c");
  }


  if (arg) return;
  call_other("/players/dune/closed/enterload.c", "prepare", "now");
  move_object(this_object(), DEST);
}


pass(string str)
{
  if (!str) return 0;
  if (str != "through the oracle") return 0;
    tell_object(this_player(),
"                              _,.-----.,_                \n"+
"                            ,-~           ~-.            \n"+
"                          ,^___           ___^.          \n"+
"                         /~    ~    .    ~    ~\\        \n"+
"                        Y  ,--._    I    _.--.  Y        \n"+
"                        | Y     ~-. | ,-~     Y |        \n"+
"                        | |        }:{        | |        \n"+
"                        j l       / | \\       ! l       \n"+
"                     .-~  (__,.--  .^.  --.,__)  ~-.     \n"+
"                    (           / / | \\ \\          )   \n"+
"                     \\.____,   ~  \\/ \\/  ~   .____/  \n"+
"                      ^.____                 ____.^      \n"+
"                         | |T ~\\  !   !  /~ T| |        \n"+
"                         | |l   _ _ _ _ _   !| |         \n"+
"                         | l \\/V V V V V V\\/ j |       \n"+
"                         l  \\ \\|_|_|_|_|_|/ /  !       \n"+
"                          \\  \\[T T T T T TI/  /        \n"+
"                           \\  `^-^-^-^-^-^'  /          \n"+
"                            \\               /           \n"+
"                             \\.           ,/            \n"+
"                                ^-.___,-^                \n");
    tell_object(this_player(),
"              I AM THE SOUL DEVOURER AND THAT WHICH HUNTS YOU\n");
    call_other(this_player(), "move_player",
       "Lothlorien#players/dune/closed/castle/rooms/green1.c");
    call_other("/players/dune/closed/castle/rooms/moonshrine.c", "reset");
    return 1;
}


query_save_flag() { return 1; }
is_castle() { return 1;}
