
#define TO this_object()
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("prince");
set_race("human");
set_short("Prince");
set_alias("mother");
set_long(
	"  The Prince is dressed for the royal ball.  He has on a red \n"+
	"velvet jacket with gold epilets, a ruffled white shirt, black \n"+
	"trousers and polished riding boots.\n");
set_hp(500);
set_level(20);
set_al(200);
set_aggressive(0);

if(!present("boots")) {
  move_object(clone_object("players/eurale/Dis/rooms/OBJ/boots"),TO); }
init_command("wear boots");

set_ac(17);
set_wc(30);

set_chat_chance(20);
  load_chat("The Prince shakes your hand... \n");
  load_chat("The Prince bows... and smiles...\n");

gold = clone_object("obj/money");
gold->set_money(random(500)+3750);
move_object(gold,this_object());
}
