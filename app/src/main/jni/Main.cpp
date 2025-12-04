#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include "Includes/Logger.h"
#include "Includes/Utils.h"
#include "KittyMemory/MemoryPatch.h"
#include "And64InlineHook/And64InlineHook.hpp"
#include "Menu.h"

const char* targetLibName = "libUE4.so";

#include "Includes/Macros.h"

struct My_Patches {
 MemoryPatch 
 Aim,
 PickupWeaponVisible,
 ShopAlwaysVisible,
 NoRecoilCtoshair,
 UnlimitedCliP,
 NoDead,
 CurrentTimeRound,
 Ammo,
 SmallCrosshair,
 AntiFlashBang,
 UnlimitedMoney,
 AManHit,
 UAnimMontage,
 USkinEditorWidget,
 SpawnPlayerCameraManager,
 UpdateCameraManager,
 FastLobby,
 AutoFireWeapons,
 FreezeMoney,
 NoGravity,
 SpeedHack,
 AddBan,
 CheckBan,
 CheckBan_Response,
 IHackProperty,
 HACK_ForceToFront;
 
} hexPatches;
bool Aim,
 PickupWeaponVisible,
 ShopAlwaysVisible,
 NoRecoilCtoshair,
 UnlimitedCliP,
 NoDead,
 CurrentTimeRound,
 Ammo,
 SmallCrosshair,
 AntiFlashBang,
 UnlimitedMoney,
 AManHit,
 UAnimMontage,
 USkinEditorWidget,
 SpawnPlayerCameraManager,
 UpdateCameraManager,
 FastLobby,
 AutoFireWeapons,
 FreezeMoney,
 NoGravity,
 SpeedHack,
 AddBan,
 CheckBan,
 CheckBan_Response,
 IHackProperty,
 HACK_ForceToFront;
 
