
inherit"obj/monster";
reset(arg) {
string chat_str;
string a_chat_str;
::reset(arg);
if(arg) return;
if(!chat_str) {
chat_str = allocate(3);
a_chat_str = allocate(2);
chat_str[0] = "blah 1\n";
chat_str[1] = "blah 2\n";
chat_str[2] = "blah 3\n";
a_chat_str[0] = "I will kill our bitch ass\n";
a_chat_str[1] = "Your as good as dead.\n";
  }
set_name("Testing This");
set_alias("this");
set_short("This is a Short Desc.");
set_long(
"Your fucking mother\n");
set_level(23);
set_race("Drow");
set_al(444);
set_wc(35);
set_ac(35);
set_chance(30);
set_spell_dam(100);
set_spell_mess1("Testing cast a beam of bright light at it's attacker.");
set_spell_mess2("Your are nailed by a beam of light.");
load_chat(2,chat_str);
load_a_chat(2,a_chat_str);
add_money(1000);
}
