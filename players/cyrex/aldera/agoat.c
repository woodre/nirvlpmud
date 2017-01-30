
inherit"obj/monster";
reset(arg) {
string chat_str;
string a_chat_str;
::reset(arg);
if(arg) return;
if(!chat_str) {
chat_str = allocate(2);
a_chat_str = allocate(2);
chat_str[0] = "The goat goes 'baaaaah'.\n";
chat_str[1] = "The goat searches for some grass to chew.\n";
a_chat_str[0] = "The goat tries to run away but gets stuck in the thick snow.\n";
a_chat_str[1] = "The goat licks you.\n";
  }
set_name("goat");
set_alias("goat");
set_short("a goat");
set_long(
"A lonely old mountain goat that needs some grass to chew. Unfortunately, as\n"
+ "the snow keeps falling, there will be NO grass! Kill the stupid goat! Why\n"
+ "the heck did he wander up here in the first place???\n");
set_level(5);
set_race("goat");
set_hp(200);
set_al(-200);
set_wc(10);
set_ac(30);
set_spell_mess2("");
load_chat(40,chat_str);
load_a_chat(40,a_chat_str);
}
