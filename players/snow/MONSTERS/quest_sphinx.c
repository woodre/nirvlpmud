inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(6000) + 4000);
  move_object(gold,this_object());
 
     set_name("sphinx");
     set_short("dark shadows");
     set_race("sphinx");
     set_alias("shadows");
     set_long("As you peer closely at the shadows, they seem to coalesce into \n"+
  "a huge form that peers down at you with eyes exuding an aura of ancient \n"+
  "wisdom. You realize that this must be a fabled shadow sphinx- most \n"+
  "powerful of the race of sphinxes. It appears non-threatening though. \n"+
  "Perhaps it will impart to you some of its great wisdom if you but wait.\n");
     set_level(30);
     set_ac(40);
     set_wc(50);
     set_hp(2000);
     set_heal(10,1);
     set_al(0);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(5);
     load_chat("The shadow sphinx whispers: This realm is for the powerful \n"+
                      "only. If you come without heals or a party, you will die.\n");
     load_chat("The shadow sphinx whispers: The giant crab lies to the north,\n"+
                      "the dark demon lies to the east, and the ogre magus abides to \n"+
                      "the west \n");
     load_a_chat("The shadow sphinx roars: You fool! I am like unto a god \n"+
                          "when compared to you!\n");
     load_a_chat("The shadows darken the room.\n");
   }
}
