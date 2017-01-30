/* Created <5/11/00> by Jara */

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

object ob;

  ob = clone_object("/players/jara/area1/docks/obj/collar.c");
    move_object(ob,this_object());

  set_name("cat");
  set_short("A stray cat");
  set_race("cat");
  set_long("The small, grey cat has a thick coat of fur and a long wiry\n"+
        "tail. He has deep-set green eyes and white whiskers.\n");
  set_level(4);
  set_ac(4);
  set_wc(8);
  set_hp(60);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(15);
  set_a_chat_chance(10);
  load_chat("The stray cat slips between your feet.\n");
  load_chat("The cat eyes you...\n");
  load_chat("The cat meows softly.\n");
  load_a_chat("The cat scratches you deeply.\n");
  load_a_chat("The stray cat hisses angrily.\n");
  load_a_chat("The cat narrows his eyes.\n");
  call_out("random_move",20+random(20));
  }
}

random_move() {
  ::random_move();
  call_out("random_move",3);
}
