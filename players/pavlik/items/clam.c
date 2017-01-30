int pearl;

reset(arg){
  if(arg) return;
  pearl = 0;
}

id(str){
  if(pearl == 0) return str == "clam";
  else return str == "pearl";
}

long(){
  if(pearl == 0)
    write("A strange and rather large clam.\n"+
    "Maybe you can break it open and see whats inside.\n");
  else
    write("A bright and shiny pearl.\n"+
    "This valuable stone reflects color beautifully!\n");
}

short(){
  if(pearl == 0) return "A large clam";
  else return "A shiny pearl";
}

get(){ return 1; }

query_weight(){ return 0; }

query_value(){
  if(pearl == 0) return 1;
  else return random(150)+10;
}

init(){
  add_action("openit","open");
  add_action("openit","break");
}

openit(str){
  int luck;

  if(str == "clam" || str == "open clam"){
    if(call_other(this_player(),"query_attrib","str") < 12){
      write("You are to weak to pry open the clam!\n");
      write("Why don't you go collect starfish instead?\n");
      return 1;
    }

    luck = random(call_other(this_player(),"query_attrib","luc"));

    write("You grab the clam and pry it open using all your strength!\n");
    say(capitalize(this_player()->query_name())+" grabs a clam "+
    "and pries it open using all his strength!\n");

    if(luck > 15){
      write("Inside you find a valuable pearl!!!\n");
      say("There is a pearl inside!\n");
      pearl = 1;
      return 1;
    }
    else if(luck < 2){
      write("A pod of poison gas explodes in your face!\n");
      say("A pod of poison gas explodes in his face!\n");
      this_player()->hit_player(random(50));
    }
    else {
      write("The clam is empty.\n");
      say("The clam is empty.\n");
    }
    write("The clam shell falls to the ground, forgotten.\n");
      say("The clam shell falls to the ground, forgotten.\n");
    if(pearl == 0) destruct(this_object());
    return 1;
  }
}
