#include "/players/wocket/closed/ansi.h"
int covered;

id(str){ return (str == "wocket" || str == "statue"); }
short(){ if(!covered)
         return ("A statue covered in "+HIG+"ivy"+OFF);
         return "A copper statue of "+HIG+"Wocket"+OFF; }

get(){ return 0; }
long(){
  if(!covered){
    write("A statue covered in ivy.  You may want to 'uncover' it.\n");
  }
  else{
    write("   A large copper statue of the great wizard Wocket.  There\n"+
      "is a small boy, about age 10, looking back at the small creature\n"+
      "that is emerging from his pocket grinning.  The creature is\n"+
      "small and furry with a mane of green hair and a tuft of yellow fur\n"+
      "upon its head.  As legend has it he stood one day looking out upon\n"+
      "the land seeing nothing but bickering and decay throughout.\n"+
      "Hopelessness ruled as his world fell into oblivion.  Seeing no\n"+
      "way to resolve the problems, he cast himself within this statue\n"+
      "to be awakened when the land has healed itself.  When balance\n"+
      "and peace have again been restored to Nirvana.  Tarnish covers\n"+
      "the ornate statue.\n"+
      "      There is a small plaque at the base you can 'read'.\n");
  }
  return 1;
}

init(){ 
  add_action("uncover","uncover");
  add_action("read_me","read");
}

uncover(str){
  if(!str || str != "statue"){
    notify_fail("What would you like to uncover?\n");
    return 0;
  }
  say(this_player()->query_name()+" uncovers the statue\n");
  write("You clear the ivy off of the statue revealing a copper sculpture\n"+
        "of Wocket.\n");
  covered = 1;
  init();
  return 1;
}
read_me(str){
  if(!str || str != "plaque"){
    notify_fail("What would you like to read?\n");
    return 0;
  }
  say(this_player()->query_name()+" reads the plaque.\n");
  write("The plaque reads:\n\n"+
        "\t\tNow Wocket is Wocket,\n"+
        "\t\the fits in my pocket\n"+
        "\t\tand cuddles up close\n"+
        "\t\tto my leg,  Then when\n"+
        "\t\tit gets cold, my leg\n"+
        "\t\the does hold, but more\n"+
        "\t\toh for more I do beg.\n"+
        "\n"+
        "\t\tFor Wocket oh Wocket\n"+
        "\t\twho fits in my pocket,\n"+
        "\t\tyour love is for what\n"+
        "\t\tI do crave.  To hold\n"+
        "\t\tyou at night and to\n"+
        "\t\tsnuggle up tight, in\n"+
        "\t\tyour warm arms till\n"+
        "\t\tthe end.\n"+
        "\n"+
        "\t\tTo most this sounds\n"+
        "\t\todd, a bunny whos bod,\n"+
        "\t\tshe wants to devote to\n"+
        "\t\ta Wocket.  But Wockets\n"+
        "\t\tnot odd, for Wockets\n"+
        "\t\thot bod, would tear\n"+
        "\t\tthrough -your- heart\n"+
        "\t\tlike a rocket.\n"+
        "\t\t    - Melanie (HunyBunny)\n\n");     
  return 1; 
}