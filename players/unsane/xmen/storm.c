#include <ansi.h>
inherit "/obj/monster";

object gold;
reset(arg) {
::reset(arg);
if(!arg) {
    set_name("storm");
set_alias("ororo");
set_short("Storm of the Xmen");
    set_race("xman");
    set_long(
"This is storm of the X-men.  She has the legenday powers of an ancient\n"+
"affrican goddess.  She can summon up hurricanes and torrential rains and\n"+
"all other sorts of weather-related mischief.  She is a tall black woman\n"+
"with long white hair.  She holds a staff in her hand and glares angrily\n"+
"at Cylops and you.  She is currently in a discussion with Cyclops about\n"+
"the leadership of the X-men.\n");
gold = clone_object("obj/money");
gold -> set_money (random (10) + 500);
move_object(gold, this_object());
move_object(clone_object("/players/unsane/xmen/boots.c"), this_object());
move_object(clone_object("/players/unsane/xmen/staff.c"),this_object());
   set_level(18);
   set_ac(14);
   set_wc(26);
   set_hp(600);
   set_al(250);
/*
set_chance(20);
set_spell_dam(30);
set_spell_mess2("Storm fries you with lightning!");
set_spell_mess1("Storm fries her foe with lightning!");
*/
  set_aggressive(0);
    set_a_chat_chance(10);
   set_chat_chance(10);
load_chat("Storm calmly says: You cannot handle this burden Scott.\n");
load_chat("Storm says: Professor X is not here now.\n");
  load_chat("Storm stares intensely at Cyclops.\n");
load_chat("Storm says: Dammit Scott, you listen to me.\n");
load_chat("Storm says: Wolverine is getting more and more maniacal.\n");
load_a_chat("Storm says: I suppose I'll have to kill this intruder too.\n");
load_a_chat("Storm says: What kind of security are you running here cyclops?\n");
load_a_chat("Storm says: X-men Unite!  We have an intruder!\n");
/* see cyclops.c for computation values */
set_wc_bonus(5);
}
}

heart_beat()
{
     ::heart_beat();
     if(!random(5) && attacker_ob)
       fry_lightning();
}

fry_lightning()
{
     tell_object(attacker_ob, "Storm fries you with " + HIC + "lightning" + NORM + "!\n");
     tell_room(environment(), "Storm fries " + attacker_ob->query_name() + " with " + HIC + "lightning" + NORM + "!\n", ({ attacker_ob }));
     attacker_ob->hit_player(random(30), "other|lightning");
}
