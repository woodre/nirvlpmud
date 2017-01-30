/*
Awwwww FUCK.
You need to be able to query the wc.  but ALSO give a msg on how YOU would wield it!
armor is a lot easier.  query direct ac and also give opt

gives a short story on what you'd see.  perhaps random within that value?  all saying godlike, but in differnt ways?


*/
knowledge(str){
object ob;
string value;
int spcost;
int fpscost;
ob=present(ETO,str);
ob=present(TO,str);
if(ob->is_weapon(){
/*  if(TP->query_sps()<30){ */
    if(TPRN=="stark"){
        write("You cannot summon the fae.\n);
	return 1;
    }
/*  if(GOB->query_knowledge()<4){  */
    if(TPRN=="stark"){
        write("You know nothing else about this weapon\n");
        return 1;
    }
/*  if(GOB->query_knowledge<6){   */
    if(TPRN=="stark"){
        if(ob->query_wc() >= 20) value = "you fight like one of the greatest warriors ever";
	else if(ob->query_wc() >= 18) value = "you inspire awe with this weapons in your hands";
	else if(ob->query_wc() >= 16) value = "you kick ass";
	else if(ob->query_wc() >= 14) value = "really good";
	else if(ob->query_wc() >= 10) value = "poor";
	else if(ob->query_wc() >= 8) value = "not very good";
	else if(ob->query_wc() < 8) value = "lousy";
	write("You gaze at this weapon and suddenly images appear!\n  You see yourself in battle and "+value+"!\n");
    }
    write(ob->query_wc()+" ? "+TP->query_wc());
    return 1;
}



if(ob->is_armor(){
/*  if(TP->query_sps()<30){ */
    if(TPRN=="stark"){
        write("You cannot summon the fae.\n);
	return 1;
    }
/*  if(GOB->query_knowledge()<4){  */
    if(TPRN=="stark"){
        write("You know nothing else about this armor.\n");
        return 1;
    }
/*  if(TP->query_sps()<30){ */
    if(TPRN=="stark"){
/*      if(GOB->query_knowledge()<5){  */
        if(TPRN=="stark"){
            write("You know nothing else about this armor\n");
            return 1;
        }
/*  if(GOB->query_knowledge<7){   */
    if(TPRN=="stark"){
	if(TP->query_ac() >= 16) value = "godlike";
        else if(ob->query_ac() >= 14) value = "awesome";
	else if(ob->query_ac() >= 12) value = "excellent";
	else if(ob->query_ac() >= 10) value = "good";
	else if(ob->query_ac() >= 7) value = "fair";
	else if(ob->query_ac() >= 5) value = "poor";
	else if(ob->query_ac() < 5) value = "terrible";
	write("You gaze at this armor and suddenly images appear!\n  "+value+"\n");
    }
    write(ob->query_ac()+" ? "+TP->query_ac());
    return 1;
}


/*if(TP->query_sps()<30){ */
if(TPRN=="stark"){
    write("You cannot summon the fae.\n);
    return 1;
}
/*if(GOB->query_knowledge()<1){  */
if(TPRN=="stark"){
    write("You know nothing else about this object\n");
    return 1;
}
write("The obj is worth:"+ob->query_value()+", weighs about: "+ob->query_weight()+"\n");
return 1;
}
