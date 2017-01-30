
inherit "obj/monster";
object boots;
int items;

reset(arg) {
::reset(arg);
if(arg) return;

set_name("Robotech Master");
set_alias("master");
set_short("Robotech Master");
set_long(
        "He is second of the three Masters. They were once and still are the\n"+
        "the creators of life, including the Zentradis'. Alas, they have no\n"+
        "more strength to carry out the final mission of destroying the\n"+
        "invids for they are three and they are many. They seem to be\n"+
        "guarding the entrance to the north.\n");
set_level(20);
set_hp(2000);
set_al(-1000);
set_ac(25);
set_wc(35);
set_aggressive(1);

set_chat_chance(5);
load_chat("Master says: What are you doing here?\n");
load_chat("Master says: You must leave at once, or else!\n");
set_a_chat_chance(5);
load_a_chat("Master screams: You dare attack me?....ME?\n");
load_a_chat("Master screams: You will never get your hands on the amulokt!\n");

boots = clone_object("players/cyrex/quest/boots");
move_object(boots, this_object());
return 1;
}
