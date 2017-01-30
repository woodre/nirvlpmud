/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */
/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */

#include "/players/eurale/defs.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name(HIG+"Sea Dragon"+NORM);
set_alias("sea dragon");
set_race("dragon");
set_short(HIG+"Sea Dragon"+NORM);
set_long(
	"This dragon is related to the dragon turtle.  It resembles a giant\n"+
	"turtle with a dragon's head and massive flippers.  A thick shell\n"+
	"which is very dark green or maybe even black covers most of it's\n"+
	"body.  The webbed toes and paddlelike flippers make land travel\n"+
	"very difficult.  This dragon has no teeth and so uses it's 'breath\n"+
	"weapon' to kill it's enemies.\n");

set_level(24);
set_hp(1100 + random(250));
set_al(-300);
set_wc(51);
/*
set_wc_bonus(39);
*/
set_ac(25);
set_heal(20,3);
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The Sea Dragon slowly turns its gaze to you....\n");
set_a_chat_chance(18);
  load_a_chat("The dragon ducks into his shell for protection..\n");
  load_a_chat("The Sea Dragon swats at you with its huge flipper..\n");
  load_a_chat("The Dragon just missed crushing you with its jaws...\n");

/*
set_chance(25);
set_spell_dam(60 + random(30));
set_spell_mess1(
  "\n\n"+
  "The Sea Dragon breathes a "+HIC+"CONE OF STEAM"+NORM+"\n\n");
set_spell_mess2(
  "\n\nA "+HIC+"CONE OF STEAM"+NORM+" engulfs you...\n\n");
*/

add_spell("steam",
  "\n\nA "+HIC+"CONE OF STEAM"+NORM+" engulfs you...\n\n",
  "\n\nThe Sea Dragon breathes a "+HIC+"CONE OF STEAM"+NORM+"\n\n",
25,"60-90","other|water",0);

add_spell("wave",
HIB+"\n      ,(   ,(   ,(   ,(   ,(   ,(   ,(   ,(\n"+
"   `-'  `-'  `-'  `-'  `-'  `-'  `-'  `-'  `\n"+NORM,
HIB+"\n      ,(   ,(   ,(   ,(   ,(   ,(   ,(   ,(\n"+
"   `-'  `-'  `-'  `-'  `-'  `-'  `-'  `-'  `\n"+NORM,
30,"40-60","other|water", 0);

