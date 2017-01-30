inherit "obj/monster";

reset(arg)
{
  object coins;
  ::reset(arg);
  if(arg) return;
    set_name("warrior");
    set_race("human");
    set_alias("soldier");
    set_short("Experienced warrior");
    set_long(
"A professional soldier, this middle aged warrior is in good\n"+
"shape.  Medium height with brown hair and a distinctive\n"+
"scar on his cheek, he has helped train most of the men\n"+
"fighting here.  He is tough!  Fair to his troops, but\n"+
"ruthless to his enemies.\n");
    set_level(15+random(3));
    set_hp(325+random(100));
    set_al(1000);
    set_wc(20+random(5));
    set_ac(12+random(3));
  set_chat_chance(5);
  set_a_chat_chance(10);
load_chat("A warrior looks at you, unsure if you are friend or foe.\n");
load_a_chat("Warrior screams as he charges you.\n");
  coins=clone_object("obj/money");
  coins->set_money(random(101)+850);
  move_object(coins,this_object());
}
