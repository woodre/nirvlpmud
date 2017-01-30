#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){

 if(!arg){

  set_light(1);
  short_desc="Saber's Dreams";
  long_desc=
"You are in a lightless black void, floating free among the merrily blazing\n"+
"stars.  The stars smile at you and bathe you in illumination.  There is no\n"+
"light.  In the center of this void are blazing letters of deep crimson fire.\n\n"+
"                    Brief Lives: Innocent Dayz\n\n"+
"The whole world is indistinct and hazy.  You believe that if you <blink> the\n"+
"whole scene may change.\n"+
"                                                     - Sweet Dreams\n";

dest_dir=({
 "players/saber/tower/dream3.c","blink",
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
int ZXZ;
ZXZ = random(6);
write("\nYou blink.  When you open your eyes, your whole world has changed.\n\n");
say(tp+" slowly fades away...\n");
if(ZXZ > 3)  {
call_other(this_player(),"move_player","into a dream#players/saber/tower/dream11.c");
  return 1;
        }
        }

wake()  {
write("\nYou wake from a strange dream...\n\n");
say(tp+" slowly fades away...\n");
        }
