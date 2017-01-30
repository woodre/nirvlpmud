inherit "room/room";
object tingler, money, thingy;
 
reset(arg)
{
    if (arg) return;
    set_light(1);
    short_desc = "An asteroid";
    long_desc = "This asteroid is located 2,000,000 light years away from Nirvana !\n";
               
if(!present("tingler")) {
move_object(clone_object("players/morgoth/MONSTERS/Etingler.c"),
  this_object()); }

dest_dir = 
({
    "players/morgoth/CASTLE/asteroid2", "south",
});
}

realm(){return "NT";}

query_temp() { return 1; }
