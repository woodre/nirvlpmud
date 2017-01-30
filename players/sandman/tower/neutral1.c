reset (arg)
{
   if (!arg)
     set_light(1);
   extra_reset();
}

extra_reset()
{
object entropy, medalion;

if (!present("entropy")) {
   medalion = clone_object("obj/treasure");
   call_other(medalion, "set_id", "medalion of balance");
   call_other(medalion, "set_alias", "medalion");
   call_other(medalion, "set_short", "A medalion emblazened with a Scale");
   call_other(medalion, "set_value", 350);
   entropy = clone_object("obj/monster.talk");
   call_other(entropy, "set_name", "lord of entropy");
   call_other(entropy, "set_alias", "entropy");
   call_other(entropy, "set_level", 7);
   call_other(entropy, "set_al", 0);
   call_other(entropy, "set_short", "A Lord of Entropy");
   call_other(entropy, "set_wc", 11);
   call_other(entropy, "set_ac", 3);
   call_other(entropy, "set_aggressive", 1);
   call_other(entropy, "set_chance", 30);
   call_other(entropy, "set_spell_mess1",
       "You decay!!!!");
   call_other(entropy, "set_spell_mess2", 
       "Entropy increases");
   call_other(entropy, "set_spell_dam", 10);
   move_object(entropy, this_object());
   move_object(medalion, entropy);
}
}
init()
{
   add_action("west","west");
   add_action("east","east");
}
west()
{
   call_other(this_player(), "move_player",
       "west#players/sandman/tower/neutral2");
}
east()
{
   call_other(this_player(), "move_player",
       "east#players/sandman/tower/entrance");
}
long()
{
    write("You stand in a room devoid of all substance. In the center of\n");
   write("this emptyness stands A Lord of Entropy. You can flee to the\n");
   write("east or continue on to the west.\n");
}
short()
{
   return "Null Dimension";
}
 

