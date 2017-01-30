string sender,msg;
reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="rose") return 1;
        return 0;
}

long() {
        write( "This is a wonderful dark red rose, it has large scarlet petals and stinging\n"+
               "thorns meaning the two faces of Love. Maybe if you <smell> it you would learn\n"+
               "more.\n"+

               "A small piece of paper hangs from a thorn, you could <read> it or <write> \n"+
               "something on it.\n");
}

short()
  { return "A scarlet rose"; }
init()
{
  add_action( "smell","smell");
  add_action( "re","read");
  add_action( "writ","write");
}
smell(arg)
{ if(arg!="rose") return;
  write("You smell the rose and immediately an intense perfume delights your nose and\n"+
        "inebriates your body.\n");
  return 1;
}
re(arg)
{ writ("              I love you!!!!!!!!!!!");
  read(arg);
  return 1;
}
read(arg)
{ if(arg!="paper") return;
  if(!msg) { write("There are no messages written on the paper.\n"); return 1; }
  write(msg+"\n");
  return 1;
}
writ(arg)
{ if(!arg) { write("What do you want to write on the paper?\n"); return 1; }
  sender=capitalize(call_other(this_player(),"query_real_name"));
  msg="You read the paper and a message for you from "+sender+" says:\n"+arg;
  return 1;
}

get() {
        return 1;
}
drop() {
        return 0;
}
