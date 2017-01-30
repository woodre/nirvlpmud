

inherit "/players/blackadder/room";
object melissa, armor1, armor2, weapon;
object money;

reset(arg) {
   if (!arg) {
      set_light(1);
      move_object(clone_object("/players/blackadder/bed"),this_object());
      move_object(clone_object("/players/blackadder/dresser"),this_object());
   }
   if (!melissa || !living(melissa)) {
      melissa = clone_object("obj/monster.c");
      call_other(melissa,"set_name","melissa");
      call_other(melissa,"set_short","Melissa");
      call_other(melissa,"set_long",
         "Melissa, Blackadders beautiful consort is lounging seductively\n" +
         "on the bed.  She has raven black hair, piercing blue eyes, ruby\n" +
         "red lips and large full breasts.  She is clad in leather boots\n" +
         "and a seductive studded leather jump suit.\n");
      call_other(melissa,"set_level",10);
      call_other(melissa,"set_hp",150);
      call_other(melissa,"set_ac",8);
      move_object(melissa,this_object());
      money = clone_object("obj/money");
      call_other(money,"set_money",random(50));
      move_object(money,melissa);
      call_other(melissa,"set_chat_chance",20);
      call_other(melissa,"set_a_chat_chance",33);
      call_other(melissa,"load_chat","Melissa moans softly...\n");
      call_other(melissa,"load_chat","Melissa says: Can't a girl get any rest?\n");
      call_other(melissa,"load_chat","Melissa says: Come over here baby!\n");
      call_other(melissa,"load_a_chat","Melissa screams: I'll whip your sorry ass!!!\n");
      weapon = clone_object("obj/weapon");
      call_other(weapon,"set_name","electro-whip");
      call_other(weapon,"set_short","Melissa's electro-whip");
      call_other(weapon,"set_alias","whip");
      call_other(weapon,"set_long",
         "Melissa uses this whip to turn all of you bad little boys into\n" +
         "good little mommas boys.  Shocking, isn't it?\n");
      call_other(weapon,"set_class",15);
      call_other(weapon,"set_value",150);
      call_other(weapon,"set_weight",2);
      transfer(weapon,melissa);
      call_other(melissa,"init_command","wield whip");
      armor1 = clone_object("obj/armor");
      call_other(armor1,"set_name","Thigh high leather boots");
      call_other(armor1,"set_short","Thigh high leather boots");
      call_other(armor1,"set_alias","boots");
      call_other(armor1,"set_long","Melissa's sensuous leather boots.\n");
      call_other(armor1,"set_value",150);
/* Changed from 2 to 1.  The mob isn't tough enough to have such good armor. -Feldegast 2-2-01 
   I changed this back because there are too few boots anyway, instead I increased
   the power of the mob to match the idea. -Maledicta 2-4-01  
   I considered making the mob more powerful, but I felt that the theme didn't
   justify making it a level 20 monster.  DO NOT CHANGE THIS AGAIN. -Feldegast 2-5-01
*/
      call_other(armor1,"set_ac",1);
      call_other(armor1,"set_type","boots");
      transfer(armor1,melissa);
      call_other(melissa,"init_command","wear boots");
      armor2 = clone_object("obj/armor");
      call_other(armor2,"set_name","jumpsuit");
      call_other(armor2,"set_short","A seductive studded leather jumpsuit");
      call_other(armor2,"set_alias","suit");
      call_other(armor2,"set_long","Melissa's seductive leather jumpsuit\n");
      call_other(armor2,"set_value",50);
      call_other(armor2,"set_ac",1);
      call_other(armor2,"set_type","armor");
      transfer(armor2,melissa);
      call_other(melissa,"init_command","wear jumpsuit");
      call_other(melissa,"set_ac", 8);
      call_other(melissa,"set_wc", 14);
      call_other(melissa,"set_chance", 5);
      call_other(melissa,"set_spell_dam", 5);
      call_other(melissa,"set_spell_mess1", "Melissa rips into her opponent with her whip!\n");
      call_other(melissa,"set_spell_mess2", "You cry out in pain as Melissa's whip tears into you!\n");
   }
   short_desc = "Master bedroom";
   no_castle_flag = 0;
   long_desc = 
   "This is the master bedroom.  A giant king-size waterbed stands in the\n"
   + "center of this room.  A dresser stands against the wall.  Lord Blackadder\n"
   + "shares this room with his consort Melissa and probably would not enjoy\n"
   + "being disturbed during a tender moment, so beware.\n";
   dest_dir = 
   ({
         "/players/blackadder/hall1", "west",
    });
}

query_light() {
   return 1;
}
query_room_maker() {
   return 101;
}

/*
remove the comments around the "room is modified()" code
below to prevent changes you have done to this room to
to be lost by using the room maker
*/
/*
room_is_modified() {
   return 1;
}
*/

/*
make your additions below this comment, do NOT remove this comment
--END-ROOM-MAKER-CODE--
*/

