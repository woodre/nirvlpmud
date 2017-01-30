#include <ansi.h>
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Nirvana Music Festival";
long_desc =
" Tents are scattered all about as people walk to and fro.\n"+
" Dust fills the air, creating sheens of light that scatter all about.\n"+
 "Camping goes farther to the north toward the stage.\n";

items = ({
"shelter",
"A torn rain shelter that still may provide some shelter from the rain.",
"dust",
"A thick dust created by the dry climate and thousands of people walking",
"tank",
"A tank dispensing the gas nitrious oxide, like what is used at the dentist office.",
"people",
"All sorts of hippy looking people wander about",
"cars",
"Cars with phish bumper stickers",
"trucks",
"Dusty trucks with grateful dead stickers.",
  });

dest_dir = ({
"/players/xiu/tour/rms/e2.c","north",
"/players/xiu/tour/rms/1.c","west",
});
}
