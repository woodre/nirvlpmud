inherit "/players/illarion/room";
#include "/players/illarion/dfns.h"
int shields;
status lights;
string song;
void change_item(string item,string new_desc);

reset(arg) {
  if(arg) return;

  lights=1;
  set_light(1);
  set_short("Illarion's Bedroom");
  set_long(
"This large, quiet tower chamber is where Illarion retreats when his work is "+
"done.  "+
"At the north end of the room is a large fireplace, with a bright fire "+
"burning within, and a long ornate mantle above.  To either side of the "+
"fireplace are floor to ceiling bookshelves, almost completely covered with "+
"books.  Opposite the fireplace a large wrougt-iron bedframe supports a "+
"bed draped with a black comforter and sheets, and overhung by a deep blue "+
"canopy.  To either side of the bed is a table with a lamp on it, and at "+
"the foot of the bed sits a large chest with a padded seat atop it.  On the "+
"east side of the room a chest of drawers and a mirror flank a small door "+
"to the bathroom, and to the west a large picture window with a double seat "+
"looks out toward where the sun sets.  On the floor is a soft, deep carpet, "+
"and a small crystal chandelier hangs above the spiral staircase that leads "+
"to the level below.");

   add_item("shields",
     "The shields protect the room from unwated guests.");
   add_item("fireplace",
     "Carefully fit and mortared fieldstone makes up the fireplace, with a "+
     "poker and shovel to one side and a bin for logs to the other.");
   add_item("fire",
     "A fire burns brightly within the fireplace, giving off cheerful light "+
     "and welcome warmth.");
   add_item("staircase","The spiral staircase leaving down is made of iron "+
         "fashioned into the form of a huge, blooming flower, with the steps "+
         "descending down the stem.");
   add_item("mantlepiece",
     "A solid oak mantle with a few keepsakes on top of it, and a long, "+
     "slightly curved blade hanging above it, half out of its sheath.");
   add_item("blade",
     "A truly beautiful weapon, almost ancient but as sound as the day "+
     "it was forged.  The hilt is wrapped in black and blue strained "+
     "leather, and the sheath is embriodered beautifully.");
   add_item("bookshelves",
     "Bookshelves made of smoothed and varnished black oak, solid, yet "+
     "necessary to carry the great weight of books put upon them.  Almost "+
     "hidden among the books is a compact but powerful stereo and a "+
     "small but well-stocked bar.");
   add_item("stereo",
     "A small combination of tape deck, CD-player, and control panel are "+
     "visible in the bookshelf.  The speakers and other peripherals "+
      "are hidden in the walls.  $&stereo_string$&");
   add_item( "bar",
      "A deceptively small bar that somehow always seems to have what you "+
      "want when you reach for something.");
   add_item( "books",
      "The printed word is obviously a great vice of Illarion's; the books "+
      "here range from instructions to magic to love stories to the great "+
      "epics of the Greeks.");
   add_item( "bedframe",
      "The bedframe of shiny wrought iron brings to mind the spires of a "+
      "palace, although it does not soar quite so much.  Surely iron is more "+
      "for show than strength, who would need an iron bed?");
   add_item( "bed",
      "The bed looks to be even bigger than a king-size, although "+
      "that may be due to the pillows and blankets piled on top of it, and "+
      "the huge canopy draped above it.");
   add_item( "canopy",
      "A canopy of deep, royal blue, hanging over the bed light a night sky.");
   add_item( "blankets",
      "Soft downy blankets, but inexplicably, they are midnight black.");
   add_item( "sheets",
      "Soft sheets of the finest satin, of a black so deep that with "+
      "stars they could be in the night sky.");
   add_item( "tables",
      "Small bedside tables of black oak, with a single drawer each and a "+
      "peculiar lamp atop them.");
   add_item( "lamps",
      "The lamps are a single crystal atop a beautifully swirled obsidian "+
      "stand, and when touched glow with a soft, warm light.");
   add_item( "chest",
      "There are two chests in the room, a chest of drawers and a floor "+
      "chest.");
   add_item( "floor chest",
      "A large, very solid chest of black oak, with a soft seat on the "+
      "top if sitting on the bed isn't appropriate.");
   add_item( "seat",
      "A soft, down-filled cushion of a soft grey color, just large enough "+
      "for two.");
   add_item( "chest of drawers",
      "A black oak chest of drawers, large, with a small amount of personal "+
      "clutter atop it.  The handles on the drawers are silver, carved into "+
      "the shape of dragon heads.");
   add_item( "handle",
      "Fanciful dragons of all styles decorate the drawers of the chest.");
   add_item( "door",
      "A small but well made door leading to the bathroom.");
   add_item( "window",
      "A huge picture window with glass so clear you could swear it was "+
      "not really there.  Dark blue draperies frame it.");
   add_item( "carpet",
      "A soft, deep carpet, shot through with all kinds of patterns.  A "+
      "single pattern in the middle catches your eye.");
   add_item( "pattern",
      "A large golden pattern in the middle of the carpet somehow gives "+
      "you the impression of Illarion's study.");
   add_item( "chandelier",
      "A silver chandelier hung with beatiful crystals, each of which can "+
      "glow softly with its own light.");

  add_exit("down","players/illarion/workroom");
  add_exit("east","/players/illarion/tower/bathroom");
}
init() {
  ::init();
  if(this_player()->query_real_name()=="illarion")
    add_action("cmd_shields","shields");
  add_action("cmd_play","play");
  add_action("cmd_stop","stop");
  add_action("cmd_lights","lights");
  if(shields && TP->query_real_name()!="illarion" &&
    TP->query_level()<100) {
    write("Please ask permission first.\n");
    move_object(TP,"/room/church");
  }
}
stereo_string() {
  if(!song)
     return "It is silent, but it would be easy to "+BLD("play")+
            "something.";
  else
     return "The speakers are playing "+song+".  You can "+BLD("stop")+
            "them or "+BLD("play")+" something else.\n";
}

