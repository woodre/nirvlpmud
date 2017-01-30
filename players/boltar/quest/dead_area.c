int digcount;
object have_ring;
id(str) { return str == "cave"; }
init() {
      digcount = 0;
       set_light( 1);
      add_action("put","put");
      add_action("south","south");
      add_action("look","look");
      add_action("look","l");
}
 short() { return "cave under the Legion of the dead office."; }
long() {
   write("This room has a faint glow in it coming from a hand on a stone\n");
   write("slab at the far end of the room. This looks like it is a place of\n");
   write("meeting as there are many large stones arranged like seats.\n");
   write("The hand looks like it is made of gold and is giving off some magical\n");
   write("energy.\n");
}
 south() {
  call_other(this_player(), "move_player", "south#players/boltar/quest/combs3.c");
  return 1;
}
put(str) {
     if(!str) {
     return 0;
     }
   if(str == "ring on hand" || str == "ring in hand"){
    str = "ringxxxt";
    have_ring = find_item_in_player(str);
    if (!have_ring) {
   write("You don't have the ring!!!\n");
  return 1;
  }
  destruct(have_ring);
  call_other(this_player(), "set_quest", "ring");
  write ("As you put the ring in the hand the hand closes up and holds the ring\n");
 write ("tight. The hand glows brightly with green light for a second then goes\n");
 write ("out.\n  Good Job! you have completed this quest.\n");
/*
   log_file("boltar.quest", this_player()->query_real_name() + " solved the ring quest.\n");
*/
  return 1;
}
 return 0;
}
find_item_in_player(i)
{
    object ob;

    ob = first_inventory(this_player());
    while(ob) {
        if (call_other(ob, "id", i))
	    return ob;
	ob = next_inventory(ob);
    }
    return 0;
}
look(str) {
   if (!str) {
   return 0;
  }
  if (str == "at hand" || str == "in hand"){
  write("It looks like something is supposed to go here.\n");
   return 1;
  }
return 0;
}
