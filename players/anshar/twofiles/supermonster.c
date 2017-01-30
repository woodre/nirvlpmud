
#include "/players/anshar/closed/mydef.h"
#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
inherit "obj/monster";
int X;
int Y;
int Z;
int G;
string SIZE;
string WHAT;
string NAME;
string RACE;
object gold;
object ob;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  Y = (random(5));
  Z = (random(10));
  X = (Y+16);

  if(X == 16) SIZE = " small";
  if(X == 17) SIZE = " medium";
  if(X == 18) SIZE = " large";
  if(X == 19) SIZE = " very large";
  if(X == 20) SIZE = " huge";

  if(Z == 0) WHAT = "ghoul";
  if(Z == 1) WHAT = "wraith";
  if(Z == 2) WHAT = "skeleton";
  if(Z == 3) WHAT = "daemon";
  if(Z == 4) WHAT = "revenant";
  if(Z == 5) WHAT = "zombie";
  if(Z == 6) WHAT = "shade";
  if(Z == 7) WHAT = "ghost";
  if(Z == 8) WHAT = "phantom";
  if(Z == 9) WHAT = "hellhound";

  if(Z == 0) RACE = "undead";
  if(Z == 1) RACE = "undead";
  if(Z == 2) RACE = "undead";
  if(Z == 3) RACE = "daemon";
  if(Z == 4) RACE = "undead";
  if(Z == 5) RACE = "undead";
  if(Z == 6) RACE = "undead";
  if(Z == 7) RACE = "undead";
  if(Z == 8) RACE = "undead";
  if(Z == 9) RACE = "hound";

  if(Z == 0){ ghoul(); }
  if(Z == 1){ wraith(); }
  if(Z == 2){ skeleton(); }
  if(Z == 3){ daemon(); }
  if(Z == 4){ revenant(); }
  if(Z == 5){ zombie(); }
  if(Z == 6){ shade(); }
  if(Z == 7){ ghost(); }
  if(Z == 8){ phantom(); }
  if(Z == 9){ hellhound(); }

  if(Y == 0) G = (random(600)+490);
  if(Y == 1) G = (random(600)+550);
  if(Y == 2) G = (random(600)+600);
  if(Y == 3) G = (random(1500)+1000);
  if(Y == 4) G = (random(2000)+3000);

  set_name(WHAT);
  set_short("A"+SIZE+" "+WHAT+"");
  set_alias("RACE");
  set_race("RACE");
  set_hp(400+(Y*25));
  set_level(X);
  set_al(-200);
  set_wc(X-3);
  set_ac(22+(Y*2));
  set_aggressive(0);

  set_dead_ob(TO);

  gold=clone_object("obj/money");
  gold->set_money(G);
  move_object(gold,this_object());

}

  id(str) {
  return (str == WHAT || str == RACE || str == "smon"); 
}

