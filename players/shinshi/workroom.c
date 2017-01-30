#include "/players/mokri/define.h"
inherit "/players/vertebraker/closed/std/room.c";

object ufo;
int shield;
reset(arg) {
	
set_light(0);
set_short("Shinshi's Tower (open)");

set_long(
"                            . ...\n"+
"                         .''.' .    '.\n"+
"                    . '' \".'.:I:.'..  '.\n"+
"                  .'.:.:..,,:II:'.'.'.. '.\n"+
"                .':.'.:.:I:.:II:'.'.'.'.. '.\n"+
"              .'.'.'.'::.:.:.:I:'.'.'.'. .  '\n"+
"             ..'.'.'.:.:I::.:II:.'..'.'..    .\n"+
"            ..'.'':.:.::.:.::II::.'.'.'.'..   .\n"+
"           ..'.'.'.:.::. .:::II:..'.'.'.'.'.   .\n"+
"          .':.''.':'.'.'.:.:I:'.'.'.'.'.. '..  ..\n"+
"          ':. '.':'. ..:.::.::.:.'..'  ':.'.'.. ..\n"+
"         .:.:.':'.   '.:':I:.:.. .'.'.  ': .'.. . ..\n"+
"         '..:.:'.   .:.II:.:..   . .:.'. '.. '. .  ..\n"+
"        .. :.:.'.  .:.:I:.:. .  . ..:..:. :..':. .  '.\n"+
"       .:. :.:.   .:.:I:.:. .    . ..:I::. :: ::  .. ..\n"+
"       .. :'.'.:. .:.:I:'.        ..:.:I:. :: ::.   . '.\n"+
"       '..:. .:.. .:II:'         ,,;IIIH.  ::. ':.      .\n"+
"      .:.::'.:::..:.AII;,      .::\",,  :I .::. ':.       .\n"+
"      :..:'.:II:.:I:  ,,;'   ' .;:FBT\"X:: ..:.. ':.    . .\n"+
"     .. :':III:. :.:A\"PBF;.  . .P,IP;;\":: :I:..'::. .    ..\n"+
"     . .:.:II: A.'.';,PP:\" .  . ..'..' .: :.::. ':...  . ..\n"+
"     . .: .:IIIH:.   ' '.' .  ... .    .:. :.:.. :...    .'\n"+
"     . .I.::I:IIA.        ..   ...    ..::.'.'.'.: ..  . .\n"+
"      .:II.'.':IA:.      ..    ..:.  . .:.: .''.'  ..  . .\n"+
"     ..::I:,'.'::A:.  . .:'-, .-.:..  .:.::AA.. ..:.' .. .\n"+
"      ':II:I:.  ':A:. ..:'   ''.. . : ..:::AHI: ..:..'.'.\n"+
"     .':III.::.   'II:.:.,,;;;:::::\". .:::AHV:: .::'' ..\n"+
"     ..\":IIHI::. .  \"I:..\":;,,,,;;\". . .:AII:: :.:'  . .\n"+
"     . . IIHHI:..'.'.'V::. \":;;;\"   ...:AIIV:'.:.'  .. .\n"+
"      . . :IIHI:. .:.:.V:.   ' ' . ...:HI:' .:: :. .  ..\n"+
"      . .  ':IHII:: ::.IA..      .. .A .,,:::' .:.    .\n"+
"      :.  ...'I:I:.: .,AHHA, . .'..AHIV::' . .  :     ..\n"+
"      :. '.::::II:.I:.HIHHIHHHHHIHHIHV:'..:. .I.':. ..  '.\n"+
"   . . .. '':::I:'.::IHHHHHHHHMHMHIHI. '.'.:IHI..  '  '  '.\n"+
"    ':... .  ''\" .::'.HMHI:HHHHMHHIHI. :IIHHII:. . . .    .\n"+
"     :.:.. . ..::.' .IV\".:I:IIIHIHHIH. .:IHI::'.': '..  .  .\n"+
"   . .:.:: .. ::'.'.'..':.::I:I:IHHHIA.'.II.:...:' .' ... . '..\n"+
"  '..::::' ...::'.IIHII:: .:.:..:..:III:.'::' .'    .    ..  . .\n"+
"  '::.:' .''     .. :IIHI:.:.. ..: . .:I:\"' ...:.:.  ..    .. ..\n"+
"     .:..::I:.  . . . .IHII:.:'   .. ..\".::.:II:.:. .  ...   . ..\n"+
"  .. . .::.:.,,...-::II:.:'    . ...... . .. .:II:.::  ...  .. ..\n"+
"   ..:.::.I .    . . .. .:. .... ...:.. . . ..:.::.   :..   . ..\n"+
"    .'.::I:.      . .. ..:.... . ..... .. . ..::. .. .I:. ..' .\n"+
"  .'':.: I.       . .. ..:.. .  . .. ..... .:. .:.. .:I.'.''..\n"+
"  . .:::I:.       . . .. .:. .    .. ..  . ... .:.'.'I'  .  ...\n"+
"  . ::.:I:..     . . . ....:. . .   .... ..   .:...:.:.:. ''.''\n"+
"  '.'::'I:.       . .. ....:. .     .. . ..  ..'  .'.:..:..    '\n"+
"        :. .     . .. .. .:.... .  .  .... ...   .  .:.:.:..    '.\n"+
"        :.      .  . . .. .:.... . . ........       .:.:.::. .    .\n"+
"        :. .     . . . . .. .::..:  . ..:.. .        ::.:.:.. .    .\n"+
"        :.. .    . . .  . .. ..:.:  .. .. .:. ..     ':::.::.:. .   .\n"+
"        ':.. .  . . . .. .. ...::' .. ..  . .:. .     V:I:::::.. .   :.\n"+
"         ::. .  . .. .. ... .:.::  .. .  . .. .. .     VI:I:::::..   ''B\n"+
"          :.. .   . .. ..:.. ..I:... . .  . .. ... .    VII:I:I:::. .'::\n"+
"          ':.. . . . .. ..:..:.:I:.:. .  . .. . .:. .    VHIII:I::.:..':\n"+
"           ::..   . . .. ..:..:.HI:. .      . . .... .   :HHIHIII:I::..:\n"+
"           ':. .  . .. .. ..:.:.:HI:.    . . .. ..... .   HHHHIHII:I::.'\n"+
"            :.. .  . . .. .:.:.:.HI:.      . . .. ... .   IHHHHIHHIHI:'\n"+
"             :..  .  . . .. ..:..IH:.     . . .. .. ,,, . 'HHHHHHHHI:'\n"+
"             ':..   . . .. ..:.:.:HI..   .  . .. . :::::.  MIH:\"\"\"'\n"+
"              :. . .  . .. ..::.:.VI:.     . . .. .:::'::. HIH\n"+
"               :..  .  . .. .:.:.:.V:.    . . . ...::I\"A:. HHV\n"+
"                :. .  .  . .. ..:.:.V:.     . . ....::I::'.HV:\n"+
"                 :. .  . . . .. .:..II:.  . . . ....':::' AV.'\n"+
"                  :.. . . .. ... .:..VI:. . . .. .:. ..:.AV'.\n"+
"                  ':.. . .  .. ..:.:.:HAI:.:...:.:.:.:.AII:.\n"+
"                   I:. .  .. ... .:.:.VHHII:..:.:..:A:'.:..\n"+
"                   IA..  . . .. ..:.:.:VHHHHIHIHHIHI:'.::.\n"+
"                   'HA:.  . . .. ..:.:.:HHHIHIHHHIHI:..:.\n"+
"                    HIA: .  . . .. ...:.VHHHIHIIHI::.:...\n"+
"                    HIHI:. .  .. ... .::.HHHIIHIIHI:::..\n"+
"                    HII:.:.  .  .. ... .::VHHIHI:I::.:..\n"+
"                    AI:..:..  .  . .. ..:.VHIII:I::.:. .\n"+
"                   AI:. ..:..  .  . .. ..' VHIII:I;... .\n"+
"                  AI:. .  .:.. .  .  . ...  VHIII::... .\n"+
"                .A:. .      :.. .  . .. .:.. VHII::..  .\n"+
"               A:. . .       ::. .. .. . .:.. \"VHI::.. .\n"+
"             .:.. .  .        :.. .:..... .::.. VHI:..\n"+
"            ... . .  .     . . :.:. ..:. . .::.. VI:..  .\n"+
"           .. .. .  .    . . ...:... . .. . .:::. V:..  .\n"+
"          '.. ..  .   .  .. ..:::.... .:. . ..::.. V..  .\n"+
"        . . .. . .   . . .. ..:::A. ..:. . . .::.. :..\n");


}
init()
{
	object me;
	::init();
		
	if(TP->is_player() && shield && TPRN != "shinshi")
	{
		me = find_player("shinshi");
		if(me)
			tell_object(me,HIG+"["+NORM+"SHIELD"+HIG+"]"+NORM+" " +CAP(TPRN)+" tried to enter your workroom.\n");
			destruct(this_player());
		if(TP && present(TP,TO))
			move_player(TP,"/room/void");
		return 1;
	}
	
	add_action("shield","shield");
	add_action("prevent", "prevent");
	add_action("ufo", "ufo");
}

