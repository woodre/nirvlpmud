inherit "room/room";

reset(arg)
{
   if(arg)
      return;
   short_desc = "Entrance into the Temple of Bishamon";
  long_desc = "You are at the entrance to the Temple of Bishamon.  The temple\n" +
              "was once a holy place, but is under the control of Benju Matsutomo\n" +
              "the Arch Lord to Satan.  Somewhere though, you feel some goodness within\n" +
      "the temple.  You feel inclined to seek out the goodness, and fight for\n" +
          "it's causes.  But, beware of the dogs of hell, they watch over the place!\n";
   set_light(1);
   dest_dir =
   ({
       "players/paulasx/temple/temple1", "north",
       "room/orc_dump", "exit",
    });
}

