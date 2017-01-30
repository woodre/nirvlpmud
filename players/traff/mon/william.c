inherit "obj/monster";

reset(arg)
{
  object coins;
  ::reset(arg);
  if(arg) return;
    set_name("william");
    set_race("human");
    set_alias("man");
    set_short("William");
    set_long(
"One of the residents of the keep.  He does minor chores for Casca\n"+
"and spends most of his time here, waiting for the next meal.\n");
    set_level(18);
    set_hp(400+random(100));
    set_al(-750);
    set_wc(26);
    set_ac(15);
  set_chat_chance(15);
  set_a_chat_chance(20);
load_chat("William says: Casca is offering a reward for Tenaka.\n");
load_chat("William says: I'll be glad when the rebels are gone.\n");
load_chat("William says: Girl!  Bring me some tea.\n");
load_chat("William say: I don't know why it's so hard to keep help these days.\n");
load_chat("William confides: We'll be rid of the halflings soon.  They are all\n"+
"being sent out to fight the rebels.\n");
load_chat("William smiles.\n");
load_chat("William confides: Casca's minions are gathering information all the time.\n");
load_a_chat("William shouts: Guards!  Help me!");
load_a_chat("William laughs: The halflings will feed on your corpse!\n");
  coins=clone_object("obj/money");
  coins->set_money(random(250)+790);
  move_object(coins,this_object());
}
