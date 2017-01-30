#define tp this_player()->query_name()
inherit "room/room";
object d1, d2, d3, d4, d5, d6;

reset(int arg){

if(!present("dream")) {
  d1 = clone_object("/players/saber/monsters/dream.c");
  d1->set_short("Guest the utter novice (dream)");
  move_object(d1,this_object());
}

 if(!arg){

  set_light(0);
  short_desc="Saber's Dreams";
  long_desc=
"A vivid construct of the church portrayed in the soft detail of fond memory.\n"+
"A free floating clock ticks quietly.  Looking up you see the mages guild\n"+
"floating overhead, while below lie the tunnels of the thieves guild.  To the\n"+
"south is the hall of the dopps.  There is a pit in the center of the room.\n";

dest_dir=({
 "players/saber/tower/dream4.c","blink",
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
