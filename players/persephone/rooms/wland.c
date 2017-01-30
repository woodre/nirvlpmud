inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(int arg){
 if(!present("alys")){
  move_object(clone_object("players/persephone/monster/alyss"), TOB);
  }
  if (arg) return;
   set_light(1);
   short_desc="Wonderland";
   long_desc="You are standing in a beautiful grassy area next to a young\n" +
             "girl who seems to be crying. Darting around your feet are many\n" +
             "small squirrels chattering and surounding you is perhaps\n" +
             "the most beautiful garden you have ever seen. It worries you however\n" +
             "that you do not know how to leave here even though you feel that\n" +
             "you never want to, perhaps wishing might work\n" +
             "\n";
   items=({"grass","The grass is green and has recently been cut. There is a scrap\n" +
                   "of paper on the grass",
           "squirrels","They are grey squirrels and seem to be minding their own business",
           "garden","The garden is stunning it is filled with roses, carnations,\n" +
                    "daffodils just to name a few and their flowers fill the air\n" +
                    "with a beautiful scent",
           "flowers","The flowers are really wonderful",
           "roses","These are the most spectacular rosebushes you have ever seen.\n",
                   "Wait a second isn't one of the roses the illusive blue rose?\n" +
                   "It is, that rosebush must be worth a fortune",
           "carnations","You are simply stunned by the beauty of these carnations\n" +
                       "they are so colourful",
           "daffodils","The daffodils are Yellow what do you expect",
           "sky","The sky is crystal clear and totally blue with only the slightes whisp\n" +
                 "of cloud to be seen",
           "cloud","The cloud seems to take the shape of a dragon most odd",
           "dragon","Where is the dragon, you must be imagining things you can only\n" +
                    "see some clouds floating across the sky",
           "paper","There seems to be something written on the paper perhaps\n" +
                   "you should read the note",
        });
}
realm() { return "NT"; }
init(){
 ::init();
  add_action("read1","read",);
  add_action("read1","peruse");
  add_action("take1","take",);
  add_action("take1","get");
  add_action("dream1","dream");
  add_action("dream1","leave");
  add_action("dream1","wish");
  add_action("smell1","smell");
  add_action("pick","pick");
}
read1(str){
 if(str=="paper" || str=="note" || str=="writing"){
  write("\n" +
        "                        Having trouble leaving wonderland\n" +
        "                        try typing dream. \n" +
        "                        PS. Suggestions as to what you\n" +
        "                        would like to see would be appreciated\n" +
        "\n");
  say(CAPTPLNM + " reads a note");
  return 1;
 }
 write("what are you trying to read\n");
 return 1;
}
take1(str){
 if (str=="rose"){
  write("You recieve a nasty prick from trying to pick a rose and have to stop\n");
  say(CAPTPLNM + " pricks himself on a rose thorn and screams loudly\n");
  return 1;
 }
 else if (str=="flowers" || str=="flower" || str=="carnations" || str=="daffodils"){
  write("You cannot bring yourself to pick the flowers\n");
  say(CAPTPLNM + " thinks about picking the flowers but decides against it.\n");
  return 1;
 }
 else if(str=="paper" || str=="note"){
  write("The piece of blows out of your reach.\n");
  say(CAPTPLNM + " tries to take a piece of paper but it keeps blowing away.\n");
  return 1;
 }
}
smell1(str){
 if(str=="flowers" || str=="flower" || str=="carnations" || str=="daffodils"){
  write("You smell the heady aroma of carnationations and daffodils.\n");
  say(CAPTPLNM + " smells the carnations and daffodils\n");
  return 1;
 }
 else if(str=="rose" || str=="roses"){
  write ("You start to smell the heady aroma of the roses you wish you had\n" +
         "roses like these.\n");
  say(CAPTPLNM + " starts sniffing the roses");
  return 1;
 }
}
dream1(str){
 if (str=="mirror" || str=="out" || str=="home"){
  write("You start to doze off dreaming sweet dreams");
  TPL->move_player("dreaming about mirrors#" + "players/persephone/rooms/junpath4");
  return 1;
 }
 write("You try to dream but mirrors keep coming into you thoughts maybe you\n" +
       "should dream about mirrors");
 say(CAPTPLNM + " goes to sleep but looks extremely restless");
 return 1;
}
pick(arg){
 if(!arg){
  write("Alyss is to alert to let you steal her posessions after she lost\n" +
        "her pills\n\n");
  say(CAPTPLNM + " tries to steal something from Alyss but fails badly\n\n");
 return 1;
 }
 if(arg){
  write("Alyss is to alert to let you steal her posessions after she lost\n" +
        "her pills\n\n");
  say(CAPTPLNM + " tries to steal something from Alyss but fails badly\n\n");
 return 1;
 }
}
