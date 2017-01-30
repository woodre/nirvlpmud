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
  short_desc = "The Tower of Water\n";
  long_desc = "The base of the Tower of Water.\n"+
              "The stone sides of the tower have been\n"+
              "eroded from centuries of water.  Magnificient\n"+
              "crystal formations hang from the ceiling like spears\n"+
              "aimed at your head.  One can only pray that they\n"+
           "don't come loose and fall perhaps injuring someone !\n"+
              "The sound of rushing, gurgling water can be heard in the\n"+
               "near distance.  A stone spiral stairway leads up to \n"+
               "another level.\n";
  move_object(rat, this_object());
  dest_dir = 
  ({
      "players/morgoth/CASTLE/water_tower2", "up",
      "players/morgoth/CASTLE/courtyard3", "southwest"
  });
}
