#include "/players/illarion/ansi.h"
#define COLOR "/players/illarion/obj/addcolor"
#define TP this_player() 
#define REALM(x) environment(x)->realm()
#define FAIL(x) { notify_fail(x); return 0; }
#define TP_COST 80

/* daemon for wedding ring object */


string c1(int type) {
  if(type>7 || type <0) return NORM;
  return ({HIY,HIW,HIW,HIK,HIB,HIG,HIR,HIC})[type];
}
string c2(int type) {
  if(type>7 || type <0) return NORM;
  return ({HIW,HIK,WHT,HIW,BLU,GRN,RED,CYN})[type];
}
short_description(int type,string name,string spouse) {
  switch(type) {
    default: return name+"'s wedding ring ["+spouse+"]";
    case 0: return COLOR->addcolor(name+"'s `WHITE`g`YELLOW`olde`WHITE`n`off` wedding ring ["+spouse+"]");
    case 1: return COLOR->addcolor(name+"'s `WHITE`s`off`i`BLACK`lv`off`e`WHITE`r`off` wedding ring ["+spouse+"]");
    case 2: return COLOR->addcolor(name+"'s `WHT`pl`WHITE`atin`WHT`um`off`wedding ring ["+spouse+"]");
    case 3: return COLOR->addcolor(name+"'s `BLACK`ob`WHITE`s`BLACK`id`WHITE`i`BLACK`an`off` wedding ring ["+spouse+"]");
    case 4: return COLOR->addcolor(name+"'s `blue`s`BLUE`ap`WHITE`ph`BLUE`ir`blue`e`off` wedding ring ["+spouse+"]");
    case 5: return COLOR->addcolor(name+"'s `green`e`GREEN`me`WHITE`r`GREEN`al`green`d`off` wedding ring ["+spouse+"]");
    case 6: return COLOR->addcolor(name+"'s `red`r`RED`ub`red`y`off` wedding ring ["+spouse+"]");
    case 7: return COLOR->addcolor(name+"'s wedding ring of `CYAN`i`cyan`ce`off` ["+spouse+"]");
  }
}
ring_setup(object ring) {
  string spouse,name;
  int type;
  type=ring->query_type();
  if(!this_player()) return;
  if(environment(ring)) name = environment(ring)->query_name();
  else name=this_player()->query_name();
  spouse=ring->query_spouse();
  ring->set_short(short_description(type,name,spouse?capitalize(spouse):"none"));
  ring->set_long(
"This ring symbolizes the undying love you have pledged to your mate,\n"+
(spouse?capitalize(spouse):"<none>")+".  With your love comes a few abilities, which can\n"+
"be listed with the command 'ring'.\n");
}

/* tries to send a message to str, 1 if successful, 0 if not */
ring_tell(string who,string message,object ring) {
  object obj;
  int type;
  if(!(obj=find_player(who))) return 0;
  type=ring->query_type();
  message=c1(type)+"["+c2(type)+"ring"+c1(type)+"]"+NORM+" "+format(message,70);
  tell_object(obj,message);
  obj = present("illarion_wedding_ring", obj);
  if(obj) obj->add_history(message);
  write(message);
  previous_object()->add_history(message);
  return 1;
}

