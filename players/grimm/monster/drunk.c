inherit "obj/monster.talk";
object coins,glue;

reset(arg) {
::reset(arg);
if(arg) return;
set_name("drunk");
set_short("The town drunk");
set_long("This is the town drunk.  He is very weak and annoying, Bruno would love it if\nyou were to kill him off.\n");
set_level(6);
set_wc(7);
set_aggressive(0);
set_chat_chance(90);
load_chat("Drunk sings: How ddrie I ammm, hic hic, how ddrie I ammm, ...\n");
load_chat("Drunk pukes on your shoes.\n");
load_chat("Drunk says: Will you buy me another drink?\n");
load_chat("Drunk snores loudly.\n");
coins = clone_object("obj/money");
coins->set_money(10+(random(30)));
move_object(coins,this_object());
}
