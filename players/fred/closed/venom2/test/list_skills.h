list_skills(){
string *arr_control;
string *arr_combat;
string *arr_creation;
int i,j,k;
arr_control = ({ "Cleanse", "Absorbi", "Burnoff", "Gtitle", "Heal",
                 "Regeneration" });
arr_combat = ({ "Wep", "Darts", "Fatal", "KO", "-----", "Hypermode" });
arr_creation = ({ "ShapeArmor", "Alarm", "Camouflage", "Spikes", "CreateItem",
                  "CreateBall" });

write(COLOR+"Control:"+NORM+"\n");
for(i = 0; i < control; i ++){
if(i == 4) write("\n");
write("L"+(i+1)+"["+HIG+arr_control[i]+NORM+"] ");
 }
write("\n\n");
write(COLOR+"Combat:"+NORM+"\n");
for(j = 0; j < combat; j++){
if(j == 4) write("\n");
write("L"+(j+1)+"["+HIR+arr_combat[j]+NORM+"] ");
 }
write("\n\n");
write(COLOR+"Creation:"+NORM+"\n");
for(k = 0; k < creation; k++){
if(k == 4) write("\n");
write("L"+(k+1)+"["+HIB+arr_creation[k]+NORM+"] ");
 }
write("\n\n");
write(COLOR+"Control/Combat:"+NORM+"\n");
if(control > 2 && combat > 2) write("L3/3["+HIY+"Feed"+NORM+"] ");
if(control > 4 && combat > 4) write("L5/5["+HIY+"Suffocate"+NORM+"] ");
write("\n\n");
write(COLOR+"Creation/Combat:"+NORM+"\n");
if(creation > 4 && combat > 4) write("L5/5["+HIY+"Block"+NORM+"] ");
if(creation > 5 && combat > 5) write("L6/6["+HIY+"Dominate"+NORM+"] ");
write("\n\n");
write(COLOR+"Level Based Skills and Abilities:"+NORM+"\n");
write("Level 1  - ["+HIM+"Threat"+NORM+"]  ["+HIM+"Absorb"+NORM+"]");
write("  ["+HIM+"Wield"+NORM+"] ["+HIM+"Tentacles"+NORM+"]\n");
if(glvl > 15){
write("level 16 - ["+HIM+"Lair"+NORM+"]\n"); /* ["+HIM+"Recruit"+NORM+"]\n"); */
}
write("\n");
write(COLOR+"Other Skills and Abilities:"+NORM+"\n");
write("[mp] [sc] [ssave] [convert] [raise_skill] [setcolor]\n");
write("[pklist]\n");
write(NORM+"For additional help on any topic type '"+HIB+"link <name>"+NORM+"' No caps.\n\n");
return 1;
}

