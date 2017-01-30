inherit "room/room";
object bird, money;
int i;

reset(arg)
{
  if (arg) return;
  set_light(1);
  i = 0;
  if(!bird || !living(bird))
  {
    while(i<3)
    {
  i += 1;
      bird = clone_object("players/morgoth/MONSTERS/bird");
      money = clone_object("obj/money");
      money->set_money(50);
      move_object(money, bird);
      move_object(bird, this_object());
      }
    }
  short_desc = "A garden path";
  long_desc = "The garden path winds to the south.\n"+
              "It is lined with meticuously trimmed hedges.\n"+
              "Flowers grow in well cared for beds.\n"+
              "The air is filled with the sweet smell of Spring.\n"+
              "Birds sing their praises from branches high and low.\n";
  dest_dir = 
  ({
      "players/morgoth/CASTLE/garden_path1", "north",
      "players/morgoth/CASTLE/garden_path3", "east"
  });
}

query_temp() { return 2; }
