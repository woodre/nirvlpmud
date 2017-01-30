
heart_beat(){

if(change==1){
 change=0;
 write("Change off\n");
/* Reverse all of wc/ac/hp/sp to normal.  probably a call out */
return; }
if(change>1){
 change--;
return; }

if(fury==1){
 fury=0;
 tell_object(environment(TO),"Fury off\n");
 furytimer=50;
/* Reverse all of wc/ac/hp/sp to normal, chk for change.  turn furytimer on */
return; }
if(fury>1){
 fury--;
return; }

if(furytimer==1){
 furytimer=0;
 write("fury able again\n");
/* */
return; }
if(furytimer>1){
 furytimer--;
return; }

if(meld==1){
 meld=0;
 tell_object(environment(TO),"Meld off\n");
 meldtimer=50;
 meldlvl=0;
/* Reverse all of wc/ac/hp/sp to normal, chk for change.  turn meldtimer on */
return; }
if(meld>1){
 meld--;
return; }

if(meldtimer==1){
 meldtimer=0;
 tell_object(environment(TO),"Meld able again\n");
/* */
return; }
if(meldtimer>1){
 meldtimer--;
return; }

if(stunned==1){
 stunned=0;
 tell_object(environment(TO),"no longer stunned\n");
/* */
return; }
if(stunned>1){
 stunned--;
return; }


}