cmd_shields() {
  write(
"You "+((shields=!shields)?"raise":"lower")+" the shields.\n");
  return 1;
}
long(string str) {
  ::long(str);
  if(!str) 
    write("The "+CYN+"shields"+NORM+" are "+CYN+(shields?BOLD+"up":"down")
      +NORM+".\n");
}
cmd_play(string str) {
  if(!str) FAIL("Play what?\n");
  if(!song) {
    write("You turn on the stereo, and start it playing "+str+".\n");
    say(TPN+" fiddles with the stereo, and it starts playing "+str+".\n");
    song=str;
  } else {
    if(str==song) {
      write("The stereo would apear to already be playing that.\n");
      say(TPN+" fiddles with the stereo, but nothing happens.\n");
    } else {
      write("You stop the stereo, and start it playing "+str+".\n");
      say(TPN+" stops the stereo, and starts it playing "+str+".\n");
      song=str;
    }
  }
  return 1;
}
cmd_stop(string str) {
  if(!str || (str != "stereo" && str != "speakers")) FAIL("Stop what?\n");
  if(!song) {
    write("It isn't playing anything.\n");
    say(TPN+" fiddles with the stereo, but nothing happens.\n");
  } else {
    write("You stop the stereo.\n");
    say(TPN+" stops the stereo.\n");
    song=0;
  }
  return 1;
}
short() {
  return (shields?HIC+"[":"")+CYN+"Illarion's Bedroom"+(shields?HIC+"]":"")+
    NORM;
}
status cmd_lights() {
  lights=!lights;
  set_light(lights?1:-1);
  write("You turn the lights "+(lights?"on":"off")+".\n");
  say(TPN+" turns the lights "+(lights?"on":"off")+".\n");
  return 1;
}
