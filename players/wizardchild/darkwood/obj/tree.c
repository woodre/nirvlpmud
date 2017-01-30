/* tree.c: tree at the end of the trail */
/* likely to host castle expansion later on */
short() { return "An enormous looming tree"; }
long()  { 
  write("A large tree of some unidentifyable type, looming high above your head.\n");
  write("The base of the tree alone is larger than anything you've ever seen before,\n");
  write("with enormous gnarled roots sprouting out of the ground in some places.\n");
  return 1;    
}
id(str) { return str == "tree" || str == "looming tree"; }
