inherit "room/room";
object money, rat;

reset(arg)
{
  if (arg) return;
  set_light(1);
  money = clone_object("obj/money");
  rat = clone_object("players/morgoth/MONSTERS/rat");
  money -> set_money(random(200));
  move_object(money, rat);
  short_desc = "The Tower of Fire\n";
  long_desc = "The base of the Tower of Fire.\n"+
              "There is a acrid smell in the air reminiscent\n"+
              "of the smell of burning oil... It seems to be\n"+
              "coming from the upper floor of the tower....\n";
  move_object(rat, this_object());
  dest_dir = 
  ({
      "players/morgoth/CASTLE/courtyard9", "northwest"
  });
}
