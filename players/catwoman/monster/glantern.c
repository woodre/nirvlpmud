inherit "obj/monster.talk";
object coins,player;
int is_quest;

reset(arg) {
::reset(arg);
if(arg) return;
is_quest = 0;

set_name("greenlantern");
set_short("The Greenlantern");
set_long("Yep hes here.\n");
set_al(1000);
set_race("human");
set_level(18);
set_wc(26);
set_hp(460);
set_ac(15);
set_spell_mess1("You get hit by a green light\n");
set_spell_mess2("You feel stunned\n");
set_chance(15);
set_spell_dam(25);
set_aggressive(0);
set_dead_ob(this_object());

coins = clone_object("obj/money");
coins->set_money(100+(random(200)));
move_object(coins,this_object());
}

init() {
  ::init();
  if(present("glring",this_player())) {
    write("\n");
    write("So you're the one that stole my ring!  I'll never give you\n"+
	  "the information you're looking for as long as I'm alive.\n"+
	  "In fact, I'll take my ring right now!......\n\n\n"+
	  "and he snatches his ring before you can react...\n\n\n");
    move_object(present("glring",this_player()),this_object());
    is_quest = 1;
    attack_object(this_player());
    return 1; }
}

monster_died() {
if(is_quest == 1) {
tell_object(this_player(),
  "In a dying gasp, Green Lantern whispers, 'The masked man had what\n"+
  "you're looking for last, just question him.  But be sure you have\n"+
  "this star with you so he knows you talked to me..... and with that\n"+
  "his eyes slowly close.....\n\n");
  tell_room(environment(),"The Green Lantern groans and dies...\n\n");
  move_object(clone_object("players/catwoman/armor/star.c"),
		this_player());
  return 1; }

else {
  tell_room(environment(),"Green Lantern doubles over and dies...\n");
  return 1; }
return 0; }
