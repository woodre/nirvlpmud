#define tp this_player()->query_name()
#include "/players/cosmo/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("club");
  set_alias("driver");
  set_short(MAG+"Big Bertha driver"+NORM);
  set_long(
    "\nA beautifully designed Big Bertha golf club. This\n"+
    "baby has perfect balance, a titanium shaft, and a huge\n"+
    "face; definitely for the serious golfer only. This was\n"+
    "Kramer's favorite club and the one which he used to drive\n"+
    "balls into the ocean. Judging by it's weight and feel,\n"+
    "it would probably make a decent weapon.\n\n");
  set_type("club");
  set_class(17);
  set_weight(1);
  set_value(750);
  set_hit_func(this_object());
  set_message_hit(({"slam"," for a hole in one","bash"," in the skull",
"smash"," across the chest","slam"," in the ribs","slice",
" with a glancing blow","graze"," in the shin","brush"," lightly"}));
}

weapon_hit(attacker){
int W;
  W = random(13);
  if(W>9)  {
    say("\n"+
      capitalize(tp)+" shouts, 'FORE!!'.\n");
    write("\n"+
      "You shout, 'FORE!' and then rip "+BLU+"Big Bertha"+NORM+" loose in"+
      " perfect motion.\n"+GRN+"W H O O S H !!"+NORM+
      "   Your perfect swings lands squarly on your prey's temple.\n"+
      RED+"T H U D !!"+NORM+"   Blood spews forth from your victim.\n\n");
  return 6; }
return; }

query_wear() {
/* Make this weapon wear down twice as fast,
   so that it breaks twice as often.         */
int wear;
  wear = 6*misses/2 + 8*hits/9;
  return wear;
}

wield(str){
  if (::wield(str) && wielded) {
    write("You grip the club and take a few light practice swings.\n");
  return 1; }
}
