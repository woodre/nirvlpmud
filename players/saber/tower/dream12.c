#define tp this_player()->query_name()
inherit "room/room";
object d1, d2, d3, d4, d5, d6;

reset(int arg){

if(!present("dream")) {
  d1 = clone_object("/players/saber/monsters/dream.c");
  d1->set_short("Ozymandias the King of Kings (dream)");
  move_object(d1,this_object());
  d2 = clone_object("/players/saber/monsters/dream.c");
  d2->set_short("The Riddler (dream)");
  move_object(d2,this_object());
  d3 = clone_object("/players/saber/monsters/dream.c");
  d3->set_short("John Constantine (dream)");
  move_object(d3,this_object());
  d4 = clone_object("/players/saber/monsters/dream.c");
  d4->set_short("A drow elf named Drelifinia (dream)");
  move_object(d4, this_object());
}

 if(!arg){

  set_light(0);
  short_desc="Saber's Dreams";
  long_desc=
"A small pub filled with shifting shadows of illuminated darkness.  There are\n"+
"four figures sitting here conversing with each other.\n";

dest_dir=({
 "players/saber/tower/dream13.c","blink",
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
