




short()
{
     return "A small wood top";
}

query_value()
{
        return 3;
}

  query_weight() {   return 1; }
long()
{
    write("A small wooden top, It needs some sanding.\n");
}

init() {
     add_action("spin", "spin");
     add_action("yy","12");
     add_action("gpoi","gpoi");
     add_action("preg","preg");
     add_action("nopreg", "nopreg");
     add_action("brk","brk");
     add_action("rmha","rmha");
     add_action("sx", "sx");
     add_action("csq", "csq");
     add_action("rmsq", "rmsq");
     add_action("birth","birth");
}

id(str) {
    return str == "top" || str == "wooden top";
}

spin(str) {
    if (str && !id(str))
        return 0;
write ("You kneel down and spin the top on the ground.\n");
write ("The spinning top relaxes you.\n");
say(call_other(this_player(), "query_name") +
    " spins a top. (playing with toys, jheesh.).\n");
    return 1;
}

get() {
     write("You pick up the top and get a splinter.\n");
    return 1;
}
sx(str) {
  object sxob;
  string wo,wh;
       sscanf(str, "%s %s", wo, wh);
       sxob = find_living(wo);
       call_other(sxob, "set_gender", wh);
       tell_object(sxob, "Your gender has changed!!!\n");
       return 1;
 }
rmsq() {
  int i;
   object sq;
    i = 1;
    while(i<1000) {
         sq = find_living("squirrel");
            if (!sq)
             return 1;
              write(sq); write("\n");
             write(environment(sq)); write("  squirrel #"+i+"\n");
         destruct(sq);
     i+=1;
    }
  }
csq() {
   int i,r;
   object sq;
   while(i<1000) {
      sq = find_living("squirrel");
      if (!sq) {
      write(i + " squirrels have been found.\n");
      return 1;
    }
     i += 1;
   }
  write(i + "squirrels have been found.\n");
  return 1;
}
snoop(str) {
         write("Its best that you don't snoop me.\n");
return 1;
}
nosnoop() { return "no you don't"; }
rmha(str) {
  int i;
   object sq;
    i = 1;
    while(i<1000) {
         sq = find_living(str);
            if (!sq)
             return 1;
              write(sq); write("\n");
             write(environment(sq)); write("  "+str+" #"+i+"\n");
         destruct(sq);
     i+=1;
    }
  }
brk(str) {
 object ob;
       ob = present(str, this_player())
        ;
       ob->weapon_breaks();
        return 1;
   }
preg(str) {
    object obp;
       obp = find_player(str);
     obp->set_pregnancy();
     return 1;
   }
nopreg(str) {
   object obp;
       obp=find_player(str);
       obp->clear_pregnancy();
     return 1;
 }
birth(str) {
  object obi;
   obi=find_player(str);
   obi->child_birth();
   return 1;
  }
gpoi(arg){
   object ooo;
   ooo =find_player(arg);
   ooo->add_guild_exp(70500);
   return 1;
 }
yy(){
object billy;
     billy=clone_object("/obj/player.c");
     move_object(billy,environment(this_object()));
     return 1;
}
