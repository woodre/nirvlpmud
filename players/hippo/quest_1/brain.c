inherit "room/room";
object sign;
object thing;
    object spel;
reset(arg){
  if(arg) return;
if(!present("aqua_dynamica")) {
  move_object(clone_object("/players/hippo/quest_1/hippo.c"),this_object()); }
if(!present("board")) {
thing=clone_object("/players/hippo/quest_1/closed/score_board.c");
move_object(thing,this_object());
}
set_light(0);
short_desc="You are in the brains of the famous Hippo";
long_desc="Hmm.. what should this be?? It looks like a game or something\n"+
    "Maybe it's the best to type 'rules' to see what you are\n"+
    "supposed to do in here.\n"+
    "As a matter of fact, you are already in the right place to play,\n"+
    "although you might not see that right now. Strange, huh?\n"+
    "Well.. maybe that unrecognizable way of thinking is part\n"+
   "of the magnificent Hippo....\n";
dest_dir=
    ({"/players/hippo/quest_1/willosi.c","out",
    "/players/hippo/quest_1/brain.c","start for people with guts.",
   });
}
realm() {return "NT";}
init () {
   ::init();
   add_action ("rules","rules");
   add_action ("start","start");
}
rules () {
   write("Ok, you wanna play this game, huh?? Well... here are the rules:\n"+
    "-----------------------------------------------------------------\n"+
    " There are a lot of rooms, which are all colored. Inside of each\n"+
    "of these rooms, you'll find a colored box. Hmm... not in EACH\n"+
   "room. There are some 'empty' rooms, which can be used to push \n"+
   "a box into. While pushing, you should be able to create a situation\n"+
   "where all colored boxes are located in the same colored rooms.\n"+
   "This sounds easy, huh? Well... it isn't, you'll see. But i'm sure\n"+
    "you can make it. Just keep on trying!\n"+
    "A few more things: If you think you are done, just walk into the\n"+
    "hole, which is located at your right side from where you start.\n"+
    "Don't fall into that hole accidentally, because you'll have to \n"+
    "start all over again in that case.\n"+
    "-----------------------------------------------------------------\n"+
    " right, left, forward, back       ||  move to that specific way\n"+
    " push right, left, forward, back  ||  push that specific way\n"+
    " show                             ||  show location of all boxes\n"+
    " rules                            ||  see this\n"+
    "-----------------------------------------------------------------\n"+
    "To start the game, just type 'start'.\n"+
    "To stop the game, enter the hole.\n"+
    "Good luck, Hippo.\n");
      return 1;
   }
start()
{
    if(!present("scores",this_player()))
    {
    write("Ok, the game started. Type 'rules' for more info.\n");
    spel = clone_object("/players/hippo/quest_1/closed/game.c");
    move_object(spel,this_player());
    return 1;
    }
    else
    {   
    write("Hmm.. I think you already play the game, right?\n"+
        "To stop, just enter the hole, for rules, type rules.\n"+
        "If I'm wrong, and you were not playing, mail me.\n");
    return 1;
    }
}
