/*  Zapata  */

inherit "obj/monster.c";
reset(arg) {

int amt;
object gold;
::reset(arg);
if(arg) return;
set_name("barker");
set_alias("ticket barker");
set_race("human");
set_short("Ticket barker");
set_long(
	"  This is the Phantasm ticket barker.  He is a handsome but \n"+
	"burly and muscular man as he handles all the ticket money.  His \n"+
	"smile is warm and his demeanor friendly but don't be fooled, his \n"+
	"job is to get you to spend your money.\n");
set_level(20);
set_hp(730);
set_al(-10);
set_wc(30);
set_aggressive(0);
set_ac(18);

set_chat_chance(25);
  load_chat("The barker smiles and says:  Hello, folks.\n");
  load_chat("The barker bellows: Best deal on the mud, really!!\n");
  load_chat("The barker says: What's a few coins to you high rollers?\n");
  load_chat("The barker barks:  Come on, pay me! \n");
  load_chat("The barker chatters: Come on in, you'll love it.\n");

set_a_chat_chance(20);
  load_a_chat("The barker bellows:  I'll kick your ass now!\n");
  load_a_chat("The barker screams:  CHEAPSKATES trying to sneak in!\n");
}
