#include "/players/jaraxle/ansi.h"
#define PATH "players/jaraxle/3rd/warrior/mercs/merc_daemon"

string *names;

static string *taken;

int *xp;



reset(arg){

 if(arg) return;

 xp = ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, });

 names = ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, });

 taken = ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, });

 restore_object(PATH);

}



list_squires(){

  int i;

  string woot;

i = 0;
woot = "";
  while(i < sizeof(names)){

woot += (i + 1)+""+GRN+"]"+NORM+" ";

    if(!names[i] && !taken[i]) names[i] = "/players/jaraxle/closed/names"->get_female_name();

    if(names[i] == 0){ woot += pad("Unavailable", 14);
   }

    else woot += pad(names[i], 14);

    woot += xp[i] +"\n\t";

    i++;

    } 

save_object(PATH);

return woot;

}



query_names(){ return names; }

query_xp(){ return xp; }

query_taken(){ return taken; }



get_squire(int i, object ob){

   int numero;

   object squire;

   numero = i - 1;

   if(taken[numero] != 0){

    tell_object(ob, "That Mercenary has been hired.\n");

    return 1;

    }

if(ob->query_money() < 10000){
write(
"The server looks at you slightly embarrased and says,\n"+  
"                   'I'm sorry good sir, but you do not have enough money'\n"+  
"                   'to hire a squire.'\n");  
return 1; }  
  


if(member_array(ob->query_real_name(),  taken) >= 0){

    tell_object(ob, "You have already hired a Mercenary today.\n");

    return 1;

    }

   if(names[numero] == 0){

    names[numero] = "/players/jaraxle/closed/names"->get_female_name();

    }

   squire = clone_object("/players/jaraxle/3rd/warrior/mercs/squire.c");
   move_object(squire, environment(ob));

squire->set_name(names[numero]);
   squire->set_alias(names[numero]);
   squire->set_short(names[numero]+", Mercenary");

   squire->set_xp(xp[numero]);

   squire->set_owner(ob);

   squire->set_spot(numero);

call_other(ob, "add_money", -40000);
   names[numero] = 0;

   xp[numero] = 0;

   taken[numero] = ob->query_real_name();


   save_object(PATH);

   return 1;

   }



set_mercenary_xp(int oldspot, int newxp){

   xp[oldspot] = newxp;

   save_object(PATH);

   }

set_mercenary_name(int oldspot, string oldname){

   names[oldspot] = oldname;

   save_object(PATH);

   }

set_not_taken(int oldspot){  

   taken[oldspot] = 0;

   }

