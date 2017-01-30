#include        "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET more_reset();
TWO_EXIT("players/astaroth/tub", "east",
           "players/astaroth/bluedream", "south",
           "Kings of Sleep",
           "You have come to Lazarus' favourite musician\n" +
           "This is Stuart Hamm.  In the opinions of many, Lazarus included,\n"+
           "he is the greatest bass guitar player that has ever lived.\n"+
           "Due to the fact that Lazarus also plays bass guitar, he really\n"+
           "likes Stu Hamm and his music.  The end result is that Stu has\n"+
           "really good equipment in here, but he will be anything but an\n"+
           "easy kill.  Have fun and be prepared to drink heavily if you try\n"+
           "to take him.\n",
           1)
 
 
object monster, weapon, armor, money;
 
more_reset(){
if (!monster || !living(monster)) {
monster = clone_object ("obj/monster");
call_other (monster, "set_name", "stu");
call_other (monster, "set_alias", "hamm");
call_other (monster, "set_alt_name", "stuart");
call_other (monster, "set_level",20);
call_other(monster, "set_ep",2000000);
call_other (monster, "set_hp",750 + random(250));
call_other (monster, "set_spell", 400);
call_other (monster, "set_al",500);
call_other (monster, "set_race","human");
call_other (monster, "set_short","Stuart Hamm");
call_other(monster, "set_long", "Stuart Hamm\n");
call_other (monster, "set_ac",19);
call_other (monster, "set_wc",25);
call_other (monster, "set_aggressive",3);
call_other (monster, "set_chance", 70);
call_other (monster, "set_spell_mess2", "You are awestruck by Stuart's playing skill!");
call_other (monster, "set_spell_mess1","You are amazed by a solo!\n");
call_other (monster, "set_spell_dam", 35);
 
transfer (clone_object("obj/heal"), monster);
{
  weapon = clone_object("obj/weapon");
weapon->set_name("bass");
weapon->set_alias("factor bass");
weapon->set_alt_name("bass guitar");
weapon->set_short("Kubicki Factor Bass");
weapon->set_long("A Kubicki Factor Bass");
weapon->set_class(18);
weapon->set_weight(3);
weapon->set_chance(90);
weapon->set_spell_mess2("The bass generates a great solo");
weapon->set_spell_mess1("The strings of the bass guitar begin to glow...");
weapon->set_spell_dam(10);
weapon->set_value(8000);
transfer (weapon, monster);
}
{
   armor= clone_object("obj/armor");
armor->set_name("armor");
armor->set_alt_name("black ice");
armor->set_short("Black Ice");
armor->set_alias("ice");
armor->set_long("armor of the Black Ice.\n");
armor->set_value(5000);
armor->set_weight(6);
armor->set_ac(4);
armor->set_type("armor");
transfer (armor, monster);
}
move_object(monster, this_object());
}
}
