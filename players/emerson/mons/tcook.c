inherit "/obj/monster";
int lvl,wcc;

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
   ob2 = clone_object("/players/emerson/weap/pcutter.c");
move_object(ob2,this_object());
   ob3 = clone_object("/players/emerson/armor/mits.c");
   move_object(ob3,this_object());
 gold = clone_object("obj/money");
gold->set_money((4000));
  move_object(gold,this_object());
     set_name("cook");
     set_short("Head Cook");
     set_race( "human");
set_long("This is the Head Cook, you watch as his slices the pizzas\n" +
"with his razor sharp pizza cutter.\n");
     set_level(20);
     set_ac(17);
     set_wc(30);
     set_hp(1000);
     set_al(-750);
     set_aggressive(0);
     set_chat_chance(30);
     set_a_chat_chance(35);
      load_chat("The head cook pushes you out of his way!\n");
      load_chat("The cook yells : What are you doing back here?!\n");
      load_chat("The cook tries to look busy while waiting for the next pizza.\n");
    load_chat("The Head Cook slaps his assistant for messing up an order!\n");
      load_a_chat("The cook cuts you with his sharp pizza cutter!\n");
      load_a_chat("Head Cook screams : Go away! I'm very busy!!\n");
      load_a_chat("Head Cook kicks you between the legs.\n");
   }
}

heart_beat() {
  ::heart_beat();
  combat_heal();
  }

combat_heal() {
  if(!random(5) && query_hp() < 800) {
    tell_room(environment(this_object()),
    "The head cook eats a slice of pizza.\n");
    heal_self(random(20)+15); }
  return; }
