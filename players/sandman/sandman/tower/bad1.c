reset (arg)
{
   if (!arg)
       set_light(1);
   extra_reset();
}

extra_reset()
{
object bruno, pentacle;
if (!present("bruno")) {

   pentacle = clone_object("obj/treasure");
   call_other(pentacle, "set_id", "pentacle");
   call_other(pentacle, "set_alias", "pentacle");
   call_other(pentacle, "set_short", "Pentacle of Mephisto");
   call_other(pentacle, "set_value", 500);
   bruno = clone_object("obj/monster.talk");
   call_other(bruno, "set_name", "bruno");
   call_other(bruno, "set_alias", "hermit");
   call_other(bruno, "set_level", 12);
   call_other(bruno, "set_al", 4000);
   call_other(bruno, "set_short", "Saint Bruno, The Hermit");
   call_other(bruno, "set_wc", 5);
   call_other(bruno, "set_ac", 11);
   call_other(bruno, "set_hp", 180);
   call_other(bruno, "set_aggressive", 0);
   call_other(bruno, "set_chance", 75);
   call_other(bruno, "set_spell_mess1",
             "You are overcome by righteous might!");
   call_other(bruno, "set_spell_mess2",
             "You are slamed by the power of the Lord!");
   call_other(bruno, "set_spell_dam", 20);
   move_object(bruno, this_object());
   move_object(pentacle, bruno);
}
}
init()
{
   add_action("northeast");   add_verb("northeast");
   add_action("west");        add_verb("west");
}
northeast()
{
   call_other(this_player(), "move_player", 
             "northeast#players/sandman/tower/entrance");
   return 1;
}
west()
{
   call_other(this_player(), "move_player",
             "west#players/sandman/tower/bad2");
   return 1;
}
long()
{
   write("You find yourself at the entrace to heaven. Before you stands\n");
   write("Bruno the Hermit enemy of all that is evil. He glows with the\n");
   write("favor of the Lord.\n");
   write("obvious exits are west, northeast\n");
}
short() {
   return "Heaven";
}
