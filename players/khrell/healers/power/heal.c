heal(str) {
    string mwho;
    int mmuch;
    if(!str) { mwho=""; mmuch = 0; }
    if(str) if(sscanf(str,"%s %d",mwho,mmuch) != 2) { mwho = str; mmuch = 0; }
	/* 06/01/06 Earwax: laf, had to add this */
    if (mmuch < 0) {
	write("Nice try scrotumbreath.\n");
	mmuch *= -1;
    }
    if(heal_var[0] > lev) return 0;
    if(lv == 0) lv = lev;
    if(lv > 40) lv = 40;    /* Added by Maledicta due to XLvl going to 100 now */
    if(pww == 0) pww = pow;
    if(query_verb() == "hp" || query_verb() == "sp") {
	call_other(POWER,"heal",lv,pww,mwho,query_verb(),mmuch);
    } else call_other(POWER,"heal",lv,pww,mwho,"heal",mmuch);
    lv = lev; pww = 0;
    return 1; }
    