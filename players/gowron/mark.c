inherit "obj/monster";

reset(arg)
{
object gold,armour,weapon;
  ::reset(arg);
  if(arg) return;
set_name("mark");
  set_race("human");
  set_alias("");
set_short("Mark the lonely warrior of the naked kind");
set_long("Mark is the last of the proud.\n");
set_level(100);
set_hp(50000)
set_al(0);
set_wc(1);
set_ac(100);
  set_chat_chance(2);
  load_chat("You want to kill Mark, you really want to.");
  load_chat("You foolishly attack mark!\n"
            "He laughs at your dumb attempt.\n");
  gold=clone_object("obj/money");
gold->set_money(random(500)+999);
  move_object(gold,this_object());
weapon=clone_object("/players/gemini/weapon/gun.c");
  move_object(weapon,this_object());
armor=clone_object("/players/gemini/armour/vest.c");
  move_object(armor,this_object());
}

