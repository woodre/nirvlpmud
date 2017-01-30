inherit "obj/monster";

reset(arg)
{
  object coins;
  ::reset(arg);
  if(arg) return;
    set_name("butler");
    set_race("human");
    set_alias("man");
    set_short("Butler");
    set_long(
"A slender old man.  He is well dressed, and looks as if he has\n"+
"held this position for a LONG time, and served many masters.\n"+
"He seems as much a part of this place as the furniture.\n");
    set_level(16);
    set_hp(400);
    set_al(500);
    set_wc(22);
    set_ac(13);
  set_chat_chance(20);
  set_a_chat_chance(25);
load_chat("Butler says:  Welcome to Delnoch Keep.\n");
load_chat("Butler whispers: It's not safe to enter here.\n");
load_chat("Butler says: Casca doesn't like guests.  It would be best to leave.\n");
load_chat("Butler says: This was a fine place when the Earl of Bronze ruled here.\n");
load_a_chat("Butler cries: Go ahead and kill me!  I'll be better off dead!\n");
load_a_chat("Butler croaks: Just because I'm old doesn't mean I'm weak!\n");
load_a_chat("Butler laughs: The halflings will feed on your corpse!\n");
  coins=clone_object("obj/money");
  coins->set_money(random(100)+790);
  move_object(coins,this_object());
}
