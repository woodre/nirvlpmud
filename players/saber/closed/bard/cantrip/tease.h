/* A cantrip which may cause a monster to attack the bard */
               
tease(str)  {
object CANTRIP_TARG;
string PNAME;
int CANTRIP_INT;

  if(!INSTR->query_cantrip("C26"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  if(!str)  {
    write("Who do you want to taunt?\n");
    return 1;
        }

  if(!(CANTRIP_TARG = present(str, ENV)))  {
    write("There is no "+capitalize(str)+" here to tease.\n");
    return 1;
        }
  
  if(spell(-50,0,5) == -1)  return 0;
  
  if(CANTRIP_TARG->is_player())  {
    write("\nOh, come on.  If you're going to tease a player, at least come up with\n"+
          "your own insulting lines.\n");
    return 1;
        }

  CANTRIP_INT = random(3);
  PNAME = CANTRIP_TARG->query_name();
  
  write("\nYou say \""+PNAME+", ");
  say("\n"+tp+" says \""+PNAME+", ");

  if(CANTRIP_INT == 0)  {
    tell_room(ENV, "I've seen broken mugs that look better then your face.\"\n");
        }
  if(CANTRIP_INT == 1)  {
    tell_room(ENV, "last time I saw anything like you, I pinned a tail on it.\"\n");
        }
  if(CANTRIP_INT == 2)  {
    tell_room(ENV, "may Crysea have more mercy on your soul then she did your face.\"\n");
        }

  CANTRIP_INT = TP->query_attrib("int");
  
  if(random(CANTRIP_INT) > random(30))  {
    tell_room(environment(TP), "\n"+CAP+" screams in rage and rushes "+tp+".\n\n");
    if(living(CANTRIP_TARG))  CANTRIP_TARG->attack_object(this_player());
         }

  call_other(TP, "add_spell_point", -5);
  return 1;
        }
