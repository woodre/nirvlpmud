inherit "room/room";

reset(arg){
    if(arg) return;
set_light(1);
set_short(BOLD+GRN+"Shamot village"+NORM);
set_long(
"  To the northwest a large shop can be seen.  Behind the shop a large\n"+
"tree grows.  From the chimney of the shop smoke billows out at regular\n"+
"intervals.  In the front of the store barrels of some liquid stand on\n"+
"each side of the door.  Hanging above the door is a small wooden sign.\n");

items = ({
	"tree",
	"An ancient tree that has been here since the first elf arrived",
	"shop",
        "A decent sized building providing wares for travellers through Shamot",
        "chimney",
        "The stone chimney has been overgrown with vines but still puffs out a lot of smoke",
        "smoke",
        "The dark smoke puffs out at regular intervals from the chimney",
        "barrels",
        "The barrels stand like sentinals in front of the shop",
        "barrel",
        "One of the barrels has a small spigot on the bottom of it",
        "spigot",
        "A small metal spigot for releasing the liquid from the barrel",
        "door",
        "The door stands open allowing all looking for wares to enter",
        "sign",
        "The sign has an engraved shield with two swords crossing over it"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/village1.c","east",
	"/players/catacomb/MF/rooms/village3.c","northwest"
	});
}
}
init(){
  ::init();
      add_action("metalwork","listen");
      add_action("smelling","smell");  
  }

metalwork()
{
   	write("Sounds of a hammer hitting an anvil can be heard inside the shop.\n");
  	return 1;
}

smelling()
{
        write("The smell of metal burning is everywhere.\n");
        return 1;
}