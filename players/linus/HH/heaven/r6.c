/* room 6 */

#include "/players/linus/HH/hdefs.h"

inherit "/players/linus/HH/heaven/main.c";

short() { return HIW + "Amongst the clouds" + NORM; }

reset(arg) {
 if(!arg);
 set_light(2);
 custom_exits = 1;
 long_desc = HIW +
"  Soft clouds hover inches above the soft ground.  A few bright rays\n"+
"of light carve their way through the clouds above.  A light mist hangs\n"+
"in the air, glistening in the bright light.  Soft harp music resonates\n"+

"off of the clouds, providing a sense of peace and tranquility.\n\n" + NORM;
 items = ({
 "clouds","Soft pillows of moisture suspended in the air",
 "cloud","A soft pillow of moisture suspended in the air",
 "mist","Moisture suspended in the air",
 "pillows","Soft pillows of moisture suspended in the air",
 "pillow","A soft pilow of moisture suspended in the air",
 "ground","Soft to the touch and obscured by clouds of mist",
 "rays","Beams of light",
 "ray","A beam of light",
 "beam","Bright light",
 });
call_out("make_some_noise",1+random(25));
}

make_some_noise() {
 say("Some clouds gently float through the sky...\n");
  call_out("make_some_noise",50);
}