ufo(str) {
  if(str=="track") {
    write(file_name(environment(ufo)));
    return 1;
  }
  if(str=="clone") {
    ufo = clone_object("/players/boltar/things/ufo");
    move_object(ufo,this_object());
    return 1;
  }
  if(find_player(str)) {
    ufo->move_player("up into the sky#"+file_name(environment(find_player(str)))
);
    return 1;
   }
   ufo->move_me(str);
  if(sscanf(str,"abduct %s",str)==1) {
   ufo->move_player("up into the sky#"+file_name(environment(find_player(str))))
;
   ufo->abduct(str);
   return 1;
  }
return 1;
}

prevent()
{
	object antiSMN;
	
	antiSMN = clone_object("/players/shinshi/closed/antiSMN.c");
	
	move_object(antiSMN, this_object());
	antiSMN->start_it();
	return 1;
}

shield()
{
	if(TPRN != "shinshi") return 0;
	
	if(shield)
	{
		shield = 0;
		set_short("Shinshi's Tower (open)");
		set_long("This is Shinshi's tower. Now he must remake room desc.\n\t\t\n\t\t\n");
		write("Shield off.\n");
		return 1;
	}
	
	shield = 1;
	set_short("Shinshi's Tower (closed)");
	set_long("This is Shinshi's tower. Now he must remake room desc. different desc closed\n\t\t\n\t\tShield ON\n");
	write("Shield on.\n");
	return 1;
}