ghoul(){
    set_long("     This flesh eating ghoul stands hunched over, its dark\n"+
             "eyes gleaming with a malevolent light. The stench of rotten\n"+
             "flesh is nearly overwhelming this close to the grisly beast.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The stench of rotten flesh drives you back.\n");
  load_chat("A disturbing gurgle floats from the carrion eater.\n");
  load_a_chat("The ghoul rakes you with diseased claws.\n");
}
wraith(){
    set_long("     The insubstantial form of the wraith exudes a chill that\n"+
             "seems nearly as cold as death itself, which may very well be\n"+
             "the case. A shimmering outline causes the form of the wraith to\n"+
             "be indistinct.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The wraith shimmers out of sight momentarily.\n");
  load_chat("A thin wail echoes from somewhere far away, or was it near?\n");
  load_a_chat("The wraith touches you, and cold seers youto the bone.\n");
}
skeleton(){
    set_long("     Pieces of decayed flesh barely cling to this skeleton that\n"+
             "has somehow been animated. The same process that engendered its\n"+
             "locomotive ability has also left its mark in the twin orbs of\n"+
             "flame that glow from eyesockets like a pair of unholy eyes.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The skeleton clacks noisily as it moves.\n");
  load_chat("The skeletone turns its gaze apon you, filling you with fear.\n");
  load_a_chat("The skeleton pummels you with bared knuckles.\n");
}
daemon(){
    set_long("     With a slick hide so dark red, it is almost black, this form\n"+
             "is an imposing sight. Sharp white fangs drip acidic drool while a\n"+
             "scorpion-like tail arches over the muscled shoulder, almost as if\n"+
             "seeking something particular.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The daemon laughs at your insignificance.\n");
  load_chat("The daemon dares you to attack.\n");
  load_a_chat("The daemon slams you with its fists.\n");
}
revenant(){
    set_long("     This force of retribution glares about, looking for something\n"+
             "to sate its incredible bloodlust. Implaccable in its desire to right\n"+
             "some wrong, the revenant relentlessly searches with unmatched fury\n"+
             "for some release from this tortured existence.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("A deep growl echoes through the still air.\n");
  load_chat("The revenant searches for retribution.\n");
  load_a_chat("The revenant attacks in a fury.\n");
}
zombie(){
    set_long("     The shambling mound of putrefied flesh reeks of death and\n"+
             "decay. Shuffling steps leave bit after bit of noxious pieces of\n"+
             "this beast in its wake.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("Pieces of rotten flesh drip from the zombie.\n");
  load_chat("The zombie shuffles slightly.\n");
  load_a_chat("Pieces of flesh shower you as the decayed form attacks.\n");
}
shade(){
    set_long("     A being comprised of pure darkness, the shade flits in and out\n"+
             "of sight. Cold permeates the air around the beast, sinking deep into\n"+
             "the bones, and sapping all strength from opponents.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The shade disappears, appearing a distance away.\n");
  load_chat("For a moment, the shade's form resembles your own.\n");
  load_a_chat("Darkness engulfs you as the shade attacks.\n");
}
ghost(){
    set_long("     The restless spirit of a being who has died an untimely death,\n"+
             "this representation of a young lady shows the signs of a violent and\n"+
             "hideous demise. Her empty-looking eyes gaze hungrily for something\n"+
             "lost, and unknown.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("A thin wail echoes from the spirit.\n");
  load_chat("The spirit weeps piteously.\n");
  load_a_chat("The ghost tugs at your soul hungrily.\n");
}
phantom(){
    set_long("     This is a dark being of negative energy with haunted eyes and\n"+
             "an evil grin full of malice and hate. The wavering form flickers in\n"+
             "and out of sight, while a thin wail permeates the air.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The phantom cackles maddeningly.\n");
  load_chat("The phantom flits around.\n");
  load_a_chat("Pain shoots through you as the phantom attacks.\n");
}
hellhound(){
    set_long("     The shaggy beast can only be called a hound by some sort of\n"+
             "great understatement. Its large form dwarfs even the most massive\n"+
             "of simple dogs. The other main difference is in the flames that lick\n"+
             "around its dark form, and within its evil eyes.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The hound growls low in its throat.\n");
  load_chat("Flame flickers within the eyes of the hound.\n");
  load_a_chat("Heat assails you as the hound leaps.\n");
}

heart_beat() {
  ::heart_beat();
  if (query_attack() &&  random(10) == 1) {
    if(Z == 0){ a_ghoul(); }
    if(Z == 1){ a_wraith(); }
    if(Z == 2){ a_skeleton(); }
    if(Z == 3){ a_daemon(); }
    if(Z == 4){ a_revenant(); }
    if(Z == 5){ a_zombie(); }
    if(Z == 6){ a_shade(); }
    if(Z == 7){ a_ghost(); }
    if(Z == 8){ a_phantom(); }
    if(Z == 9){ a_hellhound(); }
  }
}

a_ghoul() {
object target;
object envto;
int A;
envto=environment(this_object());
target=first_inventory(envto);
tell_room(environment(this_object()),
  HIR+"     *****  *       ***   **   **  *****\n"+
      "     *      *      *   *  * * * *  *    \n"+
      "     ***    *      *****  *  *  *  ***  \n"+
      "     *      *      *   *  *     *  *    \n"+
      "     *      *****  *   *  *     *  *****\n"+
      "             ENGULFS THE ROOM!"+NORM+"\n");
  while(target) {
    if(living(target)) {
      if(target->is_player()) {
         A = (query_ac(target));
         target->add_hit_point(-(10+(Y*5))+A);
 
}
}
           target=next_inventory(target);
}
return 1;
}

a_wraith() {
object target;
object envto;
int A;
envto=environment(this_object());
target=first_inventory(envto);
tell_room(environment(this_object()),
  HIR+"     *****  *       ***   **   **  *****\n"+
      "     *      *      *   *  * * * *  *    \n"+
      "     ***    *      *****  *  *  *  ***  \n"+
      "     *      *      *   *  *     *  *    \n"+
      "     *      *****  *   *  *     *  *****\n"+
      "             ENGULFS THE ROOM!"+NORM+"\n");
  while(target) {
    if(living(target)) {
      if(target->is_player()) {
         A = (query_ac(target));
         target->add_hit_point(-(10+(Y*5))+A);
 
}
}
           target=next_inventory(target);
}
return 1;
}

a_skeleton() {
object target;
object envto;
envto=environment(this_object());
target=first_inventory(envto);
tell_room(environment(this_object()),
  HIR+"     *****  *       ***   **   **  *****\n"+
      "     *      *      *   *  * * * *  *    \n"+
      "     ***    *      *****  *  *  *  ***  \n"+
      "     *      *      *   *  *     *  *    \n"+
      "     *      *****  *   *  *     *  *****\n"+
      "             ENGULFS THE ROOM!"+NORM+"\n");
  while(target) {
    if(living(target)) {
      if(target->is_player()) {
         target->hit_player(10+(Y*5));
 
}
}
           target=next_inventory(target);
}
return 1;
}

a_daemon() {
object target;
object envto;
envto=environment(this_object());
target=first_inventory(envto);
tell_room(environment(this_object()),
  HIR+"     *****  *       ***   **   **  *****\n"+
      "     *      *      *   *  * * * *  *    \n"+
      "     ***    *      *****  *  *  *  ***  \n"+
      "     *      *      *   *  *     *  *    \n"+
      "     *      *****  *   *  *     *  *****\n"+
      "             ENGULFS THE ROOM!"+NORM+"\n");
  while(target) {
    if(living(target)) {
      if(target->is_player()) {
         target->hit_player(10+(Y*5));
 
}
}
           target=next_inventory(target);
}
return 1;
}

a_revenant() {
object target;
object envto;
envto=environment(this_object());
target=first_inventory(envto);
tell_room(environment(this_object()),
  HIR+"     *****  *       ***   **   **  *****\n"+
      "     *      *      *   *  * * * *  *    \n"+
      "     ***    *      *****  *  *  *  ***  \n"+
      "     *      *      *   *  *     *  *    \n"+
      "     *      *****  *   *  *     *  *****\n"+
      "             ENGULFS THE ROOM!"+NORM+"\n");
  while(target) {
    if(living(target)) {
      if(target->is_player()) {
         target->hit_player(10+(Y*5));
 
}
}
           target=next_inventory(target);
}
return 1;
}

a_zombie() {
object target;
object envto;
envto=environment(this_object());
target=first_inventory(envto);
tell_room(environment(this_object()),
  HIR+"     *****  *       ***   **   **  *****\n"+
      "     *      *      *   *  * * * *  *    \n"+
      "     ***    *      *****  *  *  *  ***  \n"+
      "     *      *      *   *  *     *  *    \n"+
      "     *      *****  *   *  *     *  *****\n"+
      "             ENGULFS THE ROOM!"+NORM+"\n");
  while(target) {
    if(living(target)) {
      if(target->is_player()) {
         target->hit_player(10+(Y*5));
 
}
}
           target=next_inventory(target);
}
return 1;
}

a_shade() {
object target;
object envto;
envto=environment(this_object());
target=first_inventory(envto);
tell_room(environment(this_object()),
  HIR+"     *****  *       ***   **   **  *****\n"+
      "     *      *      *   *  * * * *  *    \n"+
      "     ***    *      *****  *  *  *  ***  \n"+
      "     *      *      *   *  *     *  *    \n"+
      "     *      *****  *   *  *     *  *****\n"+
      "             ENGULFS THE ROOM!"+NORM+"\n");
  while(target) {
    if(living(target)) {
      if(target->is_player()) {
         target->hit_player(10+(Y*5));
 
}
}
           target=next_inventory(target);
}
return 1;
}

a_ghost() {
object target;
object envto;
envto=environment(this_object());
target=first_inventory(envto);
tell_room(environment(this_object()),
  HIR+"     *****  *       ***   **   **  *****\n"+
      "     *      *      *   *  * * * *  *    \n"+
      "     ***    *      *****  *  *  *  ***  \n"+
      "     *      *      *   *  *     *  *    \n"+
      "     *      *****  *   *  *     *  *****\n"+
      "             ENGULFS THE ROOM!"+NORM+"\n");
  while(target) {
    if(living(target)) {
      if(target->is_player()) {
         target->hit_player(10+(Y*5));
 
}
}
           target=next_inventory(target);
}
return 1;
}

a_phantom() {
object target;
object envto;
envto=environment(this_object());
target=first_inventory(envto);
tell_room(environment(this_object()),
  HIR+"     *****  *       ***   **   **  *****\n"+
      "     *      *      *   *  * * * *  *    \n"+
      "     ***    *      *****  *  *  *  ***  \n"+
      "     *      *      *   *  *     *  *    \n"+
      "     *      *****  *   *  *     *  *****\n"+
      "             ENGULFS THE ROOM!"+NORM+"\n");
  while(target) {
    if(living(target)) {
      if(target->is_player()) {
         target->hit_player(10+(Y*5));
 
}
}
           target=next_inventory(target);
}
return 1;
}

a_hellhound() {
object target;
object envto;
envto=environment(this_object());
target=first_inventory(envto);
tell_room(environment(this_object()),
  HIR+"     *****  *       ***   **   **  *****\n"+
      "     *      *      *   *  * * * *  *    \n"+
      "     ***    *      *****  *  *  *  ***  \n"+
      "     *      *      *   *  *     *  *    \n"+
      "     *      *****  *   *  *     *  *****\n"+
      "             ENGULFS THE ROOM!"+NORM+"\n");
  while(target) {
    if(living(target)) {
      if(target->is_player()) {
         target->hit_player(10+(Y*5));
 
}
}
           target=next_inventory(target);
}
return 1;
}
