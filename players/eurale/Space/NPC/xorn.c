/*  The heal seller  */

#include "/players/eurale/closed/ansi.h"
#define TP this_player()
#define TPRN this_player()->query_real_name()
inherit "obj/monster";
object item;
int value,m;
int T;

reset(arg) {
object gold, buyer;

::reset(arg);
T = 1;
if(arg) return;
set_name("xorn");
set_alias("traveler");
set_race("alien");
set_short(BOLD+"Xorn"+NORM+", the traveler");
set_long(
  "  The wide body of Xorn is made of a pebbly, stone_like material.\n"+
  "It has a large, powerful mouth on top of its head with three\n"+
  "long arms tipped with sharp talons, symmetrically positioned\n"+
  "every 120 degrees around it.  Between the arms are large, stone-\n"+
  "lidded eyes that see in all directions.  At it's base are three\n"+
  "thick, short legs, each directly beneath an eye.  The whole body\n"+
  "looks to be designed for burrowing, mouth first.  Xorn has traveled\n"+
  "far and wide across deep space accumulating items to sell.  If you\n"+
  "would like to see his wares, just type 'ask'.  To purchase any of\n"+
  "his treasures, just 'buy <item>'.\n");

set_level(21);
set_hp(1050);
set_al(0);
set_wc(42);
set_ac(18);
set_heal(3,5);
set_aggressive(0);

set_chat_chance(2);
  load_chat("Xorn grunts, 'What want?'\n");

gold = clone_object("obj/money");
gold->set_money(3000 + random(1000));
move_object(gold,this_object());
}

init() {
add_action("ask","ask");
add_action("buy","buy");
}

ask(str) {
if( (!str) || str == "xorn" || str == "traveler" ) {
  write("Xorn looks at you and grunts.  He then shows you the following\n"+
	"items that you may buy...\n\n"+
    "     leechworm                768 coins\n"+
    "     space grub              1184 coins\n"+
    "     luminescent liquid      2400 coins\n"+
    "     relbeek wafer           2400 coins\n"+
"\n");
  return 1; }
}

buy(str) {
m = 0;

if(str == "liquid" || str == "luminescent liquid") {
  item = clone_object("players/eurale/Space/OBJ/ogyaf.c");
  value = 2400;
  m = 1; }

if(str == "wafer" || str == "relbeek wafer" || str == "relbeek") {
  item = clone_object("players/eurale/Space/OBJ/relbeek.c");
  value = 2400;
  m = 1; }

if(str == "grub" || str == "space grub") {
  item = clone_object("players/eurale/Space/OBJ/grub.c");
  value = 1152;
  m = 1; }

if(str == "leechworm" || str == "leech") {
  item = clone_object("players/eurale/Space/OBJ/leechworm.c");
  value = 768;
  m = 1; }

if(m) {
if(this_player()->query_money() <value) {
  write("'Come back with more coins', gurgles Xorn\n");
  return 1; }
if(!call_other(TP,"add_weight",call_other(item,"query_weight"))) {
  write("Xorn gurgles, 'you'll need to lighten your load first'.\n");
  return 1; }
TP->add_money(-value);
move_object(item,this_player());
say(capitalize(TPRN)+" buys a "+str+".\n");
return 1; }

else {
  write("'Me no have that!', gurgles Xorn in disgust\n");
  return 1; }
}
