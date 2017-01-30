inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/tristian/lib/ClubFeddefine.h"
id(str) { return (::id(str) || str == "warden"); }

int x;

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Warden Jones");
  set_alt_name("jones");
  set_race("human");
  set_alias("warden");
  set_gender("male");
  set_short("Warden Jones");
  set_long(
    "This is Warden Jones, he is in charge of the prison but don't let the suit and tie\n"+
    "fool you, he used to walk a beat and still knows how to wield a billy club like an\n"+
    "old time screw.  To control the animals he has to, you know he is stronger than the\n"+
    "rest of the pack, you have been warned.\n");
  set_level(24);
  set_heal(10,1);
  set_ac(55+random(10));
  set_wc(45+random(10));
  set_wc_bonus(10);
  set_hp((1200)+random(100));
  move_object(clone_object("/players/tristian/realms/ClubFed/obj/billyclub2.c"),this_object());
    init_command("wield club");
  add_money(4000+random(2500));
  set_al(1);
  set_aggressive(2);
  set_chat_chance(10);
  load_chat(
    "The warden orders you out of his office!\n");
  load_chat(
    "The warden sends you to the hole.\n");
  set_death_emote(
    "\n\nWarden Jones falls against his desk, dead at the hands of one of his convicts.....you!\n");

  set_dead_ob(this_object());

  add_spell("club_attack",0,0,10,"15-44",0,0,"Club");
  add_spell("gun_attack",0,0,10,"50-59",0,3,"Gun");
  }

  Club()  {
      tell_room(environment(this_player()),

HIC+"Warden Jones's club takes on a life of its own and hits you over and over and over!\n"+NORM+
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
"              '''''                             '$$$'            \n\n\n"+NORM);
  return;
  }
  Gun() {    
	tell_room(environment(this_player()),
HIC+"Warden Jones's pulls out his gun and unloads the revolver at everyone!!\n"+NORM);
    tell_room(environment(this_player()),
HIR+"                      ,                                               , \n"+
"                     @'===,                                  ,_____cctI \n"+
"                     '?AAAAAAAAAAAAAAAA,,,,,,,,,,,,,,,,,,,,,;LLLLLLLLLL \n");
    tell_room(environment(this_player()),
"           ~',,,      1'''''''''''###OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n"+
"            ''EEEEE, !''***'~~~~~~'OOOIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII \n");
    tell_room(environment(this_player()),
"               ,EEEEE)>''''???????'WWW!MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM  \n"+
"                'E.,)+='WWW~~~~~~#'OOO1OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
    tell_room(environment(this_player()),
"             ,~:#'|LLL!'+++???????'$$$1==========##/                     \n"+
"              &LLLLLLLLL;;;;;;;;;;;;,,,/                                 \n");
    tell_room(environment(this_player()),
"              1#LLLLLLLLLLLLLLLLLLLLLL!                                  \n"+
"            ,!###LLLLLL''EEEE,''LLLLL!                                   \n");
    tell_room(environment(this_player()),
"            !######LLL'  'EEE'  'LLLL'                                   \n"+
"           !#########L!   'EEJ. 'LL!                                     \n");
    tell_room(environment(this_player()),
"          !##########1      'JJ*,l'                                      \n"+
"         !############'!       ,l'                                       \n");
    tell_room(environment(this_player()),
"         1##########'  1'~~,~~'                                          \n"+
"        !##########'                                                     \n");
    tell_room(environment(this_player()),
"       !###########!                                                     \n"+
"       !###########1                                                     \n");
    tell_room(environment(this_player()), 
"      !############!                                                     \n"+
"      1#############                                                     \n");
    tell_room(environment(this_player()),
"     !'#############'                                                    \n"+
"     !##############!                                                    \n");
    tell_room(environment(this_player()),
"     1##########''                                                       \n"+      
"     1#####''                                                            \n"+
"     ''''                                                                \n"+NORM);

  return;
  }
