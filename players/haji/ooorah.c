inherit "obj/monster.c";
reset (str){
object sword, shield, money, suit;
 if (str) return;
set_name("guard");
set_short("Castle Guard");
set_long("You see before you a man about seven feet tall who looks like he \n"+
"could rip your face off and eat it.\n");
set_a_chat_chance(15);
load_a_chat("\nYou shall not pass !!!\n\n");
set_level(13);
set_aggressive(0);
set_hp(250);
set_al(-300);
set_spell_mess1("The guard lands a devastating blow with his halberd.\n");
set_spell_mess2("You are staggered by the strength of that last blow.\n");
set_chance(15);
set_spell_dam(10);
sword = clone_object("players/sauron/weapons/long_sword");
money = clone_object("obj/money");
shield = clone_object("players/sauron/armors/oak_shield");
suit = clone_object("players/sauron/armors/chain_mail");
move_object(sword,this_object());
move_object(suit,this_object());
move_object(shield,this_object());
    command("wield sword");
::reset(0);
}
