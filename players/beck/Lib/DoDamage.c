#define WIZZ 20
mapping Armors;
int HitPoint;

void 
RegisterArmor(object gear, mixed *params){
   if(Armors == 0){ Armors = ([ ]); }
   Armors[gear] = params;
}

status
RemoveArmor(object gear){
   if(Armors == 0){ Armors = ([ ]); }
   if(!Armors[gear]) return 0;
   Armors[gear] = 0;
   return 1;
}

QHitPoint(){ return HitPoint; }
SHitPoint(int num){ HitPoint = num; }
AHitPoint(int num){ HitPoint += num; }

int
DoDamage(int *damage, string *method){
   int i, j, k;
   string type;
   int dam, total, class, res, temp, itemp;
   string cat,subcat;
   mixed *armors2;
   object *armors;
   
   /***********************************/
   /*  BEGIN ADDITIONS FOR MULTIPLE   */
   /*  TYPES OF DEFENSE               */
   /*  Coded by Beck                  */
   /***********************************/
   if(!damage) return 0;
   for(i=0; i<sizeof(damage); i++){
      if(damage[i]){
         dam = damage[i];
         class = 0;
         res = 0;
         if(method){
            if(method[i]){
               type = method[i];
               if(sscanf(type, "%s|%s",cat,subcat) !=2){
                  if(type != "physical" && type != "magical") type = "physical";
               }
               else if(cat != "other") type = "physical";
            }
            else type = "physical";
         }
         else type = "physical";
         /* Add in individual object modifications from mapping Objects */
            if(Armors){
            armors = keys(Armors);
            for(k=0; k<sizeof(armors); k++){
               if(Armors[armors[k]]){
                  armors2 = Armors[armors[k]];
                  itemp = member_array(type,armors2);
                  if(itemp != -1){
                     class += armors2[itemp+1];
                     res += armors2[itemp+2];
                     if(armors2[itemp+3]){
                        temp = (int) call_other(armors[k],armors2[itemp+3]);
                        res += temp/100;
                        class += temp - ((temp/100)*100);  
                     }
                  }     
                }
               }
         }
         if(res > 100) res = 100;
         /* Calculate new damage */
         res = 100 - res;
         dam = res*dam;
         dam = dam/100;
         dam -= random(class + 1);
         total += dam;  
tell_object(player, "Type: "+type+" Dam: "+dam+" Res: "+(100-res)+"\n");
       }
      
   }
if(!player->is_player() && total > 50)
total = 30 + random(20);
   if (total <= 0)
      return 0;
   HitPoint = (int)player->query_hp();
   HitPoint -= total;   
   player->add_hit_point(-total);
   if(HitPoint < 0) {
      player->hit_player(3000);
      /*
      this_object()->Died();
      */
      if(!this_object()->is_player())
         destruct(this_object());
   }
   return total;
}

