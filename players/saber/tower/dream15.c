#define tp this_player()->query_name()
inherit "room/room";
object d1, d2, d3, d4, d5, d6;

reset(int arg){

if(!present("dream")) {
  d1 = clone_object("/players/saber/monsters/dream.c");
  d1->set_short("Winnie the Cult Mistress of the Vampires (dream)");
  move_object(d1,this_object());
  d2 = clone_object("/players/saber/monsters/dream.c");
  d2->set_short("Delirium the Cult Mistress of the Vampires the Cat (dream)");
  move_object(d2,this_object());
  d3 = clone_object("/players/saber/monsters/dream.c");
  d3->set_short("Celine the Cult Mistress of the Vampires (dream)");
  move_object(d3,this_object());
  d4 = clone_object("/players/saber/monsters/dream.c");
  d4->set_short("Bagera the Cult Mistress of the Vampires (dream)");
  move_object(d4, this_object());
  d5 = clone_object("/players/saber/monsters/dream.c");
  d5->set_short("Nikki the Cult Mistress of the Vampires (dream)");
  move_object(d5, this_object());
}

 if(!arg){

  set_light(0);
  short_desc="Saber's Dreams";
  long_desc=
"This is a well lit, extremely comfortable, exclusive restaurant.\n"+
"There is a well dressed, snooty waiter/bartender standing in a corner.\n"+
"You notice that most of the light is provided by a sign on the wall.\n"+
"There are many radiant Vampire ladies here, gossiping about their *prey*.\n"+
"Their collective beauty overwhelms you.\n";

dest_dir=({
 "players/saber/tower/dream16.c","blink",
 "players/saber/tower/dream1.c","wake",
 });
}  }

init(){
 ::init();
   add_action("search","search");
   add_action("dream_look","look");
   add_action("dream_look","exa");
   add_action("dream_look","l");
   add_action("blink","blink");
   add_action("wake","wake");
}

search() {
write("You probably shouldn't.  You might wake Saber.\n");
return 1;
        }

dream_look(str)  {
if(str)  {
write("Your eyes can not seem to focus on that in here...\n");
  return 1;
        }
        }

blink()  {
write("\nYou blink.  When you open your eyes, your whole world has changed.\n\n");
say(tp+" slowly fades away...\n");
        }

wake()  {
write("\nYou wake from a strange dream...\n\n");
say(tp+" slowly fades away...\n");
        }
