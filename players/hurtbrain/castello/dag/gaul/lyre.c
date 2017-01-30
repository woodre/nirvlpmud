
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("lyre");
        set_short("A lyre of a bard") ;
        set_long("This is a lyre. You can try to play it.\n") ;
        set_weight(2) ;
        set_value(1500);
        set_class(18) ;
}

init(){
 ::init();
    add_action("play","play");
}

play(str)   {

        if((str) && (str=="lyre"))  {
                write("What a bad sound! This lyre is out of tune!\n");
                say(this_player()->query_name()+" plays a out of tune lyre.\n");
                return 1;
                }
}

