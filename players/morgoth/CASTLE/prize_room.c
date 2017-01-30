inherit "room/room";
object ob1, ob2, ob3, ob4;

reset(arg)
{
  if(!present("gem")) move_object(clone_object("/players/morgoth/OBJ/huntgem.c"),this_object());
    if (arg) return;
    set_light(1);
    short_desc = "Morgoth's Prize Room";
    long_desc = ">>>>>>  MORGOTH'S PRIZE ROOM  <<<<<<\n"+
    "\n"+
    "Find the four 'missing' items.  Return them to this room.\n"+
    "The four items are 'hidden'.  Search carefully.  If you \n"+
    "find them you will be rewarded with a cash prize and a solved\n"+
    "quest.  Type 'claim prize' to win.\n";

dest_dir = 
({
    "players/morgoth/CASTLE/vil_road_1", "north",
});
}

init()
{
    ::init();
    add_action("claim_prize", "claim");
}

claim_prize(str)
{
    if (str == "prize")
    {
    if (present("magic ruby", this_player()) && present("cyclops mace", this_player()) && present("jade_quest_figurine", this_player()) && present("klezmeer sword", this_player()))
      {
      ob1 = present("magic ruby", this_player());
      ob2 = present("cyclops mace", this_player());
      ob3 = present("jade_quest_figurine", this_player());
      ob4 = present("klezmeer sword", this_player());
      write("You found all the items !!\n");
        write("You win a prize !!!\n");
        call_other(this_player(), "add_money", 5000);
    call_other(this_player(), "set_quest", "cyclops_mace");
        destruct(ob1);
        destruct(ob2);
      destruct(ob3);
      destruct(ob4);
        return 1;
      }
     write("You have not found all the items !\n");
     return 1;
     }
return 1;
}
