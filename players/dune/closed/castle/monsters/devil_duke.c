inherit "obj/monster";
#include "definitions.h"


id(str) { return str == "devil" || str == "demosater" ||
                 str == "duke"; }


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("Demosater");
   set_alias("demosater");
   set_short("Demosater, the Devil Duke");
   set_level(15);
   set_race("devil");
   set_hp(225);
   set_wc(20);
   set_ac(11);
   set_long(
"                         _,.-----.,_                \n"+
"                       ,-~           ~-.            \n"+
"                     ,^___           ___^.          \n"+
"                    /~    ~    .    ~    ~\\        \n"+
"                   Y  ,--._    I    _.--.  Y        \n"+
"                   | Y     ~-. | ,-~     Y |        \n"+
"                   | |        }:{        | |        \n"+
"                   j l       / | \\       ! l       \n"+
"                .-~  (__,.--  .^.  --.,__)  ~-.     \n"+
"               (           / / | \\ \\          )   \n"+
"                \\.____,   ~  \\/ \\/  ~   .____/  \n"+
"                 ^.____                 ____.^      \n"+
"                    | |T ~\\  !   !  /~ T| |        \n"+
"                    | |l   _ _ _ _ _   !| |         \n"+
"                    | l \\/V V V V V V\\/ j |       \n"+
"                    l  \\ \\|_|_|_|_|_|/ /  !       \n"+
"                     \\  \\[T T T T T TI/  /        \n"+
"                      \\  `^-^-^-^-^-^'  /          \n"+
"                       \\               /           \n"+
"                        \\.           ,/            \n"+
"                           ^-.___,-^                \n");
   set_chat_chance(10);
   set_chance(20);
   set_spell_dam(random(15)+15);
   set_spell_mess1("DEMOSATER RELEASES THE FIRES OF HELL AT YOU!");
   set_spell_mess2("DEMOSATER BLASTS YOU WITH EVIL DEVIL-FIRE!");
   load_chat("Demosater says: Damn you!\n");
   load_chat("Demosater says: You've ruined all my plans.\n");
   load_chat("Demosater says: At least now I shall destroy you myself.\n");
   load_chat("Demosater looks disdainfully upon you.\n");
   load_chat("Demosater says: Who dares interfere with Demosater's plan.\n");
   load_chat("Demosater laughs in a deep resounding voice.\n");
   load_chat("Demosater says: Yes, I am your true enemy.\n");
}
