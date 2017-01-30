reset (arg)
{
   if (!arg)
       set_light(1);
   extra_reset();
}

extra_reset()
{
object mephisto, cross;
if (!present("mephisto")) {

   cross = clone_object("obj/treasure");
   call_other(cross, "set_id", "cross");
   call_other(cross, "set_alias", "cross");
   call_other(cross, "set_short", "Cross of Saint Bruno");
   call_other(cross, "set_value", 500);
   mephisto = clone_object("obj/monster.talk");
   call_other(mephisto, "set_name", "mephisto");
   call_other(mephisto, "set_alias", "deceiver");
   call_other(mephisto, "set_level", 12);
   call_other(mephisto, "set_al", -4000);
   call_other(mephisto, "set_short", "Mephisto, The Deceiver");
   call_other(mephisto, "set_wc", 5);
   call_other(mephisto, "set_ac", 11);
   call_other(mephisto, "set_hp", 180);
   call_other(mephisto, "set_aggressive", 1);
   call_other(mephisto, "set_chance", 75);
   call_other(mephisto, "set_spell_mess1",
             "You are struck by phantasmal fire!");
   call_other(mephisto, "set_spell_mess2",
             "You are blasted by pure evil!");
   call_other(mephisto, "set_spell_dam", 20);
   move_object(mephisto, this_object());
   move_object(cross, mephisto);
}
}
init()
{
   add_action("southeast","southeast");
   add_action("west","west");
}
southeast()
{
   call_other(this_player(), "move_player", 
             "southeast#players/sandman/tower/entrance");
  return 1;
}
west()
{
   call_other(this_player(), "move_player",
             "west#players/sandman/tower/good2");
   return 1;
}
long()
{
   write("You have entered into the bowels of hell itself!\n");
   write("Before you stands its lord and master, Mephisto the Deceiver!\n");
   write("and he hates goody two shoes like you.\n");
   write("obvious exits are west, southeast.\n");
}
short() {
   return "Hell";
}
