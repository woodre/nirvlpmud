inherit "obj/monster";
#define MOV_RATE 1
void reset(int arg){
   ::reset(arg);
     if(arg) return;
set_name("cell");
set_short("A cell");
set_long("This cell looks like an ordinary epithelial cell.\n");
set_level(4);
set_hp(1500);
set_ac(25);
set_al(0);
set_aggressive(0);
move_object(clone_object("/players/hippo/quest_2/t/22chrf.c"),this_object());
       call_out("random_move",MOV_RATE);
}
status random_move(){
   switch(random(4)) {
      case 0 : command("north"); break;
      case 1 : command("east"); break;
      case 2 : command("west"); break;
      case 3 : command("south"); break;
   }
   call_out("random_move",MOV_RATE);
   return 1;
} 
