inherit "room/room";
object worktable;

reset(arg)
{
	if(!present("worktable")){
	move_object(clone_object("players/dersharp/stuff/worktable"), this_object());
}
  if(!arg){
	set_light(1);
        short_desc="The new addition";
	long_desc="	You travel south and enter the main workroom of dersharp.\n"+
                  "Before you stands a great window rising the full heigth of the\n"+
                  "workroom.  Along the walls are rows and rows of books.  The \n"+
                  "is also covered with draperies hanging from the ceiling and \n"+
                  "cages containing different sorts of animals.  Right before you\n"+
                  "is Dersharp's worktable and chair.\n";
	dest_dir =
                  ({ });
	items= ({
                 "window","This window covers the entire southern wall.  Outside\n"+
                          "you see lightning arcing through the night-sky as it\n"+
                          "is always night here.",
                 "books","These are Dersharp's pride and joy, he has spent days in\n"+
                         "other worlds with the help of books and holds them in high\n"+
                         "regards.",
	       });
	}
}
init() {
	add_action("north","north");
        add_action("nifty","private");
}
north() {
	move_object(this_player(),"players/dersharp/workroom");
        command("look",this_player());
	return 1;
}
nifty() {
	move_object(this_player(), "players/dersharp/rooms/pad/dining");
        command("look",this_player());
	return 1;
}
