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
"  CLIFF |          of screaming.  You are on the 98th of the 1313 ledges.\n"+
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
 "/players/saber/closed/quest/hell/circle5.c","jump",
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
  write("The flames are too hot for you to jump down into them...\n");
    return 1;
        }

demon_jump()  {
  demon_number = random(6);
  demon_check = demon_check + 1;

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
