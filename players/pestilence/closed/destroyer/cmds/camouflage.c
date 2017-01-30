#define TP     this_player()
#define IPTP   present("destroyer_ob", TP)
#define TPN    capitalize((string)TP->query_name())

status main(string str)
{
  /* command to hide in shadows */
  object ob;

if(this_player()->query_guild_rank() < 8){ write("You can't use this yet.\n"); return 1; }

  if (TP->query_invis() && IPTP->query_shadows())
  {
    write("You are already camouflaged.\n");
    return 1;
  }
  if (TP->query_attack())
  {
    write("You cannot camouflage while fighting.\n");
    return 1;
  } 
    if(this_player()->query_sp() < 40){
        write("You are too weak.\n");
        return 1;     }
  TP->add_spell_point(-40);
  TP->set_invs_sp();
  IPTP->add_shadows(1);
  IPTP->save_me();
  say(TPN + " disappears into the background.\n");
  write("You hide in background.\n");
  return 1;
}
