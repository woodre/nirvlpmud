inherit "room/room";
object flute, monster, money, fountain, sword;
status flute_is_got, flute_is_played;

reset(arg)
{
  if (arg) return;
  set_light(1);
  short_desc = "The Tower of Water\n";
  long_desc = "A large room with a fountain in the center.\n"+
              "The stone walls and ceiling are very damp.\n";
  fountain = clone_object("players/morgoth/OBJ/fountain");
  move_object(fountain, this_object());
  dest_dir = 
  ({
      "players/morgoth/CASTLE/water_tower1", "down"
  });
}

init()
{
  add_action("take_flute", "take");
  add_action("play_flute", "play");
  add_action("drink_fountain", "drink");
  ::init();
}

take_flute(str)
{
  if(str == "flute")
  {
  if(!flute_is_got)
  {
    write("You take the flute from the fountain.\n");
    say(call_other(this_player(), "query_name") + " reaches into the fountain and takes the flute.\n");
    flute = clone_object("players/morgoth/OBJ/magic_flute");
    move_object(flute, this_player());
      flute_is_got = 1;
    return 1;
  }
 }
}

play_flute(str)
{
  if(str == "flute")
  {
   if(flute_is_got)
   {
    if(!flute_is_played)
    {
      write("The music from the flute is enchanting.  Your mind floats with the sound of the flute !\n");
      say(call_other(this_player(), "query_name") + " plays the flute, magic sounds float through the room.\n");
    call_out("summon_monster", 7);
    flute_is_played = 1;
     return 1;
    }
  }
 }
}

summon_monster()
{
      write("The music has summoned Takquel, Guardian of the Blue Sword !!\n");
      say("The music has summoned Takquel, Guardian of the Blue Sword !!\n");
     monster = clone_object("players/morgoth/MONSTERS/takquel");
     sword = clone_object("players/morgoth/WEAPONS/bluesword");
     money = clone_object("obj/money");
     money -> set_money(random(4000));
     move_object(money, monster);
     move_object(sword, monster);
/* This would reduce the monster's weapon class! -Feldegast 10-6-2000
     call_other(monster, "init_command", "wield", sword);
*/
     move_object(monster, this_object());
}

drink_fountain(str)
{
  if(str == "water" || str == "fountain")
  {
    write("The water from the fountain is refreshing, your thirst is quenched.\n");
    say(call_other(this_player(), "query_name") + " drinks from the fountain.\n");
    return 1;
   }
}
