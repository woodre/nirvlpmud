mass_heal(str) {
    string mtype;
    int mmuch;
    if(mass_heal_var[0] > lev) return 0;
    if(!str) { mtype="heal"; mmuch = 0; }
    if(str) if(sscanf(str,"%s %d",mtype,mmuch) != 2) {
	    if(str == "hp" || str == "sp") { mtype = str; mmuch = 0; }
	    else { mtype = "heal"; sscanf(str,"%d",mmuch); }
	}
    if(pww == 0) pww = pow; if(lv == 0) lv = lev;
    if(lv > 40) lv = 40;
    call_other(POWER,"mass_heal",lv,pww,mass_p,mtype,mmuch);
    pww = lv = 0;
    return 1; }
    