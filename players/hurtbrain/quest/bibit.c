
inherit"obj/monster";
reset(arg) {
object gold;
object treasure;
string chat_str;
::reset(arg);
if(arg) return;
if(!chat_str) {
chat_str = allocate(3);
chat_str[0] = "Pitchman yells: 'Drinks, nuts and ice creams!'\n";
chat_str[1] = "Pitchman says: 'A Coke? One dollar, please.'\n";
chat_str[2] = "Pitchman gets the money and gives away the drink.\n";
  }
set_name("pitchman");
set_short("The pitchman");
set_long(
"This is a little man selling drinks and foods.\n");
set_level(17);
set_race("human");
set_hp(450);
set_wc(24);
set_ac(14);
set_spell_mess2("");
set_chat_chance (75);
load_chat(chat_str[0]);
load_chat(chat_str[1]);
load_chat(chat_str[2]);
gold=clone_object("obj/money");
gold->set_money(500);
move_object(gold,this_object());
treasure = clone_object("players/hurtbrain/quest/coke");
if(treasure) move_object(treasure,this_object());
}
