inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold, weapon;
  gold = clone_object("obj/money");
  gold->set_money(random(101) + 550);
  move_object(gold,this_object());
  weapon = clone_object("/players/morgoth/WEAPONS/sword");
  move_object(weapon,this_object());
  init_command("wield sword");
     set_name("guard");
     set_short("Morgoth's Guard");
     set_race( "human");
     set_alias("guard");
     set_long("This tall, merciless, well muscled guard is best left alone.\n" +
              "His allegiance is to Morgoth and he will fight to the death to\n" +
              "protect the realm. He towers before you silently, motionless.\n");
     set_level(14);
     set_ac(20 + random(3));
     set_wc(20 + random(3));
     set_hp(250 + random(40));
     set_al(0);
     set_aggressive(0);
     set_a_chat_chance(20);
     load_a_chat( 
          "Morgoth's guard slashes you visciously !!\n");
     load_a_chat(
          "Morgoth's guard methodically destroys his opponents !\n");
  }
}