/* the help screen for the ring */
display_commands() {
   write("\
ring              this message\n\
rt <msg>          send a message to your spouse\n\
rte <msg>         send an emote to your spouse\n\
rta <msg>         send an echo to your spouse\n\
rth               review your words (also rt history)\n\
rinmess [msg]     create or check your login message\n\
routmess [msg]    create or check your logout mesage\n\
rtype [msg]       change or check the appearance of your ring\n\
ring_restore      restore your spouse's lost ring\n\
ring_join         teleport to your spouse\n\
ring_summon       bring your spouse to you\n\
ring_toss         throw away your ring\n");
}
set_type(type,ring) {
  if(!type) return;
  switch(type) {
    case "gold": ring->set_type(0); break;
    case "silver": ring->set_type(1); break;
    case "platinum": ring->set_type(2); break;
    case "obsidian": ring->set_type(3); break;
    case "sapphire": ring->set_type(4); break;
    case "emerald": ring->set_type(5); break;
    case "ruby": ring->set_type(6); break;
    case "ice": ring->set_type(7); break;
    default: return;
  }
  ring_setup(ring);
}
display_types(type) {
  string *types;
  int k;
  types=explode(COLOR->addcolor("`YELLOW`gold`off`::`WHITE`silver`off`::"+
       "`WHITE`platinum`off`::`BLACK`obsidian`off`::`BLUE`sapphire`off`::"+
       "`GREEN`emerald`off`::`RED`ruby`off`::`CYAN`ice`off`"),"::");
  write("\n+-------------------+\n");
  for(k=0;k<8;k++)
    write((k==type?"(*)":"   ")+types[k]+"\n");
  write("+-------------------+\n");
  return;
}     
/* basic command for the ring */
restore_ring(spouse) {
  object sob;
  object nring;
  sob=find_player(spouse);
  if(!sob) {
    write("Your spouse must be logged in.\n");
    return 1;
  }
  nring=present("wedding ring",sob);
  if(nring) {
    write("They appear to have a ring already.\n");
    return 1;
  }
  nring=clone_object("/players/illarion/wedding/wring");
  move_object(nring,sob);
  write("You restore your spouse's ring!\n");
  tell_object(sob,"You've been given a new wedding ring.\n");
  nring->set_info(this_player()->query_real_name()+"@@@0@@@joins you in the realms of Nirvana@@@leaves you alone for now.");
  return 1;
}
ring_join(string spouse)
{
  object ob, leader;
  if(!spouse || ! (ob=find_player(spouse)))
    FAIL(capitalize(spouse)+" is not in the realms of Nirvana.\n");
  if(environment(TP) == environment(ob))
    FAIL("You are already with your spouse.\n");
  if(REALM(TP)=="NT")
    FAIL("You may not teleport from this location.\n");
  if(REALM(ob)=="NT")
    FAIL("You may not teleport to your spouse's location.\n");
  if(TP->query_spell_point() < TP_COST)
    FAIL("You lack the energy to use this ability.\n");
  TP->add_spell_point(-TP_COST);
  write("You hold onto your ring and concentrate on "+capitalize(spouse)+".\n");
  tell_room(environment(TP),TP->query_name()+" vanishes!\n", ({TP}));
  tell_room(environment(ob),TP->query_name()+" appears!\n");
  if((leader = TP->query_leader()))
  {
    TP->remove_leader(leader);
    leader->remove_follower(TP);
  }
  move_object(TP, environment(ob));
  command("look", TP);
  return 1;
}
ring_summon(spouse) {
  object ob, leader;
  if(!spouse || ! (ob=find_player(spouse)))
    FAIL(capitalize(spouse)+" is not in the realms of Nirvana.\n");
  if(environment(TP) == environment(ob))
    FAIL("You are already with your spouse.\n");
  if(REALM(TP)=="NT")
    FAIL("Your current location does not allow teleportation.\n");
  if(REALM(ob)=="NT")
    FAIL("Your spouse's location does not allow teleportation.\n");
  if(TP->query_spell_point() < TP_COST)
    FAIL("You lack the energy to use this ability.\n");
  write("You hold onto your ring and concentrate on "+capitalize(spouse)+".\n");
  tell_object(ob, "Your spouse has summoned you!\n");
  tell_room(environment(ob),ob->query_name()+" vanishes!\n", ({TP}));
  tell_room(environment(TP),ob->query_name()+" appears!\n");
  if((leader = ob->query_leader()))
  {
    ob->remove_leader(leader);
    leader->remove_follower(ob);
  }
  move_object(ob, environment(TP));
  command("look", ob);  
  return 1;
}
cmd_ring(str,spouse) {
  string verb;
  object ring;
  ring = previous_object();
  verb = query_verb();
  if(!verb) { write("no verb.\n"); return 0; }
  switch(verb) {
    case "ring": display_commands(); return 1;
    case "rth":  str = "history";
    case "rt":   if(str=="history") { previous_object()->print_history(); return 1; }
                 return str?ring_tell(spouse,TP->query_name()+": "+str,ring):0;
    case "rte":  return str?ring_tell(spouse,TP->query_name()+" "+str,ring):0;
    case "rta":  return str?ring_tell(spouse,str,ring):0;
    case "rinmess":  write("Your login message is:\n");
                     if(str) ring->set_inmess(str);
                     write(TP->query_name()+" "+ring->query_inmess()+"\n");
                     return 1;
    case "routmess": write("Your logout message is:\n");
                     if(str) ring->set_outmess(str);
                     write(TP->query_name()+" "+ring->query_outmess()+"\n");
                     return 1;
    case "rtype": if(str) set_type(str,ring);
                  display_types(ring->query_type());
                  return 1;   
    case "ring_restore": return restore_ring(spouse);
    case "ring_join": return ring_join(spouse);
    case "ring_summon": return ring_summon(spouse);
    case "ring_toss": write("You throw away your wedding ring.\n"); 
                      say(this_player()->query_name()+" throws away a wedding ring!\n");
                      destruct(previous_object());
                      return 1;
    default: return 0;
  }
}

/* sets up the ring upon login */
/* the type string can be used to setup different looks for the ring. */
startup(string spouse,string inmess) {
  object ring;
  ring=previous_object();
  if(ring_tell(spouse,TP->query_name()+" "+inmess,ring))
    write(capitalize(spouse)+" is here waiting for you.\n");
  else
    write(capitalize(spouse)+" is not here.\n");
}               
/* logout messages */
shutdown(string spouse,string outmess) {
  if(ring_tell(spouse,TP->query_name()+" "+outmess,previous_object()))
    write("You leave "+capitalize(spouse)+" all alone.\n");
}

