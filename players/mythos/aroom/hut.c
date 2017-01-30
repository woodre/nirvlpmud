inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = "Hut";
    long_desc =
    "You enter a small dimly lit hut.  Some children are up playing some games.\n"+
    "In the corner you see a small boy, an old woman and a cat all asleep- dreaming.\n"+
    "You could enter their dreams and perhaps conquer the Dream Master.  Be careful.\n";
  items = ({
    "boy","The boy is asleep.  Maybe you should to take a 'glimpse' of his dreams",
    "woman","The old woman is asleep.  Maybe you should 'peek' into her dreams",
    "cat","The cat is asleep.  Maybe you should 'peer' into its dreams",
    "children","The children are having fun.  Maybe you should 'join' them",
    "saber","This leads to the dream world of Saber's mind",
  });

  dest_dir = ({
    "/players/mythos/aroom/phut.c","out",
    "/players/mythos/aroom/boy1.c","boy",
    "/players/mythos/aroom/woman1.c","woman",
    "/players/mythos/aroom/cat1.c","cat",
    "/players/saber/tower/dream21.c","saber",
  });
}}

  init() {
    ::init();
    add_action("glimpse_boy","glimpse"); 
    add_action("peek_woman","peek");
    add_action("peer_cat","peer");
    add_action("join","join");
  }
    glimpse_boy() {
    object boy;
      write("The boy is having a nightmare about mystical Japanese monsters.\n");
      write("Why don't you try to help him by destroying the nightmares- enter his dream.\n");
    return 1; }

    join() {
    object children;
      if(present("timer")) {
        write("The children are occupied right now- you could 'join' them later.\n");
      return 1;
      }
      if(!present("timer")) {
      write("When you join the children you realize something is wrong!\n");
      write("The children are not children- they are foxes with illusions on them!\n");
      say("A mist develops and the when it clears- the children are gone! In\n");
      say("their place are foxes!\n");
        move_object(clone_object("/players/mythos/amon/fox2.c"),this_object());
        move_object(clone_object("/players/mythos/amon/fox2.c"),this_object());
        move_object(clone_object("/players/mythos/amon/fox.c"),this_object());
        move_object(clone_object("/players/mythos/amon/fox.c"),this_object());
        move_object(clone_object("/players/mythos/amon/Bfox.c"),this_object());
        move_object(clone_object("/players/mythos/amisc/timer3.c"),this_object());
      return 1;
}}

    peek_woman() {
    object woman;
      write("She is sleeping.  It seems to you that she is dreaming of something\n"+
      "that occured in her past.  Becareful...its a very difficult place.  \n");
    return 1;  }

    peer_cat() {
    object cat;
      write("It sleeps.  As you peer into its dream you see that it dreams of a more dangerous life.\n"+
    "If you are feeling brave- go ahead and enter the cat's mind.  Remember, bring light.\n");
    return 1;  }
