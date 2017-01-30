inherit "room/room";
#include "definitions.h"

string oldphase, month, phase, where;
object city;


init()
{ 
  add_action("readmap","readmap");
  if ((this_player()->query_real_name() == "dune") ||
      (this_player()->query_level() >= 200) )
  {
    add_action("forcephase","forcephase");
    add_action("history", "history");
  }
  ::init();
}


reset(arg)
{

  moon_sequence();

  if (!present("dial"))
    move_object(clone_object(CASTLEOBJECT+"/moondial.c"), this_object());

  if (!arg)
  {
    set_light(1);
    short_desc=("The Moonshrine");
    long_desc=
"                                .       .   . .          \n"+
"        . .                  .    * . . .  .  +   .      \n"+
"            +      .           .   .      +              \n"+
"                            .       . +  .+. .           \n"+
"  .                      .     . + .  . .     .      .   \n"+
"           .      .    .     . .   . . .                 \n"+
"      *             .    . .  +    .  .           .      \n"+
"          .     .    .  +   . .  *  .       .            \n"+
"               . + .  .  .  .. +  .                      \n"+
".      .  .  .  *   .  *  . +..  .            *          \n"+
" .      .   . .   .   .   . .  +   .    .            +   \n"+
"     The Moonshrine stands gazing towards the stars. Its thin walls\n"+
"and pillars are made of smooth blue-white marble. The side walls are\n"+
"latticed in intricate designs. Above you, the huge roof displays the\n"+
"complete starmap of the Lothlorien moon phases. Upon the ground,\n"+
"miniature versions of seven cities lie in a circle. As the light outside\n"+
"pierces through the latticed walls, a sort of pattern emerges.\n";

    dest_dir=({
CASTLEROOM+"/green11.c","leave"  ,
            });

    items=({
"starmap","     There are six phases of the Lothlorien moons\n"+
          "Dark            Waxing Crescent        Waxing Gibbous\n"+
          "Full            Waning Gibbous         Waning Crescent\n"+
          "Type 'readmap' to see what the current month and phase are",
"phases", "     The phases are all displayed on the starmap",
"cities", "     They lie in a circle",
"walls",  "     The walls are of laced stone",
"pattern","     Somehow the Sithi Cities are connected to the\n"+
          "phases of the moon",
    });
  }
}


moon_sequence()
{
  int tyme, digit, phasenum, monthnum;
/* Following added for LD fix, makes this easier on LP as well
 * --Rumplemintz    11-Dec-2009
 */
  string tymestr;  /* Time converted into a str */
  string cut_tymestr; /* tymestr cut to last 6 digits */
  int newtyme;     /* cut_tymestr converted back into int */

  /* get the current time in seconds, since 1970 */
  tyme = time();

/* My way of getting the correct value without the while statements below
 */
  tymestr = "blah";
  tymestr += tyme;

#ifndef __LDMUD__
  cut_tymestr = tymestr[-6..-1];
#else
  cut_tymestr = tymestr[<6..<1];
#endif
  newtyme = atoi(cut_tymestr);

  /* reduce it to the last 288 hours */
/* -- Rumplemintz - Dec-11-2009
  while(tyme > 10000000000) tyme -= 10000000000;
  while(tyme > 1000000000) tyme -= 1000000000;
  while(tyme > 100000000) tyme -= 100000000;
  while(tyme > 10000000) tyme -= 10000000;
  while(tyme > 1036800) tyme -= 1036800;
  tyme = tyme / 3600;
*/

  tyme = newtyme / 3600;

  /* monthnum in a range of 0 to 288 hours */
  monthnum = tyme;

  switch(monthnum) {  /* months change every 24 hours */
    case 0..24:      month = "jonever";   digit = 0; break;
    case 25..48:     month = "feyever";   digit = 24; break;
    case 49..72:     month = "marris";    digit = 48; break;
    case 73..96:     month = "avrel";     digit = 72; break;
    case 97..120:    month = "maia";      digit = 96; break;
    case 121..144:   month = "yuven";     digit = 120; break;
    case 145..168:   month = "tiyagar";   digit = 144; break;
    case 169..192:   month = "anitul";    digit = 168; break;
    case 193..216:   month = "septander"; digit = 192; break;
    case 217..240:   month = "octander";  digit = 216; break;
    case 241..264:   month = "novander";  digit = 240; break;
    case 265..288:   month = "decander";  digit = 264; break;
  }

  phasenum = monthnum - digit;
  /* phasenum in a range of 0 to 24 hours */
  switch(phasenum) {   /* phases change every 4 hours */
    case 0..4:     phase = "full";            break;
    case 5..8:     phase = "waning gibbous";  break;
    case 9..12:    phase = "waning crescent"; break;
    case 13..16:   phase = "dark";            break;
    case 17..20:   phase = "waxing crescent"; break;
    case 21..24:   phase = "waxing gibbous";  break;
  }

  if (phase != oldphase)
  {
    say("Rays of light poking through the walls slowly change direction.\n");
    if (city)
    {
      tell_room(environment(city), city->short()+" has shifted out of phase.\n");
      destruct(city);
    }
    say("You hear a loud rumble over your head as the starmap rotates.\n");
    oldphase = phase;
    switch(phase)
    {
      case "full": 
          city = clone_object(CASTLEOBJECT+"/jao_e-tinukaii.c");                           
          break;
      case "waning gibbous":     
          city = clone_object(CASTLEOBJECT+"/hikehikayo.c");
          break;
      case "waning crescent":    
          city = clone_object(CASTLEOBJECT+"/daai_chikiza.c");
          break;
      case "dark":               
          city = clone_object(CASTLEOBJECT+"/mezutua.c");
          break;
      case "waxing crescent":    
          city = clone_object(CASTLEOBJECT+"/kementari.c");
          break;
      case "waxing gibbous":     
          city = clone_object(CASTLEOBJECT+"/tumetai.c");                       
          break;
    }
    where = randomly_locate(city);
  }
  call_out("moon_sequence", 300);
  return 1; 
}


