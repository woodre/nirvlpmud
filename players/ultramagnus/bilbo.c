inherit "obj/monster.c";

reset(arg)
{
   object weapon;
   object armor;
   ::reset(arg);
   if(arg) return;
   set_name("bilbo");
   set_alias("hobbit");
/* Set wc moved from here. -Snow 3/00 */
   set_ac(20);
   set_level(19);
   set_al(200);
   set_hp(475);
   set_short("An Friendly Little Hobbit Dressed in Green.");
   set_long("An friendly little hobbit dressed in green.\n" + 
      "He has a small little sword at his side with the words sting\n" + 
      "printed on the scabbard\n");
weapon=clone_object("/players/ultramagnus/sting.c");
   move_object(weapon,this_object());
   command("wield sting",this_object());
   set_wc(20);
}
