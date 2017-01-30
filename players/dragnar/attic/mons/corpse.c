/*
    Changelog:
	(Bal) set_al changed from -1000
	(Bal) .2 chance set_aggressive added
 */
inherit "obj/monster";

void
reset(int arg) {
   object shroud, bag;

   ::reset(arg);
   if (arg) return;
   set_name("man");
   set_race("human");   /* ? */
   set_short("Dead man awakened from the grave");
   set_long(
"A corpse buried here recently.  Looks like he died a terrible death.\n" +
"You feel like killing him to get away from the sight of him.\n");
   set_level(20);
   set_hp(450 + random(100));
   set_al(100 - random(600));
   set_wc(30);
   set_ac(17);
   set_aggressive(random(2));
   set_chance(35);
   set_spell_dam(30);
   set_spell_mess1("The corpse throws some of his rotten flesh.\n");
   set_spell_mess2("The corpse throws some of his rotten flesh at you!\n" +
		   "The worms eat at your face!\n");
   set_chat_chance(5);
   load_chat("The corpse moans: Why do you take me from my rest?\n");

   shroud = clone_object("/players/dragnar/armor/shroud");
   bag = clone_object("/players/dragnar/items/bag");
   move_object(shroud, this_object());
   move_object(bag, this_object());
}

init() {
  add_action("stop_move","north");
  add_action("stop_move","south");
  add_action("stop_move","west");
  add_action("stop_move","east");
  add_action("stop_move","northwest");
  add_action("stop_move","northeast");
  add_action("stop_move","southwest");
  add_action("stop_move","southeast");
  }

stop_move() {
  if(this_player()->is_npc()) return 0;
  if(this_player()->query_ghost()) return 0;
  write("The corpse grabs you and throws you on the ground!\n");
  if(!query_attack()) attack_object(this_player());
  this_player()->hit_player(random(30)+10);
  return 1; }
