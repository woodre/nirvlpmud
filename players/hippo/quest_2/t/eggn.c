#define ENVTO environment(this_object())
string name;
string newname;

id(str) {
   if(str==name||str=="egg"||str=="nucleus") return 1;
   return 0;
}
reset(arg) {
  if(!arg) {
     newname="egg";
      name="egg nucleus";
  }
  return;
}
long() {
   if(name=="complete egg nucleus") {
   write("This is a complete egg nucleus, ready to be fertilized.\n"+
      "Of course, a male sperm cell is needed to prevent this\n"+
      "cell from starving unutilized.");
   } else {
   write("This nucleus is the main part of a female egg cell.\n"+
      "However, it's far from functional yet. Before this\n"+
      "cell and a spermatocyte can melt into each other,\n"+
      "a lot of functional structures have to be added.\n");
   }
}
short() { return name; }
get() { return 1; }
drop() { return 0; }
value() { return 0; }
init() {
  add_action("add","add");
}
add(arg) {
   string obj, obj2, dump, rlobj, objnewname;
   int tmp;
   if(!arg) return 0;
   tmp=sscanf(arg,"%s to %s",obj,obj2);
   if (tmp!=2) {
      write("What do you wanna add to what?");
      return 1;
   }
   if(present(obj,ENVTO)==this_object()) { rlobj=obj; } 
   else { rlobj=obj2; }
   if(present(rlobj,ENVTO)) {
      write("That is not here.\n");
      return 1;
   }
   else {
     if(rlobj=="chromosome"||rlobj=="chromosomes") {
       write ("ok, I'll add "+rlobj+" to the egg nucleus.\n");
       destruct(present(rlobj,ENVTO));
       tmp=sscanf(rlobj,"%shromoso%s",objnewname,dump);
       newname=objnewname+newname;
       if(newname=="22 cegg") 
           name="egg nucleus with 22 chromosomes";
       if(newname=="x cegg") 
          name="egg nucleus with x chromosome";
       if(newname=="x c22 cegg"||newname=="22 cx cegg")
          name="complete egg nucleus";
     }
     else
       write("Impossible, inappropriate and silly action.");
   }
   return 1;
}
