
init(){

      add_action("shout_in");       add_verb("shout");
      add_action("tell_in");        add_verb("tell");
}


id(str){

      return str = "silencer";
}
shout_in(){

   return 1;
}


tell_in(){

    return 1;
}
remove(i){
    int n;

    n = 0;
    n = i;

      if(n==1)
        destruct(this_object());
      return 1;
}
