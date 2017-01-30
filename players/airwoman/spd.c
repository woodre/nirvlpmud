inherit "obj/monster";
 
reset(arg){
::reset(arg);
if(arg) return;
set_name("spud");
set_level(10);
set_hp(200);
set_whimpy(150);
set_al(200);
set_ac(8);
set_wc(14);
set_short("spud");
set_long("HERE'S Bud!  It's what u asked for wasnt it?\n"+
        "or was that Bud light?\n");
    set_object(this_object());
 
        set_function("bud");
        set_type("bud");
        set_match(" ");
 
        set_function("light");    
        set_type("light");
        set_match(" ");
}
 
bud(str) {
    string a, b;
    object bud1;
       if (sscanf(str, "%sbud%s", a, b)==2 ||
            sscanf(str, "%sBud%s", a, b)==2 ||
            sscanf(str, "%sBUD%s", a, b)==2)
        {
        if (sscanf(str, "%sbud light%s", a, b)==2 ||
        sscanf(str, "%sbud lite%s", a, b)==2)
        {move_object(clone_object("/players/airwoman/beer"), this_player());
        say("A bud light flies to "+ this_player()->query_name()+"\n");
        write("A bud light flies to your hand\n");
        }
        else {
        if (!present("bud")) {
          move_object(clone_object("/players/airwoman/bud"), 
this_room());
        say("Bud appears in a flash!\n");
        write("You see Bud appear in a flash!\n");
 
        }
        }
 
}
 
}
light(str) {
        string a, b;
        if (sscanf(str, "%sbud light%s", a, b)==2 ||
        sscanf(str, "%bud lite%s", a, b)==2)
        {return;}
        else
        {
        if(sscanf(str, "%slight%s", a, b)==2 ||
        sscanf(str, "%slite%s", a, b)==2)
        {
        move_object(clone_object("/players/airwoman/flash"), this_player());
say("A flash light flies to "+this_player()->query_name()+"'s hand."+"\n");
        write("A flash light flies to your hand\n");
 }
  }                         
  }      
