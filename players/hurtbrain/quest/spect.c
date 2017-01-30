
inherit"obj/monster";
reset(arg) {
object gold;
string chat_str;
string a_chat_str;
::reset(arg);
if(arg) return;
if(!chat_str) {
chat_str = allocate(4);
a_chat_str = allocate(2);
chat_str[0] = "Spectator says: 'Hey , do you want to sit down please?'\n";
chat_str[1] = "Spectator shouts: 'C'mon guys...lets fuck these assholes.'\n";
chat_str[2] = "Spectator stands up to see the action.\n";
chat_str[3] = "Spectator shouts: 'Crush them near their goal line!'\n";
a_chat_str[0] = "Spectator says: 'Sit down you little bullshit!'\n";
a_chat_str[1] = "Spectator smashes your head.\n";
  }
set_name("spectator");
set_short("A spectator");
set_long(
"A man looking at the game and shouting like a mad. It doesn't seem to\n"
+ "be very dangerous.\n");
set_level(12);
set_race("human");
set_hp(180);
set_wc(16);
set_ac(9);
if(random(2))
set_aggressive(1);
set_spell_mess2("");
set_chat_chance (40);
load_chat(chat_str[0]);
load_chat(chat_str[1]);
load_chat(chat_str[2]);
load_chat(chat_str[3]);
set_a_chat_chance(40);
load_a_chat(a_chat_str[0]);
load_a_chat(a_chat_str[1]);
gold=clone_object("obj/money");
gold->set_money(550+random(100));
move_object(gold,this_object());
}
