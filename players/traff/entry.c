inherit "room/room";
reset(arg) {
if(!arg) {
set_light(1);
short_desc="Castle Entry Hall";

long_desc=
"You are standing in the Entry Hall of a great castle. Before you stands\n"+
"a massive archway with double wooden doors. Near the archway\n"+
"begins a marble stairway that rises and turns out of sight through\n"+
"a smaller archway. Doorways lead to the left and right. In the center\n"+
"of the Hall stands a carved stone figure of a Paladin in full plate mail\n"+
"holding aloft a mighty steel sword. The sword blazes with red holy\n"+
"fire that lights the room.\n";

items=({
"door", "Solid wooden doors stand before you. They are unlocked.\n",
"stairway","This beautiful marble stairway leads to a small archway set midway up the north wall.",
"statue, figure, paladin"," The stone statue is of a mighty Paladin from the days when their numbers\n"+
"were many and they were sworn to protect the land and its people. \n"+
"Only a few of their order now remain.",
"sword, fire"," The sword burns with the holy fire of power and righteousness."
});

dest_dir=({
"/players/arrina/palace/sitting","west",
"/players/arrina/palace/chapel","east",
"/players/arrina/palace/courtyard","north",
"/players/arrina/palace/walkway","up",
});
} }


