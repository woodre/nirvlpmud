inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
 gold = clone_object("obj/money");
  gold->set_money(random(25));
  move_object(gold,this_object());
  ob2 = clone_object("/players/saber/armor/ljacket.c");
move_object(ob2,this_object());
 ob3 = clone_object("/players/saber/weapons/bknuckles.c");
move_object(ob3,this_object());
     set_name("thug");
     set_short("A young thug");
     set_race( "human");
     set_long("A tough young thug.\n");
     set_gender("male");
     set_level(3);
     set_ac(4);
     set_wc(7);
     set_hp(45);
     set_al(-500);
     set_aggressive(0);
     set_chat_chance(15);
     load_chat("The young thug rattles the machine.\n");
     load_chat("The young thug looks at you.\n");
     load_chat("The young thug says: Hay buddy, spare a silver coin?\n");
     load_chat("The young thug tries to look important.\n");
     load_chat("You hear faint music in the background.\n");
     load_chat("You hear faint techno music in the background.\n");
     load_a_chat("You hear faint music in the background.\n");
     load_a_chat("The young thug screams: You're dead meat!\n");
     load_a_chat("The young thug punches you in the face.\n");
     load_a_chat("The young thug looks around for a way to run.\n");
     set_a_chat_chance(15);
   }
}
