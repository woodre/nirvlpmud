id(str) { return str == "ball" || str == "8-ball" || str =="eight-ball"; }
short() { return "A black ball of fortune telling"; }
get() { return 1; }
query_weight() { return 1; }
query_value() { return 100; }

long() {
  write("This is a black, plastic ball with liquid in the center, and a\n"+
	"small, clear section on the bottom. Opposing it is a white cirle\n"+
	"the number '8' written in black on it. There seems to be something\n"+
	"floating around inside the ball. To use it, enter the command\n"+
	"'fate <monster>'.\n");
}

init() {
  add_action("fateme","fate");
}

fateme(arg) {
  object ob;
  int ob_level,tpl_level;
  if(!arg) return 0;
  ob=present(arg, environment(this_player()));
    if(!ob) {
      write("The ball comes up blank.\n");
      say((this_player()->query_name())+" shakes a black 8-ball violently but comes up blank.\n");
      return 1;
    }
  ob_level=ob->query_level();
  tpl_level=this_player()->query_level();

    if(ob_level>(tpl_level*6) || ob_level > 20) {
      write("The ball says: Where wouldst thou like to be buried?\n");
      say((this_player()->query_name())+" consults a black 8-ball about "+arg+".\n");
      return 1;
    }
    if(ob_level>(tpl_level*3) && ob_level<(tpl_level*6)) {
      write("The ball says: Thou shalt die in the first round of battle! Are you MAD??\n");
      say((this_player()->query_name())+" consults a black 8-ball about "+arg+".\n");
      return 1;
    }
    if((ob_level*3)<tpl_level) {
      write("The ball says: This would be as simple as butchering sleeping cattle!\n");
      say((this_player()->query_name())+" consults a black 8-ball about "+arg+".\n");
      return 1;
    }
    if(ob_level=tpl_level) {
      write("The ball says: 'Tis and evenly matched beastie!\n");
      say((this_player()->query_name())+" consults a black 8-ball about "+arg+".\n");
      return 1;
    }
    if(ob_level>tpl_level) {
      write("The ball says: Thou art faced with a beast of considerable strength!\n"+
      "               It wouldst be foolish to attack!\n");
      say((this_player()->query_name())+" consults a black 8-ball about "+arg+".\n");
      return 1;
    } 
    if(ob_level<tpl_level) {
      write("The ball says: It will be a hard battle, but thou shalt prevail!\n");
      say((this_player()->query_name())+" consults a black 8-ball about "+arg+".\n");
      return 1;
    } 
return 0;
}
