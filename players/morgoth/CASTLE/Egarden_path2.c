inherit "room/room";
object bird, money;
int i;
status ruby_there;

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
  short_desc = "A garden path\n";
  long_desc = "The garden path is lined with meticuously trimmed hedges.\n"+
              "Flowers grow in well cared for beds.\n"+
              "The air is filled with the sweet smell of Spring.\n"+
              "Birds sing their praises from branches high and low.\n";
move_object(clone_object("players/morgoth/OBJ/rock.c"),this_object());
  dest_dir = 
  ({
      "players/morgoth/CASTLE/garden_path1", "north",
      "players/morgoth/CASTLE/garden_path3", "east"
  });
}

init() {
  ::init();
  add_action("roll","roll");
}

roll(str) {
if(present("bird")) {
  write("The little bird flies close by and distracts you.\n"); return 1; }
if(!str) { write("Roll what?\n"); return 1; }
if(str == "rock" && !ruby_there) {
  write("You heave with all your might and roll the heavy rock\n"+
	"just far enough to find a magic ruby.\n");
  move_object(clone_object("players/morgoth/OBJ/magic_ruby.c"),
	this_player());
  ruby_there = 1;
  return 1; }
else {
  write("You roll the big rock a little ways and find slugs and\n"+
	"earthworms underneath.\n");
  return 1; }
}

query_temp() { return 2; }
