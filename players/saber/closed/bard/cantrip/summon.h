/* This cantrip will summon a small 3 hp (no xp) animal.  The animal is
   NOT under the control of the caster */

summon(str)  {
int CANTRIP_INT;
object CANTRIP_TARG;

  if(spell(-50,0,15) ==-1) return 0;
  
  if(!INSTR->query_cantrip("C25"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  CANTRIP_INT = random(5);
  
  if(CANTRIP_INT == 0)  {
    CANTRIP_TARG = clone_object("/players/saber/closed/bard/mon/kitten.c");  
        }
  if(CANTRIP_INT == 1)  {
    CANTRIP_TARG = clone_object("/players/saber/closed/bard/mon/spider.c");
        }
  if(CANTRIP_INT > 1)  {
    CANTRIP_TARG = clone_object("obj/monster");
    CANTRIP_TARG->set_level(1);
    CANTRIP_TARG->set_hp(3);
    CANTRIP_TARG->set_ep(1);
    CANTRIP_TARG->set_wc(4);
    CANTRIP_TARG->set_ac(5);
    CANTRIP_TARG->set_alias("summoned");
        }
  if(CANTRIP_INT == 2)  {
    CANTRIP_TARG->set_name("fly");
    CANTRIP_TARG->set_race("insect");
    CANTRIP_TARG->set_short("A tiny fly");
    CANTRIP_TARG->set_long("A tiny fly buzzing around the room.\n");
    CANTRIP_TARG->set_ac(40);
    CANTRIP_TARG->set_wc(2);
    CANTRIP_TARG->set_chat_chance(10);
    CANTRIP_TARG->set_a_chat_chance(10);
    CANTRIP_TARG->load_chat("Bzzzzzzzzzzzzzzzz.\n");
    CANTRIP_TARG->load_a_chat("Bzzzzzzzzzzzzzzzz.\n");
         }
  if(CANTRIP_INT == 3)  {
    CANTRIP_TARG->set_name("rat");
    CANTRIP_TARG->set_race("rodent");
    CANTRIP_TARG->set_short("A black rat");
    CANTRIP_TARG->set_long("A black rat.\n");
    CANTRIP_TARG->set_chat_chance(5);
    CANTRIP_TARG->set_a_chat_chance(5);
    CANTRIP_TARG->load_chat("The rat runs across the floor.\n");
    CANTRIP_TARG->load_chat("The rat looks up at you.\n");
    CANTRIP_TARG->load_chat("The rat sniffs at your foot.\n");
    CANTRIP_TARG->load_a_chat("The rat squeeeeeks in terror!\n");
         }
  if(CANTRIP_INT == 4)  {
    CANTRIP_TARG->set_name("mouse");
    CANTRIP_TARG->set_race("rodent");
    CANTRIP_TARG->set_short("A small white mouse");
    CANTRIP_TARG->set_long("A small white mouse with red eyes.\n");
    CANTRIP_TARG->set_chat_chance(5);
    CANTRIP_TARG->set_a_chat_chance(5);
    CANTRIP_TARG->load_chat("The mouse runs across the floor.\n");
    CANTRIP_TARG->load_chat("The mouse looks up at you.\n");
    CANTRIP_TARG->load_chat("The mouse squeeks.\n");
    CANTRIP_TARG->load_a_chat("The mouse runs across the floor!\n");
         }

  write("\nYou trace a minor "+BOLD+"rune of summoning"+NORM+".\n");
  say("\n"+tp+" traces a minor "+BOLD+"rune of summoning"+NORM+".\n");
  tell_room(ENV,
    CANTRIP_TARG->short()+" appears in a puff of smoke.\n");
  
  move_object(CANTRIP_TARG, ENV);  

  call_other(TP,"add_spell_point",-15);
  return 1;
        }
