inherit "room/room";
object h, h1, h2;
int flag = 0;

reset(arg) {
  if(arg) return;
    h = clone_object ("players/beren/Monsters/Olgyo/piai.c");
    move_object (h, this_object());
    h1 = clone_object ("players/beren/Monsters/Olgyo/carmic.c");
    move_object (h1, this_object ());
    h2 = clone_object ("players/beren/Monsters/Olgyo/nameless.c");
    move_object (h2, this_object ());
    if (arg) return;

    set_light(1);
    short_desc = "A small hut";
    long_desc =
"You've just entered the small hut. You can see three Olgyos here and you\n"+
"can be sure - they won't let you out with all your money!\n";
    dest_dir = ({"players/beren/Rooms/Olgyo/oroom4", "west"});
}

init ()
{
    ::init ();
    add_action ("winning", "pay");
    add_action ("my_west", "west");
}

my_west (str)
{
   if (present ("piai") || present ("carmic") || present ("nameless")) {
         write ("You can't get out when Olgyos are still alive!\n");
      return 1;
   }
}

winning (str) {
	if (flag == 1) return 0;
	write ("Piai says: He paid me!!!\n");
	write ("Carmic says: Nope! He paid me!!!\n");
write ("Nameless says: Get your dirty hands off my money!\n");
write ("Olgyos started to hit each other!\n");
write ("At last they decided to kill you first.\n");
write ("But they look weaker!\n");
if (present ("piai")) h -> hit_player (200 + random (200));
	if (present ("carmic")) h1 -> hit_player (200 + random (200));
	if (present ("nameless")) h2 -> hit_player (200 + random (200));
	flag = 1;
       return 1;
}
