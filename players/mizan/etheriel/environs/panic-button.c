id(str) { return str == "button"; }
short() { return "A panic button"; }
long() {
  write("This is a purple-striped button suspended in nowhere in particular\n"+
	"that you can push to escape this realm. A voice in your head tells\n"+
	"you not to push this button because you would be a weakling. Another\n"+
	"voice tells you to push it so you can escape further torture of this\n"+
	"strange area.\n");
}

init() {
  add_action("push","push");
}

push(str) {
  if(!str || str != "button") return 0;
  write("Ok.\nBOOM!!!\n\n");
  this_player()->move_player("panic#room/wild1");
  return 1;
}
