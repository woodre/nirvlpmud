reset (arg)
{
   if (!arg)
       set_light(1);
   extra_reset();
}

extra_reset()
{
object chimera, fleece;
if(!present("chimera"))  {

   fleece = clone_object("obj/treasure");
   call_other(fleece, "set_id", "fleece");
   call_other(fleece, "set_alias", "chimera's fleece");
   call_other(fleece, "set_short", "Chimera's Fleece");
   call_other(fleece, "set_value", 1000);
   chimera = clone_object("obj/monster.talk");
   call_other(chimera, "set_name", "chimera");
   call_other(chimera, "set_alias", "dragon");
   call_other(chimera, "set_level", 18);
   call_other(chimera, "set_hp", 700);
   call_other(chimera, "set_al", 0);
   call_other(chimera, "set_short", "The mythical Chimera");
   call_other(chimera, "set_wc", 19);
   call_other(chimera, "set_ac", 13);
   call_other(chimera, "set_aggressive", 1);
   call_other(chimera, "set_chance", 50);
   call_other(chimera, "set_spell_mess1",
       "You are bathed in fire");
   call_other(chimera, "set_spell_mess2",
       "You are burnt badly!");
   call_other(chimera, "set_spell_dam", 30);
   move_object(chimera, this_object());
   move_object(fleece, chimera);
}
}
init()
{
   add_action("east","east");
   add_action("trump","trump");
   add_action("sneak","sneak");
   add_action("escape","escape");
   add_action("use","use");
   add_action("calm","calm");
   add_action("calm","charm");
   add_action("drink","drink");
   add_action("drop","drop");
}
drink() {
    write("You are too busy fighting to drink.\n");
    return 1;
}

east()
{
   if (present("chimera")) {
      write("The chimera bars your way.\n");
      return 1;
   }
   call_other(this_player(), "move_player", 
             "east#players/sandman/tower/swdroom2");
   return 1;
}
trump()
{
   write("a force binds you to this plane!");
   return 1;
}
use()
{
   write("a force binds you to this plane!");
   return 1;
}
calm() {
   write("The chimera shakes off your spell!\n");
   return 1;
}
sneak()
{
   write("You can't sneak here!\n");
   return 1;
}

escape()
{
   write("There is no escape!\n");
   return 1;
}
drop()
{
    write("you can't drop shit in here. I have to clean this place.\n");
    return 1;
}
long()
{
   write("This is the foyer to the Vault of the Sword.\n");
   write("The blood sword can be seen to the east in the next room.\n");
   write("It's yours for the taking. Ohhh, did i mention the chimera?\n");
}
short()  {
   return "ante-chamber";
}
