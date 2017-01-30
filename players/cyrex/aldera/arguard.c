
inherit"obj/monster";
reset(arg) {
object armor;
object weapon;
object treasure;
string chat_str;
string a_chat_str;
::reset(arg);
if(arg) return;
if(!chat_str) {
chat_str = allocate(2);
a_chat_str = allocate(2);
chat_str[0] = "The guard stares at you.\n";
chat_str[1] = "Royal Guard says: move along now children.\n";
a_chat_str[0] = "The Royal Guard says: I don't want to hurt you.\n";
a_chat_str[1] = "The Royal Guard says: Please stop this nonsense at once!\n";
  }
set_name("royal guard");
set_alias("guard");
set_short("Royal Guard");
set_long(
"One of the many guardians of the Aldera Castle. He looks very proud.\n");
set_level(19);
set_race("human");
set_hp(1000);
set_al(-1000);
set_wc(20);
set_ac(15);
set_spell_mess2("");
load_chat(15,chat_str);
load_a_chat(15,a_chat_str);
armor = clone_object("/players/cyrex/aldera/aarmor");
if(armor) {
move_object(armor,this_object());
  }
weapon = clone_object("/players/cyrex/aldera/ablade");
if(weapon) {
move_object(weapon,this_object());
   }
treasure = clone_object("/players/cyrex/aldera/acloak");
if(treasure) move_object(treasure,this_object());
}
