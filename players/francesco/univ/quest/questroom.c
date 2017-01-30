#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;



set_light(1);

short_desc = "Francesco's quest room" ;
long_desc =
     "    This small room is very quiet and allows for a great\n"+
     "concentration.  The desk you see here is almost empty but\n"+
     "for a pencil, a notebook and a small calculator.  The chair\n"+
     "behind the desk is very comfortable.\n",

items = ({
     "calculator","Hand held calculator, useful for making simple additions and multiplications",
     "desk","An ample office desk, with some papers and a picture of a boy over it",
     "pencil","Sharp pencil with eraser",
     "notebook","Made by several pages of graph paper",
     "chair","Leather business chair",
});

dest_dir = ({
  "/players/francesco/workroom.c","back",
});

}
