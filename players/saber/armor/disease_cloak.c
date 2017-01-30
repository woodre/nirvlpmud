inherit "obj/armor";
object player, disease;

reset(arg){
   ::reset(arg);
   set_name("cloak");
   set_short("A cloak of sickly black and green");
   set_alias("disease cloak");
   set_long("An sickly black and green cloak of detailed workmanship.\n"+
            "It is covered with many small unholy symbols of Arate.\n");
   set_type("cloak");
   set_ac(2);
   set_weight(1);
   set_value(1000);
   set_save_flag(1);
   call_out("disease_check",120);
}

disease_check()  {
  player = environment(this_object());
  
  if(player()->is_player())  {
   if(!present("flu", player))  {
    if(present("no_disease", player))  {
      tell_room(player, 
                "You feel your resistance to disease begin to weaken.\n");
      disease = present("no_disease", player);
      destruct(disease);
          }
     
    tell_room(player, "You begin to feel sick.\n");
    disease = clone_object("/players/saber/closed/virus/flu.c");
    move_object(disease, player);
    call_out("disease_check", 250);
    return 1;
          }
        }
  call_out("disease_check", 250);
  return 1;
          }
