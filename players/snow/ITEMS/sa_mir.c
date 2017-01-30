id(str) { return str == "mirror"; }

short() { return "A crystal mirror"; }

long() { 
  write(
"A beautiful crystal mirror. 'gaze into mirror' to see a reflection...\n");
  }

init() {
  add_action("gaze","gaze");
  }

gaze(str) {
  if( str == "into mirror") {
if(this_player()->query_real_name() == "sapphire") {
  write(
"As you gaze into the mirror you see an image of a beautiful young woman\n"+
"from Oregon. Your luxurious tresses of hair fall gracefully about your \n"+
"face. Your piercing eyes are enough to stun and seduce any man.\n"+"\n"+
"Snow thinks you are beautiful.\n");
return 1;
    }
  write(
"As you gaze into the mirror you see your reflection...\n"+"\n");
write(this_player()->long()+"\n"+"You are reasonably attractive.\n");
return 1;
  }
}
