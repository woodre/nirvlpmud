inherit "obj/monster";

reset(arg)
{
  object coins,weapon,key;
  ::reset(arg);
  if(arg) return;
set_name("trainer");
set_race("human");
set_alias("man");
set_short("Halfling Trainer");
set_long(
"A large muscular man dressed in heavy leather.  You notice that\n"+
"the leather is covered with scratch and bite marks.\n");
set_level(19);
set_hp(425+random(100));
set_al(-800);
set_wc(26+random(4));
set_ac(14+random(4));
  set_chat_chance(2);
  set_a_chat_chance(10);
load_chat("Trainer looks around the room like he is looking for food.\n");
load_a_chat("Trainer says: Fools!  Only I can control the halflings!\n");
    set_chance(10);
    set_spell_mess1("Halfling Trainer glares at you with evil eyes.  You feel weaker.\n");
    set_spell_mess2("You feel an odd tingling as the Trainer smashes you with his sword\n");
    set_spell_dam(5);
  coins=clone_object("obj/money");
  coins->set_money(random(101)+750);
  move_object(coins,this_object());
  weapon = clone_object("/players/traff/weps/halfsword.c");
  move_object(weapon,this_object());
  init_command("wield sword");
  key=clone_object("/players/traff/room/rustkey.c");
  move_object(key,this_object());
}
