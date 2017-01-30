
inherit "obj/weapon";
init() {
     add_action("wield","wield");
     add_action("stopwield","unwield");
     add_action("read","read");
}
reset(arg) {
   ::reset(arg);
if(arg) return;
      set_short("Rush Limbaugh's book");
      set_name("book");
      set_alias("rbook");
      set_long("This is Rush Limbaugh's book, 'The way things ought to be' \n");
      set_value(1000);
      set_weight(3);
      set_class(10);
      set_hit_func(this_object());
      set_short("Rush Limbaugh's book");
}
weapon_hit() {
    object att;
    string at,str1,str2;
      att=call_other(this_player(),"query_attack",0);
      at=file_name(att);
    write(at + "\n");
        sscanf(at,"%s#%s",str1,str2);
        write(str1);
        if(str1=="players/haji/rush/char/bill") {
        write("Bill cringes in terror as you read words from Rush's book!\n");
        write("Kapow!!!\n");
      att=0;
      at=0;
    return 20;
   }
  }
read(str) {
    if(str=="book") {
         write("This is the great book by Rush Limbaugh, 'The way things ought to be.\n");
         write("You open the book and begin reading.\n");
         write("To help you on your quest for the golden microphone.\n");
         write("You will need to get the four components for the key to the\n");
         write("safe in which the golden microphone is stored.\n");
         write("However, this will not be easy to accomplish without certain\n");
         write("other accessories.  \n");
         write("First of all you will need a book of great advice to protect you\n");
         write("from the evil influence of the head liberal.\n");
         write("\nSecond, you will need sound advice from a great leader from\n");
         write("the past in order to protect you from the third most powerful\n");
         write("liberal of them all.\n");
         write("\nThird, you will need the proper weapon to protect you from\n");
         write("those that cater to these liberals.\n");
         write("Fourth, you will need to have a sign to protect you from the\n");
         write("the one who represents change in one our oldest institutions.\n");
         write("\nAfter you have all the neccesary components.\n");
         write("You will need to assemble the key parts in order and find the safe.\n");
         return 1;
      }

  return 1;
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
