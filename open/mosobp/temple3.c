inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = "A Temple Foyer";
long_desc = "This is the entrance to the Namekian Temple, and for many\n;
years this temple has been a constand and vigil place for its community\n;
to come worship. This temple is a quiet, serenge,place of forgiveness.  \n;
This room is lighted by a giant chandelier in the middle of the room.  Around\n;
the room many tapestries and ancient rugs are hung on the walls.\n;
set_light(1);

dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/temple8.c","north",
"/players/mosobp/areas/TEMPLE/rooms/temple4.c","east",
"/players/mosobp/areas/TEMPLE/rooms/temple2.c","west",
});
}
