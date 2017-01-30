#define tp this_player()->query_name()
inherit "room/room";
int demon_number, demon_check;
object monster;

reset(int arg){
if(!present("demon"))  {
  call_out("demon_jump",4);
        }
 if(!arg){

set_light(0);
short_desc = "The Dark Circle";
long_desc=
"\n"+
" _________\n"+
"         | \n"+
"  A     |          You stand within the outer plane of the Dark Circle.\n"+
"  BIG   |          The air is think with sulphur and the distant sounds\n"+
"  CLIFF |          of screaming.  You are on the 56th of the 1313 ledges.\n"+
"        |          There is no way up, you can only jump down the cliff.\n"+
"       |    *\n"+
"       |               *                                  *\n"+
"      |   *        *        *     *     *  *                      *     *\n"+
"     |  **       * *   *  *   *   * *     *  *   *   *  *   *   * *   *  * *\n"+
"     |   *  *   *  * ** * * *  NASTY LOOKING FLAMES *  ** *  * *   * ** *   *\n"+
"     |* ** * *** * ** * ** * * * ** * * ** * *  * * * * * ** ** * * ** ** * * \n"+
"\n";

items=({
 "cliff","You stand atop a large cliff.  Do you dare to jump?",
 "ledge","YOu stand atop a towering ledge.  Do you dare to jump?",
 "flames","The flames are a dark crimson",
 });

dest_dir=({
 "/players/saber/closed/quest/hell/circle4.c","jump",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
  add_action("jump_off","jump");
}

search() {
write("You almost singe your hands!\n");
say (tp +" searches the area\n");
 return 1;  }

jump_off()  {
if(present("demon"))  {
  write("The demons prevent you from jumping!\n");
  return 1;
        }
say(tp+" jumps off the ledge and plummets down into the flames.\n");
write("\nYou jump off the ledge...\n\n\n\n\n");
write("     F\n"+
"       A\n"+
"         L\n"+
"           L\n"+
"             I\n"+
"               N\n"+
"                 G\n");
write("\n\n\n\n\nYou pass through layer upon layer of flames before you land.\n");
        }

demon_jump()  {
  demon_number = random(6);
  demon_check = demon_check + 1;

  if(demon_check < 2)  {
    monster = clone_object("/players/saber/closed/quest/hell/demon3.c");
    move_object(monster, this_object());
    say(monster->short()+" jumps from the flames.\n");
  call_out("demon_jump",1);
    return 1;
        }
  if(demon_check > 5)  {
  say("You are singed by a HUGE burst of flames.\n");
  return 1;
        }

  if(demon_number < 2)  {
    monster = clone_object("/players/saber/closed/quest/hell/manes.c");
        }
  if(demon_number > 1 && demon_number < 4)  {
    monster = clone_object("/players/saber/closed/quest/hell/demon.c");
        }
  if(demon_number > 3 && demon_number < 5)  {
    monster = clone_object("/players/saber/closed/quest/hell/demon1.c");
        }
  if(demon_number > 4)  {
    monster = clone_object("/players/saber/closed/quest/hell/demon2.c");
        }

  move_object(monster, this_object());
  say(monster->short()+" jumps from the flames!\n");
  call_out("demon_jump",10);
  return 1;
        }
