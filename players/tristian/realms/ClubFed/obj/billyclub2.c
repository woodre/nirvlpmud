#include <ansi.h>
#define CO call_other

inherit "obj/weapon";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name(RED+"Billy Club of Punishment"+NORM);
   set_class(21);
   set_weight(1);
   set_value(5000);
   set_type("club");
   set_alias("billy club");
   set_short(RED+"Billy Club of Punishment"+NORM);
   set_long(
      "This billy club belonged to the Warden of Club Fed from the time he was a\n"+
      "screw walking a beat watching over prisoners.  It has busted more skulls\n"+
      "and put more cons in the infirmary than you can count.  The handle is wrapped\n"+
      "in leather tailing off to a lanyard ment to keep it attached to your wrist.\n");

   set_hit_func(this_object());

  message_hit=({
    ""+HIR+"demolished"+NORM+""," with an extreme blow",  
    ""+RED+"decapitated"+NORM+""," with a blow to the head",
    ""+HIK+"bludgeoned"+NORM+""," with some force",
    ""+HIK+"clobbered"+NORM+""," in the chest",
    ""+HIK+"prodded"+NORM+"","'s left kneecap, forcing a gasp of pain",
    ""+BLU+"poked"+NORM+""," in the stomach with minor effect",
    ""+HIG+"touched"+NORM+""," on the arm with an ineffective swing",
  });
}

query_wear() {
   return 1;
}

weapon_breaks() {
   return 1;
}

weapon_hit(attacker) {

   int clubhit;
   clubhit=random(500);
      if(!random(15) && check_race(attacker)){
       if(!attacker) return 1;

tell_room(environment(this_player()),

HIC+"The club takes on a life of its own and hits the convict over and over and over!\n"+NORM+
RED+"                      .ed--------$$$$be.                     \n");
tell_room(environment(this_player()),
"                     --           ^~~**$$$e.                     \n"+
"                   .-                   '$$$c                    \n");
tell_room(environment(this_player()),
"                  /                      -4$$b                   \n"+
"                 d  3                     $$$$                   \n");
tell_room(environment(this_player()),
"                 $  *                   .$$$$$$                  \n"+
"                .$  ^c           $$$$$e$$$$$$$$.                 \n");
tell_room(environment(this_player()),
"                d$L  4.         4$$$$$$$$$$$$$$b                 \n"+
"                $$$$b ^ceeeee.  4$$ECL.F*$$$$$$$                 \n");
tell_room(environment(this_player()),
"    e$''=.      $$$$P d$$$$F $ $$$$$$$$$- $$$$$$                 \n"+
"   z$$b. ^c     3$$$F '$$$$b   $'$$$$$$$  $$$$*'      .=''$c     \n");
tell_room(environment(this_player()),
"  4$$$$L   \     $$P'  '$$b   .$ $$$$$...e$$        .=  e$$$.    \n"+
"  ^*$$$$$c  %..   *c    ..    $$ 3$$$$$$$$$$eF     zP  d$$$$$    \n");
tell_room(environment(this_player()),
"    '**$$$ec   '\   %ce''    $$$  $$$$$$$$$$*    .r' =$$$$P''    \n"+
"          '*$b.  'c  *$e.    *** d$$$$$'L$$    .d'  e$$***'      \n");
tell_room(environment(this_player()),
"            ^*$$c ^$c $$$      4J$$$$$% $$$ .e*'.eeP'            \n"+
"               '$$$$$$''$=e....$*$$**$cz$$' '..d$*'              \n");
tell_room(environment(this_player()),
"                 '*$$$  *=%4.$ L L$ P3$$$F $$$P'                 \n"+
"                    '$   '%*ebJLzb$e$$$$$b $P'                   \n");
tell_room(environment(this_player()),
"                      %..      4$$$$$$$$$$ '                     \n"+
"                       $$$e   z$$$$$$$$$$%                       \n");
tell_room(environment(this_player()),
"                        '*$c  '$$$$$$$P'                         \n"+
"                         '''*$$$$$$$$bc                          \n");
tell_room(environment(this_player()),
"                      .-'    .$***$$'''*e.                       \n"+
"                   .-'    .e$'     '*$c  ^*b.                    \n");
tell_room(environment(this_player()),
"            .=*'''    .e$*'          '*bc  '*$e..                \n"+
"          .$'        .z*'               ^*$e.   '*****e.         \n");
tell_room(environment(this_player()),
"          $$ee$c   .d'                     '*$.        3.        \n"+
"          ^*$E')$..$'                         *   .ee==d%        \n"+
"             $.d$$$*                           *  J$$$e*         \n"+
"              '''''                             '$$$'            \n"+NORM);

      attacker->heal_self(-(30+random(10)));
      return 1;
   }
}

check_race(object ob) {
  if(
    CO(ob,"id","convict")) return 1;
  else return 0;
}
