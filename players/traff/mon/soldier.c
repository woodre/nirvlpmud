inherit "obj/monster";

reset(arg)
{
  object coins,weapon;
  ::reset(arg);
  if(arg) return;
    set_name("soldier");
    set_race("human");
    set_alias("man");
    set_short("Soldier");
    set_long("An off duty soldier relaxing after duty on the wall.\n");
    set_level(10);
    set_hp(150);
    set_al(-250);
    set_ac(7+random(3));
  set_chat_chance(15);
  set_a_chat_chance(25);
load_chat("Soldier says: Casca is going to crush the rebels any day now.\n");
load_chat("Soldier winks at Jill.\n");
load_chat("Soldier says: The halflings will be loose in Skoda soon!\n");
load_chat("Soldier says: With all the new taxes you would think I could get a raise!\n");
load_a_chat("Soldier sneers: You wimp!  I'll make short work of you!\n");
load_a_chat("Soldier says: Bad enough I have to stand on the wall all day.  Now I\n"+
"to put up with the likes of you!\n");
load_a_chat("Soldier kicks a chair out of his way.\n");
  coins=clone_object("obj/money");
  coins->set_money(random(101)+400);
  move_object(coins,this_object());
  weapon = clone_object("/players/traff/weps/sword.c");
  move_object(weapon,this_object());
  init_command("wield sword");
/* MOVED SET_WC TO AFTER INIT WIELD -Snow */
  set_wc(13+random(3));
}
