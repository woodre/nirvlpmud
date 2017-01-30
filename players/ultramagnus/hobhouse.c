/* Added the out() function so players could leave this thing. -Snow 3/00 */
id(str) {return str == "hobhouse" ;}
short() {return "A Small Hobbit House" ;}
long() {write("A beautiful house with a green color.\n");
	write("It seems that it is inhabited...\n");}
get() {return 0;}
drop() {return 1;}

init() {
  add_action("out","out"); }

out() { this_player()->move_player("out#players/ultramagnus/hobvil1.c"); return 1; }
