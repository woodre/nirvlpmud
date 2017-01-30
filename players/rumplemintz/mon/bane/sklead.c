inherit "obj/monster";

reset(arg)
{
   object weapon;
   ::reset(arg);
   if(arg) return;
   set_name("The Skull Leader");
   set_alias("leader");
   set_race("undead");
   set_hp(random(150)+300);
   set_al(-1000);
   set_short("The Skull Leader");
   set_long("The dreaded Skull Leader.  This is a warrior who has become one of\n"+
      "Lord Bane's sidemen.  He is skilled in the use of his sword, and does\n"+
      "not need armor.  He is strong, you have been warned.\n");
   set_wc(26);
   set_ac(15);
   set_level(18);
   set_chat_chance(10);
   load_chat("Leader says:  Listen to the walls......\n");
   load_chat("Leader says:  The walls know the way!\n");
   add_spell("ghoul","#MN# summons an $HW$undead wraith$N$ to smite you.\n",
                     "#MN# summons an $HW$undead wraith$N$ from the underground.\n",
                     20,50,"other|evil",1);
   weapon=clone_object("players/rumplemintz/weapon/skelsword");
   move_object(weapon,this_object());
   init_command("wield sword");
}
