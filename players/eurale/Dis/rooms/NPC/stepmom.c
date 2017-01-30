
#define TO this_object()
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("stepmother");
set_race("human");
set_short("Stepmother");
set_alias("mother");
set_long(
	"  This is Cinderella's evil stepmother.  Her jet-black hair and\n"+
	"long pointed nose give her the appearance of a witch.  Her voice \n"+
	"is almost a 'cackle' and she puts on the airs of royalty.\n");
set_hp(500);
set_level(19);
set_al(-400);
set_aggressive(0);

if(!present("hairpin")){
  move_object(clone_object("players/eurale/Dis/rooms/OBJ/hairpin"),TO); }
init_command("wield hairpin");
set_ac(16);
set_wc(28);

set_chat_chance(20);
  load_chat("Stepmother smiles and nods.... \n");

gold = clone_object("obj/money");
gold->set_money(random(50)+1000);
move_object(gold,this_object());
}
