inherit "room/room";
status rock_is_lifted;
object rock;

reset(arg)
{
  if (arg) return;
  set_light(1);
  short_desc = "Strawberry Fields\n";
  long_desc = "Strawberry Fields forever....\n"+
              "\n"+
              "A large rock is sitting on the side of the path.\n";
  rock = clone_object("players/morgoth/OBJ/rock");
  move_object(rock, this_object());
  dest_dir = 
  ({
      "players/morgoth/CASTLE/field15", "north",
    "players/morgoth/CASTLE/field12", "east"
  });
}

init()
{
  add_action("lift_rock", "lift");
  ::init();
}


/*  quest changed by Eurale  4/10/97
lift_rock(str)
{
  if(str == "rock")
  {
   if(!rock_is_lifted)
   {
    object ob;
      write("You found a magic ruby !!\n");
   ob = clone_object("players/morgoth/OBJ/magic_ruby");
  move_object(ob, this_player());
      rock_is_lifted = 1;
      return 1;
    }
   }
}
*/
lift_rock(str) {
if(!str) { write("Lift what?\n"); return 1; }
if(str == "rock") {
  write("You lift the heavy rock and find slugs underneath.\n");
  return 1; }
}
