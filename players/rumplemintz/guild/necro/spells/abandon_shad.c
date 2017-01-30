#include <ansi.h>
int time;
object quick;

string get_msg(){
    object ob;
    ob = quick;
    switch(random(7)){
    case 0:  return ob->query_name()+BOLD+BLK+" kneels to the ground as depression sets in.\n"+OFF;
    case 1:  return ob->query_name()+BOLD+BLK+" lowers "+ob->query_possessive()+" weapon.\n"+OFF;
    case 2:  return ob->query_name()+BOLD+BLK+" is over come by past memories of sadness.\n"+OFF;
    case 3:  return ob->query_name()+BOLD+BLK+" lowers "+ob->query_possessive()+" head, giving up the fight.\n"+OFF;
    case 4:  return ob->query_name()+BOLD+BLK+" looks very depressed.\n"+OFF;
    case 5:  return ob->query_name()+BOLD+BLK+" tries to attack you but fails as "+ob->query_pronoun()+" abandons all hope.\n"+OFF;
    case 6:  return BOLD+BLK+"Gloom hovers above "+OFF+ob->query_name()+BOLD+BLK+" as the will to fight leaves "+ob->query_possessive()+".\n"+OFF;
    }
}

void quickshad_on(){
    shadow(quick, 1);
}

int quickshad_off(){
    shadow(quick, 0);
    destruct(this_object());
    return 1;
}

int query_rescued(){ return 1; }
string short(){
    return quick->short()+" (depressed)";
}

void attacked_by(object ob){
    tell_room(environment(quick), get_msg());
    time--;
    quick->stop_fight();
    quick->stop_fight();
    if(time < 0){
	tell_room(environment(quick),HIR+quick->query_name()+" regains the will to fight!\n"+OFF);
	quickshad_off();
    }
}

void attack_object(){
}

int set_monster(object mon, int i){
    if(!mon)
	return 0;
    quick = mon;
    quickshad_on();
    time = i;
    return 1;
}

int query_cursed(string str){
    if(str == "abandoned") 
	return 1; 
    return 0;
}
/* incorrect formatting on these functions
   ghetto fix by illarion on 2 dec 2004 */
int do_damage(int *i){
    int s, tot;
    s=sizeof(i);
    while(s--)
	tot += i[s];
    call_out("hurtme",0,tot);
    quick->stop_fight();
    quick->stop_fight();
    return tot;
}

int hit_player(int i, object t, int i2, object t2){
    call_out("hurtme",0,i+i2);
    quick->stop_fight();
    quick->stop_fight();
    return i+i2;
}

void hurtme(int i){
    quick->heal_self(-i);
}

int query_prevent_shadow(){ return 1; }
