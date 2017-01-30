/*
Revised by Feldegast 12-24-01.
It now reduces wear, with a random chance of breaking and a random chance of enhancing the weapon.
*/

inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
   set_hp(180);
   set_name("smith");
   set_alias("smith");
   set_short("A Weapon Smith");
   set_ac(9);
   set_wc(16);
   set_al(142);
   set_long("This is Joe, the Weapon smith.\nAsk him to <sharpen> <weapon>.\n");
   set_level(12);
   set_chat_chance(40);
   load_chat("Smith says:  Careful now, if it is too good of a weapon it might break.\n");
   load_chat("Smith looks around briefly.\n");
   load_chat("Smith says:  So have you seen the weapon out on the island?\n");
   load_chat("Smith says:  Hard to believe they allow such powerful weapons out there!\n");
   load_chat("Smith sighs.\n");

}

/*break*/
init()
{
  add_action("sharpen","sharpen");
}

sharpen(str) {
   object weapon;
   int old_class;
   int old_value;
   string a, b;

   if(this_player()->query_money() < 800) {
     write("You do not have 800 coins.\n");
     return 1;
   }

   weapon = present(str, this_player());
   if (!weapon) {
      write("You don't have "+str+" with you.\n");
      return 1;
   }

   if (living(weapon)) {
      write("He tries but fails to sharpen it.\n");
      return 1;
   }

   old_class = weapon->weapon_class();
   old_value = weapon->query_value();

   if (!old_class) {
      write("Smith says: I can't do anything with THAT.\n");
      return 1;
   }

   if(weapon->query_broke())
   {
     write("Smith says: I can't do anything with that.  Its broken!\n");
     return 1;
   }

   if (sscanf(weapon->short(),"%swield%s",a,b) == 2)
      command("unwield "+weapon->query_name(), this_player());

   if(!random(8))
   {
      destruct(weapon);
      write("The weapon crumbles to powder under the incompetent blacksmith's ministrations.\n"+
            "Smith says: Oops!\n");
      return 1;
   }

   write("The weapon smith repairs and hones your weapon.\n");
   tell_room(environment(this_player()),"The weapon smith sharpens "+weapon->short()+".\n", ({ this_player() }));

   weapon->set_hits(0);
   weapon->set_misses(0);

   this_player()->add_money(-800);

   if (this_player()->query_attrib("luc") > random(200) && old_class < 20 && !present("blessing", weapon) ) 
   {
      weapon->set_class(old_class + 1);
      move_object(clone_object("players/bern/guild/blessing"), weapon);
      write("The "+weapon->short()+" looks better than ever.\n");
   }
   return 1;
}

