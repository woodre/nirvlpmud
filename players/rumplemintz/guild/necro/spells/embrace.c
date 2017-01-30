#include "../defs.h"

cmd(str){
object ob;
int exp,exp2;
string file,filemsg;
ob = GOB;
  if(!ob) return 0;
  if(!ob->checklev(2,5)) return 1;
  if(!str){
    notify_fail("What would you like to embrace?\n");
    return 0;
  }
  if(str != "death"){
    notify_fail("That is not something you can embrace.\n");
    return 0;
  }
  if(tp->query_sp() < 25) { 
    notify_fail("You do not have enough spell points for this.\n"); 
    return 0; 
  }
  
  write(BOLD+BLK+"You clench your fists tightly as you begin to chant.  A soft\n"+ 
        "fog rises from the ground as you make your unholy prayer.  A loud\n"+
        "wail is heard as the fog begins to take form and you begin to see\n"+
        "figures.  Suddenly you body is flooded with the "+OFF+"spirits"+BOLD+BLK+" of a hundred\n"+ 
        "dead warriors.  They rip through your body taking pieces of your soul\n"+
        "with them.  Slowly you can feel yourself letting go.\n"+OFF);  
  exp = tp->query_exp();
  tp->raise_stamina(-1);
  file = LOG+"/DEMBRACE";
  filemsg = ctime(time())+" "+tp->query_real_name()+"  level:"+tp->query_level()+"+"+
            tp->query_extra_level()+"  guildlevel:"+tp->query_guild_rank()+"\tEXP: "+exp+"(before death)\n";
  write_file(file,filemsg);
  call_out("edeath2",2,({tp,ob,exp}));
  return 1;
}

edeath2(arg){
  arg[0]->death();
  call_out("edeath3",4,arg);
}

edeath3(arg){
int dif,dif2,exp2;
string msg;

  msg = "";  
  if(present("corpse",environment(arg[0]))){
    destruct( present("corpse",environment(arg[0])));
    arg[0]->add_exp(dif2);
    arg[1]->add_blood(10);
    arg[1]->add_skin(5);
    arg[1]->add_eye(2);
    arg[1]->add_heart(1);
    arg[1]->add_spine(1);
    arg[1]->add_val(50);
    arg[1]->save_me();
    msg += "\nThe spirits "+BOLD+BLK+"begin to rip through your corpse, removing all the\n"+
          "components and placing them in your pouch.  They whisper in your\n"+
          "ear \""+OFF+"We have taken your soul, we thank you for your sacrifice"+BOLD+BLK+"\".\n"+OFF;
  } 
  tell_object(arg[0],msg);
  call_out("edeath4",4,arg);
}

edeath4(arg){
int exp2,dif,dif2;
string msg;
string file;
string filemsg;
  msg = "\nThe spirits "+BOLD+BLK+"flood back through you, but this time pain rips through\n"+
         "you as you begin to feel a new body forming around you.\n"+OFF;
  
  
  exp2 = arg[0]->query_exp();
  dif = arg[2]-exp2;
  dif2 = (dif/4);
  arg[0]->add_exp(dif2);
  tell_object(arg[0],msg);
  move_object(clone_object(OBJ+"/misc/resurrectob.c"),arg[0]);
  command("necroresurrectme",arg[0]);
  arg[1]->add_emdeaths(1);
}