add_spell("splash",
HIB+"\n                           .HI\n"+NORM+
HIB+"                          .MHMH                 X:\n"+NORM+
HIB+"                          :HMMH.            .X!HMM.\n"+NORM+
HIB+"                          `HMHM!            !MHMMX\n"+NORM+
HIB+"                           HMHHH.            IMM!\n"+NORM+
HIB+"                           XHHHHM!\n"+NORM+
HIB+"     XMMM!.                IMHXHMM.                        :I.\n"+NORM+
HIB+"     `HMHMMI.              :HHXXHH'                      .AMH'\n"+NORM+
HIB+"       `VMHHM!              HHXIHH                      :MHH'\n"+NORM+
HIB+"         `!HHHA.            XHIIIX.    .MX     .:HD    AHHV\n"+NORM+
HIB+"            `HHHA.          !HI!IXI    AM:    AMHH'. :HHM!\n"+NORM+
HIB+"              `XXHA.     .  `HI!:IX   :HH    AHHMV .IXHH'\n"+NORM+
HIB+"               `!XIX:.  AMA:.H!::IX.  !HX   AHHHV :IIHX\n"+NORM+
HIB+"                 `XIXX: :HHHHHI. .HMMMXXH: !XIHHHIIHV'\n"+NORM+
HIB+"                  `X!:IXIMHHXHI.  IHHH!HX.!IIXH!.IHV\n"+NORM+
HIB+"                   `H:.:!IHHXII:  .XH!!HMI::X! :XHI\n"+NORM+
HIB+"                    :MI. .!!II!:  :II.!H!.:I:.IHV: \n"+NORM+
HIB+"               :AMMHHII!:. :::::   ::.I: .: :IHV.                          .!!: \n"+NORM+
HIB+"                   `:VMHII:. .       ..   .IHHMI                    .:IHHMMMHMM!\n"+NORM+
HIB+"      ..::::.....      HHXI:.            :IXXHHMH.          .:!IXHHHHHMHHHX!'\n"+NORM+
HIB+"AMMMMMMMMHHHHHHHXIIIII!!!:::.            :!!IXHHHHH:..:!!XXXHHXI!:'\n"+NORM+
HIB+"              ``::!XHX:....                     .!XHHHI:'\n"+NORM+
HIB+"                       II!:..           .::!IIHHI'\n"+NORM+
HIB+"                  .:II::  .::        ::. .:!IHM:\n"+NORM+
HIB+"            :IXXIIIIIIXHMH::!: .::  .::!II!: :H!\n"+NORM+
HIB+"     .!XHHHHXHHHX!:'  .XXIXH: :III:  !XHHHHHHI!IA:.      !MA\n"+NORM+
HIB+" AHMMHMMMHI!:'      :HHHHHH:.!HHHHI: :HM:    `!XXXX::.   XMMI     .HM!\n"+NORM+
HIB+" `VI!'             !MV'  :!!IHMMMHHI. XX          `!XHHA. ..      :HMM:\n"+NORM+
HIB+"                        AIIHI'   VMH: :I             `VHMMH:.      `!!\n"+NORM+
HIB+"             .MMMV'    AHHH:      `HH::!    .HM:        `VMMMA\n"+NORM+
HIB+"           .HV'      :MHHHI        `HI!!.                 `:HMD\n"+NORM+
HIB+"          :'         IMHV'          `XII!\n"+NORM+
HIB+"                      `'             :XIX.\n"+NORM+
HIB+"                                      !HHI          IMMI\n"+NORM+
HIB+"                                      `XHH!         IMMM:\n"+NORM+
HIB+"                                       XHHH.         :I:\n"+NORM+
HIB+"                                       !MHMI\n"+NORM+
HIB+"  VK                                   :MHHH:\n"+NORM+
HIB+"                                       `VMMV'\n"+NORM,

/*
HIB+"\n                           .HI\n"+NORM+
HIB+"                          .MHMH                 X:\n"+NORM+
HIB+"                          :HMMH.            .X!HMM.\n"+NORM+
HIB+"                          `HMHM!            !MHMMX\n"+NORM+
HIB+"                           HMHHH.            IMM!\n"+NORM+
HIB+"                           XHHHHM!\n"+NORM+
HIB+"     XMMM!.                IMHXHMM.                        :I.\n"+NORM+
HIB+"     `HMHMMI.              :HHXXHH'                      .AMH'\n"+NORM+
HIB+"       `VMHHM!              HHXIHH                      :MHH'\n"+NORM+
HIB+"         `!HHHA.            XHIIIX.    .MX     .:HD    AHHV\n"+NORM+
HIB+"            `HHHA.          !HI!IXI    AM:    AMHH'. :HHM!\n"+NORM+
HIB+"            `HHHA.          !HI!IXI    AM:    AMHH'. :HHM!\n"+NORM+
HIB+"              `XXHA.     .  `HI!:IX   :HH    AHHMV .IXHH'\n"+NORM+
HIB+"               `!XIX:.  AMA:.H!::IX.  !HX   AHHHV :IIHX\n"+NORM+
HIB+"                 `XIXX: :HHHHHI. .HMMMXXH: !XIHHHIIHV'\n"+NORM+
HIB+"                  `X!:IXIMHHXHI.  IHHH!HX.!IIXH!.IHV\n"+NORM+
HIB+"                   `H:.:!IHHXII:  .XH!!HMI::X! :XHI\n"+NORM+
HIB+"                    :MI. .!!II!:  :II.!H!.:I:.IHV: \n"+NORM+
HIB+"               :AMMHHII!:. :::::   ::.I: .: :IHV.                          .!!: \n"+NORM+
HIB+"                   `:VMHII:. .       ..   .IHHMI                    .:IHHMMMHMM!\n"+NORM+
HIB+"      ..::::.....      HHXI:.            :IXXHHMH.          .:!IXHHHHHMHHHX!'\n"+NORM+
HIB+"AMMMMMMMMHHHHHHHXIIIII!!!:::.            :!!IXHHHHH:..:!!XXXHHXI!:'\n"+NORM+
HIB+"              ``::!XHX:....                     .!XHHHI:'\n"+NORM+
HIB+"                       II!:..           .::!IIHHI'\n"+NORM+
HIB+"                  .:II::  .::        ::. .:!IHM:\n"+NORM+
HIB+"            :IXXIIIIIIXHMH::!: .::  .::!II!: :H!\n"+NORM+
HIB+"     .!XHHHHXHHHX!:'  .XXIXH: :III:  !XHHHHHHI!IA:.      !MA\n"+NORM+
HIB+" AHMMHMMMHI!:'      :HHHHHH:.!HHHHI: :HM:    `!XXXX::.   XMMI     .HM!\n"+NORM+
HIB+" `VI!'             !MV'  :!!IHMMMHHI. XX          `!XHHA. ..      :HMM:\n"+NORM+
HIB+"                        AIIHI'   VMH: :I             `VHMMH:.      `!!\n"+NORM+
HIB+"             .MMMV'    AHHH:      `HH::!    .HM:        `VMMMA\n"+NORM+
HIB+"           .HV'      :MHHHI        `HI!!.                 `:HMD\n"+NORM+
HIB+"          :'         IMHV'          `XII!\n"+NORM+
HIB+"          :'         IMHV'          `XII!\n"+NORM+
HIB+"                      `'             :XIX.\n"+NORM+
HIB+"                                      !HHI          IMMI\n"+NORM+
HIB+"                                      `XHH!         IMMM:\n"+NORM+
HIB+"                                       XHHH.         :I:\n"+NORM+
HIB+"                                       !MHMI\n"+NORM+
HIB+"  VK                                   :MHHH:\n"+NORM+
HIB+"                                       `VMMV'\n"+NORM,
*/
"#MN# launches a large splash of $HB$W A T E R$N$ and submerges #TN#.\n",
30,"40-60","other|water", 1);
}

monster_died() {
  object ob;
  tell_room(environment(this_object()),
    "\nWith a gigantic SPLASH, the sea dragon hits the water...dead!\n\n");
  move_object(clone_object("players/eurale/Keep/OBJ/dragon_shell.c"),
    environment(this_object()));
  if(attacker_ob)
  move_object(clone_object("players/eurale/Keep/QST/seadragon.c"),
                attacker_ob);
  write_file("/players/eurale/Keep/LOGS/dragons",
  ctime(time())+"     Seadragon        "+query_attack()->query_real_name()+"\n");
return 0; }
