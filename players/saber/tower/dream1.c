#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){

 if(!arg){

  set_light(1);
  short_desc="Saber's Dreams";
  long_desc=
"You have entered the mind of Saber.  As he is currently asleep, you\n"+
"see brief flickers of dreams and half forgotten memories drifting by.\n"+
"If you move quietly, you can probably explore his memories.\n"+
"There is a small, free floating sign here.\n";

dest_dir=({
 "players/saber/tower/dream2.c","blink",
 "players/saber/tower/tower11.c","wake",
 });
}  }

init(){
 ::init();
   add_action("search","search");
   add_action("dream_look","look");
   add_action("dream_look","exa");
   add_action("dream_look","l");
   add_action("new_read","read");
}

search() {
write("You probably shouldn't.  You might wake Saber.\n");
return 1;
        }

dream_look(str)  {
if(str == "sign")  {
  write("You should probably read it.\n");
  return 1;
        }
if(str)  {
write("Your eyes can not seem to focus on that in here...\n");
  return 1;
        }
        }

new_read(str)  {
if(str == "sign")  {
write(
"  Note that these are DREAMS, not the actual creatures.  Because of\n"+
"  the elusive nature of this nocturnal reality, the individuals\n"+
"  represented here are not nearly as tough as the originals might\n"+
"  once have been.  Also realize that once you have entered the realm\n"+
"  of dreams, it may take some time to leave it.\n");
  return 1;
        }
        }
