LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# Here is the name of your lib.
# When you change the lib name, change also on System.loadLibrary("") under OnCreate method on StaticActivity.java
# Both must have same name
LOCAL_MODULE    := tojik_9

# Code optimization
LOCAL_ARM_MODE := arm
LOCAL_CFLAGS := -Wno-error=format-security -fpermissive -fvisibility=hidden -fvisibility-inlines-hidden
LOCAL_CFLAGS += -fno-rtti -fno-exceptions -g0 -fomit-frame-pointer -ffunction-sections -fdata-sections
LOCAL_CPPFLAGS += -fvisibility=hidden -ffunction-sections -fdata-sections
LOCAL_LDFLAGS += -Wl,--strip-all
LOCAL_LDFLAGS += "-Wl,-z,max-page-size=16384"

# Here you add the cpp file
LOCAL_SRC_FILES := Main.cpp \
	Substrate/hde64.c \
	Substrate/SubstrateDebug.cpp \
	Substrate/SubstrateHook.cpp \
	Substrate/SubstratePosixMemory.cpp \
	Substrate/SymbolFinder.cpp \
	KittyMemory/KittyMemory.cpp \
	KittyMemory/MemoryPatch.cpp \
    KittyMemory/MemoryBackup.cpp \
    KittyMemory/KittyUtils.cpp \
	And64InlineHook/And64InlineHook.cpp \

LOCAL_LDLIBS := -llog -landroid

include $(BUILD_SHARED_LIBRARY)