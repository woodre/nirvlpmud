#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
object owner;

reset(arg) {
	if(!present("knight_book")){
      owner = clone_object("/players/guilds/warriors/OBJ/trainer_knight");
      move_object(owner, this_object());
	}
  if(arg) return;
set_light(1);

short_desc = "Top of the tower";
long_desc =
"The roof of the tower of the gates.\n"+
"There is a beautiful view of the forests and mountains from here.\n" +
"Stairs lead back into the tower.\n";

items = ({
"view",
"You see a spectacular view of the plains and mountains",
});

dest_dir = ({
  "/players/morgar/tower3","down",
});

}


