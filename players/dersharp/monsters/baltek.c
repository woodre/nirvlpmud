inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("baltek");
   set_short("Baltek the Brave");
   set_long("This great fighter has come to stop the evil of the Shadow\n"+
            "Master.  However he is awfully stupid and seems stumped in this\n"+
            "room....\n");
   set_level(6);
   set_hp(90);
   set_ac(5);
   set_wc(10);
   set_al(100);
   weapon=clone_object("/players/dersharp/weapons/bsword");
   move_object(weapon,this_object());
}
