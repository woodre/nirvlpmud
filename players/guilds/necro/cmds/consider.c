#include "../DEFS"

string get_comp_diff(int m,int p,string mon){
    int dif;
    string msg;
    dif = m - p;
    if(dif > 0){
	switch(dif){
	case 0..100:
	    msg = "You "+HIG+"think it would be an balanced fight.\n"+OFF;
	    break;
	case 101..400:
	    msg = mon+" looks a little bigger then yourself.\n"+OFF;
	    break;
	case 401..700:
	    msg = "It would be a tough fight.\n";
	    break;
	case 701..1100:
	    msg = "You think "+mon+" would kill you.\n";
	    break;
	default:
	    msg =  mon+HIR+" could destroy you.\n"+OFF;
	    break;                     
	}
    } else {
	dif = (dif)*(-1);
	switch(dif){
	case 0..100:
	    msg = "You "+HIG+"think it would be a balanced fight.\n"+OFF;
	    break;
	case 101..700:
	    msg = "You think it would be an easy fight.\n";
	    break;
	case 701..1100:
	    msg = "You would kill "+mon+" with out breaking a sweat.\n";
	    break;
	default:
	    msg = "You "+HIR+"think you could destroy "+mon+".\n"+OFF;
	    break;
	}
    }
    return msg;
}

int cmd(string str){
    object monster;
    string msg,mname;
    int monstercomp,mycomp;
    if(!str){
	notify_fail("Who would you like to consider?\n");
	return 0;
    }
    monster = present(str,environment(this_player()));
    if(!monster){
	notify_fail("That is not here to consider.\n");
	return 0;
    }
    if(!monster->is_npc()){
	notify_fail("You can only consider monsters.\n");
	return 0;
    }
    monstercomp = (int)monster->query_composite();
    mycomp = (int)this_player()->query_composite();
    write("You look over "+(string)monster->query_name()+".\n ");
    write(get_comp_diff(monstercomp,mycomp,(string)monster->query_name()));
    return 1; 
}
