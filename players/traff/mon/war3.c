inherit "obj/monster";

reset(arg)
{
  object coins;
  ::reset(arg);
  if(arg) return;
    set_name("warrior");
    set_race("human");
    set_alias("soldier");
    set_short("Young warrior");
    set_long(
"This young lad was probably pushing a plow a short time ago.\n"+
"He has blond hair and blue eyes.  His face is set with a look\n"+
"of determination.  He knows his chances here are not good, but\n"+
"he will not run because he is a man now.  He will worry about\n"+
"the future tomorrow!\n");
    set_level(14+random(3));
    set_hp(200+random(200));
    set_al(1000);
    set_wc(18+random(5));
    set_ac(11+random(3));
  set_chat_chance(5);
  set_a_chat_chance(10);
load_chat("A warrior looks at you, unsure if you are friend or foe.\n");
load_a_chat("Warrior screams as he charges you.\n");
  coins=clone_object("obj/money");
  coins->set_money(random(101)+750);
  move_object(coins,this_object());
}
