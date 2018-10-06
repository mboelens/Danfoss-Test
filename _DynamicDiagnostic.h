#ifndef _DYNAMIC_DIAGNOSTICS_H
#define _DYNAMIC_DIAGNOSTICS_H
typedef struct {
	struct {
 U8 _SetDummy0;
	}SET;
struct {
 U32 CP_SPN517_DanfossBlock;
 U16 CP_SPN517_Raw;
 U8 _CheckDummy1;
}CHECK;
} TEST_T;
extern TEST_T _TEST;
#endif
