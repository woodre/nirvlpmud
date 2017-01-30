
inherit "room/room";
object keivjam, virus1, virus2, virus3;

reset(arg) {
  if(!arg) {

    set_light(1);
    short_desc = "Virtual Reality";
    long_desc = "You have entered an area in the virtual world of elof.\n"+
             "Here you hope to find Keivjam.  When you do, KILL HIM\n"+
             "Not that it'll be easy, but if you don't the mud shall\n"+
             "lag to an unspeakable level.\n";

    dest_dir = ( {
            "players/lew/elof/vir_wrld2", "north",
            "players/lew/elof/vir_wrld6", "east",
              } );

          keivjam=clone_object("players/lew/elof/keivjam");
          virus1=clone_object("players/lew/elof/virus");
          virus2=clone_object("players/lew/elof/virus1");
          virus3=clone_object("players/lew/elof/virus2");
          move_object(keivjam, "players/lew/elof/vir_wrld25");
          move_object(virus1, "players/lew/elof/vir_wrld13");
          move_object(virus2, "players/lew/elof/vir_wrld22");
          move_object(virus3, "players/lew/elof/vir_wrld1");
/* Rumplemintz
          return 1;
*/
    }
}
realm(){ return "NT"; }
