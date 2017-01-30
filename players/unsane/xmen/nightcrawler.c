int i;
inherit "obj/monster.talk";
int hps;

object gold;
reset(arg) {
::reset(arg);
if(!arg) {
    set_name("nightcrawler");
set_alias("kurt");
set_short("Nightcrawler of the Xmen");
    set_race("xman");
    set_long(
"  Nightcrawler is a furry blue humanoid with a long forked tail.  He somewhat\n"+
"resembles a demon in appearance, a fact that didn't help him much in\n"+
"his youth.  He seems to be troubled by his life and appearance.  But he\n"+
"finds friendship with Wolverine and the other X-men.  It is said that\n"+
"he can teleport, making a BAMF sound and leaving behind the smell of \n"+
"brimstone.\n");
enable_commands();
set_heart_beat(1);
gold = clone_object("obj/money");
gold -> set_money (random (500) + 500);
move_object(gold, this_object());
move_object(clone_object("/players/unsane/xmen/tail.c"), this_object());
move_object(clone_object("/players/unsane/xmen/gloves.c"),this_object());
   set_level(19);
   set_ac(15);
   set_wc(28);
   set_hp(700);
   set_al(400);
set_chance(10);
set_spell_dam(20);
set_spell_mess2("Nightcrawler grabs a body part and tries to teleport it off of you!");
set_spell_mess1("Nightcrawler tries to teleport his foe's limb!");
  set_aggressive(0);
    set_a_chat_chance(10);
   set_chat_chance(10);
load_chat("Nightcrawler says: Sprechen sie Deutsch?\n");
load_chat("Nightcrawler says: Did you see the inferno?\n");
load_chat("Nightcrawler says: Just like old times huh Wolvie?\n");
load_chat("Nightcrawler does a somersault.\n");
load_chat("Nightcrawler winks at you.\n");
load_a_chat("Nightcrawler seems upset with you.\n");
load_a_chat("Nightcrawler says: X-men Unite!\n");
load_a_chat("Nightcrawler clenches his fists.\n");
}
}
heart_beat(){
::heart_beat();
hps = this_object()->query_hp();
if (hps < 30) {
i = random(3);
if (i == 0) {write("Nightcrawler tries to BAMF away but fails.\n");}
if (i == 1) {
say("BAMF!\n");
move_object(this_object(),"/players/unsane/xmen/control");
say("BAMF!\n");
}
if (i==2) {
say("BAMF!\n");
move_object(this_object(),"/players/unsane/xmen/danger");
say("BAMF!\n");
}
}
}
