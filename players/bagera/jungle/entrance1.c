/* Added an exit, [5.24.01] - Vertebraker */
inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("The Jungle Book");
  long_desc=
     "Bagera's Jungle is closed for reconstruction.  Check back soon.\n";
 dest_dir=
({
      "/room/forest4.c", "exit",
});
}
