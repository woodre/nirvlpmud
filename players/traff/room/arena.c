
inherit "room/room";
int GONG;

reset(arg){

 if(!arg){

 set_light(1);
 short_desc="Delnoch Arena";
 long_desc=
("Since Casca has gained power, gladiator style fighting has become\n"+
"popular.  Many people fight because they can earn money no other way.\n"+
"You now stand in such an arena.  As you look around you notice that\n"+
"the stands are empty, and the arena seems to be deserted.  Off to\n"+
"one side you see a large brass gong.\n");

items=({
"ground","The ground here is covered with garss",
"stands","Row upon row of wooden bench seats for the spectators",
"gong","A large brass gong suspended from a wooden framework about 6 feet\n"+
"tall.  Hanging from the frame is large striker.  You wonder what\n"+
"would happen if you were to <ring> the <gong>",
 });

  dest_dir=({
"/players/traff/room/dmain.c","west",
      });
  }   }


init()  {
 ::init();
  add_action("north","north");
  add_action("ring_gong","ring");
}

ring_gong()  {
  if(present("gladiator"))  {
  say(this_player()->query_name()+" tries to summon another fighter!\n");
  write("There is already a gladiator here.  You must kill him before\n"+
     "you summon another\n");
return 1;  }

GONG=(GONG+1);
  if(GONG>20)  {
    say("The gong rings, but nothing happens.\n");
    write("You can't summon a gladiator right now.  Try again later.\n");
  GONG=(GONG-1);
return 1;  }

  if(this_player()->query_level()<6)  {
    say(this_player()->query_name()+" rings the gong.\n"+
    "BONGGGGGGGG!\nA Gladiator strides onto the field.\n");
    write("You ring the gong.\nBONGGGGGGG!\n"+
    "A Gladiator strides onto the field.\n");
      move_object(clone_object("/players/traff/mon/glad1.c"),this_object());
return 1;  }

  if(this_player()->query_level()<11)  {
    say(this_player()->query_name()+" rings the gong.\n"+
    "BONGGGGGGGG!\nA Gladiator strides onto the field.\n");
    write("You ring the gong.\nBONGGGGGGG!\n"+
    "A Gladiator strides onto the field.\n");
      move_object(clone_object("/players/traff/mon/glad2.c"),this_object());
return 1;  }

  if(this_player()->query_level()<16)  {
    say(this_player()->query_name()+" rings the gong.\n"+
    "BONGGGGGGGG!\nA Gladiator strides onto the field.\n");
    write("You ring the gong.\nBONGGGGGGG!\n"+
    "A Gladiator strides onto the field.\n");
      move_object(clone_object("/players/traff/mon/glad3.c"),this_object());
return 1;  }

     {
    say(this_player()->query_name()+" rings the gong.\n"+
    "BONGGGGGGGG!\nA Gladiator strides onto the field.\n");
    write("You ring the gong.\nBONGGGGGGG!\n"+
    "A Gladiator strides onto the field.\n");
      move_object(clone_object("/players/traff/mon/glad4.c"),this_object());
return 1;  }
}

west()  {

  GONG=0;
call_other(this_player(),"move_player","west#players/traff/room/dmain.c");
return 1;
         }
