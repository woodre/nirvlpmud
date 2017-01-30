inherit "room/room";

object mage, weap;

reset(arg)
{
   if(!mage || !living(mage))
   {
      mage = clone_object("obj/monster.c");
      call_other(mage, "set_name", "necromancer");
      call_other(mage, "set_alias", "mage");
      call_other(mage, "set_level",19);
      call_other(mage, "set_al", -300);
      call_other(mage, "set_short", "A black robed necromancer");
      call_other(mage, "set_wc",15);
      call_other(mage, "set_ac",2);
      call_other(mage, "set_aggressive", 1);
      call_other(mage, "set_move_at_reset");
      call_other(mage, "set_ep",250000);
      call_other(mage, "set_chance",25);
      call_other(mage, "set_spell_mess2",
                 "You are hit by a fire ball.");
      call_other(mage, "set_spell_dam",30);
      weap  = clone_object("obj/weapon");
      call_other(weap, "set_name", "firesword");
      call_other(weap, "set_short", "A firesword");
      call_other(weap, "set_class",15);
      call_other(weap, "set_weight",2);
      call_other(weap, "set_value",10000);
      move_object(weap, mage);
      move_object(mage, this_object());
   }
   if(arg)
      return;
   short_desc = "South of Altar";
   long_desc = "You are just south of the altar of the Temple of Bishamon.  You\n" +
                      "are confronted by Akari, the devils Mage.  He protects the altar from\n" +
                      "Avatars like yourself from discovering its powers.  He will stop at nothing\n" +
                      "to protect Benju's interests.  Beware of his great powers!!\n\n";
   set_light(1);
   dest_dir = ({ "players/paulasx/temple/temple_center", "south",
/*
                 "players/paulasx/temple/temple_nw", "west",
                 "players/paulasx/temple/temple_ne", "east",
*/  
                      "players/paulasx/temple/temple_altar", "north", });
}
init() {
  ::init();
  add_action("north","north");}

north() {
    if(present("mage",this_object())) {
        write("The mage bars the way.\n");
        return 1;
   }
    call_other(this_player(), "move_player", "north#players/paulasx/temple/temple_altar");
    return 1;
}

