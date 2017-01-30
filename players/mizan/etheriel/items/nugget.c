#define MASTER_R "/players/mizan/closed/FishnuggetDM.c"
int thawstate;

id(str) { return str == "nuggets" || str == "nugget" || str == "fishnugget"; }

short() {
  if(thawstate >= 100) return "A frozen fishnugget";
  else if(thawstate < 100 && thawstate >= 50) return "A fishnugget";
  else if(thawstate < 50) return "A soggy fishnugget";
}

long() {
  write("This is a chunk of... FISH!\n"+
  "It appears to be kosher.\n");
}

get() { return 1; }

reset(arg) {
  if(!arg) thawstate = 150;
  remove_call_out("fake_beat");
  call_out("fake_beat", 1);
}

init() {
  add_action("eatme","eat");
}

fake_beat() {
  thawstate --;
  if(1 == random(30)) MASTER_R->fishnugget_emote(this_object());  
  if(!thawstate) destruct(this_object());
  if(1 == random(50)) {
    say("A fishnugget explodes violently!\n");
    destruct(this_object());
    return 1;
  }

  remove_call_out("fake_beat");
  call_out("fake_beat", 1);
}

eatme(str) {
  if(!str || !id(str) || environment() != this_player()) return 0;
  if(thawstate >= 100) {
    write("You would only break your teeth if you did that.\n");
    say((this_player()->query_name()) + " contemplates the nutritional value of a frozen fishnugget.\n");
    return 1;
  } else if(thawstate >= 50 && thawstate < 100) {
    write("You gobble up a fishnugget.\n"+
    "Surprisingly It tastes like... fish.\n");
    say((this_player()->query_name()) + " gobbles up a fishnugget.\n");
    this_player()->heal_self(1);
    destruct(this_object());
    return 1;
  } else if(thawstate < 50) {
    write("You attempt to eat a soggy, crusty fishnugget.\n"+
    "You puke on your shoes and hurl the crummy-tasting thing into oblivion.\n"+
    "That was pretty slick.\n");
    say((this_player()->query_name()) + " tries to eat a soggy fishnugget but spews its remains\n"+
    " clear across the room in disgust.\n");
    destruct(this_object());
    return 1;
  }

}
