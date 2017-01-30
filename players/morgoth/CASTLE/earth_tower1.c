inherit "room/room";
object rat, money, awl;

reset(arg)
{
  if (arg) return;
  set_light(1);
  rat = clone_object("players/morgoth/MONSTERS/rat");
  awl = clone_object("players/morgoth/OBJ/awl");
  money = clone_object("obj/money");
  money -> set_money(random(100));
  move_object(awl, rat);
  move_object(money, rat);
  move_object(rat, this_object());
  short_desc = "The Tower of Earth\n";
  long_desc = "The base of the Tower of Earth.\n"+
              "A narrow staircase hugs the outer wall...\n";
  dest_dir = 
  ({
      "players/morgoth/CASTLE/earth_tower2", "up",
      "players/morgoth/CASTLE/courtyard7", "northeast"
  });
}
