cure(str) { if(cure_var[0] > lev) return 0; call_other(POWER,"cure",lev,pow,str); return 1; }