void *hack_thread(void *) {
    LOGI(("Carregando..."));

    ProcMap il2cppMap;
    do {
        il2cppMap = KittyMemory::getLibraryMap("libUE4.so");

        sleep(1);
    } while (!il2cppMap.isValid());
    
hexPatches.Aim = MemoryPatch::createWithHex("libUE4.so",0x028c1fec,"0000A0E31EFF2FE1"); //1
hexPatches.PickupWeaponVisible = MemoryPatch::createWithHex("libUE4.so",0x028abe50,"0100A0E31EFF2FE1"); //2
hexPatches.ShopAlwaysVisible = MemoryPatch::createWithHex("libUE4.so",0x028abda8,"0100A0E31EFF2FE1"); //3
hexPatches.NoRecoilCtoshair = MemoryPatch::createWithHex("libUE4.so",0x028c4694,"0000A0E31EFF2FE1"); //4
hexPatches.UnlimitedCliP = MemoryPatch::createWithHex("libUE4.so",0x02906f54,"0201E0E31EFF2FE1"); //5
//soat kill
hexPatches.NoDead = MemoryPatch::createWithHex("libUE4.so",0x028fa4ac,"0201E0E31EFF2FE1"); //6
hexPatches.CurrentTimeRound = MemoryPatch::createWithHex("libUE4.so",0x028ad880,"0201E0E31EFF2FE1"); //7

//oqi pistolet
hexPatches.Ammo = MemoryPatch::createWithHex("libUE4.so",0x02906f3c,"0201E0E31EFF2FE1"); //8
//money и т.д
hexPatches.SmallCrosshair = MemoryPatch::createWithHex("libUE4.so",0x028c3884,"0100A0E31EFF2FE1"); //9
hexPatches.AntiFlashBang = MemoryPatch::createWithHex("libUE4.so",0x028a310c,"0100A0E31EFF2FE1"); //10
hexPatches.UnlimitedMoney = MemoryPatch::createWithHex("libUE4.so",0x02948fcc,"0201E0E31EFF2FE1"); //11
//паронат немемури
hexPatches.AManHit = MemoryPatch::createWithHex("libUE4.so",0x028bb618,"0100A0E31EFF2FE1"); //12

hexPatches.UAnimMontage = MemoryPatch::createWithHex("libUE4.so",0x028c30e4,"0000A0E31EFF2FE1"); //13
hexPatches.USkinEditorWidget = MemoryPatch::createWithHex("libUE4.so",0x0292104c,"0000A0E31EFF2FE1"); //14
hexPatches.SpawnPlayerCameraManager = MemoryPatch::createWithHex("libUE4.so",0x040fb0c8,"0100A0E31EFF2FE1"); //15
hexPatches.UpdateCameraManager = MemoryPatch::createWithHex("libUE4.so",0x04105db8,"0100A0E31EFF2FE1"); //16
//FastLobby
hexPatches.FastLobby = MemoryPatch::createWithHex("libUE4.so",0x028e6c4c,"0000A0E31EFF2FE1"); //17
hexPatches.AutoFireWeapons = MemoryPatch::createWithHex("libUE4.so",0x02930558,"1EFF2FE1"); //18

hexPatches.FreezeMoney = MemoryPatch::createWithHex("libUE4.so",0x028c6b18,"1EFF2FE1"); //19
hexPatches.NoGravity = MemoryPatch::createWithHex("libUE4.so",0x03cbf7f8,"0100A0E31EFF2FE1"); //20
hexPatches.SpeedHack = MemoryPatch::createWithHex("libUE4.so",0x03cbf81c,"0100A0E31EFF2FE1"); //21
//Antiban
hexPatches.AddBan = MemoryPatch::createWithHex("libUE4.so",0x02882278,"1EFF2FE1");//22
hexPatches.CheckBan = MemoryPatch::createWithHex("libUE4.so",0x028758e0,"1EFF2FE1");//23
hexPatches.CheckBan_Response = MemoryPatch::createWithHex("libUE4.so",0x02885524,"1EFF2FE1");//24
hexPatches.IHackProperty = MemoryPatch::createWithHex("libUE4.so",0x028df4e4,"1EFF2FE1");//25
hexPatches.HACK_ForceToFront = MemoryPatch::createWithHex("libUE4.so",0x02e2a860,"1EFF2FE1");//26
    return NULL;
}