string randomly_locate(object ob)
{
  int rnd;
  string placed;
  rnd = random(12) + 1;
  switch(rnd)
  {
    case 1:   move_object(ob, CASTLEROOM+"/tempent.c");  placed  = "tempent";  break;
    case 2:   move_object(ob, CASTLEROOM+"/bush.c");     placed  = "bush";     break;
    case 3:   move_object(ob, CASTLEROOM+"/2east.c");    placed  = "2east";    break;
    case 4:   move_object(ob, CASTLEROOM+"/1sw2.c");     placed  = "1sw2";     break;
    case 5:   move_object(ob, CASTLEROOM+"/brown2.c");   placed  = "brown2";   break;
    case 6:   move_object(ob, CASTLEROOM+"/brown4.c");   placed  = "brown4";   break;
    case 7:   move_object(ob, CASTLEROOM+"/brown8.c");   placed  = "brown8";   break;
    case 8:   move_object(ob, CASTLEROOM+"/brown1.c");   placed  = "brown1";   break;
    case 9:   move_object(ob, CASTLEROOM+"/hill4.c");    placed  = "hill4";    break;
    case 10:  move_object(ob, CASTLEROOM+"/hill5.c");    placed  = "hill5";    break;
    case 11:  move_object(ob, CASTLEROOM+"/hill9.c");    placed  = "hill9";    break;
    case 12:  move_object(ob, CASTLEROOM+"/outdoor2.c"); placed  = "outdoor2"; break;
  }
  return placed; 
}


string query_phase() { return phase; } /* let other objects find out what */
string query_month() { return month; } /* phase and month it is */


forcephase()
{
  say(TPN+" tinkers with a few of the Moon Shrine levers and gears.\n");
  write("Jumpstarting Lothlorien moon phase sequence.\n");
  moon_sequence(); 
  return 1; 
}


history()
{
  write("Current phase of moon: "+phase+".\n");
  write("Current month: "+month+".\n");
  if (city)
    if (city->short()) write("Current city: "+city->short()+".\n");
  write("Current place: "+where+".\n");
  return 1;
}


readmap()
{
  say(TPN+" studies the Starmap.\n");
  write("~~~~~Lothlorien Moon Dial~~~~~\n");
  write("It is "+CAP(month)+" and the moon is "+CAP(phase)+".\n");
  return 1;
}
