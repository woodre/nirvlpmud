inherit "room/room";
object rat, money;

reset(arg)
{
  if (arg) return;
  set_light(1);
  rat = clone_object("players/morgoth/MONSTERS/rat");
  money = clone_object("obj/money");
  money->set_money(random(100));
  move_object(money, rat);
  move_object(rat, this_object());
  short_desc = "A large courtyard\n";
  long_desc = "The southwest corner of the courtyard.\n";
  dest_dir = 
  ({
      "players/morgoth/CASTLE/courtyard4", "north",
      "players/morgoth/CASTLE/courtyard8", "east",
      "players/morgoth/CASTLE/earth_tower1", "southwest"
  });
}
