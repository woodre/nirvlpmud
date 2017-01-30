/*  the Fallen Lands - demon curse   
    Version:  4.0     Updated: 11.1.99        
*/

/* Added new function so that can use one to check all
 * Rumplemintz - Dec-05-2009
 */
#include "/players/zeus/closed/all.h"
#define FLDH "/players/zeus/closed/fl_demon.c"

n_dir(){   if(FLDH->check_demon(TP))  return 1; }
s_dir(){   if(FLDH->check_demon(TP))  return 1;}
e_dir(){   if(FLDH->check_demon(TP))  return 1;}
w_dir(){   if(FLDH->check_demon(TP))  return 1;}
nw_dir(){  if(FLDH->check_demon(TP))  return 1;}
ne_dir(){  if(FLDH->check_demon(TP))  return 1;}
se_dir(){  if(FLDH->check_demon(TP))  return 1;}
sw_dir(){  if(FLDH->check_demon(TP))  return 1;}
u_dir(){   if(FLDH->check_demon(TP))  return 1;}
d_dir(){   if(FLDH->check_demon(TP))  return 1;}

dir_check(){ if(FLDH->check_demon(TP)) return 1; }
