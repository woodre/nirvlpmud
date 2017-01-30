inherit "room/room";
object bird, flowers, money;
int i;

reset(arg)
{
  if (arg) return;
  set_light(1);
  i = 0;
  if(!bird || !living(bird))
  {
    while(i<2)
    {
  i += 1;
      bird = clone_object("players/morgoth/MONSTERS/bird");
      money = clone_object("obj/money");
      money->set_money(50);
      move_object(money, bird);
      move_object(bird, this_object());
      }
  flowers = clone_object("players/morgoth/OBJ/flowers");
  move_object(flowers, this_object());
    }
  short_desc = "A garden path";
  long_desc = "The garden path continues...\n";
  dest_dir = 
  ({
      "players/morgoth/CASTLE/Egarden_path2", "west",
  });
}

query_temp() { return 1; }
