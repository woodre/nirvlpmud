inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("ranger");
set_short("The Lone Ranger");
set_long("The Lone Ranger says: Be Good Now.\n");
set_al(1000);
set_race("human");
set_level(15);
set_wc(20);
set_hp(225);
set_ac(12);
set_spell_mess1("The Lone Ranger hits you bad\n");
set_spell_mess2("The Lone Ranger hits you again\n");
set_chance(15);
set_spell_dam(15);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(600 + random(275));
move_object(coins,this_object());
}

init() {
  ::init();
  if(present("qstar",this_player())) {
  write("\n");
    write("I see you've talked to my friend the Green Lantern.\n"+
	  "He smiles and takes his star from you......\n"+
	  "then he asks, 'What can I do for you?'\n");
  write("\n");
    move_object(present("qstar",this_player()),this_object());
    move_object(clone_object("players/catwoman/closed/qst2.c"),
		this_player());
    return 1; }
}
