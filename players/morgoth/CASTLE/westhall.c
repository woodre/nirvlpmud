inherit "room/room";
object net_monster, money;

reset(arg)
{
  if (arg) return;
  set_light(1);
  short_desc = "The NET monster room\n";
  long_desc = "A hideous vax-like creature is in one corner of this room.\n"+
              "The creature is covered with a mass of twisted,\n"+
              "tangled cable and wires.  The wire tendrils cover\n"+
              "the walls, ceiling and floor.  The room is the creature\n"+
              "and the creature is the room.  The creature's wires reach\n"+
              "out to you and cover your body.  They reach into\n"+
              "your mind.  The creature is your mind and your mind is\n"+
              "the creature.....its thoughts are your thoughts......\n"+
              "its only thought........is KILL.................\n";
  net_monster = clone_object("players/morgoth/MONSTERS/net_monster");
  money = clone_object("obj/money");
  money->set_money(5000+random(3000));
  move_object(money, net_monster);
  move_object(net_monster, this_object());
  dest_dir = 
  ({
    "players/morgoth/CASTLE/courtyard4", "east"
  });
}