extern "C" {

JNIEXPORT jobjectArray
JNICALL
Java_Tojik_Mods_modmenu_FloatingModMenuService_getFeatureList(JNIEnv *env, jobject context) {
    jobjectArray ret;
    const char *features[] = {
            ("Category_SFG 4.21 32bit All Mod"),//Not counted
            
            ("Collapse_Aim Ammo no Dead AManHit"),//Not counted
		    ("CollapseAdd_Toggle_➣ Aim"),//1
			("CollapseAdd_Toggle_➣ No Dead"),//2
			("CollapseAdd_Toggle_➣ Ammo"),//3
			("CollapseAdd_Toggle_➣ AManHit"),//4
			("CollapseAdd_Toggle_➣ Anti Flash Bang"),//5
			
			("Collapse_ANTI BAN"),//Not counted
            ("CollapseAdd_Toggle_➣ AddBan"),//6
            ("CollapseAdd_Toggle_➣ CheckBan"),//7
            ("CollapseAdd_Toggle_➣ CheckBan_Response"),//8
            ("CollapseAdd_Toggle_➣ IHackProperty"),//9
            ("CollapseAdd_Toggle_➣ HACK-ForceToFront"),//10
			
			("Collapse_Time Recoil Unlimited SpeedHack"),//Not counted
			("CollapseAdd_Toggle_➣ CurrentTimeRound"),//11
			("CollapseAdd_Toggle_➣ Pick up Weopon Visible"),//12
			("CollapseAdd_Toggle_➣ Shop Always Visible"),//13
			("CollapseAdd_Toggle_➣ No Recoil Ctoshair"),//14
			("CollapseAdd_Toggle_➣ Unlimited CliP"),//15
			("CollapseAdd_Toggle_➣ Unlimited Money"),//16
			("CollapseAdd_Toggle_➣ Small crosshair"),//17
			("CollapseAdd_Toggle_➣ SpeedHack"),//18
			
			("Collapse_Time Recoil Unlimited SpeedHack Gravity"),//Not counted
			("CollapseAdd_Toggle_➣ UAnimMontage"),//19
			("CollapseAdd_Toggle_➣ USkinEditorWidget"),//20
			("CollapseAdd_Toggle_➣ SpawnPlayerCameraManager"),//21
			("CollapseAdd_Toggle_➣ UpdateCameraManager"),//22
			("CollapseAdd_Toggle_➣ FastLobby"),//23
			("CollapseAdd_Toggle_➣ AutoFire Weapons"),//24
			("CollapseAdd_Toggle_➣ FreezeMoney"),//25
			("CollapseAdd_Toggle_➣ NoGravity"),//26
		    //Website
            ("Category_FOR MORE"), //Not counted
            ("ButtonLink_ MY BLOGSPOT_https://elementman50.blogspot.com"), //Not counted       
            ("ButtonLink_ Telegram Chanell_https://t.me/linkuzbio"), //Not counted       
            ("ButtonLink_ YouTube Chanell_https://youtube.com/@saveeditoronlinecom"), //Not counted       
          };
    
    //Now you dont have to manually update the number everytime;
    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    pthread_t ptid;
    pthread_create(&ptid, NULL, antiLeech, NULL);

    return (ret);
}

JNIEXPORT void JNICALL
Java_Tojik_Mods_modmenu_Preferences_Changes(JNIEnv *env, jclass clazz, jobject obj,
                                        jint featNum, jstring featName, jint value,
                                        jboolean boolean, jstring str) {

    LOGD(("Feature name: %d - %s | Value: = %d | Bool: = %d | Text: = %s"), featNum,
         env->GetStringUTFChars(featName, 0), value,
         boolean, str != NULL ? env->GetStringUTFChars(str, 0) : "");

    //BE CAREFUL NOT TO ACCIDENTLY REMOVE break;

        switch (featNum) {
                
            case 1:
            Aim = boolean;
            if (Aim) {
                hexPatches.Aim.Modify();
            } else {
                hexPatches.Aim.Restore();
            }
            break;
            
			case 2:
            PickupWeaponVisible = boolean;
            if (PickupWeaponVisible) {
                hexPatches.PickupWeaponVisible.Modify();
            } else {
                hexPatches.PickupWeaponVisible.Restore();
            }
            break;
            
            case 3:
            ShopAlwaysVisible = boolean;
            if (ShopAlwaysVisible) {
                hexPatches.ShopAlwaysVisible.Modify();
            } else {
                hexPatches.ShopAlwaysVisible.Restore();
            }
            break;
            
			case 4:
            NoRecoilCtoshair = boolean;
            if (NoRecoilCtoshair) {
                hexPatches.NoRecoilCtoshair.Modify();
            } else {
                hexPatches.NoRecoilCtoshair.Restore();
            }
            break;
            
			case 5:
            UnlimitedCliP = boolean;
            if (UnlimitedCliP) {
                hexPatches.UnlimitedCliP.Modify();
            } else {
                hexPatches.UnlimitedCliP.Restore();
            }
            break;
            
			case 6:
            NoDead = boolean;
            if (NoDead) {
                hexPatches.NoDead.Modify();
            } else {
                hexPatches.NoDead.Restore();
            }
            break;
            
			case 7:
            CurrentTimeRound = boolean;
            if (CurrentTimeRound) {
                hexPatches.CurrentTimeRound.Modify();
            } else {
                hexPatches.CurrentTimeRound.Restore();
            }
            break;
            
			case 8:
            Ammo = boolean;
            if (Ammo) {
                hexPatches.Ammo.Modify();
            } else {
                hexPatches.Ammo.Restore();
            }
            break;
            
			case 9:
            SmallCrosshair = boolean;
            if (SmallCrosshair) {
                hexPatches.SmallCrosshair.Modify();
            } else {
                hexPatches.SmallCrosshair.Restore();
            }
            break;
            
			case 10:
            AntiFlashBang = boolean;
            if (AntiFlashBang) {
                hexPatches.AntiFlashBang.Modify();
            } else {
                hexPatches.AntiFlashBang.Restore();
            }
            break;
            
			case 11:
            UnlimitedMoney = boolean;
            if (UnlimitedMoney) {
                hexPatches.UnlimitedMoney.Modify();
            } else {
                hexPatches.UnlimitedMoney.Restore();
            }
            break;
            
			case 12:
            AManHit = boolean;
            if (AManHit) {
                hexPatches.AManHit.Modify();
            } else {
                hexPatches.AManHit.Restore();
            }
            break;
            
			case 13:
            UAnimMontage = boolean;
            if (UAnimMontage) {
                hexPatches.UAnimMontage.Modify();
            } else {
                hexPatches.UAnimMontage.Restore();
            }
            break;
            
			case 14:
            USkinEditorWidget = boolean;
            if (USkinEditorWidget) {
                hexPatches.USkinEditorWidget.Modify();
            } else {
                hexPatches.USkinEditorWidget.Restore();
            }
            break;
            
			case 15:
            SpawnPlayerCameraManager = boolean;
            if (SpawnPlayerCameraManager) {
                hexPatches.SpawnPlayerCameraManager.Modify();
            } else {
                hexPatches.SpawnPlayerCameraManager.Restore();
            }
            break;
            
			case 16:
            UpdateCameraManager = boolean;
            if (UpdateCameraManager) {
                hexPatches.UpdateCameraManager.Modify();
            } else {
                hexPatches.UpdateCameraManager.Restore();
            }
            break;
            
            case 17:
            FastLobby = boolean;
            if (FastLobby) {
                hexPatches.FastLobby.Modify();
            } else {
                hexPatches.FastLobby.Restore();
            }
            break;
            
            case 18:
            AutoFireWeapons = boolean;
            if (AutoFireWeapons) {
                hexPatches.AutoFireWeapons.Modify();
            } else {
                hexPatches.AutoFireWeapons.Restore();
            }
            break;
            
            case 19:
            FreezeMoney = boolean;
            if (FreezeMoney) {
                hexPatches.FreezeMoney.Modify();
            } else {
                hexPatches.FreezeMoney.Restore();
            }
            break;
            
            case 20:
            NoGravity = boolean;
            if (NoGravity) {
                hexPatches.NoGravity.Modify();
            } else {
                hexPatches.NoGravity.Restore();
            }
            break;
            
            case 21:
            SpeedHack = boolean;
            if (SpeedHack) {
                hexPatches.SpeedHack.Modify();
            } else {
                hexPatches.SpeedHack.Restore();
            }
            break;
            
            case 22:
            AddBan = boolean;
            if (AddBan) {
                hexPatches.AddBan.Modify();
            } else {
                hexPatches.AddBan.Restore();
            }
            break;
            
            case 23:
            CheckBan = boolean;
            if (CheckBan) {
                hexPatches.CheckBan.Modify();
            } else {
                hexPatches.CheckBan.Restore();
            }
            break;
            
            case 24:
            CheckBan_Response = boolean;
            if (CheckBan_Response) {
                hexPatches.CheckBan_Response.Modify();
            } else {
                hexPatches.CheckBan_Response.Restore();
            }
            break;
            
            case 25:
            IHackProperty = boolean;
            if (IHackProperty) {
                hexPatches.IHackProperty.Modify();
            } else {
                hexPatches.IHackProperty.Restore();
            }
            break;
            
            case 26:
            HACK_ForceToFront = boolean;
            if (HACK_ForceToFront) {
                hexPatches.HACK_ForceToFront.Modify();
            } else {
                hexPatches.HACK_ForceToFront.Restore();
            }
            break;
}
}
}

__attribute__((constructor))
void lib_main() {

    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
}
