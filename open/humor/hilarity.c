#define VICTIM TO->query_attack()
#define VNAME CAP(VICTIM->query_name())
#include <universal.h>
#include "/players/entropy/includes/define.h"
inherit "/obj/monster";
int corpse, aclass, wclass;
string parts;
int xx, aa;=20
string h_mode, b_mode;
reset(arg) {
 =20
   ::reset(arg);
   if (!arg) {
     h_mode =3D "no";
     b_mode =3D "no";
     set_name(GREEN+"P"+HIK+"rot"+NORM+GREEN+"ot"+HIK+"ype"+NORM);
     set_dead_ob(this_object());
     set_short(HIK+"<<"+HIW+"Synthetic"+HIK+">>"+NORM+" =
["+GREEN+"P"+HIK+"rot"+NORM+GREEN+"ot"+HIK+"ype"+NORM+"]");
     set_alias("synthetic");
     set_alt_name("prototype");
     set_race("Synthetic");
     set_gender("male");
     set_long("Standing nearly nine feet tall this humaniod machine is =
called a Synthetic.\n"+
              "Having a body loosely based on the human form, this model =
looks anything but\n"+
              "organic. The outer shell is made from high quality =
stainless steel, not the\n"+
              "lightest of armors, but provides decent protection for =
this one ton monster\n"+
     		  "This is the Prototype model Synthetic introduced to the =
executives nearly three\n"+
     		  "years ago. While lacking the software of the newer, more =
sophisticated models,\n"+
     		  "there is no lack in power. Outfitted with two heavy class =
autocannons and a hi-\n"+
     		  "output micro reactor, the Prototype can hold its own. One =
early production flaw\n"+
     		  "involves an impropper fitting of a lead seal, causing =
radiation leaks. Inspired\n"+
     		  "by their own mistake, they discovered a way to exploit that =
fax paux.\n"+
     		  "\n"+
     		  "Analysis:\n"+
     		  =
CYAN+"<><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n"+NORM+
     		  "Defense:             =
["+HIB+"|||||||"+HIG+"||||||||"+HIY+"|||||"+HIK+"|||||||||||||"+NORM+"]\n=
"+
     		  "Attack:              =
["+HIB+"|||||||"+HIG+"||||||||"+HIY+"||||||||"+HIR+"|||"+HIK+"|||||||"+NO=
RM+"]\n"+
     		  "Power Source:        =
["+HIB+"|||||||"+HIG+"||||||||"+HIY+"||"+HIK+"||||||||||||||||"+NORM+"]\n=
"+
     		  "Salvage:             =
["+HIB+"|||||||"+HIG+"||"+HIK+"||||||||||||||||||||||||"+NORM+"]\n"+
     		  "Software:            =
["+HIB+"||||"+HIK+"|||||||||||||||||||||||||||||"+NORM+"]\n"+
     		  =
CYAN+"<><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n"+NORM);
     set_level(70+random(10));
     aclass =3D 110+random(30);
     set_ac(aclass);
     wclass =3D 215+random(70);
     set_wc(wclass);
     set_hp(8800 + random(2000));
     set_al(0);
     set_aggressive(0);
     set_chat_chance(3);
     load_chat("The Prototype performs an IR scan of the room.\n");
     load_chat("A constant hum resonates from the chestplate of the =
Prototype.\n");
     load_chat("A green glow envelops the room.\n");

     set_spell_mess2(HIG+"                               ...----....\n"+
"                         ..-:'''         '''-..\n"+
"                      .-'                      '-.\n"+
"                    .'              .     .       '.\n"+
"                  .'   .          .    .      .    .''.\n"+
"                .'  .    .       .   .   .     .   . ..:.\n"+
"              .' .   . .  .       .   .   ..  .   . ....::.\n"+
"             ..   .   .      .  .    .     .  ..  . ....:IA.\n"+
"            .:  .   .    .    .  .  .    .. .  .. .. ....:IA.\n"+
"           .: .   .   ..   .    .     . . .. . ... ....:.:VHA.\n"+
"           '..  .  .. .   .       .  . .. . .. . .....:.::IHHB.\n"+
"          .:. .  . .  . .   .  .  . . . ...:.:... .......:HIHMM.\n"+
"         .:.... .   . .'::''.. .   .  . .:.:.:II;,. .. ..:IHIMMA\n"+
"         ':.:..  ..::IHHHHHI::. . .  ...:.::::.,,,. . ....VIMMHM\n"+
"        .:::I. .AHHHHHHHHHHAI::. .:...,:IIHHHHHHMMMHHL:. . VMMMM\n"+
"       .:.:V.:IVHHHHHHHMHMHHH::..:' .:HIHHHHHHHHHHHHHMHHA. .VMMM.\n"+
"       :..V.:IVHHHHHMMHHHHHHHB... . .:VPHHMHHHMMHHHHHHHHHAI.:VMMI\n"+
"       ::V..:VIHHHHHHMMMHHHHHH. .   .I':IIMHHMMHHHHHHHHHHHAPI:WMM\n"+
"       ::'. .:.HHHHHHHHMMHHHHHI.  . .:..I:MHMMHHHHHHHHHMHV:':H:WM\n"+
"       :: . :.::IIHHHHHHMMHHHHV  .ABA.:.:IMHMHMMMHMHHHHV:'. .IHWW\n"+
"       '.  ..:..:.:IHHHHHMMHV' .AVMHMA.:.'VHMMMMHHHHHV:' .  :IHWV\n"+
"        :.  .:...:'.:.:TPP'   .AVMMHMMA.:. 'VMMHHHP.:... .. :IVAI\n"+
"       .:.   '... .:''   .   ..HMMMHMMMA::. .'VHHI:::....  .:IHW'\n"+
"       ...  .  . ..:IIPPIH: ..HMMMI.MMMV:I:.  .:ILLH:.. ...:I:IM\n"+
"     : .   .''' .:.V'. .. .  :HMMM:IMMMI::I. ..:HHIIPPHI::'.P:HM.\n"+
"     :.  .  .  .. ..:.. .    :AMMM IMMMM..:...:IV':T::I::.'.:IHIMA\n"+
"     'V:.. .. . .. .  .  .   'VMMV..VMMV :....:V:.:..:....::IHHHMH\n"+
"       'IHH:.II:.. .:. .  . . . ' :HB'' . . ..PI:.::.:::..:IHHMMV'\n"+
"        :IP''HHII:.  .  .    . . .'V:. . . ..:IH:.:.::IHIHHMMMMM'\n"+
"        :V:. VIMA:I..  .     .  . .. . .  .:.I:I:..:IHHHHMMHHMMM\n"+
"        :'VI:.VWMA::. .:      .   .. .:. ..:.I::.:IVHHHMMMHMMMMI\n"+
"        :.'VIIHHMMA:.  .   .   .:  .:.. . .:.II:I:AMMMMMMHMMMMMI\n"+
"        :..VIHIHMMMI...::.,:.,:!'I:!'I!'I!'V:AI:VAMMMMMMHMMMMMM'\n"+
"        ':.:HIHIMHHA:'!!'I.:AXXXVVXXXXXXXA:.'HPHIMMMMHHMHMMMMMV\n"+
"          V:H:I:MA:W'I :AXXXIXII:IIIISSSSSSXXA.I.VMMMHMHMMMMMM\n"+=20
"            'I::IVA ASSSSXSSSSBBSBMBSSSSSSBBMMMBS.VVMMHIMM'''\n"+
"             I:: VPAIMSSSSSSSSSBSSSMMBSSSBBMMMMXXI:MMHIMMI\n"+
"            .I::. 'H:XIIXBBMMMMMMMMMMMMMMMMMBXIXXMMPHIIMM'\n"+
"            :::I.  ':XSSXXIIIIXSSBMBSSXXXIIIXXSMMAMI:.IMM\n"+
"            :::I:.  .VSSSSSISISISSSBII:ISSSSBMMB:MI:..:MM\n"+
"            ::.I:.  ':'SSSSSSSISISSXIIXSSSSBMMB:AHI:..MMM.\n"+
"            ::.I:. . ..:'BBSSSSSSSSSSSSBBBMMMB:AHHI::.HMMI\n"+
"            :..::.  . ..::':BBBBBSSBBBMMMB:MMMMHHII::IHHMI\n"+
"            ':.I:... ....:IHHHHHMMMMMMMMMMMMMMMHHIIIIHMMV'\n"+
"              'V:. ..:...:.IHHHMMMMMMMMMMMMMMMMHHHMHHMHP'\n"+
"                ':. .:::.:.::III::IHHHHMMMMMHMHMMHHHHM'\n"+
"                 '::....::.:::..:..::IIIIIHHHHMMMHHMV'\n"+
"                   '::.::.. .. .  ...:::IIHHMMMMHMV'\n"+
"                     'V::... . .I::IHHMMV''\n"+
"                       ''VHVHHHAHHHHMMV:''\n"+
"\n"+
"\n"+
"                    "+HIR+"["+HIY+" RADIATION ATTACK UNLEASHED =
"+HIR+"]"+NORM+"\n");
     set_spell_mess1("\n"+
			    "		The Prototype fires a beam of "+HBGRN+"radiation"+NORM+"!\n"+
			    "\n");
     set_chance(8);
     set_spell_dam(250+random(100));

     }
  }

random_part()
{
	string part;
	switch(random(11))
		{
		case 0:
		part =3D "head";
		break;
		case 1:
		part =3D "torso";
		break;
		case 2:
		part =3D "right leg";
		break;
		case 3:
		part =3D "left leg";
		break;
		case 4:
		part =3D "left arm";
		break;
		case 5:
		part =3D "right arm";
		break;
		case 6:
		part =3D "left hand";
		break;
		case 7:
		part =3D "right hand";
		break;
		case 8:
		part =3D "left foot";
		break;
		case 9:
		part =3D "right foot";
		break;
		case 10:
		part =3D "pelvis";
		break;
		}
	return part;
}

heart_beat()
{
=09
	::heart_beat();
=09
	if(!environment()) return;
  	if(!attacker_ob) return;
	if(b_mode =3D=3D "yes") { go_berserk(); }
	if(h_mode =3D=3D "yes") {
		heal_me();
		if(hit_point < 1000) {
			tell_room(ENV(VICTIM),HIR+"The Prototype screams in mechanical rage =
as it enters "+HIK+"["+CYAN+"BERSERK"+HIK"]"+HIR+" mode...\n"+NORM);
			TO->set_wc(wclass);
			TO->set_ac(aclass);
			h_mode =3D "no";
			b_mode =3D "yes";
		}=20
		if(hit_point > 3000){
			tell_room(ENV(VICTIM),MAG+"The Prototype leaves =
"+HIK+"["+YELLOW+"REGENERATION"+HIK+"]"+NORM+MAG+" mode...\n"+NORM);
			TO->set_wc(wclass);
			TO->set_ac(aclass);
			h_mode =3D "no";
		}

	}	=20
	if(h_mode =3D=3D "no") {=20
		xx =3D random(100);
		if(xx > 75)=20
		{
		=09
			tell_object(VICTIM,HIK+"The Prototype fires its =
"+RED+"AUTOCANNONS"+HIK+"!!!\n");
			=
tell_object(VICTIM,"------------------------------------------------\n"+N=
ORM);

			switch(1+random(3))
			{
				case 1:
				tell_object(VICTIM, "Bullets tear through your =
"+HIR+random_part()+NORM+"!!\n");=09
				call_other(VICTIM,"heal_self",-20-random(10));
				break;
				case 2:
				tell_object(VICTIM, "Bullets tear through your =
"+HIR+random_part()+NORM+"!!\n");=09
				call_other(VICTIM,"heal_self",-20-random(10));
				tell_object(VICTIM, "Bullets tear through your =
"+HIR+random_part()+NORM+"!!\n");	=20
				call_other(VICTIM,"heal_self",-20-random(10));
				break;
				case 3:
				tell_object(VICTIM, "Bullets tear through your =
"+HIR+random_part()+NORM+"!!\n");=09
				call_other(VICTIM,"heal_self",-20-random(10));
				tell_object(VICTIM, "Bullets tear through your =
"+HIR+random_part()+NORM+"!!\n");	=20
				call_other(VICTIM,"heal_self",-20-random(10));
				tell_object(VICTIM, "Bullets tear through your =
"+HIR+random_part()+NORM+"!!\n");	=20
				call_other(VICTIM,"heal_self",-20-random(10));
				break;
				case 4:
				tell_object(VICTIM, "Bullets tear through your =
"+HIR+random_part()+NORM+"!!\n");=09
				call_other(VICTIM,"heal_self",-20-random(10));
				tell_object(VICTIM, "Bullets tear through your =
"+HIR+random_part()+NORM+"!!\n");	=20
				call_other(VICTIM,"heal_self",-20-random(10));
				tell_object(VICTIM, "Bullets tear through your =
"+HIR+random_part()+NORM+"!!\n");	=20
				call_other(VICTIM,"heal_self",-20-random(10));
				tell_object(VICTIM, "Bullets tear through your =
"+HIR+random_part()+NORM+"!!\n");	=20
				call_other(VICTIM,"heal_self",-20-random(10));
				break;
			}
			=
tell_object(VICTIM,HIK+"------------------------------------------------\=
n"+NORM);
			tell_room(ENV(VICTIM), VNAME+" is "+HIR+"TORN TO PIECES"+NORM+" by =
the Prototype's Autocannons!!!\n");
		}
		if(hit_point < 2000) {
			if(hit_point > 1000) {
				tell_room(ENV(VICTIM),HIY+"The Prototype enters =
"+HIK+"["+BLUE+"REGENERATION"+HIK+"]"+HIY" mode...\n"+NORM);
				TO->set_wc(50);
  				TO->set_ac(200);
				h_mode =3D "yes";
				b_mode =3D "no";
			}
			if(hit_point < 1001) {
				if(b_mode =3D=3D "no"){
					tell_room(ENV(VICTIM),HIR+"The Prototype screams in mechanical rage =
as it enters "+HIK+"["+CYAN+"BERSERK"+HIK"]"+HIR+" mode...\n"+NORM);
					TO->set_wc(wclass);
					TO->set_ac(aclass);
					h_mode =3D "no";
					b_mode =3D "yes";
			=09
				}
				}
			}
		}=09
	}
heal_me() {
	tell_room(ENV(VICTIM),"The Prototype "+HIG+"GLOWS " +NORM+"with =
radioactive power as it recharges!\n");
  	hit_point +=3D 30+random(20);
	return ;}

go_berserk() {
    string color, colorname;
    int bb;
    tell_object(VICTIM, HIK+"The Prototype lashes out in =
"+HIM+"RAGE"+HIK+"!!!\n"+
    						"Flashes of "+HIM+"energy"+HIK+" rupture from its chest and =
engulf you!\n"+
    						"Uncontrollable convulsions grip your body. You lose control =
of your "+MAG+random_part()+HIK+"!\n"+NORM);
	bb =3D 10+random(20);
	hit_point -=3D bb;
	call_other(VICTIM,"heal_self",-bb);
	return ;}
monster_died() {
	tell_room(environment(this_object()),"The protype crumbles into a pile =
of rubble!\n");
	corpse =3D present("corpse", environment());
	if(corpse) destruct(corpse);
	move_object(clone_object(COR_OBJ_CRO+"syn_rubble"), environment());   =20
 return ;}
