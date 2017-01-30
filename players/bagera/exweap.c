
inherit "obj/weapon";
init() {
     add_action("wield","wield");
     add_action("stopwield","unwield");
}
reset(arg) {
   ::reset(arg);
if(arg) return;
set_short("Tiger's Claws");
      set_name("claws");
      set_alias("claws");
set_long("These are the claws of a massive tiger. The claws are jagged\n"+
"and are outstretched. They are three inches in length and their razor\n"+
"sharpness will slice through your opponent with ease.\n");
      set_value(1000);
      set_weight(1);
      set_class(17);
      set_hit_func(this_object());
set_short("Tiger Claws");
}
weapon_hit() {
    object att;
    string at,str1,str2;
      att=call_other(this_player(),"query_attack",0);
      at=file_name(att);
    write(at + "\n");
        sscanf(at,"%s#%s",str1,str2);
        write(str1);
      att=0;
      at=0;
    return 20;
   }
wield(str) {
    if (!id(str))
        return 0;
    if (environment() != this_player()) {
        /* write("You must get it first!\n"); */
        return 0;
    }
    if (wielded) {
        write("You already wield it!\n");
        return 1;
    }
    if(wield_func)
        if(!call_other(wield_func,"wield",this_object())) 
            return 1;
    wielded_by = this_player();
    call_other(this_player(), "wield", this_object());
    wielded = 1;
    return 1;
}
stopwield() {
   call_other(this_player(), "stop_wielding");
wielded = 0;
wielded_by = 0;
return 1;
}
