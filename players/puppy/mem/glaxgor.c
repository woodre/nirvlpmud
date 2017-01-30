inherit "/room/room";

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  set_short("A sullen memorial");
  set_long("\
This is a Memorial to remember Glaxgor's father.\n\
Please pay your respects because he was a loving\n\
father, devoted husband, and someone who found the\n\
Lord very early in his life. I hope all will remember\n\
what he has done for Glaxgor and the rest of his family.\n\
Please type \"lay rose\" and observe a moment of silence\n\
to offer your condolences to Glaxgor and his family.\n");
  if(!present("grave")) {
    move_object(clone_object("/players/puppy/mem/gravestone"), this_object());
  }
  dest_dir = ({
    "/players/puppy/mem/2", "north",
  });
}

int no_light_damage() { return 1; }

void init()
{
  ::init();
  add_action("cmd_lay", "lay");
}

int cmd_lay(string str) {
  string *files;
  if(str != "rose" && str != "rose down" && str != "a rose" && str != "a rose down") {
    notify_fail("You may only \"lay a rose\" down.\n");
    return 0;
  }
  files=({
    "/players/traff/misc/redrose",
    "/players/traff/misc/yellowrose",
  });
  write("You rest a single beautiful rose blossom on\n"+
         "the grave of Glaxgor's father.\n");
  write("Thank you for your condolences.\n");
  say((string)this_player()->query_name() +
    " bows "+possessive(this_player())+
    " head down in silence and tosses a single rose "+
     "blossom on the grave of Glaxgor's father.\n");
  move_object(clone_object(files[random(sizeof(files))]), this_object());
  return 1;
}
