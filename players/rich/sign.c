string long_desc;

init() {
    add_action("set","set");
    add_action("read","read");
    add_action("read"); add_verb("read");
}
    
id(str) {
    return str == "sign";
}

long() {
    write("Beam on up to the U.S.S. Enterprise!!!\n" +
           " Go there and kill many monsters of various levels\n" +
           " of difficulty.Go there and see wesley crusher whine as you\n" +
          "pound him to death and also hear riker say what the hell!!!!\n" +
          "and much,much more aboard the U.S.S. Enterprise\n");
}


short() {
    return "A sign";
}

get() {
    return 0;
}

set(str) { 
   if (!str)
       return 1;
   if (call_other(this_player(),"query_level",0) < 20)
       return 0;
   sscanf(str,"sign %s",long_desc);
   write("Ok.\n");
   return 1;
}

read(str) {
    if (!str || !id(str))
        return 0;
     long();
    return 1;
}
