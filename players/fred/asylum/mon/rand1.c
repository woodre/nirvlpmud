inherit "obj/monster.c";
#include <ansi.h>
#define attacked (this_object()->query_attack())
#define tp this_player()->query_name()
#define tpp this_player()->query_possessive()
int b, c, d;
string A, B, C, D;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

b = random(4);
c = random(9);
d = random(5);

switch(b){
  case 0: B = "Lost"; break;
  case 1: B = "Trapped"; break;
  case 2: B = "Tormented"; break;
  case 3: B = "Enraged"; break; }
  
switch(c){
  case 0: C = BLU; break;
  case 1: C = BOLD+BLK; break;
  case 2: C = BOLD+RED; break;
  case 3: C = HIY; break;
  case 4: C = HIG; break;
  case 5: C = HIB; break;
  case 6: C = MAG; break;
  case 7: C = CYN; break;
  case 8: C = BOLD; break; }

switch(d){
  case 0: D = "neck"; break;
  case 1: D = "shoulder"; break;
  case 2: D = "arm"; break;
  case 3: D = "chest"; break;
  case 4: D = "legs"; break; }

set_name("spirit");
set_alias("crappem");
set_race("spirit");
set_short("A "+B+" "+C+"Spirit"+NORM);
set_long(
   "A "+B+" Spirit that is condemed to roam the halls of this wretched place\n"+
   "for all eternity unless someone or something can free it from it's hellish\n"+
   "state.  Cold dead eyes gaze deep into your soul pleading with you for help.\n"); 
set_al(-(random(1000)));
set_aggressive(0);
set_gender("male");
set_chat_chance(3);
  load_chat("A "+B+" Spirit floats around the room...\n");
  load_chat("A "+B+" Spirit looks deep within you soul...\n");
  load_chat("A "+B+" Spirit pleads for help...\n");
set_a_chat_chance(5);
  load_a_chat("The "+B+" Spirit begs, Why are you doing this to me?\n");
  load_a_chat("The "+B+" Spirit shrieks in agony...\n"); 
set_chance(20);
set_spell_mess1(
  "\n            The "+B+" spirit's eyes "+C+"FLARE"+NORM+" with a deep hatred...\n\n"+
  "        The spirit "+HIY+"grabs"+NORM+" it's attacker by the neck with "+BOLD+"COLD DEAD HANDS"+NORM+".\n");  
set_spell_mess2(
  "\n      The "+B+" spirit "+HIY+"grabs"+NORM+" your "+D+" with "+BOLD+"COLD DEAD HANDS"+NORM+".\n\n"+
  "               You can feel the hands slowly draining your "+C+"life"+NORM+".\n");
set_dead_ob(this_object());

if(B == "Lost"){ lost(); }
if(B == "Trapped"){ trapped(); }
if(B == "Tormented"){ tormented(); }
if(B == "Enraged"){ enraged(); }
}

lost(){
  set_level(14);
  set_wc(random(3)+17);
  set_ac(11);
  set_hp(220);
  set_spell_dam(10); }
trapped(){
  set_level(16);
  set_wc(random(3)+21);
  set_ac(13);
  set_hp(300);
  set_spell_dam(15); }
tormented(){
  set_level(18);
  set_wc(random(3)+25);
  set_ac(15);
  set_hp(400);
  set_spell_dam(25); }
enraged(){
  set_level(20);
  set_wc(random(3)+29);
  set_ac(17);
  set_hp(500);
  set_spell_dam(30); }

monster_died(){
  object corpse;
  corpse = present("corpse", environment());
  tell_object(attacked,
   "\n      The "+B+" Spirit smiles as it floats away. Almost thanking you.\n\n"+
   "              A piece of it's soul is all that remains of it's existance.\n");
  
   if(B == "Lost"){
      move_object(clone_object("/players/fred/asylum/obj/soul1.c"), 
      environment(this_object())); }
   else if(B == "Trapped"){
      move_object(clone_object("/players/fred/asylum/obj/soul2.c"),
      environment(this_object())); }
   else if(B == "Tormented"){
      move_object(clone_object("/players/fred/asylum/obj/soul3.c"),
      environment(this_object())); }
   else if(B == "Enraged"){
      move_object(clone_object("/players/fred/asylum/obj/soul4.c"),
      environment(this_object())); } 
   if(corpse)
    destruct(corpse);
    return 1; 
  }
   
        

