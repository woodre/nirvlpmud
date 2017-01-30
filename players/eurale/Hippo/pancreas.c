inherit "room/room";

reset(arg){
  if(arg) return;
set_light(0);

short_desc = "The pancreas";
long_desc =
  "  This large, elongated gland is situated behind the stomach and secretes a\n"+
  "digestive juice into the small intestine.  Groups of differentiated cells\n"+
  "in the gland produce the hormone insulin.\n";

items = ({
  "juice","Yellow and waxy looking",
  "cells","They look to be langerhans",
});

dest_dir = ({
  "/players/eurale/Hippo/liver.c","back",
  "/players/eurale/Hippo/langerhans","langerhans",
});

}
